/*******************************************************************************
* File Name: SpeakerPin.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SpeakerPin_H) /* Pins SpeakerPin_H */
#define CY_PINS_SpeakerPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SpeakerPin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SpeakerPin__PORT == 15 && ((SpeakerPin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SpeakerPin_Write(uint8 value) ;
void    SpeakerPin_SetDriveMode(uint8 mode) ;
uint8   SpeakerPin_ReadDataReg(void) ;
uint8   SpeakerPin_Read(void) ;
uint8   SpeakerPin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SpeakerPin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SpeakerPin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SpeakerPin_DM_RES_UP          PIN_DM_RES_UP
#define SpeakerPin_DM_RES_DWN         PIN_DM_RES_DWN
#define SpeakerPin_DM_OD_LO           PIN_DM_OD_LO
#define SpeakerPin_DM_OD_HI           PIN_DM_OD_HI
#define SpeakerPin_DM_STRONG          PIN_DM_STRONG
#define SpeakerPin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SpeakerPin_MASK               SpeakerPin__MASK
#define SpeakerPin_SHIFT              SpeakerPin__SHIFT
#define SpeakerPin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SpeakerPin_PS                     (* (reg8 *) SpeakerPin__PS)
/* Data Register */
#define SpeakerPin_DR                     (* (reg8 *) SpeakerPin__DR)
/* Port Number */
#define SpeakerPin_PRT_NUM                (* (reg8 *) SpeakerPin__PRT) 
/* Connect to Analog Globals */                                                  
#define SpeakerPin_AG                     (* (reg8 *) SpeakerPin__AG)                       
/* Analog MUX bux enable */
#define SpeakerPin_AMUX                   (* (reg8 *) SpeakerPin__AMUX) 
/* Bidirectional Enable */                                                        
#define SpeakerPin_BIE                    (* (reg8 *) SpeakerPin__BIE)
/* Bit-mask for Aliased Register Access */
#define SpeakerPin_BIT_MASK               (* (reg8 *) SpeakerPin__BIT_MASK)
/* Bypass Enable */
#define SpeakerPin_BYP                    (* (reg8 *) SpeakerPin__BYP)
/* Port wide control signals */                                                   
#define SpeakerPin_CTL                    (* (reg8 *) SpeakerPin__CTL)
/* Drive Modes */
#define SpeakerPin_DM0                    (* (reg8 *) SpeakerPin__DM0) 
#define SpeakerPin_DM1                    (* (reg8 *) SpeakerPin__DM1)
#define SpeakerPin_DM2                    (* (reg8 *) SpeakerPin__DM2) 
/* Input Buffer Disable Override */
#define SpeakerPin_INP_DIS                (* (reg8 *) SpeakerPin__INP_DIS)
/* LCD Common or Segment Drive */
#define SpeakerPin_LCD_COM_SEG            (* (reg8 *) SpeakerPin__LCD_COM_SEG)
/* Enable Segment LCD */
#define SpeakerPin_LCD_EN                 (* (reg8 *) SpeakerPin__LCD_EN)
/* Slew Rate Control */
#define SpeakerPin_SLW                    (* (reg8 *) SpeakerPin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SpeakerPin_PRTDSI__CAPS_SEL       (* (reg8 *) SpeakerPin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SpeakerPin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SpeakerPin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SpeakerPin_PRTDSI__OE_SEL0        (* (reg8 *) SpeakerPin__PRTDSI__OE_SEL0) 
#define SpeakerPin_PRTDSI__OE_SEL1        (* (reg8 *) SpeakerPin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SpeakerPin_PRTDSI__OUT_SEL0       (* (reg8 *) SpeakerPin__PRTDSI__OUT_SEL0) 
#define SpeakerPin_PRTDSI__OUT_SEL1       (* (reg8 *) SpeakerPin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SpeakerPin_PRTDSI__SYNC_OUT       (* (reg8 *) SpeakerPin__PRTDSI__SYNC_OUT) 


#if defined(SpeakerPin__INTSTAT)  /* Interrupt Registers */

    #define SpeakerPin_INTSTAT                (* (reg8 *) SpeakerPin__INTSTAT)
    #define SpeakerPin_SNAP                   (* (reg8 *) SpeakerPin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SpeakerPin_H */


/* [] END OF FILE */
