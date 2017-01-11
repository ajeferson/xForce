#include "stm32f4xx.h"
#include "defines.h"
#include "tm_stm32f4_disco.h"

int main(void) {
    /* Initialize System */
    SystemInit();

    /* Initialize leds on board */
    TM_DISCO_LedInit();

    /* Initialize button on board */
    TM_DISCO_ButtonInit();

    while(1) {
        /* If button pressed */
        if (TM_DISCO_ButtonPressed()) {
            /* Turn on leds */
            TM_DISCO_LedOn(LED_RED | LED_GREEN);
        } else {
            /* Turn off leds */
            TM_DISCO_LedOff(LED_RED | LED_GREEN);
        }
    }
}

/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  return -1;
}
