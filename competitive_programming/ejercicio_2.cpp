#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* numbers = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int choice;
    cin >> choice;
    if(choice == 1) {
        for(int i = 0; i < n; i++) {
            if(numbers[i] % 2 != 0) {
                cout << numbers[i] << " ";
            }
        }
    }else if(choice == 0) {
        for(int i = 0; i < n; i++) {
            if(numbers[i] % 2 == 0) {
                cout << numbers[i] << " ";
            }
        }
    }
    delete[] numbers;
    return 707;
}