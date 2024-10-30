#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_TRANSACTIONS 100

// Function to compare two characters (for sorting)
int char_compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Function to sort a string
void sort_string(char *str) {
    size_t len = strlen(str);
    qsort(str, len, sizeof(char), char_compare);
}

// Function to group anagrams
void group_anagrams(char transactions[][MAX_STR_LEN], int n) {
    // Create an array to hold the sorted versions of the transactions
    char sorted_transactions[MAX_TRANSACTIONS][MAX_STR_LEN];
    int grouped[MAX_TRANSACTIONS] = {0}; // Track if the transaction is already grouped

    // Sort each transaction and store it
    for (int i = 0; i < n; i++) {
        strcpy(sorted_transactions[i], transactions[i]);
        sort_string(sorted_transactions[i]);
    }

    printf("Grouped Anagrams:\n");

    // Group anagrams
    for (int i = 0; i < n; i++) {
        if (grouped[i]) continue; // Skip already grouped transactions

        printf("[");
        int first = 1; // To handle comma placement
        for (int j = i; j < n; j++) {
            if (!grouped[j] && strcmp(sorted_transactions[i], sorted_transactions[j]) == 0) {
                // Print the original transaction
                if (!first) {
                    printf(", ");
                }
                printf("\"%s\"", transactions[j]);
                grouped[j] = 1; // Mark as grouped
                first = 0; // Update after first print
            }
        }
        printf("]\n");
    }
}

int main() {
    char transactions[MAX_TRANSACTIONS][MAX_STR_LEN] = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    int n = 6; // Number of transactions

    group_anagrams(transactions, n);

    return 0;
}