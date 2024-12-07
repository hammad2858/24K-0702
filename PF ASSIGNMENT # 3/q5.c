#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeInventory(char*** speciesSupplies, int** numSupplies, int numSpecies) {
    *speciesSupplies = (char**)malloc(numSpecies * sizeof(char*));
    *numSupplies = (int*)calloc(numSpecies, sizeof(int));
    for (int i = 0; i < numSpecies; i++) {
        (*speciesSupplies)[i] = NULL;
    }
}

void addSupplies(char*** speciesSupplies, int* numSupplies, int speciesIndex, int numNewSupplies) {
    printf("Adding %d supplies for species %d:\n", numNewSupplies, speciesIndex + 1);
    (*speciesSupplies)[speciesIndex] = (char**)realloc((*speciesSupplies)[speciesIndex], 
                                                (numSupplies[speciesIndex] + numNewSupplies) * sizeof(char*));
    for (int i = 0; i < numNewSupplies; i++) {
        char buffer[100];
        printf("Enter supply name: ");
        scanf("%s", buffer);
        (*speciesSupplies)[speciesIndex][numSupplies[speciesIndex] + i] = strdup(buffer);
    }
    numSupplies[speciesIndex] += numNewSupplies;
}

void updateSupply(char*** speciesSupplies, int* numSupplies, int speciesIndex, int supplyIndex) {
    if (speciesIndex < 0 || supplyIndex < 0 || speciesSupplies[speciesIndex] == NULL || 
        supplyIndex >= numSupplies[speciesIndex]) {
        printf("Invalid species or supply index.\n");
        return;
    }
    printf("Updating supply %d for species %d:\n", supplyIndex + 1, speciesIndex + 1);
    char buffer[100];
    printf("Enter new supply name: ");
    scanf("%s", buffer);
    free(speciesSupplies[speciesIndex][supplyIndex]);
    speciesSupplies[speciesIndex][supplyIndex] = strdup(buffer);
}

void removeSpecies(char*** speciesSupplies, int* numSupplies, int speciesIndex, int numSpecies) {
    if (speciesIndex < 0 || speciesIndex >= numSpecies || speciesSupplies[speciesIndex] == NULL) {
        printf("Invalid species index.\n");
        return;
    }
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);
    speciesSupplies[speciesIndex] = NULL;
    numSupplies[speciesIndex] = 0;
    printf("Species %d removed successfully.\n", speciesIndex + 1);
}

void displayInventory(char*** speciesSupplies, int* numSupplies, int numSpecies) {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < numSpecies; i++) {
        if (speciesSupplies[i] == NULL) {
            printf("Species %d: No data available.\n", i + 1);
        } else {
            printf("Species %d supplies:\n", i + 1);
            for (int j = 0; j < numSupplies[i]; j++) {
                printf("- %s\n", speciesSupplies[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int numSpecies, choice, speciesIndex, supplyIndex, numNewSupplies;
    char*** speciesSupplies;
    int* numSupplies;

    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    initializeInventory(&speciesSupplies, &numSupplies, numSpecies);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter species index (1-%d): ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--;
                if (speciesIndex < 0 || speciesIndex >= numSpecies) {
                    printf("Invalid species index.\n");
                    break;
                }
                printf("Enter the number of new supplies: ");
                scanf("%d", &numNewSupplies);
                addSupplies(&speciesSupplies, numSupplies, speciesIndex, numNewSupplies);
                break;

            case 2:
                printf("Enter species index (1-%d): ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--;
                if (speciesIndex < 0 || speciesIndex >= numSpecies || speciesSupplies[speciesIndex] == NULL) {
                    printf("Invalid species index.\n");
                    break;
                }
                printf("Enter supply index (1-%d): ", numSupplies[speciesIndex]);
                scanf("%d", &supplyIndex);
                supplyIndex--;
                updateSupply(speciesSupplies, numSupplies, speciesIndex, supplyIndex);
                break;

            case 3:
                printf("Enter species index (1-%d): ", numSpecies);
                scanf("%d", &speciesIndex);
                speciesIndex--;
                removeSpecies(speciesSupplies, numSupplies, speciesIndex, numSpecies);
                break;

            case 4:
                displayInventory(speciesSupplies, numSupplies, numSpecies);
                break;

            case 5:
                for (int i = 0; i < numSpecies; i++) {
                    if (speciesSupplies[i] != NULL) {
                        for (int j = 0; j < numSupplies[i]; j++) {
                            free(speciesSupplies[i][j]);
                        }
                        free(speciesSupplies[i]);
                    }
                }
                free(speciesSupplies);
                free(numSupplies);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
