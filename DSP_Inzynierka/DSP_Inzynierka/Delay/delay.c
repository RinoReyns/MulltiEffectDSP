/*
 * delay.c
 *
 *  Created on: 8 paŸ 2016
 *      Author: £ukasz Pindor
 */
#include "math.h"
#include <stdlib.h>
#include "usbstk5515.h"

#define N 30245 
int delay_w_probkach=0;
int licznik_opoznienia=0;
int tablica_opoznionych_probek[N];
signed int temp=0;
signed long temp2=0;
 //// inicjalizacja w inicie i ubicie

void delay_init(short int* opoznienie) {

	int* i=(int*)malloc(15);

	// czyszczenie buffora, w którym bêd¹ przechowywane próbki, które s¹ dodawane w odpowiednim czasie
	for ( *i = 0 ; *i < N ; *i=(*i)+1)
	{
		tablica_opoznionych_probek[*i] = 0;
	}
	free(i);

	// opoznienie z zakresu od 10ms od 600 ms
	delay_w_probkach=*opoznienie*48;
}

Int16 delay(Int16* sygnal_wejsciowy, char* gain_input )
{


	temp2=((long)(*gain_input)*32767/100);
	temp2=((long)(*sygnal_wejsciowy)*(temp2));
	temp2>>=15;
	temp=(temp2)+tablica_opoznionych_probek[licznik_opoznienia];
	tablica_opoznionych_probek[licznik_opoznienia]=temp2;

	licznik_opoznienia++;
	if(licznik_opoznienia==delay_w_probkach)
		licznik_opoznienia=0;

	return((Int16) temp);
}
