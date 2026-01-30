#include <iostream>
#include <string>
using namespace std;

int main() {
    string userName;

    cout << "Enter your name: " << endl;
    getline(cin, userName);

    cout << "Welcome " << userName << " to your storage system." << endl;

}