#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h> //你如果不加這個，就會出現亂碼(???)
/*C99 standard (ISO/IEC 9899:1999):
7.11.1.1 The setlocale function (p: 205-206)*/
int main()
{
    // Set the locale to support wide characters
    setlocale(LC_ALL, "ja_JP.utf8");

    // Change code page to 65001 (UTF-8)
    system("chcp 65001");

    // File name with mixed Traditional Chinese and English characters
    const wchar_t *filename = L"蔡亞恩.txt";

    // Open the file in read mode with wide characters
    FILE *file = _wfopen(filename, L"r, ccs=UTF-8");

    // Check if the file is opened successfully
    if (file == NULL)
    {
        fwprintf(stderr, L"Error opening file: %ls\n", filename);
        return 1;
    }

    // Read and print the content of the file
    wprintf(L"Content of file %ls:\n", filename);

    wchar_t buffer[1024];
    bool ab = true;
    while (fgetws(buffer, sizeof(buffer) / sizeof(buffer[0]), file) != NULL)
    {
        if (ab)
        {
            ab = false;
            printf("\x1b[32;49m"); // 綠色
        }
        else
        {
            ab = true;
            printf("\x1b[31;49m"); // 紅色
        }
        wprintf(L"%ls", buffer);
    }

    // Close the file
    fclose(file);
    printf("\x1b[39;49m"); // 白色
    // Change code page back to 950 (default for many East Asian languages)
    // system("chcp 950");

    return 0;
}
