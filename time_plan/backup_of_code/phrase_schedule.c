#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include <ctype.h>
#include <wchar.h>
#include <limits.h>
#include <locale.h>
#include <stdbool.h>
#define BLACK_TXT_YELLOW_BG "\x1b[30;43m"
#define BLACK_TXT_PINK_BG "\x1b[30;45m"
#define RESET "\x1b[0m"
#define PADDING 5
#define DEBUG_999 if (false)
#define GREEN_1 L"國"
#define GREEN_2 L"英"
#define GREEN_3 L"數"
#define RED_1 L"歷"
#define RED_2 L"地"
#define RED_3 L"公"
#define RED_4 L"音"
#define RED_5 L"體"
#define RED_6 L"自"
#define RED_7 L"綜"
#define IF_STRSTR(CLASSNAME) (wcsstr(schedule->D[i].className[j], CLASSNAME))
#define IF_GREEN if (IF_STRSTR(GREEN_1) || IF_STRSTR(GREEN_2) || IF_STRSTR(GREEN_3))
#define IF_SHOW_GREEN                \
    IF_GREEN                         \
    {                                \
        printf(BLACK_TXT_YELLOW_BG); \
    }
#define IF_RED if ( \
    IF_STRSTR(RED_1) || IF_STRSTR(RED_2) || IF_STRSTR(RED_3) || IF_STRSTR(RED_4) || IF_STRSTR(RED_5) || IF_STRSTR(RED_6) || IF_STRSTR(RED_7))
#define IF_SHOW_RED                \
    IF_RED                         \
    {                              \
        printf(BLACK_TXT_PINK_BG); \
    }
#define XO

typedef struct DaySchedule
{
    wchar_t className[8][35];
} DaySchedule;

typedef struct Schedule
{
    DaySchedule D[5];
} Schedule;

void printSchedule(Schedule *schedule)
{
#ifndef XO
    printf("==========Schedule==========\n");
#endif
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
#ifdef XO
            bool isGreenOrRed = false;
            IF_GREEN
            {
                printf("O");
                isGreenOrRed = true;
            }
            IF_RED
            {
                printf("X");
                isGreenOrRed = true;
            }
            if (!isGreenOrRed)
            {
                printf("-");
            }
#else
            IF_SHOW_GREEN
            IF_SHOW_RED
            wprintf(L"%8ls,\t", schedule->D[i].className[j]);
            printf(RESET);
#endif
        }
#ifndef XO
        printf("\n");
#endif
    }
}

int main(int argv, char **argc)
{
    setlocale(LC_ALL, "ja_JP.utf8");
    FILE *fp;
    wchar_t str[4 + 4 + 1];
    swprintf(str, 4 + 4 + 1, L"%hs", argc[1]);
#ifndef XO
    printf("%ls\n", str);
#endif
    fp = _wfopen(str, L"r, ccs=UTF-8");
    wchar_t buffer[5000];
#ifndef XO
    printf("===");
#endif

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
            DEBUG_999 printf(BLACK_TXT_YELLOW_BG);
            if (padding < PADDING)
            {
                padding++;
            }
            else
            {
                wchar_t *p = wcsstr(buffer, L"</a></span>") - 1;
                DEBUG_999 printf("\x1b[30;42m\t{DEBUG}");
                DEBUG_999 wprintf(L"%ls", p);
                while (*p != L'\0')
                {
                    if (*p == L'>')
                    {
                        break;
                    }
                    // LINE_CTRL:need end of {}
                    p--;
                }
                DEBUG_999 printf("\x1b[30;45m\t{DEBUG}");
                DEBUG_999 wprintf(L"%ls", p);
                DEBUG_999 printf("sizeofstr(%d)", ((wcsstr(buffer, L"</a></span>")) - (p + 1)) / sizeof(wchar_t));
                //! important 這裡是要放兩個指標相減，不用除sizeof..............VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
                wmemcpy(schedule.D[weekday].className[classSegment], p + 1, ((wcsstr(buffer, L"</a></span>")) - (p + 1)) /*/ sizeof(wchar_t)*/);
                schedule.D[weekday].className[classSegment][((wcsstr(buffer, L"</a></span>")) - (p + 1)) /*/ sizeof(wchar_t)*/] = L'\0';
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
        DEBUG_999 wprintf(L"%ls\n", buffer);
        printf(RESET);
    }
    fclose(fp);
    printSchedule(&schedule);
}