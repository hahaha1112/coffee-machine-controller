<<<<<<< HEAD
# 咖啡机控制系统

## 项目简介

本项目是一个咖啡机控制系统，由研磨系统、水箱供水系统、电炉加热和保温系统4部分组成。能根据用户的喜好萃取出不同口味的咖啡，并能实现自动磨豆、自动上水、自动萃取、自动保温等功能。

## 系统特点

- 使用DS18B20数字温度传感器进行温度检测
- 自动磨豆功能：根据不同咖啡种类自动调整研磨时间
- 自动上水功能：控制水泵和水阀实现自动上水
- 自动萃取功能：控制水温和水流实现最佳萃取效果
- 自动保温功能：保持咖啡在最佳温度
- 错误检测与报警功能：检测水位、咖啡豆量、温度异常等情况

## 硬件要求

- 主控制器：任意支持C语言编程的单片机/微控制器
- 温度传感器：DS18B20单总线数字温度传感器
- 执行部件：加热器、研磨器、水泵、水阀等
- 输入设备：按键面板
- 输出设备：显示屏（LCD/OLED）

## 软件架构

项目采用模块化设计，主要包含以下模块：

- 温度检测模块(ds18b20.c/h)：负责DS18B20传感器的驱动和温度读取
- 按键处理模块(keypad.c/h)：负责按键扫描和处理
- 显示模块(display.c/h)：负责信息显示
- 控制模块(control.c/h)：负责状态控制和执行器控制
- 公共模块(common.c/h)：包含公共函数和数据结构

## 目录结构

```
咖啡机控制系统/
├── include/              # 头文件目录
│   ├── common.h          # 公共头文件
│   ├── ds18b20.h         # DS18B20温度传感器头文件
│   ├── keypad.h          # 按键处理头文件
│   ├── display.h         # 显示模块头文件
│   └── control.h         # 控制模块头文件
├── src/                  # 源文件目录
│   ├── main.c            # 主程序
│   ├── common.c          # 公共函数实现
│   ├── ds18b20.c         # DS18B20温度传感器驱动实现
│   ├── keypad.c          # 按键处理实现
│   ├── display.c         # 显示模块实现
│   └── control.c         # 控制模块实现
├── doc/                  # 文档目录
├── lib/                  # 库文件目录
├── Makefile              # 编译脚本
└── README.md             # 项目说明文档
```

## 编译与运行

在支持make工具的环境中，可以使用以下命令编译和运行：

```bash
# 编译项目
make

# 清理编译文件
make clean

# 运行程序
make run
``` 
=======
# coffee-machine-controller
本项目是一个咖啡机控制系统，由研磨系统、水箱供水系统、电炉加热和保温系统4部分组成。能根据用户的喜好萃取出不同口味的咖啡，并能实现自动磨豆、自动上水、自动萃取、自动保温等功能。
>>>>>>> 2f15e42bf2afb5f7d66defe2a6e04ac0247557f7
