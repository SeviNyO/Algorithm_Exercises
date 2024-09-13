#include <iostream>
#include <conio.h>
#include "CListaTransporte.hpp"


int main() {
	CListaTransporte* lista = new CListaTransporte();
	while (1) {
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'c') {
				lista->agregarTransporte(new CCoche());
			}
			else if (tecla == 'b') {
				lista->agregarTransporte(new CBiclicleta());
			}
		}
		lista->animacion();
		
		_sleep(50);
	}
	delete lista;
	_getch();
	return 707;
}