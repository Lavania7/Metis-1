# 快速开发模板-v0.2

## Release Notes 更新说明
这一模板提供六个文件层级，分别是：
```
ProjectRoot
├── App : Application
├── Bsp : Board support, GPIO, CAN, USART, etc.
├── Dev : Device abstraction, joint, arm, gimbal, etc.
├── Drv : Drivers, M3508, DM_motor, etc.
├── Lib : Algorithms and utilities, PID, uint_to_float, etc.
└── Sys : System control, flags, muti-robots, etc.
```
开发不限于C板。对于常见的嵌入式项目，只需复制需要的文件夹CubeMX配置好的工程里即可

## Recommendations 推荐用法

### How to name 命名
通常来说命名只要简洁通俗就没问题，但大型项目里标准化还是比较重要的，笔者在此提出一组个人较喜欢的命名：

```C
typedef enum __name_enum
{
    /* some enums */
}name_enum;
```

```C
typedef struct __AlgoTypedef 
{

}AlgoTypedef;

typedef struct __MechTypedef
{

}MechTypedef;

typedef struct __DeviceTypedef
{

}DeviceTypedef;

typedef struct __CtrlTypedef
{

}CtrlTypedef;

typedef struct __HandleTypedef
{

}HandleTypedef;

typedef struct __DataTypedef
{

}DataTypedef;

typedef struct __FlagTypedef
{

}FlagTypedef;
```

```C
void filename_object_movement(SomeTypedef *hstp, Sometype varible, ...);
```

### How to organize 内容布局
一般来说顺着看得懂就行，但好的布局让人愉悦（）笔者在此提出一套好用的布局用注释快捷键
需要：
- 安装插件“Doxygen Documentation Generator”，用来生成注释。
- 安装插件”C/C++ Snippets”，用来生成文件头、代码块分割线等。

配置方法：
Doxygen Documentation Generator支持的操作是所有的/**+回车，因此不用动
C/C++ Snippets 是用来配置所有的.abc类命令，需要：
1. ctrl+shift+p,弹出的命令框里输入"snip",选择“配置用户代码片段”
2. 点击“新建全局代码文件”，名称任取，比如"stm32-snippets"
3. 复制本文件所在文件夹的“stm32.code-snippets”内容到刚刚新建的文件里
4. 配置完成，转到你的工程（比如eide工程），输入点号.，可以看到命令提示

abc.c：
- 文件信息，键入/**后回车
- .line回车 生成代码块分割线
- .table回车 生成表状注释
- 函数名前/**回车，生成函数注释

abc.h：
- .hinit 自动生成防重复编译代码

### What to code 层文件组织
一般来说能让人用F12（转到定义）顺着看懂就行，但大型项目里标准化还是比较重要的。笔者在此提出一些喜欢的文件组织方法：

以“让两轴机械臂转起来”这个小任务为例：

- 文件层：定义+示例操作+关注点

- App：业务逻辑，让机械臂末端抬到最远端，只关心“机械臂末端”这个机构的整体效果
- Device：设备控制，让机械臂的某个关节电机抬到某个角度，或某只关心“某个具体设备”的工作逻辑
- Bsp：版上外设配置，配置电机CAN的发送和接收中断，只关心CAN和其他外设
- Drv：驱动，电机初始化，编组，控制环实现，保护等函数，只关心这个牌子的电机的控制实现
- Lib：库，整形转浮点函数，PID算法等，只关心谁需要用什么算法或简单函数
- Sys：系统工作，状态机，控制模式等

# Ending 结尾
祝开发愉快！
![摸鱼强度](https://img.shields.io/badge/摸鱼强度-适度-brightgreen)
![效率提升](https://img.shields.io/badge/效率提升-已安排-blue)
![灵感触发](https://img.shields.io/badge/灵感-看缘分-yellow)
![代码质量](https://img.shields.io/badge/质量-有待观察-orange)
![bug概率](https://img.shields.io/badge/bug-不可避免-red)



