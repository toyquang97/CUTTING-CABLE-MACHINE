/*
 * input.c
 *
 *  Created on: Mar 25, 2022
 *      Author: HT-QUANG
 */

#define _INPUT_C

#include "input.h"

int32_t readEncoder(void)
{
	static int32_t countValue = 0;
	countValue = (int32_t)TIM3->CNT;
	if (TIM3->CNT > 65535 - 10 || TIM3->CNT > 3999)
	{
		TIM3->CNT = 0;
	}
	return countValue;
}

int16_t getRealPulsePosition(void)
{
	realPulse = readEncoder();
	positionDirective = (int32_t)realPulse;
	getPosition = positionDirective / 4;
	if (getPosition > 999)
	{
		TIM3->CNT = 0;
		countTimeRotation++;
	}
	return getPosition;
}

float convertRotationToMet(uint8_t counterRotation, int16_t pulseEncoder)
{
	float actualPosition = 0;
	actualPosition = (counterRotation + (float)(pulseEncoder / 1000)) / SCALEROTATION;
	return actualPosition;
}

int16_t getSpeedRPM(int16_t positionEncoder)
{
	static int16_t speedEncoder = 0;
	countIndex++;
	if(countIndex == 100)
	{
		if(positionEncoder > oldPositionEncoder)
		{
			speedEncoder = ((positionEncoder - oldPositionEncoder) * 10 * 60 )/1000;
		}
		if(positionEncoder == oldPositionEncoder)
		{
			speedEncoder = 0;
		}
		oldPositionEncoder = positionEncoder;
		countIndex = 0;
	}
	return speedEncoder;
}
uint32_t *p;
void ReadInput(void){
//	memcpy((void *)in,(void *)Userin,MAX_IN_BYTE);
//	return ;
	uint8_t i, j, temp;
	uint32_t kCode[3] = {0,0,0};
	p = kCode;
//���ȶ�ȡ��ť�������(һ��22��)
//	kCode[0] = ((PORTA & 0x0F) |						// PA0~PA3
//			(((uint32_t)PORTE & 0x07) << 4) |			// PE0~PE2
//			((uint32_t)PORTD << 7) |					// PD0~PD7
//			(((uint32_t)PORTB & 0x03) << 15) |			// PB0~PB1
//			(((uint32_t)PORTB & 0x30) << 13) |			// PB4~PB5
//			(((uint32_t)PORTC & 0x07) << 19));			// PC0~PC2
	kCode[0] = ((GPIOB->IDR) & 0x3FFF);

	HC166_PARA_EN(); __NOP();__NOP();__NOP();__NOP();
	HC166_CLK_LOW();__NOP();__NOP();__NOP();__NOP();
	HC166_CLK_HIGH();__NOP();__NOP();__NOP();__NOP();
	HC166_CLK_LOW();__NOP();__NOP();__NOP();__NOP();
	HC166_SERI_EN(); __NOP();__NOP();__NOP();__NOP();
	HC595_LUCK_DIS();

	temp =21;
	for(j=0; j<8; j++)
		{
			if (PIN_A6)
				kCode[temp / 32] |= (0x01ul << (temp % 32));
			HC166_CLK_HIGH();__NOP();__NOP();__NOP();__NOP();
			HC166_CLK_LOW();__NOP();__NOP();
			--temp;
		}
	
	__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();

	if(mExtern_Number)
		{//������չ��
			kCode[1] = 0x00;
			kCode[2] = 0x00;
			//SSPCON1 = 0x00; __NOP();__NOP();__NOP();__NOP();
			HC166_PARA_EN(); __NOP();__NOP();__NOP();__NOP();
			HC166_CLK_LOW();__NOP();__NOP();__NOP();__NOP();
			HC166_CLK_HIGH();__NOP();__NOP();__NOP();__NOP();
			HC166_CLK_LOW();__NOP();__NOP();__NOP();__NOP();
			HC166_SERI_EN(); __NOP();__NOP();__NOP();__NOP();
			HC595_LUCK_DIS();
			temp = 0;
			for (i=0; i<mExtern_Number; i++)
				{
					temp = 22 + (i + 1) * 16 - 1;
					for(j=0; j<24; j++)
						{
//#warning   please modify here!
							if (PIN_A6)
								kCode[temp / 32] |= (0x01ul << (temp % 32));
							HC166_CLK_HIGH();__NOP();__NOP();__NOP();__NOP();
							HC166_CLK_LOW();__NOP();__NOP();
							--temp;
						}
				}
				

			__NOP();__NOP();__NOP();__NOP();
			__NOP();__NOP();__NOP();__NOP();
			__NOP();__NOP();__NOP();__NOP();
//			SSPCON1 = 0x32;
		}

	for (i=0; i<MAX_IN_BYTE; ++i)
		{	
			input[2][i] = input[1][i];
			input[1][i] = input[0][i];
		}
	input[0][0] = (uint8_t)kCode[0];
	input[0][1] = (uint8_t)(kCode[0] >> 8);
	input[0][2] = (uint8_t)(kCode[0] >> 16);
	j = 3;

	switch (mExtern_Number)
		{
			case 1:
				input[0][3] = (uint8_t)(kCode[0] >> 24);
				input[0][4] = (uint8_t)kCode[1];
				j = 5;
				break;
				
			case 2:
				input[0][3] = (uint8_t)(kCode[0] >> 24);
				input[0][4] = (uint8_t)kCode[1];
				input[0][5] = (uint8_t)(kCode[1] >> 8);
				input[0][6] = (uint8_t)(kCode[1] >> 16);
				j = 7;
				break;
				
			case 3:
				input[0][3] = (uint8_t)(kCode[0] >> 24);
				input[0][4] = (uint8_t)kCode[1];
				input[0][5] = (uint8_t)(kCode[1] >> 8);
				input[0][6] = (uint8_t)(kCode[1] >> 16);
				input[0][7] = (uint8_t)(kCode[1] >> 24);
				input[0][8] = (uint8_t)kCode[2];
				j = 9;
				break;				
		}

	for (i=0; i<j; ++i)
		{	
			if (input[2][i] == input[1][i] && input[1][i] == input[0][i])
				in[i] = input[2][i];
		}
}
