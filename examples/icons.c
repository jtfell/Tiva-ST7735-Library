#include "inc/tm4c123gh6pm.h"
#include <stdio.h>
#include <stdint.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/ssi.h"

#include "ST7735.h"


int main(void)
{

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       SYSCTL_OSC_MAIN);
    LcdInit();

    //
    // Loop forever.
    //
    while (1) {

        fillScreen(ST7735_BLACK);

        fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
        fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
        delay_ms(500);

        // pause
        fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);
        fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);
        fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);
        delay_ms(500);

        // play color
        fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
        delay_ms(500);

        // pause color
        fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);
        fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);

        // play color
        fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);

        delay_ms(500);
        fillScreen(ST7735_BLACK);

        drawString("string1", 10, 50, ST7735_WHITE, ST7735_BLACK, 1);

        delay_ms(500);

        drawString("string2", 30, 50, ST7735_WHITE, ST7735_BLACK, 1);

        delay_ms(500);
    }
}



