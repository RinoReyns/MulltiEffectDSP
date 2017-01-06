/*
 * delay2.c
 *
 *  Created on: 8 paŸ 2016
 *      Author: £ukasz Pindor
 */

#include "usbstk5515.h"
#include "math.h"
#include <stdlib.h>

#define N 30500

int delay_w_probkach2=0;
int licznik_opoznienia2=0;
signed int tablica_opoznionych_probek2[N];
Int16 xh=0;
signed long temp_d=0;
signed long temp2_d=0;



void delay2_init(short int* opoznienie)
{
	int* i_d=(int*)malloc(15);
	// czyszczenie buffora, w którym bêd¹ przechowywane próbki, które s¹ dodawane w odpowiednim czasie
	for ( *i_d = 0 ; *i_d < N ; *i_d=*i_d+1)
	{
		tablica_opoznionych_probek2[*i_d] = 0;
	}
	free(i_d);
	// zmienna odpowiedzialna za opóŸnienie
	delay_w_probkach2=*opoznienie*48;
}


Int16 delay2(Int16* sygnal_wejsciowy, char* FF,char* BL,char* FB)
{



	temp2_d=((long)(*FB)*32767/100);
	temp2_d=((long)(temp2_d)*tablica_opoznionych_probek2[licznik_opoznienia2]);
	temp2_d>>=15;
	xh=(*sygnal_wejsciowy)+(temp2_d);

	temp_d=((long)(*FF)*32767/100);
	temp_d=((long)(temp_d)*tablica_opoznionych_probek2[licznik_opoznienia2]);
	temp_d>>=15;

	temp2_d=((long)(*BL)*32767/100);
	temp2_d=((long)(temp2_d)*(xh));
	temp2_d>>=15;
	xh=temp_d+temp2_d;

	tablica_opoznionych_probek2[licznik_opoznienia2]=xh;

	licznik_opoznienia2++;
	if(licznik_opoznienia2==delay_w_probkach2)
		licznik_opoznienia2=0;

	return( xh);
}

