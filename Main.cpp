#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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

    public:
    Inventory() {
        count = 0;
    }

    void loadData(const string& filename);
    void sortByName();

    
};

int main() {
    string userName;
    int productCount = 0;
    Inventory store;

    store.loadData("Storage.txt");
    store.sortByName();

    cout << "Enter your name: " << endl;
    getline(cin, userName);

    cout << "Welcome " << userName << " to your storage system." << endl;

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