#include <ctype.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <locale.h> //你如果不加這個，就會出現亂碼(???)
/*C99 standard (ISO/IEC 9899:1999):
7.11.1.1 The setlocale function (p: 205-206)*/

// record point 1: can get name
#define RECORD_POINT_1 false
#define IF_record_point_1 if (RECORD_POINT_1)
// record point 1: can remove str lead tail space
#define RECORD_POINT_2 false
#define IF_record_point_2 if (RECORD_POINT_2)

#define PRINT_ALL_TRY false
#define IF_print_all_try if (PRINT_ALL_TRY)

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Linkedlist
{
    Node *Head;
    Node *Tail;
} Linkedlist;

void initLinkedlist(Linkedlist *list)
{
    list->Head = NULL;
    list->Tail = NULL;
}

typedef Linkedlist Heap;

void addHead(Linkedlist *list, void *data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data=data;//哇我是87，忘記放data
    if (list->Tail == NULL)
    {
        list->Tail = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = list->Head;
    }
    list->Head = tmp;
}

void initHeap(Heap *heap)
{
    initLinkedlist(heap);
}

void pushHeap(Heap *heap, void *data)
{
    addHead(heap, data);
}

void *popHeap(Heap *heap)
{
    void *tmp = NULL;
    if (heap->Tail == NULL)
    {
        tmp = NULL;
    }
    else if (heap->Head == heap->Tail)
    {
        tmp = heap->Head->data;
        free(heap->Head);
        heap->Head = NULL;
        heap->Tail = NULL;
    }
    else
    {
        Node *node_to_remove = heap->Head;
        tmp = node_to_remove->data;
        heap->Head = node_to_remove->next;
        free(node_to_remove);
    }
    return tmp;
}

typedef struct Member
{
    int age;
    int height;
    char name[];
} Member;

void addNewMember(Linkedlist *list, Member *member)
{
    addHead(list, (void *)member);
}

void addNewMember_via_name_age_height(char *name, int age, int height)
{
    Member *member = (Member *)malloc(sizeof(Member) + strlen(name) + 1); //! IMPORTANT!我都忘記這裡這樣搞要加一
    member->age = age;
    member->height = height;
    strcpy(member->name, name);
}

typedef Heap *HeapPtr;

int main()
{
    Heap heap;
    HeapPtr h = &heap;
    initHeap(h);
    // Set the locale to support wide characters
    setlocale(LC_ALL, "ja_JP.utf8");

    // Change code page to 65001 (UTF-8)
    system("chcp 65001");

    // File name with mixed Traditional Chinese and English characters
    const wchar_t *filename = L"C:\\Users\\vboxuser\\c99practice\\蔡亞恩.txt";

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
            IF_print_all_try printf("\x1b[32;49m"); // 綠色
        }
        else
        {
            ab = true;
            IF_print_all_try printf("\x1b[31;49m"); // 紅色
        }
        // if string include "漢語拼音：", \x1b[30;43m
        if (wcsstr(buffer, L"漢語拼音：") != NULL) // TODO? if not wchar_t ?
        {

            IF_record_point_1 wprintf(L"{{%ls}}", buffer);

            IF_print_all_try printf("\x1b[30;43m"); // 黑底黃字
            // buffer.foreach
            wchar_t *p = buffer;
            bool after_colon = false;
            wchar_t *w_name_str = (wchar_t *)malloc(sizeof(wchar_t));
            while (*p != L'\0')
            {
                if (*p == L'：')
                {
                    IF_print_all_try printf("\x1b[34;43;1;3;4m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m"); // 白色
                    after_colon = true;
                    w_name_str[0] = L'\0';
                }
                else
                {
                    if (after_colon)
                    {
                        /*
                                https://learn.microsoft.com/zh-tw/cpp/c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l?view=msvc-170
                                strlen 會將字串解譯為單一位元組字元字串，因此即使字串包含多位元組字元，傳回值也會一律等於位元組數。 wcslen 是寬字元版本的 strlen；wcslen 的引數是寬字元字串，且字元的計數也是使用寬 (二位元) 字元。 否則，wcslen 和 strlen 的行為即會相同。
                                */
                        int long_str_ptr = (int)wcslen(w_name_str);
                        wchar_t *realloc_w_name_str = (wchar_t *)realloc(w_name_str, sizeof(wchar_t) * (long_str_ptr + 2));
                        if (realloc_w_name_str)
                        {
                            w_name_str = realloc_w_name_str;
                        }
                        else
                        {
                            exit(EXIT_FAILURE); // TODO __LINE__
                        }
                        w_name_str[long_str_ptr] = *p;
                        w_name_str[long_str_ptr + 1] = L'\0'; //! important 幹87喔XD
                    }
                    IF_print_all_try printf("\x1b[30;43m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m"); // 白色
                }
                p++;
            }
            IF_record_point_1 wprintf(L"<<%ls>>\n", w_name_str);
            char name_str[wcslen(w_name_str) + 1];
            int ret = wcstombs(name_str, w_name_str, sizeof(name_str) / sizeof(char));
            if (ret == wcslen(w_name_str) + 1)
            {
                name_str[wcslen(w_name_str)] = '\0';
                printf("[!]\n");
            }
            if (ret)
            {
                IF_record_point_2 printf("%s\n", name_str);
                char *name_str_low_ptr = name_str;
                while (*name_str_low_ptr != '\0' && isspace(*name_str_low_ptr))
                {
                    name_str_low_ptr++;
                }
                char *name_str_high_ptr = name_str + strlen(name_str) - 1;
                while (name_str_high_ptr > name_str && isspace(*name_str_high_ptr))
                {
                    name_str_high_ptr--;
                }
                char name_str_remove_space[name_str_high_ptr - name_str_low_ptr + 2];
                memcpy(name_str_remove_space, name_str_low_ptr, name_str_high_ptr - name_str_low_ptr + 1);
                name_str_remove_space[name_str_high_ptr - name_str_low_ptr + 1] = '\0';
                IF_record_point_2 printf("<<<%s>>%d>", name_str_remove_space, *name_str_remove_space);
                Member *member = (Member *)malloc(sizeof(Member) + (strlen(name_str_remove_space) + 1) * sizeof(char));
                strcpy(member->name, name_str_remove_space);
                pushHeap(h, member);
            }
            else
            {
                printf("[ERROR]\n");
            }
            free(w_name_str);
        }
        else
        {
            IF_print_all_try wprintf(L"%ls", buffer);
        }
    }

    // Close the file
    fclose(file);
    IF_print_all_try printf("\x1b[39;49m"); // 白色
    // Change code page back to 950 (default for many East Asian languages)
    // system("chcp 950");

    printf("\n");
    while (h->Tail!=NULL)
    {
        Member *member_to_free = (Member *)popHeap(h);
        printf("member name:\t%s\n", member_to_free->name);
        free(member_to_free);
    }

    return EXIT_SUCCESS;
}
