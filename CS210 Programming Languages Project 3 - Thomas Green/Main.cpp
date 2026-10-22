/* Thomas Green
   10/16/2026
   CS210 Programming Languages
   Project Three Main.cpp file
   */

#include "ItemTracker.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu();
int getValidMenuChoice();

int main() {
	const string inputFileName = "Input_File.txt";
	int userInput;
	string searchItem;

	userInput = 0;
	searchItem = "";

	// Instantiates tracker (loads file and creates backup)
	ItemTracker tracker(inputFileName);

	cout << "======================================================\n";
	cout << "              CORNER GROCER ITEM TRACKER              \n";
	cout << "======================================================\n";

	while (userInput != 4) {
		displayMenu();
		userInput = getValidMenuChoice();

		switch (userInput) {
		    case 1:
				cout << "\nEnter the item's name to search: ";
				cin >> searchItem;
				tracker.displayItemCount(searchItem);
				break;

			case 2:
				tracker.displayAllItems();
				break;

			case 3:
				tracker.displayHistogram();
				break;

			case 4:
				cout << "\nExiting the program. Have a great day!\n";
				break;

			default:
				cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
				break;
		}
	}

	return 0;
}

// Displays the main menu options
void displayMenu() {
	cout << "\nPlease select an option:\n";
	cout << "1. Search for an item\n";
	cout << "2. Display all items and their counts\n";
	cout << "3. Display a histogram of item counts\n";
	cout << "4. Exit the program\n";
	cout << "Enter your choice (1-4): ";
}

// Validates user input for menu selection
int getValidMenuChoice() {
	int choice;
	string discardedInput;

	choice = 0;
	discardedInput = "";

	while (!(cin >> choice)) {
		cin.clear();
		getline(cin, discardedInput);
		cout << "Invalid input. Please enter a number between 1 and 4: ";
	}

	return choice;
}