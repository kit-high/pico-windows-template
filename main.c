#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


void let_task()
{
    if (cyw43_arch_init()) {
        printf("init failed");
        return;
    }
    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        printf("LED ON\n");
        vTaskDelay(100);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        printf("LED OFF\n");
        vTaskDelay(100);
    }
}

int main() 
{
    stdio_init_all();

    xTaskCreate(let_task, "LED_TASK", 512, NULL, 1, NULL);
    vTaskStartScheduler();
    
    while(1){};
}