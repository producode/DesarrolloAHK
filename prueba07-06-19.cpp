// pruebaDesarrollo070619.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

const int tamanioVector = 10;

int vectorPrueba1[10] = { 1,2,3,4,5,6,7,8,9,10 };
int vectorPrueba2[10] = { 10,20,30,40,50,60,70,80,90,100 };

void intercaladoVectores(int primerVector[tamanioVector], int segundoVector[tamanioVector]) {
	int j = 1;
	int vectorCambiante[tamanioVector][2];
	for (int i = 0;i < tamanioVector;i++) {
		vectorCambiante[i][0] = primerVector[i];
		vectorCambiante[i][1] = segundoVector[i];
	}
	int nuevoVector[tamanioVector];
	for (int i = 0;i < tamanioVector;i++) {
		nuevoVector[i] = vectorCambiante[i][j];
		cout << nuevoVector[i] << ",";
		j = 1 - j;
	}
}

int sumador(int vector[15]) {
	int resultado = 0;
	for (int i = 0;i < 15;i++) {
		resultado = resultado + vector[i];
	}
	return resultado;
}

int mayorJugador(int tiempo[15][3]) {
	int mayor = tiempo[0][0];
	int jugador = 0;
	int maquina = 0;
	for (int i = 0;i < 15;i++) {
		for (int j = 0;j < 3;j++) {
			if (tiempo[i][j] > mayor) {
				mayor = tiempo[i][j];
				jugador = i;
				maquina = j;
			}
		}
	}
	return jugador;
}

int mayorMaquina(int tiempos[15][3]) {
	int primerVector[15];
	int segundoVector[15];
	int tercerVector[15];
	for (int i = 0;i < 15;i++) {
		primerVector[i] = tiempos[i][0];
		segundoVector[i] = tiempos[i][1];
		tercerVector[i] = tiempos[i][2];
	}
	int resultado1 = sumador(primerVector);
	int resultado2 = sumador(segundoVector);
	int resultado3 = sumador(tercerVector);
	if (resultado1 >= resultado2) {
		if (resultado1 >= resultado3) {
			return 0;
		}
		else {
			return 2;
		}
	}
	else {
		if (resultado2 >= resultado3) {
			return 1;
		}
		else {
			return 2;
		}
	}
}

void vicio() {
	int tiempos[15][3];
	for (int i = 0;i < 15;i++) {
		cout << "jugador " << i << " jugo (en horas) " << endl;
		for (int j = 0;j < 3;j++) {
			cout << "maquina " << j << ": ";
			cin >> tiempos[i][j];
		}
	}
	int jugadorMayor = 0;
	int maquinaMayor = 0;
	jugadorMayor = mayorJugador(tiempos);
	cout << "el jugador " << jugadorMayor << " es el mas vicio" << endl;
	cout << "la maquina mas usada es la " << mayorMaquina(tiempos) << endl;
	bool salir = true;
	while (salir) {
		int jugador = 0;
		cout << "ingrese el numero de jugador para ver la maquina en la que mas jugo o ingrese 20 para salir" << endl;
		cin >> jugador;
		if (jugador == 20) {
			salir = false;
		}
		else if (jugador >= 0 && jugador < 15) {
			if (tiempos[jugador][0] >= tiempos[jugador][1]) {
				if (tiempos[jugador][0] >= tiempos[jugador][2]) {
					cout << "utilizo mas la maquina 0" << endl;
				}
				else {
					cout << "utilizo mas la maquina 2" << endl;
				}
			}
			else {
				if (tiempos[jugador][1] >= tiempos[jugador][2]) {
					cout << "utilizo mas la maquina 1" << endl;
				}
				else {
					cout << "utilizo mas la maquina 2" << endl;
				}
			}
		}
	}
}

int calcularFactorial(int numero) {
	if (numero <= 1) {
		return 1;
	}
	return numero * calcularFactorial(numero - 1);
}

void pedirFactorial() {
	int numero = 0;
	do {
		cout << "ingrese un numero para sacar el factorial o un numero negativo para salir" << endl;
		cin >> numero;
		cout << calcularFactorial(numero) << endl;
	} while (numero >= 1);
}

enum gamas {
	alta = 0,
	media = 1,
	baja = 2
};

enum facturas {
	A = 0,
	B = 1,
	C = 2
};

enum pagos {
	constado = 0,
	financiado = 1,
	parcialmenteFinanciado = 2
};

struct Automovil
{
	string marca;
	string modelo;
	gamas gama;
	int anioFabricacion;
	double valorResidual;
	int kilometros;
};

struct Factura
{
	facturas tipo;
	double importe;
	Automovil *autoVendido;
	string fecha;
	string comprador;
	pagos tipoPago;
};

struct Cuenta
{
	string tipo;
	double valor;
};

struct NodoCuentas
{
	Cuenta cuenta;
	NodoCuentas *siguiente;
};

struct ListaCuentas
{
	NodoCuentas *primerCuenta;
};

struct NodoAsiento
{
	string Asiento;
	NodoAsiento *siquiente;
};

struct ListaAsientos
{
	NodoAsiento *primerAsiento;
};

struct Movimiento
{
	string fecha;
	string hora;
	ListaCuentas *cuentas;
	Factura *factura;
	ListaAsientos *asientos;
};

struct NodoMovimiento
{
	Movimiento movimiento;
	NodoMovimiento *siguiente;
};

struct ListaMovimientos
{
	NodoMovimiento *primerMovimiento;
};

struct DiarioContable
{
	int anio;
	ListaMovimientos *movimientos;
};

Automovil *automovilCreate(string marca, string modelo, gamas gama, int anioFabricacion, double valorResidual, int kilometros) {
	Automovil *nuevoAutomovil = new Automovil;
	nuevoAutomovil->marca = marca;
	nuevoAutomovil->modelo = modelo;
	nuevoAutomovil->gama = gama;
	nuevoAutomovil->anioFabricacion = anioFabricacion;
	nuevoAutomovil->valorResidual = valorResidual;
	nuevoAutomovil->kilometros = kilometros;
	return nuevoAutomovil;
}

Factura *facturaCreate(facturas tipo, double importe, Automovil *autoVendido, string fecha, string comprador, pagos tipoPago) {
	Factura *nuevaFactura = new Factura;
	nuevaFactura->tipo = tipo;
	nuevaFactura->importe = importe;
	nuevaFactura->autoVendido = autoVendido;
	nuevaFactura->fecha = fecha;
	nuevaFactura->comprador = comprador;
	nuevaFactura->tipoPago = tipoPago;
	return nuevaFactura;
}

DiarioContable *diarioContableCreate(int anio, ListaMovimientos *movimientos) {
	DiarioContable *nuevoDiarioContable = new DiarioContable;
	nuevoDiarioContable->anio = anio;
	nuevoDiarioContable->movimientos = movimientos;
	return nuevoDiarioContable;
}

Cuenta *cuentaCreate(string tipo, int valor) {
	Cuenta *cuenta = new Cuenta;
	cuenta->tipo = tipo;
	cuenta->valor = valor;
	return cuenta;
}

void agregarAsiento(NodoAsiento *asiento, string asientoAgregar) {
	if (asiento->siquiente == NULL) {
		asiento->Asiento = asientoAgregar;
	}
	else {
		agregarAsiento(asiento->siquiente, asientoAgregar);
	}
}

void agregarCuenta(NodoCuentas *cuentas, Cuenta cuenta) {
	if (cuentas->siguiente == NULL) {
		cuentas->cuenta = cuenta;
	}
	else {
		agregarCuenta(cuentas->siguiente, cuenta);
	}
}

void agregarMovimiento(NodoMovimiento *movimiento, Movimiento mov) {
	if (movimiento->siguiente == NULL) {
		movimiento->movimiento = mov;
	}
	else {
		agregarMovimiento(movimiento->siguiente, mov);
	}
}

NodoCuentas buscarCuenta(NodoCuentas* cuenta, string tipo) {
	if (cuenta->cuenta.tipo == tipo) {
		return *cuenta;
	}
	else if (cuenta->siguiente != NULL) {
		return buscarCuenta(cuenta->siguiente, tipo);
	}
}

void modificarCuentas(NodoCuentas *inicial, NodoCuentas *cuenta, Factura factura, ListaAsientos *asientos) {
	if (factura.tipoPago == 0) {
		if (cuenta->cuenta.tipo == "Mercaderia") {
			cuenta->cuenta.valor = cuenta->cuenta.valor - factura.autoVendido->valorResidual;
			agregarAsiento(asientos->primerAsiento, "- Mercaderia $" + to_string(factura.autoVendido->valorResidual));
		}
		else if (cuenta->cuenta.tipo == "Caja") {
			cuenta->cuenta.valor = cuenta->cuenta.valor + factura.importe;
			agregarAsiento(asientos->primerAsiento, "+ Caja $" + to_string(factura.importe));
		}
		else if (cuenta->cuenta.tipo == "Ventas") {
			NodoCuentas cuentaMercaderia = buscarCuenta(inicial, "Mercaderia");
			NodoCuentas cuentaCaja = buscarCuenta(inicial, "Caja");
			cuenta->cuenta.valor = cuenta->cuenta.valor + (cuentaCaja.cuenta.valor - cuentaMercaderia.cuenta.valor);
			agregarAsiento(asientos->primerAsiento, "+ Ventas $" + to_string(cuentaCaja.cuenta.valor - cuentaMercaderia.cuenta.valor));
		}
	}
	else if (factura.tipoPago == 1) {
		if (cuenta->cuenta.tipo == "Mercaderia") {
			cuenta->cuenta.valor = cuenta->cuenta.valor - factura.autoVendido->valorResidual;
			agregarAsiento(asientos->primerAsiento, "- Mercaderia $" + to_string(factura.autoVendido->valorResidual));
		}
		else if (cuenta->cuenta.tipo == "Deudores por ventas") {
			cuenta->cuenta.valor = cuenta->cuenta.valor + (factura.importe * 1.15);
			agregarAsiento(asientos->primerAsiento, "+ Deudores por venta $" + to_string(factura.importe * 1.15));
		}
		else if (cuenta->cuenta.tipo == "Intereses ganados") {
			cuenta->cuenta.valor = cuenta->cuenta.valor + (factura.importe * 0.15);
			agregarAsiento(asientos->primerAsiento, "+ Intereses ganados $" + to_string(factura.importe * 0.15));
		}
		else if (cuenta->cuenta.tipo == "Ventas") {
			NodoCuentas cuentaMercaderia = buscarCuenta(inicial, "Mercaderia");
			NodoCuentas cuentaDeudores = buscarCuenta(inicial, "Deudores por venta");
			cuenta->cuenta.valor = cuenta->cuenta.valor + (cuentaDeudores.cuenta.valor - cuentaMercaderia.cuenta.valor);
			agregarAsiento(asientos->primerAsiento, "+ Ventas $" + to_string(cuentaDeudores.cuenta.valor - cuentaMercaderia.cuenta.valor));
		}
	}
}

Movimiento *movimientoCreate(string fecha, string hora, ListaCuentas *cuentas, Factura *factura) {
	Movimiento *nuevoMovimiento = new Movimiento;
	nuevoMovimiento->fecha = fecha;
	nuevoMovimiento->hora = hora;
	nuevoMovimiento->factura = factura;
	modificarCuentas(cuentas->primerCuenta, cuentas->primerCuenta, *factura, new ListaAsientos);
	return nuevoMovimiento;
}

int main()
{
	int opcion = 1;
	cout << "seleccione ejercicio A(1 a 3) ejercicio B(4)" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		intercaladoVectores(vectorPrueba1, vectorPrueba2);
		break;
	case 2:
		vicio();
		break;
	case 3:
		pedirFactorial();
		break;
	case 4:
		Automovil *vehiculo;
		Factura *factura;
		Movimiento *movimiento;
		ListaCuentas *cuentas;
		DiarioContable *diarioContable;
		ListaMovimientos *movimientos;
		
		agregarCuenta(cuentas->primerCuenta, *cuentaCreate("Mercaderia", 720000));
		agregarCuenta(cuentas->primerCuenta, *cuentaCreate("Caja", 720000));
		agregarCuenta(cuentas->primerCuenta, *cuentaCreate("Ventas", 720000));
		agregarCuenta(cuentas->primerCuenta, *cuentaCreate("Deudores por venta", 720000));
		agregarCuenta(cuentas->primerCuenta, *cuentaCreate("Intereses ganados", 720000));
		vehiculo = automovilCreate("ford", "focus", alta, 2017, 360000, 80000);
		factura = facturaCreate(A, 450000, vehiculo, "01/06/2019", "JE morgan SA", financiado);
		movimiento = movimientoCreate(factura->fecha, "12:44", cuentas, factura);
		agregarMovimiento(movimientos->primerMovimiento, *movimiento);
		diarioContable = diarioContableCreate(2017, movimientos);
		break;
	default:
		break;
	}
	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
