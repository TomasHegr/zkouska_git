#include <stdbool.h>
#include <stm8s.h>
//#include <stdio.h>
#include "main.h"
#include "milis.h"
//#include "delay.h"
//#include "uart1.h"

void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();
    //init_uart1();

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(BTN_PORT, BTN_PIN, GPIO_MODE_IN_PU_NO_IT);
}


int main(void)
{
  
    uint32_t time = 0;
    uint8_t memory=0;
    init();

    while (1) {
        if (milis() - time > 333 ) {
            time = milis();
            if(PUSH(BTN)==1 && memory==0){  //rozvsícení led tlačítkem
                REVERSE(LED); 
            }
            memory=PUSH(BTN);
            
            
            //printf("%ld\n", time);
        }
        //delay_ms(333);
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
