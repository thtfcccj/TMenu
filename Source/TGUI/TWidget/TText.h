/*******************************************************************************

                           TWidget之扩展文本框控件

*******************************************************************************/
#ifndef __T_TEXT_H 
#define __T_TEXT_H

/*******************************************************************************
                                控件说明
*******************************************************************************/
//因部分编译器显示方式不同,下列的窗口显示若不够清晰,请在其它文本编辑器里打开试试!
//控件说明:
//如下所示为文本框扩展控件演示:
//  ┌──(可选显示头)───┐
//  │如下所示为文本框扩展  ┼
//  │控件演示:             │
//  │   [确定]    [返回]   ↓
//  └←━━━━━━━━━→┘

//除具有文本框基本控件功能外,增加了以下特性和显示样式:
//1: 文本对齐方式可配置
//2: 文本是否具有焦点,当具有焦点时,可在文字之间移动
//3: 可增加前后缀,并可决定前后缀是否带焦点
//5: 最后一栏用户附加功能(具体由用户决定显示和需完成的功能)

//继承关系:
//TListBoxEx继承关系为:
//  TListBoxEx->TListBox->TWidget->(间接继承)TWin
//直接继承时可直接将该结构转换为基类结构后并调用基类相关函数
//间接继承通过该结构提供的间接转函数数转换为基类结构并可调用基类结构函数
//
//因控件已包装好,且基类无特殊说明外(注释带★标志),
//基类直接操作不当可能会影响系统工作,故不建议直接使用基类操作

/**********************************************************************
                  内部结构
**********************************************************************/
#include "TListbox.h"

typedef struct{
  TListbox_t Listbox;           //基类
  unsigned char Style;         //样式
  const char *pBottom1;      //首个按钮字
  const char *pBottom2;      //第二个按钮字
  const char *pString;        //当前行的未处理字符缓冲
  TItemSize_t FocusX;         //文本可获得焦点时的X位置
  TGUINotify_t cbGUINotify;    //扩展通报函数
}TText_t;

//通报函数应响应下列类型通报:
//TGUI_NOTIFY_GET_CAPTION,      //得到标题
//附加行内容整行不受样式控制,由回调函数决定

//此控件自定义通报为:
#define   TTEXT_NOTIFY_GET_STRING   128    //得到字符串通报,以'\n'表示一行
#define   TTEXT_NOTIFY_BOTTOM1      129    //第一个按被按下通报
#define   TTEXT_NOTIFY_BOTTOM2      130    //第二个按被按下通报
//当文本有焦点时,焦点按确认及ASC码键通报,通报的pv指正在编辑位置字符,Items指按键
//返回值无效
#define   TTEXT_NOTIFY_FOCUS        131    

//注:当附加行不只一个焦点时,应注意按键处理程序的预先处理

//--------------------------文本样式------------------------
//其中,样式定义为:
#define   TTEXT_EN_BOTTOM1     0x01    //允许增加附加按键1,如保存,确认键
#define   TTEXT_EN_BOTTOM2     0x02    //允许增加附加按键2,如取消,返回键
//文字对齐方式:(0-1bit)
#define   TTEXT_ALIGN_MASK      0x0c    //屏蔽位
#define   TTEXT_ALIGN_LEFT      0x00    //左对齐
#define   TTEXT_ALIIGN_CENTER   0x04    //局中对齐
#define   TTEXT_ALIGN_RIGHT     0x08    //右对齐
//#define   TTEXT_ALIGN_DISPERSE  0x0c    //分散对齐,暂未实现
//其它标志
#define   TTEXT_EN_FOCUS_TEXT   0x10     //允许文本获得焦点
//#define   TTEXT_EN_WORD_WRAP  0x20     //允许文本自动换行,暂未实现
#define   TTEXT_FOCUS2          0x80     //焦点在第二个按钮上,否则默认在第一个

/**********************************************************************
                          行为函数
**********************************************************************/

//-------------------------初始化函数-----------------------------
//注:考虑很多系统仅使用静态内层分配,故将创建函数留给更高一层,即
//可在此基础上立真正的创建函数
void TText_Init(TText_t *pText,  //由用户分配的存储空间
                TWinHandle_t hWin,         //已建立并初始化好的窗口
                unsigned char Flag,        //控件标志
                unsigned char Style,       //文本显示样式
                const char *pBottom1,      //首个按钮字,无时为NULL
                const char *pBottom2,      //第二个按钮字,无时为NULL            
                TGUINotify_t cbGUINotify); //通报函数

//-------------------------窗口重画所有函数-------------------------
//以此为基础的应用程序(非继承类)初始化完成后调用此函数重画所有
#define  TText_PaintAll(pText) \
  do{ListBox_PaintAll((TListbox_t *)(pText));}while()

//-------------------------更新字符函数-----------------------------
//当字符被改变时调用此函数
//由控件自已获得字符串,需更新显示时,应调用TText_PaintAll()更新
void TText_UpdateText(TText_t *pText);


//-------------------------按键处理函数-----------------------------
void TText_Key(TText_t *pText,unsigned char Key);

//-------------------------文本框回调实现函数-----------------------------
//仅供内部通报使用
const void*TText_Notify(void *pvSource,
                        unsigned char Type, 
                        const void *pvData);


#endif

