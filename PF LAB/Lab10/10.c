#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100
#define MAX_STRING_LENGTH 50

struct TravelPackage {
    char packageName[MAX_STRING_LENGTH];
    char destination[MAX_STRING_LENGTH];
    int duration;         
    double cost;         
    int seatsAvailable;   
};


void displayPackages(struct TravelPackage packages[], int packageCount) {
    if (packageCount == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d: %s\n", i + 1, packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: %.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
        printf("\n");
    }
}


void bookPackage(struct TravelPackage packages[], int packageCount) {
    int packageIndex;
    printf("Enter the package number you want to book (1 to %d): ", packageCount);
    scanf("%d", &packageIndex);

    
    if (packageIndex < 1 || packageIndex > packageCount) {
        printf("Invalid package number.\n");
        return;
    }

    packageIndex--; 

   
    if (packages[packageIndex].seatsAvailable > 0) {
        packages[packageIndex].seatsAvailable--;
        printf("Booking successful for package: %s\n", packages[packageIndex].packageName);
        printf("Seats remaining: %d\n", packages[packageIndex].seatsAvailable);
    } else {
        printf("Sorry, no seats available for package: %s\n", packages[packageIndex].packageName);
    }
}

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int packageCount = 0;
    int choice;

   
    strcpy(packages[0].packageName, "Beach Getaway");
    strcpy(packages[0].destination, "Somiani");
    packages[0].duration = 7;
    packages[0].cost = 20000.00;
    packages[0].seatsAvailable = 5;

    strcpy(packages[1].packageName, "Mountain Adventure");
    strcpy(packages[1].destination, "Babusar Top");
    packages[1].duration = 10;
    packages[1].cost = 100000;
    packages[1].seatsAvailable = 3;

    packageCount = 2; 

    do {
        printf("\nTravel Package Management Menu:\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Travel Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages(packages, packageCount);
                break;
            case 2:
                bookPackage(packages, packageCount);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}