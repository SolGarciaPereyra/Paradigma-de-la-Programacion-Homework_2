#include "ejercicio_1_expresando_tiempo.hpp"

int main(){
    //Obtengo los valores para los atributos de la clase que voy a instanciar mas adelante (inciso 1i):
    int hora = obteniendo_valor_atributo("hora", 1, 12);
    int minuto = obteniendo_valor_atributo("minutos", 0, 59);
    int segundo = obteniendo_valor_atributo("segundos", 0, 59);
    string franja_h = obteniendo_franja_horaria();

    //Verifico el inciso 1a:
    Horario horario_sin_parametro;
    horario_sin_parametro.visualizar_info();

    //Verifico el inciso 1b:
    Horario horario_solo_hora(hora);
    horario_solo_hora.visualizar_info();

    //Verifico el inciso 1c:
    Horario horario_hora_minuto(hora, minuto);
    horario_hora_minuto.visualizar_info();

    //Verifico el inciso 1d:
    Horario horario_hora_minuto_segundo(hora, minuto, segundo);
    horario_hora_minuto_segundo.visualizar_info();

    //Verifico el inciso 1e y 1h:
    Horario horario_hora_minuto_segundo_franja(hora, minuto, segundo, franja_h);
    horario_hora_minuto_segundo_franja.visualizar_info();
    horario_hora_minuto_segundo_franja.visualizar_info_24h(); 

    //Verifico el inciso 1g:
    int nueva_hora = obteniendo_valor_atributo("hora", 1, 12);
    horario_hora_minuto_segundo_franja.set_horas(nueva_hora);
    cout << "La nueva hora es: " << horario_hora_minuto_segundo_franja.get_horas() << endl;

    int nuevo_minuto = obteniendo_valor_atributo("minutos", 0, 59);
    horario_hora_minuto_segundo_franja.set_minutos(nuevo_minuto);
    cout << "El nuevo minuto es: " << horario_hora_minuto_segundo_franja.get_minutos() << endl;

    int nuevo_segundo = obteniendo_valor_atributo("segundos", 0, 59);
    horario_hora_minuto_segundo_franja.set_segundos(nuevo_segundo);
    cout << "El nuevo segundo es: " << horario_hora_minuto_segundo_franja.get_segundos() << endl;

    string nueva_franja_horaria = obteniendo_franja_horaria();
    horario_hora_minuto_segundo_franja.set_franja_horaria(nueva_franja_horaria);
    cout << "El nuevo segundo es: " << horario_hora_minuto_segundo_franja.get_franja_horaria() << endl;

    return 0;
}