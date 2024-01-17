#include <stdio.h>
#include <string.h>

void reverseRows(char *input) {
    int length = strlen(input);
    if (length <= 0) {
        return; // Empty string or invalid input
    }

    // Find the end of each row and reverse them in-place
    int start = 0;
    for (int i = 0; i < length; ++i) {
        if (input[i] == '\n' || input[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                // Swap characters at start and end indices
                char temp = input[start];
                input[start] = input[end];
                input[end] = temp;
                ++start;
                --end;
            }
            start = i + 1; // Move to the next row
        }
    }

    // Reverse the entire string in-place
    int i = 0, j = length - 1;
    while (i < j) {
        // Swap characters at i and j indices
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        ++i;
        --j;
    }
}

int main() {
    char input[] = "1st row\n2nd row\n3ed row\n";
    printf("Input string: \"%s\"\n", input);

    reverseRows(input);

    printf("Output string: \"%s\"\n", input);

    return 0;
}

