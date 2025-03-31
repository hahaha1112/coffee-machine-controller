#ifndef _CONTROL_H
#define _CONTROL_H

#include "common.h"

// 控制相关常量
#define GRINDING_TIME_DEFAULT  10  // 默认研磨时间（秒）
#define BREWING_TIME_DEFAULT   30  // 默认萃取时间（秒）
#define WARMING_TIME_MAX       60  // 最大保温时间（分钟）

// 控制引脚定义
// 此处为硬件相关，需根据实际情况修改
#define HEATER_PIN       PIN_D0   // 加热器控制引脚
#define GRINDER_PIN      PIN_D1   // 研磨器控制引脚
#define WATER_PUMP_PIN   PIN_D2   // 水泵控制引脚
#define WATER_VALVE_PIN  PIN_D3   // 水阀控制引脚

// 函数声明
void control_init(void);                               // 初始化控制模块
void init_coffee_machine(CoffeeMachine *machine);      // 初始化咖啡机状态
void update_coffee_machine_state(CoffeeMachine *machine, float temp);  // 更新咖啡机状态
void control_coffee_machine(CoffeeMachine *machine);   // 控制咖啡机
void control_heater(uint8_t state);                    // 控制加热器
void control_grinder(uint8_t state);                   // 控制研磨器
void control_water_pump(uint8_t state);                // 控制水泵
void control_water_valve(uint8_t state);               // 控制水阀

#endif /* _CONTROL_H */ 