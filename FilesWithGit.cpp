#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Jacket {
    string fabric, brand;
    double price;
};

struct Jacket* input_jackets(struct Jacket* p)
{
    int i;
    for (i = 0; i < 5; i++) {
        cin.ignore();
        cout << "Jacket " << i + 1 << " Brand:\t";
        getline(cin, (p + i)->brand);
        cout << "Jacket " << i + 1 << " Fabric:\t";
        getline(cin, (p + i)->fabric);
        cout << "Jacket " << i + 1 << " Price:\t";
        cin >> (p+i)->price;
    }

    return p;
}

void write_jackets(struct Jacket* p)
{
    int i;

    //declaring ofstream and opening file for writing
    ofstream myFile;
    myFile.open("jacket.txt", ios::out);

    //loop writing to file
    for (i = 0; i < 5; i++) {
        myFile << (p + i)->brand << endl;
        myFile << (p + i)->fabric << endl;
        myFile << (p + i)->price << endl;
    }

    //closing file
    myFile.close();
}

int main()
{
    //Declaring struct array & pointer
    struct Jacket jackets[5];
    struct Jacket* ptr = jackets;

    //taking user input function
    input_jackets(ptr);

    //writing input to file function
    write_jackets(ptr);
}