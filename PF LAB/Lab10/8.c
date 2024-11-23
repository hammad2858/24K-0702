#include <stdio.h>
#include <string.h>

#define MAX_CARS 100
#define MAX_STRING_LENGTH 50

struct Car {
    char make[MAX_STRING_LENGTH];
    char model[MAX_STRING_LENGTH];
    int year;
    float price;
    float mileage;
};

void addCar(struct Car cars[], int carCount) {
    if (carCount >= MAX_CARS) {
        printf("Cannot add more cars, dealership is full.\n");
        return;
    }// func ends

    struct Car newCar;
    printf("Enter car make: ");
    scanf("%s", &newCar.make);
    printf("Enter car model: ");
    scanf("%s", &newCar.model);
    printf("Enter car year: ");
    scanf("%d", &newCar.year);
    printf("Enter car price: ");
    scanf("%.1f", &newCar.price);
    printf("Enter car mileage: ");
    scanf("%.1f", &newCar.mileage);

    cars[carCount] = newCar;  
    printf("Car added successfully!\n");
}

void displayCars(struct Car cars[], int carCount) {
    if (carCount == 0) {
        printf("No cars available.\n");
        return;
    }

    printf("\nAvailable Cars:\n");
    for (int i = 0; i < carCount; i++) {
        printf("Car %d: %s %s (%d) - Price: $%.2f, Mileage: %.2f miles\n",i + 1, cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }// i ends 
} // func ends

void searchCars(struct Car cars[], int carCount) {
    char searchTerm[MAX_STRING_LENGTH];
    printf("Enter make or model to search for: ");
    scanf("%s", searchTerm);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < carCount; i++) {
        if (strcmp(cars[i].make, searchTerm) == 0 || strcmp(cars[i].model, searchTerm) == 0) {
            printf("Car %d: %s %s (%d) - Price: $%.2f, Mileage: %.2f miles\n",
                   i + 1, cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching the search term '%s'.\n", searchTerm);
    }
} // func ends

int main() {
    struct Car cars[MAX_CARS];
    int carCount = 0;
    int choice;

    do {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add Car\n");
        printf("2. Display Cars\n");
        printf("3. Search Cars\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, carCount);
                carCount++;  // Increment car count after adding a car
                break;
            case 2:
                displayCars(cars, carCount);
                break;
            case 3:
                searchCars(cars, carCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}