#include <iostream>
#include <string>
using namespace std;

//Declaro mi clase "Horario", con la que voy a trabajar para poder expresar un determiando momento en el tiempo. 
class Horario{
    public:
        //Declaro los atributos de mi clase:
        int horas;
        int minutos;
        int segundos;
        string franja_horaria; 

        /*Declaro un constructor para mi clase, el cual me sirve para:
        1. Poder inicializar la clase sin recibir parametros (por eso defino valores default para los atributos).
        2. Poder inicializarla pasandole solo la hora como parametro.
        3. Poder inicializarla pasandole solo la hora y los minutos como parametros.
        4. Poder inicializarla pasandole solo la hora, los minutos y los segundos como parametros.
        5. Poder inicializarla pasandole parametros para cada atributo.*/
        Horario(int hora = 0, int minuto = 0, int segundo = 0, string franja = "a.m.");  //Defini valores default para mis atributos.
        
        //Declaro un metodo que me servira para mostrar los valores de los atributos de la clase, por la terminal.
        void visualizar_info();

};