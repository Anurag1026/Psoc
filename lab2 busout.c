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

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
            myreg_Write(0x03);
            CyDelay(500);
            myreg_Write(0x05);
            CyDelay(500);
            myreg_Write(0x06);
            CyDelay(500);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
