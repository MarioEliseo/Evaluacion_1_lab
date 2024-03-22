#include "Prestamo.h"
#include "Cliente.h"
#include "Pago.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


Prestamo::Prestamo()
{
    //ctor
}
Prestamo::Prestamo(int  np, Cliente *cli, Fecha *fa, float ma){
    this -> numeroPrestamo = np;
    this -> cliente = cli;
    this -> fechaAprobacion = fa;
    this -> montoAprobado = ma;
    this -> saldoPendiente = ma;
    this -> contadorPagos = 0;
}

Prestamo::~Prestamo()
{
    //dtor
}
int Prestamo::getNumeroPrestamo(){
    return this -> numeroPrestamo;
}
void Prestamo::setNumeroPrestamo(int np){
    this -> numeroPrestamo = np;
}
Cliente *Prestamo::getCliente(){
    return this -> cliente;
}
void Prestamo::setCliente(Cliente *cli){
    this -> cliente = cli;
}
void Prestamo::setFechaAprobacion(Fecha *fa){
    this -> fechaAprobacion = fa;
}
Fecha *Prestamo::getFechaAprobacion(){
    return this -> fechaAprobacion;
}
void Prestamo::setMontoAprobacion(float ma){
    this -> montoAprobado = ma;
}
float Prestamo::getMontoAprobado(){
    return this -> montoAprobado;
}
bool Prestamo::hacerPago(Pago *pg){
    bool retorno = false;
    if (this -> contadorPagos < DIMP){
        this -> lstPagos[this -> contadorPagos] = pg;
        this -> contadorPagos++;
        this -> saldoPendiente -= pg -> getMontoPago();
        retorno = true;
    }
    return retorno;
}
Pago **Prestamo::getLstPagos(){
    return this -> lstPagos;
}
float Prestamo::getSaldoPendiente(){
    return this -> saldoPendiente;
}
int Prestamo::getContadorPagos(){
    return this -> contadorPagos;
}
