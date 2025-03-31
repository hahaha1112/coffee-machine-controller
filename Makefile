# 咖啡机控制系统Makefile

# 编译器设置
CC = gcc
CFLAGS = -Wall -Wextra -g -I./include

# 目标文件
TARGET = coffee_machine

# 源文件目录
SRC_DIR = src

# 源文件列表
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# 头文件目录
INCLUDES = -I./include

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译源文件生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 清理目标
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

# 运行目标
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run 