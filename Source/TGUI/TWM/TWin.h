/* ----------------------------------------------------------------------------
 *                TGUI窗口函数
 *TGUI窗口是所有其它控件的基类窗口
 * --------------------------------------------------------------------------*/

#ifndef __T_WIN_H 
#define __T_WIN_H

//---------------------------TWIN窗口说明-------------------------------
//TWinMng窗口是相对于文本的底层GUI窗口,该窗口具有以下特性:
//位置:指明了含相对显示屏的位置及大小,(可以为负)
//该窗口有的绘图(即文本)缓冲区,该缓冲区与窗口宽度与高度呈对应关系
//每个窗口均可以获得焦点(相对窗口的坐标,高度为1),焦点未隐藏时将反向显示

//窗口可根据需要动态改变大小,当改变时,对应显示缓冲区将移位

//继承关系:
//TWin为最底层部件
//直接继承时可直接将该结构转换为基类结构后并调用基类相关函数
//间接继承通过该结构提供的间接转函数数转换为基类结构并可调用基类结构函数
//
//因控件已包装好,且基类无特殊说明外(注释带★标志),
//基类直接操作不当可能会影响系统工作,故不建议直接使用基类操作

/**********************************************************************
                  内部结构
**********************************************************************/
#include "TGUIBase.h"

//窗口定义:
typedef struct{
  TRect_t Rect;           //窗口相对于显示屏位置及大小
  TFocus_t Focus;         //当前焦点区,相对于当前窗口
  unsigned char Flag;     //窗口标志,见定义
  unsigned short BufSize; //显示缓冲区大小,防止越界
  char *pBuf;             //当前窗口的显示缓冲区
}TWin_t;

//标志位定义为:
#define   TWIN_HIDDEN       0x80    //窗口隐藏标志,隐藏后将不显示
#define   TWIN_LATTICE      0x40    //窗口用作点阵标志,点阵方式画图由用户负责

/**********************************************************************
                          成员操作函数
**********************************************************************/

//-------------------------★得到x轴位置函数----------------------------
#define TWin_GetX(pWin)     ((pWin)->Rect.x)

//-------------------------★得到y轴位置函数----------------------------
#define TWin_GetY(pWin)     ((pWin)->Rect.y)

//-------------------------★得到宽度函数----------------------------
#define TWin_GetW(pWin)     ((pWin)->Rect.w)

//-------------------------★得到高度函数----------------------------
#define TWin_GetH(pWin)     ((pWin)->Rect.h)

//-------------------------★得到缓冲区大小函数----------------------------
#define TWin_GetBufSize(pWin)     ((pWin)->BufSize)

/**********************************************************************
                          行为函数
**********************************************************************/

//-------------------------初始化窗口函数----------------------------
//开机时调用此函数初始化
void TWin_InitWin(TWin_t *pWin,       //需初始化的窗口
                  signed char w,    //原始宽度
                  signed char h,    //原始高度
                  char *pBuf,       //缓冲区
                  unsigned short BufSize);//缓冲区大小

//-------------------------★窗口隐藏函数----------------------------
void TWin_Hidden(TWin_t *pWin);

//-------------------------★窗口显示函数-----------------------------
//可用于更新一屏显示
void TWin_Disp(TWin_t *pWin);

//----------------------★检查窗口是否被隐藏函数----------------------
//开机时调用此函数初始化
#define TWin_IsHidden(pWin) ((pWin)->Flag & TWIN_HIDDEN)

//-------------------------★窗口移动函数----------------------------
//窗口位动,使用绝对坐标
void TWin_Move(TWin_t *pWin, signed char x, signed char y);

//-------------------------★窗口改变大小函数----------------------------
//使用绝对大小
void TWin_ReSize(TWin_t *pWin, signed char w, signed char h);

//-------------------------★更新一行字符函数----------------------------
//当字符串不够时,后面将清为0,当字符串过多时,后面将不会显示
void TWin_SetString(TWin_t *pWin, 
                    signed char y,              //在窗口内的相对纵座标
                    const char *pString); //字符串

//-------------------------★得到指定行缓冲区函数----------------------------
//此函数用于直接更新行缓冲区数据,注意更新长度小于窗体宽度
char *TWin_pGetString(TWin_t *pWin,
                      signed char y);//在窗口内的相对纵座标

//-------------------------★得到指定位置字符函数----------------------------
//x,y为窗口内的相对坐标
char TWin_GetChar(TWin_t *pWin,signed char x,signed char y);
//#define	TWin_GetChar(pWin,x,y) *((pWin)->pBuf + ((pWin)->Rect.w * (y) + (x)))

//-------------------------★更新一行字符函数----------------------------
//当字符串不够时,后面将清为0,当字符串过多时,后面将不会显示
void TWin_SetString(TWin_t *pWin, 
                    signed char y,              //在窗口内的相对纵座标
                    const char *pString); //字符串

//-------------------------★设置焦点函数----------------------------
//移动或置焦点时调用此函数
//当宽度为0时,表示取消窗口焦点显示
void TWin_SetFocus(TWin_t *pWin,
                   signed char x, //在窗口中的x位置
                   signed char y, //在窗口中的y位置
                   signed char w); //宽度

//-------------------------★取消焦点显示函数----------------------------
#define TWin_ClrFocus(pWin) do{TWin_SetFocus(pWin,0,0,0);}while(0)

//-------------------------判断某个位置是否在焦点上函数----------------
//调用此函数确保该绝对位置在该窗口内
//是则反非0,否则返回1
unsigned char TWin_IsFocus(TWin_t *pWin,
                           signed char x,   //焦点相对坐标x
                           signed char y);   //焦点相对坐标y 

/**********************************************************************
                        点阵模式处理
**********************************************************************/
//点阵模式窗口是为适应用户在显示屏上画图准备的,将某窗口置为点阵模式后
//该窗口在TGUI里的内容仍响应用户输入但禁止更新显示,该区域的显示将交由
//用户直接控制显示屏画图.
//用户应确保绘图区位于最顶层窗口显示!!!(当窗口不在最顶层时,若有上层
//窗口在TGUI里更新了,将遮住该窗口,暂未提供解决此问题的方法)

//-------------------------★窗口置为点阵模式函数----------------------
//置为点阵模式后,该窗口将不再响应输入，负责的窗口绘图由用户处理
void TWin_SetLattice(TWin_t *pWin);

//-------------------------★窗口取消点阵模式函数----------------------
void TWin_ClrLattice(TWin_t *pWin);

//-------------------------★判断是否在点阵模式函数----------------------
//unsigned char TWin_IsLattice(TWin_t *pWin);
#define  TWin_IsLattice(pWin)    (pWin->Flag & TWIN_LATTICE)

//---------------------------点阵区域清屏函数---------------------------
//立即清除点阵区域的显示,交由用户画图
void TWin_ClrLatticeDisp(TWin_t *pWin);


/**********************************************************************
                         回调函数
**********************************************************************/

//---------------------通报窗口某些区域被更新函数----------------------
void TWin_cbUpdateNotify(signed char x,signed char y, 
                         signed char w, signed char h);

//---------------------通报窗口马上清屏函数----------------------------
void TWin_cbClrNowNotify(signed char x,signed char y, 
                         signed char w, signed char h);

#endif

