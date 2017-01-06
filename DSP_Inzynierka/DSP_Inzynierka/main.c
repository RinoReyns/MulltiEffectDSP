#include "usbstk5515.h"
#include "usbstk5515_led.h"
#include "aic3204.h"
#include "PLL.h"
#include "bargraph.h"
#include "oled.h"
#include "pushbuttons.h"
#include "stereo.h"
#include "math.h"
#include "stdio.h"
#include "dsplib.h"
#include "EffectsList.h"


Int16 lewy_wejscie;
Int16 prawy_wejscie;
Int16 lewy_wyjscie;
Int16 prawy_wyjscie;
Int16 mono_wejscie;


// Czêstotliwoœæ próbkowania (48 kHz)
#define CZESTOTL_PROBKOWANIA 48000L

// Wzmocnienie wejœcia w dB: 0 dla wejœcia liniowego, 30 dla mikrofonowego
#define WZMOCNIENIE_WEJSCIA_dB 0

char effect_count=0;
void main( void )
{
	// Inicjalizacja p³ytki
		USBSTK5515_init();			// BSL
		pll_frequency_setup(60);	// PLL
		aic3204_hardware_init();	// I2C
		aic3204_init();				// kodek AIC3204
		USBSTK5515_ULED_init();		// diody LED
		asm(" bclr XF");				// diody off
		oled_init();				// wyœwielacz LED 2x19 znaków
		SAR_init();					// przyciski


	// ustawienie czêstotliwoœci próbkowania i wzmocnienia wejœcia
	set_sampling_frequency_and_gain(CZESTOTL_PROBKOWANIA, WZMOCNIENIE_WEJSCIA_dB);


	// Przetwarzanie próbek sygna³u w pêtli
	while (1) 
	{

		// odczyt próbek audio, zamiana na mono
		aic3204_codec_read(&lewy_wejscie, &prawy_wejscie);
		mono_wejscie = stereo_to_mono(lewy_wejscie, prawy_wejscie);
		mono_wejscie=effect_chaine(mono_wejscie);
		lewy_wyjscie=mono_wejscie;
		prawy_wyjscie=mono_wejscie;

		// zapisanie wartoœci na wyjœcie audio
		aic3204_codec_write(lewy_wyjscie, prawy_wyjscie);

		// diody pokazuj¹ poziom sygna³u
		bargraph_6dB(lewy_wyjscie, prawy_wyjscie);

		// interface
		if (effect_count==0)
		{
			effect_count=list_Of_Effects();
			if(effect_count!=0)
				init_List();
		}
		else
		{
			effect_count=chosen_Effect(&effect_count);
		}


	}

}


