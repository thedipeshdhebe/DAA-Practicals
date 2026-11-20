#include <iostream>
using namespace std;
int main() {
    int n;
    long long fact = 1;
    cout << "Enter a number: ";
    cin >> n;
    if (n==0 || n==1) {
        cout << "Factorial = 1";
        return 0;
    } else {
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        cout << "Factorial = " << fact;
    }
    return 0;
}