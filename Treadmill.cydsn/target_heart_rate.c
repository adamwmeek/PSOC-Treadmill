/* ========================================
 *
 * This file contains target_heart_rate, the
 * system that sets and attempts to maintain
 * a target heart rate
 *
 * @Author Adam Meek meeka@msoe.edu
 *
 * ========================================
*/

#include <target_heart_rate.h>
#include <math.h>

/*
 * Sets the target heart rate for the user based on age.
 * @param age   the age of the user
*/
void setTarget(double age){
    
    //TODO: Possibly check resting heart rate of user?
    
    if(age > 219){
        age = 219;
    }
    
    target_heart_rate = ceil((220 - age) * 0.7);
}
/*
 * Returns how much slower the user's heart rate is than the target. 
 * If the user's heart rate is faster than the target, the value is negative.
*/
double checkHeartRate(){
    
    return target_heart_rate - getUserHeartRate();
}

double getUserHeartRate(){
    
    //TODO: Aquire user's heart rate from hardware
    return 0;
}


/* [] END OF FILE */
