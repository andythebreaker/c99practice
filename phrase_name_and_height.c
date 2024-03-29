#include <ctype.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <locale.h> //你如果不加這個，就會出現亂碼(???)
/*C99 standard (ISO/IEC 9899:1999):
7.11.1.1 The setlocale function (p: 205-206)*/

// both side Linkedlist
#define BOTHSIDE

// record point 1: can get name
#define RECORD_POINT_1 false
#define IF_record_point_1 if (RECORD_POINT_1)
// record point 1: can remove str lead tail space
#define RECORD_POINT_2 false
#define IF_record_point_2 if (RECORD_POINT_2)
// commit sha:8744fbe3b180381b9f0b236954a0cc27938aec29
#define RECORD_POINT_3 false
#define IF_record_point_3 if (RECORD_POINT_3)

#define PRINT_ALL_TRY false
#define IF_print_all_try if (PRINT_ALL_TRY)

// Function to calculate age
int calculateAge(int birthYear, int birthMonth, int birthDay)
{
    // Get current date
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);

    // Calculate age
    int age = current_time.tm_year + 1900 - birthYear;

    // Adjust age based on birth month and day
    if (current_time.tm_mon + 1 < birthMonth || (current_time.tm_mon + 1 == birthMonth && current_time.tm_mday < birthDay))
    {
        age--;
    }

    return age;
}

typedef struct Node
{
    void *data;
    struct Node *next;
#ifdef BOTHSIDE
    struct Node *prev;
#endif
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
    tmp->data = data; // 哇我是87，忘記放data
    if (list->Tail == NULL)
    {
        list->Tail = tmp;
        tmp->next = NULL;
    }
    else
    {
#ifdef BOTHSIDE
        list->Head->prev = tmp;
#endif
        tmp->next = list->Head;
    }
#ifdef BOTHSIDE
    tmp->prev = NULL;
#endif
    list->Head = tmp;
}

typedef int (*COMPARE)(void *, void *);

/*#ifdef BOTHSIDE
Node* partition(Node *low,Node *high){

}

void quickSort(Linkedlist list,COMPARE copmare,Node *low,Node *high){
if(l)
}
#endif*/

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
    int y, m, d;
    int age;
    int height;
    char name[];
} Member;

int CompareAge(void *a, void *b)
{
    return ((Member *)a)->age - ((Member *)b)->age;
}

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

typedef struct TreeNode
{
    struct TreeNode *Left;
    struct TreeNode *Right;
    void *data;
} TreeNode;

typedef enum age_or_height
{
    age,
    height
} age_or_height;

int Comp_sel(void *a, void *b, age_or_height sel)
{
    printf("{[%s]}", ((Member *)b)->name);
    if (sel == age)
    {
        return ((Member *)a)->age - ((Member *)b)->age;
    }
    else
    {
        return ((Member *)a)->height - ((Member *)b)->height;
    }
}

typedef int (*COMP_SEL)(void *, void *, age_or_height);

void InsertNode(TreeNode **PTR_to_NodeRoot, COMP_SEL comp_sel, void *data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    if (*PTR_to_NodeRoot == NULL)
    {
        *PTR_to_NodeRoot = newNode;
        return;
    }
    TreeNode *tmp = *PTR_to_NodeRoot;
    while (1)
    {
        if (comp_sel(data, tmp->data, age) > 0)
        {
            if (tmp->Right == NULL)
            {
                tmp->Right = newNode;
                break;
            }
            else
            {
                tmp = tmp->Right;
            }
        }
        else
        {
            if (tmp->Left == NULL)
            {
                tmp->Right = newNode;
                break;
            }
            else
            {
                tmp = tmp->Left;
            }
        }
    }
}

typedef void (*DISPLAY)(void *);

void Display(void *data)
{
    Member *member_to_free = (Member *)data;
    printf("member name:\t%20s\tbirthdate:%5d%3d%3d\tage:%4d\theight:%4d\n", member_to_free->name, member_to_free->y, member_to_free->m, member_to_free->d, member_to_free->age, member_to_free->height);
}

void inOrder(TreeNode *root, DISPLAY display)
{
    if (root != NULL)
    {
        inOrder(root->Left, display);
        display(root->data);
        inOrder(root->Right, display);
    }
}

int main()
{
    TreeNode *root = NULL;
    ;
    Heap heap;
    HeapPtr h = &heap;
    initHeap(h);
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
        else if (wcsstr(buffer, L"生日：") != NULL)
        { ////COPY STRAT FROM...
            IF_record_point_1 wprintf(L"{{%ls}}", buffer);
            IF_print_all_try printf("\x1b[30;43m");
            wchar_t *p = buffer;
            bool after_colon = false;
            wchar_t *w_name_str = (wchar_t *)malloc(sizeof(wchar_t));
            while (*p != L'\0')
            {
                if (*p == L'：')
                {
                    IF_print_all_try printf("\x1b[34;43;1;3;4m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m");
                    after_colon = true;
                    w_name_str[0] = L'\0';
                }
                else
                {
                    if (after_colon)
                    {
                        int long_str_ptr = (int)wcslen(w_name_str);
                        wchar_t *realloc_w_name_str = (wchar_t *)realloc(w_name_str, sizeof(wchar_t) * (long_str_ptr + 2));
                        if (realloc_w_name_str)
                        {
                            w_name_str = realloc_w_name_str;
                        }
                        else
                        {
                            exit(EXIT_FAILURE);
                        }
                        w_name_str[long_str_ptr] = *p;
                        w_name_str[long_str_ptr + 1] = L'\0';
                    }
                    IF_print_all_try printf("\x1b[30;43m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m");
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
                IF_record_point_3 printf("<<<%s>>%d>", name_str_remove_space, *name_str_remove_space);
                // Member *member = (Member *)malloc(sizeof(Member) + (strlen(name_str_remove_space) + 1) * sizeof(char));
                // strcpy(member->name, name_str_remove_space);
                int birthday[3];
                sscanf(name_str_remove_space, "%d/%d/%d", &birthday[0], &birthday[1], &birthday[2]);
                ((Member *)h->Head->data)->y = birthday[0];
                ((Member *)h->Head->data)->m = birthday[1];
                ((Member *)h->Head->data)->d = birthday[2];
                ((Member *)h->Head->data)->age = calculateAge(birthday[0], birthday[1], birthday[2]);
            }
            else
            {
                printf("[ERROR]\n");
            }
            free(w_name_str);
        } ////COPY END...
        else if (wcsstr(buffer, L"身高：") != NULL)
        { ////COPY STRAT FROM...
            IF_record_point_1 wprintf(L"{{%ls}}", buffer);
            IF_print_all_try printf("\x1b[30;43m");
            wchar_t *p = buffer;
            bool after_colon = false;
            wchar_t *w_name_str = (wchar_t *)malloc(sizeof(wchar_t));
            while (*p != L'\0')
            {
                if (*p == L'：')
                {
                    IF_print_all_try printf("\x1b[34;43;1;3;4m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m");
                    after_colon = true;
                    w_name_str[0] = L'\0';
                }
                else
                {
                    if (after_colon)
                    {
                        int long_str_ptr = (int)wcslen(w_name_str);
                        wchar_t *realloc_w_name_str = (wchar_t *)realloc(w_name_str, sizeof(wchar_t) * (long_str_ptr + 2));
                        if (realloc_w_name_str)
                        {
                            w_name_str = realloc_w_name_str;
                        }
                        else
                        {
                            exit(EXIT_FAILURE);
                        }
                        w_name_str[long_str_ptr] = *p;
                        w_name_str[long_str_ptr + 1] = L'\0';
                    }
                    IF_print_all_try printf("\x1b[30;43m");
                    IF_print_all_try wprintf(L"%lc", *p);
                    IF_print_all_try printf("\x1b[0m");
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
                IF_record_point_3 printf("<<<%s>>%d>", name_str_remove_space, *name_str_remove_space);
                // Member *member = (Member *)malloc(sizeof(Member) + (strlen(name_str_remove_space) + 1) * sizeof(char));
                // strcpy(member->name, name_str_remove_space);
                // pushHeap(h, member);
                ((Member *)h->Head->data)->height = atoi(name_str_remove_space);
            }
            else
            {
                printf("[ERROR]\n");
            }
            free(w_name_str);
        } ////COPY END...
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
    while (h->Tail != NULL)
    {
        Member *member_to_free = (Member *)popHeap(h);
        InsertNode(&root, &Comp_sel, member_to_free);
        // printf("member name:\t%20s\tbirthdate:%5d%3d%3d\tage:%4d\theight:%4d\n", member_to_free->name, member_to_free->y, member_to_free->m, member_to_free->d, member_to_free->age, member_to_free->height);
        // free(member_to_free);
    }

    inOrder(root, &Display);

    return EXIT_SUCCESS;
}
