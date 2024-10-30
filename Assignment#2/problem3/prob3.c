#include <stdio.h>
#include <string.h>

void compress_word(const char *input, char *output, int *removed_count) {
    int j = 0;
    *removed_count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (i == 0 || input[i] != input[i - 1]) {
            output[j++] = input[i];
        } else {
            (*removed_count)++;
        }
    }
    output[j] = '\0';
}

void compress_multiple_words(char words[][100], int num_words) {
    for (int i = 0; i < num_words; i++) {
        char compressed[100];
        int removed_count = 0;

        compress_word(words[i], compressed, &removed_count);
        printf("Original: \"%s\", Compressed: \"%s\", Removed: %d\n", 
               words[i], compressed, removed_count);
    }
}

int main() {
    char words[][100] = {"booooook", "coooool", "heeeey"};
    int num_words = sizeof(words) / sizeof(words[0]);

    compress_multiple_words(words, num_words);
    return 0;
}
