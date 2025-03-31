#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "common.h"

// 按键定义
#define KEY_NONE        0   // 无按键
#define KEY_POWER       1   // 电源键
#define KEY_START       2   // 开始键
#define KEY_STOP        3   // 停止键
#define KEY_MENU        4   // 菜单键
#define KEY_UP          5   // 上键
#define KEY_DOWN        6   // 下键
#define KEY_OK          7   // 确认键

// 按键长按时间定义（毫秒）
#define KEY_LONG_PRESS_TIME    1000

// 按键端口定义
// 此处为硬件相关，需根据实际情况修改
#define KEY_PORT        PORT_C

// 函数声明
void keypad_init(void);                     // 初始化按键
int keypad_scan(void);                      // 扫描按键，返回按键值
void process_key_input(int key, CoffeeMachine *machine);  // 处理按键输入

#endif /* _KEYPAD_H */ 