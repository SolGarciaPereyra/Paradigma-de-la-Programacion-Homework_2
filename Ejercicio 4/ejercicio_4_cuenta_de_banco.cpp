#include "ejercicio_4_cuenta_de_banco.hpp"

//Defino los metodos de la clase abstracta "Cuenta Bancaria" (los que no son metodos virtuales puros):
CuentaBancaria::CuentaBancaria(double cantidad_balance, string nombre_del_titular): balance(cantidad_balance), titularCuenta(nombre_del_titular) {}

void CuentaBancaria::depositar(double dinero_a_depositar){ balance = balance + dinero_a_depositar;}

string CuentaBancaria::get_titularCuenta(){ return titularCuenta;}

double CuentaBancaria::get_balance(){ return balance;}

void CuentaBancaria::set_balance(double nuevo_balance){ balance = nuevo_balance;}

//Defino los metodos de la subclase "Caja de Ahorros":
CajaDeAhorro::CajaDeAhorro(double balance_de_cuenta, string nombre_titular): CuentaBancaria(balance_de_cuenta, nombre_titular) {}

double CajaDeAhorro::retirar(double cantidad_a_retirar){
    if(cantidad_a_retirar > get_balance()){  //Impido que sea posible retirar mas dinero del que existe en el balance.
        cout << "No se puede retirar el dinero exigido, ya que es mas dinero del que existe en el balance." << endl;
        return 0;
    }
    
    double nuevo_balance = get_balance() - cantidad_a_retirar;  //Calculo con cuanta plata me voy a quedar en la caja luego de realizar el retiro de dinero.
    set_balance(nuevo_balance); //Le saco al balance total la cantidad que quiero retirar (es decir, actualizo el valor de balance con "nuevo_balance").
    return cantidad_a_retirar; //Retorno la cantidad de plata que saque de mi caja. 
}

void CajaDeAhorro::mostrarInfo(){
    conteo_mostrarInfo = conteo_mostrarInfo + 1; //Actualizo la cantidad de veces que el usuario pidio ver la info de la cuenta.
    if(conteo_mostrarInfo > 2){ //Realizo el descuento exigido por la consigna.
        double nuevo_balance = get_balance() - 20;
        set_balance(nuevo_balance);
    }

    //Imprimo por la terminal la informacion de la cuenta:
    cout << "Nombre del titular: " << get_titularCuenta() << endl; 
    cout << "Tipo de cuenta: " << tipo_de_cuenta << endl;
    cout << "Balance de la cuenta: " << get_balance() << endl;
}

//Defino los metodos de la subclase "Caja de Ahorros":

CuentaCorriente::CuentaCorriente(double balance_de_cuenta, string nombre_titular): CuentaBancaria(balance_de_cuenta, nombre_titular) {}

void CuentaCorriente::set_CajaDeAhorro(shared_ptr<CajaDeAhorro> caja_de_ahorro_puntero){ titular_CajaDeAhorro_puntero = caja_de_ahorro_puntero;}

double CuentaCorriente::retirar(double cantidad_a_retirar){
    if(cantidad_a_retirar > get_balance()){ //Impido que sea posible retirar mas dinero del que existe en el balance.
        cout << "No alcanza el balance en la cuenta corriente para retirar esa cantidad. Procedemos a probar con la caja de ahorros." << endl;

        double plata_retirada = titular_CajaDeAhorro_puntero->retirar(cantidad_a_retirar); //Le doy la posibilidad de retirar la plata de la caja de ahorro.

        if(plata_retirada == 0){ //Si "plata_retirada" es igual a cero, significa que el balance de la caja de ahorros es menor a "cantidad_a_retirar"
            cout << "No existen suficientes fondos tanto en la cuenta corriente, como en la caja de ahorro, para retirar esa cantidad de dinero." << endl;
            return 0;
        }
        
        return plata_retirada;
    }
    
    double nuevo_balance = get_balance() - cantidad_a_retirar;  //Calculo con cuanta plata me voy a quedar en la cuenta luego de realizar el retiro de dinero.
    set_balance(nuevo_balance); //Le saco al balance total la cantidad que quiero retirar (es decir, actualizo el valor de balance con "nuevo_balance").
    return cantidad_a_retirar; //Retorno la cantidad de plata que saque de mi cuenta. 
}

void CuentaCorriente::mostrarInfo(){
    //Imprimo por la terminal la informacion de la cuenta:
    cout << "Nombre del titular: " << get_titularCuenta() << endl; 
    cout << "Tipo de cuenta: " << tipo_de_cuenta << endl;
    cout << "Balance de la cuenta: " << get_balance() << endl;
}