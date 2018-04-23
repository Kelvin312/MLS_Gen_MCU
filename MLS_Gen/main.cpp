#include "stdafx.h"
#include "config.h"
#include "HardwareUART.cpp"

#define OUTP _BV(0)
#define OUTN _BV(1)
#define OUTRES _BV(2)
#define T1_PIN PIND
#define T1_INPUT _BV(5)

u16 fbIndex = 0; //Индекс обратной связи в массиве обратных связей
u32 mlsPeriod = 0; //Период М последовательности
u16 repeatCnt = 0; //Счетчик повторов М последовательности
u32 mlsLenCnt = 0; //Счетчик периода М последовательности

u32 curFeedback = 0; //Текущий набор обратных связей
u32 lfsr = 0; //Сдвиговый регистр
u8 res = 0; //Выход М последовательности

inline void calculate();

int main(void)
{
	cli();
	wdt_reset();
	
	//Установка делителя частоты кварца в 1
	clock_prescale_set(clock_div_1);

	//Инициализация портов
	PORTB = 0x00;
	DDRB = LED_PIN | OUTP | OUTN | OUTRES;

	PORTC=0x00;
	DDRC=0x00;

	PORTD = 0x00;
	DDRD = 0x00;
	
	//Таймер 0 в 250 kHz 
	TCCR0A=0x00;
	TCCR0B=0x00;
	
	

	//Таймер 1 в режиме CTC (обнуление таймера по совпадению)
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1=0x00;
	OCR1A=0x00;
	OCR1B=0x00;
	TCCR1A=0x00;
	TCCR1B=0x00;
	

	//Выключить таймер 2
	ASSR=0x00;
	TCCR2A=0x00;
	TCCR2B=0x00;
	TCNT2=0x00;
	OCR2A=0x00;
	OCR2B=0x00;

	//Выключить прерывания
	EICRA=0x00;
	EIMSK=0x00;
	PCICR=0x00;
	//Прерывание таймера 0
	TIMSK0=0x00;
	TIMSK1=0x00;
	TIMSK2=0x00;

	//Выключить аналоговый компаратор
	ACSR=0x80;
	ADCSRB=0x00;
	DIDR1=0x00;

	//Выключить АЦП
	ADCSRA=0x00;

	//Выключить SPI
	SPCR=0x00;

	//Выключить TWI
	TWCR=0x00;

	//Сторожевой таймер с интервалом 15мс
	//wdt_enable(WDTO_2S); //Собака кусается

	//Разрешить глобально прервания
	sei();

	mlsPeriod = pgm_read_dword(&feedbacks[0]); //Вычисление периода М последовательности
	mlsPeriod |= mlsPeriod >> 1;
	mlsPeriod |= mlsPeriod >> 2;
	mlsPeriod |= mlsPeriod >> 4;
	mlsPeriod |= mlsPeriod >> 8;
	mlsPeriod |= mlsPeriod >> 16;
	
	
	fbIndex = 0;
	mlsLenCnt = 1; //Установка начального состояния выходов
	repeatCnt = 1;
	calculate();
	calculate();

	TCCR1B=0x08|7; //Тактирование от T1 по фронту
	OCR1A = clockDividor - 1; //Установка делителя частоты синхронизации
	TCNT1H=0x00;
	TCNT1L=0x00;
	TIFR1 |= _BV(OCF1A);

	PORTB |= OUTRES; //Выключение сброса триггеров
	LED_PORT |= LED_PIN; //Сброс индикатора ошибки
	
	TCNT0 = 0;
	OCR0A = 10;
	OCR0B = 35;
	TIFR0 |= TIFR0;
	
	while(!(TIFR1 & _BV(OCF1A) || TCNT1L)) wdt_reset();
	TCCR0B = 0x03; //250 kHz
	

	while (1)
	{
		if(TIFR1 & _BV(OCF1A)) //Ждем флаг синхронизации
		{
			//LED_PORT &= ~LED_PIN;
			TIFR1 |= _BV(OCF1A); //Сброс флага синхронизации

			calculate(); //Вычисление следующего значения последовательности

			if(!(TIFR0 & _BV(OCF0A))) break; //Частота высокая
			TCNT0 = 0; //Сброс защитного таймера
			TIFR0 |= _BV(OCF0A);
			
			
			if(TIFR1 & _BV(OCF1A)) break; //Не успели расчитать М последовательность
			//LED_PORT |= LED_PIN;
		}
		if(TIFR0 & _BV(OCF0B)) break; //Частота низкая
		
		//if(TCNT1L != oldT1Val) //Сброс защитного таймера
		//{
			//oldT1Val = TCNT1L;  
			//TCNT0 = 0x00;
		//}
		//wdt_reset();
	}
	
	PORTB &= ~(LED_PIN | OUTP | OUTN | OUTRES);
	while(1)
	{
		
	}
}

inline void calculate()
{
	PORTB &= ~3; //Меняем состояние выходов
	PORTB |= res;

	if(--mlsLenCnt == 0)
	{
		mlsLenCnt = mlsPeriod;
		if(--repeatCnt == 0)
		{
			repeatCnt = repeatMls;
			curFeedback = pgm_read_dword(&feedbacks[fbIndex]); //Загружаем обратные связи
			lfsr = initState[fbIndex];
			if(++fbIndex >= feedbacksSize) fbIndex = 0;
		}
	}
	
	res = lfsr & 1; //Вычисление следующего значения М последовательности
	lfsr >>= 1;
	if(res)
	{ 
		lfsr ^= curFeedback;
		res = 2;
	}
	else res = 1;
}