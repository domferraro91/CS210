// Domenic Ferraro
// CS-210 Project 3
// April 13, 2026

//This is the header file for GroceryItem.
#pragma once

#include <string>

class GroceryItem {
private:
	std::string name;
	int quantity;

public:
	GroceryItem(const std::string& itemName, int itemQuantity);
	
	std::string getName() const;
	int getQuantity() const;
};