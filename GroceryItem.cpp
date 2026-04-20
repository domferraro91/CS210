// Domenic Ferraro
// CS-210 Project 3
// April 13, 2026

// This is the GroceryItem functions definitions file.

#include "GroceryItem.h"

using namespace std;

// Constructor.
GroceryItem::GroceryItem(const string& itemName, int itemQuantity) {
	name = itemName;
	quantity = itemQuantity;
}


int GroceryItem::getQuantity() const {
	return quantity;
}

string GroceryItem::getName() const {
	return name;
}