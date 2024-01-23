
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <locale.h> //你如果不加這個，就會出現亂碼(???)
/*C99 standard (ISO/IEC 9899:1999):
7.11.1.1 The setlocale function (p: 205-206)*/

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
void initHeap(Heap* heap)
{
    initLinkedlist(heap);
}

void addHeap(Heap* heap, void* data)
{
    addHead(heap,data);
}

typedef struct Member
{
    int age;
    int height;
    char name[];
} Member;

void addNewMember(Linkedlist *list, Member *member)
{
    addHead(list,(void*)member);
}

void addNewMember_via_name_age_height(char* name,int age,int height)
{
    Member *member=(Member*)malloc(sizeof(Member)+strlen(name)+1);//!IMPORTANT!我都忘記這裡這樣搞要加一
    member->age=age;
    member->height=height;
    strcpy(member->name,name);
}

int main()
{
    // Set the locale to support wide characters
    setlocale(LC_ALL, "");

    // Change code page to 65001 (UTF-8)
    system("chcp 65001");

    // File name with mixed Traditional Chinese and English characters
    const wchar_t *filename = L"D:\\Andy\\c99practice\\蔡亞恩.txt";

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
        // if string include "漢語拼音：", \x1b[30;43m
        if (wcsstr(buffer, L"漢語拼音：") != NULL) // TODO? if not wchar_t ?
        {
            printf("\x1b[30;43m"); // 黑底黃字
            // buffer.foreach
            wchar_t *p = buffer;
            while (*p != L'\0')
            {
                if (*p == L'：')
                {
                    printf("\x1b[34;43;1;3;4m");
                    wprintf(L"%lc", *p);
                    printf("\x1b[0m"); // 白色
                }
                else
                {
                    printf("\x1b[30;43m");
                    wprintf(L"%lc", *p);
                    printf("\x1b[0m"); // 白色
                }
                p++;
            }
        }
        else
        {
            wprintf(L"%ls", buffer);
        }
    }

    // Close the file
    fclose(file);
    printf("\x1b[39;49m"); // 白色
    // Change code page back to 950 (default for many East Asian languages)
    // system("chcp 950");

    return 0;
}
