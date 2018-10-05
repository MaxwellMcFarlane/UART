#include "test_uart_nb.h"

void test_1_nb(){
        uart_write_nb('H');
        uart_write_nb('e');
        uart_write_nb('l');
        uart_write_nb('l');
        uart_write_nb('o');
        uart_write_nb(' ');
        uart_write_nb('M');
        uart_write_nb('a');
        uart_write_nb('x');
        uart_write_nb('w');
        uart_write_nb('e');
        uart_write_nb('l');
        uart_write_nb('l');
        uart_write_nb(':');
        uart_write_nb(')');
        uart_write_nb('\r');
        uart_write_nb('\n');
}

void test_2_nb(){
    while(1){
        char c = uart_read_nb();
        uart_write_nb(c);
        uart_write_nb('\r');
        uart_write_nb('\n');
        uart_write_nb(c);
    }
}
