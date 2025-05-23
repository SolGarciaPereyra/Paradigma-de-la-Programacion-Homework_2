#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Declaro mi clase "Horario", con la que voy a trabajar para poder expresar un determiando momento en el tiempo. 
class Horario{
    /* En un principio, habia decidido hacer mis atributos publicos. Pero, cuando segui avanzando con los incisos de la consigna, 
    y llegue a la parte en la que piden "leer y cambiar" los atributos, pense que tal vez ese ejercicio estaba pensando como para
    que usemos getters y setters. Por lo que vi innecesario declarar mis atributos como publicos, para luego usar esos metodos,
    cuando simplemente podria haber hecho, por ejemplo, Horario.horas. Entonces, decidi cambiarlos a privado, para que tenga mas
    sentido el uso de esos metodos.*/
    private:
        //Declaro los atributos de mi clase:
        int horas;
        int minutos;
        int segundos;
        string franja_horaria; 
    
    //Declaro mis metodos publicos, para poder acceder a ellos desde mi main. 
    public:
        /*Declaro un constructor para mi clase, el cual me sirve para:
        1. Poder inicializar la clase sin recibir parametros (por eso defino valores default para los atributos).
        2. Poder inicializarla pasandole solo la hora como parametro.
        3. Poder inicializarla pasandole solo la hora y los minutos como parametros.
        4. Poder inicializarla pasandole solo la hora, los minutos y los segundos como parametros.
        5. Poder inicializarla pasandole parametros para cada atributo.*/
        Horario(int hora = 0, int minuto = 0, int segundo = 0, string franja = "a.m.");  //Defini valores default para mis atributos.
        
        /*A continuación, voy a declarar una serie de getters, para que se pueda leer cada atributo de forma individual (como solo leen 
        los atributos y no los modifican, los declaro const para indicar su comportamiento. Es decir, para aclarar que esos metodos no 
        modifican a los atributos). Tambien, voy a declarar un metodo que permita leer todos los atributos juntos, con el formato pedido 
        (visualizar_info) y con el formato de 24h (visualizar_info_24h).*/
        int get_horas () const;
        int get_minutos () const;
        int get_segundos () const;
        string get_franja_horaria() const;
        void visualizar_info();
        void visualizar_info_24h();

        /*Ahora, voy a declarar una serie de setters, para permitir que sea posible la modificacion de los valores de los atributos.*/
        void set_horas(int nueva_hora);
        void set_minutos(int nuevos_minutos);
        void set_segundos(int nuevos_segundos);
        void set_franja_horaria(string nueva_franja_horaria);

        //No necesito destructor porque no trabajo con punteros y en ningun lado asigno memoria de forma dinamica. 
};

/* Declaro una funcion que me permite interactuar con el programa, para poder ingresar los valores de los atributos que quiero 
mediante el teclado. Esta funcion sirve para obtener los valores de los atributos "horas", "minutos" y "segundos". 
Recibe como paramtero de entrada a:
1. atributo: es un string que tiene la intencion de indicar para que atributo se desea el valor
2. extremo_inferior_rango_permitido: indica el numero mas chico que puede valer el atributo
3. extremo_superior_rango_permitido: indica el numero mas grande que puede valer el atributo
2 y 3 delimitan el rango al que puede pertenecer el valor del atributo.*/
int obteniendo_valor_atributo(string atributo, int extremo_inferior_rango_permitido, int extremo_superior_rango_permitido);

/*Su intencion es la misma que la de la funcion "obteniendo_valor_atributo", salvo que esta sirve para poder obtener la franja horaria
deseada.*/
string obteniendo_franja_horaria();