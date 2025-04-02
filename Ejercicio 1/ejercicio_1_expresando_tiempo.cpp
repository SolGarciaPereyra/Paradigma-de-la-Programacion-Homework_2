#include "ejercicio_1_expresando_tiempo.hpp"

/*Defino mi constructor "Horario". Para hacerlo, inicializo mis atributos con una lista de inicializacion. Ademas, utilizo el
operador ternario para verificar, para cada atributo a definir, que los  alores ingresaods como parametros son validos/correctos.
Chequeo que no se introduzcan valores fuera de los rangos permititdos: horas = [0, 23], minutos = [0, 59], segundos = [0, 59], 
franja_horaria = {"a.m.", "p.m."}. De no ser valido el valor ingresado, se inicializa el atributo con el valor default correspondiente 
(0 para las horas, minutos y/o segundos; "a.m." para la franja horaria).*/
Horario::Horario(int hora, int minuto, int segundo, string franja):horas(((hora <= 23) && (hora >= 0)) ? hora : 0), minutos(((minuto <= 59) && (minuto >= 0)) ? minuto : 0), segundos(((segundo <= 59) && (segundo >= 0)) ? segundo : 0), franja_horaria(((franja == "a.m.") || (franja == "p.m.")) ? franja : "a.m."){}

void Horario::visualizar_info(){

}