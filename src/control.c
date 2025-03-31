#include "../include/control.h"

// 控制模块初始化
void control_init(void)
{
    // 初始化控制引脚
    // 此处为硬件相关代码，需根据实际微控制器修改
    
    // 关闭所有控制
    control_heater(0);
    control_grinder(0);
    control_water_pump(0);
    control_water_valve(0);
}

// 初始化咖啡机状态
void init_coffee_machine(CoffeeMachine *machine)
{
    if (!machine)
        return;
    
    // 设置初始状态
    machine->state = STATE_IDLE;
    machine->coffeeType = COFFEE_ESPRESSO;
    machine->targetTemp = TEMP_DEFAULT;
    machine->waterLevel = 100;
    machine->coffeeBeansLevel = 100;
    machine->brewingTime = 0;
    machine->warmingTime = 0;
    machine->errorCode = 0;
}

// 更新咖啡机状态
void update_coffee_machine_state(CoffeeMachine *machine, float temp)
{
    static uint8_t time_counter = 0;
    
    if (!machine)
        return;
    
    // 每秒更新一次状态
    time_counter++;
    if (time_counter < 10) // 假设delay_ms(100)，则10次为1秒
        return;
    
    time_counter = 0;
    
    // 根据当前状态更新
    switch (machine->state)
    {
        case STATE_IDLE:
            // 空闲状态，无需特殊处理
            break;
            
        case STATE_HEATING:
            // 加热状态
            // 检查温度是否达到目标温度
            if (temp >= machine->targetTemp)
            {
                // 温度达到，准备就绪
                machine->state = STATE_IDLE;
            }
            break;
            
        case STATE_GRINDING:
            // 研磨状态
            // 模拟研磨过程
            machine->coffeeBeansLevel -= 2; // 每秒减少2%的咖啡豆
            
            // 检查研磨时间
            if (machine->brewingTime >= GRINDING_TIME_DEFAULT)
            {
                // 研磨完成，进入萃取状态
                machine->state = STATE_BREWING;
                machine->brewingTime = 0;
            }
            else
            {
                // 研磨中
                machine->brewingTime++;
            }
            
            // 检查咖啡豆是否不足
            if (machine->coffeeBeansLevel <= 5)
            {
                // 咖啡豆不足，设置错误状态
                machine->state = STATE_ERROR;
                machine->errorCode = ERROR_NO_BEANS;
            }
            break;
            
        case STATE_BREWING:
            // 萃取状态
            // 模拟萃取过程
            machine->waterLevel -= 2; // 每秒减少2%的水
            
            // 检查萃取时间
            if (machine->brewingTime >= BREWING_TIME_DEFAULT)
            {
                // 萃取完成，进入保温状态
                machine->state = STATE_WARMING;
                machine->brewingTime = 0;
                machine->warmingTime = 0;
            }
            else
            {
                // 萃取中
                machine->brewingTime++;
            }
            
            // 检查水位是否不足
            if (machine->waterLevel <= 5)
            {
                // 水不足，设置错误状态
                machine->state = STATE_ERROR;
                machine->errorCode = ERROR_NO_WATER;
            }
            break;
            
        case STATE_WARMING:
            // 保温状态
            // 检查保温时间
            if (machine->warmingTime >= WARMING_TIME_MAX)
            {
                // 保温时间到，回到空闲状态
                machine->state = STATE_IDLE;
            }
            else
            {
                // 保温中
                machine->warmingTime++;
            }
            
            // 检查温度是否在保温范围内
            if (temp < (machine->targetTemp - TEMP_TOLERANCE))
            {
                // 温度过低，需要加热
                control_heater(1);
            }
            else if (temp > (machine->targetTemp + TEMP_TOLERANCE))
            {
                // 温度过高，关闭加热
                control_heater(0);
            }
            break;
            
        case STATE_ERROR:
            // 错误状态
            // 停止所有操作，等待用户处理
            control_heater(0);
            control_grinder(0);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        default:
            break;
    }
}

// 控制咖啡机
void control_coffee_machine(CoffeeMachine *machine)
{
    if (!machine)
        return;
    
    // 根据当前状态控制各个部件
    switch (machine->state)
    {
        case STATE_IDLE:
            // 空闲状态，关闭所有控制
            control_heater(0);
            control_grinder(0);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        case STATE_HEATING:
            // 加热状态，打开加热器
            control_heater(1);
            control_grinder(0);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        case STATE_GRINDING:
            // 研磨状态，打开研磨器
            control_heater(1);  // 保持加热
            control_grinder(1);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        case STATE_BREWING:
            // 萃取状态，打开水泵和水阀
            control_heater(1);  // 保持加热
            control_grinder(0);
            control_water_pump(1);
            control_water_valve(1);
            break;
            
        case STATE_WARMING:
            // 保温状态，根据温度控制加热器
            // 注意：加热器的控制已在update_coffee_machine_state中处理
            control_grinder(0);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        case STATE_ERROR:
            // 错误状态，关闭所有控制
            control_heater(0);
            control_grinder(0);
            control_water_pump(0);
            control_water_valve(0);
            break;
            
        default:
            break;
    }
}

// 控制加热器
void control_heater(uint8_t state)
{
    // 控制加热器
    // 此处为硬件相关代码，需根据实际微控制器修改
    
    // 模拟控制
    if (state)
    {
        // 打开加热器
        printf("加热器: 开启\n");
    }
    else
    {
        // 关闭加热器
        printf("加热器: 关闭\n");
    }
}

// 控制研磨器
void control_grinder(uint8_t state)
{
    // 控制研磨器
    // 此处为硬件相关代码，需根据实际微控制器修改
    
    // 模拟控制
    if (state)
    {
        // 打开研磨器
        printf("研磨器: 开启\n");
    }
    else
    {
        // 关闭研磨器
        printf("研磨器: 关闭\n");
    }
}

// 控制水泵
void control_water_pump(uint8_t state)
{
    // 控制水泵
    // 此处为硬件相关代码，需根据实际微控制器修改
    
    // 模拟控制
    if (state)
    {
        // 打开水泵
        printf("水泵: 开启\n");
    }
    else
    {
        // 关闭水泵
        printf("水泵: 关闭\n");
    }
}

// 控制水阀
void control_water_valve(uint8_t state)
{
    // 控制水阀
    // 此处为硬件相关代码，需根据实际微控制器修改
    
    // 模拟控制
    if (state)
    {
        // 打开水阀
        printf("水阀: 开启\n");
    }
    else
    {
        // 关闭水阀
        printf("水阀: 关闭\n");
    }
} 