/******************************************************************************

                          KS0108底层驱动程序
此驱动程序负责驱动IO与KS0108进行通讯
注:
1.为保证此驱动程序可驱动不同点阵,故不负责片选信号,所在调用此函数前
  请确保对应控制器已被选中,并在退出后适当时间置为不选中状态
2.因数据总线DB可能为公用,调用驱动程序前应确保DB为输入状态,
 驱动程序保证函数返回时数据为输入状态

*******************************************************************************/

#ifndef __KS0108_DRV_H
#define __KS0108_DRV_H

/******************************************************************************
                            IO回调函数实现
*******************************************************************************/

//IO初始化
#define cbKs0108Drv_IoInit() do{}while(0)

//时钟信号E控制,下降沿锁存信号,下升沿输出信号
#define cbKs0108Drv_ClrE() do{ }while(0)
#define cbKs0108Drv_SetE() do{ }while(0)

//读写信号RW控制,高电平读低电平写
#define cbKs0108Drv_ClrRW() do{ }while(0)
#define cbKs0108Drv_SetRW() do{ }while(0)

//数据/指令选择,高电平数据,低电平指令
#define cbKs0108Drv_ClrRS() do{ }while(0)
#define cbKs0108Drv_SetRS() do{ }while(0)

//总线数据定义
#define cbKs0108Drv_InDB()      do{ }while(0)
#define cbKs0108Drv_OutDB()     do{ }while(0)
#define cbKs0108Drv_SetDB(Data) do{ }while(0)
#define cbKs0108Drv_GetDB() (0)

//注:此驱动程序不负责片选信号驱动

/******************************************************************************
                            其它函数实现
*******************************************************************************/
//地址建立时间,见数据手册
#define cbKs0108Drv_Tasu() do{ }while(0)
//数据建立时间,见数据手册
#define cbKs0108Drv_Tdsu() do{ }while(0)

//数据延时时间,即读延时,从E上升沿开始至获得数据时间
#define cbKs0108Drv_Td() do{ }while(0)
//数据保持时间,即写延时,E下降沿开始至LCD锁存完数据时间
#define cbKs0108Drv_Tdhr() do{ }while(0)

//写数据时判断忙标志无效次数,若超过则强制写入
#define cbKs0108Drv_GetBusyCount() (20)

/******************************************************************************
                            相关函数接口
*******************************************************************************/

//-----------------------------读状态函数----------------------------
//返回读出的状态码
unsigned char Ks0108Drv_RdState(void);

//-----------------------------写状态函数----------------------------
void Ks0108Drv_WrState(unsigned char Data);

//-----------------------------读数据函数----------------------------
//返回读出的数据
unsigned char Ks0108Drv_RdData(void);

//-----------------------------写数据函数----------------------------
void Ks0108Drv_WrData(unsigned char Data);


#endif  //#define __KS0101_DRV_H

