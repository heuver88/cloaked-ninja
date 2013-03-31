/***************************************************************************
                          gpu.h  -  description
                             -------------------
    begin                : Sun Oct 28 2001
    copyright            : (C) 2001 by Pete Bernert
    email                : BlackDove@addcom.de
 ***************************************************************************/
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version. See also the license.txt file for *
 *   additional informations.                                              *
 *                                                                         *
 ***************************************************************************/

#ifndef _GPU_INTERNALS_H
#define _GPU_INTERNALS_H

#define OPAQUEON   10
#define OPAQUEOFF  11

#define KEY_RESETTEXSTORE 1
#define KEY_SHOWFPS       2
#define KEY_RESETOPAQUE   4
#define KEY_RESETDITHER   8
#define KEY_RESETFILTER   16
#define KEY_RESETADVBLEND 32
//#define KEY_BLACKWHITE    64
#define KEY_BADTEXTURES   128
#define KEY_CHECKTHISOUT  256

#if !defined(__BIG_ENDIAN__) || defined(__x86_64__) || defined(__i386__)
#ifndef __LITTLE_ENDIAN__
#define __LITTLE_ENDIAN__
#endif
#endif

#ifdef __LITTLE_ENDIAN__
#define RED(x) (x & 0xff)
#define BLUE(x) ((x>>16) & 0xff)
#define GREEN(x) ((x>>8) & 0xff)
#define COLOR(x) (x & 0xffffff)
#elif defined __BIG_ENDIAN__
#define RED(x) ((x>>24) & 0xff)
#define BLUE(x) ((x>>8) & 0xff)
#define GREEN(x) ((x>>16) & 0xff)
#define COLOR(x) SWAP32(x & 0xffffff)
#endif

/////////////////////////////////////////////////////////////////////////////

void           updateDisplay(void);
void           SetAutoFrameCap(void);
void           SetFixes(void);

/////////////////////////////////////////////////////////////////////////////

#ifdef _XBOX

#define GPUopen				PEOPS_GPUopen
#define GPUdisplayText		PEOPS_GPUdisplayText
#define GPUdisplayFlags		PEOPS_GPUdisplayFlags
#define GPUmakeSnapshot		PEOPS_GPUmakeSnapshot
#define GPUinit				PEOPS_GPUinit
#define GPUclose			PEOPS_GPUclose
#define GPUshutdown			PEOPS_GPUshutdown
#define GPUcursor			PEOPS_GPUcursor
#define GPUupdateLace		PEOPS_GPUupdateLace
#define GPUreadStatus		PEOPS_GPUreadStatus
#define GPUwriteStatus		PEOPS_GPUwriteStatus
#define GPUreadDataMem		PEOPS_GPUreadDataMem
#define GPUreadData			PEOPS_GPUreadData
#define GPUwriteDataMem		PEOPS_GPUwriteDataMem
#define GPUwriteData		PEOPS_GPUwriteData
#define GPUsetMode			PEOPS_GPUsetMode
#define GPUgetMode			PEOPS_GPUgetMode
#define GPUdmaChain			PEOPS_GPUdmaChain
#define GPUconfigure		PEOPS_GPUconfigure
#define GPUabout			PEOPS_GPUabout
#define GPUtest				PEOPS_GPUtest
#define GPUfreeze			PEOPS_GPUfreeze
#define GPUgetScreenPic		PEOPS_GPUgetScreenPic
#define GPUshowScreenPic	PEOPS_GPUshowScreenPic
#endif

#endif // _GPU_INTERNALS_H
