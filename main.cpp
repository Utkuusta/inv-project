#include <stdio.h>
#include <cstdlib>  // For the system function
#include "wpa_wifi.h"
#include <iostream>
#include <limits> // for numeric_limits

int main() {
    int choice;

    do {
        // Display menu
        std::cout << "Select an option:\n";
        std::cout << "1. Set Wifi Network\n";
        std::cout << "2. Remove Wifi Network\n";
        std::cout << "3. Option 3\n";
        std::cout << "0. Exit\n";

        // Get user input
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice) || choice < 0 || choice > 3) {
            std::cout << "Invalid input. Please enter a valid choice: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Process user choice
        switch (choice) {
            case 1:
                std::cout << "Searching Nearby Networks.\n";
                // Perform actions for Option 1
                scanresults();
                setnetwork();
                break;
            case 2:
                std::cout << "Removing Network.\n";
                // Perform actions for Option 2
                removenetwork();
                break;
            case 3:
                std::cout << "You selected Option 3.\n";
                // Perform actions for Option 3
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
