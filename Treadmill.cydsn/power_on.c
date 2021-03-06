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
#include <math.h>

/*
 * Plays a note 
 * @param duration  The duration of the note in ms
 */
void playNote(double frequency, int duration) {
    
    int halfPeriod = (int) ceil(1000.0 / (2.0 * frequency));
    int cycles = duration / halfPeriod;
    
    int i;
    for(i = 0; i < cycles; i++){
        CyPins_SetPin( SpeakerPin_0 );
        CyDelay( ceil(halfPeriod) );
        CyPins_ClearPin( SpeakerPin_0 );
        CyDelay( ceil(halfPeriod) );
    }
}

void startup_music(){
    
    double noteFreq[] = { 400 , 200, 400};
    int noteDur[] = { 200, 200, 200 };
    
    int i;
    for(i = 0; i < 3; i++){
        playNote(noteFreq[i], noteDur[i]);
    }
}

void startup_display(){
    
    LCD_Init();
    
    //fill top with blocks in 100ms intervals
    LCD_Position(0,0);
    LCD_PutChar(LCD_CUSTOM_6);
    
    int i;
    for(i = 1; i < 16; i++){
        LCD_Position(0,i);
        LCD_PutChar(LCD_CUSTOM_6);
        
        LCD_Position(0,i-1);
        LCD_PutChar(LCD_CUSTOM_7);
        
        CyDelay(100);
    }
    
    LCD_ClearDisplay();
    
    //Display welcome text
    LCD_Position(0,3);
    LCD_PrintString("Welcome to");
    
    LCD_Position(1,2);
    LCD_PrintString("my treadmill");
    
    //Pause so user can read it, then clear
    CyDelay(1500);
    LCD_ClearDisplay();    
}



/* [] END OF FILE */