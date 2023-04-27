#include <stdio.h>

int main() {
    char str[100], newstr[100];
    int i, j = 0;

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\t') {
            newstr[j] = str[i];
            j++;
        }
    }
    newstr[j] = '\0';

    printf("String after removing white spaces: %s", newstr);

    return 0;
}
