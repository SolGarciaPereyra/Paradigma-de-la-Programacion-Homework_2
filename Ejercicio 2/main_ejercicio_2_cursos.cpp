#include "ejercicio_2_cursos.hpp"

int main(){
    //Creo 2 vectores, en los cuales voy a ir llevando registro de los objetos "Curso" y "Estudiante" que el usuario decida ir creando.
    vector<shared_ptr<Curso>> cursos_creados; 
    vector<shared_ptr<Estudiante>> estudiantes_creados; 
    //Tambien creo un objeto "Legajo" para llevar registro de los legajos que se fueron creanod:
    Legajo legajos_registro;

    /*El 1 (en el valor de la variable de abajo) fue elegido arbitrariamente. Me paso que si lo dejaba sin valor (int eleccion_del_usuario;),
    cuando corria el programa, terminaba al instante, sin ofrecerme el menu de opciones. Osea que nunca entraba al bucle. Entonces,
    supuse que se debia que "int eleccion_del_usuario;" era equivalente a "int eleccion_del_usuario = 0;". Por lo tanto, probe igualandolo
    a cualquier numero diferente a 0, y recien ahi me anduvo (me aparecio el menu de opciones y me dejo seleccionar las opciones que queria).*/
    int eleccion_del_usuario = 1;
    while(eleccion_del_usuario != 0){
        cout << "~~~~~ Bienvenidos a gestion.udesa ~~~~~" << endl;
        cout << endl;
        cout << "0. Salir del programa" << endl;
        cout << "1. Crear un curso" << endl;
        cout << "2. Crear un curso, realizando una copia de un curso ya existente" << endl;
        cout << "3. Crear un estudiante" << endl;
        cout << "4. Inscribir a un estudiante a un curso" << endl;
        cout << "5. Chequear si un estudiante se encuentra inscripto a un curso" << endl;
        cout << "6. Desinscribir a un estudiante de un curso" << endl;
        cout << "7. Chequear si un curso alcanzo su capacidad maxima" << endl;
        cout << "8. Imprimir la lista de estudiantes pertenecientes a un curso" << endl;
        cout << "9. Calcular el promedio general de un estudiante" << endl;
        cout << endl;
        cout << "Indique la opcion que desea realizar: ";
        cin >> eleccion_del_usuario;

        switch(eleccion_del_usuario){
            case 0: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            case 1: {
                string nombre_curso_elegido;
                cout << "Indicar el nombre del curso nuevo: ";
                //Para que cin lea el nombre completo (y no pare de leer al encontrarse con el primer espacio en blanco) hacemos:
                cin.ignore(); //Esto hace que se pueda saltear el "/n", causado por el usuario cuando toco la tecla "enter/return", y que getline sea capaz de leer la linea completa. 
                getline(cin, nombre_curso_elegido); 
                cursos_creados.push_back(make_shared<Curso>(nombre_curso_elegido));
                cout << endl;
                break;
            } 
            case 2: {
                //Primero hay que saber a cual curso el usuario quiere copiar:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso al que desea copiar: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;

                //Ahora creo un nuevo curso, usando el constructor de copia con el curso original:
                shared_ptr<Curso> curso_nuevo_copia = make_shared<Curso>(*cursos_creados[posicion_del_curso]);
                //Le cambio el nombre al nuevo curso:
                string nuevo_nombre;
                cout << "Indicar el nombre del curso nuevo: ";
                //Para que cin lea el nombre completo (y no pare de leer al encontrarse con el primer espacio en blanco) hacemos:
                cin.ignore(); //Esto hace que se pueda saltear el "/n", causado por el usuario cuando toco la tecla "enter/return", y que getline sea capaz de leer la linea completa. 
                getline(cin, nuevo_nombre); 
                curso_nuevo_copia->nombre_del_curso = nuevo_nombre;

                //Lo agrego a la lista de cursos creados:
                cursos_creados.push_back(curso_nuevo_copia);
                cout << "Se ha creado y copiado de manera exitosa el nuevo curso, llamado " << curso_nuevo_copia->nombre_del_curso << "." << endl;
                break;
            }
            case 3: {
                string nombre_estudiante_elegido;
                cout << "Indicar el nombre completo del nuevo estudiante: ";
                //Para que cin lea el nombre completo (y no pare de leer al encontrarse con el primer espacio en blanco) hacemos:
                cin.ignore(); //Esto hace que se pueda saltear el "/n", causado por el usuario cuando toco la tecla "enter/return", y que getline sea capaz de leer la linea completa. 
                getline(cin, nombre_estudiante_elegido); 

                int legajo;
                cout << "Ingrese el legajo del estudiante nuevo: ";
                cin >> legajo;
                
                //Chequeo que el legajo del estudiante sea unico:
                shared_ptr<Estudiante> estudiante_nuevo = make_shared<Estudiante>(nombre_estudiante_elegido, legajo);
                int chequeando_existencia_legajo = legajos_registro.agregar_legajo_estudiante(legajo, estudiante_nuevo);
                if(chequeando_existencia_legajo == 0){
                    estudiantes_creados.push_back(estudiante_nuevo);
                    cout << "El nuevo estudiante fue creado de manera exitosa.";
                }
                else{
                    cout << "Ya existe un estudiante con el legajo ingresado, por lo que no se creo el nuevo estudiante. Vuelva a intentarlo, eligiendo otro legajo.";
                }

                cout << endl;
                break;
            }
            case 4: {
                //Primero hay que saber a cual curso el usuario quiere inscribir al estudiante:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso al que desea inscribir al estudiante: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;

                //Ahora, hay que saber a que estudiante desea inscribir: 
                int posicion_del_estudiante;
                cout << "Ingrese el indice del estudiante al que desea inscribir al curso: " << endl;
                //Le imprimo las opciones existentes de estudiantes:
                for(int index = 0; index < static_cast<int>(estudiantes_creados.size()); index++){
                    cout << index << ": " << estudiantes_creados[index]->get_nombre_completo() << endl;
                }
                cin >> posicion_del_estudiante;
                
                //Ahora que conocemos tanto el curso como el estudiante, agregamos el ultimo al primero:
                cursos_creados[posicion_del_curso]->inscribirse_al_curso(estudiantes_creados[posicion_del_estudiante]);
                //Agregamos el curso a la lista de cursos del estudiante. Para eso, necesitamos una nota para el estudiante:
                float nota_final_curso;
                cout << "Ingrese la nota final que desea darle al estudiante en ese curso: ";
                cin >> nota_final_curso;
                estudiantes_creados[posicion_del_estudiante]->agregar_curso_con_nota_final(nota_final_curso, cursos_creados[posicion_del_curso]);
                
                cout << endl;
                break;
            }
            case 5: {
                //Primero hay que saber el curso en el que el usuario esta interesado:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso en el que desea chequear si se encuentra el estudiante: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;

                //Ahora, hay que saber el legajo del estudiante que esta buscando:
                int legajo_estudiante_buscado;
                cout << "Indique el legajo del estudiante que desea buscar: ";
                cin >> legajo_estudiante_buscado;

                //Ahora nos fijamos si esta inscripto o no:
                cursos_creados[posicion_del_curso]->estudiante_inscripto_o_no(legajo_estudiante_buscado);

                cout << endl;
                break;
            }
            case 6: {
                //Primero hay que saber a cual curso el usuario quiere desinscribir al estudiante:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso al que desea desinscribir al estudiante: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;
                
                //Ahora, hay que saber a que estudiante desea desinscribir: 
                int posicion_del_estudiante;
                cout << "Ingrese el indice del estudiante al que desea desinscribir al curso: " << endl;
                //Le imprimo las opciones existentes de estudiantes:
                for(int index = 0; index < static_cast<int>(estudiantes_creados.size()); index++){
                    cout << index << ": " << estudiantes_creados[index]->get_nombre_completo() << endl;
                }
                cin >> posicion_del_estudiante;

                //Desinscribimos al estudiante:
                cursos_creados[posicion_del_curso]->desinscribirse_al_curso(estudiantes_creados[posicion_del_estudiante]);

                cout << endl;
                break;
            }
            case 7: {
                //Primero hay que saber el curso en el que el usuario esta interesado:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso al que desea revisar su capacidad: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;

                cursos_creados[posicion_del_curso]->curso_completo_o_no();

                cout << endl;
                break;
            }
            case 8: {
                //Primero hay que saber el curso en el que el usuario esta interesado en conocer la lista de estudiantes:
                int posicion_del_curso;
                cout << "Ingrese el indice del curso al que se le desea imprimir la lista de estudiantes: " << endl;
                //Le imprimo las opciones existentes de cursos:
                for(int posicion = 0; posicion < static_cast<int>(cursos_creados.size()); posicion++){
                    cout << posicion << ": " << cursos_creados[posicion]->nombre_del_curso << endl;
                }
                cin >> posicion_del_curso;

                cursos_creados[posicion_del_curso]->imprimir_lista_estudiantes();

                cout << endl;
                break;
            }
            case 9: {
                //Primero hay que saber el estuiante en el que el usuario esta interesado:
                int posicion_del_estudiante;
                cout << "Ingrese el indice del estudiante al que se le desea calcular el promedio general: " << endl;
                //Le imprimo las opciones existentes de estudiantes:
                for(int index = 0; index < static_cast<int>(estudiantes_creados.size()); index++){
                    cout << index << ": " << estudiantes_creados[index]->get_nombre_completo() << endl;
                }
                cin >> posicion_del_estudiante;

                //Calculo el promedio general del estudiante:
                estudiantes_creados[posicion_del_estudiante]->calcular_promedio_general();
                cout << "El promedio general de " << estudiantes_creados[posicion_del_estudiante]->get_nombre_completo() << " es " << estudiantes_creados[posicion_del_estudiante]->get_promedio_general() << "." << endl;

                cout << endl;
                break;
            }
            default:
                cout << "La opcion indicada no es valida. Si desea, intente de nuevo, ingresando una opcion valida.";      
        }
    };

    return 0;
}