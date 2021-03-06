/******************************************************************************
*
* Copyright (C) 2009 - 2015 Xilinx, Inc.  All rights reserved.
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

/* read.c -- read bytes from a input device.
 */
#ifndef UNDEFINE_FILE_OPS
#include "xil_printf.h"
#include "xparameters.h"

#ifdef __cplusplus
extern "C" {
	__attribute__((weak)) s32 _read (s32 fd, char8* buf, s32 nbytes);
}
#endif

/*
 * read  -- read bytes from the serial port. Ignore fd, since
 *          we only have stdin.
 */
__attribute__((weak)) s32
read (s32 fd, char8* buf, s32 nbytes)
{
#ifdef STDIN_BASEADDRESS
  s32 i;
  s32 numbytes = 0;
  char8* LocalBuf = buf;

  (void)fd;
  if(LocalBuf != NULL) {
	for (i = 0; i < nbytes; i++) {
		numbytes++;
		*(LocalBuf + i) = inbyte();
		if ((*(LocalBuf + i) == '\n' )|| (*(LocalBuf + i) == '\r')) {
			break;
		}
	}
  }

  return numbytes;
#else
  (void)fd;
  (void)buf;
  (void)nbytes;
  return 0;
#endif
}

__attribute__((weak)) s32
_read (s32 fd, char8* buf, s32 nbytes)
{
#ifdef STDIN_BASEADDRESS
  s32 i;
  s32 numbytes = 0;
  char8* LocalBuf = buf;

  (void)fd;
  if(LocalBuf != NULL) {
	for (i = 0; i < nbytes; i++) {
		numbytes++;
		*(LocalBuf + i) = inbyte();
		if ((*(LocalBuf + i) == '\n' )|| (*(LocalBuf + i) == '\r')) {
			break;
		}
	}
  }

  return numbytes;
#else
  (void)fd;
  (void)buf;
  (void)nbytes;
  return 0;
#endif
}
#endif
