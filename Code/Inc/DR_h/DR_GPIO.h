/*
 * DR_GPIO.h
 *
 *  Created on: Dec 29, 2020
 *  Author: Damian Melamed
 */

#ifndef DR_H_DR_GPIO_H_
#define DR_H_DR_GPIO_H_

/*!-----------INCLUDES PUBLICOS-----------------------------------------------------------------------------*/
#include <System.h>
/*!-----------DEFINES Y MACROS PUBLCIAS---------------------------------------------------------------------*/

enum {PORTA, PORTB, PORTC, PORTD, PORTE };

enum {INPUT, OUTPUT};
enum {HIGH, LOW};

enum {INPUT_PULLUP, INPUT_PULLDOWN, INPUT_FLOATING, INPUT_ANALOG};
enum {OUTPUT_PUSHPULL, OUTPUT_OPENDRAIN};
enum {ALTERNATE_PUSHPULL, ALTERNATE_OPENDRAIN};


/*!-----------TIPOS DE DATOS PUBLCIAS-----------------------------------------------------------------------*/

/*!-----------VARIABLES GLOBALES PUBLICAS-------------------------------------------------------------------*/
//extern variables

/*!-----------FUNCIONES-------------------------------------------------------------------------------------*/
void GPIO_setDir(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_setPin(uint8_t port, uint8_t pin, uint8_t val);
uint8_t GPIO_getPin(uint8_t port, uint8_t pin);
void GPIO_setInputMode(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_setOutputMode(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_setAltFunc(uint8_t port, uint8_t pin, uint8_t mode);


#endif /* DR_H_DR_GPIO_H_ */
