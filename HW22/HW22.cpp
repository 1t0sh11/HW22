#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("f.txt");
    ofstream outputFile("g.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Could not open the file f.txt!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error: Could not open the file g.txt!" << endl;
        return 1;
    }

    int choice;
    cout << "Select conversion option:" << endl;
    cout << "1. First Name Middle Name Last Name" << endl;
    cout << "2. Last Name I.M." << endl;
    cout << "Your choice (1 or 2): ";
    cin >> choice;

    string surname, name, patronymic;
    while (inputFile >> surname >> name >> patronymic) {
        if (choice == 1) {
            outputFile << name << " " << patronymic << " " << surname << endl;
        }
        else if (choice == 2) {
            outputFile << surname << " " << name[0] << "." << patronymic[0] << "." << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Data successfully processed and saved to g.txt!" << endl;

    return 0;
}