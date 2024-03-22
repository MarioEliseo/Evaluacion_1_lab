#include <iostream>
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#include "Fecha.h"
#include "Pago.h"
#define TML 5
using namespace std;

int menu(){
    int op;
    cout << "MENU DE OPCIONES" << endl;
    cout << "1. Agregar cliente a la lista" << endl;
    cout << "2. Agregar prestamo a la lista" << endl;
    cout << "3. Hacer pagos de prestamos" << endl;
    cout << "4. Mostrar lista de clientes" << endl;
    cout << "5. Mostrar lista de prestamos" << endl;
    cout << "6. Mostrar detalles del prestamo" << endl;
    cout << "7. Salir" << endl;
    cout << "Digite una opcion: ";
    cin >> op;

    return op;
}
Cliente *agregarCliente(){
    int id;
    string n,a;
    Cliente *cli;
    cout << "Ingrese el id del cliente: ";
    cin >> id;
    cout << "Ingrese el nombre del cliente: ";
    cin >> n;
    cout << "Ingrese el apellido del cliente: ";
    cin >> a;
    cli = new Cliente (id, n, a);
    return cli;
}
Cliente *BuscarCliente(Cliente *lst[], int cont, int db){
    bool Encontrado = false;
    int contador = 0;
    Cliente *cli = NULL;
    while(contador < cont && !Encontrado){
        if(lst[contador]-> getIdCliente() == db){
            Encontrado = true;
            cli = lst[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli){
    int np;
    int d, m, a;
    Fecha *fa;
    float ma;
    Prestamo *ptmo;
    cout << "Digite el numero del prestamo: ";
    cin >> np;
    cout << "Digite la fecha de aprobacion (dd/mm/aa): " <<endl;
    cin >> d;
    cin >> m;
    cin >> a;
    fa = new Fecha(d,m,a);
    cout << "Digite el monto del cliente: ";
    cin >> ma;
    ptmo = new Prestamo(np, cli, fa, ma);
    return ptmo;
}
Prestamo *BuscarPrestamo(Prestamo *lst[], int cont, int db){
    bool encontrado = false;
    int contador = 0;
    Prestamo *ptmo = NULL;
    while(contador < cont && !encontrado){
        if(lst[contador]-> getNumeroPrestamo() == db){
            encontrado = true;
            ptmo = lst[contador];
        }
        else{
            contador++;
        }
    }
    return ptmo;
}
void registrarPago(Prestamo *ptmo){
    int d,m,a;
    Fecha *fp;
    float mp;
    Pago *pg;
    cout << "Digite la fecha de pago (dd/mm/aa): " <<endl;
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Digite el monto del pago: ";
    cin >> mp;
    fp = new Fecha(d,m,a);
    pg = new Pago(fp, mp);
    ptmo -> hacerPago(pg);
}
void verDetalles(Prestamo *ptmo){
    cout << "Id prestmo: " << ptmo->getNumeroPrestamo() << endl;
    cout << "Cliente: " << ptmo->getCliente()->getNombre() << " " << ptmo->getCliente()->getApellido() << endl;
    cout << "Fecha-Aprobacion: ";
    ptmo->getFechaAprobacion()->mostrarFecha();
    cout << "\nMonto aprobado: " << ptmo->getMontoAprobado() << endl;
    cout << "Saldo pendiente: " << ptmo->getSaldoPendiente() << endl;
    if(ptmo->getContadorPagos() == 0){
        cout << "No tiene pagos registrados\n";
    }
    else{
        Pago **lista = ptmo ->getLstPagos();
        cout << "No\tFecha\t\tMonto\n";
        for(int i = 0; i < ptmo->getContadorPagos(); i++){
            cout << (i + 1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t" << lista[i]->getMontoPago() << "\t" << endl;
        }
    }
}
int main(){
    Cliente *lstCliente[TML];
    Prestamo *lstPrestamo[TML];
    Cliente *cli = NULL;
    Prestamo *ptmo = NULL;
    int contCli = 0, contPtmo = 0, idCli, idPtmo;
    int opc;
    do{
        system("cls");
        opc = menu();
        switch(opc){
            case 1:
                ///Agregar Clientes
                if(contCli < TML){
                    lstCliente[contCli] = agregarCliente();
                    contCli++;
                    cout << "El cliente se agrego con exito" << endl;
                }
                else{
                    cout << "La lista de clientes esta llena" << endl;
                }
                break;
            case 2:
                ///Agregar Prestamos
                {
                    if(contPtmo < TML){
                        cout << "Digite el id del cliente: ";
                        cin >> idCli;
                        cli = BuscarCliente(lstCliente, contCli, idCli);
                        if(cli){
                            lstPrestamo[contPtmo] = agregarPrestamo(cli);
                            contPtmo++;
                            cout << "El prestamo se registro con exito\n";
                        }
                        else{
                            cout << "El cliente no existe, no se puede agregar el prestamo" <<endl;
                        }
                    }
                    else{
                        cout << "La lista de prestamo esta llena" << endl;
                    }
                }
                break;
            case 3:
                ///Hacer Pagos
                cout << "Digite el numero del prestamo: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if (ptmo){
                    registrarPago(ptmo);
                    cout << "El pago se registro con exito\n";
                }
                else{
                    cout << "El prestamo no existe, no se puede registrar el pago" <<endl;
                }
                break;
            case 4:
                ///Mostrar lista de clientes
                if(contCli == 0){
                    cout << "La lista esta vacia\n";
                }
                else{
                    cout << "Id\tNombre\tApellido\n";
                    for(int i = 0; i < contCli; i++){
                        cout << lstCliente[i] -> getIdCliente() << "\t";
                        cout << lstCliente[i] -> getNombre() << "\t";
                        cout << lstCliente[i] -> getApellido() << "\n";
                    }
                }
                break;
            case 5:
                ///Mostrar lista de prestamos
                if(contPtmo == 0){
                    cout << " La lista esta vacia\n";
                }
                else{
                    cout << "No\tCliente\t\tFecha\t\tMonto\t\tSaldo pendiente" <<endl;
                    for(int i = 0; i < contPtmo; i++){
                        cout << lstPrestamo[i] -> getNumeroPrestamo() << "\t";
                        cout << lstPrestamo[i] -> getCliente()-> getNombre() << " " << lstPrestamo[i]-> getCliente()-> getApellido() << "\t";
                        lstPrestamo[i]-> getFechaAprobacion()-> mostrarFecha();
                        cout << "\t" << lstPrestamo[i]-> getMontoAprobado() << "\t";
                        cout << "\t" << lstPrestamo[i]-> getSaldoPendiente() << "\n";
                    }
                }
                break;
            case 6:
                ///Mostrar detalle del prestamo
                cout << "Digite el numero del prestamo: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if(ptmo){
                    verDetalles(ptmo);
                }
                else{
                    cout << "El prestamo no existe, no se pueden ver los detalles\n";
                }
                break;
            case 7:
                ///Salir
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida..." << endl;
                break;
        }
        system("pause");
    }while(opc != 7);
    return 0;
}
