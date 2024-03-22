#include "Pago.h"
#include <iostream>
#include <string.h>
#include "Fecha.h"
using namespace std;

Pago::Pago()
{
    //ctor
}
Pago::Pago(Fecha *fp, float mp){
    this -> fechaPago = fp;
    this -> montoPago = mp;
}
Pago::~Pago()
{
    //dtor
}
Fecha *Pago::getFechaPago(){
    return this -> fechaPago;
}
float Pago::getMontoPago(){
    return this -> montoPago;
}
