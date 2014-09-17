/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <power_on.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Init();
    LCD_Position(1,2);
    LCD_PrintString("Hello, world!");
    startup_music();
   
    uint16_t time = 0;
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        LCD_Position(0,2);
        switch(time % 4)
        {
            case 0: LCD_PutChar(LCD_CUSTOM_0); break;
            case 1: LCD_PutChar(LCD_CUSTOM_1); break;
            case 2: LCD_PutChar(LCD_CUSTOM_2); break;
            case 3: LCD_PutChar(LCD_CUSTOM_1); break;
            default: LCD_PutChar(LCD_CUSTOM_2);
        }
        CyDelay(300);
        time++;
    }
}

/* [] END OF FILE */
