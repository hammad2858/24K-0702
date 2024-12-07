#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for content metadata
typedef struct {
    char title[100];
    float rating;
    int runtime; // in minutes
    char encodingFormat[20];
} ContentMetadata;

// Structure for device preferences
typedef struct {
    char resolution[20];
    int playbackPosition; // in seconds
    float bandwidthUsage; // in Mbps
} DevicePreference;

// Structure for user profile
typedef struct {
    char username[50];
    float* engagementScores; // Row in engagement matrix
    DevicePreference** devicePreferences; // Device-specific preferences
    int numDevices; // Number of devices
} UserProfile;

void initializeEngagementMatrix(float*** matrix, int numUsers, int numCategories) {
    *matrix = (float**)malloc(numUsers * sizeof(float*));
    for (int i = 0; i < numUsers; i++) {
        (*matrix)[i] = (float*)calloc(numCategories, sizeof(float)); // Initialize with zeros
    }
}

void initializeDeviceMatrix(DevicePreference**** matrix, int numUsers, int maxDevices) {
    *matrix = (DevicePreference***)malloc(numUsers * sizeof(DevicePreference**));
    for (int i = 0; i < numUsers; i++) {
        (*matrix)[i] = (DevicePreference**)malloc(maxDevices * sizeof(DevicePreference*));
        for (int j = 0; j < maxDevices; j++) {
            (*matrix)[i][j] = (DevicePreference*)malloc(sizeof(DevicePreference));
            strcpy((*matrix)[i][j]->resolution, "1080p");
            (*matrix)[i][j]->playbackPosition = 0;
            (*matrix)[i][j]->bandwidthUsage = 0.0;
        }
    }
}

void initializeContentMetadataMatrix(ContentMetadata*** matrix, int numCategories, int numContents) {
    *matrix = (ContentMetadata**)malloc(numCategories * sizeof(ContentMetadata*));
    for (int i = 0; i < numCategories; i++) {
        (*matrix)[i] = (ContentMetadata*)malloc(numContents * sizeof(ContentMetadata));
        for (int j = 0; j < numContents; j++) {
            strcpy((*matrix)[i][j].title, "Unknown");
            (*matrix)[i][j].rating = 0.0;
            (*matrix)[i][j].runtime = 0;
            strcpy((*matrix)[i][j].encodingFormat, "Unknown");
        }
    }
}

void updateEngagementScore(float** matrix, int userIndex, int categoryIndex, float newScore) {
    matrix[userIndex][categoryIndex] = newScore;
}

void updateDevicePreference(DevicePreference* device, const char* resolution, int playbackPosition, float bandwidthUsage) {
    strcpy(device->resolution, resolution);
    device->playbackPosition = playbackPosition;
    device->bandwidthUsage = bandwidthUsage;
}

void updateContentMetadata(ContentMetadata* content, const char* title, float rating, int runtime, const char* format) {
    strcpy(content->title, title);
    content->rating = rating;
    content->runtime = runtime;
    strcpy(content->encodingFormat, format);
}

void displayEngagementMatrix(float** matrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        printf("User %d Engagement Scores: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayDevicePreferences(DevicePreference*** matrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        printf("User %d Device Preferences:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("  Device %d: Resolution: %s, Playback Position: %d, Bandwidth: %.2f Mbps\n",
                   j + 1, matrix[i][j]->resolution, matrix[i][j]->playbackPosition, matrix[i][j]->bandwidthUsage);
        }
    }
}

void displayContentMetadataMatrix(ContentMetadata** matrix, int numCategories, int numContents) {
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d Contents:\n", i + 1);
        for (int j = 0; j < numContents; j++) {
            printf("  Title: %s, Rating: %.1f, Runtime: %d mins, Format: %s\n",
                   matrix[i][j].title, matrix[i][j].rating, matrix[i][j].runtime, matrix[i][j].encodingFormat);
        }
    }
}

void freeEngagementMatrix(float** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void freeDeviceMatrix(DevicePreference*** matrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMetadataMatrix(ContentMetadata** matrix, int numCategories) {
    for (int i = 0; i < numCategories; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numUsers = 2, numCategories = 3, maxDevices = 2, numContents = 2;

    float** engagementMatrix;
    initializeEngagementMatrix(&engagementMatrix, numUsers, numCategories);

    DevicePreference*** deviceMatrix;
    initializeDeviceMatrix(&deviceMatrix, numUsers, maxDevices);

    ContentMetadata** contentMatrix;
    initializeContentMetadataMatrix(&contentMatrix, numCategories, numContents);

    updateEngagementScore(engagementMatrix, 0, 1, 4.5);
    updateDevicePreference(deviceMatrix[0][0], "4K", 1200, 5.2);
    updateContentMetadata(&contentMatrix[1][0], "Action Movie", 8.9, 120, "HDR");

    printf("Engagement Matrix:\n");
    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);

    printf("\nDevice Preferences:\n");
    displayDevicePreferences(deviceMatrix, numUsers, maxDevices);

    printf("\nContent Metadata:\n");
    displayContentMetadataMatrix(contentMatrix, numCategories, numContents);

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, maxDevices);
    freeContentMetadataMatrix(contentMatrix, numCategories);

    return 0;
}
