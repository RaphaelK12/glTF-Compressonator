//=====================================================================
// Copyright (c) 2016    Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
/// \file GPU_DecodeBase.h
//
//=====================================================================

#ifndef H_GPU_DECODE_BASE
#define H_GPU_DECODE_BASE

#ifdef _WIN32
#ifndef DISABLE_TESTCODE
#include "Compressonator.h"
#define NOMINMAX
#include "Windows.h"
//uncomment to show image on console window for debug
//#define SHOW_WINDOW  

namespace GPU_Decode
{

#define str_WindowsClassName    "GPU_DecodeClass"
#define str_WindowName          "GPU_DecodeWindow"


    class RenderWindow
    {
    public:
        RenderWindow() {};
        virtual ~RenderWindow() {};

        HDC         m_hDC = 0;
        HGLRC       m_hRC = 0;
        HWND        m_hWnd = nullptr;
        HINSTANCE hInstance = GetModuleHandle(NULL);

        HRESULT InitWindow(HINSTANCE hInstance, int width, int height, WNDPROC callback =NULL);
        void    EnableWindowContext(HWND hWnd, HDC * hDC, HGLRC * hRC);
        void    DisableWindowContext(HWND hWnd, HDC hDC, HGLRC hRC);

    };

    class TextureControl: public RenderWindow
    {
    public:
        TextureControl() {};
        virtual ~TextureControl() {};

        virtual CMP_ERROR WINAPI Decompress(const CMP_Texture* pSourceTexture, CMP_Texture* pDestTexture) const = 0;

    private:
    };
}

extern LRESULT CALLBACK WndProc2(HWND, UINT, WPARAM, LPARAM);

#endif // !H_GPU_DECODE_BASE
#endif
#endif
