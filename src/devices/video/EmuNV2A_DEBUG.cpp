// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// ******************************************************************
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  This file is heavily based on code from XQEMU
// *  https://github.com/xqemu/xqemu/tree/master/hw/xbox/nv2a/nv2a_debug.c
// *  Copyright (c) 2012 espes
// *  Copyright (c) 2015 Jannik Vogel
// *  Copyright (c) 2018 Matt Borgerson
// *
// *  Contributions for Cxbx-Reloaded
// *  Copyright (c) 2017-2018 Luke Usher <luke.usher@outlook.com>
// *  Copyright (c) 2018 Patrick van Logchem <pvanlogchem@gmail.com>
// *
// *  All rights reserved
// *
// ******************************************************************

#define DEBUG_START(DEV) \
const char *DebugNV_##DEV(xbox::addr_xt addr) \
{ \
	switch (addr) {
#define DEBUG_CASE(a) \
		case a: return #a;
#define DEBUG_CASE_EX(a, c) \
		case a: return #a c;
#define DEBUG_END(DEV) \
		default: \
			return "Unknown " #DEV " Address"; \
	} \
}

DEBUG_START(PMC)
	DEBUG_CASE(NV_PMC_BOOT_0);
	DEBUG_CASE(NV_PMC_BOOT_1);
	DEBUG_CASE(NV_PMC_INTR_0);
	DEBUG_CASE(NV_PMC_INTR_EN_0);
	DEBUG_CASE(NV_PMC_ENABLE);
DEBUG_END(PMC)

DEBUG_START(PBUS)
	DEBUG_CASE(NV_PBUS_FBIO_RAM)
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_0, ":VENDOR_ID");
	DEBUG_CASE(NV_PBUS_PCI_NV_1);
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_2, ":REVISION_ID");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_3, ":LATENCY_TIMER");
	DEBUG_CASE(NV_PBUS_PCI_NV_4);
	DEBUG_CASE(NV_PBUS_PCI_NV_5);
	DEBUG_CASE(NV_PBUS_PCI_NV_6);
	DEBUG_CASE(NV_PBUS_PCI_NV_7);
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_11, ":SUBSYSTEM");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_12, ":ROM_BASE");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_13, ":CAP_PTR");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_14, ":RESERVED");
	DEBUG_CASE(NV_PBUS_PCI_NV_15);
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_16, ":SUBSYSTEM");
	DEBUG_CASE(NV_PBUS_PCI_NV_17);
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_18, ":AGP_STATUS");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_19, ":AGP_COMMAND");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_20, ":ROM_SHADOW");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_21, ":VGA");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_22, ":SCRATCH");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_23, ":DT_TIMEOUT");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_24, ":PME");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_25, ":POWER_STATE");
	DEBUG_CASE_EX(NV_PBUS_PCI_NV_26, ":RESERVED");
DEBUG_END(PBUS)

DEBUG_START(PFIFO)
	DEBUG_CASE(NV_PFIFO_DELAY_0);
	DEBUG_CASE(NV_PFIFO_DMA_TIMESLICE);
	DEBUG_CASE(NV_PFIFO_TIMESLICE);
	DEBUG_CASE(NV_PFIFO_INTR_0);
	DEBUG_CASE(NV_PFIFO_INTR_EN_0);
	DEBUG_CASE(NV_PFIFO_RAMHT);
	DEBUG_CASE(NV_PFIFO_RAMFC);
	DEBUG_CASE(NV_PFIFO_RAMRO);
	DEBUG_CASE(NV_PFIFO_RUNOUT_STATUS);
	DEBUG_CASE(NV_PFIFO_RUNOUT_PUT_ADDRESS);
	DEBUG_CASE(NV_PFIFO_RUNOUT_GET_ADDRESS);
	DEBUG_CASE(NV_PFIFO_CACHES);
	DEBUG_CASE(NV_PFIFO_MODE);
	DEBUG_CASE(NV_PFIFO_DMA);
	DEBUG_CASE(NV_PFIFO_SIZE)
	DEBUG_CASE(NV_PFIFO_CACHE0_PUSH0);
	DEBUG_CASE(NV_PFIFO_CACHE0_PULL0);
	DEBUG_CASE(NV_PFIFO_CACHE0_HASH);
	DEBUG_CASE(NV_PFIFO_CACHE1_PUSH0);
	DEBUG_CASE(NV_PFIFO_CACHE1_PUSH1);
	DEBUG_CASE(NV_PFIFO_CACHE1_PUT);
	DEBUG_CASE(NV_PFIFO_CACHE1_STATUS);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_PUSH);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_FETCH);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_STATE);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_INSTANCE);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_CTL);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_PUT);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_GET);
	DEBUG_CASE(NV_PFIFO_CACHE1_REF);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_SUBROUTINE);
	DEBUG_CASE(NV_PFIFO_CACHE1_PULL0);
	DEBUG_CASE(NV_PFIFO_CACHE1_PULL1);
	DEBUG_CASE(NV_PFIFO_CACHE1_HASH);
	DEBUG_CASE(NV_PFIFO_CACHE1_ACQUIRE_0);
	DEBUG_CASE(NV_PFIFO_CACHE1_ACQUIRE_1);
	DEBUG_CASE(NV_PFIFO_CACHE1_ACQUIRE_2);
	DEBUG_CASE(NV_PFIFO_CACHE1_SEMAPHORE);
	DEBUG_CASE(NV_PFIFO_CACHE1_GET);
	DEBUG_CASE(NV_PFIFO_CACHE1_ENGINE);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_DCOUNT);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_GET_JMP_SHADOW);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_RSVD_SHADOW);
	DEBUG_CASE(NV_PFIFO_CACHE1_DMA_DATA_SHADOW);
	DEBUG_CASE(NV_PFIFO_CACHE1_METHOD);
	DEBUG_CASE(NV_PFIFO_CACHE1_DATA);
DEBUG_END(PFIFO)

// TODO: Remove disabled warning once case are add to PRMA switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PRMA)
DEBUG_END(PRMA)
#pragma warning(pop)

DEBUG_START(PVIDEO)
	DEBUG_CASE(NV_PVIDEO_DEBUG_2);
	DEBUG_CASE(NV_PVIDEO_DEBUG_3);
	DEBUG_CASE(NV_PVIDEO_INTR);
	DEBUG_CASE(NV_PVIDEO_INTR_EN);
	DEBUG_CASE(NV_PVIDEO_BUFFER);
	DEBUG_CASE(NV_PVIDEO_STOP);
	DEBUG_CASE(NV_PVIDEO_BASE(0));
	DEBUG_CASE(NV_PVIDEO_BASE(1));
	DEBUG_CASE(NV_PVIDEO_LIMIT(0));
	DEBUG_CASE(NV_PVIDEO_LIMIT(1));
	DEBUG_CASE(NV_PVIDEO_LUMINANCE(0));
	DEBUG_CASE(NV_PVIDEO_LUMINANCE(1));
	DEBUG_CASE(NV_PVIDEO_CHROMINANCE(0));
	DEBUG_CASE(NV_PVIDEO_CHROMINANCE(1));
	DEBUG_CASE(NV_PVIDEO_OFFSET(0));
	DEBUG_CASE(NV_PVIDEO_OFFSET(1));
	DEBUG_CASE(NV_PVIDEO_SIZE_IN(0));
	DEBUG_CASE(NV_PVIDEO_SIZE_IN(1));
	DEBUG_CASE(NV_PVIDEO_POINT_IN(0));
	DEBUG_CASE(NV_PVIDEO_POINT_IN(1));
	DEBUG_CASE(NV_PVIDEO_DS_DX(0));
	DEBUG_CASE(NV_PVIDEO_DS_DX(1));
	DEBUG_CASE(NV_PVIDEO_DT_DY(0));
	DEBUG_CASE(NV_PVIDEO_DT_DY(1));
	DEBUG_CASE(NV_PVIDEO_POINT_OUT(0));
	DEBUG_CASE(NV_PVIDEO_POINT_OUT(1));
	DEBUG_CASE(NV_PVIDEO_SIZE_OUT(0));
	DEBUG_CASE(NV_PVIDEO_SIZE_OUT(1));
	DEBUG_CASE(NV_PVIDEO_FORMAT(0));
	DEBUG_CASE(NV_PVIDEO_FORMAT(1));
DEBUG_END(PVIDEO)

DEBUG_START(PTIMER)
	DEBUG_CASE(NV_PTIMER_INTR_0);
	DEBUG_CASE(NV_PTIMER_INTR_EN_0);
	DEBUG_CASE(NV_PTIMER_NUMERATOR);
	DEBUG_CASE(NV_PTIMER_DENOMINATOR);
	DEBUG_CASE(NV_PTIMER_TIME_0);
	DEBUG_CASE(NV_PTIMER_TIME_1);
	DEBUG_CASE(NV_PTIMER_ALARM_0);
DEBUG_END(PTIMER)

// TODO: Remove disabled warning once case are add to PCOUNTER switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PCOUNTER)
DEBUG_END(PCOUNTER)
#pragma warning(pop)

// TODO: Remove disabled warning once case are add to PVPE switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PVPE)
DEBUG_END(PVPE)
#pragma warning(pop)

// TODO: Remove disabled warning once case are add to PTV switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PTV)
DEBUG_END(PTV)
#pragma warning(pop)

// TODO: Remove disabled warning once case are add to PRMFB switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PRMFB)
DEBUG_END(PRMFB)
#pragma warning(pop)

// TODO: Remove disabled warning once case are add to PRMVIO switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PRMVIO)
DEBUG_END(PRMVIO)
#pragma warning(pop)

DEBUG_START(PFB)
	DEBUG_CASE(NV_PFB_CFG0)
	DEBUG_CASE(NV_PFB_CFG1)
	DEBUG_CASE(NV_PFB_CSTATUS)
	DEBUG_CASE(NV_PFB_REFCTRL)
	DEBUG_CASE(NV_PFB_NVM) // 	NV_PFB_NVM_MODE_DISABLE 
	DEBUG_CASE(NV_PFB_PIN)
	DEBUG_CASE(NV_PFB_PAD)
	DEBUG_CASE(NV_PFB_TIMING0)
	DEBUG_CASE(NV_PFB_TIMING1)
	DEBUG_CASE(NV_PFB_TIMING2)
	DEBUG_CASE(NV_PFB_TILE(0))
	DEBUG_CASE(NV_PFB_TLIMIT(0))
	DEBUG_CASE(NV_PFB_TSIZE(0))
	DEBUG_CASE(NV_PFB_TSTATUS(0))
	DEBUG_CASE(NV_PFB_TILE(1))
	DEBUG_CASE(NV_PFB_TLIMIT(1))
	DEBUG_CASE(NV_PFB_TSIZE(1))
	DEBUG_CASE(NV_PFB_TSTATUS(1))
	DEBUG_CASE(NV_PFB_TILE(2))
	DEBUG_CASE(NV_PFB_TLIMIT(2))
	DEBUG_CASE(NV_PFB_TSIZE(2))
	DEBUG_CASE(NV_PFB_TSTATUS(2))
	DEBUG_CASE(NV_PFB_TILE(3))
	DEBUG_CASE(NV_PFB_TLIMIT(3))
	DEBUG_CASE(NV_PFB_TSIZE(3))
	DEBUG_CASE(NV_PFB_TSTATUS(3))
	DEBUG_CASE(NV_PFB_TILE(4))
	DEBUG_CASE(NV_PFB_TLIMIT(4))
	DEBUG_CASE(NV_PFB_TSIZE(4))
	DEBUG_CASE(NV_PFB_TSTATUS(4))
	DEBUG_CASE(NV_PFB_TILE(5))
	DEBUG_CASE(NV_PFB_TLIMIT(5))
	DEBUG_CASE(NV_PFB_TSIZE(5))
	DEBUG_CASE(NV_PFB_TSTATUS(5))
	DEBUG_CASE(NV_PFB_TILE(6))
	DEBUG_CASE(NV_PFB_TLIMIT(6))
	DEBUG_CASE(NV_PFB_TSIZE(6))
	DEBUG_CASE(NV_PFB_TSTATUS(6))
	DEBUG_CASE(NV_PFB_TILE(7))
	DEBUG_CASE(NV_PFB_TLIMIT(7))
	DEBUG_CASE(NV_PFB_TSIZE(7))
	DEBUG_CASE(NV_PFB_TSTATUS(7))
	DEBUG_CASE(NV_PFB_MRS)
	DEBUG_CASE(NV_PFB_EMRS)
	DEBUG_CASE(NV_PFB_MRS_EXT)
	DEBUG_CASE(NV_PFB_EMRS_EXT)
	DEBUG_CASE(NV_PFB_REF)
	DEBUG_CASE(NV_PFB_PRE)
	DEBUG_CASE(NV_PFB_ZCOMP(0))
	DEBUG_CASE(NV_PFB_ZCOMP(1))
	DEBUG_CASE(NV_PFB_ZCOMP(2))
	DEBUG_CASE(NV_PFB_ZCOMP(3))
	DEBUG_CASE(NV_PFB_ZCOMP(4))
	DEBUG_CASE(NV_PFB_ZCOMP(5))
	DEBUG_CASE(NV_PFB_ZCOMP(6))
	DEBUG_CASE(NV_PFB_ZCOMP(7))
	DEBUG_CASE(NV_PFB_ZCOMP_OFFSET)
	DEBUG_CASE(NV_PFB_ARB_PREDIVIDER)
	DEBUG_CASE(NV_PFB_ARB_TIMEOUT)
	DEBUG_CASE(NV_PFB_ARB_XFER_REM)
	DEBUG_CASE(NV_PFB_ARB_DIFF_BANK)
	DEBUG_CASE(NV_PFB_CLOSE_PAGE0)
	DEBUG_CASE(NV_PFB_CLOSE_PAGE1)
	DEBUG_CASE(NV_PFB_CLOSE_PAGE2)
	DEBUG_CASE(NV_PFB_BPARB)
	DEBUG_CASE(NV_PFB_CMDQ0)
	DEBUG_CASE(NV_PFB_CMDQ1)
	DEBUG_CASE(NV_PFB_ILL_INSTR)
	DEBUG_CASE(NV_PFB_RT)
	DEBUG_CASE(NV_PFB_AUTOCLOSE)
	DEBUG_CASE(NV_PFB_WBC)
	DEBUG_CASE(NV_PFB_CMDQ_PRT)
	DEBUG_CASE(NV_PFB_CPU_RRQ)
	DEBUG_CASE(NV_PFB_BYPASS);
DEBUG_END(PFB)

// TODO: Remove disabled warning once case are add to PSTRAPS switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PSTRAPS)
DEBUG_END(PSTRAPS)
#pragma warning(pop)

DEBUG_START(PGRAPH)
	DEBUG_CASE(NV_PGRAPH_DEBUG_0);
	DEBUG_CASE(NV_PGRAPH_DEBUG_1);
	DEBUG_CASE(NV_PGRAPH_DEBUG_3);
	DEBUG_CASE(NV_PGRAPH_DEBUG_4);
	DEBUG_CASE(NV_PGRAPH_DEBUG_5);
	DEBUG_CASE(NV_PGRAPH_DEBUG_8);
	DEBUG_CASE(NV_PGRAPH_DEBUG_9);
	DEBUG_CASE(NV_PGRAPH_INTR);
	DEBUG_CASE(NV_PGRAPH_NSOURCE);
	DEBUG_CASE(NV_PGRAPH_INTR_EN);
	DEBUG_CASE(NV_PGRAPH_CTX_CONTROL);
	DEBUG_CASE(NV_PGRAPH_CTX_USER);
	DEBUG_CASE(NV_PGRAPH_CTX_SWITCH1);
	DEBUG_CASE(NV_PGRAPH_CTX_SWITCH2);
	DEBUG_CASE(NV_PGRAPH_CTX_SWITCH3);
	DEBUG_CASE(NV_PGRAPH_CTX_SWITCH4);
	DEBUG_CASE(NV_PGRAPH_CTX_SWITCH5);
	DEBUG_CASE(NV_PGRAPH_CTX_CACHE1);
	DEBUG_CASE(NV_PGRAPH_CTX_CACHE2);
	DEBUG_CASE(NV_PGRAPH_CTX_CACHE3);
	DEBUG_CASE(NV_PGRAPH_CTX_CACHE4);
	DEBUG_CASE(NV_PGRAPH_CTX_CACHE5);
	DEBUG_CASE(NV_PGRAPH_STATUS);
	DEBUG_CASE(NV_PGRAPH_TRAPPED_ADDR);
	DEBUG_CASE(NV_PGRAPH_TRAPPED_DATA_LOW);
	DEBUG_CASE(NV_PGRAPH_SURFACE);
	DEBUG_CASE(NV_PGRAPH_INCREMENT);
	DEBUG_CASE(NV_PGRAPH_FIFO);
	DEBUG_CASE(NV_PGRAPH_RDI_INDEX);
	DEBUG_CASE(NV_PGRAPH_RDI_DATA);
	DEBUG_CASE(NV_PGRAPH_FFINTFC_ST2);
	DEBUG_CASE(NV_PGRAPH_CHANNEL_CTX_TABLE);
	DEBUG_CASE(NV_PGRAPH_CHANNEL_CTX_POINTER);
	DEBUG_CASE(NV_PGRAPH_CHANNEL_CTX_TRIGGER);
	DEBUG_CASE(NV_PGRAPH_DEBUG_2);
	DEBUG_CASE(NV_PGRAPH_TTILE(0));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(0));
	DEBUG_CASE(NV_PGRAPH_TSIZE(0));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(0));
	DEBUG_CASE(NV_PGRAPH_TTILE(1));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(1));
	DEBUG_CASE(NV_PGRAPH_TSIZE(1));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(1));
	DEBUG_CASE(NV_PGRAPH_TTILE(2));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(2));
	DEBUG_CASE(NV_PGRAPH_TSIZE(2));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(2));
	DEBUG_CASE(NV_PGRAPH_TTILE(3));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(3));
	DEBUG_CASE(NV_PGRAPH_TSIZE(3));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(3));
	DEBUG_CASE(NV_PGRAPH_TTILE(4));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(4));
	DEBUG_CASE(NV_PGRAPH_TSIZE(4));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(4));	
	DEBUG_CASE(NV_PGRAPH_TTILE(5));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(5));
	DEBUG_CASE(NV_PGRAPH_TSIZE(5));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(5));	
	DEBUG_CASE(NV_PGRAPH_TTILE(6));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(6));
	DEBUG_CASE(NV_PGRAPH_TSIZE(6));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(6));
	DEBUG_CASE(NV_PGRAPH_TTILE(7));
	DEBUG_CASE(NV_PGRAPH_TLIMIT(7));
	DEBUG_CASE(NV_PGRAPH_TSIZE(7));
	DEBUG_CASE(NV_PGRAPH_TSTATUS(7));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(0));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(1));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(2));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(3));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(4));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(5));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(6));
	DEBUG_CASE(NV_PGRAPH_ZCOMP(7));
	DEBUG_CASE(NV_PGRAPH_ZCOMP_OFFSET);
	DEBUG_CASE(NV_PGRAPH_FBCFG0);
	DEBUG_CASE(NV_PGRAPH_FBCFG1);
	DEBUG_CASE(NV_PGRAPH_PATT_COLOR0);
	DEBUG_CASE(NV_PGRAPH_DEBUG_6);
	DEBUG_CASE(NV_PGRAPH_DEBUG_7);
	DEBUG_CASE(NV_PGRAPH_DEBUG_10);
	DEBUG_CASE(NV_PGRAPH_CSV0_D);
	DEBUG_CASE(NV_PGRAPH_CSV0_C);
	DEBUG_CASE(NV_PGRAPH_CSV1_B);
	DEBUG_CASE(NV_PGRAPH_CSV1_A);
	DEBUG_CASE(NV_PGRAPH_CHEOPS_OFFSET);
	DEBUG_CASE(NV_PGRAPH_DMA_STATE);
	DEBUG_CASE(NV_PGRAPH_BLEND);
	DEBUG_CASE(NV_PGRAPH_BLENDCOLOR);
	DEBUG_CASE(NV_PGRAPH_BORDERCOLOR0);
	DEBUG_CASE(NV_PGRAPH_BORDERCOLOR1);
	DEBUG_CASE(NV_PGRAPH_BORDERCOLOR2);
	DEBUG_CASE(NV_PGRAPH_BORDERCOLOR3);
	DEBUG_CASE(NV_PGRAPH_BUMPOFFSET1);
	DEBUG_CASE(NV_PGRAPH_BUMPSCALE1);
	DEBUG_CASE(NV_PGRAPH_CLEARRECTX);
	DEBUG_CASE(NV_PGRAPH_CLEARRECTY);
	DEBUG_CASE(NV_PGRAPH_COLORCLEARVALUE);
	DEBUG_CASE(NV_PGRAPH_COMBINEFACTOR0);
	DEBUG_CASE(NV_PGRAPH_COMBINEFACTOR1);
	DEBUG_CASE(NV_PGRAPH_COMBINEALPHAI0);
	DEBUG_CASE(NV_PGRAPH_COMBINEALPHAO0);
	DEBUG_CASE(NV_PGRAPH_COMBINECOLORI0);
	DEBUG_CASE(NV_PGRAPH_COMBINECOLORO0);
	DEBUG_CASE(NV_PGRAPH_COMBINECTL);
	DEBUG_CASE(NV_PGRAPH_COMBINESPECFOG0);
	DEBUG_CASE(NV_PGRAPH_COMBINESPECFOG1);
	DEBUG_CASE(NV_PGRAPH_CONTROL_0);
	DEBUG_CASE(NV_PGRAPH_CONTROL_1);
	DEBUG_CASE(NV_PGRAPH_CONTROL_2);
	DEBUG_CASE(NV_PGRAPH_CONTROL_3);
	DEBUG_CASE(NV_PGRAPH_FOGCOLOR);
	DEBUG_CASE(NV_PGRAPH_FOGPARAM0);
	DEBUG_CASE(NV_PGRAPH_FOGPARAM1);
	DEBUG_CASE(NV_PGRAPH_SETUPRASTER);
	DEBUG_CASE(NV_PGRAPH_SHADERCLIPMODE);
	DEBUG_CASE(NV_PGRAPH_SHADERCTL);
	DEBUG_CASE(NV_PGRAPH_SHADERPROG);
	DEBUG_CASE(NV_PGRAPH_SEMAPHOREOFFSET);
	DEBUG_CASE(NV_PGRAPH_SHADOWZSLOPETHRESHOLD);
	DEBUG_CASE(NV_PGRAPH_SPECFOGFACTOR0);
	DEBUG_CASE(NV_PGRAPH_SPECFOGFACTOR1);
	DEBUG_CASE_EX(NV_PGRAPH_TEXADDRESS0, ":_ADDRV");
	DEBUG_CASE(NV_PGRAPH_TEXADDRESS1);
	DEBUG_CASE(NV_PGRAPH_TEXADDRESS2);
	DEBUG_CASE(NV_PGRAPH_TEXADDRESS3);
	DEBUG_CASE(NV_PGRAPH_TEXCTL0_0);
	DEBUG_CASE(NV_PGRAPH_TEXCTL0_1);
	DEBUG_CASE(NV_PGRAPH_TEXCTL0_2);
	DEBUG_CASE(NV_PGRAPH_TEXCTL0_3);
	DEBUG_CASE(NV_PGRAPH_TEXCTL1_0);
	DEBUG_CASE(NV_PGRAPH_TEXCTL1_1);
	DEBUG_CASE(NV_PGRAPH_TEXCTL1_2);
	DEBUG_CASE(NV_PGRAPH_TEXCTL1_3);
	DEBUG_CASE(NV_PGRAPH_TEXCTL2_0);
	DEBUG_CASE(NV_PGRAPH_TEXCTL2_1);
	DEBUG_CASE(NV_PGRAPH_TEXFILTER0);
	DEBUG_CASE(NV_PGRAPH_TEXFILTER1);
	DEBUG_CASE(NV_PGRAPH_TEXFILTER2);
	DEBUG_CASE(NV_PGRAPH_TEXFILTER3);
	DEBUG_CASE(NV_PGRAPH_TEXFMT0);
	DEBUG_CASE(NV_PGRAPH_TEXFMT1);
	DEBUG_CASE(NV_PGRAPH_TEXFMT2);
	DEBUG_CASE(NV_PGRAPH_TEXFMT3);
	DEBUG_CASE(NV_PGRAPH_TEXIMAGERECT0);
	DEBUG_CASE(NV_PGRAPH_TEXIMAGERECT1);
	DEBUG_CASE(NV_PGRAPH_TEXIMAGERECT2);
	DEBUG_CASE(NV_PGRAPH_TEXIMAGERECT3);
	DEBUG_CASE(NV_PGRAPH_TEXOFFSET0);
	DEBUG_CASE(NV_PGRAPH_TEXOFFSET1);
	DEBUG_CASE(NV_PGRAPH_TEXOFFSET2);
	DEBUG_CASE(NV_PGRAPH_TEXOFFSET3);
	DEBUG_CASE(NV_PGRAPH_TEXPALETTE0);
	DEBUG_CASE(NV_PGRAPH_TEXPALETTE1);
	DEBUG_CASE(NV_PGRAPH_TEXPALETTE2);
	DEBUG_CASE(NV_PGRAPH_TEXPALETTE3);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX0);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX1);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX2);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX3);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX4);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX5);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX6);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPX7);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY0);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY1);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY2);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY3);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY4);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY5);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY6);
	DEBUG_CASE(NV_PGRAPH_WINDOWCLIPY7);
	DEBUG_CASE(NV_PGRAPH_ZSTENCILCLEARVALUE);
	DEBUG_CASE(NV_PGRAPH_ZCLIPMIN);
	DEBUG_CASE(NV_PGRAPH_ZOFFSETBIAS);
	DEBUG_CASE(NV_PGRAPH_ZOFFSETFACTOR);
	DEBUG_CASE(NV_PGRAPH_EYEVEC0);
	DEBUG_CASE(NV_PGRAPH_EYEVEC1);
	DEBUG_CASE(NV_PGRAPH_EYEVEC2);
	DEBUG_CASE(NV_PGRAPH_ZCLIPMAX);
DEBUG_END(PGRAPH)

DEBUG_START(PCRTC)
	DEBUG_CASE(NV_PCRTC_INTR_0);
	DEBUG_CASE(NV_PCRTC_INTR_EN_0);
	DEBUG_CASE(NV_PCRTC_START);
	DEBUG_CASE(NV_PCRTC_CONFIG);
DEBUG_END(PCRTC)

DEBUG_START(PRMCIO)
	DEBUG_CASE(VGA_CRT_DC);
	DEBUG_CASE(VGA_CRT_DM);
	DEBUG_CASE(VGA_ATT_R);
	DEBUG_CASE(VGA_ATT_W);
	DEBUG_CASE(VGA_GFX_D);
	DEBUG_CASE(VGA_SEQ_D);
	DEBUG_CASE(VGA_MIS_R);
	DEBUG_CASE(VGA_MIS_W);
	DEBUG_CASE(VGA_FTC_R);
	DEBUG_CASE(VGA_IS1_RC);
	DEBUG_CASE(VGA_IS1_RM);
	DEBUG_CASE(VGA_PEL_D);
	DEBUG_CASE(VGA_PEL_MSK);
	DEBUG_CASE(VGA_CRT_IC);
	DEBUG_CASE(VGA_CRT_IM);
	DEBUG_CASE(VGA_GFX_I);
	DEBUG_CASE(VGA_SEQ_I);
	DEBUG_CASE(VGA_PEL_IW);
	DEBUG_CASE(VGA_PEL_IR);
DEBUG_END(PRMCIO)

DEBUG_START(PRAMDAC)
	DEBUG_CASE(NV_PRAMDAC_NVPLL_COEFF);
	DEBUG_CASE(NV_PRAMDAC_MPLL_COEFF);
	DEBUG_CASE(NV_PRAMDAC_VPLL_COEFF);
	DEBUG_CASE(NV_PRAMDAC_PLL_TEST_COUNTER);

DEBUG_END(PRAMDAC)

// TODO: Remove disabled warning once case are add to PRMDIO switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PRMDIO)
DEBUG_END(PRMDIO)
#pragma warning(pop)

// TODO: Remove disabled warning once case are add to PRAMIN switch.
#pragma warning(push)
#pragma warning(disable: 4065)
DEBUG_START(PRAMIN)
DEBUG_END(PRAMIN)
#pragma warning(pop)

DEBUG_START(USER)
	DEBUG_CASE(NV_USER_DMA_PUT);
	DEBUG_CASE(NV_USER_DMA_GET);
	DEBUG_CASE(NV_USER_REF);
DEBUG_END(USER)


