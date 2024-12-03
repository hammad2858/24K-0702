#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int publicationYear;
};

struct Library {
    struct Book *books;
    int numBooks;
};

int main() {
    int numBooks = 5;

    
    struct Library *library = (struct Library *)malloc(sizeof(struct Library));
    library->numBooks = numBooks;

    
    library->books = (struct Book *)malloc(numBooks * sizeof(struct Book));

    
    for (int i = 0; i < numBooks; i++) {
        printf("Enter details for book %d:\n", i + 1);

        printf("Title: ");
        scanf("%s", library->books[i].title);

        printf("Author: ");
        scanf("%s", library->books[i].author);

        printf("Publication Year: ");
        scanf("%d", &library->books[i].publicationYear);
    }

    
    printf("\nBooks published after 2000:\n");
    for (int i = 0; i < numBooks; i++) {
        if (library->books[i].publicationYear > 2000) {
            printf("%s\n", library->books[i].title);
        }
    }

    
    free(library->books);
    free(library);

    return 0;
}