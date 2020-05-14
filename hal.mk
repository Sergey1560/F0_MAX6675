
C_SOURCES += \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_ll_usb.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_spi.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_spi_ex.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c \
Lib/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c \

C_SOURCES += \
Lib/STM32F0xx_HAL_Driver_conf/stm32f0xx_hal_msp.c \
Lib/STM32F0xx_HAL_Driver_conf/stm32f0xx_it.c


C_INCLUDES +=  \
-ILib/STM32F0xx_HAL_Driver/Inc \
-ILib/STM32F0xx_HAL_Driver/Inc/Legacy \
-ILib/STM32F0xx_HAL_Driver_conf 

C_DEFS +=  \
-DUSE_HAL_DRIVER \
