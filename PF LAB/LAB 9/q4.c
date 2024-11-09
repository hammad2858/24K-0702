#include <stdio.h>
#include <string.h>

int main() {
    char words[][10] = {"hello", "world", "programming", "c"};
    int num_words = sizeof(words) / sizeof(words[0]);

    char input_word[10];

    printf("Enter a word: ");
    scanf("%s", input_word);

    int found = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], input_word) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}