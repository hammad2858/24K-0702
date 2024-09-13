#include <stdio.h>

int main() {
    char character;

    printf("Enter a character: ");
    scanf("%c", &character);
	
	// checked values  via ascii code//

    if (character >= 'a' && character<= 'z') {
        printf(" small alphabet.\n", character);
    } 
	else if (character >= 'A' && character <= 'Z') {
        printf(" capital alphabet.\n", character);
    } 
	else if (character >= '0' && character <= '9') {
        printf(" digit.\n", character);
    } 
	else {
        printf(" special character.\n", characters);
    }

    return 0;
}