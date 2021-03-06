/******************************************************************************
*
* Copyright (C) 2004 - 2014 Xilinx, Inc. All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* 
*
******************************************************************************/
/******************************************************************************
*
* File   : microblaze_disable_icache.s
* Date   : 2002, March 20.
* Company: Xilinx
* Group  : Emerging Software Technologies
*
* Summary:
* Disable L1 icache on the microblaze.
*
*
******************************************************************************/

#include "xparameters.h"

	.text
	.globl	microblaze_disable_icache
	.ent	microblaze_disable_icache
	.align	2
microblaze_disable_icache:
#if XPAR_MICROBLAZE_USE_MSR_INSTR == 1
	rtsd	r15, 8
	msrclr  r0, 0x20
#else /*XPAR_MICROBLAZE_USE_MSR_INSTR == 1*/
	#Read the MSR register
	mfs	r8, rmsr
	#Clear the icache enable bit
	andi	r8, r8, ~(0x20)
	#Save the MSR register
	mts	rmsr, r8
	#Return
	rtsd	r15, 8
	nop
#endif
	.end	microblaze_disable_icache
