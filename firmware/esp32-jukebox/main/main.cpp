/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"

extern "C" void app_main(void)
{
    printf("Hello world!\n");

    vTaskDelay(pdTICKS_TO_MS(5000));
    printf("Resetting...");
    esp_restart();
}
