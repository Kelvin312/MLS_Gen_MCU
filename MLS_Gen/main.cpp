#include "stdafx.h"
#include "config.h"
#include "HardwareUART.cpp"

#define OUTP _BV(0)
#define OUTN _BV(1)
#define OUTRES _BV(2)
#define T1_PIN PIND
#define T1_INPUT _BV(5)

u16 fbIndex = 0; //������ �������� ����� � ������� �������� ������
u32 mlsPeriod = 0; //������ � ������������������
u16 repeatCnt = 0; //������� �������� � ������������������
u32 mlsLenCnt = 0; //������� ������� � ������������������

u32 curFeedback = 0; //������� ����� �������� ������
u32 lfsr = 0; //��������� �������
u8 res = 0; //����� � ������������������

inline void calculate();

int main(void)
{
	cli();
	wdt_reset();
	
	//��������� �������� ������� ������ � 1
	clock_prescale_set(clock_div_1);

	//������������� ������
	PORTB = 0x00;
	DDRB = LED_PIN | OUTP | OUTN | OUTRES;

	PORTC=0x00;
	DDRC=0x00;

	PORTD = 0x00;
	DDRD = 0x00;
	
	//������ 0 � 250 kHz 
	TCCR0A=0x00;
	TCCR0B=0x00;
	
	

	//������ 1 � ������ CTC (��������� ������� �� ����������)
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1=0x00;
	OCR1A=0x00;
	OCR1B=0x00;
	TCCR1A=0x00;
	TCCR1B=0x00;
	

	//��������� ������ 2
	ASSR=0x00;
	TCCR2A=0x00;
	TCCR2B=0x00;
	TCNT2=0x00;
	OCR2A=0x00;
	OCR2B=0x00;

	//��������� ����������
	EICRA=0x00;
	EIMSK=0x00;
	PCICR=0x00;
	//���������� ������� 0
	TIMSK0=0x00;
	TIMSK1=0x00;
	TIMSK2=0x00;

	//��������� ���������� ����������
	ACSR=0x80;
	ADCSRB=0x00;
	DIDR1=0x00;

	//��������� ���
	ADCSRA=0x00;

	//��������� SPI
	SPCR=0x00;

	//��������� TWI
	TWCR=0x00;

	//���������� ������ � ���������� 15��
	//wdt_enable(WDTO_2S); //������ ��������

	//��������� ��������� ���������
	sei();

	mlsPeriod = pgm_read_dword(&feedbacks[0]); //���������� ������� � ������������������
	mlsPeriod |= mlsPeriod >> 1;
	mlsPeriod |= mlsPeriod >> 2;
	mlsPeriod |= mlsPeriod >> 4;
	mlsPeriod |= mlsPeriod >> 8;
	mlsPeriod |= mlsPeriod >> 16;
	
	
	fbIndex = 0;
	mlsLenCnt = 1; //��������� ���������� ��������� �������
	repeatCnt = 1;
	calculate();
	calculate();

	TCCR1B=0x08|7; //������������ �� T1 �� ������
	OCR1A = clockDividor - 1; //��������� �������� ������� �������������
	TCNT1H=0x00;
	TCNT1L=0x00;
	TIFR1 |= _BV(OCF1A);

	PORTB |= OUTRES; //���������� ������ ���������
	LED_PORT |= LED_PIN; //����� ���������� ������
	
	TCNT0 = 0;
	OCR0A = 10;
	OCR0B = 35;
	TIFR0 |= TIFR0;
	
	while(!(TIFR1 & _BV(OCF1A) || TCNT1L)) wdt_reset();
	TCCR0B = 0x03; //250 kHz
	

	while (1)
	{
		if(TIFR1 & _BV(OCF1A)) //���� ���� �������������
		{
			//LED_PORT &= ~LED_PIN;
			TIFR1 |= _BV(OCF1A); //����� ����� �������������

			calculate(); //���������� ���������� �������� ������������������

			if(!(TIFR0 & _BV(OCF0A))) break; //������� �������
			TCNT0 = 0; //����� ��������� �������
			TIFR0 |= _BV(OCF0A);
			
			
			if(TIFR1 & _BV(OCF1A)) break; //�� ������ ��������� � ������������������
			//LED_PORT |= LED_PIN;
		}
		if(TIFR0 & _BV(OCF0B)) break; //������� ������
		
		//if(TCNT1L != oldT1Val) //����� ��������� �������
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
	PORTB &= ~3; //������ ��������� �������
	PORTB |= res;

	if(--mlsLenCnt == 0)
	{
		mlsLenCnt = mlsPeriod;
		if(--repeatCnt == 0)
		{
			repeatCnt = repeatMls;
			curFeedback = pgm_read_dword(&feedbacks[fbIndex]); //��������� �������� �����
			lfsr = initState[fbIndex];
			if(++fbIndex >= feedbacksSize) fbIndex = 0;
		}
	}
	
	res = lfsr & 1; //���������� ���������� �������� � ������������������
	lfsr >>= 1;
	if(res)
	{ 
		lfsr ^= curFeedback;
		res = 2;
	}
	else res = 1;
}