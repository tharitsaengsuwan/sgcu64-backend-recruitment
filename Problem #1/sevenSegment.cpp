#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void writeNumber(int n, string& line1, string& line2, string& line3) {
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
    int h1, h2, m1, m2, s1, s2;
    if (mi >= 60 || si >= 60) {
        h1 = -1;
        h2 = -1;
        m1 = -1;
        m2 = -1;
        s1 = -1;
        s2 = -1;
    }
    else {
        h1 = hi / 10;
        h2 = hi % 10;
        m1 = mi / 10;
        m2 = mi % 10;
        s1 = si / 10;
        s2 = si % 10;
    }
    string line1 = "", line2 = "", line3 = "";
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

    cout << line1 << "\n";
    cout << line2 << "\n";
    cout << line3 << "\n";
}

int main()
{
    cout << "Input: ";
    string time;
    cin >> time;
    int pos1 = time.find(":");
    int pos2 = time.find(":", pos1 + 1);
    string h = time.substr(0, 2);
    string m = time.substr(3, 2);
    string s = time.substr(6);

    stringstream hs(h);
    int hi;
    hs >> hi;

    stringstream ms(m);
    int mi;
    ms >> mi;

    stringstream ss(s);
    int si;
    ss >> si;

    writeScreen(hi, mi, si);

    system("pause");
}
