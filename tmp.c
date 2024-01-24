{////COPY STRAT FROM...
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
        printf("<<<%s>>%d>", name_str_remove_space, *name_str_remove_space);
        Member *member = (Member *)malloc(sizeof(Member) + (strlen(name_str_remove_space) + 1) * sizeof(char));
        strcpy(member->name, name_str_remove_space);
        pushHeap(h, member);
    }
    else
    {
        printf("[ERROR]\n");
    }
    free(w_name_str);
}////COPY END...