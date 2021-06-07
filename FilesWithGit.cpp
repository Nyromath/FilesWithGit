#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Jacket {
    string brand, fabric, colour, size, price;
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
        cout << "Jacket " << i + 1 << " Colour:\t";
        getline(cin, (p + i)->colour);
        cout << "Jacket " << i + 1 << " Size:\t";
        getline(cin, (p + i)->size);
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
        myFile << (p + i)->colour << endl;
        myFile << (p + i)->size << endl;
        myFile << (p + i)->price << endl;
    }

    //closing file
    myFile.close();
}

struct Jacket* output_jackets(struct Jacket* p)
{
    int i = 0;

    //declaring ifstream and opening file for reading
    ifstream myFile;
    myFile.open("jacket.txt", ios::in);

    //reading file into structure array
    string item;
    for (i = 0; i < 5; i++) {
        getline(myFile, item);
        (p + i)->brand = item;
        getline(myFile, item);
        (p + i)->fabric = item;
        getline(myFile, item);
        (p + i)->colour = item;
        getline(myFile, item);
        (p + i)->size = item;
        getline(myFile, item);
        (p + i)->price = "$" + item;
    }

    //closing file
    myFile.close();

    //outputting data
    for (int i = 0; i < 5; i++) {
        cout << "Jacket " << i + 1 << ":\t";
        cout << (p + i)->brand << ", ";
        cout << (p + i)->fabric << ", ";
        cout << (p + i)->colour << ", ";
        cout << (p + i)->size << ", ";
        cout << (p + i)->price << endl;
    }

    return p;
}

void search_by_size(struct Jacket* p)
{
    //defining search variable
    string search;
    int i, found = 0;

    //taking input for search term
    cout << "\nEnter the size you want:\t";
    cin >> search;

    //searching for size
    for (i = 0; i < 5; i++) {
        if ((p + i)->size == search) {
            found++;
        }
    }

    //outputting results
    cout << "\nWe have " << found << " Jackets of size " << search << " in stock.";
}

int main()
{
    //Declaring struct array & pointer
    struct Jacket jackets[5];
    struct Jacket* ptr = jackets;

    /* MEMBER2 INPUT STUFF
    //taking user input function
    input_jackets(ptr);

    //writing input to file function
    write_jackets(ptr);
    */

    //MEMBER1 OUTPUT STUFF
    
    //reading from file
    output_jackets(ptr);

    //search function
    search_by_size(ptr);

    return 0;
}