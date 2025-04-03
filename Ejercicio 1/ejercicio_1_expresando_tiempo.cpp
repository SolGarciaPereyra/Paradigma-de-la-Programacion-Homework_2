#include "ejercicio_1_expresando_tiempo.hpp"

/*Defino mi constructor "Horario". Para hacerlo, inicializo mis atributos con una lista de inicializacion. Ademas, utilizo el
operador ternario para verificar, para cada atributo a definir, que los  alores ingresaods como parametros son validos/correctos.
Chequeo que no se introduzcan valores fuera de los rangos permititdos: horas = [1, 12], minutos = [0, 59], segundos = [0, 59], 
franja_horaria = {"a.m.", "p.m."}. De no ser valido el valor ingresado, se inicializa el atributo con el valor default correspondiente 
(0 para las horas, minutos y/o segundos; "a.m." para la franja horaria).*/
Horario::Horario(int hora, int minuto, int segundo, string franja):horas(((hora <= 12) && (hora >= 1)) ? hora : 0), minutos(((minuto <= 59) && (minuto >= 0)) ? minuto : 0), segundos(((segundo <= 59) && (segundo >= 0)) ? segundo : 0), franja_horaria(((franja == "a.m.") || (franja == "p.m.")) ? franja : "a.m."){}

int Horario::get_horas() const{ return horas;} //Para poder leer solamente el atributo horas.

int Horario::get_minutos() const{ return minutos;} //Para poder leer solamente el atributo mintuos.

int Horario::get_segundos() const{ return segundos;} //Para poder leer solamente el atributo segundos.

string Horario::get_franja_horaria() const{ return franja_horaria;} //Para poder leer solamente el atributo franja_horaria.

void Horario::visualizar_info(){
    /* Esta es la funcion que servira para leer los atributos de forma conjunta, con el formato pedido. Para lograr esto, use la
    libreria recomendada por la consigna. Uso setw para indicar que se espera 2 caracteres. Si el valor del atributo tiene menos
    de los caracteres esperados, se completa con 0 a la izquierda. Esto lo realizo mediante el uso de setfill, dentro del cual inclui
    un operador ternario ya que, por estetica, personalmente no me gusta como se veria "00h". Entoces, para el caso de que las horas,
    minutos o segundos sean iguales a 0, se le indica que rellene con un espacio vacio. De esta forma, se vera, por ejemplo, " 0h".
    El uso de setw y setfill no es necesario con la franja horaria, ya que la cantidad de caracteres que ocupa es siempre la misma.*/
    cout << setfill((horas != 0) ? '0' : ' ') << setw(2) << horas << "h, " << setfill((minutos != 0) ? '0' : ' ') << setw(2) << minutos << "m, " << setfill((segundos != 0) ? '0' : ' ') << setw(2) << segundos << "s " << franja_horaria << endl;
}

void Horario::visualizar_info_24h(){
    /*Esta funcion es casi identica a la funcion "visualizar_infor", salvo por el formato en el que presenta la informacion.
    Le sacamos el atributo "franja_horaria", ya que pasamos al formato del atributo hora de [1, 12] al de [0, 23]. En este nuevo 
    formato, ya no es necesario indicar si es "a.m." o "p.m." ya que, dependiendo del valor de la hora, se sabe si es antes del 
    mediodia (0 hasta las 11) o despues (12 hasta las 23). Para lograr el cambio en el formato, agregue un condiconal que chequea 
    si el valor original corresponde a "a.m." o "p.m.". Si corresponde a "a.m.", dejo el valor igual, excepto si hace referencia a las
    12 a.m. En ese caso, lo cambio a 0h. De lo contrario, si corresponden a horas p.m., le sumo 12 horas, salvo por las 12 p.m. En ese
    caso, lo dejo tal cual.*/
    int hora_formateada;
    if(franja_horaria == "a.m."){
        if(horas == 12){ hora_formateada = 0;}
        else{ hora_formateada = horas;}
    }
    else{
        if(horas == 12){ hora_formateada = horas;}
        else{ hora_formateada = horas + 12;}
    }

    cout << setfill((horas != 0) ? '0' : ' ') << setw(2) << hora_formateada << "h, " << setfill((minutos != 0) ? '0' : ' ') << setw(2) << minutos << "m, " << setfill((segundos != 0) ? '0' : ' ') << setw(2) << segundos << "s " << endl;
}

void Horario::set_horas(int nueva_hora){ horas = nueva_hora;} //Para poder cambiar solamente el atributo horas.

void Horario::set_minutos(int nuevos_minutos){ minutos = nuevos_minutos;} //Para poder cambiar solamente el atributo minutos.

void Horario::set_segundos(int nuevos_segundos){ segundos = nuevos_segundos;} //Para poder cambiar solamente el atributo segundos.

void Horario::set_franja_horaria(string nueva_franja_horaria){ franja_horaria = nueva_franja_horaria;} //Para poder cambiar solamente el atributo franja_horaria.

int obteniendo_valor_atributo(string atributo, int extremo_inferior_rango_permitido, int extremo_superior_rango_permitido){
    //Permito que se pueda ingresar el valor del atriuto mediante el teclado:
    int valor_ingresado;
    cout << "Ingrese el valor de " << atributo << " deseado: ";
    cin >> valor_ingresado;

    /*Chequeo que el valor ingresado pertenezca al rango permitido. De no ser asi, se le pide al usuario que vuelva a ingresar otro
    valor o, si desea, eligir salir del programa mediante el ingreso del numero -1 (eleccion arbitraria). En el caso de seguir ingresando
    incorrectamente el valor, se le va a seguir pidiendo ingresar uno nuevo hasta que lo haga o hasta que eliga terminar el programa.*/
    while((valor_ingresado < extremo_inferior_rango_permitido)|| (valor_ingresado > extremo_superior_rango_permitido)){
        cout << "El valor ingresado no es valido, por favor ingresar otro (si desea salir del programa ingrese el numero -1): ";
        cin >> valor_ingresado;
        
        if(valor_ingresado == -1){ exit(1);}  //Chequeo si el usuario eligio salir del programa.
    }

    return valor_ingresado;
}

string obteniendo_franja_horaria(){
    //Permito que se pueda ingresar la franja horaria mediante el teclado:
    string franja_ingresada;
    cout << "Ingrese si desea que el horario sea a.m. o p.m.: ";
    cin >> franja_ingresada;

    /*Chequeo que la franja ingresada pertenezca a las opciones permitidas. De no ser asi, se le pide al usuario que vuelva a ingresar 
    otra franja o, si desea, eligir salir del programa mediante el ingreso de la palabra "SALIR" (eleccion arbitraria). En el caso de 
    seguir ingresando incorrectamente la franja, se le va a seguir pidiendo ingresar una nueva hasta que lo haga o hasta que eliga 
    terminar el programa.*/
    while((franja_ingresada != "a.m.") && (franja_ingresada != "p.m.")){
        cout << "La franja ingresada no es valida, por favor ingresar otra (si desea salir del programa ingrese la palabra SALIR): ";
        cin >> franja_ingresada;
        
        if(franja_ingresada == "SALIR"){ exit(1);}  //Chequeo si el usuario eligio salir del programa.
    }

    return franja_ingresada;
}