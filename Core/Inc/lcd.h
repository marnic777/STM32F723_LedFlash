#ifndef __LCD_H
#define __LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "st7789h2.h"
#include "../Fonts/fonts.h"

#define LCD_OK         ((uint8_t)0x00)
#define LCD_ERROR      ((uint8_t)0x01)
#define LCD_TIMEOUT    ((uint8_t)0x02)

// LCD default font 
#define LCD_DEFAULT_FONT         Font12

// LCD Orientation  
#define  LCD_ORIENTATION_PORTRAIT         ((uint8_t)0x00)  /*!< Portrait orientation choice of LCD screen  */
#define  LCD_ORIENTATION_LANDSCAPE        ((uint8_t)0x01)  /*!< Landscape orientation choice of LCD screen */
#define  LCD_ORIENTATION_LANDSCAPE_ROT180 ((uint32_t)0x02) /*!< Landscape rotated 180° orientation choice of LCD screen */

// LCD color   
#define LCD_COLOR_BLUE          ((uint16_t)0x001F)
#define LCD_COLOR_GREEN         ((uint16_t)0x07E0)
#define LCD_COLOR_RED           ((uint16_t)0xF800)
#define LCD_COLOR_CYAN          ((uint16_t)0x07FF)
#define LCD_COLOR_MAGENTA       ((uint16_t)0xF81F)
#define LCD_COLOR_YELLOW        ((uint16_t)0xFFE0)
#define LCD_COLOR_LIGHTBLUE     ((uint16_t)0x841F)
#define LCD_COLOR_LIGHTGREEN    ((uint16_t)0x87F0)
#define LCD_COLOR_LIGHTRED      ((uint16_t)0xFC10)
#define LCD_COLOR_LIGHTMAGENTA  ((uint16_t)0xFC1F)
#define LCD_COLOR_LIGHTYELLOW   ((uint16_t)0xFFF0)
#define LCD_COLOR_DARKBLUE      ((uint16_t)0x0010)
#define LCD_COLOR_DARKGREEN     ((uint16_t)0x0400)
#define LCD_COLOR_DARKRED       ((uint16_t)0x8000)
#define LCD_COLOR_DARKCYAN      ((uint16_t)0x0410)
#define LCD_COLOR_DARKMAGENTA   ((uint16_t)0x8010)
#define LCD_COLOR_DARKYELLOW    ((uint16_t)0x8400)
#define LCD_COLOR_WHITE         ((uint16_t)0xFFFF)
#define LCD_COLOR_LIGHTGRAY     ((uint16_t)0xD69A)
#define LCD_COLOR_GRAY          ((uint16_t)0x8410)
#define LCD_COLOR_DARKGRAY      ((uint16_t)0x4208)
#define LCD_COLOR_BLACK         ((uint16_t)0x0000)
#define LCD_COLOR_BROWN         ((uint16_t)0xA145)
#define LCD_COLOR_ORANGE        ((uint16_t)0xFD20)

/* LCD special pins */ 
/* LCD reset pin */
#define LCD_RESET_PIN                    GPIO_PIN_7
#define LCD_RESET_GPIO_PORT              GPIOH
#define LCD_RESET_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOH_CLK_ENABLE()
#define LCD_RESET_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOH_CLK_DISABLE()
    
/* LCD tearing effect pin */
#define LCD_TE_PIN                       GPIO_PIN_8
#define LCD_TE_GPIO_PORT                 GPIOC
#define LCD_TE_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOC_CLK_ENABLE()
#define LCD_TE_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOC_CLK_DISABLE()

/* Backlight control pin */
#define LCD_BL_CTRL_PIN                  GPIO_PIN_11
#define LCD_BL_CTRL_GPIO_PORT            GPIOH
#define LCD_BL_CTRL_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOH_CLK_ENABLE()
#define LCD_BL_CTRL_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOH_CLK_DISABLE()

typedef struct 
{ 
  uint32_t TextColor;
  uint32_t BackColor;
  sFONT    *pFont; 
} LCD_DrawPropTypeDef;

  
/* Structure to represent a point with X and Y coordinates */
typedef struct 
{
    int16_t X;
    int16_t Y;
} Point, *pPoint;

typedef enum
{
  CENTER_MODE          = 0x01,    /* Center mode */
  RIGHT_MODE           = 0x02,    /* Right mode  */
  LEFT_MODE            = 0x03     /* Left mode   */
} Line_ModeTypdef;

// Exported_Functions STM32F723E DISCOVERY LCD Exported Functions
uint8_t  LCD_Init(void);
uint8_t  LCD_InitEx(uint32_t orientation);
uint8_t  LCD_DeInit(void);
uint32_t LCD_GetXSize(void);
uint32_t LCD_GetYSize(void);
 
uint16_t LCD_GetTextColor(void);
uint16_t LCD_GetBackColor(void);
void     LCD_SetTextColor(__IO uint16_t Color);
void     LCD_SetBackColor(__IO uint16_t Color);
void     LCD_SetFont(sFONT *fonts);
sFONT    *LCD_GetFont(void);

void     LCD_Clear(uint16_t Color);
void     LCD_ClearStringLine(uint16_t Line);
void     LCD_DisplayStringAtLine(uint16_t Line, uint8_t *ptr);
void     LCD_DisplayStringAt(uint16_t Xpos, uint16_t Ypos, uint8_t *Text, Line_ModeTypdef Mode);
void     LCD_DisplayChar(uint16_t Xpos, uint16_t Ypos, uint8_t Ascii);

uint16_t LCD_ReadPixel(uint16_t Xpos, uint16_t Ypos);
void     LCD_DrawPixel(uint16_t Xpos, uint16_t Ypos, uint16_t RGB_Code);
void     LCD_DrawHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     LCD_DrawVLine(uint16_t Xpos, uint16_t Ypos, uint16_t Length);
void     LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void     LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     LCD_DrawPolygon(pPoint Points, uint16_t PointCount);
void     LCD_DrawEllipse(int Xpos, int Ypos, int XRadius, int YRadius);
void     LCD_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp);
void     LCD_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pbmp);
void     LCD_FillRect(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height);
void     LCD_FillCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius);
void     LCD_FillPolygon(pPoint Points, uint16_t PointCount);
void     LCD_FillEllipse(int Xpos, int Ypos, int XRadius, int YRadius);

void     LCD_DisplayOff(void);
void     LCD_DisplayOn(void);

/* These functions can be modified in case the current settings
   need to be changed for specific application needs */
__weak void LCD_MspInit(void);
__weak void LCD_MspDeInit(void);

#ifdef __cplusplus // c++ detection 
}
#endif 

#endif /* __LCD_H */    
