#include "../include/keypad.h"

// 按键初始化
void keypad_init(void)
{
    // 配置按键IO口为输入模式
    // 此处为硬件相关代码，需根据实际微控制器修改
}

// 扫描按键
int keypad_scan(void)
{
    static uint8_t key_status = 0;
    static uint16_t long_press_time = 0;
    int key_value = KEY_NONE;
    
    // 此处为硬件相关代码，需根据实际微控制器修改
    // 简化实现，实际应该读取IO口状态判断按键
    
    // 模拟按键检测
    // 实际项目中应该读取IO口状态并进行消抖处理
    
    return key_value;
}

// 处理按键输入
void process_key_input(int key, CoffeeMachine *machine)
{
    if (!machine)
        return;
    
    switch (key)
    {
        case KEY_POWER:
            // 电源键处理
            if (machine->state == STATE_IDLE)
            {
                // 空闲状态下按电源键，开始加热
                machine->state = STATE_HEATING;
                machine->targetTemp = TEMP_DEFAULT;
            }
            else
            {
                // 其他状态下按电源键，回到空闲状态
                machine->state = STATE_IDLE;
            }
            break;
            
        case KEY_START:
            // 开始键处理
            if (machine->state == STATE_IDLE || machine->state == STATE_HEATING)
            {
                // 空闲或加热状态下按开始键，开始研磨咖啡豆
                if (machine->coffeeBeansLevel > 10)  // 确保有足够的咖啡豆
                {
                    machine->state = STATE_GRINDING;
                }
                else
                {
                    // 咖啡豆不足，设置错误状态
                    machine->state = STATE_ERROR;
                    machine->errorCode = 1;  // 错误码1表示咖啡豆不足
                }
            }
            break;
            
        case KEY_STOP:
            // 停止键处理
            if (machine->state != STATE_IDLE)
            {
                // 非空闲状态下按停止键，回到空闲状态
                machine->state = STATE_IDLE;
            }
            break;
            
        case KEY_MENU:
            // 菜单键处理
            // 在此可以实现菜单切换功能
            break;
            
        case KEY_UP:
            // 上键处理
            if (machine->state == STATE_IDLE || machine->state == STATE_HEATING)
            {
                // 调整目标温度
                if (machine->targetTemp < TEMP_MAX)
                {
                    machine->targetTemp += 1.0f;
                }
            }
            break;
            
        case KEY_DOWN:
            // 下键处理
            if (machine->state == STATE_IDLE || machine->state == STATE_HEATING)
            {
                // 调整目标温度
                if (machine->targetTemp > TEMP_MIN)
                {
                    machine->targetTemp -= 1.0f;
                }
            }
            break;
            
        case KEY_OK:
            // 确认键处理
            if (machine->state == STATE_ERROR)
            {
                // 错误状态下按确认键，清除错误
                machine->state = STATE_IDLE;
                machine->errorCode = 0;
            }
            break;
            
        default:
            break;
    }
} 