#include <stdio.h>
#include <string.h>

int main() {
    char words[5][21]; 

    printf("Enter 5 words:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < 5; i++) {
        int len = strlen(words[i]);
        int palindrome = 1; 

        for (int j = 0; j < len / 2; j++) {
            if (words[i][j] != words[i][len - j - 1]) {
               palindrome = 0;
                break; 
            }
        }

        if (palindrome) {
            printf("%s is a Palindrome\n", words[i]);
        } else {
            printf("%s is Not a Palindrome\n", words[i]);
        }
    }

    return 0;
}