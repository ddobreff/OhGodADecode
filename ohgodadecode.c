// Copyright (c) 2017 OhGodACompany - OhGodAGirl & OhGodAPet

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "ohgodadecode.h"
const float version=1.01;
// Parameter len is the size in bytes of asciistr, meaning rawstr
// must have (len >> 1) bytes allocated
// Maybe asciistr just NULL terminated?
// Returns length of rawstr in bytes
int ASCIIHexToBinary(void *rawstr, const char *asciistr, size_t len)
{
	for(int i=0, j = 0; i < len; ++i)
	{
		char tmp=asciistr[i];
		if(tmp < 'A') tmp -= '0';
		else if(tmp < 'a') tmp=(tmp - 'A') + 10;
		else tmp=(tmp - 'a') + 10;
		
		if(i & 1) ((uint8_t *)rawstr)[j++] |= tmp & 0x0F;
		else ((uint8_t *)rawstr)[j]=tmp << 4;
	}
	
	return(len >> 1);
}

#ifdef STRAP_R9
#define VBIOS_STRAP VBIOS_STRAP_R9
#else
#define VBIOS_STRAP VBIOS_STRAP_RX
#endif

int main(int argc, char **argv)
{
	uint32_t buf[12];
	VBIOS_STRAP *Timings=(VBIOS_STRAP*)buf;
		
	// Short circuited logic should prevent a segfault.
	if(argc != 2 || strlen(argv[1]) != 96)
	{
		printf("OhGodADecode v%.02f\n", version);
		printf("Usage: %s <96-char hex string>\n", argv[0]);
		return(1);
	}
	
	ASCIIHexToBinary(buf, argv[1], 96);

	printf("DAT_DLY=%d ", Timings->SEQ_WR_CTL_D1.DAT_DLY);
	printf("DQS_DLY=%d ", Timings->SEQ_WR_CTL_D1.DQS_DLY);
	printf("DQS_XTR=%d ", Timings->SEQ_WR_CTL_D1.DQS_XTR);
	printf("DAT_2Y_DLY=%d ", Timings->SEQ_WR_CTL_D1.DAT_2Y_DLY);
	printf("ADR_2Y_DLY=%d ", Timings->SEQ_WR_CTL_D1.ADR_2Y_DLY);
    printf("CMD_2Y_DLY=%d\n", Timings->SEQ_WR_CTL_D1.CMD_2Y_DLY);
	printf("OEN_DLY=%d ", Timings->SEQ_WR_CTL_D1.OEN_DLY);
	printf("OEN_EXT=%d ", Timings->SEQ_WR_CTL_D1.OEN_EXT);
	printf("OEN_SEL=%d ", Timings->SEQ_WR_CTL_D1.OEN_SEL);
	printf("ODT_DLY=%d ", Timings->SEQ_WR_CTL_D1.ODT_DLY);
    printf("ODT_EXT=%d ", Timings->SEQ_WR_CTL_D1.ODT_EXT);
	printf("ADR_DLY=%d ", Timings->SEQ_WR_CTL_D1.ADR_DLY);
	printf("CMD_DLY=%d\n\n", Timings->SEQ_WR_CTL_D1.CMD_DLY);

    printf("DAT_DLY_H_D0=%d ", Timings->SEQ_WR_CTL_2.DAT_DLY_H_D0);
    printf("DQS_DLY_H_D0=%d ", Timings->SEQ_WR_CTL_2.DQS_DLY_H_D0);
    printf("OEN_DLY_H_D0=%d ", Timings->SEQ_WR_CTL_2.OEN_DLY_H_D0);
    printf("DAT_DLY_H_D1=%d ", Timings->SEQ_WR_CTL_2.DAT_DLY_H_D1);
    printf("DQS_DLY_H_D1=%d ", Timings->SEQ_WR_CTL_2.DQS_DLY_H_D1);
    printf("OEN_DLY_H_D1=%d ", Timings->SEQ_WR_CTL_2.OEN_DLY_H_D1);
    printf("WCDR_EN=%d\n\n", Timings->SEQ_WR_CTL_2.WCDR_EN);

	printf("TCKSRE=%d ", Timings->SEQ_PMG_TIMING.TCKSRE);
	printf("TCKSRX=%d ", Timings->SEQ_PMG_TIMING.TCKSRX);
	printf("TCKE_PULSE=%d ", Timings->SEQ_PMG_TIMING.TCKE_PULSE);
	printf("TCKE=%d ", Timings->SEQ_PMG_TIMING.TCKE);
	printf("SEQ_IDLE=%d ", Timings->SEQ_PMG_TIMING.SEQ_IDLE);
	printf("TCKE_PULSE_MSB=%d ", Timings->SEQ_PMG_TIMING.TCKE_PULSE_MSB);
	printf("SEQ_IDLE_SS=%d\n\n", Timings->SEQ_PMG_TIMING.SEQ_IDLE_SS);

	printf("TRCDW=%d ", Timings->SEQ_RAS_TIMING.TRCDW);
	printf("TRCDWA=%d ", Timings->SEQ_RAS_TIMING.TRCDWA);
	printf("TRCDR=%d ", Timings->SEQ_RAS_TIMING.TRCDR);
	printf("TRCDRA=%d ", Timings->SEQ_RAS_TIMING.TRCDRA);
	printf("TRRD=%d ", Timings->SEQ_RAS_TIMING.TRRD);
	printf("TRC=%d ", Timings->SEQ_RAS_TIMING.TRC);
	printf("Pad0=%d\n\n", Timings->SEQ_RAS_TIMING.Pad0);
	
	printf("TNOPW=%d ", Timings->SEQ_CAS_TIMING.TNOPW);
	printf("TNOPR=%d ", Timings->SEQ_CAS_TIMING.TNOPR);
	printf("TR2W=%d ", Timings->SEQ_CAS_TIMING.TR2W);
	printf("TCCDL=%d ", Timings->SEQ_CAS_TIMING.TCCDL);
	printf("TR2R=%d ", Timings->SEQ_CAS_TIMING.TR2R);
	printf("TW2R=%d ", Timings->SEQ_CAS_TIMING.TW2R);
	printf("Pad0=%d ", Timings->SEQ_CAS_TIMING.Pad0);
	printf("TCL=%d ", Timings->SEQ_CAS_TIMING.TCL);
	printf("Pad1=%d\n\n", Timings->SEQ_CAS_TIMING.Pad1);
	
	printf("TRP_WRA=%d ", Timings->SEQ_MISC_TIMING.TRP_WRA);
	printf("TRP_RDA=%d ", Timings->SEQ_MISC_TIMING.TRP_RDA);
	printf("TRP=%d ", Timings->SEQ_MISC_TIMING.TRP);
	printf("TRFC=%d ", Timings->SEQ_MISC_TIMING.TRFC);
	printf("Pad0=%d \n\n", Timings->SEQ_MISC_TIMING.Pad0);
	
	printf("PA2RDATA=%d ", Timings->SEQ_MISC_TIMING2.PA2RDATA);
	printf("Pad0=%d ", Timings->SEQ_MISC_TIMING2.Pad0);
	printf("PA2WDATA=%d ", Timings->SEQ_MISC_TIMING2.PA2WDATA);
	printf("Pad1=%d ", Timings->SEQ_MISC_TIMING2.Pad1);
	printf("TFAW=%d ", Timings->SEQ_MISC_TIMING2.TFAW);
	printf("TCRCRL=%d ", Timings->SEQ_MISC_TIMING2.TCRCRL);
	printf("TCRCWL=%d ", Timings->SEQ_MISC_TIMING2.TCRCWL);
	printf("TFAW32=%d\n\n", Timings->SEQ_MISC_TIMING2.TFAW32);
	
	printf("WL=%d ", Timings->SEQ_MISC1.WL);
	printf("CL=%d ", (5 + (Timings->SEQ_MISC1.CL)) | ( Timings->SEQ_MISC8.CLEHF <<4));
	printf("WR=%d\n\n", (4 + (Timings->SEQ_MISC1.WR)) | ( Timings->SEQ_MISC8.WREHF <<4));

	printf("TRAS=%d\n\n", Timings->SEQ_MISC3.TRAS);
	
	printf("ACTRD=%d ", Timings->ARB_DRAM_TIMING.ACTRD);
	printf("ACTWR=%d ", Timings->ARB_DRAM_TIMING.ACTWR);
	printf("RASMACTRD=%d ", Timings->ARB_DRAM_TIMING.RASMACTRD);
	printf("RASMACTWR=%d\n\n", Timings->ARB_DRAM_TIMING.RASMACTWR);
	
	printf("RAS2RAS=%d ", Timings->ARB_DRAM_TIMING2.RAS2RAS);
	printf("RP=%d " , Timings->ARB_DRAM_TIMING2.RP);
	printf("WRPLUSRP=%d ", Timings->ARB_DRAM_TIMING2.WRPLUSRP);
	printf("BUS_TURN=%d\n\n", Timings->ARB_DRAM_TIMING2.BUS_TURN);
	
	return(0);
}
