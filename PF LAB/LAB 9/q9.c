#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
   char reversed_str[len + 1];

    for (int i = 0, j = len - 1; i < len; i++, j--) {
        reversed_str[i] = str[j];
    }
    reversed_str[len] = '\0';

    strcpy(str, reversed_str);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}