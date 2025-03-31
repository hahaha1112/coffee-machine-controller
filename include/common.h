#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 系统常量定义
#define TRUE            1
#define FALSE           0

// 温度相关常量
#define TEMP_MIN        60.0f   // 最低温度（摄氏度）
#define TEMP_MAX        95.0f   // 最高温度（摄氏度）
#define TEMP_DEFAULT    85.0f   // 默认温度（摄氏度）
#define TEMP_TOLERANCE  2.0f    // 温度容差

// 定义咖啡机状态
typedef enum {
    STATE_IDLE,         // 空闲状态
    STATE_HEATING,      // 加热状态
    STATE_GRINDING,     // 研磨咖啡豆
    STATE_BREWING,      // 萃取咖啡
    STATE_WARMING,      // 保温状态
    STATE_ERROR         // 错误状态
} MachineState;

// 定义咖啡类型
typedef enum {
    COFFEE_ESPRESSO,    // 浓缩咖啡
    COFFEE_AMERICANO,   // 美式咖啡
    COFFEE_LATTE,       // 拿铁咖啡
    COFFEE_CAPPUCCINO   // 卡布奇诺
} CoffeeType;

// 咖啡机控制结构体
typedef struct {
    MachineState state;         // 当前状态
    CoffeeType coffeeType;      // 咖啡类型
    float targetTemp;           // 目标温度
    uint8_t waterLevel;         // 水位（百分比）
    uint8_t coffeeBeansLevel;   // 咖啡豆水平（百分比）
    uint8_t brewingTime;        // 萃取时间（秒）
    uint8_t warmingTime;        // 已保温时间（分钟）
    uint8_t errorCode;          // 错误代码
} CoffeeMachine;

// 系统初始化
void system_init(void);

// 延时函数（毫秒）
void delay_ms(uint16_t ms);

#endif /* _COMMON_H */ 