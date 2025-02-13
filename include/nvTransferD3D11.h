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


#ifndef __NVTRANSFER_D3D11_H__
#define __NVTRANSFER_D3D11_H__

#include <d3d11.h>
#include "nvCVImage.h"
#include "nvTransferD3D.h"  // for NvCVImage_ToD3DFormat() and NvCVImage_FromD3DFormat()

#ifdef __cplusplus
extern "C" {
#endif // ___cplusplus



//! Initialize an NvCVImage from a D3D11 texture.
//! The pixelFormat and component types with be transferred over, and a cudaGraphicsResource will be registered;
//! the NvCVImage destructor will unregister the resource.
//! It is necessary to call NvCVImage_MapResource() after rendering D3D and before calling  NvCVImage_Transfer(),
//! and to call NvCVImage_UnmapResource() before rendering in D3D again.
//! \param[in,out]  im  the image to be initialized.
//! \param[in]      tx  the texture to be used for initialization.
//! \return         NVCV_SUCCESS if successful.
//! \note           This is an experimental API. If you find it useful, please respond to XXX@YYY.com,
//!                 otherwise we may drop support.
NvCV_Status NvCV_API NvCVImage_InitFromD3D11Texture(NvCVImage *im, struct ID3D11Texture2D *tx);



#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // __NVTRANSFER_D3D11_H__

