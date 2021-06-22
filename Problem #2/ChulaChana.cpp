#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<string> placeName = { "Mahamakut Building", "Sara Phra Keaw", "CU Sport Complex", "Sanam Juub", "Samyarn Mitr Town"};

vector<set<string>> peopleData(5);

void removeUser(string phone) {
    for (int i = 0; i < 5; i++) {
        peopleData[i].erase(phone);
    }
}

void checkIn() {
    cout << "Check in\n";
    cout << "Enter phone number: ";
    string phone;
    cin >> phone;
    for (int i = 0; i < 5; i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << "\n";
    }
    cout << "Select the place: ";
    int place;
    cin >> place;

    removeUser(phone);
    peopleData[place - 1].insert(phone);

    cout << "Checking in " << phone << " into " << placeName[place - 1] << "\n";
    cout << "-----------------------------------------------------------------\n";
}

void checkOut() {
    cout << "Check out\n";
    cout << "Enter phone number: ";
    string phone;
    cin >> phone;
    removeUser(phone);
    cout << "Checking out " << phone << "\n";
    cout << "-----------------------------------------------------------------\n";
}

void printPeopleCount() {
    cout << "Current Population\n";
    for (int i = 0; i < 5; i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << ": " << peopleData[i].size() << "\n";
    }
    cout << "-----------------------------------------------------------------\n";
}

void executeCommand(int command) {
    if (command == 1) {
        checkIn();
    }
    else if (command == 2) { 
        checkOut();
    }
    else if (command == 3) {
        printPeopleCount();
    }
    else {
        cout << "Invalid command\n";
        cout << "-----------------------------------------------------------------\n";
    }
}

int main()
{
    while (true) {
        cout << "Welcome to Chula Chana!!!\n";
        cout << "Available commands:\n";
        cout << "  1. Check in user\n";
        cout << "  2. Check out user\n";
        cout << "  3. Print people count\n";
        cout << "Please input any number: ";
        int command;
        cin >> command;
        cout << "-----------------------------------------------------------------\n";

        executeCommand(command);

    }  
}
