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
//#include <Cypins.h>
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   if(sw_Read()==0){
    
        led_Write(0);
        CyDelay(1000);
    }   
        else{
        led_Write(1);
        CyDelay(500);}
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
