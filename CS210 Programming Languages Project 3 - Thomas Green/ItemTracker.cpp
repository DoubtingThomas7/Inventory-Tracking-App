/* Thomas Green
   10/16/2026
   CS210 Programming Languages
   Project Three
   */

#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Formats input strings so lookups are case insensitive and consistent
string ItemTracker::formatName(string itemName) const {
	int i;

	if (itemName.empty()) {
		return ""; // Return an empty string if the input is empty
	}
	
	// Convert the first character to uppercase and the rest to lowercase
	itemName[0] = toupper(itemName[0]);
	for (i = 1; i < itemName.length(); ++i) {
		itemName[i] = tolower(itemName[i]);
	}
	return itemName;
}

// Constructor that loads records and creates a backup file
ItemTracker::ItemTracker(const string& inputFileName) {
	loadDataFromFile(inputFileName);
	backupDataToFile("count.dat");
}

// Reads daily transaction records and updates the count
void ItemTracker::loadDataFromFile(const string& filename) {
	
	ifstream inputFile;
	string item;

	inputFile.open(filename);

	if (!inputFile.is_open()) {
		cout << "Error: Could not open file " << filename << endl;
		return;
	}

	while (inputFile >> item) {
		
		item = formatName(item);

		if (itemCount.count(item) == 0) {
			itemCount.emplace(item, 1);
		}

		else {
			itemCount.at(item) = itemCount.at(item) + 1;
		}
	}

	inputFile.close();
}

// Writes the current item counts to Count.dat
void ItemTracker::backupDataToFile(const string& filename) const {

	ofstream outputFile;
	map<string, int>::const_iterator it;

	outputFile.open(filename);

	if (!outputFile.is_open()) {
		cout << "Warning: Could not create backup file: " << filename << endl;
		return;
	}

	for (it = itemCount.begin(); it != itemCount.end(); ++it) {
		outputFile << it->first << " " << it->second << "\n";
	}

	outputFile.close();
}

// Menu Option 1: Looks up count
void ItemTracker::displayItemCount(const string& origItemName) const {
	string formattedName;
	int count;

	formattedName = formatName(origItemName);

	// Verify if the item exists in the map and display the count
	if (itemCount.count(formattedName) > 0) {
		count = itemCount.at(formattedName);
		cout << "\n--> " << formattedName << " was purchased " << count << " time(s)." << endl;
	}

	else {
		cout << "\n--> " << formattedName << " was not purchased today." << endl;
	}
}

// Menu Option 2: Prints items and their counts
void ItemTracker::displayAllItems() const {
	map<string, int>::const_iterator it;

	cout << "\n" << string(34, '-') << "\n";
	cout << left << setw(20) << "Item Name" << "Count\n";
	cout << string(34, '-') << "\n";

	for (it = itemCount.begin(); it != itemCount.end(); ++it) {
		cout << left << setw(20) << it->first << it->second << "\n";
	}

	cout << string(34, '-') << "\n";
}

// Menu Option 3: Prints histogram of item counts
void ItemTracker::displayHistogram() const {
	map<string, int>::const_iterator it;
	string histogram;

	cout << "\n" << string(48, '-') << "\n";
	cout << left << setw(18) << "Item Name" << "Purchase Count (Histogram)\n";
	cout << string(48, '-') << "\n";

	for (it = itemCount.begin(); it != itemCount.end(); ++it) {
		histogram = string(it->second, '*');
		cout << left << setw(18) << it->first << histogram << " (" << it->second << ")\n";
	}

	cout << string(48, '-') << "\n";
}