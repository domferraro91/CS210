// Domenic Ferraro
// CS-210 Project 3
// April 13, 2026

//This is the header file for GroceryList.

#pragma once
#include <string>
#include <vector>
#include "GroceryItem.h"

class GroceryList {
private:
	std::vector<GroceryItem> groceryList;

public:
	GroceryList();

	void loadList();
	void findItem(const std::string description);
	void printList() const;
	void printHist() const;
};