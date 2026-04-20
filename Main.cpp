// Domenic Ferraro
// CS-210 Project 3
// April 13, 2026

// This project opens a provided list of grocery items and their quantities sold.
// It allows the user to search for individual items and see how many of that item sold.
// It also shows the entire list of items including their quantities, as well as
// showing a histogram to easily compare the best sellers.

#include "GroceryList.h"
#include <limits>
#include <iostream>

using namespace std;

// Function to for input validation.
int getValidInt(string prompt, int min, int max) {
    int value;

    // Loop until valid input is received
    while (true) {
        cout << prompt;
        cin >> value;

        // Check for input failure (non-integer input)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }
        // Check for non-positive integers
        if (value < min || value > max) {
            cout << "Value must be " << min << " to " << max << "." << endl;
            continue;
        }

        return value;
    }
}

int main() {
	GroceryList list;
	int userInput;
	string desc;
    bool running = true;

    // Opens provided txt file and maps it out into the groceryList vector.
	list.loadList();


    // Main program.
    while (running) {
		cout << "\n=====================MENU=====================\n"
             << "1. Enter grocery item to search" << endl
			 << "2. Print list of all items and quantities" << endl
			 << "3. Print histogram of all items and quantities" << endl
			 << "4. Exit program" << endl;

        userInput = getValidInt("Please enter your choice.\n", 1, 4);

        switch (userInput) {

        case 1:
            cout << "Enter Item: ";
            cin >> desc;
            list.findItem(desc);
            break;

        case 2:
            list.printList();
            break;

        case 3:
            list.printHist();
            break;

        case 4:
            running = false;
            return 0;

        default:
            cout << "Invalid input." << endl;
            break;
        }
	}
    return 0;
}