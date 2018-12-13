#include <stdint.h>
#include <usb_type.h>
#include <usb_core.h>
#include "usb/cdcusb_app.h"
#include "usb/cdcusb_prop.h"

extern void (*pEpInt_IN[7])(void);
extern void (*pEpInt_OUT[7])(void);
extern void (*pCallbacks[8])(void);

extern DEVICE_INFO Device_Info;
extern DEVICE Device_Table;
extern DEVICE_PROP Device_Property;
extern USER_STANDARD_REQUESTS User_Standard_Requests;

DEVICE_INFO *pDeviceInfo;
DEVICE_INFO *pInformation; // who uses this ??
DEVICE* pDeviceTable;

typedef void (*THandler)(void);

void _Initialize(void* pDeviceInfo, void* pDevice, void* pDeviceProperty, void* pUserStandardRequests,
      THandler arrHandlerIn[], THandler arrHandlerOut[], THandler callbacks[]);

void InitUsb()
{
  pInformation = &Device_Info;
  pDeviceInfo = &Device_Info; // for internal use
  pDeviceTable = &Device_Table; // for internal use
  _Initialize(&Device_Info, &Device_Table, &Device_Property, &User_Standard_Requests, pEpInt_IN, pEpInt_OUT, pCallbacks);
}


void Get_SerialNum()
{
}