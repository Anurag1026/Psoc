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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    pwm_Start();
    clk_Start();
    uint8 i;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        for(i=0;i<=255;i++){
            pwm_WriteCompare(i);
            CyDelay(20);
        }
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
