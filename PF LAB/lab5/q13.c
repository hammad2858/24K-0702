#include <stdio.h>

int main() {
    char character, encrypted_char,decrypted_char;
    int key;

    printf("Enter a character: ");
    scanf("%c", &character);

    printf("Enter a key: ");
    scanf("%d", &key);

    // Encryption
    encrypted_char = character ^ key;
    printf("Encrypted character: %c\n", encrypted_char);

    // Decryption
    decrypted_char = encrypted_char ^ key;
    printf("Decrypted character: %c\n", decrypted_char);

    return 0;
}