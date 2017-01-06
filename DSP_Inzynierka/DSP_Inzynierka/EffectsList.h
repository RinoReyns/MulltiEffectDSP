/*
 * Interface.h
 *
 *  Created on: 29 paü 2016
 *      Author: £ukasz Pindor
 */

#include "usbstk5515.h"

#ifndef EFFECTSLIST_H_
#define EFFECTSLIST_H_

void init_List();
char list_Of_Effects();
char chosen_Effect(char* effect_Number);
Int16 effect_chaine(Int16 input);

#endif /* EFFECTSLIST_H_ */
