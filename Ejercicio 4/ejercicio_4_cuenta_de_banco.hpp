#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*Explicacion para el inciso 4a:
En la clase abstracta "Cuenta Bancaria", decidi declarar los atributos como private ya que estos son datos muy importantes, a los cuales
no cualquiera deberia tener acceso. Hay que ser cuidadosos a la hora de modificar esa informacion. Es por esto que declare a set_balance,
get_balance y get_titularCuenta como protected, ya que asegura que los cambios esten controlados y que no cualquiera pueda conocer esa
informacion. Al mismo tiempo, a diferencia de si hubieran sido private, me permite que las subclases (CajaDeAhorros y CuentaCorriente)
puedan acceder a esos metodos dentro de sus configuraciones. Si hubiera declarado todos los metodos como private (bajo el pretexto de que,
por ejemplo, no cualquiera deberia poder retirar plata o establacer el balance de la cuenta), las subclases no hubieran podido tener
acceso a ellos, sin importar el tipo de herencia, limitando su funcionalidad. El unico que declare como public fue a depositar, ya que me evita tener que declarar una
funcion/metodo dentro de las subclases, solamente para que pueda invocar al metodo y asi poder aprovechar su funcion.
Esto ultimo me lleva a mencionar el por que en mi eleccion del tipo de herencia. Elegi usar herencia public ya que, si hubiera elegido 
protected, depositar seria heredado como protected, lo que haria mi justificacion a la hora de decidir declaralo como public en 
CuentaBancaria como innecesaria. Esto se debe a que tendria que hacer lo que habia dicho que intentaba ahorrarme: declarar funciones en 
las subclases solamente para poder usar ese metodo (me ahorro codigo de esta forma).
Finalmente, dentro de ambas subclases declare tanto a los atributos extra y a los metodos como public, ya que me permite poder invocarlos
desde mi main. */

//Declaro mi clase abstracta:
class CuentaBancaria{
    private:
        //Declaro los atributos exigidos por la consigna:
        double balance;
        string titularCuenta;

    protected:
        CuentaBancaria(double cantidad_balance, string nombre_del_titular); //Declaro mi constructor
        string get_titularCuenta(); //Declaro un getter para poder acceder al valor del atributo titularCuenta en mis subclases.
        double get_balance(); //Declaro un getter para poder acceder al valor del atributo balance en mis subclases.
        void set_balance(double nuevo_balance); //Declaro un setter para poder modificar el valor del atributo balance en mis subclases.
        //Declaro los metodos exigidos por la consigna:
        virtual double retirar(double cantidad_a_retirar) = 0;
        virtual void mostrarInfo() = 0;

    public:
        void depositar(double dinero_a_depositar);
};

//Declaro mis dos subclases:
class CajaDeAhorro: public CuentaBancaria{
    public:
        string tipo_de_cuenta = "Caja de Ahorro";  //Lo voy a usar a la hora de mostrar la informacion de la cuenta.
        int conteo_mostrarInfo = 0;  //Me sirve para llevar registro de cuantas veces el usuario pidio ver los detalles de la cuenta.

        CajaDeAhorro(double balance_de_cuenta, string nombre_titular); //Declaro mi constructor
        double retirar(double cantidad_a_retirar) override;
        void mostrarInfo() override;

        friend class CuentaCorriente;
};

class CuentaCorriente: public CuentaBancaria{
    public:
        string tipo_de_cuenta = "Cuenta Corriente"; //Lo voy a usar a la hora de mostrar la informacion de la cuenta.
        shared_ptr<CajaDeAhorro> titular_CajaDeAhorro_puntero; //Lo necesito para poder trabajar con la caja de ahorros en la funcion retirar.

        CuentaCorriente(double balance_de_cuenta, string nombre_titular);
        void set_CajaDeAhorro(shared_ptr<CajaDeAhorro> caja_de_ahorro_puntero);
        double retirar(double cantidad_a_retirar) override;
        void mostrarInfo() override;
};