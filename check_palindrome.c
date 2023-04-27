#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
void main()
{
    char str1[100],str2[100];
    int i;
    printf("Enter any string to reverse :");
    scanf("%[^\n]s",str1);
    for(i=strlen(str1)-1;i>=0;i--)
    {
        str2[i]=str1[i];
    }
    if(strcmp(str1,str2)==0)
        printf("True");
    else
        printf("False");
}
