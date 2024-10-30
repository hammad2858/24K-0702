#include <stdio.h>
#include <string.h>

void analyze_slogans(char *slogans[], int num_slogans) {
    for (int i = 0; i < num_slogans; i++) {
        char *slogan = slogans[i];
        int freq[128] = {0}; 

        
        for (int j = 0; slogan[j] != '\0'; j++) {
            freq[(unsigned char)slogan[j]]++;
        }

        
        printf("For \"%s\": {", slogan);
        for (int k = 0; k < 128; k++) {
            if (freq[k] > 0) {
                printf("'%c': %d", k, freq[k]);
                if (k < 127) {
                    printf(", ");
                }
            }
        }
        printf("}\n");
    }
}

int main() {
    char *slogans[] = {"buy now", "save big", "limited offer"};
    int num_slogans = sizeof(slogans) / sizeof(slogans[0]);

    analyze_slogans(slogans, num_slogans);
    return 0;
}
