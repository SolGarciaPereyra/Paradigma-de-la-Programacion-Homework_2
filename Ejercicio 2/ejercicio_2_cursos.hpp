#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*Aclaracion: no agrego destructores a mis clases porque no me hacen falta. Estoy tabajando con smart pointers, los cuales manejan su
uso de memoria de forma independiente. Es decir, no necesito liberar la memoria manualmente, ya que ellos mismo lo hacen cuando se deja
de usarlos.*/

/*Respuesta al inciso 2c: 
Yo describiria a la relacion entre los objetos "Curso" y "Estudiante" como una relacion de agregacion. Ambos objetos pueden existir de 
manera independiente: los estudiantes pueden estar asociados (inscriptos) tanto a multiples cursos, como a ninguno, y aun asi existir.
Lo mismo sucede con los cursos, los cuales pueden tener inscriptos multiples estudiantes, o ninguno, y aun asi exisitir. Aun asi, "Curso"
y "Estudiantes" estan estrechamente relacionados, mas que en una simple asociacion, pero no poseen "ownership" exclusivo sobre el otro.*/

class Estudiante; //Lo decalro antes que curso, para poder usarlo en este ultimo.

//Declaro algunas funciones que me van a ser utiles para el inciso 2biv:
ostream& operator<<(ostream& os, const Estudiante& estudiante);
ostream& operator<<(ostream& os, const shared_ptr<Estudiante>& estudiante);
bool comparar_estudiantes_alfabeticamnete(const shared_ptr<Estudiante>& estudiante, const shared_ptr<Estudiante>& estudiante_a_comparar);

class Curso{
    protected:
        vector<shared_ptr<Estudiante>> lista_estudiantes;

    public:
        string nombre_del_curso;

        Curso(string nombre_del_curso_); //Defino mi constructor
        void inscribirse_al_curso(shared_ptr<Estudiante> estudiante_a_inscribirse_puntero);
        void desinscribirse_al_curso(shared_ptr<Estudiante> estudiante_a_desinscribirse_puntero);
        void estudiante_inscripto_o_no(int legajo_estudiante);
        void curso_completo_o_no();
        void imprimir_lista_estudiantes(); 

        //Para el inciso 2bv:
        Curso(const Curso& curso_que_copio); //Realizo una sobrecarga del constructor, pero este va a realizar la copia del curso.
};

//Declaro ua class adicional llamada "Legajo", para poder llevar registro de todos los legajos existentes y asegurarme que no hayan dos estudiantes con el mismo legajo.
class Legajo{ 
    private:
        vector<pair<int, shared_ptr<Estudiante>>> registro_legajos_y_estudiantes;

    public:
        int agregar_legajo_estudiante(int legajo_nuevo, shared_ptr<Estudiante> estudiante_puntero);
};

class Estudiante{
    //Declaro el nombre y legajo del estudiante como private ya que, una vez establecidos, no tengo intencion de cambiarlos.
    private:
        string nombre_completo;
        int legajo;
        float promedio_general;

    protected:
        vector<pair<float, shared_ptr<Curso>>> cursos_con_notas_finales; //Uso pair para guardar en el vector cada nota final del curso con el nombre de este ultimo, de forma asociada.
    
    public:
        Estudiante(string nombre_completo_estudiante, int legajo_estudiante); //Defino mi constructor
        string get_nombre_completo() const;
        int get_legajo() const;
        void agregar_curso_con_nota_final(float nota_final, shared_ptr<Curso> puntero_curso);
        void calcular_promedio_general();
        float get_promedio_general();
        void eliminar_curso_con_nota_final(string nombre_curso_a_eliminar);
        //Declaro la funcion que va a sobreescribir al operador "<":
        bool operator<(const Estudiante& estudiante_a_comparar) const;

        friend ostream& operator<<(ostream& os, const Estudiante& estudiante);
};