/*###############################################################################
#
# Copyright 2020 NVIDIA Corporation
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of
# this software and associated documentation files (the "Software"), to deal in
# the Software without restriction, including without limitation the rights to
# use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
# the Software, and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
# FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
# COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
# IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
###############################################################################*/


#ifndef __NVTRANSFER_D3D_H__
#define __NVTRANSFER_D3D_H__

#ifndef _WINDOWS_
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif // WIN32_LEAN_AND_MEAN
  #include <Windows.h>
#endif // _WINDOWS_
#include <dxgitype.h>
#include "nvCVImage.h"

#ifdef __cplusplus
extern "C" {
#endif // ___cplusplus



//! Utility to determine the D3D format from the NvCVImage format, type and layout.
//! \param[in]  format    the pixel format.
//! \param[in]  type      the component type.
//! \param[in]  layout    the layout.
//! \param[out] d3dFormat a place to store the corresponding D3D format.
//! \return     NVCV_SUCCESS if successful.
//! \note       This is an experimental API. If you find it useful, please respond to XXX@YYY.com, otherwise we may drop support.
NvCV_Status NvCV_API NvCVImage_ToD3DFormat(NvCVImage_PixelFormat format, NvCVImage_ComponentType type, unsigned layout, DXGI_FORMAT *d3dFormat);


//! Utility to determine the NvCVImage format, component type and layout from a D3D format.
//! \param[in]  d3dFormat the D3D format to translate.
//! \param[out] format    a place to store the NvCVImage pixel format.
//! \param[out] type      a place to store the NvCVImage component type.
//! \param[out] layout    a place to store the NvCVImage layout.
//! \return     NVCV_SUCCESS if successful.
//! \note       This is an experimental API. If you find it useful, please respond to XXX@YYY.com, otherwise we may drop support.
NvCV_Status NvCV_API NvCVImage_FromD3DFormat(DXGI_FORMAT d3dFormat, NvCVImage_PixelFormat *format, NvCVImage_ComponentType *type, unsigned char *layout);


#ifdef __dxgicommon_h__

//! Utility to determine the D3D color space from the NvCVImage color space.
//! \param[in]  nvcvColorSpace  the NvCVImage colro space.
//! \param[out] pD3dColorSpace  a place to store the resultant D3D color space.
//! \return     NVCV_SUCCESS          if successful.
//! \return     NVCV_ERR_PIXELFORMAT  if there is no equivalent color space.
//! \note       This is an experimental API. If you find it useful, please respond to XXX@YYY.com, otherwise we may drop support.
NvCV_Status NvCV_API NvCVImage_ToD3DColorSpace(unsigned char nvcvColorSpace, DXGI_COLOR_SPACE_TYPE *pD3dColorSpace);


//! Utility to determine the NvCVImage color space from the D3D color space.
//! \param[in]  d3dColorSpace   the D3D color space.
//! \param[out] pNvcvColorSpace a place to store the resultant NvCVImage color space.
//! \return     NVCV_SUCCESS          if successful.
//! \return     NVCV_ERR_PIXELFORMAT  if there is no equivalent color space.
//! \note       This is an experimental API. If you find it useful, please respond to XXX@YYY.com, otherwise we may drop support.
NvCV_Status NvCV_API NvCVImage_FromD3DColorSpace(DXGI_COLOR_SPACE_TYPE d3dColorSpace, unsigned char *pNvcvColorSpace);

#endif // __dxgicommon_h__


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // __NVTRANSFER_D3D_H__

