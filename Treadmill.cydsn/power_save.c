/* ========================================
 *
 * The power saving software on this PSOC Treadmill.
 *
 * @author Adam Meek    meeka@msoe.edu
 * ========================================
*/

void PsSleep(){
    
    CyPmSaveClocks();
    CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_NONE);
}

/* [] END OF FILE */