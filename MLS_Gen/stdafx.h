#ifndef STDAFX_H_
#define STDAFX_H_

#define F_CPU 16000000UL //������� ������������ �� 16 ���
#define LED_PIN _BV(5)  //��� ����������� ����������
#define LED_PORT PORTB //���� ����� ����������

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h> 

#include <string.h>
#include <math.h>

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
typedef signed long s32;

//������� ��� ���������� ��������� �������� � �������������
template<class T> inline constexpr T operator~ (T a) { return static_cast<T>(~static_cast<int>(a)); }
template<class T> inline constexpr T operator| (T a, T b) { return static_cast<T>(static_cast<int>(a) | static_cast<int>(b)); }
template<class T> inline constexpr T operator& (T a, T b) { return static_cast<T>(static_cast<int>(a) & static_cast<int>(b)); }
template<class T> inline constexpr T operator^ (T a, T b) { return static_cast<T>(static_cast<int>(a) ^ static_cast<int>(b)); }
template<class T> inline T& operator|= (T& a, T b) { return reinterpret_cast<T&>(reinterpret_cast<int&>(a) |= static_cast<int>(b)); }
template<class T> inline T& operator&= (T& a, T b) { return reinterpret_cast<T&>(reinterpret_cast<int&>(a) &= static_cast<int>(b)); }
template<class T> inline T& operator^= (T& a, T b) { return reinterpret_cast<T&>(reinterpret_cast<int&>(a) ^= static_cast<int>(b)); }

//������� ���������� true, ���� ������ �������� ������
//c: ����������� ������
inline bool isDigit(u8 c) { return c >= '0' && c <= '9'; }

//������� ���������� �����, ��������������� ����������� �������
//c: ������
inline u8 Dec2Int(u8 c) { return c - '0'; }

//������, �������� ��� type � ����������� �� _Test
//���� _Test == false, �� type ����� ���� _Ty2
template<bool _Test, class _Ty1, class _Ty2>
struct conditional
{	
	typedef _Ty2 type;
};
//���� _Test == true, �� type ����� ���� _Ty1
template<class _Ty1, class _Ty2>
struct conditional<true, _Ty1, _Ty2>
{	
	typedef _Ty1 type;
};

//��������� �����
//S: �������� ������ ������
template<u16 S> struct RingBuffer
{
	private:
	//��� ��������
	typedef typename conditional<(S>128), u16, u8 >::type T;
	//���������� ������� ������ ����� � ���������� 2^x
	static const u16 S0 = S-1, S1 = S0 | S0 >> 1, S2 = S1 | S1 >> 2, S4 = S2 | S2 >> 4, S8 = S4 | S4 >> 8;
	static const T bufferSize = S8 + 1; //������ ������
	volatile T writeIndex = 0, readIndex = 0; //������� ������ � ������
	volatile u8 buffer[bufferSize]; //��� �����

	public:
	volatile bool isOverflow = false; //���� ������������ ������

	//������� ��������� ���� � ����� ������
	//data: ����������� ����
	void Push(u8 data)
	{
		if (Size() == bufferSize) //������������
		{
			isOverflow = true;
			return;
		}
		buffer[writeIndex++ & (bufferSize - 1)] = data;
	}
	//������� ���������� ���� �� ������ ������ � ������� ��� �� ������
	u8 Pop()
	{
		if (Empty()) return 0; //����� ������
		return buffer[readIndex++  & (bufferSize - 1)];
	}
	//������� ���������� ���� �� ������ ������
	u8 Front() const 
	{
		if (Empty()) return 0;
		return buffer[readIndex & (bufferSize - 1)];
	}
	//������� ���������� ���� �� ����� ������
	u8 Back() const 
	{
		if (Empty()) return 0;
		return buffer[writeIndex - 1 & (bufferSize - 1)];
	}
	//������� ������� �����
	void Clear()
	{
		readIndex = writeIndex = 0;
	}
	//������� ���������� ������� ������ ������
	T Size() const
	{
		return writeIndex - readIndex;
	}
	//������� ���������� true, ���� ����� ������
	bool Empty() const
	{
		return writeIndex == readIndex;
	}
};

//������������ ������� ������ UART (���� �������� � ���������� ���� �����)
enum class ParityAndStop:u8
{
	None1 =  0,
	//None2 =  1,
	Even1 = 4,
	//Even2 = 5,
	Odd1 = 6,
	//Odd2 = 7
};

#endif /* STDAFX_H_ */