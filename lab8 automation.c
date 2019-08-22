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

CYBLE_CONN_HANDLE_T connectionHandle;
CYBLE_GATTS_WRITE_REQ_PARAM_T *wrReqParam;  //structure reference. 
//store data received from client into a structure. write request event is going to be handled 
uint8 DevType, DevCode, DevParam;

void HandleDevice(){
    
    switch(DevType){
        
        case 1:{
        if(DevCode==1)
        {
            RLED_Write(DevParam);
             GLED_Write(1);
        }
        if(DevCode==2)
        {
            GLED_Write(DevParam);
            RLED_Write(1);
            
        }
        
            break;
        }
        case 2:{
            if(DevCode==1)
        {
           PWM_WriteCompare(DevParam);
        } 
            break;
        }
    }
    
}

void CustomEventHandler(uint32 event, void* eventParam)
{
    switch(event)
    {
        
        case CYBLE_EVT_STACK_ON:        
            CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            break;
            
        case CYBLE_EVT_GAP_DEVICE_DISCONNECTED:         
             CyBle_GappStartAdvertisement(CYBLE_ADVERTISING_FAST);
            break;
            
        case CYBLE_EVT_GATT_CONNECT_IND:            
            connectionHandle = *(CYBLE_CONN_HANDLE_T *)eventParam;
            break;
            
        case CYBLE_EVT_GATTS_WRITE_REQ:         //write request from client
            //geta array of 3 bytes, convert event parameter to home automation structure
            //wrReqParam is a structure
            wrReqParam = (CYBLE_GATTS_WRITE_REQ_PARAM_T *) eventParam;  //typecasted it to cyble type
            
            //validate data before doing anything, compare recieved data and fields in home automation characteristics
       
            if (CYBLE_CUSTOM_SERVICE_CUSTOM_CHARACTERISTIC_CHAR_HANDLE == wrReqParam->handleValPair.attrHandle)
            {
                DevType = (uint8)wrReqParam->handleValPair.value.val[0]; //first byte typecasted to uint8 & copied into DevTye
                DevCode = (uint8)wrReqParam->handleValPair.value.val[1]; //second byte
                DevParam = (uint8)wrReqParam->handleValPair.value.val[2]; //third byte
                 
                HandleDevice();     //call function to control devices
                CyBle_GattsWriteRsp(connectionHandle);  //send ack to mobile if data is validated
            }
            break;

        default:break;    
    }
    
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    CyBle_Start(CustomEventHandler);
    PWM_Start();
    CLK_Start();    
    for(;;)
    {
        CyBle_ProcessEvents();
    }
}

/* [] END OF FILE */