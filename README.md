# Project A: Dynamic Array, Struct, and Search System README

## Student Info

- **Name**: \[Jose Rodriguez\]  
- **Repository**:\[[https://github.com/Reedley-College-CSCI/csci-41-sp26-project-a-dynamicarray-struct-and-search-system-JoseRodriguez21](https://github.com/Reedley-College-CSCI/csci-41-sp26-project-a-dynamicarray-struct-and-search-system-JoseRodriguez21)\]

---

## Project Summary

Briefly describe the theme or purpose of your program.

The purpose of this program is to manage the inventory of a small store. The user can add, delete, search for, and display all products. This is done by sorting the array alphabetically with bubble sort. When searching for a product, the user enters the product name. The binary search algorithm is used to locate the desired item in the array. 

---

## Project Structure/File Overview

Provide a complete list of the files (including text files) and classes in your project, along with their purposes.

* Storage.txt: Text file to save information about the storage system.  
* main.cpp: Provides a menu interface that allows the user to interact with the inventory system and perform different actions on the Storage text file.  
* Class Inventory: This class manages the storage system by sorting the array and providing functions such as loading data, searching for a product, adding a product, etc.

---

## Requirements Checklist and Where They Are Met

Be specific. Vague statements such as “it works” or “it loads data” will not receive credit.

| Requirement | How It’s Met (What specifically happens?) | File/Class/Function |
| :---- | :---- | :---- |
| Dynamic Array | When adding a new product, the program adds it to the array and then uses the sorting system to sort it again. When deleting the program, it removes the product from the array and then sorts the array again. | void addProduct() void deleteProduct() void sortByName() |
| Read from File (≥ 20 entries) | Loads storage data from Storage.txt using a function before the program asks the user for anything. | Storage.txt and void loadData(const string& filename) |
| Struct w/ ≥ 3 elements | Struct Products has 4 elements: the product name, the number of items in stock, the product price, and the product category. | Struct Products      string productName     Int itemStock     double price     string category |
| Struct inside a Class | The Inventory class manages the Products struct, creating a dynamic array for all the data. | Class Inventory |
| Menu UI | Allow the user to add, delete, search, and quit the program | Private:     void displayMenu() |
| Update external file with changes (save on quit/modify) | Saves the products back into the Storage text file once we quit the program, typing \-99. | updateData() |
| Search Functionality Type of search What field is searched Do data need to be sorted? |  When searching for a product name using binary search, the data must be sorted. This program uses bubble sort.  | searchProduct(productName, opCount) |
|  Search Time Reporting |  Added a report of elapsed execution on case 4 when searching for a product. |  Void Inventory::selectOption() |
| Input Validation | Prevents users from typing letters when selecting an option.   | Void Inventory::selectOption() |
| Exception Handling (file I/O or invalid input) (Note: wrapping file open failure in try/catch alone is not sufficient.) | Before loading or uploading data back into the text file, the program makes sure the file is open correctly. If this doesn’t happen, the program prints a message letting the user know. | Void Inventory::updateData(const string& filename) Void Inventory::loadData(const string& filename) |

---

## How to Run

List instructions here if special input files or arguments are needed.

To run this program, you need to have both the main.cpp and Storage.txt in the same folder. Then use a code editor that has a compiler to run C++ code on your computer.

---

## One Representative Operation

## Describe, step-by-step, how ONE item is added to the dynamic array, including:

When adding a product to the dynamic array, the program first checks whether the array has capacity for another product. If the array is full, the program calls the resize function to allocate more space. Then the program asks the user for all the product details, sorts the array again, and updates the file if the user exits the program before time.  
---

## Known Issues or Planned Enhancements

Optional, but helpful if you encountered bugs or want to add more features later.

For project B, I will fix a bug that occurs when adding a product. If the user enters two numbers separately when the program asks for the number of items in stock, the code treats the first as the stock quantity and the second as the price. Which breaks the code visually, but in the program, it still saves each value in the right spot. I also plan to add a feature to edit products and see how much profit each product makes by adding the price it was bought for. 

---

## Feedback Integration (future use)

Leave this blank for now. You’ll fill it in when working on Project B.

