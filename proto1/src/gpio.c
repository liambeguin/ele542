/*
 * This file is part of Lab1 ELE542
 *
 * "THE BEER-WARE LICENSE" (Revision 42):
 *  As long as you retain this notice you can do whatever you want with this
 *  stuff. If we meet some day, and you think this stuff is worth it,
 *  you can buy us a beer in return.
 *  If you use this at ETS, beware of the shool's policy against copying
 *  and fraud.
 *
 *   Filename : gpio.c
 * Created on : Jul 11, 2016
 *    Authors : Jeremie Venne <jeremie.k.venne@gmail.com>
 *              Liam Beguin <liambeguin@gmail.com>
 *
 */

#include "inc/platform.h"
#include "inc/gpio.h"


/*
 * More info:
 * https://cours.etsmtl.ca/ele542/labo/Ref-STK500-ATMega32/ATMega32-Complete.pdf
 * Page 49
 */

void gpio_set_input(gpio_port_t port, uint8_t gpio_mask) {

	switch(port) {
		case GPIO_PORT_A: DDRA &= ~(gpio_mask); break;
		case GPIO_PORT_B: DDRB &= ~(gpio_mask); break;
		case GPIO_PORT_C: DDRC &= ~(gpio_mask); break;
		case GPIO_PORT_D: DDRD &= ~(gpio_mask); break;
	}
}
void gpio_set_output(gpio_port_t port, uint8_t gpio_mask) {

	switch(port) {
		case GPIO_PORT_A: DDRA |= gpio_mask; break;
		case GPIO_PORT_B: DDRB |= gpio_mask; break;
		case GPIO_PORT_C: DDRC |= gpio_mask; break;
		case GPIO_PORT_D: DDRD |= gpio_mask; break;
	}
}
void gpio_pin_set(gpio_port_t port, uint8_t gpio_mask) {

	switch(port) {
		case GPIO_PORT_A: PORTA |= gpio_mask; break;
		case GPIO_PORT_B: PORTB |= gpio_mask; break;
		case GPIO_PORT_C: PORTC |= gpio_mask; break;
		case GPIO_PORT_D: PORTD |= gpio_mask; break;
	}
}

void gpio_pin_clear(gpio_port_t port, uint8_t gpio_mask) {

	switch(port) {
		case GPIO_PORT_A: PORTA &= ~(gpio_mask); break;
		case GPIO_PORT_B: PORTB &= ~(gpio_mask); break;
		case GPIO_PORT_C: PORTC &= ~(gpio_mask); break;
		case GPIO_PORT_D: PORTD &= ~(gpio_mask); break;
	}
}
void gpio_pin_toggle(gpio_port_t port, uint8_t gpio_mask) {

	switch(port) {
		case GPIO_PORT_A: PORTA ^= gpio_mask; break;
		case GPIO_PORT_B: PORTB ^= gpio_mask; break;
		case GPIO_PORT_C: PORTC ^= gpio_mask; break;
		case GPIO_PORT_D: PORTD ^= gpio_mask; break;
	}
}
void gpio_port_set(gpio_port_t port, uint8_t value) {

	switch(port) {
		case GPIO_PORT_A: PORTA = value; break;
		case GPIO_PORT_B: PORTB = value; break;
		case GPIO_PORT_C: PORTC = value; break;
		case GPIO_PORT_D: PORTD = value; break;
	}
}
uint8_t gpio_port_read(gpio_port_t port) {

	uint8_t data = 0x00;

	switch(port) {
		case GPIO_PORT_A: data = PINA; break;
		case GPIO_PORT_B: data = PINB; break;
		case GPIO_PORT_C: data = PINC; break;
		case GPIO_PORT_D: data = PIND; break;
	}
	return data;
}
uint8_t gpio_pin_read(gpio_port_t port, uint8_t pin) {

	return gpio_port_read(port) & pin;
}
