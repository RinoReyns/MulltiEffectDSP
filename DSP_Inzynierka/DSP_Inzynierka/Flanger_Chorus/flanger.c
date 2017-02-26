/*
 * flanger.c
 *
 *  Created on: 9 paŸ 2016
 *      Author: £ukasz Pindor
 */
#include "math.h"
#include "dsplib.h"
#include "usbstk5515.h"
#include <stdlib.h>

#define F 725

int delay_flanger_w_probkach=0;
int licznik=0;
int tablica_opoznienia_flanger[F];
signed long temp2_f=0;
signed long temp3=0;

int omega=0;
DATA faza = 0;
DATA y = 0;


void flanger_init(char* opoznienie, char* lfo_frequency) 
{
	short int* i_f=(short int*)malloc(11);
	omega=(int)((22368L * ((int)(*lfo_frequency))) >> 14);
	
	for ( *i_f = 0 ; *i_f < F ; *i_f=*i_f+1)
	{
		tablica_opoznienia_flanger[*i_f] = 0;
	}
	free(i_f);

	delay_flanger_w_probkach=*opoznienie*48;
}

Int16 flanger (Int16* sygnal_wejsciowy, char* lfo_amplitude, char* volume )
{


	sine(&faza, &y, 1);
	faza += omega;
	temp2_f=((long)y+32767);
	temp2_f=((long)16056*(temp2_f));
	temp2_f>>=15;
	temp2_f=((long)(*lfo_amplitude)*327*(temp2_f));
	temp2_f>>=15;
	y=((int)(temp2_f));

	/// czy to w ogóle potrzebne raczej nie tutaj
	if (y<-32760)
		y=32760;
	else if(y>=-32760)
		y=abs(y);


	temp3=((long)y*delay_flanger_w_probkach);
	temp3>>=15;
	temp3=licznik+temp3;


	if(temp3<0)
		temp3=temp3+delay_flanger_w_probkach;
	else if (temp3>=delay_flanger_w_probkach)
		temp3=temp3-delay_flanger_w_probkach;



	temp2_f=*sygnal_wejsciowy+tablica_opoznienia_flanger[temp3];
	temp2_f=((long)(*volume)*327*(temp2_f));
	temp2_f>>=15;
	tablica_opoznienia_flanger[licznik]=*sygnal_wejsciowy;
	licznik++;
	if(licznik==delay_flanger_w_probkach)
		licznik=0;



	return (Int16) temp2_f;
}


