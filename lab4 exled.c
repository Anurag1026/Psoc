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
    uint8 i;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {   
        for(i=0;i<=15;i++)
        {
        controlreg_Write(i);
        CyDelay(500);
        }
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
