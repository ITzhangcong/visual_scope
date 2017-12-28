#include "outputdata.h"
#include <stdlib.h>
/*************************ʹ��˵��****************************************
��Э���롰Visual Scope�����Э����ݣ��ù��Ŀ���ֱ����ԭ������λ��Э�鼴��
�״�ʹ��ʱ��
1.����outputdata.c���͡�outputdata.h����ӵ���Ĺ�����
2.�ڡ�outputdata.c���а�����ԭ����Ĵ��ڷ��ͺ���ͷ�ļ�
3.��uart_putchar(databuf[i]);����滻Ϊ��Ĵ����ֽڷ��ͺ�������send_char(databuf[i]);
4.����ĳ�����Ҫ���Ͳ������ݵ�.c�ļ�����Ӱ�����#include "outputdata.h"�����ڱ��ļ��е��ú���OutPut_Data(x,y,z,w);
  �����β�x��y��z��w���Ǵ����ĸ�short int 16λ���ݣ��ֱ��Ӧͨ��1,2,3,4
************************************************************************/

//�˴������Ĵ���ͷ�ļ�����������������������������

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

void OutPut_Data(int x,int y,int z,int w)//��������ú���
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
    uart_putchar(databuf[i]);//��Ҫ�޸ĵĴ����ֽڷ��ͺ�������������������������
}