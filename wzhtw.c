#include <stdio.h>
#include <wchar.h>
#include <locale.h>//你如果不加這個，就會出現亂碼(???)
int main() {
    // Set the locale to support wide characters
    setlocale(LC_ALL, "");

    // Wide string in traditional Chinese
    wchar_t wstr[] = L"這是一個繁體中文寬字串";

    // Print wide string using wprintf
    wprintf(L"%ls\n", wstr);

    return 0;
}
