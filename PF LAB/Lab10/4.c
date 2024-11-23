#include <stdio.h>
#include <string.h>
#define MAX_MOVIES 100


struct movie_info {
    char title[20];
    char genre[30];
    char director[100];
    int year;
    float rating;
};


int addmovie(struct movie_info movies[], int count);
void searchMoviesByGenre(struct movie_info movies[], int count);
void displayAllMovies(struct movie_info movies[], int count);

int main() {
    struct movie_info movies[MAX_MOVIES];  
    int movieCount = 0;  
    int choice;

    do {
        
        printf("\nMovie Management\n");
        printf("1. Add a New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                movieCount = addmovie(movies, movieCount);
                break;
            case 2:
                searchMoviesByGenre(movies, movieCount);
                break;
            case 3:
                displayAllMovies(movies, movieCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }

    } while (choice != 4);

    return 0;
}


int addmovie(struct movie_info movies[], int count) {
    struct movie_info newMovie;

    printf("\nEnter movie title: ");
    fgets(newMovie.title, sizeof(newMovie.title), stdin);
    newMovie.title[strcspn(newMovie.title, "\n")] = 0; 

    printf("Enter movie genre: ");
    fgets(newMovie.genre, sizeof(newMovie.genre), stdin);
    newMovie.genre[strcspn(newMovie.genre, "\n")] = 0; 
    printf("Enter director's name: ");
    fgets(newMovie.director, sizeof(newMovie.director), stdin);
    newMovie.director[strcspn(newMovie.director, "\n")] = 0;

    printf("Enter release year: ");
    scanf("%d", &newMovie.year);

    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &newMovie.rating);
    getchar();  

    
    movies[count] = newMovie;
    count++;

    printf("Movie added successfully!\n");
    return count; 
}


void searchMoviesByGenre(struct movie_info movies[], int count) {
    char genre[30];
    int found = 0;

    printf("\nEnter genre to search for: ");
    fgets(genre, sizeof(genre), stdin);
    genre[strcspn(genre, "\n")] = 0; 

    printf("\nMovies in the genre '%s':\n", genre);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            printf("----------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in this genre.\n");
    }
}


void displayAllMovies(struct movie_info movies[], int count) {
    if (count == 0) {
        printf("\nNo movies available.\n");
        return;
    }

    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
        printf("----------------------------\n");
    }
}
