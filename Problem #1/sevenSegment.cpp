#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void writeNumber(int n, string& line1, string& line2, string& line3) {
    // this function is used to write one number (n) to each line (line1, line2, and line3)

    // note that if n is -1, it means our input is invalid, so we write blank space instead
    if (n == -1) {
        line1 += "    ";
        line2 += "    ";
        line3 += " __ ";
    }
    else if (n == 0) {
        line1 += " __ ";
        line2 += "|  |";
        line3 += "|__|";
    }
    else if (n == 1) {
        line1 += "    ";
        line2 += "   |";
        line3 += "   |";
    }
    else if (n == 2) {
        line1 += " __ ";
        line2 += " __|";
        line3 += "|__ ";
    }
    else if (n == 3) {
        line1 += " __ ";
        line2 += " __|";
        line3 += " __|";
    }
    else if (n == 4) {
        line1 += "    ";
        line2 += "|__|";
        line3 += "   |";
    }
    else if (n == 5) {
        line1 += " __ ";
        line2 += "|__ ";
        line3 += " __|";
    }
    else if (n == 6) {
        line1 += " __ ";
        line2 += "|__ ";
        line3 += "|__|";
    }
    else if (n == 7) {
        line1 += " __ ";
        line2 += "   |";
        line3 += "   |";
    }
    else if (n == 8) {
        line1 += " __ ";
        line2 += "|__|";
        line3 += "|__|";
    }
    else if (n == 9) {
        line1 += " __ ";
        line2 += "|__|";
        line3 += " __|";
    }
}

void writeScreen(int hi, int mi, int si) {
    // h1 and h2 are each digit of hi. h1 is the first digit, h2 is the second digit
    // m1 and m2 are each digit of mi. m1 is the first digit, m2 is the second digit
    // s1 and s2 are each digit of si. s1 is the first digit, s2 is the second digit
    int h1, h2, m1, m2, s1, s2;

    // If minutes or seconds is greater than or equal to 60, it is an invalid input. 
    // Here, I represent an invalid input with -1
    if (mi >= 60 || si >= 60) {
        h1 = -1;
        h2 = -1;
        m1 = -1;
        m2 = -1;
        s1 = -1;
        s2 = -1;
    }
    else {
        // If an input is valid, we will then get each digit from hi, mi, si
        h1 = hi / 10;
        h2 = hi % 10;
        m1 = mi / 10;
        m2 = mi % 10;
        s1 = si / 10;
        s2 = si % 10;
    }

    // We need three lines to write a seven segment number to a console screen. We call each line line1, line2, and line3
    string line1 = "", line2 = "", line3 = "";

    // a function writeNumber is used to write each number to each line seperately
    writeNumber(h1, line1, line2, line3);
    line1 += " ";
    line2 += " ";
    line3 += " ";
    writeNumber(h2, line1, line2, line3);
    line1 += "   ";
    line2 += " . ";
    line3 += " . ";
    writeNumber(m1, line1, line2, line3);
    line1 += " ";
    line2 += " ";
    line3 += " ";
    writeNumber(m2, line1, line2, line3);
    line1 += "   ";
    line2 += " . ";
    line3 += " . ";
    writeNumber(s1, line1, line2, line3);
    line1 += " ";
    line2 += " ";
    line3 += " ";
    writeNumber(s2, line1, line2, line3);

    // when we finished populating every line with each number, we then print all those lines to the console screen
    cout << line1 << "\n";
    cout << line2 << "\n";
    cout << line3 << "\n";
}

int main()
{
    cout << "Input: ";
    // accept input as a string
    string time;
    cin >> time;

    // get substring of hours, minutes, and seconds
    string h = time.substr(0, 2);
    string m = time.substr(3, 2);
    string s = time.substr(6);

    // turn string of hours into int (called hi)
    stringstream hs(h);
    int hi;
    hs >> hi;

    // turn string of minutes into int (called mi)
    stringstream ms(m);
    int mi;
    ms >> mi;

    // turn string of seconds into int (called si)
    stringstream ss(s);
    int si;
    ss >> si;

    // this function is used to write a seven segment number to a console screen
    writeScreen(hi, mi, si);

    system("pause");
}

