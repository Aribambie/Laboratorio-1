//*****************************************************************************
// Universidad del Valle de Guatemala
// Electrónica Digital 2
// Archivo: Laboratorio 1
// Hardware: ATMega328p
// Autor: Adriana Marcela Gonzalez
// Carnet: 22438
//*****************************************************************************
// Librerías
//*****************************************************************************
#define F_CPU 16000000

// Librerías incluidas a lo largo del programa
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Display/Display.h"

#define DEBOUNCE_TIME 25 // Tiempo de delay para el anti-rrebote

//*****************************************************************************
// Prototipos de función
//*****************************************************************************
void initPorts(void); // Función para iniciar puertos 
void blueleds(void); // Función para los leds del jugador 1 (azul)
void redleds(void); // Función para los leds del jugador 2 (rojo)
void ledsoff(void); // Función para apagar todos los leds

//*****************************************************************************
// Variables globales
//*****************************************************************************
volatile uint8_t start = 0; // Variable de inicio del juego 
volatile uint8_t bloquear = 1; // Variable de bloqueo 
volatile uint8_t redcount = 0; // Contador 2
volatile uint8_t bluecount = 0; // Contador 1

//*****************************************************************************
// Código principal
//*****************************************************************************

int main(void) {
    initPorts();
    initDisplay();
    displaynum(0); //Se despliega un cero en el display inicialmente 
    
    // Habilitar las interrupciones globales
    sei();
    
    // Apagar los LEDs
    PORTB &= ~((1 << PORTB0)|(1 << PORTB1)|(1 << PORTB2)|(1 << PORTB3)|(1 << PORTB5));
    PORTC &= ~((1 << PORTC0)|(1 << PORTC1)|(1 << PORTC2));
    
    while (1) {
   
    }
}

//*****************************************************************************
// Subrutinas
//*****************************************************************************
void initPorts(void) {
    // Configurar botones como entradas
    DDRB &= ~(1 << DDB4);
    DDRC &= ~(1 << DDC4);
	DDRD &= ~(1 << DDD7);
	
    // Habilitar pull-up en los botones
    PORTB |= (1 << DDB4);
    PORTC |= (1 << DDC4);
	PORTD |= (1 << DDD7);
    
    // Habilitar ISR para PB4, PC4 y PD7
    PCICR |= (1 << PCIE0) | (1 << PCIE1) | (1 << PCIE2);
    
    // Habilitar los botones para que funcionen con la interrupción
    PCMSK0 |= (1 << PCINT4);
    PCMSK1 |= (1 << PCINT12);
	PCMSK2 |= (1 << PCINT23);
    
    // Configurar LEDs como salidas
    DDRC |= ((1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3));
    DDRB |= ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3));
}

void blueleds(void) {
    switch (bluecount) {
        case 1: 
		PORTB = (PORTB & 0xF0) | 0x01; 
		break; // Encender PB0
        case 2: 
		PORTB = (PORTB & 0xF0) | 0x03; 
		break; // Encender PB0 y PB1
        case 3: 
		PORTB = (PORTB & 0xF0) | 0x07; 
		break; // Encender PB0, PB1 y PB2
        case 4: 
		PORTB = (PORTB & 0xF0) | 0x0F; // Encender todos los bits bajos
		// Apagar los leds del otro jugador 
		PORTC = (PORTC & 0xF0) | 0x00; 
		PORTB &= ~(1 << PORTB5);
                bloquear = 1; // Bloquear el juego de nuevo
                start = 0; // Terminar el juego 
                displaynum(1); // Jugador azul gana
                redcount = 0; // Reiniciar los contadores 
                bluecount = 0;
                break;
    }
}

void redleds(void) {
    switch (redcount) {
        case 1: 
		PORTC = (PORTC & 0xF0) | 0x04; 
		break; // Encender PC0
        case 2: 
		PORTC = (PORTC & 0xF0) | 0x06; 
		break; // Encender PC0 y PC1
        case 3: 
		PORTC = (PORTC & 0xF0) | 0x07; 
		break; // Encender PC0, PC1 y PC2
        case 4: 
		PORTB |= (1 << PORTB5); // Encender PB5
		PORTC = (PORTC & 0xF0) | 0x0F; // Encender todos los bits bajos
		PORTB = (PORTB & 0xF0) | 0x00; // Apagar los leds del oponente
                bloquear = 1; // Bloquear el juego de nuevo
                start = 0; // Terminar el juego 
                displaynum(2); // Jugador rojo gana
                redcount = 0; // Reiniciar los contadores 
                bluecount = 0;
                break;
    }
}

void ledsoff(void) {
	// Apagar todos los leds 
	PORTC = (PORTC & 0xF0) | 0x00; 
	PORTB = (PORTB & 0xF0) | 0x00;
	PORTB &= ~(1 << PORTB5);  
}

//*****************************************************************************
// ISR
//*****************************************************************************
ISR(PCINT0_vect) {
	_delay_ms(DEBOUNCE_TIME); // Anti-rrebote
    if (!(PINB & (1 << PINB4))) {  // Botón de inicio
		ledsoff(); // Apagar todos los leds 
		// Iniciar un conteo regresivo para el inicio del juego 
        displaynum(5);
        _delay_ms(1000);
        displaynum(4);
        _delay_ms(1000);
        displaynum(3);
        _delay_ms(1000);
        displaynum(2);
        _delay_ms(1000);
        displaynum(1);
        _delay_ms(1000);
        displaynum(0);
        
		// Iniciar y desbloquear el juego 
        bloquear = 0;
        start = 1;
    }
}

// Interrupción para el botón rojo 
ISR(PCINT2_vect) {
    if (start && !bloquear) { // Verificar que el juego este habilitado
        if (!(PIND & (1 << PIND7))) {  // Botón del jugador rojo
			_delay_ms(DEBOUNCE_TIME); // Anti-rrebote
			if (!(PIND & (1 << PIND7))){
			 if (redcount < 4) {
                redcount++;
                redleds();
            }
		  }
		}
    
	}
}

ISR(PCINT1_vect) {
	if (start && !bloquear) { // Verificar que el juego este habilitado
	    if (!(PINC & (1 << PINC4))) {  // Botón del jugador azul
		    _delay_ms(DEBOUNCE_TIME); // Anti-rrebote
		    if (!(PINC & (1 << PINC4))){
			    if (bluecount < 4) {
				    bluecount++;
				    blueleds();
			    }
		    }
	    }
    }
}

