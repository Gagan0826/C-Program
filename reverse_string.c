#include <stdio.h>

int main() {
    char str[100], rev[100];
    int i, len;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    for(i = 0; i < len; i++) {
        rev[i] = str[len-i-1];
    }
    rev[len] = '\0';

    printf("Original string: %s\n", str);
    printf("Reversed string: %s", rev);

    return 0;
}
