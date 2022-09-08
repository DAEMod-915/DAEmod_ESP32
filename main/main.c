#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

#include "string.h"

#include "driver/uart.h"
#include "driver/gpio.h"

#define BUFFER_SIZE 1024

#define TXD 0
#define RXD 1

#define UART_PORT_NUM 1
#define UART_BAUD_RATE 115200
#define TASK_STACK_SIZE 10



static void uart_tx_task(void *arg)
{
	uint8_t curr_message = 0;
	const char* message = "12345\n";
	const char* mess2   = "54321\n";
	const size_t length = strlen(message);
	while (1)
	{
		if ( curr_message )
		{
			uart_write_bytes(UART_PORT_NUM, message, length);
		}
		else
		{
			uart_write_bytes(UART_PORT_NUM, mess2, length);
		}
		curr_message = !curr_message;
		vTaskDelay( 10000 / portTICK_PERIOD_MS );
	}
}


void app_main(void)
{
	// UART Configuration
    printf("Starting Up UART Comms\n");
    
	uart_config_t uart_config = {
		.baud_rate = UART_BAUD_RATE,
		.data_bits = UART_DATA_8_BITS,
		.parity = UART_PARITY_DISABLE,
		.stop_bits = UART_STOP_BITS_1,
		.flow_ctrl = UART_HW_FLOWCTRL_DISABLE
	};

	ESP_ERROR_CHECK(uart_driver_install(UART_PORT_NUM, BUFFER_SIZE * 2, 0, 0, NULL, 0));
	ESP_ERROR_CHECK(uart_param_config(UART_PORT_NUM, &uart_config));
	ESP_ERROR_CHECK(uart_set_pin(UART_PORT_NUM, TXD, RXD, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));
	
	printf(">>> UART Setup completed <<<");

	// END UART Configuration

	xTaskCreate(uart_tx_task, "TX Transmit", BUFFER_SIZE * 2, NULL, configMAX_PRIORITIES, NULL);	
	
	fflush(stdout);
}
