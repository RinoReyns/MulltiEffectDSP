/*
 * flanger.h
 *
 *  Created on: 9 paü 2016
 *      Author: £ukasz Pindor
 */

#ifndef FLANGER_H_
#define FLANGER_H_

void flanger_init(char* opoznienie,  char* lfo_frequency);

Int16 flanger(Int16* sygnal_wejsciowy, char* lfo_amplitude, char* volume);

#endif /* FLANGER_H_ */
