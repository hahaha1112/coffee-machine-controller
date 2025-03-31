#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "common.h"

// 显示区域定义
#define DISPLAY_AREA_STATUS     0   // 状态显示区
#define DISPLAY_AREA_TEMP       1   // 温度显示区
#define DISPLAY_AREA_TYPE       2   // 咖啡类型显示区
#define DISPLAY_AREA_TIME       3   // 时间显示区
#define DISPLAY_AREA_ERROR      4   // 错误显示区

// 错误代码定义
#define ERROR_NONE              0   // 无错误
#define ERROR_NO_BEANS          1   // 咖啡豆不足
#define ERROR_NO_WATER          2   // 水不足
#define ERROR_TEMP_HIGH         3   // 温度过高
#define ERROR_TEMP_LOW          4   // 温度过低
#define ERROR_SYSTEM            5   // 系统错误

// 函数声明
void display_init(void);                                   // 初始化显示
void display_clear(void);                                  // 清除显示
void display_set_cursor(uint8_t row, uint8_t col);         // 设置光标位置
void display_print_string(const char *str);                // 显示字符串
void display_print_number(int num);                        // 显示数字
void display_print_float(float num, uint8_t decimal);      // 显示浮点数
void update_display(CoffeeMachine *machine, float temp);   // 更新显示

#endif /* _DISPLAY_H */ 