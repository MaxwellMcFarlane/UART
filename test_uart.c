#include "uart.h"

void test_1(){
    while(1){
        uart_write('H');
        uart_write('e');
        uart_write('l');
        uart_write('l');
        uart_write('o');
        uart_write(' ');
        uart_write('M');
        uart_write('a');
        uart_write('x');
        uart_write(':');
        uart_write(')');
        uart_write('\r');
        uart_write('\n');
    }
}

void test_2(){
    while(1){
        char c = uart_read();
        uart_write(c);
        uart_write('\r');
        uart_write('\n');
        uart_write(c);
    }
}
