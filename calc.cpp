#include <iostream>
using namespace std;

int main() {
    char ch;
    float no1, no2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> ch;

    cout << "Enter two operands: ";
    cin >> no1 >> no2;

    switch (ch) {
        case '+':
            cout << no1 << " + " << no2 << " = " << no1 + no2;
            break;
        case '-':
            cout << no1 << " - " << no2 << " = " << no1 - no2;
            break;
        case '*':
            cout << no1 << " * " << no2 << " = " << no1 * no2;
            break;
        case '/':
            if (no2 != 0) {
                cout << no1 << " / " << no2 << " = " << no1 / no2;
            } else {
                cout << "Error! Division by zero is not allowed.";
            }
            break;
        default:
            cout << "Error! Incorrect Operator.";
            break;
    }

    return 0;
}
