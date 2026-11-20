#include <iostream>
using namespace std;
int main(){
    int n;
    int a[100];
    int key;
    bool found = false;
    cout << "Enter the number of Elements in the array:";
    cin >> n;
    cout << "Enter the " << n << " Elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter the Elements to search :";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
        cout << "Elements found in the array at the position :" << i+1;
        found = true;
        break;
        }
    }
    if (!found)
    cout << "Elements is not found in the array .";
    return 0;
}