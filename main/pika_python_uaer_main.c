/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "pikaScript.h"
#include "driver/uart.h"

char pika_platform_getchar(void)
{
    char ch;
    while (1)
    {
        if(uart_read_bytes(UART_NUM_0, &ch, 1, 100 / portTICK_PERIOD_MS)> 0)
        {
            return ch;
        }
        vTaskDelay(1);
    }
}

int pika_platform_putchar(char ch)
{
    uart_write_bytes(UART_NUM_0, &ch, 1);
    return 0;
}

static void pika_console_uart_init(void) 
{
    const uart_config_t uart_config = 
    {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    // We won't use a buffer for sending data.
    uart_driver_install(UART_NUM_0, 1024, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_0, &uart_config);
    uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    vTaskDelay(1*1000 / portTICK_PERIOD_MS);
    uart_flush(UART_NUM_0);
    uart_flush(UART_NUM_0);
}

void app_main(void)
{
    printf("Hello world!\n");
    pika_console_uart_init();
    PikaObj * root  = pikaPythonInit();
    pikaPythonShell(root);
    while (1)
    {
        vTaskDelay(100);
    }
    
}
