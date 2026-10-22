/* Thomas Green
   10/16/2026
   CS 210 Programming Languages
   Project Three .h file
   */

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

using namespace std;

class ItemTracker {
private:
	map<string, int> itemCount;

	// Helper method to standardize capilalization to Title Case
	string formatName(string itemName) const;

public:
	// Constructor that initializes the itemCount map and generates count.dat file
	ItemTracker(const string& inputFileName);

	// Core file operations
	void loadDataFromFile(const string& filename);
	void backupDataToFile(const string& filename) const;

	// Reporting and display operations
	void displayItemCount(const string& origItemName) const;
	void displayAllItems() const;
	void displayHistogram() const;
};

#endif // ITEMTRACKER_H
