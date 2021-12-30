# Takk_Zynq_Labs中文  实验文档

# Lab01 Zynq介绍与PS端的开发环境

## 1 Zynq介绍

​	Zynq是 Xilinx 推出的一款 Soc（All-Programmable System-on-Chip，SoC）芯片，狭义上的来说就是 Zynq  =（CPU + FPGA）。而SoC 这个术语常用于指专用集成电路 （Application Specific Integrated Circuit，ASIC），基于 ASIC 的 SoC需要大量的开发时间和成本，缺乏灵活性，同时流片验证也十分不便入门开发者。所以说Zynq是一种ASIC的替代品。

​	Zynq的内部是由两个ARM Cortex-A9处理器以及一个传统 的现场可编程门阵列 （Field Programmable Gate Array，FPGA）逻辑部件组成的。我们简称其为PS与PL部分。如下图所示：

<img src="C:\Users\lenovo\Desktop\绘图1.png" alt="绘图1" style="zoom: 33%;" />

​	由上图我们可以得知，SoC的系统内有十分丰富的资源，而且每个部分都有不同的特点。比如一些USB接口与PS部分连接，这意味着，如果PL部分（FPGA）需要你的USB外设的资源，那么需要通过PS与PL的内部互联总线才能够实现。而且这个总线还是AXI协议！

​	关于AXI协议，内容十分多，对于初学者，尤其是写习惯软件语言的朋友，对时序的理解和把握还不是很通透。因此，在本小节我们不会提太多的内部细节，等我们需要实现该协议时我们再去深刻理解它，并且能够通过硬件描述语言(HDL)来对其进行代码编写。

同时，现在我们看一下Zynq的一大重点PL部分。

<img src="C:\Users\lenovo\Desktop\3.png" alt="3" style="zoom:33%;" />

<img src="C:\Users\lenovo\Desktop\4.png" alt="4" style="zoom:33%;" />

​	



​	PL部分中，存在许多的IP核，也就是所谓的硬件中的“ 造轮子 ”！我们可以抽象的理解为其是软件语言中的函数！ 通过不同的IP连接我们可以构造出很复杂很丰富很酷coool的电路！以达到我们预期的需求与设计目标。有些IP是Xilinx或者其他公司所提供，也有许多Github开源IP，甚至我们自己也可以编写IP。

​	同样的，AXI协议是这些IP连接起来的“桥梁”，所以学好AXI协议的时序至关重要啊家人们。

​	

## 2 实验目标：制作第一个PS程序

​		在PS端实现串口打印功能

## 3 实际实验步骤