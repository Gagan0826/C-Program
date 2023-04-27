#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int len1, len2, i, j, flag = 0;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    for(i=0; i<=len1-len2; i++) {
        for(j=0; j<len2; j++) {
            if(str1[i+j] != str2[j]) {
                break;
            }
        }
        if(j == len2) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("%s is a substring of %s", str2, str1);
    }
    else {
        printf("%s is not a substring of %s", str2, str1);
    }

    return 0;
}
