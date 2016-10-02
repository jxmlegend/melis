/*
*********************************************************************************************************
*											        ePOS
*						           the Easy Portable/Player Operation System
*									           epos headfile
*
*						        (c) Copyright 2006-2007, Steven.ZGJ China
*											All	Rights Reserved
*
* File    : epos_para.h
* By      : Steven.ZGJ
* Version : V0.1
*
* note�����е�ģ���ڲ������ȫ���Եĳ���������Ҫ����"ģ����_xxx", ����"MEMS_xxx", "EXEC_xxx"
************************************************************************************************************************
*/

#ifndef EPOS_PARA_H
#define EPOS_PARA_H

#include "typedef.h"
#include "cfgs.h"

#define   EPOS_MEDIA_NAND       0
#define   EPOS_MEDIA_CARD       1
#define   EPOS_MEDIA_NOR        2
/*
*****************
*   ����/����eposȫ�ֱ���
*****************
*/
typedef struct __TARGET_PARA
{
    __u32 Debugenable;
}__target_para_t;

typedef struct __RDSK_PARA
{
    __u32           BaseAddr;       //ramdisk position address
    __u32           FullSize;       //full ramdisk size
    __u32           UsedByteSize;   //usefull ramdisk size
    __u32           Reserved0;      //reserved for align
}__rdsk_para_t;

typedef struct __EPOS_PARA
{
    __target_para_t Target;         //0 debug, 1 release
    __dram_para_t   DramPara;       //dram init para    
    __rdsk_para_t   CfgDataPara;    //config data para
    __rdsk_para_t   RamDiskPara;    //ram disk para
    __u32           Media;          //storage media

}__epos_para_t;


typedef struct __EPOS_HEAD
{
	__u32			headjump;
	unsigned char	magic[8];       //'EPOS-IMG'
	__u32			version;
	__u8            reserved0[16];

	__epos_para_t   start_para;

    //ͷ�Ͱ���KRNL_INIT���볤�ȼ�����Ϊ16K
	unsigned char	reserved[(0x4000 - sizeof(__epos_para_t)) - 0x20 - 0x84];

    //{sizeof(headjump + magic + version + rev.) = 0x20}

    //����KRNL_INIT����εĴ��룬Ϊ0x6C���ֽ�,
    //����޸���head.s�еİ��ƴ�������´���δ�С.
    //by sunny at 2011-04-13-13-47.
} __epos_head_t;
							                        

#endif						//EPOS_PARA_H
