#include "ejercicio_4_cuenta_de_banco.hpp"

int main(){
    //Verifico la funcionalidad de tanto la Caja de Ahorros, como la de la Cuenta Corriente:
    /*Lo inicializo como un share pointer para despues poder pasarselo a Cuenta Corriente sin problemas y para que, cuando use "mostrarInfo"
    de la caja, no tenga problemas con la actualizacion de la info de la caja, al no tener copias de la misma (es lo que me sucedio cuando 
    intente hacerlo con un unique pointer)*/
    shared_ptr<CajaDeAhorro> caja_de_ahorro = make_shared<CajaDeAhorro>(1000, "Sol"); 
    caja_de_ahorro->depositar(150);
    caja_de_ahorro->mostrarInfo();
    cout << endl; //Lo hago porque quiero dejar una linea en blanco en la terminal, para separar secciones.
    caja_de_ahorro->retirar(1300);
    cout << endl;
    caja_de_ahorro->retirar(330);
    caja_de_ahorro->mostrarInfo();
    cout << endl;

    CuentaCorriente cuenta_corriente = CuentaCorriente(100, "Sol");
    cuenta_corriente.set_CajaDeAhorro(caja_de_ahorro);
    cuenta_corriente.depositar(50);
    cuenta_corriente.mostrarInfo();
    cout << endl;
    cuenta_corriente.retirar(100);
    cuenta_corriente.mostrarInfo();
    cout << endl;
    cuenta_corriente.retirar(200);
    cuenta_corriente.mostrarInfo();
    caja_de_ahorro->mostrarInfo();
    cout << endl;
    cuenta_corriente.retirar(900);
    cout << endl;
    
    return 0;
}