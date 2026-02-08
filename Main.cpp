#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

struct Products {
    string productName;
    int itemStock;
    double price;
    string category;

    Products() {
        productName = "";
        itemStock = 0;
        price = 0.0;
        category = "";
    }
};

class Inventory {
    private:
        Products product[30];
        int count;
        bool compareCase(const string& product1, const string& product2) const;
        void bubbleSort();
        void displayMenu();
        
    public:
    Inventory() {
        count = 0;
    }

    void loadData(const string& filename);
    void updateData(const string& filename);
    void sortByName();
    void printProducts() const;
    void selectOption();
    void addProduct();
    void deleteProduct(const string& targetProduct);
    int searchProduct(const string& targetProduct);
};

int main() {
    string userName;
    int productCount = 0;
    Inventory store;
    

    store.loadData("Storage.txt");
    store.sortByName();

    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "\nWelcome " << userName << " to your storage system." << endl;
    store.selectOption();
    store.updateData("Storage.txt");

}

void Inventory::loadData(const string& filename) {
    ifstream storageFile(filename);

    if (!storageFile) {
        cout << "Error opening Storage.txt." << endl;
        return;
    }

    count = 0;
    string line;

    while(getline(storageFile, line) && count < 30) {
        stringstream ss(line);
        string words[20];
        int wordCount = 0;
        string word;

        while (ss >> word && wordCount < 20) {
            words[wordCount] = word;
            wordCount++;
        }
        
        if (wordCount < 4) continue;

        int stock = stoi(words[wordCount - 3]);
        double price = stod(words[wordCount - 2]);
        string category = words[wordCount - 1];

        string name = words[0];
        for (int i = 1; i < wordCount - 3; i++) {
            name += " " + words[i]; 
        }

        product[count].productName = name;
        product[count].itemStock = stock;
        product[count].price = price;
        product[count].category = category;

        count++;
    }

    storageFile.close();

    cout << "Loaded " << count << " products." << endl;
}

void Inventory::printProducts() const {
    cout << "\nPRODUCT LIST:\n";
    for (int i = 0; i < count; i++) {
        cout << product[i].productName << " | "
             << product[i].itemStock << " | "
             << product[i].price << " | "
             << product[i].category << endl;
    }
}

bool Inventory::compareCase(const string& product1, const string& product2) const {
    int n;
    if (product1.length() < product2.length()) {
        n = product1.length();
    }
    else {
        n = product2.length();
    }
    for (int i = 0; i < n; i++) {
        char char1 = tolower(product1[i]);
        char char2 = tolower(product2[i]);
        if (char1 < char2) return true;
        if (char1 > char2) return false;
    }
    return product1.length() < product2.length();
}

void Inventory::sortByName() {
    bubbleSort();
}

void Inventory::bubbleSort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (!compareCase(product[j].productName, product[j + 1].productName)) {
                Products temp = product[j];
                product[j] = product[j + 1];
                product[j + 1] = temp;
            }
        }
    }
}

void Inventory::displayMenu() {
    cout << "\n         Storage         " << endl;
    cout << "-------------------------" << endl;
    cout << "1 - Add Product          " << endl;
    cout << "2 - Delete Product       " << endl;
    cout << "3 - Display all Products " << endl;
    cout << "4 - Search for a Product " << endl;
    cout << "-99 - Exit the program   " << endl;
    cout << "-------------------------" << endl;
    cout << "Enter a choice: ";

}

void Inventory::addProduct() {
    if (count == 30) {
        cout << "\n Storage has reach it's max capacity." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter product name: ";
    getline(cin, product[count].productName);

    cout << "Enter stock quantity: ";
    while(!(cin >> product[count].itemStock)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter an integer: ";
    }

    cout << "Enter price: ";
    while (!(cin >> product[count].price)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a number: ";
    }

    cout << "Enter a category: ";
    cin.ignore();
    getline(cin, product[count].category);

    count++;
    cout << "Product added succesfully.";
    sortByName();
}

void Inventory::deleteProduct(const string& targetProduct) {
    int index = searchProduct(targetProduct);

    if (index == -1) {
        cout << targetProduct << " not found." << endl;
        return;
    }

    for (int i = index; i < count - 1; i++) {
        product[i] = product[i + 1];
    }
    
    product[count - 1] = Products();

    count--;
    cout << targetProduct << " has been deleted." << endl;
}

int Inventory::searchProduct(const string& targetProduct) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (!compareCase(product[mid].productName, targetProduct) &&
           (!compareCase(targetProduct, product[mid].productName))) {
            return mid;
        }
        else if (compareCase(product[mid].productName, targetProduct)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void Inventory::selectOption() {
    int userChoice;
    while(true) {
        displayMenu();
        while (!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Invalid input. Enter a number from the menu:" << endl;
            continue;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice == -99) {
            break;
        }
        switch (userChoice) {
            case 1: addProduct(); 
                    break;
            case 2: {
                      string productName;

                      cout << "Enter product name to delete: ";
                      getline(cin, productName);

                      deleteProduct(productName);
                      break;
                    } 
            case 3: printProducts(); 
                    break;
            case 4: {
                      string productName;

                      cout << "\nEnter product name to search: ";
                      getline(cin, productName);

                      int index = searchProduct(productName);

                      if (index == -1) {
                          cout << productName << " not found." << endl;
                      }
                      else {
                          cout << productName << "Found: " << endl;
                          cout << product[index].productName << " | ";
                          cout << product[index].itemStock << " | ";
                          cout << product[index].price << " | ";
                          cout << product[index].category << " | \n"; 
                      }

                      break;
                   }
            default: cout << "\n Invalid option." << endl; break;
        }
    }
}

void Inventory::updateData(const string& filename) {
    ofstream storageFile(filename);

    if (!storageFile) {
        cout << "Error opening " << filename << " for uploading" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        storageFile << product[i].productName << " "
                    << product[i].itemStock << " "
                    << product[i].price << " "
                    << product[i].category << endl;
    }

    storageFile.close();
    cout << "Data saved to " << filename << " successfully." << endl;
}