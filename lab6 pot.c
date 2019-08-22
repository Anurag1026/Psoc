#include <project.h>
#include<stdio.h>

int main()
{
 UART_Start();
 adc_Start();
 adc_StartConvert();
mux_Start();

    CyGlobalIntEnable; /* Enable global interrupts. */
char buff[] = {'\0'};
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    int16 a,b;
    for(;;)
    {
     mux_Select(0);
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    a=adc_GetResult16(0);
    UART_WriteTxData(a);
    mux_Select(1);
    adc_IsEndConversion(adc_WAIT_FOR_RESULT);
    b=adc_GetResult16(0);
    
    UART_WriteTxData(b);
    sprintf(buff,"$%d %d;",a,b);
   UART_PutString(buff);
   
    CyDelay(100);
    /* Place your application code here. */
    }
}

/* [] END OF FILE */