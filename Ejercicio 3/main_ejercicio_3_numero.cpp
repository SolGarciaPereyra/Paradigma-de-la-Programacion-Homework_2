#include "ejercicio_3_numero.hpp"

int main(){
    //Verifico la clase Entero:
    //Defino las variables que voy a usar para las operaciones:
    unique_ptr<Numero> numero_al_que_aplico_operaciones_entero = make_unique<Entero>(10);
    unique_ptr<Numero> numero_suma_entero = make_unique<Entero>(2);
    unique_ptr<Numero> numero_resta_entero = make_unique<Entero>(4);
    unique_ptr<Numero> numero_multiplicacion_entero = make_unique<Entero>(3);
    unique_ptr<Numero> numero_division_entero = make_unique<Entero>(5);
    //Realizo las operaciones e imprimo los resultados:
    cout << "Nuestro numero es: " << numero_al_que_aplico_operaciones_entero->toString() << endl;
    cout << "Si le sumo " << numero_suma_entero->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_entero->suma(*numero_suma_entero))->toString() << endl;
    cout << "Si le resto " << numero_resta_entero->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_entero->resta(*numero_resta_entero))->toString() << endl;
    cout << "Si lo multiplico por " << numero_multiplicacion_entero->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_entero->multiplicacion(*numero_multiplicacion_entero))->toString() << endl;
    cout << "Si lo divido por " << numero_division_entero->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_entero->division(*numero_division_entero))->toString() << endl;
    cout << endl; //Lo hago porque quiero dejar una linea en blanco en la terminal, para separar secciones.

    //Verifico la clase Real:
    //Defino las variables que voy a usar para las operaciones:
    unique_ptr<Numero> numero_al_que_aplico_operaciones_real = make_unique<Real>(10.5);
    unique_ptr<Numero> numero_suma_real = make_unique<Real>(2.5);
    unique_ptr<Numero> numero_resta_real = make_unique<Real>(4.5);
    unique_ptr<Numero> numero_multiplicacion_real = make_unique<Real>(2);
    unique_ptr<Numero> numero_division_real = make_unique<Real>(5.2);
    //Realizo las operaciones e imprimo los resultados:
    cout << "Nuestro numero es: " << numero_al_que_aplico_operaciones_real->toString() << endl;
    cout << "Si le sumo " << numero_suma_real->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_real->suma(*numero_suma_real))->toString() << endl;
    cout << "Si le resto " << numero_resta_real->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_real->resta(*numero_resta_real))->toString() << endl;
    cout << "Si lo multiplico por " << numero_multiplicacion_real->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_real->multiplicacion(*numero_multiplicacion_real))->toString() << endl;
    cout << "Si lo divido por " << numero_division_real->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_real->division(*numero_division_real))->toString() << endl;
    cout << endl; //Lo hago porque quiero dejar una linea en blanco en la terminal, para separar secciones.

    //Verifico la clase Complejo:
    //Defino las variables que voy a usar para las operaciones:
    unique_ptr<Numero> numero_al_que_aplico_operaciones_complejo = make_unique<Complejo>(3, 5);
    unique_ptr<Numero> numero_suma_complejo = make_unique<Complejo>(2, 7);
    unique_ptr<Numero> numero_resta_complejo = make_unique<Complejo>(1, 6);
    unique_ptr<Numero> numero_multiplicacion_complejo = make_unique<Complejo>(4, 3);
    unique_ptr<Numero> numero_division_complejo = make_unique<Complejo>(8, 2);
    //Realizo las operaciones e imprimo los resultados:
    cout << "Nuestro numero es: " << numero_al_que_aplico_operaciones_complejo->toString() << endl;
    cout << "Si le sumo " << numero_suma_complejo->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_complejo->suma(*numero_suma_complejo))->toString() << endl;
    cout << "Si le resto " << numero_resta_complejo->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_complejo->resta(*numero_resta_complejo))->toString() << endl;
    cout << "Si lo multiplico por " << numero_multiplicacion_complejo->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_complejo->multiplicacion(*numero_multiplicacion_complejo))->toString() << endl;
    cout << "Si lo divido por " << numero_division_complejo->toString() << " obtendremos el valor: " << (numero_al_que_aplico_operaciones_complejo->division(*numero_division_complejo))->toString() << endl;
    cout << endl; //Lo hago porque quiero dejar una linea en blanco en la terminal, para separar secciones.
    
    return 0;
}