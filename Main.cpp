#include <iostream>
#include <string>
using namespace std;

struct Products {
    string productName;
    int itemsStock;
    double price;
    string category;
};

int main() {
    string userName;

    cout << "Enter your name: " << endl;
    getline(cin, userName);

    cout << "Welcome " << userName << " to your storage system." << endl;

}