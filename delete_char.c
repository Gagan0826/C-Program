#include <stdio.h>

int main() {
    char str[100], newstr[100], ch;
    int i, j = 0;

    printf("Enter a string: ");
    gets(str);

    printf("Enter the character to be deleted: ");
    scanf("%c", &ch);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ch) {
            newstr[j] = str[i];
            j++;
        }
    }
    newstr[j] = '\0';

    printf("String after deleting '%c': %s", ch, newstr);

    return 0;
}
