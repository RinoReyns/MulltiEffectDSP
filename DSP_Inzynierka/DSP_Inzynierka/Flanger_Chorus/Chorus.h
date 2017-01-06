/*
 * Chorus.h
 *
 *  Created on: 16 paü 2016
 *     Author: £ukasz Pindor
 */

#ifndef CHORUS_H_
#define CHORUS_H_

void chorus_init(char* opoznienie,  char* lfo_frequency);

Int16 chorus(Int16* sygnal_wejsciowy, char* lfo_amplitude, char* volume);

#endif /* CHORUS_H_ */
