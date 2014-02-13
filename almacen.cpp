/*
 *  almacen.cpp
 *  Practica4
 *
 *  Created by Jonás López Mesa on 18/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "almacen.h"
//using namespace std;
//#include <iostream>

CAlmacen::CAlmacen(int s) : size(s){ //constructor Crea el array de compartimentos ‘cajas’, del tamaño indicado s. Inicializa a 0 el numero de cajas ocupadas y el numero de unidades en cada caja.

	int i;
	cout << "hola" << endl;
	cajas = new box[size];
	nCajasOcupadas = 0;
	
	for (i = 0; i < size; i++) {
		cajas[i].p_units = 0;
	}
}

CAlmacen::~CAlmacen(){ //Destructor Libera la memoria ocupada por el array ‘cajas’.

	delete[] cajas;
	
}

int CAlmacen::buscarProducto(int cod){ //Recibe el código de un producto y devuelve la posicion de la caja donde está, ó -1 si no lo encuentra.

	int posicion;
	int i;
	for (i = 0; i < actual; i++) {
		if (cod == cajas[i].p_code) {
			posicion = i;
		}
		else {
			posicion = -1;
		}

	}
	
	return posicion;
}

void CAlmacen::infoProducto(string name){ //Recibe el nombre de un producto y devuelve toda la información sobre él, es decir, la caja donde se encuentra, su código y el número de unidades disponibles.
	
	int p = 0;
	int i;
	for (i = 0; i < nCajasOcupadas; i++) {
		if (name == cajas[i].p_name) {
			cout << "Nombre del Producto:" << cajas[i].p_name << endl;
			cout << "Código del Producto:" << cajas[i].p_code << endl;
			cout << "Caja donde se encuentra:" << i << endl;
			cout << "Número de Unidades disponibles" << cajas[i].p_units << endl;
			p = 1;
		}
	}
	
	if (p = 0) {
		cout << "Ese producto no existe" << endl;
	}
	
	
}

void CAlmacen::anadirProducto(string name, int cod, int unidades){ //Recibe los datos de un producto a meter en el almacen (nombre, código y número de unidades). Si el producto ya está en algún compartimento del almacén, simplemente actualiza el número de unidades disponibles. Si no, lo mete en el primer compartimento vacío que encuentre, si el almacén no está lleno, e incrementa nCajasOcupadas.

	int i;
	int ver = 0;
	
	for (i = 0; i < nCajasOcupadas; i++) {
		if (cod == cajas[i].p_code) {
			cajas[i].p_units = unidades;
			ver = 1;
		}
	}
	if (ver = 0) {
		if (nCajasOcupadas < size) {
			cajas[i].p_name = name;
			cajas[i].p_code = cod;
			cajas[i].p_units = unidades;
			nCajasOcupadas++;
		}
	}

}

void CAlmacen::retirarProducto(string name, int cod, int unidades){ //Recibe el nombre y código de un producto y el número de unidades a retirar. Busca el compartimento donde está y resta las unidades pedidas, siempre y cuando sea posible (pedido menor que unidades disponibles). Si el compartimento queda vacío, decrementa nCajasOcupadas.

	int rec = 0;
	int i;
	for (i = 0; i < nCajasOcupadas; i++) {
		if ((name == cajas[i].p_name) && (cod == cajas[i].p_code)) {
			if (cajas[i].p_units > unidades){
				cajas[i].p_units = (cajas[i].p_units - unidades);
				rec = 1;
			}
			if ((cajas[i].p_units < unidades) && (rec == 0)) {
				cout << "no hay suficientes unidades de ese producto" << endl;
				rec = 1;
			}
			if ((cajas[i].p_units = unidades) && (rec == 0)) {
				nCajasOcupadas--;
				rec = 1;
			}
			if (rec == 1) {
				i = nCajasOcupadas;
			}
		}
	}
	
}

void CAlmacen::listar(){ //Lista todos los productos que hay en el almacén, mostrando la caja donde están, el nombre, código y número de unidades.

	int i;
	
	
	cout << "*************ALMACÉN**************";
	for (i = 0; i < nCajasOcupadas; i++) {
		cout << "----------------------------------" << endl;
		cout << "Caja donde está situada:.........." << i << endl;
		cout << "Nombre:..........................." << cajas[i].p_name << endl;
		cout << "Código:..........................." << cajas[i].p_code << endl;
		cout << "Número de Unidades:..............." << cajas[i].p_units << endl;
		cout << "----------------------------------" << endl;
		
	}
	
}





