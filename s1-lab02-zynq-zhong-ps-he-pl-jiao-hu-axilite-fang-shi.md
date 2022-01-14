---
description: 视频在bilibili  https://www.bilibili.com/video/BV1ku411U7ir/
---

# S1 Lab02 Zynq中PS和PL交互（AXI-Lite方式）

## 1 实验介绍

AXI: AXI-full AXI-Stream AXI-Lite

在Zynq PS PL之间的交互方式多种多样，在这里我们采用AXI-Lite总线协议实现通过GP接口让二者联系起来。该Lab并不复杂，因为我们不会直接写Lite协议！

![PL设备以AXI-Lite协议与GP接口交互示意图](<.gitbook/assets/1 (3).png>)

通过在PL部分创建【数据发送 IP核】 （这是我们写的的第一个IP核！），然后向PS部分不断发送数据。该IP是通过AXI-Lite总线接口发送数据到GP接口，GP接口将我们的数据放到该 IP 对应内存中(已经统一编址了，详情可以参考操作系统方面的原理)，它放到内存中的数据并不是只放一个也不是只放我们传输给他的。他会放该IP核内AXI-Lite接口所设置的寄存器中的数据。并且！ AXI-Lite协议下，与GP接口是一个字一个字的读写。

之后，我们只需要在PS部分通过ARM核上执行访问内存的C代码即可把它放置的数据拿到手！当然，我们访问内存只要用指针索引即可。

此时同学A问：那么我怎么知道我的IP核的地址在哪啊？

当然！IP的内存地址十分重要，我们可以通过下面3种方法Get到！

1. 在PL设计时，在Block Design的时候通过内存助手找到该地址。
2. 在我们的IP综合好以后，生成的顶层硬件信息 HDF，已经包含啦！但是我们不用打开它，当我们打开SDK或者Vitis的时候，它们会自动生成对应的driver文件夹，里面的配置头文件中有地址信息！
3. 当然实际开发我们会用sdk启动时根据SDK创建的头文件：\<xparameters.h> 来找到有关我们IP的一切信息！

同时，修改内存中我们IP核的地址（其实就是对应PL寄存器的值）也可以完成PS到PL写的功能！

由此，我们在理论上就实现了PL和PS的通信！

### 2 实验目标：制作第PS读PL的程序（PS写给PL放到下一节IO来讲）

#### 1. PL向PS发送数据

#### 2. PS读出PL的数据

### 3 实际实验步骤

暂缺，待补，详情步骤请见视频