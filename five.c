#include <stdio.h>
#include <string.h>

#define MAX_SEATS 50

// Structure to represent a passenger
struct Passenger {
    char name[50];
    int seat_number;
    int is_reserved;
};

// Function to initialize the passenger array
void initialize(struct Passenger passengers[]) {
    for (int i = 0; i < MAX_SEATS; i++) {
        passengers[i].is_reserved = 0; // Initially, all seats are available
    }
}

// Function to book a ticket
void bookTicket(struct Passenger passengers[]) {
    int seat;
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (passengers[seat - 1].is_reserved) {
        printf("Seat %d is already reserved.\n", seat);
    } else {
        strcpy(passengers[seat - 1].name, name);
        passengers[seat - 1].seat_number = seat;
        passengers[seat - 1].is_reserved = 1;
        printf("Ticket booked successfully.\n");
    }
}

// Function to cancel a ticket
void cancelTicket(struct Passenger passengers[]) {
    int seat;
    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    scanf("%d", &seat);

    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }

    if (passengers[seat - 1].is_reserved) {
        passengers[seat - 1].is_reserved = 0;
        printf("Ticket for seat %d is canceled.\n", seat);
    } else {
        printf("Seat %d is not reserved.\n", seat);
    }
}

// Function to display the current seat status
void displayStatus(struct Passenger passengers[]) {
    printf("Seat Status:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (passengers[i].is_reserved) {
            printf("Seat %d: Reserved for %s\n", passengers[i].seat_number, passengers[i].name);
        } else {
            printf("Seat %d: Available\n", i + 1);
        }
    }
}

int main() {
    struct Passenger passengers[MAX_SEATS];
    initialize(passengers);

    int choice;
    while (1) {
        printf("\nRailway Reservation System\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Seat Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket(passengers);
                break;
            case 2:
                cancelTicket(passengers);
                break;
            case 3:
                displayStatus(passengers);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

