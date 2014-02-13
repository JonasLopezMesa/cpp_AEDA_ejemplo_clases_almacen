//#include <iostream>
//#include <string>
#include "almacen.cpp"

//using namespace std;

int main () {
	
/*	int s;
	cout << "Antes de comenzar, introduzca el número máximo de compartimentos del almacen" << endl;
	cin >> s;
	CAlmacen almacen1(s);
*/	
	void menu();
	
	menu();

}
	
void menu(){
		
		int cod;
		int unidades;
		string name;
		int a = 0;
		int op;int s;
		cout << "Antes de comenzar, introduzca el número máximo de compartimentos del almacen" << endl;
		cin >> s;
		CAlmacen almacen1(s);
		while(a == 0){
			cout << "MENÚ" << endl;
			cout << "Selecciona la opcion que desees:" << endl;
			cout << "1 ===> Listar todos los Productos" << endl;
			cout << "2 ===> Información sobre un Producto (nombre)" << endl;
			cout << "3 ===> Añadir un Producto" << endl;
			cout << "4 ===> Hacer un pedido del producto" << endl;
			cout << "5 ===> Salir" << endl;
			
			cin >> op;	
			switch(op){
				case 1: void listar();
					break;
				case 2: cout << "introduce el nombre del producto del que deseas recibir información:" << endl;
						cin >> name;
						almacen1.infoProducto(name);
					break;
				case 3: cout << "introduce el nombre del producto que deseas añadir" << endl;
						cin >> name;
						cout << "introduce el código del producto que deseas añadir" << endl;
						cin >> cod;
						cout << "introduce el número de unidades de ese producto" << endl;
						cin >> unidades;
						almacen1.anadirProducto(name, cod, unidades);
					break;
				case 4: cout << "introduce el nombre del producto que deseas añadir" << endl;
						cin >> name;
						cout << "introduce el código del producto que deseas añadir" << endl;
						cin >> cod;
						cout << "introduce el número de unidades de ese producto" << endl;
						cin >> unidades;
						almacen1.retirarProducto(name, cod, unidades);
					break;					
				case 5: cout << "adios!!!" << endl;
					a = 1;
					break;	
				default: cout << "ERROR vuelva a escribir una opcion correcta" << endl;
					
					
			}
		}
		
	}





