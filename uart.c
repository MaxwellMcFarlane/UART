#include "uart.h"

void uart_init(){
    //initialize U1RX & U1TX: w/o ANSELx set digital inputs TRISx
    U1RXR = 0x0; //RPA2 RX
    RPA0R = 0x1; //RPA0 TX
    ANSELA = 0;
    TRISA = 0xffff;
    U1BRG = 260;
    U1STAbits.URXEN = 1;
    U1STAbits.UTXEN = 1;
    U1MODEbits.ON = 1;
    U1MODEbits.BRGH = 0;
    
}

uint8_t uart_read_ready(){
    if(U1STAbits.URXDA) return 1;
    return 0;
}

uint8_t uart_write_ready(){
    if(!U1STAbits.UTXBF) return 1;
    return 0;
}

char uart_read_nb(){
    char arg;
    if(uart_read_ready()){//wait if UTXBF is clear
        arg = U1RXREG;
        return arg;
    } else {
        return '\0';
    }
}

void uart_write_nb(char arg){
    if(uart_write_ready()){//if UTXBF is clear
        U1TXREG = arg; 
    }
}

char uart_read(){
    char arg;
    while(uart_read_ready()){}//if UTXBF is clear
    arg = U1RXREG;
    return arg;
}

char * uart_read_line(){
    int i = 0;
    char bar = '\0';
    while(bar != '\r') {
        bar = uart_read_nb();
        if (bar != '\0') {
            if (bar == 8){
                i--;
                string[i] = ' ';
                uart_write_nb(bar);
                uart_write_nb(' ');
                uart_write_nb(bar);
            } else{
                uart_write_nb(bar);
                string[i] = bar;
                i++;
            }
        }
    }
    while(!uart_write_ready()){}
    U1TXREG = '\r';
    while(!uart_write_ready()){}
    U1TXREG = '\n';
    string[i] = '\0';
    return &string[0];
}

void uart_write(char arg){
    
    while(uart_write_ready()){}//wait if UTXBF is clear
    U1TXREG = arg; 
}

void uart_write_string(char * arg){
    uint8_t i = 0;
    while(arg[i] != '\0'){   
        if(uart_write_ready()){//if UTXBF is clear
            U1TXREG = arg[i];
            i++;
        }
    }
    //possibly write new line after printing string
}