# Metis 说明文档
本项目为机器人相关开发的软件架构

## Release Notes 更新说明
本项目使用VScode的eide插件，配合keil进行开发。这套流程的配置教程待更新

### 关于其他说明文档
本项目目录 MDK-ARM\.doc 内有每部分详细的说明文件：
- cboard.md - RoboMaster C型开发板的快速使用说明
- easygit.md - git实现文件管理和协同开发的配置教学与命令速查表
- robot.md - 机器人架构与开发工作的细节简述
- template.md - 本项目使用的开发模板的说明

以及对于vscode用户的注释生成命令配置：
- stm32.code-snippets.txt - 复制使用，配置方法见 template.md

## Fastuse 项目速览
本项目采用如下的工程文件架构：
ProjectRoot
├── App : Application
├── Bsp : Board support, GPIO, CAN, USART, etc.
├── Dev : Device abstraction, joint, arm, gimbal, etc.
├── Drv : Drivers, M3508, DM_motor, etc.
├── Lib : Algorithms and utilities, PID, uint_to_float, etc.
└── Sys : System control, flags, muti-robots, etc.

## By-talk 杂谈
这个项目的命名来源是希腊神话中的“智慧与技艺女神”：Metis

祝开发愉快！