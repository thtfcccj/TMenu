/*****************************************************************************

                         ���а�ṹ����                   

*****************************************************************************/
#ifndef __CLIP_BOARD_H
#define __CLIP_BOARD_H

/*****************************************************************************
                          �û�������
*****************************************************************************/

#ifndef CLIP_BOARD_BUF_SIZE
  #define CLIP_BOARD_BUF_SIZE   255
#endif

#if CLIP_BOARD_BUF_SIZE > 255
    #define ClipBoardSizt_t   unsigned char
#else
    #define ClipBoardSizt_t   unsigned short
#endif

/*****************************************************************************
                        ��ؽṹ
*****************************************************************************/

//���а嶨��
struct _ClipBoard{
  char Buf[CLIP_BOARD_BUF_SIZE]; //���л�����
  short PrvSel;                  //�ϴ�ѡ��λ��,-1��ʾ��û�״�ѡ��
};

#endif //#define CLIP_BOARD
