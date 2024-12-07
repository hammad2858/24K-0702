#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    int at_count = 0, dot_count = 0;
    int i = 0;

    
    if (email[0] == '\0') {
        return 0;
    }

    while (email[i] != '\0') {
        if (email[i] == '@') {
            at_count++;
        } else if (email[i] == '.') {
            dot_count++;
        }
        i++;
    }

    
    return (at_count == 1 && dot_count > 1);
}

int main() {
    char *email;
    int length;

    printf("Enter your email address: ");
    scanf("%s", &length);

    
    email = (char *)malloc(length + 1);

    printf("Enter your email address: ");
    scanf("%s", email);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    
    free(email);

    return 0;
}