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
        
        /*A continuación, voy a declarar una serie de getters, para que se pueda leer cada atributo de forma individual. Tambien, voy a
        declarar un metodo que permita leer todos los atributos juntos, con el formato pedido (visualizar_info) y con el formato de 24h
        (visualizar_info_24h).*/
        int get_horas();
        int get_minutos();
        int get_segundos();
        string get_franja_horaria();
        void visualizar_info();
        void visualizar_info_24h();

        /*Ahora, voy a declarar una serie de setters, para permitir que sea posible la modificacion de los valores de los atributos.*/
        void set_horas(int nueva_hora);
        void set_minutos(int nuevos_minutos);
        void set_segundos(int nuevos_segundos);
        void set_franja_horaria(string nueva_franja_horaria);
};