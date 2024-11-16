#include <stdio.h>
#include <string.h>

void rev_str(char *s)
{
    if (s == NULL || *s == '\0')
    {
        return;
    }
    rev_str(s + 1);
    printf("%c", *s);
}
int main()
{
    char str[100];
    printf("Enter string :");
    scanf("%s", &str);

    rev_str(str);
    printf("\n");
}