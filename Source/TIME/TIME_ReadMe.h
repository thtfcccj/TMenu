/*****************************************************************************
 
                         TGUI上的输入法说明

*****************************************************************************/

//--------------------------输入法显示方案------------------------------
//共占4行: 宽度可根据显示屏宽度调整:

//第一行：当前被修改的字符串，光标停在此位置
//第二行：输入法图标+提示
//第三行: 拼音时：显示拼音字符，符号时显示被先符号
//第四行：拼音时显示被择的汉字，符号时显示被先符号

//以最小屏要求128*64示例(外框表示显示屏):原显示“中国”两字，进入编辑界面
//默认第一个为拼音输入法状态:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音            ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//--------------------------输入法的切换------------------------------
//1.1这里为拼音输入法状态，换#键切换输入方式后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃123             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//1.2这里切换到了数字输入法状态，换#键继续切换输入方式后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃abc             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//1.3这里切换到了小写字母输入法状态，换#键继续切换输入方式后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃ABC             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//1.4这里切换到了D大写字母输入法状态，换#键继续切换输入方式后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音            ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//1.5回环到了拼音输入法状态
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音            ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//1.5若修改完成或取消修改，直接按“退出”键即退出此界面

//----------------------------拼音输入法------------------------------
//2.1.在进入拼音输入法状态，这里需输入“人”字,先输入第一个字母r后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音->拼音输入  ┃
//┃1p 2q 3r 4s     ┃
//┃平1 片2 品3 评4 ┃ 
//┗━━━━━━━━┛
//2.2.输入拼音对应的数字键e选择后面的字母,这里按3键后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音->拼音输入  ┃
//┃1pei 2re 3se    ┃
//┃呸1 胚2 陪3 培4 ┃ 
//┗━━━━━━━━┛
//2.3.输入拼音对应的数字键n选择后面的字母,这里按6键后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音->拼音输入  ┃
//┃1pen 2ren 3sen  ┃
//┃喷1 盆2         ┃ 
//┗━━━━━━━━┛
//2.4.这里已打到ren拼音了，我们按“确认”或“下”键切换到拼音选择状态后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音->拼音选择  ┃
//┃1pen 2ren 3sen  ┃
//┃喷1 盆2         ┃ 
//┗━━━━━━━━┛
//2.5.注意，第二行“拼音输入”变成“拼音选择”了，若拼音字母不在显示范围，
//  则可按上下或上下页键继续查看下一页拼音；这里在显示范围，按ren对应数字鍵2后界面:
//┏━━━━━━━━┓
//┃中国│          ┃
//┃拼音->汉字选择  ┃
//┃1pen 2ren 3sen  ┃
//┃人1 仁2 壬3 忍4 ┃ 
//┗━━━━━━━━┛
//2.6.注意，第二行“拼音选择”变成“汉字选择”了，若汉字不在显示范围，
//  则可按上下或上下页键继续查看下一页汉字；这里在显示范围，按“人”对应数字鍵1后界面:
//┏━━━━━━━━┓
//┃中国人│        ┃
//┃拼音            ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//2.7.这里人字已经输入了

//----------------------------数字输入法------------------------------
//3.1.在1.2数字输入法状态，直接输入小键盘数字键即可
//┏━━━━━━━━┓
//┃中国人1│       ┃
//┃123             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//----------------------------大小输入法------------------------------
//4.1.在1.3,1.4 大小写字母输入法状态，直接输入小键盘对应数字键几次即可
//      输入对应拼音，如：想输入E，则第一次按3键后:
//┏━━━━━━━━┓
//┃中国人1D│      ┃
//┃ABC             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//4.2.可以看到对应键第一个字母"D"上来了，继续按3键后:
//┏━━━━━━━━┓
//┃中国人1E│      ┃
//┃ABC             ┃
//┃                ┃
//┃                ┃ 
//┗━━━━━━━━┛
//4.3输入完成，等待约1S后可输入下个字母

//----------------------------符号输入法------------------------------
//5.1.在1.1-1.4的任何输入法状态，按“*”键即可进入符号输入状态:
//┏━━━━━━━━┓
//┃中国人1E│      ┃
//┃  1  .2  ,3  ?4 ┃
//┃ @1  #2  $3  %4 ┃
//┃●1 ■2 ▲3 ★4 ┃
//┗━━━━━━━━┛
//5.2若想输入符号"●"，检查在3行1列，连续按数字键31,则选中:
//┏━━━━━━━━┓
//┃中国人1E●│    ┃
//┃  1  .2  ,3  ?4 ┃
//┃ @1  #2  $3  %4 ┃
//┃●1 ■2 ▲3 ★4 ┃
//┗━━━━━━━━┛
//5.3若没有找到想要的符号，可按上下或上下页键查看下一屏:
//┏━━━━━━━━┓
//┃中国人1E●│    ┃
//┃ <1  >2  [3  ]4 ┃
//┃ {1  }2  (3  )4 ┃
//┃ /1  \2  -3  _4 ┃
//┗━━━━━━━━┛
//5.4按“退出”键退到输入法状态

