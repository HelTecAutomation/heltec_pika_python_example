# 例程使用说明

[toc]

## 1. 简介

  PikaPython 是一个完全重写的超轻量级 python 引擎，零依赖，零配置，可以在 **Flash ≤ 64KB，RAM≤ 4KB** 的平台下运行(如 stm32g030c8 和 stm32f103c8)，极易部署和扩展，具有大量的中文文档和视频资料。PikaPython 具有框架式 C 模块开发工具，只要用 Python 写好调用 API ，就能够自动连接到 C 模块，非常方便快捷。不用手动处理任何全局表、宏定义、等等。

  本次例程将把 PikaPython 功能适配到 **WIFI_LoRa_32_V3** 开发板上面。使 **WIFI_LoRa_32_V3** 也可以使用 PikaPython 相关的功能。

## 2. 安装基本环境

2.1 参考 [快速入门 - ESP32 - — ESP-IDF 编程指南 latest 文档 (espressif.com)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/get-started/) 安装 esp-idf_5.1 版本。

2.2 将本例程放到 esp-idf_5.1 环境下直接编译下载，就会出现以下界面。

```sh
I (363) heap_init: Initializing. RAM available for dynamic allocation:
I (370) heap_init: At 3FCA2450 len 000472C0 (284 KiB): DRAM
I (376) heap_init: At 3FCE9710 len 00005724 (21 KiB): STACK/DRAM
I (383) heap_init: At 3FCF0000 len 00008000 (32 KiB): DRAM
I (389) heap_init: At 600FE010 len 00001FF0 (7 KiB): RTCRAM
I (396) spi_flash: detected chip: gd
I (399) spi_flash: flash io: dio
I (404) sleep: Configure to isolate all GPIO pins in sleep state
I (410) sleep: Enable automatic switching of GPIO sleep configuration
I (418) app_start: Starting scheduler on CPU0
I (422) app_start: Starting scheduler _======[pikapython packages installed]======
pikascript-core==v1.13.0 (2023/11/01 11:11:16)
ESP32===v0.4.4
PikaStdDevice===v2.4.4
PikaStdLib===v1.13.0
time===v0.2.0
===========================================

~~~/ POWERED BY \~~~
~  pikapython.com  ~
~~~~~~~~~~~~~~~~~~~~
hello pikapython!
>>> 
```

2.3 出现以上界面之后，即可像 python 那样输入执行了。例如输入一个 **hello world**

```sh
~~~/ POWERED BY \~~~
~  pikapython.com  ~
~~~~~~~~~~~~~~~~~~~~
hello pikapython!
>>> print('hello world')
hello world
>>> 
```

## 3. 操作 WIFI_LoRa_32_V3 的 gpio

  上面步骤已经将例程下载到开发板里面了，接下来就可以直接在交互式界面去操作 WIFI_LoRa_32_V3 的引脚。下载是操作示例：

```python
// 示例代码
import PikaStdDevice
import time
gpio =  PikaStdDevice.GPIO()
gpio.setPin("P35")
gpio.setId(35)
gpio.setMode("out")
gpio.enable()
while True:
    gpio.high();
    time.sleep_ms(500)
    gpio.low();
    time.sleep_ms(500)

    
```



```sh
// 实时交互式串口输入演示
>>> print('hello world')
hello world
>>> import PikaStdDevice
>>> import time
>>> gpio =  PikaStdDevice.GPIO()
>>> gpio.setPin("P35")
>>> gpio.setId(35)
>>> gpio.setMode("out")
>>> gpio.enable()
I (485082) gpio: GPIO[35]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 0| Pulldown: 0| Intr:0 
>>> while True:
...     gpio.high();
...     time.sleep_ms(500)
...     gpio.low();
...     time.sleep_ms(500)
... 
```



  示例选取的是 WIFI_LoRa_32_V3 的 LED 引脚（GPIO35），这段代码输入进去之后，LED 灯每隔 500ms 就会闪烁一次。

> 注：
>
> - gpio.setPin("P35") 这一句里面的格式固定 **P**+引脚编号（P35 就是代表操作 35号引脚），输入 "GPIO35"和“35”都是错误的。
> - 除了上面的直接手输入之外，还可以使用串口软件将 **.py** 文件直接通过串口发送到开发板上，它会马上进行执行。



## 4. 例程使用的相关库版本

1. esp-idf 使用的是 5.1 版本。
2. pikaPython 库使用的版本

> pikascript-core==v1.13.0
> PikaStdLib==v1.13.0
> ESP32==v0.4.4
> PikaStdDevice==v2.4.4
> time==v0.2.0



## 参考文档

1. [pikaPython 官网](https://pikapython.com/)

2. [PikaPython 开发文档 — PikaPython 0.1 documentation](https://pikapython.com/doc/)
3. [快速入门 - ESP32 - — ESP-IDF 编程指南 latest 文档 (espressif.com)](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/get-started/) 
4. [pikasTech/PikaPython: An ultra-lightweight Python interpreter that runs with only 4KB of RAM, zero dependencies. It is ready to use out of the box without any configuration required and easy to extend with C. Similar project: MicroPython, JerryScript. (github.com)](https://github.com/pikasTech/PikaPython)

