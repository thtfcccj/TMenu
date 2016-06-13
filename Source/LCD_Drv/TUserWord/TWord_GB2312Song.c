/* ----------------------------------------------------------------------------
 *                用户自定义字模－GB2312宋体16X16点阵实现
 *此模块适用于不带字库的LCD显示屏，用自定义字实现
 *取模方式为 左上 → 右上 → 左下 → 右下 
 * --------------------------------------------------------------------------*/

//-------------用户自定义字符GB2312字模(以TWord_GB2312LUT对应)------------
//此字模为TWord_GB2312.c中的TWord_GB2312LUT位置对应的宋体16X16点阵字模
//此查找表以GB2312为基础接先后顺序排列,每两个字当成一个字符
//其中,带"★"标识符的为系统保留字符
//附GB2312字符查找表
const unsigned char TWord_GB2312SongLUT[] = 
{
  //"○"		//★【A1F0】,单选框,不选中
  0x00,0x00,0x07,0xC0,0x18,0x30,0x20,0x08,0x20,0x08,0x40,0x04,0x40,0x04,0x40,0x04,
  0x40,0x04,0x40,0x04,0x20,0x08,0x20,0x08,0x18,0x30,0x07,0xC0,0x00,0x00,0x00,0x00, 
  //"●"		//★【A1F1】,单选框,选中
  0x00,0x00,0x07,0xC0,0x1F,0xF0,0x3F,0xF8,0x3F,0xF8,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,
  0x7F,0xFC,0x7F,0xFC,0x3F,0xF8,0x3F,0xF8,0x1F,0xF0,0x07,0xC0,0x00,0x00,0x00,0x00, 
  //"□"		//★【A1F5】,复选框,不选中
  0x00,0x00,0x7F,0xFC,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,
  0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x7F,0xFC,0x00,0x00,0x00,0x00, 
  //"■"		//★【A1F6】,复选框,选中
  0x00,0x00,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,
  0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x7F,0xFC,0x00,0x00,0x00,0x00, 
  //"→"		//★【A1FA】,TWidget水平滚动条
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x38,0xFF,0xFE,
  0x00,0x38,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"←"		//★【A1FB】,TWidget水平滚动条
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x38,0x00,0xFF,0xFE,
  0x38,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"↑"		//★【A1FC】,TWidget垂直滚动条
  0x01,0x00,0x01,0x00,0x03,0x80,0x03,0x80,0x07,0xC0,0x01,0x00,0x01,0x00,0x01,0x00,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"↓"		//★【A1FD】,TWidget垂直滚动条
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  0x01,0x00,0x01,0x00,0x01,0x00,0x07,0xC0,0x03,0x80,0x03,0x80,0x01,0x00,0x01,0x00,
  //"─"		//★【A9A4】,TWidget框架
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,   
  //"━"		//★【A9A5】,TWidget水平滚动条
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
  0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"│"		//★【A9A6】,TWidget框架
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"┃"		//★【A9A7】,TWidget垂直滚动条
  0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
  0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
  //"┌"		//★【A9B0】,TWidget框架
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"┐"		//★【A9B4】,TWidget框架
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"└"		//★【A9B8】,TWidget框架
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"┘"		//★【A9BC】,TWidget框架
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"├"		//★【A9C0】,TWidget提示 
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"┤"		//★【A9C8】,TWidget提示
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0x00,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"┬"		//★【A9D0】,TWidget提示
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"┴"		//★【A9D8】,TWidget提示
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //"┼"		//★【A9E0】,TWidget提示    
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFF,
  0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,
  //"保"		//  【B1A3】,保存按钮 
  0x10,0x00,0x1B,0xF8,0x12,0x08,0x22,0x08,0x32,0x08,0x63,0xF8,0xA0,0x40,0x2F,0xFE,
  0x20,0xE0,0x21,0x60,0x21,0x50,0x22,0x58,0x24,0x4E,0x28,0x44,0x20,0x40,0x00,0x00,
  //"出"		//  【B3F6】,退出按钮
  0x01,0x00,0x01,0x00,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x3F,0xFC,0x21,0x04,
  0x01,0x00,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x3F,0xFC,0x20,0x04,0x00,0x00, 
  //"存"		//  【B4E6】,保存按钮
  0x03,0x00,0x02,0x00,0x7F,0xFC,0x04,0x00,0x04,0x00,0x0B,0xF8,0x18,0x10,0x10,0x20,
  0x30,0x20,0x57,0xFE,0x90,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0xA0,0x10,0x40,
  //"进"		//  【BDF8】,进入按钮
  0x01,0x10,0x41,0x10,0x21,0x10,0x37,0xFC,0x21,0x10,0x01,0x10,0x01,0x10,0xF7,0xFE,
  0x11,0x10,0x11,0x10,0x12,0x10,0x12,0x10,0x14,0x10,0x28,0x00,0x47,0xFE,0x00,0x00,
  //"入"		//  【C8EB】,退出按钮 
  0x0C,0x00,0x06,0x00,0x02,0x00,0x01,0x00,0x03,0x00,0x02,0x80,0x02,0x80,0x04,0x40,
  0x04,0x20,0x08,0x20,0x08,0x10,0x10,0x08,0x20,0x0E,0x40,0x04,0x80,0x00,0x00,0x00,
  //"退"		//  【CDCB】,退出按钮
  0x40,0x00,0x27,0xF0,0x24,0x10,0x07,0xF0,0x04,0x10,0x04,0x10,0xE7,0xF0,0x24,0x88,
  0x24,0x50,0x24,0x20,0x25,0x10,0x26,0x18,0x24,0x08,0x50,0x00,0x8F,0xFE,0x00,0x00,
};

