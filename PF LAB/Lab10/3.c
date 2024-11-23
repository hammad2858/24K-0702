#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 5


typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
} Flight;


void displayFlightDetails(Flight flights[], int count);
void displayAvailableFlights(Flight flights[], int count);
void bookSeat(Flight flights[], int count);

int main() {

    Flight flights[MAX_FLIGHTS] = {
        {101, "Karachi", "Lahore", "2024-12-15", 10},
        {102, "Peshawar", "Dal Badin", "2024-12-16", 15},
        {103, "Islamabad", "Lahore", "2024-12-18", 8},
        {105, "Skardu", "Karachi", "2024-12-19", 12}
    };

    int choice;

    do {
        
        printf("\nFlight Management System\n");
        printf("1. Display All Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlightDetails(flights, MAX_FLIGHTS);
                break;
            case 2:
                displayAvailableFlights(flights, MAX_FLIGHTS);
                bookSeat(flights, MAX_FLIGHTS);
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

// Func to display all flight details
void displayFlightDetails(Flight flights[], int count) {
    printf("\nAll Flight Details:\n");
    for (int i = 0; i < count; i++) {
        printf("\nFlight Number: %d\n", flights[i].flightNumber);
        printf("Departure City: %s\n", flights[i].departureCity);
        printf("Destination City: %s\n", flights[i].destinationCity);
        printf("Date: %s\n", flights[i].date);
        printf("Available Seats: %d\n", flights[i].availableSeats);
    }
}

// Func to display only flights with available seats
void displayAvailableFlights(Flight flights[], int count) {
    printf("\nAvailable Flights:\n");
    for (int i = 0; i < count; i++) {
        if (flights[i].availableSeats > 0) {
            printf("\nFlight Number: %d\n", flights[i].flightNumber);
            printf("Departure City: %s\n", flights[i].departureCity);
            printf("Destination City: %s\n", flights[i].destinationCity);
            printf("Date: %s\n", flights[i].date);
            printf("Available Seats: %d\n", flights[i].availableSeats);
        }
    }
}

// Func for booking 
void bookSeat(Flight flights[], int count) {
    int flightNumber;
    printf("\nEnter the flight number to book a seat: ");
    scanf("%d", &flightNumber);

    // Find the flight by flight number
    for (int i = 0; i < count; i++) {
        if (flights[i].flightNumber == flightNumber) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat successfully booked on Flight %d!\n", flightNumber);
                printf("Remaining Seats: %d\n", flights[i].availableSeats);
            } else {
                printf("No seats available on Flight %d.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight number %d not found!\n", flightNumber);
}
