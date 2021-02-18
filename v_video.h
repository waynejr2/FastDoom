//
// Copyright (C) 1993-1996 Id Software, Inc.
// Copyright (C) 2016-2017 Alexey Khokholov (Nuke.YKT)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	Gamma correction LUT.
//	Functions to draw patches (by post) directly to screen.
//	Functions to blit a block to the screen.
//

#ifndef __V_VIDEO__
#define __V_VIDEO__

#include "doomtype.h"

#include "doomdef.h"

// Needed because we are refering to patches.
#include "r_data.h"

//
// VIDEO
//

#define CENTERY (SCREENHEIGHT / 2)

// Screen 0 is the screen updated by I_Update screen.
// Screen 1 is an extra buffer.

extern byte screen0[SCREENWIDTH * SCREENHEIGHT];
extern byte screen4[SCREENWIDTH * 32];

extern int dirtybox[4];

extern int usegamma;

// Allocates buffer screens, call before R_Init.
void V_Init(void);

void V_CopyRect(int srcx, int srcy, byte *srcscrn, int width, int height, int destx, int desty, byte *destscrn);
void V_SetRect(byte color, int width, int height, int destx, int desty, byte *destscrn);

void V_Blit(unsigned int dest_page, int source_x, int source_y, int dest_x, int dest_y, unsigned int width, unsigned int height, unsigned int src_page);

void V_DrawPatch(int x, int y, byte *scrn, patch_t *patch);
void V_DrawPatchScreen0(int x, int y, patch_t *patch);
void V_DrawPatchDirect(int x, int y, patch_t *patch);
void V_DrawPatchFlippedScreen0(int x, int y, patch_t *patch);

void V_WriteTextDirect(int x, int y, char *string);
void V_WriteCharDirect(int x, int y, unsigned char c);

void V_MarkRect(int x, int y, int width, int height);

#endif
