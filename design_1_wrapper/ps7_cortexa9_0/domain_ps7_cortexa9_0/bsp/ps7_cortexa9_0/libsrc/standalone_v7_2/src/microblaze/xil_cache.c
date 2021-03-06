/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc. All rights reserved.
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
/*****************************************************************************/
/**
*
* @file xil_cache.c
*
* This contains implementation of cache related driver functions.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who  Date     Changes
* ----- ---- -------- -------------------------------------------------------
* 1.00  hbm  07/28/09 Initial release
* 3.10  asa  05/04/13 This version of MicroBlaze BSP adds support for system
*					  cache/L2 cache. Existing APIs in this file are modified
*					  to add support for L2 cache.
*					  These changes are done for implementing PR #697214.
* </pre>
*
* @note
*
* None.
*
******************************************************************************/

#include "xil_cache.h"


/****************************************************************************/
/**
*
* @brief    Disable the data cache.
*
* @param    None
*
* @return   None.
*
****************************************************************************/
void Xil_DCacheDisable(void)
{
	Xil_DCacheFlush();
	Xil_DCacheInvalidate();
	Xil_L1DCacheDisable();
}

/****************************************************************************/
/**
*
* @brief    Disable the instruction cache.
*
* @param    None
*
* @return   None.
*
*
****************************************************************************/
void Xil_ICacheDisable(void)
{
	Xil_ICacheInvalidate();
	Xil_L1ICacheDisable();
}
