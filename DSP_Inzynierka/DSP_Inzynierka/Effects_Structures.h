/*
 * Effects_Structures.h
 *
 *  Created on: 1 lis 2016
 *      Author: �ukasz Pindor
 */
#include "bool_type.h"
#include "Tremolo/lfo_type.h"
#ifndef EFFECTS_STRUCTURES_H_
#define EFFECTS_STRUCTURES_H_

typedef enum { ms, volume, frequency, ds } kind_of_parameter; /// ms- delay-time, volume - gain(1-100) and volume(0-1) normalized during init of effect, ds-for 1 number step
struct delay_structure
{
	bool On;
	short int opoznienie;
	char gain;

}  delay_structure={false,600,90};


struct delay2_structure
{
	bool On;
	short int opoznienie;
	char FF; //%feedforward
	char BL;  //%blend
	char FB; //%feedbackward

}  delay2_structure={false,400,50,70,50};

struct falnger_chorus_structure
{
	bool On;
	char opoznienie;
	char lfo_frequency;
	char lfo_amplitude;
	char volume;
}	flanger_structure={false,5,1,100,90},chorus_structure={false,5,1,40,90};

struct distortion_structure
{
	bool On;
	char gain; // 1-10
	char mix;
	char volume;
}	distortion_structure={false,2,20,30};

struct tremolo_structure
{
	bool On;
	char lfo_frequency;
	char volume;
	typ_LFO type;
}	tremolo_structure={false,20,50,sinus};


#endif /* EFFECTS_STRUCTURES_H_ */
