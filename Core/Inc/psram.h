/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PSRAM_H
#define __PSRAM_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

#define PSRAM_OK            ((uint8_t)0x00)
#define PSRAM_ERROR        ((uint8_t)0x01)

#define PSRAM_DEVICE_ADDR  ((uint32_t)0x60000000)
#define PSRAM_DEVICE_SIZE  ((uint32_t)0x80000)  /* SRAM device size in Bytes */  
  
/* #define SRAM_MEMORY_WIDTH    FMC_NORSRAM_MEM_BUS_WIDTH_8*/
#define PSRAM_MEMORY_WIDTH    FMC_NORSRAM_MEM_BUS_WIDTH_16

#define PSRAM_BURSTACCESS     FMC_BURST_ACCESS_MODE_DISABLE
/* #define PSRAM_BURSTACCESS     FMC_BURST_ACCESS_MODE_ENABLE*/
  
#define PSRAM_WRITEBURST      FMC_WRITE_BURST_DISABLE
/* #define PSRAM_WRITEBURST     FMC_WRITE_BURST_ENABLE */
 
#define CONTINUOUSCLOCK_FEATURE    FMC_CONTINUOUS_CLOCK_SYNC_ONLY 
/* #define CONTINUOUSCLOCK_FEATURE     FMC_CONTINUOUS_CLOCK_SYNC_ASYNC */ 

/* DMA definitions for SRAM DMA transfer */
#define __PSRAM_DMAx_CLK_ENABLE            __HAL_RCC_DMA2_CLK_ENABLE
#define __PSRAM_DMAx_CLK_DISABLE           __HAL_RCC_DMA2_CLK_DISABLE
#define PSRAM_DMAx_CHANNEL                 DMA_CHANNEL_0
#define PSRAM_DMAx_STREAM                  DMA2_Stream5  
#define PSRAM_DMAx_IRQn                    DMA2_Stream5_IRQn
#define PSRAM_DMA_IRQHandler           DMA2_Stream5_IRQHandler   

// Exported_Functions PSRAM Exported Functions
uint8_t PSRAM_Init(void);
uint8_t PSRAM_DeInit(void);
uint8_t PSRAM_ReadData(uint32_t uwStartAddress, uint16_t *pData, uint32_t uwDataSize);
uint8_t PSRAM_ReadData_DMA(uint32_t uwStartAddress, uint16_t *pData, uint32_t uwDataSize);
uint8_t PSRAM_WriteData(uint32_t uwStartAddress, uint16_t *pData, uint32_t uwDataSize);
uint8_t PSRAM_WriteData_DMA(uint32_t uwStartAddress, uint16_t *pData, uint32_t uwDataSize);
   
/* These functions can be modified in case the current settings (e.g. DMA stream)
   need to be changed for specific application needs */
void    PSRAM_MspInit(SRAM_HandleTypeDef  *hsram, void *Params);
void    PSRAM_MspDeInit(SRAM_HandleTypeDef  *hsram, void *Params);

#ifdef __cplusplus // c++ detection 
}
#endif  

#endif /* __PSRAM_H */
