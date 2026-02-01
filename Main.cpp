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
    public:
    Inventory() {
        count = 0;
    }

    void loadData(const string& filename);

    
};

int main() {
    string userName;
    int productCount = 0;
    Inventory store;

    store.loadData("Storage.txt");
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
}