#include "Header.h"

BITMAPFILEHEADER read_bmp_file(FILE* File)
{
    BITMAPFILEHEADER BmpFile = { 0 };
    char FileType[3] = { 0 };
    fread(FileType, sizeof(*FileType), 2, File);
    if (strcmp(FileType, "BM") != 0)
    {
        printf("Error. This is not bmp file.");
        exit(1);
    }
    fread(&BmpFile.Header, sizeof(BmpFile.Header), 1, File);
    fseek(File, BmpFile.Header.dataOffset, SEEK_SET);
    if (BmpFile.Header.bitsPerPixel != 24)
    {
        printf("Error. This is not 24-bit bmp file.");
        exit(1);
    }
    BmpFile.Color = (RGBQUAD*)calloc(BmpFile.Header.imageSize, sizeof(BmpFile.Color));
    fread(BmpFile.Color, sizeof(*BmpFile.Color), BmpFile.Header.imageSize, File);
    return BmpFile;
}

void negative_filter(RGBQUAD* Px, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        Px[i].rgbRed = 255 - Px[i].rgbRed;
        Px[i].rgbBlue = 255 - Px[i].rgbBlue;
        Px[i].rgbGreen = 255 - Px[i].rgbGreen;
    }
}

void monochrome_filter(RGBQUAD* Px, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        short Grayscale = (0.3 * Px[i].rgbRed) + (0.59 * Px[i].rgbBlue) + (0.11 * Px[i].rgbGreen);
        Px[i].rgbRed = Grayscale;
        Px[i].rgbBlue = Grayscale;
        Px[i].rgbGreen = Grayscale;
    }
}

void median_filter(BITMAPFILEHEADER BmpFile, RGBQUAD* Px)
{
    int count;
    printf("Enter count:");
    scanf_s("%d", &count);
    int N = count / 2;
    for (int y = N; y < BmpFile.Header.size.height - N; y++)
    {
        for (int x = N; x < BmpFile.Header.size.width - N; x++)
        {
            RGBQUAD* window = (RGBQUAD*)malloc((count * count) * sizeof(window));
            int i = 0;
            for (int w = -N; w <= N; w++)
            {
                for (int h = -N; h <= N; h++)
                {
                    window[i++] = BmpFile.Color[BmpFile.Header.size.width * (y + w) + (x + h)];
                }
            }
            for (int q = 0; q < count * count; q++)
            {
                for (int j = 0; j < count * count; j++)
                {
                    if (window[q].rgbRed + window[q].rgbGreen + window[q].rgbBlue < window[j].rgbRed + window[j].rgbGreen + window[j].rgbBlue)
                    {
                        RGBQUAD buf = window[q];
                        window[q] = window[j];
                        window[j] = buf;
                    }
                }
            }
            BmpFile.Color[BmpFile.Header.size.width * y + x] = window[count * count / 2];
            free(window);
        }
    }
}

void gamma_correction_filter(BITMAPFILEHEADER BmpFile, RGBQUAD* Px, int Size)
{
    float gamma;
    printf("Enter the gamma value: ");
    scanf_s("%f", &gamma);
    for (int i = 0; i < BmpFile.Header.size.height * BmpFile.Header.size.width; i++)
    {
        Px[i].rgbRed = 255 * pow(Px[i].rgbRed / 255.0f, gamma);
        Px[i].rgbGreen = 255 * pow(Px[i].rgbGreen / 255.0f, gamma);
        Px[i].rgbBlue = 255 * pow(Px[i].rgbBlue / 255.0f, gamma);
    }
}

void filter_menu(BITMAPFILEHEADER BmpFile)
{
    int choice, exit = 0;
    while (exit != 1)
    {
        printf("1.Negative\n2.Monochrome\n3.Median Filter.\n4.Gamma correction\nChoose the filtring type: ");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            negative_filter(BmpFile.Color, BmpFile.Header.imageSize);
            exit = 1;
            break;
        case 2:
            monochrome_filter(BmpFile.Color, BmpFile.Header.imageSize);
            exit = 1;
            break;
        case 3:
            median_filter(BmpFile, BmpFile.Color);
            exit = 1;
            break;
        case 4:
            gamma_correction_filter(BmpFile, BmpFile.Color, BmpFile.Header.imageSize);
            exit = 1;
            break;
        default:
            printf("Wrong input. Try again.\n");
            rewind(stdin);
            break;
        }
    }
    printf("File was filtred");
}

void free_struct(BITMAPFILEHEADER* BmpFile)
{
    if (!BmpFile)
        return;
    free(BmpFile->Color);
}
