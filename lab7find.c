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
void Stack_Handler(uint32 eventcode,void*eventParam){
    switch(eventcode)
    {
    case CYBLE_EVT_STACK_ON:
    case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:
    CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
    break;
    
    }
}
void Ias_Handler(uint32 eventcode, void *eventParam){
    uint8 alert,a,b;
    CyBle_IassGetCharacteristicValue(CYBLE_IAS_ALERT_LEVEL,sizeof(alert),&alert);
    if(alert==0x01)
    {   
        for(a=0;a<=2;a++){
        LEDG_Write(0);
        CyDelay(1000);
        LEDG_Write(1);
        CyDelay(1000);
        }
    }
    else if(alert==0x02)
    {   
         for(b=0;b<=9;b++){
        LEDR_Write(0);
        CyDelay(500);
        LEDR_Write(1);
        CyDelay
        (500);
        }
    }
    else if(alert==0x00){
        LEDG_Write(1);
        LEDR_Write(1);
    }
}
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    CyBle_Start(Stack_Handler);
    CyBle_IasRegisterAttrCallback(Ias_Handler);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        CyBle_ProcessEvents();
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
