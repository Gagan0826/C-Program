#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, len;
    char temp;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    for(i = 0; i < len-1; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("String after sorting in alphabetical order: %s", str);

    return 0;
}
