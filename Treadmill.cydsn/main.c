/* ========================================
 *
 * PSOC-Treadmill 
 * CE 4920 - MSOE
 * 
 * ----------------------------------------
 * This is the main file for the software driving the
 * PSOC Treadmill
 * 
 * @author Adam Meek meeka@msoe.edu
 * ========================================
*/
#include <project.h>
#include <power_on.h>
#include <target_heart_rate.h>

int main(){
    CyGlobalIntEnable;   /* Uncomment this line to enable global interrupts. */
    CapSense_1_Start();
    
    CapSense_1_InitializeAllBaselines();
    CapSense_1_ScanEnabledWidgets();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    uint16_t time = 0;
    
    startup_display();
    startup_music();
    
    LCD_DisplayOff();
    
    for(;;){
        //heartbeat
        LCD_Position(1,15);
        switch(time % 4)
        {
            case 0: LCD_PutChar(LCD_CUSTOM_0); break;
            case 1: LCD_PutChar(LCD_CUSTOM_1); break;
            case 2: LCD_PutChar(LCD_CUSTOM_2); break;
            case 3: LCD_PutChar(LCD_CUSTOM_1); break;
            default: LCD_PutChar(LCD_CUSTOM_2);
        }
        
        if(CapSense_1_IsBusy() == 0){
            CapSense_1_UpdateEnabledBaselines();
            
            int sliderPos = CapSense_1_GetCentroidPos(CapSense_1_LINEARSLIDER0__LS);
            
            if(sliderPos != 65535){
                LCD_DisplayOn();
                LCD_Position(0,0);
                LCD_PrintDecUint16(sliderPos);
            }
        }
        //playNote(440, 300);
        CyDelay(300);
        time++;
        
        if(time == 30){
            LCD_DisplayOff();
            time = 0;
        }
    }
}

/* [] END OF FILE */
