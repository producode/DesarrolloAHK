// EjerciciosClase6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

struct Paty
{
	double precio;
	int grasa;
	double grosor;
};

struct Gaseosa
{
	double precio;
	string marca;
	string sabor;
};

struct Panceta
{
	double precio;
	int grasa;
	int cocion;
};

struct Cheddar
{
	double precio;
	double grasa;
};

struct Pan
{
	double precio;
	bool integral;
};

struct NodoPaty 
{
	Paty patyIngrediente;
	NodoPaty *siguientePaty;
};

struct NodoPanceta
{
	Panceta pancetaIngrediente;
	NodoPanceta *siguientePanceta;
};

struct NodoCheddar
{
	Cheddar cheddarIngrediente;
	NodoCheddar *siguienteCheddar;
};

struct ListaPaty
{
	NodoPaty *primerPaty;
};

struct ListaPanceta
{
	NodoPanceta *primerPanceta;
};

struct ListaCheddar
{
	NodoCheddar *primerCheddar;
};

struct Hamburguesa
{
	Pan panSuperior;
	Pan panInferior;
	ListaPaty *patys;
	ListaPanceta *pancetas;
	ListaCheddar *cheddars;
};

Paty *patyCreate(double precio, int grasa, double grosor) {
	Paty *nuevoPaty = new Paty;
	nuevoPaty->precio = precio;
	nuevoPaty->grasa = grasa;
	nuevoPaty->grosor = grosor;
	return nuevoPaty;
}

Gaseosa *gaseosaCreate(double precio, string marca, string sabor) {
	Gaseosa *nuevaGaseosa = new Gaseosa;
	nuevaGaseosa->precio = precio;
	nuevaGaseosa->marca = marca;
	nuevaGaseosa->sabor = sabor;
	return nuevaGaseosa;
}

Panceta *pancetaCreate(double precio,int grasa,int cocion) {
	Panceta *nuevaPanceta = new Panceta;
	nuevaPanceta->precio = precio;
	nuevaPanceta->grasa = grasa;
	nuevaPanceta->cocion = cocion;
	return nuevaPanceta;
}

Cheddar *cheddarCreate(double precio, int grasa) {
	Cheddar *nuevoCheddar = new Cheddar;
	nuevoCheddar->precio = precio;
	nuevoCheddar->grasa = grasa;
	return nuevoCheddar;
}

Pan *panCreate(double precio,bool integral) {
	Pan *nuevoPan = new Pan;
	nuevoPan->precio = precio;
	nuevoPan->integral = integral;
}

Hamburguesa *hamburguesaCreate(Pan panSuperior,Pan panInferior) {
	Hamburguesa *nuevaHamburguesa = new Hamburguesa;
	nuevaHamburguesa->panSuperior = panSuperior;
	nuevaHamburguesa->panInferior = panInferior;
}

double calcularIVA(double precio) {
	double resultado = (precio / 100) * 21;
	resultado += precio;
	return resultado;
}

void *nodoPancetaCreate(Panceta nuevaPanceta,NodoPanceta *NodoAuxiliar){
	NodoAuxiliar->siguientePanceta = new NodoPanceta;
	NodoAuxiliar = NodoAuxiliar->siguientePanceta;
	NodoAuxiliar->pancetaIngrediente = nuevaPanceta;
	NodoAuxiliar->siguientePanceta = NULL;
}
void *nodoCheddarCreate(Cheddar nuevaCheddar, NodoCheddar *NodoAuxiliar) {
	NodoAuxiliar->siguienteCheddar = new NodoCheddar;
	NodoAuxiliar = NodoAuxiliar->siguienteCheddar;
	NodoAuxiliar->cheddarIngrediente = nuevaCheddar;
	NodoAuxiliar->siguienteCheddar = NULL;
}

void agregarPanceta(Panceta nuevaPanceta, Hamburguesa *nuevaHamburguesa) {
	if (nuevaHamburguesa->pancetas->primerPanceta == NULL) {
		nuevaHamburguesa->pancetas->primerPanceta = new NodoPanceta;
		nuevaHamburguesa->pancetas->primerPanceta->pancetaIngrediente = nuevaPanceta;
		nuevaHamburguesa->pancetas->primerPanceta->siguientePanceta = NULL;
	}
	else {
		NodoPanceta *NodoAuxiliar = nuevaHamburguesa->pancetas->primerPanceta;
		while (NodoAuxiliar->siguientePanceta != NULL) {
			NodoAuxiliar = NodoAuxiliar->siguientePanceta;
		}
		nodoPancetaCreate(nuevaPanceta, NodoAuxiliar);
	}
}

void agregarCheddar(Cheddar nuevaCheddar, Hamburguesa *nuevaHamburguesa) {
	if (nuevaHamburguesa->cheddars->primerCheddar == NULL) {
		nuevaHamburguesa->cheddars->primerCheddar = new NodoCheddar;
		nuevaHamburguesa->cheddars->primerCheddar->cheddarIngrediente = nuevaCheddar;
		nuevaHamburguesa->cheddars->primerCheddar->siguienteCheddar = NULL;
	}
	else {
		NodoCheddar *NodoAuxiliar = nuevaHamburguesa->cheddars->primerCheddar;
		while (NodoAuxiliar->siguienteCheddar != NULL) {
			NodoAuxiliar = NodoAuxiliar->siguienteCheddar;
		}
		nodoCheddarCreate(nuevaCheddar, NodoAuxiliar);
	}
}

int main()
{
    
}
