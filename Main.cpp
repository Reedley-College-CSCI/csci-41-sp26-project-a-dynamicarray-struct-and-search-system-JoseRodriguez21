#include <iostream>
#include <string>
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
};

int main() {
    string userName;


    cout << "Enter your name: " << endl;
    getline(cin, userName);

    cout << "Welcome " << userName << " to your storage system." << endl;

}