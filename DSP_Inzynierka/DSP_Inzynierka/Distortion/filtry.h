/*
 * filtry.h
 */

#ifndef FILTRY_H_
#define FILTRY_H_

const signed int IIR_low_pass_300Hz[5]  = {    13,     13,    13, -31857,  30997 };
const signed int IIR_low_pass_600Hz[5]  = {    48,     48,    48, -30949, 29322  };
const signed int IIR_low_pass_1000Hz[5] = {   128,    128,   128, -29742, 27330  };
const signed int IIR_low_pass_1200Hz[5] = {   181,    181,   181, -29096, 26150  };
const signed int IIR_low_pass_2000Hz[5] = {    472,    472,   472, -26754, 22629  };
const signed int IIR_low_pass_2400Hz[5] = {    658,    658,   658, -25575, 21015  };
const signed int IIR_low_pass_4000Hz[5] = {   1622,   1622,  1622, -20964, 15649  };
const signed int IIR_low_pass_4800Hz[5] = {   2210,   2210,  2210, -18726, 13526  };
const signed int IIR_low_pass_9600Hz[5] = {   6769,   6769,  6768, -6053,  6416  };

#endif
