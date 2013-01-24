/*
 * Copyright © 2013 Siarhei Siamashka <siarhei.siamashka@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SUNXI_MALI_UMP_DRI2_H
#define SUNXI_MALI_UMP_DRI2_H

#include <ump/ump.h>
#include <ump/ump_ref_drv.h>

typedef struct {
    int                     overlay_x;
    int                     overlay_y;

    WindowPtr               pOverlayWin;
    void                   *pOverlayDirtyDRI2Buf;
    Bool                    bOverlayWinEnabled;
    Bool                    bOverlayWinOverlapped;
    Bool                    bWalkingAboveOverlayWin;

    DestroyWindowProcPtr    DestroyWindow;
    PostValidateTreeProcPtr PostValidateTree;
    GetImageProcPtr         GetImage;
    ump_secure_id           ump_fb_secure_id;

    int                     drm_fd;
} SunxiMaliDRI2;

SunxiMaliDRI2 *SunxiMaliDRI2_Init(ScreenPtr pScreen, Bool bUseOverlay);
void SunxiMaliDRI2_Close(ScreenPtr pScreen);

#endif