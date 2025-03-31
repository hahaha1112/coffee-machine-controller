#include "../include/common.h"
#include "../include/ds18b20.h"
#include "../include/display.h"
#include "../include/keypad.h"
#include "../include/control.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// 系统初始化
void system_init(void)
{
    // 初始化DS18B20温度传感器
    ds18b20_init();
    
    // 初始化显示模块
    display_init();
    
    // 初始化按键模块
    keypad_init();
    
    // 初始化控制模块
    control_init();
    
    // 输出初始化完成信息
    printf("咖啡机系统初始化完成\n");
}

// 延时函数（毫秒）
void delay_ms(uint16_t ms)
{
    // 使用平台相关的延时函数
#ifdef _WIN32
    Sleep(ms);  // Windows平台使用Sleep函数
#else
    usleep(ms * 1000);  // Unix/Linux平台使用usleep函数（微秒）
#endif
} 