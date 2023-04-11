#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct BITMAPINFOHEADER
{
    unsigned __int32 fileSize;
    unsigned __int8	 _space[4];
    unsigned __int32 dataOffset;
    unsigned __int32 infoHeaderSize;

    struct {
        unsigned __int32 width, height;
    } size;

    unsigned __int16 planeCount;
    unsigned __int16 bitsPerPixel;
    unsigned __int32 compressionType;
    unsigned __int32 imageSize;

    struct {
        unsigned __int32 width, height;
    } pixelDensity;

    unsigned __int32 colorCount;
    unsigned __int32 importantColorCount;
} BITMAPINFOHEADER;

typedef struct RGBQUAD
{
    unsigned __int8  rgbBlue;
    unsigned __int8  rgbGreen;
    unsigned __int8  rgbRed;
} RGBQUAD;

typedef struct BITMAPFILEHEADER
{
    BITMAPINFOHEADER Header;
    RGBQUAD* Color;
} BITMAPFILEHEADER;

BITMAPFILEHEADER read_bmp_file(FILE* File);
void negative_filter(RGBQUAD* Px, int Size);
void monochrome_filter(RGBQUAD* Px, int Size);
void median_filter(BITMAPFILEHEADER BmpFile, RGBQUAD* Px);
void gamma_correction_filter(BITMAPFILEHEADER BmpFile, RGBQUAD* Px, int Size);
void filter_menu(BITMAPFILEHEADER BmpFile);
void free_struct(BITMAPFILEHEADER* BmpFile);
