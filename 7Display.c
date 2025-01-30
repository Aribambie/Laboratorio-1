/*
 * _7Display.c
 *
 * Created: 23/01/2025 10:16:41
 *  Author: Adriana Gonzalez 
 */ 
#include <avr/io.h>
#include <util/delay.h>

// Función para inicializar pines para Display
void initDisplay(void){
	 UCSR0B = 0;  // Desactiva la transmisión y la recepción
	 DDRD = 0xFF;
}
// Función para desplegar un número
void displaynum(uint8_t num){
	switch(num){
		case 0:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD |= (1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD &= ~(1 << PORTD6); //g
		break;
		case 1:
		PORTD |= (1 << PORTD0); //b
		PORTD &= ~(1 << PORTD1); //a
		PORTD |= (1 << PORTD2); //c
		PORTD &= ~(1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD &= ~(1 << PORTD5); //f
		PORTD &= ~(1 << PORTD6); //g
		break;
		case 2:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD &= ~(1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD |= (1 << PORTD4); //e
		PORTD &= ~(1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 3:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD &= ~(1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 4:
		PORTD |= (1 << PORTD0); //a
		PORTD &= ~(1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD &= ~(1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 5:
		PORTD &= ~(1 << PORTD0); //b
		PORTD |= (1 << PORTD1); //a
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 6:
		PORTD |= (1 << PORTD0); //a
		PORTD &= ~(1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD |= (1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 7:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD &= ~(1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD &= ~(1 << PORTD5); //f
		PORTD &= ~(1 << PORTD6); //g
		break;
		case 8:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD |= (1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
		case 9:
		PORTD |= (1 << PORTD0); //a
		PORTD |= (1 << PORTD1); //b
		PORTD |= (1 << PORTD2); //c
		PORTD |= (1 << PORTD3); //d
		PORTD &= ~(1 << PORTD4); //e
		PORTD |= (1 << PORTD5); //f
		PORTD |= (1 << PORTD6); //g
		break;
	}
}

// Función para desplegar el punto
void displayp(uint8_t point){
	DDRD |= (1 << DDD7);
	_delay_ms(500);
	DDRD &= ~(1 << DDD7);
	_delay_ms(500);
}


