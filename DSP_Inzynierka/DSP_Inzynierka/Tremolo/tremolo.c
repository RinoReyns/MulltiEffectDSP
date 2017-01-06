/*
 * tremol.c
 *
 *  Created on: 16 lis 2016
 *      Author: Weronika Majewska
 */

#include "math.h"
#include <stdlib.h>
#include "usbstk5515.h"
#include "dsplib.h"
#include "lfo_type.h"

//deklaracje zmiennych do LFO
int omega_t=0;
DATA faza_t = 0;
DATA y_t = 0;

signed long gain=0;
signed long modulujacy=0;
signed long zmodulowany=0;

//funkcja inicjalizuj¹ca omege - zalezna od parametru czestotliwosci LFO - 0-20Hz
void tremolo_init(char *czestotliwosc_LFO)
{
	omega_t=(int)((22368L * ((int)(*czestotliwosc_LFO))) >> 14);
}

Int16 tremolo(Int16* sygnal_wejsciowy, char* volume, typ_LFO* typ)
{

				if(*typ==sinus)
				{
					//SINUS
					// obliczenie kolejnej próbki sygna³u sinus
					sine(&faza_t, &y_t, 1);
					// y zawiera obliczon¹ próbkê sygna³u: y = sin(faza)
					// inkrementacja argumentu sinusa (k¹ta fazowego):
					faza_t += omega_t;
				}
				else if(*typ==sq)
				{
					y_t = (faza_t >= 0) ? 10000 : -10000;
					faza_t += omega_t;
				}
				else if(*typ==saw)
				{
					y_t = faza_t;
					faza_t += omega_t;
				}
				else if(*typ==tri)
				{
					y_t = faza_t;
					faza_t += omega_t;
					y_t = (faza_t>=0) ? faza_t : -faza_t;
					y_t=(y_t-163384) <<1;
				}

				//zamiana parametru na gain_tremolo na Q15


				 gain=(long)(*volume*32768/100);

				//wymnozenie wzmocnienia przez probke sinusa

				modulujacy=((long)(gain)*y_t);
				modulujacy>>=15;

				//zmodulowanie sygnalu wejsciowego
				zmodulowany=((long)(modulujacy)*(*sygnal_wejsciowy));
				zmodulowany>>=15;
				//suma i na wyjscie
				modulujacy=zmodulowany+*sygnal_wejsciowy;


				return (Int16) modulujacy;

}
