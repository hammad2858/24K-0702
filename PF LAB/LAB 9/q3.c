#include <stdio.h>
#include <string.h>

int main() {
    char destination[100], source[100];
    int n;

    printf("Enter the destination string: ");
    scanf("%s", destination);

    printf("Enter the source string: ");
    scanf("%s", source);

    printf("Enter the number of characters to append: ");
    scanf("%d", &n);

    if (n > strlen(source)) {
        n = strlen(source);
    }

    // Concatenate the first n characters of the source string to the destination
    strncat(destination , source, n);

    printf("The new concatenated string is: %s\n", destination);

    return 0;
}