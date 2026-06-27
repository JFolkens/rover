#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define HEARTBEAT_GPIO 2

void heartbeat(void *pvParameter)
{
    gpio_pad_select_gpio(HEARTBEAT_GPIO);
    gpio_set_direction(HEARTBEAT_GPIO, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(HEARTBEAT_GPIO, 0);
        vTaskDelay(1000 / portTICK_RATE_MS);
        gpio_set_level(HEARTBEAT_GPIO, 1);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void driveForward(void *pvParameter)
{
    /* TODO: Drive forward one meter */
}

void app_main()
{
    xTaskCreate(&heartbeat, "heartbeat", 512, NULL, 5, NULL);
    xTaskCreate(&driveForward, "driveForward", 2048, NULL, 5, NULL);
}