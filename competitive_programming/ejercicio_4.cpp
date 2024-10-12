#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int valor;
    int suma = 0;
    int menor = 100;
    for(int i = 0; i < n; ++i) {
        cin >> valor;
        if(valor < menor) {
            menor = valor;
        }
        suma += valor;
    }
    suma-=menor;
    cout << suma;
    return 0;
}