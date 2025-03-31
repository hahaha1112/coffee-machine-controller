#include "../include/ds18b20.h"

// 设置DS18B20的DQ线为输出
static void ds18b20_dq_output(void)
{
    // 根据实际硬件设置IO口为输出模式
    // 此处为硬件相关代码，需根据实际微控制器修改
}

// 设置DS18B20的DQ线为输入
static void ds18b20_dq_input(void)
{
    // 根据实际硬件设置IO口为输入模式
    // 此处为硬件相关代码，需根据实际微控制器修改
}

// 读取DQ线状态
static uint8_t ds18b20_dq_read(void)
{
    // 根据实际硬件读取IO口状态
    // 此处为硬件相关代码，需根据实际微控制器修改
    return 1; // 默认返回高电平
}

// 设置DQ线状态
static void ds18b20_dq_write(uint8_t level)
{
    // 根据实际硬件设置IO口状态
    // 此处为硬件相关代码，需根据实际微控制器修改
}

// 初始化DS18B20
uint8_t ds18b20_init(void)
{
    uint8_t status;
    
    // 复位DS18B20
    status = ds18b20_reset();
    
    return status;
}

// 复位DS18B20
uint8_t ds18b20_reset(void)
{
    uint8_t status;
    
    // 输出模式
    ds18b20_dq_output();
    
    // 拉低总线至少480us
    ds18b20_dq_write(0);
    delay_ms(1); // 延时大于480us
    
    // 释放总线
    ds18b20_dq_write(1);
    
    // 等待15-60us
    // 此处硬件相关代码，可用微秒级延时函数
    delay_ms(1); // 简化为1ms延时
    
    // 切换为输入模式，等待DS18B20响应
    ds18b20_dq_input();
    
    // 等待60-240us判断是否有低电平响应
    // 检测DQ线，如果为低电平，则存在DS18B20
    status = ds18b20_dq_read();
    
    // 等待响应信号结束
    delay_ms(1);
    
    return !status; // 返回0表示存在设备，1表示不存在
}

// 写一位
void ds18b20_write_bit(uint8_t bit)
{
    // 输出模式
    ds18b20_dq_output();
    
    // 首先拉低总线2us以上
    ds18b20_dq_write(0);
    
    // 延时根据写0还是写1决定
    if (bit)
    {
        // 写1: 拉低总线1-15us后释放
        delay_ms(1); // 简化为1ms
        ds18b20_dq_write(1);
        delay_ms(1); // 简化为1ms
    }
    else
    {
        // 写0: 拉低总线60-120us
        delay_ms(1); // 简化为1ms，实际应为60us以上
        ds18b20_dq_write(1);
        // 释放总线
    }
}

// 读一位
uint8_t ds18b20_read_bit(void)
{
    uint8_t bit;
    
    // 输出模式
    ds18b20_dq_output();
    
    // 首先拉低总线2us以上
    ds18b20_dq_write(0);
    delay_ms(1); // 简化为1ms
    
    // 释放总线
    ds18b20_dq_write(1);
    
    // 输入模式
    ds18b20_dq_input();
    
    // 读取数据线状态
    bit = ds18b20_dq_read();
    
    // 等待时间片结束
    delay_ms(1); // 简化为1ms
    
    return bit;
}

// 写一个字节
void ds18b20_write_byte(uint8_t data)
{
    uint8_t i;
    
    // 低位在前
    for (i = 0; i < 8; i++)
    {
        ds18b20_write_bit(data & 0x01);
        data >>= 1;
    }
}

// 读一个字节
uint8_t ds18b20_read_byte(void)
{
    uint8_t i;
    uint8_t data = 0;
    
    // 低位在前
    for (i = 0; i < 8; i++)
    {
        if (ds18b20_read_bit())
            data |= (1 << i);
    }
    
    return data;
}

// 开始温度转换
void ds18b20_start_convert(void)
{
    ds18b20_reset();              // 复位
    ds18b20_write_byte(DS18B20_CMD_SKIPROM);  // 跳过ROM
    ds18b20_write_byte(DS18B20_CMD_CONVERTTEMP);  // 开始温度转换
}

// 读取温度值
float ds18b20_read_temp(void)
{
    uint8_t temp_msb, temp_lsb;
    int16_t temp_raw;
    float temperature;
    
    ds18b20_start_convert();      // 开始温度转换
    
    delay_ms(750);                // 等待温度转换完成，最长需要750ms
    
    ds18b20_reset();              // 复位
    ds18b20_write_byte(DS18B20_CMD_SKIPROM);  // 跳过ROM
    ds18b20_write_byte(DS18B20_CMD_READSCR);  // 读取暂存器
    
    // 读取温度值（低字节在前）
    temp_lsb = ds18b20_read_byte();
    temp_msb = ds18b20_read_byte();
    
    // 计算实际温度值
    temp_raw = (temp_msb << 8) | temp_lsb;
    
    // 默认12位精度，除以16得到实际温度值
    temperature = temp_raw * 0.0625f;
    
    return temperature;
} 