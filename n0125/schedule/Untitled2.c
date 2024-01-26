
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>
#include <limits.h>
#include <locale.h>
#define BLACK_TXT_YELLOW_BG "\x1b[30;43m"
#define RESET "\x1b[0m"
#define PADDING 5
typedef struct DaySchedule
{
    wchar_t className[8][35];
} DaySchedule;

typedef struct Schedule
{
    DaySchedule D[5];
} Schedule;

int main(int argv, char **argc)
{
    setlocale(LC_ALL, "ja_JP.utf8");
    FILE *fp;
    wchar_t str[4 + 4 + 1];
    swprintf(str, 4 + 4 + 1, L"%hs", argc[1]);
    printf("%ls\n", str);
    fp = _wfopen(str, L"r, ccs=UTF-8");
    wchar_t buffer[5000];
    printf("===");

    // VARDEF:first 5 td is dont care
    int padding = 0;
    // VARDEF:weekday 1~5
    int weekday = 0;
    // VARDEF:classSegment 1~8
    int classSegment = 0;
    // VARDEF:main
    Schedule schedule;

    while (fgetws(buffer, 5000, fp) != NULL) //! important
    {
        if (wcsstr(buffer, L"<td class=\"tdColumn\">"))
        {
            printf(BLACK_TXT_YELLOW_BG);
            if (padding < PADDING)
            {
                padding++;
            }
            else
            {
                wchar_t *p = wcsstr(buffer, L"</a></span>");
                while (*p != L'\0')
                {
                    if (*p == L'<')
                    {
                        break;
                    }
                    // LINE_CTRL:need end of {}
                    p--;
                }
                wmemcpy(schedule.D[weekday].className[classSegment], p + 1, ((wcsstr(buffer, L"</a></span>")) - (p + 1)) / sizeof(wchar_t));
                schedule.D[weekday].className[classSegment][((wcsstr(buffer, L"</a></span>")) - (p + 1)) / sizeof(wchar_t)] = L'\0';
                // LINE_CTRL:need end of {}
                if (weekday >= 4)
                {
                    weekday = 0;
                    classSegment++;
                }
                else
                {
                    weekday++;
                }
            }
        }
        wprintf(L"%ls\n", buffer);
        printf(RESET);
    }
    fclose(fp);
}
