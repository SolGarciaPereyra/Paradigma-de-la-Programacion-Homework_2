#include <iostream>
#include <string>
#include <memory>
using namespace std;

//Declaro mi interfaz Numero:
class Numero{
    public:
        //Declaro los metodos virtuales puros exigidos por la consigna:
        virtual unique_ptr<Numero> suma(Numero& numero_que_le_sumo) = 0;
        virtual unique_ptr<Numero> resta(Numero& numero_que_le_resto) = 0;
        virtual unique_ptr<Numero> multiplicacion(Numero& numero_multiplicativo) = 0;
        virtual unique_ptr<Numero> division(Numero& numero_divisor) = 0;
        virtual string toString() = 0;

        virtual ~Numero() = default; //Declaro mi destructor 
};

//Declaro las clases que van a implementar la interfaz Numero, exigidas por la consigna:
/*Las 3 clases van a tener herencia publica por parte de la interfaz, para poder usar los metodos de esta ultima desde mi main. 
Estos metodos van a ser declarados usando la palabra "override" para indicar que se esta sobrescribiendo un metodo virtual pertenecinete
a, en este caso, la interfaz.*/
class Entero: public Numero{
    private:
        int valor; 

    //Declaro mis metodos publicos, para poder acceder a ellos desde mi main.
    public:
        Entero(int valor); //Defino mi constructor
        unique_ptr<Numero> suma(Numero& numero_que_le_sumo) override;
        unique_ptr<Numero> resta(Numero& numero_que_le_resto) override;
        unique_ptr<Numero> multiplicacion(Numero& numero_multiplicativo) override;
        unique_ptr<Numero> division(Numero& numero_divisor) override;
        string toString() override;

        ~Entero() override = default; //Defino mi destructor
};

class Real: public Numero{
    private:
        double valor;

    //Declaro mis metodos publicos, para poder acceder a ellos desde mi main.
    public:
        Real(double valor); //Defino mi constructor
        unique_ptr<Numero> suma(Numero& numero_que_le_sumo) override;
        unique_ptr<Numero> resta(Numero& numero_que_le_resto) override;
        unique_ptr<Numero> multiplicacion(Numero& numero_multiplicativo) override;
        unique_ptr<Numero> division(Numero& numero_divisor) override;
        string toString() override;

        ~Real() override = default; //Defino mi destructor
};

class Complejo: public Numero{
    private:
        /*Hay que acordarnos que un numero imaginario posee una parte real y otra imaginaria. Entonces, establezco un atributo diferente
        para cada parte, para poder realizar adecuadamente las operaciones.*/
        double parte_real;
        double parte_imaginaria;

    //Declaro mis metodos publicos, para poder acceder a ellos desde mi main.
    public:
        Complejo(double parte_real_, double parte_imaginaria_); //Defino mi constructor
        unique_ptr<Numero> suma(Numero& numero_que_le_sumo) override;
        unique_ptr<Numero> resta(Numero& numero_que_le_resto) override;
        unique_ptr<Numero> multiplicacion(Numero& numero_multiplicativo) override;
        unique_ptr<Numero> division(Numero& numero_divisor) override;
        string toString() override;

        ~Complejo() override = default; //Defino mi destructor
};