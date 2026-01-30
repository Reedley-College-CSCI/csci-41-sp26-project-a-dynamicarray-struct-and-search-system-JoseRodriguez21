#include <iostream>
#include <string>
using namespace std;

struct Products {
    string productName;
    int itemsStock;
    double price;
    string category;
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