/******************************************************************************

                          KS0108命令字定义

*******************************************************************************/

#ifndef __KS0108_CMD_H
#define __KS0108_CMD_H

/******************************************************************************
                            命令字定义
*******************************************************************************/

//显示开关控制指令
#define Ks0108Cmd_GetDispOn()    0x3f    //显示开 
#define Ks0108Cmd_GetDispOff()   0x3e    //显示关 

//y地址指令,y<=63
#define Ks0108Cmd_GetAdrY(yy)  (0x40 | (yy))

//x地址指令,x<=7
#define Ks0108Cmd_GetAdrX(xx)  (0xb8 | (xx))

//显示状态行指令,z<=63
#define Ks0108Cmd_GetAdrZ(zz)  (0xc0 | (zz))

//读取的状态字位定义
#define KS0108_CMD_STATE_BUSY  0x80  //忙标志
#define KS0108_CMD_STATE_OFF   0x20  //关闭标志,否则为打开状态
#define KS0108_CMD_STATE_RESET 0x10  //复位标志,否则为正常状态

//读写数据直接操作读写函数即可！


#endif  //#define __KS0108_CMD_H

