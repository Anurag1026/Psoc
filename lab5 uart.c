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
#include <stdio.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
UART_Start();
ADC_Start();
ADC_StartConvert();
uint16 i;
char buff[]={'\0'};

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
  
    {
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        i=ADC_GetResult16(0);
          
       sprintf(buff,"the value of ADC is: %d\r\n",i);
  UART_PutString(buff);
    //UART_WriteTxData(i);
    CyDelay(500);/* Place your application code here. */
    }
   
    
}

/* [] END OF FILE */
