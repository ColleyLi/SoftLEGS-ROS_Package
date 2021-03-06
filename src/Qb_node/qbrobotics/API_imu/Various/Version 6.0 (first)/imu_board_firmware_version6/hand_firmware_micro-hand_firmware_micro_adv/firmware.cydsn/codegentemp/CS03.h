/*******************************************************************************
* File Name: CS03.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CS03_H) /* Pins CS03_H */
#define CY_PINS_CS03_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS03_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CS03_Write(uint8 value) ;
void    CS03_SetDriveMode(uint8 mode) ;
uint8   CS03_ReadDataReg(void) ;
uint8   CS03_Read(void) ;
void    CS03_SetInterruptMode(uint16 position, uint16 mode) ;
uint8   CS03_ClearInterrupt(void) ;
/** @} general */

/***************************************
*           API Constants        
***************************************/

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CS03_SetDriveMode() function.
     *  @{
     */
        /* Drive Modes */
        #define CS03_DM_ALG_HIZ         PIN_DM_ALG_HIZ   /**< \brief High Impedance Analog   */
        #define CS03_DM_DIG_HIZ         PIN_DM_DIG_HIZ   /**< \brief High Impedance Digital  */
        #define CS03_DM_RES_UP          PIN_DM_RES_UP    /**< \brief Resistive Pull Up       */
        #define CS03_DM_RES_DWN         PIN_DM_RES_DWN   /**< \brief Resistive Pull Down     */
        #define CS03_DM_OD_LO           PIN_DM_OD_LO     /**< \brief Open Drain, Drives Low  */
        #define CS03_DM_OD_HI           PIN_DM_OD_HI     /**< \brief Open Drain, Drives High */
        #define CS03_DM_STRONG          PIN_DM_STRONG    /**< \brief Strong Drive            */
        #define CS03_DM_RES_UPDWN       PIN_DM_RES_UPDWN /**< \brief Resistive Pull Up/Down  */
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CS03_MASK               CS03__MASK
#define CS03_SHIFT              CS03__SHIFT
#define CS03_WIDTH              1u

/* Interrupt constants */
#if defined(CS03__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CS03_SetInterruptMode() function.
     *  @{
     */
        #define CS03_INTR_NONE      (uint16)(0x0000u)   /**< \brief Disabled             */
        #define CS03_INTR_RISING    (uint16)(0x0001u)   /**< \brief Rising edge trigger  */
        #define CS03_INTR_FALLING   (uint16)(0x0002u)   /**< \brief Falling edge trigger */
        #define CS03_INTR_BOTH      (uint16)(0x0003u)   /**< \brief Both edge trigger    */
        /** @} intrMode */
/** @} group_constants */

    #define CS03_INTR_MASK      (0x01u)
#endif /* (CS03__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS03_PS                     (* (reg8 *) CS03__PS)
/* Data Register */
#define CS03_DR                     (* (reg8 *) CS03__DR)
/* Port Number */
#define CS03_PRT_NUM                (* (reg8 *) CS03__PRT) 
/* Connect to Analog Globals */                                                  
#define CS03_AG                     (* (reg8 *) CS03__AG)                       
/* Analog MUX bux enable */
#define CS03_AMUX                   (* (reg8 *) CS03__AMUX) 
/* Bidirectional Enable */                                                        
#define CS03_BIE                    (* (reg8 *) CS03__BIE)
/* Bit-mask for Aliased Register Access */
#define CS03_BIT_MASK               (* (reg8 *) CS03__BIT_MASK)
/* Bypass Enable */
#define CS03_BYP                    (* (reg8 *) CS03__BYP)
/* Port wide control signals */                                                   
#define CS03_CTL                    (* (reg8 *) CS03__CTL)
/* Drive Modes */
#define CS03_DM0                    (* (reg8 *) CS03__DM0) 
#define CS03_DM1                    (* (reg8 *) CS03__DM1)
#define CS03_DM2                    (* (reg8 *) CS03__DM2) 
/* Input Buffer Disable Override */
#define CS03_INP_DIS                (* (reg8 *) CS03__INP_DIS)
/* LCD Common or Segment Drive */
#define CS03_LCD_COM_SEG            (* (reg8 *) CS03__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS03_LCD_EN                 (* (reg8 *) CS03__LCD_EN)
/* Slew Rate Control */
#define CS03_SLW                    (* (reg8 *) CS03__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS03_PRTDSI__CAPS_SEL       (* (reg8 *) CS03__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS03_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS03__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS03_PRTDSI__OE_SEL0        (* (reg8 *) CS03__PRTDSI__OE_SEL0) 
#define CS03_PRTDSI__OE_SEL1        (* (reg8 *) CS03__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS03_PRTDSI__OUT_SEL0       (* (reg8 *) CS03__PRTDSI__OUT_SEL0) 
#define CS03_PRTDSI__OUT_SEL1       (* (reg8 *) CS03__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS03_PRTDSI__SYNC_OUT       (* (reg8 *) CS03__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CS03__SIO_CFG)
    #define CS03_SIO_HYST_EN        (* (reg8 *) CS03__SIO_HYST_EN)
    #define CS03_SIO_REG_HIFREQ     (* (reg8 *) CS03__SIO_REG_HIFREQ)
    #define CS03_SIO_CFG            (* (reg8 *) CS03__SIO_CFG)
    #define CS03_SIO_DIFF           (* (reg8 *) CS03__SIO_DIFF)
#endif /* (CS03__SIO_CFG) */

/* Interrupt Registers */
#if defined(CS03__INTSTAT)
    #define CS03_INTSTAT             (* (reg8 *) CS03__INTSTAT)
    #define CS03_SNAP                (* (reg8 *) CS03__SNAP)
    
	#define CS03_0_INTTYPE_REG 		(* (reg8 *) CS03__0__INTTYPE)
#endif /* (CS03__INTSTAT) */

#endif /* End Pins CS03_H */


/* [] END OF FILE */
