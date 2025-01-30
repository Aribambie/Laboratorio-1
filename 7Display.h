/*
 * _7Display.h
 *
 * Created: 23/01/2025 10:16:19
 *  Author: Adriana Gonzalez
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

// Función para inicializar pines para Display 
void initDisplay(void);
// Función para desplegar un número 
void displaynum(uint8_t num);
// Función para desplegar el punto
void displayp(uint8_t point);


#endif /* 7DISPLAY_H_ */
