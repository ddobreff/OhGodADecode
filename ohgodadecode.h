// Copyright (c) 2017 OhGodACompany - OhGodAGirl & OhGodAPet

#ifndef __OHGODADECODE_H
#define __OHGODADECODE_H

#pragma pack(push, 1)

typedef struct _SEQ_WR_CTL_D1_FORMAT
{
	uint32_t DAT_DLY : 4;
	uint32_t DQS_DLY : 4;
	uint32_t DQS_XTR : 1;
	uint32_t DAT_2Y_DLY : 1;
	uint32_t ADR_2Y_DLY : 1;
	uint32_t CMD_2Y_DLY : 1;
	uint32_t OEN_DLY : 4;
	uint32_t OEN_EXT : 4;
	uint32_t OEN_SEL : 2;
	uint32_t Pad0 : 2;
	uint32_t ODT_DLY : 4;
	uint32_t ODT_EXT : 1;
	uint32_t ADR_DLY : 1;
	uint32_t CMD_DLY : 1;
	uint32_t Pad1 : 1;
} SEQ_WR_CTL_D1_FORMAT;

typedef struct _SEQ_WR_CTL_2_FORMAT
{
	uint32_t DAT_DLY_H_D0 : 1;
	uint32_t DQS_DLY_H_D0 : 1;
	uint32_t OEN_DLY_H_D0 : 1;
	uint32_t DAT_DLY_H_D1 : 1;
	uint32_t DQS_DLY_H_D1 : 1;
	uint32_t OEN_DLY_H_D1 : 1;
	uint32_t WCDR_EN : 1;
	uint32_t Pad0 : 25;
} SEQ_WR_CTL_2_FORMAT;

typedef struct _SEQ_PMG_TIMING_FORMAT
{
	uint32_t TCKSRE : 3;
	uint32_t Pad0 : 1;
	uint32_t TCKSRX : 3;
	uint32_t Pad1 : 1;
	uint32_t TCKE_PULSE : 4;
	uint32_t TCKE : 6;
	uint32_t SEQ_IDLE : 3;
	uint32_t Pad2 : 2;
	uint32_t TCKE_PULSE_MSB : 1;
	uint32_t SEQ_IDLE_SS : 8;
} SEQ_PMG_TIMING_FORMAT;

typedef struct _SEQ_RAS_TIMING_FORMAT
{
	uint32_t TRCDW : 5;
	uint32_t TRCDWA : 5;
	uint32_t TRCDR : 5;
	uint32_t TRCDRA : 5;
	uint32_t TRRD : 4;
	uint32_t TRC : 7;
	uint32_t Pad0 : 1;
} SEQ_RAS_TIMING_FORMAT;

typedef struct _SEQ_CAS_TIMING_FORMAT
{
	uint32_t TNOPW : 2;
	uint32_t TNOPR : 2;
	uint32_t TR2W : 5;
	uint32_t TCCDL : 3;
	uint32_t TR2R : 4;
	uint32_t TW2R : 5;
	uint32_t Pad0 : 3;
	uint32_t TCL : 5;
	uint32_t Pad1 : 3;
} SEQ_CAS_TIMING_FORMAT;

typedef struct _SEQ_MISC_TIMING_FORMAT
{
	uint32_t TRP_WRA : 7;
	uint32_t TRP_RDA : 7;
	uint32_t TRP : 6;
	uint32_t TRFC : 9;
	uint32_t Pad0 : 3;
} SEQ_MISC_TIMING_FORMAT;

typedef struct _SEQ_MISC_TIMING_FORMAT_R9
{
	uint32_t TRP_WRA : 8;
	uint32_t TRP_RDA : 7;
	uint32_t TRP : 5;
	uint32_t TRFC : 9;
	uint32_t Pad0 : 3;
} SEQ_MISC_TIMING_FORMAT_R9;

typedef struct _SEQ_MISC_TIMING2_FORMAT
{
	uint32_t PA2RDATA : 3;
	uint32_t Pad0 : 1;
	uint32_t PA2WDATA : 3;
	uint32_t Pad1 : 1;
	uint32_t TFAW : 5;
	uint32_t TCRCRL : 3;
	uint32_t TCRCWL : 5;
	uint32_t TFAW32 : 4;
	uint32_t Pad2 : 3;
	uint32_t TWDATATR : 4;
} SEQ_MISC_TIMING2_FORMAT;

/* Authored by Dobromir Dobrev */
typedef struct _MC_SEQ_MISC1
{
        /* MR0 */
        uint32_t WL   : 3 ;
        uint32_t CL   : 4 ;
        uint32_t TM   : 1 ;
        uint32_t WR   : 4 ;
        uint32_t BA0_0 : 1 ;
        uint32_t BA0_1 : 1 ;
        uint32_t BA0_2 : 1 ;
        uint32_t BA0_3 : 1 ;
        /* MR1 */
        uint32_t DS   : 2 ;
        uint32_t DT   : 2 ;
        uint32_t ADR  : 2 ;
        uint32_t CAL  : 1 ;
        uint32_t PLL  : 1 ;
        uint32_t RDBI : 1 ;
        uint32_t WDBI : 1 ;
        uint32_t ABI  : 1 ;
        uint32_t RES  : 1 ;
        uint32_t BA1_0 : 1 ;
        uint32_t BA1_1 : 1 ;
        uint32_t BA1_2 : 1 ;
        uint32_t BA1_3 : 1 ;
} SEQ_MISC1_FORMAT;

/* Authored by Dobromir Dobrev */
typedef struct _MC_SEQ_MISC3
{
        /* MR4 */
        uint32_t EHP   : 4 ;
        uint32_t CRCWL : 3 ;
        uint32_t CRCRL : 2 ;
        uint32_t RDCRC : 1 ;
        uint32_t WRCRC : 1 ;
        uint32_t EHPI  : 1 ;
        uint32_t BA0_0  : 1 ;
        uint32_t BA0_1  : 1 ;
        uint32_t BA0_2  : 1 ;
        uint32_t BA0_3  : 1 ;
        /* MR5 */
        uint32_t LP1   : 1 ;
        uint32_t LP2   : 1 ;
        uint32_t LP3   : 1 ;
        uint32_t PDBW  : 3 ;
        uint32_t TRAS  : 6 ;
        uint32_t BA1_0  : 1 ;
        uint32_t BA1_1  : 1 ;
        uint32_t BA1_2  : 1 ;
        uint32_t BA1_3  : 1 ;
} SEQ_MISC3_FORMAT;

/* Authored by Dobromir Dobrev */
typedef struct _MC_SEQ_MISC8
{
        /* MR8 */
        uint32_t CLEHF : 1 ;
        uint32_t WREHF : 1 ;
        uint32_t RFU  : 10 ;
        uint32_t BA0_0  : 1 ;
        uint32_t BA0_1  : 1 ;
        uint32_t BA0_2  : 1 ;
        uint32_t BA0_3  : 1 ;
        /* MR7 */
        uint32_t PLLSB : 1 ;
        uint32_t PLLFL : 1 ;
        uint32_t PLLDC : 1 ;
        uint32_t LFM   : 1 ;
        uint32_t ASYNC : 1 ;
        uint32_t DQPA  : 1 ;
        uint32_t TEMPS : 1 ;
        uint32_t HVFRD : 1 ;
        uint32_t VDDR  : 2 ;
        uint32_t RFU2  : 2 ;
        uint32_t BA1_0  : 1 ;
        uint32_t BA1_1  : 1 ;
        uint32_t BA1_2  : 1 ;
        uint32_t BA1_3  : 1 ;
} SEQ_MISC8_FORMAT;


typedef struct _ARB_DRAM_TIMING_FORMAT
{
	uint32_t ACTRD : 8;
	uint32_t ACTWR : 8;
	uint32_t RASMACTRD : 8;
	uint32_t RASMACTWR : 8;
} ARB_DRAM_TIMING_FORMAT;

typedef struct _ARB_DRAM_TIMING2_FORMAT
{
	uint32_t RAS2RAS : 8;
	uint32_t RP : 8;
	uint32_t WRPLUSRP : 8;
	uint32_t BUS_TURN : 8;
} ARB_DRAM_TIMING2_FORMAT;

typedef struct _VBIOS_STRAP_RX
{
	SEQ_WR_CTL_D1_FORMAT SEQ_WR_CTL_D1;
	SEQ_WR_CTL_2_FORMAT SEQ_WR_CTL_2;
	SEQ_PMG_TIMING_FORMAT SEQ_PMG_TIMING;
	SEQ_RAS_TIMING_FORMAT SEQ_RAS_TIMING;
	SEQ_CAS_TIMING_FORMAT SEQ_CAS_TIMING;
	SEQ_MISC_TIMING_FORMAT SEQ_MISC_TIMING;
	SEQ_MISC_TIMING2_FORMAT SEQ_MISC_TIMING2;
	SEQ_MISC1_FORMAT SEQ_MISC1;
	SEQ_MISC3_FORMAT SEQ_MISC3;
	SEQ_MISC8_FORMAT SEQ_MISC8;
	ARB_DRAM_TIMING_FORMAT ARB_DRAM_TIMING;
	ARB_DRAM_TIMING2_FORMAT ARB_DRAM_TIMING2;
} VBIOS_STRAP_RX;

typedef struct _VBIOS_STRAP_R9
{
	SEQ_WR_CTL_D1_FORMAT SEQ_WR_CTL_D1;
	SEQ_WR_CTL_2_FORMAT SEQ_WR_CTL_2;
	SEQ_RAS_TIMING_FORMAT SEQ_RAS_TIMING;
	SEQ_CAS_TIMING_FORMAT SEQ_CAS_TIMING;
	SEQ_MISC_TIMING_FORMAT_R9 SEQ_MISC_TIMING;
	SEQ_MISC_TIMING2_FORMAT SEQ_MISC_TIMING2;
	SEQ_PMG_TIMING_FORMAT SEQ_PMG_TIMING;
	SEQ_MISC1_FORMAT SEQ_MISC1;
	SEQ_MISC3_FORMAT SEQ_MISC3;
	SEQ_MISC8_FORMAT SEQ_MISC8;
	ARB_DRAM_TIMING_FORMAT ARB_DRAM_TIMING;
	ARB_DRAM_TIMING2_FORMAT ARB_DRAM_TIMING2;
} VBIOS_STRAP_R9;

#pragma pack(pop)

#endif
