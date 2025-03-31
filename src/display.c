#include "../include/display.h"
#include <stdio.h>
#include <string.h>

// 显示初始化
void display_init(void)
{
    // 初始化显示设备
    // 此处为硬件相关代码，需根据实际显示设备修改
    
    // 清除显示
    display_clear();
}

// 清除显示
void display_clear(void)
{
    // 清除显示
    // 此处为硬件相关代码，需根据实际显示设备修改
}

// 设置光标位置
void display_set_cursor(uint8_t row, uint8_t col)
{
    // 设置光标位置
    // 此处为硬件相关代码，需根据实际显示设备修改
}

// 显示字符串
void display_print_string(const char *str)
{
    // 显示字符串
    // 此处为硬件相关代码，需根据实际显示设备修改
    
    // 打印到控制台（模拟显示）
    printf("%s", str);
}

// 显示数字
void display_print_number(int num)
{
    char buf[16];
    
    // 将数字转换为字符串
    sprintf(buf, "%d", num);
    
    // 显示字符串
    display_print_string(buf);
}

// 显示浮点数
void display_print_float(float num, uint8_t decimal)
{
    char buf[16];
    char format[8];
    
    // 构造格式化字符串
    sprintf(format, "%%.%df", decimal);
    
    // 将浮点数转换为字符串
    sprintf(buf, format, num);
    
    // 显示字符串
    display_print_string(buf);
}

// 获取状态字符串
static const char* get_state_string(MachineState state)
{
    switch (state)
    {
        case STATE_IDLE:     return "空闲";
        case STATE_HEATING:  return "加热中";
        case STATE_GRINDING: return "研磨中";
        case STATE_BREWING:  return "萃取中";
        case STATE_WARMING:  return "保温中";
        case STATE_ERROR:    return "错误";
        default:             return "未知";
    }
}

// 获取咖啡类型字符串
static const char* get_coffee_type_string(CoffeeType type)
{
    switch (type)
    {
        case COFFEE_ESPRESSO:   return "浓缩咖啡";
        case COFFEE_AMERICANO:  return "美式咖啡";
        case COFFEE_LATTE:      return "拿铁";
        case COFFEE_CAPPUCCINO: return "卡布奇诺";
        default:                return "未知";
    }
}

// 获取错误信息字符串
static const char* get_error_string(uint8_t error_code)
{
    switch (error_code)
    {
        case ERROR_NONE:      return "无错误";
        case ERROR_NO_BEANS:  return "咖啡豆不足";
        case ERROR_NO_WATER:  return "水不足";
        case ERROR_TEMP_HIGH: return "温度过高";
        case ERROR_TEMP_LOW:  return "温度过低";
        case ERROR_SYSTEM:    return "系统错误";
        default:              return "未知错误";
    }
}

// 更新显示
void update_display(CoffeeMachine *machine, float temp)
{
    if (!machine)
        return;
    
    // 清除显示
    display_clear();
    
    // 显示状态
    display_set_cursor(0, 0);
    display_print_string("状态: ");
    display_print_string(get_state_string(machine->state));
    
    // 显示当前温度和目标温度
    display_set_cursor(1, 0);
    display_print_string("温度: ");
    display_print_float(temp, 1);
    display_print_string("°C/");
    display_print_float(machine->targetTemp, 1);
    display_print_string("°C");
    
    // 显示咖啡类型
    display_set_cursor(2, 0);
    display_print_string("类型: ");
    display_print_string(get_coffee_type_string(machine->coffeeType));
    
    // 显示水位和咖啡豆水平
    display_set_cursor(3, 0);
    display_print_string("水位: ");
    display_print_number(machine->waterLevel);
    display_print_string("%");
    
    display_set_cursor(3, 10);
    display_print_string("豆量: ");
    display_print_number(machine->coffeeBeansLevel);
    display_print_string("%");
    
    // 如果有错误，显示错误信息
    if (machine->state == STATE_ERROR)
    {
        display_set_cursor(4, 0);
        display_print_string("错误: ");
        display_print_string(get_error_string(machine->errorCode));
    }
} 