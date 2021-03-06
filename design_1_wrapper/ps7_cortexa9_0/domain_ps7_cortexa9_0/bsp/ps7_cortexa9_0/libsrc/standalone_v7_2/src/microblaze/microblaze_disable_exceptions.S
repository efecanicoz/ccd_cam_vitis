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
* Disable exceptions on microblaze.
*
*
******************************************************************************/

#include "xparameters.h"

	.text
	.globl	microblaze_disable_exceptions
	.ent	microblaze_disable_exceptions
	.align 2
microblaze_disable_exceptions:
#if XPAR_MICROBLAZE_USE_MSR_INSTR == 1
	rtsd    r15, 8
        msrclr  r0, 0x100
#else
        mfs     r4, rmsr;
        andi    r4, r4, ~(0x100);                       /* Turn OFF the EE bit */
        mts     rmsr, r4;
        rtsd    r15, 8;
        nop;
#endif
.end microblaze_disable_exceptions
