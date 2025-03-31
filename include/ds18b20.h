#ifndef _DS18B20_H
#define _DS18B20_H

#include "common.h"

// DS18B20 ROM指令
#define DS18B20_CMD_SEARCHROM      0xF0
#define DS18B20_CMD_READROM        0x33
#define DS18B20_CMD_MATCHROM       0x55
#define DS18B20_CMD_SKIPROM        0xCC
#define DS18B20_CMD_ALARMSEARCH    0xEC

// DS18B20 功能指令
#define DS18B20_CMD_CONVERTTEMP    0x44  // 温度转换指令
#define DS18B20_CMD_READSCR        0xBE  // 读暂存器指令
#define DS18B20_CMD_WRITESCR       0x4E  // 写暂存器指令
#define DS18B20_CMD_COPYSCR        0x48  // 拷贝暂存器指令
#define DS18B20_CMD_RECALLE2       0xB8  // 重调用E2指令
#define DS18B20_CMD_READPWR        0xB4  // 读电源模式指令

// DS18B20端口定义
#define DS18B20_DQ_PORT            PORT_B
#define DS18B20_DQ_PIN             PIN_0

// 函数声明
uint8_t ds18b20_init(void);                      // 初始化DS18B20
void ds18b20_write_byte(uint8_t data);           // 写一个字节
uint8_t ds18b20_read_byte(void);                 // 读一个字节
uint8_t ds18b20_read_bit(void);                  // 读一位
void ds18b20_write_bit(uint8_t bit);             // 写一位
uint8_t ds18b20_reset(void);                     // 复位DS18B20
float ds18b20_read_temp(void);                   // 读取温度
void ds18b20_start_convert(void);                // 开始温度转换

#endif /* _DS18B20_H */ 