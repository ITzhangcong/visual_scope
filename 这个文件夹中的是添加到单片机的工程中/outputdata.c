#include "outputdata.h"
#include <stdlib.h>
/*************************使用说明****************************************
本协议与“Visual Scope”软件协议兼容，用过的可以直接用原来的下位机协议即可
首次使用时：
1.将“outputdata.c”和“outputdata.h”添加到你的工程中
2.在“outputdata.c”中包含你原程序的串口发送函数头文件
3.将uart_putchar(databuf[i]);语句替换为你的串口字节发送函数，如send_char(databuf[i]);
4.在你的程序需要发送波形数据的.c文件中添加包含：#include "outputdata.h"，并在本文件中调用函数OutPut_Data(x,y,z,w);
  其中形参x，y，z，w就是传入四个short int 16位数据，分别对应通道1,2,3,4
************************************************************************/

//此处添加你的串口头文件包含！！！！！！！！！！！！

unsigned short CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT)
{
    unsigned short CRC_Temp;
    unsigned char i,j;
    CRC_Temp = 0xffff;

    for (i=0;i<CRC_CNT; i++){      
        CRC_Temp ^= Buf[i];
        for (j=0;j<8;j++) {
            if (CRC_Temp & 0x01)
                CRC_Temp = (CRC_Temp >>1 ) ^ 0xa001;
            else
                CRC_Temp = CRC_Temp >> 1;
        }
    }
    return(CRC_Temp);
}

void OutPut_Data(int x,int y,int z,int w)//主程序调用函数
{
  int temp[4] = {0};
  unsigned int temp1[4] = {0};
  unsigned char databuf[10] = {0};
  unsigned char i;
  unsigned short CRC16 = 0;
  temp[0]=x;
  temp[1]=y;
  temp[2]=z;
  temp[3]=w;
  for(i=0;i<4;i++)
    temp1[i] = (unsigned int)temp[i];
   
  for(i=0;i<4;i++) 
  {
    databuf[i<<1]   = (unsigned char)(temp1[i]&0xff);
    databuf[(i<<1)+1] = (unsigned char)((temp1[i]&0xff00)>>8);
  }
  
  CRC16 = CRC_CHECK(databuf,8);
  databuf[8] = CRC16&0xff;
  databuf[9] =(CRC16&0xff00)>>8;
  
  for(i=0;i<10;i++)
    uart_putchar(databuf[i]);//需要修改的串口字节发送函数！！！！！！！！！！！
}