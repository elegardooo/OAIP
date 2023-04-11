#include "Header.h"

int main()
{
    BITMAPFILEHEADER BmpFile;
    FILE* File, *OutputFile;
    char FileName[256], empty = 0;
    printf("Enter the file name(including .bmp): ");
    scanf("%s", &FileName);
    File = fopen(FileName, "rb");
    if (File == NULL)
    {
        perror("File open error.");
        exit(1);
    }
    BmpFile = read_bmp_file(File);
    fclose(File);
    filter_menu(BmpFile);
    OutputFile = fopen("FiltredFile.bmp", "wb");
    fputs("BM", OutputFile);
    fwrite(&BmpFile.Header, sizeof(BmpFile.Header), 1, OutputFile);
    fwrite(BmpFile.Color, sizeof(short)/2, BmpFile.Header.imageSize, OutputFile);
    free_struct(&BmpFile);
    return 0;
}
