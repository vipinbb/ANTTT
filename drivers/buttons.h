/***********************************************************************************************************************
File: buttons.h                                                                
***********************************************************************************************************************/

#ifndef __BUTTONS_H
#define __BUTTONS_H

#include "configuration.h"

/***********************************************************************************************************************
Type Definitions
***********************************************************************************************************************/
typedef enum {RELEASED, PRESSED} ButtonStateType; 
typedef enum {BUTTON_ACTIVE_LOW = 0, BUTTON_ACTIVE_HIGH = 1} ButtonActiveType;

typedef struct 
{
  ButtonActiveType eActiveState;
  ButtonPortType ePort;
}ButtonConfigType;


/***********************************************************************************************************************
Constants / Definitions
***********************************************************************************************************************/
#define BUTTON_INIT_MSG_TIMEOUT         (u32)1000     /* Time in ms for init message to send */
#define BUTTON_DEBOUNCE_TIME            (u32)25       /* Time in ms for button debouncing */
#define TOTAL_BUTTONS                   (u8)9
#define BUTTON_COLUMN_SWITCH_TIME_MS    50            // Time in ms for switching of the button column line 

#define BUTTON_ROW1_GPIOTE_CHANNEL      0
#define BUTTON_ROW2_GPIOTE_CHANNEL      1
#define BUTTON_ROW3_GPIOTE_CHANNEL      2

#define BUTTON_ROW1_PIN                 P0_26_INDEX
#define BUTTON_ROW2_PIN                 P0_08_INDEX
#define BUTTON_ROW3_PIN                 P0_09_INDEX

#define BUTTON_COL1_PIN                 P0_14_INDEX
#define BUTTON_COL2_PIN                 P0_15_INDEX
#define BUTTON_COL3_PIN                 P0_23_INDEX

/***********************************************************************************************************************
Function Declarations
***********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/
bool IsButtonPressed(u32 u32Button_);
bool WasButtonPressed(u32 u32Button_);
void ButtonAcknowledge(u32 u32Button_);
bool IsButtonHeld(u32 u32Button_, u32 u32ButtonHeldTime_);

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/
void ButtonInitialize(void);                        
void ButtonRunActiveState(void);
u8 Button_get_active_column(void);

/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/
static void Button_rotate_columns(void);

/***********************************************************************************************************************
State Machine Declarations
***********************************************************************************************************************/
static void ButtonSM_Idle(void);                
static void ButtonSM_ButtonActive(void);        


#endif /* __BUTTONS_H */

/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
