/**
 * @file Print_Binary.c
 * @brief Source code for Print_Binary function implementation.
 *
 * This file contains the function implementation for the Print_Binary function,
 * which takes in a uint8_t value and prints the value in binary format.
 * It relies on the EUSCI_A0_UART driver.
 *
 * @author Aaron Nanas
 * @author Jose Flores
 * @author Erendira Miranda
 *
 */

#include "../inc/Print_Binary.h"

void Print_Binary(uint8_t value_to_convert)
{
    uint8_t bit_position;
    printf("Line Sensor: ");

    for (bit_position = 8; bit_position > 0; bit_position --)
    {
        EUSCI_A0_UART_OutChar(
                (value_to_convert & (1U << (bit_position - 1U))) ? '1' : '0');
        if(bit_position == 5)
        {
            EUSCI_A0_UART_OutChar('_');
        }

       // printf("\n");
    }

}
