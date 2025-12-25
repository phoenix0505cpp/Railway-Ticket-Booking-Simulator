#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Structure to store passenger details
struct Passenger {
    int id;
    string name;
};

// Maximum seats available
const int MAX_SEATS = 3;

// Data structures
vector<Passenger> booked;        // Confirmed passengers
queue<Passenger> waitingList;    // Waiting list
int nextId = 1;

// Function to book a ticket
void bookTicket() {
    Passenger p;
    p.id = nextId++;

    cout << "\nEnter Passenger Name: ";
    cin.ignore();
    getline(cin, p.name);

    if (booked.size() < MAX_SEATS) {
        booked.push_back(p);
        cout << "Ticket Confirmed! Seat allocated.\n";
    } else {
        waitingList.push(p);
        cout << "Seats full! Added to waiting list.\n";
    }
}

// Function to cancel a ticket
void cancelTicket() {
    int id;
    cout << "\nEnter Passenger ID to cancel ticket: ";
    cin >> id;

    for (int i = 0; i < booked.size(); i++) {
        if (booked[i].id == id) {
            cout << "Ticket cancelled for " << booked[i].name << ".\n";
            booked.erase(booked.begin() + i);

            // Move passenger from waiting list to booked
            if (!waitingList.empty()) {
                Passenger p = waitingList.front();
                waitingList.pop();
                booked.push_back(p);
                cout << "Waiting list passenger " << p.name 
                     << " got confirmed seat.\n";
            }
            return;
        }
    }
    cout << "Passenger ID not found.\n";
}

// Function to display booked passengers
void displayBooked() {
    if (booked.empty()) {
        cout << "\nNo confirmed bookings.\n";
        return;
    }

    cout << "\nConfirmed Passengers:\n";
    for (auto &p : booked) {
        cout << "ID: " << p.id << " | Name: " << p.name << "\n";
    }
}

// Function to display waiting list
void displayWaitingList() {
    if (waitingList.empty()) {
        cout << "\nWaiting list is empty.\n";
        return;
    }

    queue<Passenger> temp = waitingList;
    cout << "\nWaiting List:\n";
    while (!temp.empty()) {
        Passenger p = temp.front();
        temp.pop();
        cout << "ID: " << p.id << " | Name: " << p.name << "\n";
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== Railway Ticket Booking Simulator =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Confirmed Passengers\n";
        cout << "4. View Waiting List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: displayBooked(); break;
            case 4: displayWaitingList(); break;
            case 5: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}