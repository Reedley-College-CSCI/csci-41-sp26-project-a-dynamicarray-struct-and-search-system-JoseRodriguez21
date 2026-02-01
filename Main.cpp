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
        Products Product[30];
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
    }

    storageFile.close();
}