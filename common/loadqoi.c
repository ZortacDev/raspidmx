//-------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2013, 2022 Andrew Duncan, Moritz Kuntze
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>

#include "bcm_host.h"

#include "loadqoi.h"

#include "qoi.h"

//-------------------------------------------------------------------------

#ifndef ALIGN_TO_16
#define ALIGN_TO_16(x) ((x + 15) & ~15)
#endif

//-------------------------------------------------------------------------

bool
loadQoi(
        IMAGE_T* image,
        const char *path)
{
    qoi_desc image_info;
    void* pixel_data = qoi_read(path, &image_info, 0);

    if (pixel_data == NULL)
    {
        return false;
    }


    //---------------------------------------------------------------------

    VC_IMAGE_TYPE_T type = VC_IMAGE_RGB888;

    if (image_info.channels == 4)
    {
        type = VC_IMAGE_RGBA32;
    }

    initImage(image,
              type,
              image_info.width,
              image_info.height,
              false);

    memcpy(image->buffer, pixel_data, image->size);
    free(pixel_data);

    return true;
}

