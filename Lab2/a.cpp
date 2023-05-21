#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    // Declare second integer, double, and String variables.
    int a;
    double b;
    string c;
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> a;
    cin >> b;
    getline(cin, c);
    // Print the sum of both integer variables on a new line.
    cout << i + a << endl;
    // Print the sum of the double variables on a new line.
    cout << b + d << endl;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s << c;
    system("pause");
    return 0;
}