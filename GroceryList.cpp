// Domenic Ferraro
// CS-210 Project 3
// April 13, 2026

// This is the GroceryList function definitions file.

#include "GroceryList.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <cctype>

using namespace std;

// Function to re-capitalize the first letter of each item when printed for a neater look.
// Was neccessary after being able to search for an item without letter case mattering.
string capitalize(const string& str) {
	if (str.empty()) return str;

	string result = str;

	transform(result.begin(), result.end(), result.begin(), ::tolower);

	result[0] = toupper(result[0]);

	return result;
}

GroceryList::GroceryList() {}

// Function to load the provided txt on program start-up, transform the case to lower for easier searching,
// and use a map to put both the item and its quantity into the groceryList vector. It also stores the info in frequency.dat.
void GroceryList::loadList() {
	groceryList.clear();
	ifstream file("CS210_Project_Three_Input_File.txt");
	string item;
	map<string, int> counts;

	// If file doesn't exist or doesn't open correctly.
	if (!file) {
		cout << "File empty or not found." << endl;
		return;
	}

	// While intaking the names of the items in the file, transform its case to lower,
	// and then count each item.
	while (file >> item) {
		transform(item.begin(), item.end(), item.begin(), ::tolower);
		counts[item]++;
	}

	file.close();

	// Puts each item and its quantity into the vector.
	for (const auto& [name, count] : counts) {
		groceryList.push_back({ name, count });
	}

	// Puts new grocery list with item and quantity into frequency.dat
	ofstream outFile("frequency.dat");

	if (!outFile) {
		cout << "Error opening file for saving." << endl;
		return;
	}

	for (int i = 0; i < groceryList.size(); i++) {
		outFile << groceryList[i].getName() 
			    << ": " 
				<< groceryList[i].getQuantity() 
				<< endl;
	}
	outFile.close();
}

// Function to find an item in the vector by using its name.
void GroceryList::findItem(string description) {

	// Transforms user input to all lower case for easier search results.
	transform(description.begin(), description.end(), description.begin(), ::tolower);

	for (const auto& item : groceryList) {
		
		// If item matches user input, print item name and its quantity.
		if (item.getName() == description) {
			cout << capitalize(item.getName()) << ": " << item.getQuantity() << endl;
			return;
		}
	}

	// If item is not found.
	cout << "Item not found.\n";
}

// Function to print the whole list of items and their quantities provided.
void GroceryList::printList() const{
	for (const auto& entry : groceryList) {
		cout << capitalize(entry.getName()) << ": " << entry.getQuantity() << endl;
	}
}

// Function to print a histogram of the items in the list provided.
void GroceryList::printHist() const {
	char ast = '*';

	// This loop aligns the text and asterisks for a cleaner and easier to read look.
	for (const auto& entry : groceryList) {
		cout << right << setw(15) << capitalize(entry.getName()) << ": ";
		for (int i = 0; i < entry.getQuantity(); i++) {
			cout << ast; 
		}
		cout << endl;
	}
}