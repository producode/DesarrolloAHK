// EjerciciosClase6.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

enum Prioridades{
    alta = 1,
    media = 2,
    baja = 3
};

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
	double precioBruto;
	double precioNeto;
};

struct NodoHamburguesa
{
	Hamburguesa hamburguesa;
	NodoHamburguesa *siguiente;
};

struct ListaHamburguesa
{
	NodoHamburguesa *primerHamburguesa;
};

struct Juguete
{
	double precio;
	string caricatura;
};

struct Combo
{
	Gaseosa bebida;
	Juguete juguete;
	ListaHamburguesa *hamburguesas;
	double precioBruto;
	double precioNeto;
};

struct NodoCombo
{
	Combo combo;
	NodoCombo *siguiente;
};

struct ListaCombo
{
	NodoCombo *primerCombo;
};

struct Pedido
{
	ListaCombo *combos;
	Prioridades prioridad;
	double precioBruto;
	double precioNeto;
};

struct NodoPedido
{
	Pedido pedido;
	NodoPedido *siguiente;
};

struct ListaPedido
{
	NodoPedido *primerPedido;
};

struct Cliente
{
	string nombre;
	Prioridades prioridad;
};

struct Repartidor
{
	int cantidadDePedidos;
	int cansancio;
	string nombre;
	string apellido;
};

struct NodoRepartidor{
    Repartidor repartidor;
    NodoRepartidor *siguiente;
};

struct ListaRepartidor{
    NodoRepartidor *primerRepartidor;
};

struct Semana
{
	ListaPedido *pedidos;
	double contaduria;
};

struct NodoCliente
{
    Cliente cliente;
    NodoCliente *siguiente;
};

struct ListaCliente
{
    NodoCliente *primerCliente;
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
	return nuevoPan;
}

Hamburguesa *hamburguesaCreate(Pan panSuperior,Pan panInferior) {
	Hamburguesa *nuevaHamburguesa = new Hamburguesa;
	nuevaHamburguesa->panSuperior = panSuperior;
	nuevaHamburguesa->panInferior = panInferior;
	return nuevaHamburguesa;
}

Combo *comboCreate(Gaseosa bebida, Juguete juguete){
    Combo *nuevoCombo = new Combo;
    nuevoCombo->bebida = bebida;
    nuevoCombo->juguete = juguete;
    return nuevoCombo;
}

Pedido *pedidoCreate(){
    Pedido *nuevoPedido = new Pedido;
    return nuevoPedido;
}

Repartidor *repartidorCreate(string nombre,string apellido){
    Repartidor *nuevoRepartidor = new Repartidor;
    nuevoRepartidor->nombre = nombre;
    nuevoRepartidor->apellido = apellido;
    nuevoRepartidor->cansancio = 0;
    nuevoRepartidor->cantidadDePedidos = 0;
    return nuevoRepartidor;
}

double calcularIVA(double precio) {
	double resultado = (precio / 100) * 21;
	resultado += precio;
	return resultado;
}

//funciones auxiliares para gregar elementos

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

void *nodoHamburguesaCreate(Hamburguesa nuevaHambueguesa,NodoHamburguesa *NodoAuxiliar){
	NodoAuxiliar->siguiente = new NodoHamburguesa;
	NodoAuxiliar = NodoAuxiliar->siguiente;
	NodoAuxiliar->hamburguesa = nuevaHambueguesa;
	NodoAuxiliar->siguiente = NULL;
}

void *nodoComboCreate(Combo nuevoCombo,NodoCombo *NodoAuxiliar){
	NodoAuxiliar->siguiente = new NodoCombo;
	NodoAuxiliar = NodoAuxiliar->siguiente;
	NodoAuxiliar->combo = nuevoCombo;
	NodoAuxiliar->siguiente = NULL;
}

//funciones para agregar elementos a listas

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

void agregarHamburguesa(Hamburguesa nuevaHamburguesa, Combo *nuevoCombo) {
	if (nuevoCombo->hamburguesas->primerHamburguesa == NULL) {
		nuevoCombo->hamburguesas->primerHamburguesa = new NodoHamburguesa;
		nuevoCombo->hamburguesas->primerHamburguesa->hamburguesa = nuevaHamburguesa;
		nuevoCombo->hamburguesas->primerHamburguesa->siguiente = NULL;
	}
	else {
		NodoHamburguesa *NodoAuxiliar = nuevoCombo->hamburguesas->primerHamburguesa;
		while (NodoAuxiliar->siguiente != NULL) {
			NodoAuxiliar = NodoAuxiliar->siguiente;
		}
		nodoHamburguesaCreate(nuevaHamburguesa, NodoAuxiliar);
	}
}

void agregarCombo(Combo nuevoCombo, Pedido *nuevoPedido) {
	if (nuevoPedido->combos->primerCombo == NULL) {
		nuevoPedido->combos->primerCombo = new NodoCombo;
		nuevoPedido->combos->primerCombo->combo = nuevoCombo;
		nuevoPedido->combos->primerCombo->siguiente = NULL;
	}
	else {
		NodoCombo *NodoAuxiliar = nuevoPedido->combos->primerCombo;
		while (NodoAuxiliar->siguiente != NULL) {
			NodoAuxiliar = NodoAuxiliar->siguiente;
		}
		NodoComboCreate(nuevoCombo, NodoAuxiliar);
	}
}

//funciones auxiliares para el calculo de precios

double obtenerTotalPancetas(NodoPanceta nodoAuxiliar){
	if(nodoAuxiliar->siguientePanceta == NULL){
        return nodoAuxiliar->pancetaIngrediente->precio;
	}
	else{
        double total = nodoAuxiliar->pancetaIngrediente->precio;
        total = total + obtenerTotalPancetas(nodoAuxiliar->siguientePanceta);
        return total;
	}
}

double obtenerTotalCheddar(NodoCheddar nodoAuxiliar){
	if(nodoAuxiliar->siguienteCheddar == NULL){
        return nodoAuxiliar->cheddarIngrediente->precio;
	}
	else{
        double total = nodoAuxiliar->cheddarIngrediente->precio;
        total = total + obtenerTotalCheddar(nodoAuxiliar->siguienteCheddar);
        return total;
	}
}

double obtenerTotalPatys(NodoPaty nodoAuxiliar){
	if(nodoAuxiliar->siguientePaty == NULL){
        return nodoAuxiliar->patyIngrediente->precio;
	}
	else{
        double total = nodoAuxiliar->patyIngrediente->precio;
        total = total + obtenerTotalPatys(nodoAuxiliar->siguientePaty);
        return total;
	}
}

double obtenerTotalHamburguesas(NodoHamburguesa nodoAuxiliar){
	if(nodoAuxiliar->siguiente == NULL){
        return nodoAuxiliar->hamburguesa->precioNeto;
	}
	else{
        double total = nodoAuxiliar->hamburguesa->precioNeto;
        total = total + obtenerTotalHamburguesas(nodoAuxiliar->siguiente);
        return total;
	}
}

double obtenerTotalCombos(NodoCombo nodoAuxiliar){
	if(nodoAuxiliar->siguiente == NULL){
        return nodoAuxiliar->combo->precioNeto;
	}
	else{
        double total = nodoAuxiliar->combo->precioNeto;
        total = total + obtenerTotalCombos(nodoAuxiliar->siguiente);
        return total;
	}
}

// Calculos de totales

double hamburguesaCalcularPrecio(Hamburguesa *hamburguesaCalculo){
    double total = 0;
    total = obtenerTotalCheddar(hamburguesaCalculo->cheddars->primerCheddar);
    total = total + obtenerTotalPancetas(hamburguesaCalculo->pancetas->primerPanceta);
    total = total + obtenerTotalPatys(hamburguesaCalculo->patys->primerPaty);
    return ((total/100)*110);
}

double comboCalcularPrecio(Combo *comboCalculo){
    double total = 0;
    total = obtenerTotalHamburguesas(comboCalculo->hamburguesas->primerHamburguesa);
    total = total + comboCalculo->bebida->precio;
    total = total + comboCalculo->juguete->precio;
    return total;
}

double pedidoCalcularPrecio(Pedido *pedidoCalculo){
    double total = 0;
    total = obtenerTotalCombos(pedidoCalculo->combos->primerCombo);
    return total;
}

struct TiposClientes
{
    ListaCliente *altaPrioridad;
    ListaCliente *mediaPrioridad;
    ListaCliente *bajaPrioridad;
};

void ordenarClientes(ListaCliente *clientesOrdenar){
    NodoCliente nodoAuxiliar = clientesOrdenar->primerCliente;
    diferenciar(clientesOrdenar->primerCliente);
    clientesOrdenar->primerCliente = listaAuxiliar->altaPrioridad;
    agregarAlFinalCliente(clientesOrdenar->primerCliente,listaAuxiliar->mediaPrioridad);
    agregarAlFinalCliente(clientesOrdenar->primerCliente,listaAuxiliar->bajaPrioridad);
}

void agregarAlFinalCliente(NodoCliente *clienteAgregar,NodoCliente *clienteSiguiente){
    if(clienteAgregar->siguiente == NULL){
        cliente->siguiente = clienteSiguiente;
    }
    else{
        agregarAlFinalCliente(cliente->siguiente,clienteSiguiente);
    }
}

TiposClientes listaAuxiliar = new TiposClientes;
void diferenciar(NodoCliente *clienteActual){
    if(clienteActual->cliente->prioridad == alta){
        if(listaAuxiliar->altaPrioridad->primerCliente == NULL){
            listaAuxiliar->altaPrioridad->primerCliente = new NodoCliente;
            listaAuxiliar->altaPrioridad->primerCliente->cliente = clienteActual->cliente;
            listaAuxiliar->altaPrioridad->primerCliente->siguiente = NULL;
        }
        else{
            agregarListaAuxiliar(listaAuxiliar->altaPrioridad->primerCliente,clienteActual->cliente);
        }
    }
    else if(clienteActual->cliente->prioridad == media){
        if(listaAuxiliar->mediaPrioridad->primerCliente == NULL){
            listaAuxiliar->mediaPrioridad->primerCliente = new NodoCliente;
            listaAuxiliar->mediaPrioridad->primerCliente->cliente = clienteActual->cliente;
            listaAuxiliar->mediaPrioridad->primerCliente->siguiente = NULL;
        }
        else{
            agregarListaAuxiliar(listaAuxiliar->mediaPrioridad->primerCliente,clienteActual->cliente);
        }
    }
    else if(clienteActual->cliente->prioridad == baja){
        if(listaAuxiliar->bajaPrioridad->primerCliente == NULL){
            listaAuxiliar->bajaPrioridad->primerCliente = new NodoCliente;
            listaAuxiliar->bajaPrioridad->primerCliente->cliente = clienteActual->cliente;
            listaAuxiliar->bajaPrioridad->primerCliente->siguiente = NULL;
        }
        else{
            agregarListaAuxiliar(listaAuxiliar->bajaPrioridad->primerCliente,clienteActual->cliente);
        }
    }
}

void agregarListaAuxiliar(NodoCliente *cliente, Cliente clienteAgregar){
    if(clienteAgregar->siguiente == NULL){
        NodoCliente nodoAuxiliar = new NodoCliente;
        nodoAuxiliar->cliente = clienteAgregar;
        cliente->siguiente = nodoAuxiliar;
    }
    else{
        agregarListaAuxiliar(cliente->siguiente,clienteAgregar);
    }
}

int main()
{

}
