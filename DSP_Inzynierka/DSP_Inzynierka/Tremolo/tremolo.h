/*
 * tremolo.h
 *
 *  Created on: 16 lis 2016
 *      Author: Weronika Majewska
 */
#include "lfo_type.h"
#include "usbstk5515.h"
#ifndef TREMOLO_H_
#define TREMOLO_H_

void tremolo_init(char *czestotliwosc_LFO);
Int16 tremolo(Int16* sygnal_wejsciowy, char* volume, typ_LFO* typ_LFO);


#endif /* TREMOLO_H_ */
