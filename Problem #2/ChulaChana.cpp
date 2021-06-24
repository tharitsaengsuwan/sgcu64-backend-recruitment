#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

// this vector keeps all the places name
vector<string> placeName = { "Mahamakut Building", "Sara Phra Keaw", "CU Sport Complex", "Sanam Juub", "Samyarn Mitr Town"};

// this vector keeps information about users in each place
vector<set<string>> peopleData(5);

// this function remove a user with specified phone number from every place
void removeUser(string phone) {
    for (int i = 0; i < placeName.size(); i++) {
        peopleData[i].erase(phone);
    }
}

// this function take phone number as an input an checked that user in to a specified place
void checkIn() {
    cout << "Check in\n";
    cout << "Enter phone number: ";
    string phone;
    cin >> phone;
    for (int i = 0; i < placeName.size(); i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << "\n";
    }
    cout << "Select the place: ";
    int place;
    cin >> place;

    // If a specified place doesn't exist, we print out 'Invalid place'
    if (place <= 0 || place > placeName.size()) {
        cout << "Invalid place\n";
        cout << "-----------------------------------------------------------------\n";
        return;
    }

    // We check a user in by making sure they has not already checked in anywhere else first, then we can insert a user to the specified place
    removeUser(phone);
    peopleData[place - 1].insert(phone);

    cout << "Checking in " << phone << " into " << placeName[place - 1] << "\n";
    cout << "-----------------------------------------------------------------\n";
}

// this function is used to checked out the specified user
void checkOut() {
    cout << "Check out\n";
    cout << "Enter phone number: ";
    string phone;
    cin >> phone;
    removeUser(phone);
    cout << "Checking out " << phone << "\n";
    cout << "-----------------------------------------------------------------\n";
}

// this function is used to print user population onto console screen
void printPeopleCount() {
    cout << "Current Population\n";
    for (int i = 0; i < placeName.size(); i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << ": " << peopleData[i].size() << "\n";
    }
    cout << "-----------------------------------------------------------------\n";
}

// this function is used to add a new location to the list
void addLocation() {
    cout << "Add a new location\n";
    cout << "Please enter a new location name: ";
    string name;
    getline(cin >> ws, name);
    placeName.push_back(name);
    set<string> s;
    peopleData.push_back(s);
    cout << "A new location has been added\n";
    for (int i = 0; i < placeName.size(); i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << "\n";
    }
    cout << "-----------------------------------------------------------------\n";
}

// this function is used to removed the specified place from the list
void removeLocation() {
    cout << "Remove a location\n";
    for (int i = 0; i < placeName.size(); i++) {
        cout << "  " << i + 1 << ". " << placeName[i] << "\n";
    }
    cout << "Select the location you want to remove: ";
    int place;
    cin >> place;

    // If a specified place doesn't exist, we print out 'Invalid place'
    if (place <= 0 || place > placeName.size()) {
        cout << "Invalid place\n";
        cout << "-----------------------------------------------------------------\n";
        return;
    }

    cout << "Successfully removed " << placeName[place - 1] << "\n";
    placeName.erase(placeName.begin() + place - 1);
    peopleData.erase(peopleData.begin() + place - 1);
    cout << "-----------------------------------------------------------------\n";
}

// this function take a number 'command', and then decide which function to run
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
    else if (command == 4) {
        addLocation();
    }
    else if (command == 5) {
        removeLocation();
    }
    else {
        // If that command dousn't exist, we print out "Invalid command"
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
        cout << "  4. Add a new location\n";
        cout << "  5. Remove a location\n";
        cout << "Please input any number: ";
        int command;
        cin >> command;
        cout << "-----------------------------------------------------------------\n";

        executeCommand(command);

    }  
}
