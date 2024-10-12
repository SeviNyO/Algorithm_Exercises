#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> trabajadores;
    vector<string> alumnos;

    int trab = 0;
    int alum = 0;

    vector<string> atendidos;
    string entrada, tipo, name;
    for(int i = 0; i < n; ++i){
        cin >> entrada;
        if(entrada == "LLEGA"){
            cin >> tipo >> name;
            if(tipo == "TRABAJADOR"){
                trabajadores.push_back(name);
            }
            else if(tipo == "ALUMNO"){
                alumnos.push_back(name);
            }
        }
        else if(entrada == "ATIENDE"){
            if(trab < trabajadores.size()){
                atendidos.push_back(trabajadores[trab]);
                trab++;
            }
            else if(alum < alumnos.size()){
                atendidos.push_back(alumnos[alum]);
                alum++;
            }
        }
    }


    for(auto nombre : atendidos){
        cout << nombre << '\n';
    }

    return 0;
}
