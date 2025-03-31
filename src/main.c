/**
 * 咖啡机控制系统
 * 
 * 功能：自动磨豆、自动上水、自动萃取、自动保温
 * 硬件：DS18B20温度传感器、按键、显示屏、加热器、水泵、研磨机
 */

#include "../include/common.h"
#include "../include/ds18b20.h"
#include "../include/display.h"
#include "../include/keypad.h"
#include "../include/control.h"

int main(void)
{
    float temperature;
    int keyValue;
    CoffeeMachine coffeeMachine;
    
    // 系统初始化
    system_init();
    
    // 咖啡机状态初始化
    init_coffee_machine(&coffeeMachine);
    
    // 主循环
    while (1)
    {
        // 读取温度
        temperature = ds18b20_read_temp();
        
        // 检测按键
        keyValue = keypad_scan();
        
        // 处理按键输入
        process_key_input(keyValue, &coffeeMachine);
        
        // 更新咖啡机状态
        update_coffee_machine_state(&coffeeMachine, temperature);
        
        // 执行咖啡机控制操作
        control_coffee_machine(&coffeeMachine);
        
        // 更新显示
        update_display(&coffeeMachine, temperature);
        
        // 延时
        delay_ms(100);
    }
    
    return 0;
} 