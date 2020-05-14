C_SOURCES += \
Lib/USB_conf/usb_device.c \
Lib/USB_conf/usbd_conf.c \
Lib/USB_conf/usbd_desc.c \
Lib/USB_conf/usbd_cdc_if.c \
Lib/STM32_USB_Device_Library/Core/Src/usbd_core.c \
Lib/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
Lib/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c \
Lib/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c  

C_INCLUDES +=  \
-ILib/USB_conf \
-ILib/STM32_USB_Device_Library/Core/Inc \
-ILib/STM32_USB_Device_Library/Class/CDC/Inc \
