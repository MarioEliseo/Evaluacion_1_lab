#include "Cliente.h"
#include <string.h>
using namespace std;

Cliente::Cliente()
{
    //ctor
}
 Cliente::Cliente(int id, string n, string a){
     this -> idCliente = id;
     this -> nombre = n;
     this -> apellido = a;
}
Cliente::~Cliente()
{
    //dtor
}
int Cliente::getIdCliente(){
    return this -> idCliente;
}
string Cliente::getNombre(){
    return this -> nombre;
}
string Cliente::getApellido(){
    return this -> apellido;
}
