#include "ejercicio_2_cursos.hpp"

//Algunas de las funciones/metodos que necesito para cumplir con el inciso 2biv:
//Sobreescribo el operador "<<":
//Paso el segundo parametro como const para indicar que la funcion no tiene intencion de modificar ni al puntero ni al objeto, solo leer su informacion.
ostream& operator<<(ostream& os, const Estudiante& estudiante){
    os << "Nombre del estudiante: " << estudiante.get_nombre_completo() << ", Legajo: " << to_string(estudiante.get_legajo());
    return os; 
}

ostream& operator<<(ostream& os, const shared_ptr<Estudiante>& estudiante){
    /*Declaro esta funcion ya que, cuando imprima "lista_estudiantes", no voy a poder pasar sus elementos directamente como parametros 
    de entrada a la funcion que defini arriba (ya que estos son smart pointers). Entonces, uso primero esta funcion para desreferenciar el smart pointer "estudiante", y
    dentro de esta funcion uso la de arriba para imprimri el objeto Estudiante.*/
    os << *estudiante;
    return os; 
}

/*En la funcion "imprimir_lista_estudiantes", cuando uso sort() tengo la intencion de ordenar los objetos Estudiantes. Pero, mi lista
contiene punteros a esos objetos. Entonces, para que sort pueda hacer su trabajo correctamente, defino esta funcion que le permite 
ordenar esos punteros, al comparar los nombres de los estudiantes a los que apuntan esos smart pointers.*/
bool comparar_estudiantes_alfabeticamnete(const shared_ptr<Estudiante>& estudiante, const shared_ptr<Estudiante>& estudiante_a_comparar){
    //Si se cumple la desigualdad, devuelve true. De lo contrario, devuelve false.
    return *estudiante < *estudiante_a_comparar; //Uso la sobrecarga del operador "<" que defini en la clase Estudiante.
}

//Defino los metodos de la clase "Curso":
Curso::Curso(string nombre_del_curso_): nombre_del_curso(nombre_del_curso_) {}

void Curso::inscribirse_al_curso(shared_ptr<Estudiante> estudiante_a_inscribirse_puntero){
    if(static_cast<int>(lista_estudiantes.size()) < 20){ //Chequeo que no se pase de la capacidad establecida por la consigna. 
        lista_estudiantes.push_back(estudiante_a_inscribirse_puntero); //Inscribo al estudiante en el curso (lo agrego al final de la "lista")
    }
    else{
        cout << "No se ha podido inscribir al estudiante en el curso, ya que este posee su capacidad maxima de estudiantes." << endl;
    }
}

void Curso::desinscribirse_al_curso(shared_ptr<Estudiante> estudiante_a_desinscribirse_puntero){
    for(int posicion = 0; posicion < static_cast<int>(lista_estudiantes.size()); posicion++){
        //Chequeo que los legajos sean iguales y no sus nombres, porque la consigna aclara que los legajos son unicos para cada estudiante, pero no necesariamente sus nombres.
        if(lista_estudiantes[posicion]->get_legajo() == estudiante_a_desinscribirse_puntero->get_legajo()){
            //Antes de eliminar al estudiante de la lista del curso, elimino el curso de la lista de clases del estudiante.
            lista_estudiantes[posicion]->eliminar_curso_con_nota_final(nombre_del_curso);
            //Ahora elimino al estudiante de la lista del curso.
            lista_estudiantes.erase(lista_estudiantes.begin() + posicion);
            break;
        }
    }
}

void Curso::estudiante_inscripto_o_no(int legajo_estudiante){
    bool encontrado = false; 

    for(int posicion = 0; posicion < static_cast<int>(lista_estudiantes.size()); posicion++){
        //Chequeo que los legajos sean iguales:
        if(lista_estudiantes[posicion]->get_legajo() == legajo_estudiante){
            cout << "El estudiante con legajo " << to_string(legajo_estudiante) << " se encuentra inscripto en el curso " << nombre_del_curso << "." << endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        cout << "El estudiante con legajo " << to_string(legajo_estudiante) << " no se encuentra inscripto en el curso " << nombre_del_curso << "." << endl;
    }
};

void Curso::curso_completo_o_no(){
    int nivel_capacidad_curso = static_cast<int>(lista_estudiantes.size());
    //Chequeo si la capacidad actual del curso supera o no el limite establecido por la consigna (capacidad maxima = 20):
    if(nivel_capacidad_curso < 20){
        cout << "El curso " << nombre_del_curso << " no se encuentra completo. Aun es posible inscribir a nuevos alumnos." << endl;
    }
    else{
        cout << "El curso " << nombre_del_curso << " se encuentra completo. Ya no es posible inscribir a nuevos alumnos." << endl;
    }
};

void Curso::imprimir_lista_estudiantes(){
    if(static_cast<int>(lista_estudiantes.size()) == 0){
        cout << "No hay estudiantes inscriptos a este curso." << endl;
    }
    else{
        sort(lista_estudiantes.begin(), lista_estudiantes.end(), comparar_estudiantes_alfabeticamnete); //Ordeno a los estudiantes alfabeticamente

        /*Ahora, imprimo los estudiantes utilizando el metodo con el que sobreescribi el operador "<<" para smart pointers (el cual
        internamente invoca al otro metodo que escribi para sobreescribir el operador "<<"):*/
        for(int posicion = 0; posicion < static_cast<int>(lista_estudiantes.size()); posicion++){
            cout << lista_estudiantes[posicion] << endl;
        }
    }
};

/*Esta sobrecarga del constructor realiza un "shallow copy" al curso ya existente. Decidi usar este tipo de copia ya que, como 
"lista_estudiantes" es un vector conformado por smart pointers (mas especificamente shared pointers), esto permite que dos
cursos puedan compartir a sus estudiantes, sin necesidad de duplicarlos. Por lo que, al usar "shallow copy", me permite que cada 
estudiante siga "existiendo" una unica vez en mi memoria. Si hubiera elegido hacer "deep copy", estaria duplicando innecesariamente 
a los estudiantes. Ademas, al usar shared pointers me permite hacer "shallow copy" sin tener que preocuparme por problemas de 
doble borrado o "dangling pointers", ya que estos punteros manejan de forma independiente, automatica y segura su memoria y el conteo de 
referencias.*/
Curso::Curso(const Curso& curso_que_copio): nombre_del_curso(curso_que_copio.nombre_del_curso), lista_estudiantes(curso_que_copio.lista_estudiantes) {}

//Defino los metodos de la clase "Legajo":
int Legajo::agregar_legajo_estudiante(int legajo_nuevo, shared_ptr<Estudiante> estudiante_puntero){
    if(static_cast<int>(registro_legajos_y_estudiantes.size()) == 0){ //Es el primer estudiante que agrego/existe
        registro_legajos_y_estudiantes.push_back(make_pair(legajo_nuevo, estudiante_puntero));
        return 0;
    }
    else{ //Ya existen otros objetos estudiantes
        for(int posicion = 0; posicion < static_cast<int>(registro_legajos_y_estudiantes.size()); posicion++){
            //En el caso de que el legajo que se quiere usar con el nuevo estudiante, ya haya sido elegido por otro.
            if(registro_legajos_y_estudiantes[posicion].first == legajo_nuevo){ 
                return 1;
            }
        }
        //Ninguno de los estudiantes ya existentes posee ese numero de legajo:
        registro_legajos_y_estudiantes.push_back(make_pair(legajo_nuevo, estudiante_puntero));
        return 0;
    }
}

//Defino los metodos de la clase "Estudiante":
Estudiante::Estudiante(string nombre_completo_estudiante, int legajo_estudiante): nombre_completo(nombre_completo_estudiante), legajo(legajo_estudiante) {}

string Estudiante::get_nombre_completo() const{ return nombre_completo;}

int Estudiante::get_legajo() const{ return legajo;}

void Estudiante::agregar_curso_con_nota_final(float nota_final, shared_ptr<Curso> puntero_curso){
    cursos_con_notas_finales.push_back(make_pair(nota_final, puntero_curso)); //Agrego al final de la "lista" el nuevo curso con su nota final correspondiente
}

void Estudiante::calcular_promedio_general(){
    //Declaro y defino las variables que voy a necesitar para poder calcular el promedio general del estudiante.
    int cantidad_cursos_inscripto = static_cast<int>(cursos_con_notas_finales.size());
    float sumatoria_notas_finales = 0;

    //Calculo el valor de sumatoria_notas_fianles:
    for(int posicion = 0; posicion < cantidad_cursos_inscripto; posicion++){
        sumatoria_notas_finales = sumatoria_notas_finales + cursos_con_notas_finales[posicion].first;
    }

    //Calculo el promedio general:
    if(cantidad_cursos_inscripto != 0){
        float promedio_general_calculado = sumatoria_notas_finales / cantidad_cursos_inscripto; //Aplico la formula del promedio
        promedio_general = promedio_general_calculado; //Actualizo el valor del atributo "promedio_general"
    }
    else{
        promedio_general = 0; //En el caso de que no este inscripto a ningun curso
    }
}

float Estudiante::get_promedio_general(){ return promedio_general;}

void Estudiante::eliminar_curso_con_nota_final(string nombre_curso_a_eliminar){
    for(int posicion = 0; posicion < static_cast<int>(cursos_con_notas_finales.size()); posicion++){
        if(cursos_con_notas_finales[posicion].second->nombre_del_curso == nombre_curso_a_eliminar){
            //Elimino el curso de la lista de notas del estudiante:
            cursos_con_notas_finales.erase(cursos_con_notas_finales.begin() + posicion);
            //Actualizo el nuevo promedio general del estudiante:
            calcular_promedio_general();
            break;
        }
    }
}

//Sobreescribo el operador "<":
bool Estudiante::operator<(const Estudiante& estudiante_a_comparar) const{
    //Si se cumple la desigualdad, devuelve true. De lo contrario, devuelve false. 
    return nombre_completo < estudiante_a_comparar.nombre_completo;  
}
