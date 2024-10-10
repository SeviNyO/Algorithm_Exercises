#include <iostream>
using namespace std;

int main() {
    int R, C;
    int A;
    do {
        cin >> R >> C;
        cin >> A;
    } while (R <= 0 || R > 50 || C <= 0 || C > 50 || A <= 0 || A > 20);
    char** dibujo = new char*[R];
    for (int i = 0; i < R; ++i) {
        dibujo[i] = new char[C];
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> dibujo[i][j];
        }
    }
    //estoy entrando en locura
    int nR = R * A;
    int nC = C * A;
    char** dibujoA = new char* [nR];
    for (int i = 0; i < nR; ++i) {
        dibujoA[i] = new char[nC];
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            dibujoA[i * A][j * A] = dibujo[i][j];
            for (int ia = 0; ia < A; ++ia) {
                for (int ja = 0; ja < A; ++ja) {
                    dibujoA[(i * A) + ia][(j * A) + ja] = dibujo[i][j];
                }
                // dibujoA[i * a][j * a] = dibujo[i][j];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < nR; ++i) {
        for (int j = 0; j < nC; ++j) {
            cout << dibujoA[i][j];
        }
        cout << endl;
    }
    delete [] dibujo;
    delete [] dibujoA;
}