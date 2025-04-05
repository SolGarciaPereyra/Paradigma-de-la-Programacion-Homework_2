#include "ejercicio_3_numero.hpp"

/*Aclaracion: en todos los metodos usados para realizar las operaciones, comienzo creando un "raw pointer" ya que, en un principio, queria usar
dynamic_cast con un unique<ptr> en vez del "raw pointer", pero no me lo permitia. Entonces, pense en crear el "raw pointer" para poder usar el 
dynamic_cast de la forma en la que se que se podia usar, trabajar con el numero para poder realizar la operacion matematica necesaria, y luego 
devolver el resultado en un "unique pointer". */

//Entero:
Entero::Entero(int valor): valor(valor) {}
//Sobrescribo los metodos de la interfaz Numero para mi clase Entero:

unique_ptr<Numero> Entero::suma(Numero& numero_que_le_sumo){  
    Entero* numero_que_le_sumo_entero = dynamic_cast<Entero*>(&numero_que_le_sumo);
    /*Gracias al polimorfismo, puedo crear un unique pointer Entero con el resultado de la suma de Enteros, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Entero> resultado_entero = make_unique<Entero>(valor + numero_que_le_sumo_entero->valor); //Realizo la suma y a su resultado lo guardo en un unique pointer.
    return resultado_entero;
}

unique_ptr<Numero> Entero::resta(Numero& numero_que_le_resto){
    Entero* numero_que_le_resto_entero = dynamic_cast<Entero*>(&numero_que_le_resto);
    /*Gracias al polimorfismo, puedo crear un unique pointer Entero con el resultado de la resta de Enteros, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Entero> resultado_entero = make_unique<Entero>(valor - numero_que_le_resto_entero->valor); //Realizo la resta y a su resultado lo guardo en un unique pointer.
    return resultado_entero;
}

unique_ptr<Numero> Entero::multiplicacion(Numero& numero_multiplicativo){
    Entero* numero_multiplicativo_entero = dynamic_cast<Entero*>(&numero_multiplicativo);
    /*Gracias al polimorfismo, puedo crear un unique pointer Entero con el resultado de la multiplicacion de Enteros, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Entero> resultado_entero = make_unique<Entero>(valor * numero_multiplicativo_entero->valor); //Realizo la multiplicacion y a su resultado lo guardo en un unique pointer.
    return resultado_entero;
}

unique_ptr<Numero> Entero::division(Numero& numero_divisor){
    Entero* numero_divisor_entero = dynamic_cast<Entero*>(&numero_divisor);

    //Chequeo que el numero que voy a usar para dividir no sea igual a cero, para que no haya errores al hacer la cuenta.
    if(numero_divisor_entero->valor == 0){
        cout << "No se pueden dividr los numeros ingresados. Saliendo del programa." << endl;
        exit(1);
    }

    /*Gracias al polimorfismo, puedo crear un unique pointer Entero con el resultado de la division de Enteros, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Entero> resultado_entero = make_unique<Entero>(valor / numero_divisor_entero->valor); //Realizo la division y a su resultado lo guardo en un unique pointer.
    return resultado_entero;
}

string Entero::toString(){
    return to_string(valor);
}

//Real:
Real::Real(double valor): valor(valor) {}
//Sobrescribo los metodos de la interfaz Numero para mi clase Real:

unique_ptr<Numero> Real::suma(Numero& numero_que_le_sumo){
    Real* numero_que_le_sumo_real = dynamic_cast<Real*>(&numero_que_le_sumo);
    /*Gracias al polimorfismo, puedo crear un unique pointer Real con el resultado de la suma de Reales, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Real> resultado_real = make_unique<Real>(valor + numero_que_le_sumo_real->valor); //Realizo la suma y a su resultado lo guardo en un unique pointer.
    return resultado_real;
}

unique_ptr<Numero> Real::resta(Numero& numero_que_le_resto){
    Real* numero_que_le_resto_real = dynamic_cast<Real*>(&numero_que_le_resto);
    /*Gracias al polimorfismo, puedo crear un unique pointer Real con el resultado de la resta de Reales, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Real> resultado_real = make_unique<Real>(valor - numero_que_le_resto_real->valor); //Realizo la resta y a su resultado lo guardo en un unique pointer.
    return resultado_real;
}

unique_ptr<Numero> Real::multiplicacion(Numero& numero_multiplicativo){
    Real* numero_multiplicativo_real = dynamic_cast<Real*>(&numero_multiplicativo);
    /*Gracias al polimorfismo, puedo crear un unique pointer Real con el resultado de la multiplicacion de Reales, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Real> resultado_real = make_unique<Real>(valor * numero_multiplicativo_real->valor); //Realizo la multiplicacion y a su resultado lo guardo en un unique pointer.
    return resultado_real; 
}

unique_ptr<Numero> Real::division(Numero& numero_divisor){
    Real* numero_divisor_entero = dynamic_cast<Real*>(&numero_divisor);

    //Chequeo que el numero que voy a usar para dividir no sea igual a cero, para que no haya errores al hacer la cuenta.
    if(numero_divisor_entero->valor == 0){
        cout << "No se pueden dividr los numeros ingresados. Saliendo del programa." << endl;
        exit(1);
    }

    /*Gracias al polimorfismo, puedo crear un unique pointer Real con el resultado de la division de Reales, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Real> resultado_real = make_unique<Real>(valor / numero_divisor_entero->valor); //Realizo la division y a su resultado lo guardo en un unique pointer.
    return resultado_real;
}

string Real::toString(){
    return to_string(valor);
}

//Complejo:
Complejo::Complejo(double parte_real_, double parte_imaginaria_): parte_real(parte_real_), parte_imaginaria(parte_imaginaria_) {}
//Sobrescribo los metodos de la interfaz Numero para mi clase Complejo:

unique_ptr<Numero> Complejo::suma(Numero& numero_que_le_sumo){
    Complejo* numero_que_le_sumo_complejo = dynamic_cast<Complejo*>(&numero_que_le_sumo);
    /*Gracias al polimorfismo, puedo crear un unique pointer Complejo con el resultado de la suma de Complejos, y se me convierte
    implicitamente en un unique pointer Numero. La suma entre numeros complejos consiste en sumar la parte real de un numero con
    la del otro, y la parte imaginaria de un numero con la del otro.*/ 
    unique_ptr<Complejo> resultado_complejo = make_unique<Complejo>(parte_real + numero_que_le_sumo_complejo->parte_real, parte_imaginaria + numero_que_le_sumo_complejo->parte_imaginaria); //Realizo la suma y a su resultado lo guardo en un unique pointer.
    return resultado_complejo;
}

unique_ptr<Numero> Complejo::resta(Numero& numero_que_le_resto){
    Complejo* numero_que_le_resto_complejo = dynamic_cast<Complejo*>(&numero_que_le_resto);
    /*Gracias al polimorfismo, puedo crear un unique pointer Complejo con el resultado de la resta de Complejos, y se me convierte
    implicitamente en un unique pointer Numero. La resta entre numeros complejos consiste en restar la parte real de un numero con
    la del otro, y la parte imaginaria de un numero con la del otro.*/ 
    unique_ptr<Complejo> resultado_entero = make_unique<Complejo>(parte_real - numero_que_le_resto_complejo->parte_real, parte_imaginaria - numero_que_le_resto_complejo->parte_imaginaria); //Realizo la resta y a su resultado lo guardo en un unique pointer.
    return resultado_entero;
}

unique_ptr<Numero> Complejo::multiplicacion(Numero& numero_multiplicativo){
    Complejo* numero_multiplicativo_complejo = dynamic_cast<Complejo*>(&numero_multiplicativo);
    /*La multiplicacion entre numeros complejos se realiza de la siguiente manera:
    Siendo z1 = (a + bi) y z2 = (c + di), la multiplicacion entre z1 y z2 es igual a: (a + bi)(c + di).
    Luego de usar las distributiva para resolver esa multiplicacion, nos quedamos con que z1*z2 = ac + adi + bci + bdi^2
    De ese resultados podemos notar que:
    1. ac y -bd son partes reales
    2. adi + bci lo podemos reescribir sacando factor comun de "i", obteniendo (ad + bc)i, lo que es parte imaginaria
    Entonces, podemos calcular la multiplicacion entre numeros complejos de la siguiente forma:
    Parte real = (z1_parte_real * z2_parte_real) - (z1_parte_imaginaria * z2_parte_imaginaria)
    Parte imaginaria = (z1_parte_real * z2_parte_imaginaria) + (z1_parte_imaginaria * z2_parte_real)
    En este caso, z1 es el numero declarado en el main y z2 es "numero_multiplicativo_complejo".
    Por lo tanto, procedo a calcular la parte real e imaginaria del resultado: */
    double parte_real_ = (parte_real * numero_multiplicativo_complejo->parte_real) - (parte_imaginaria * numero_multiplicativo_complejo->parte_imaginaria);
    double parte_imaginaria_ = (parte_real * numero_multiplicativo_complejo->parte_imaginaria) + (parte_imaginaria * numero_multiplicativo_complejo->parte_real);
    /*Gracias al polimorfismo, puedo crear un unique pointer Complejo con el resultado de la multiplicacion de Complejos, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Complejo> resultado_complejo = make_unique<Complejo>(parte_real_, parte_imaginaria_); 
    return resultado_complejo; 
}

unique_ptr<Numero> Complejo::division(Numero& numero_divisor){
    Complejo* numero_divisor_complejo = dynamic_cast<Complejo*>(&numero_divisor);
    /*La division entre numeros complejos se realiza de la siguiente manera:
    Siendo z1 = (a + bi) y z2 = (c + di), para poder realizar la division entre ellos, hay que multiplicar tanto el numerador como el denominador por el conjugado
    del denominador. Es decir, siendo el numerador (a + bi) y el denominador (c + di), multiplicamos ambos por (c - di). Luego de resolver ambas partes por separado,
    aplicando la propiedad distributiva, nos quedamos con que el numerador es [(ac + bd) + (bc - ad)i] y el denominador es (c^2 + d^2). Ahora, si dividimos la
    fraccion en parte imaginaria y parte real, nos encontramos con que:
    Parte real = (ac + bd)/(c^2 + d^2)
    Parte imaginaria = (bc - ad)/(c^2 + d^2)
    Esto es igual a:
    Parte real = ((z1_parte_real * z2_parte_real) + (z1_parte_imaginaria * z2_parte_imaginaria))/(z2_parte_real^2 + z2_parte_imaginaria^2)
    Parte imaginaria = ((z1_parte_imaginaria * z2_parte_real) - (z1_parte_real * z2_parte_imaginaria))/(z2_parte_real^2 + z2_parte_imaginaria^2)
    En este caso, z1 es el numero declarado en el main y z2 es "numero_divisor_complejo".
    Por lo tanto, procedo a calcular la parte real e imaginaria del resultado: 
    Antes de hacer eso, chequeo que el denominador no sea cero: */
    double denominador = (numero_divisor_complejo->parte_real * numero_divisor_complejo->parte_real) + (numero_divisor_complejo->parte_imaginaria * numero_divisor_complejo->parte_imaginaria);
    if(denominador == 0){
        cout << "No se pueden dividr los numeros ingresados. Saliendo del programa." << endl;
        exit(1);
    }

    double parte_real_ = ((parte_real * numero_divisor_complejo->parte_real) + (parte_imaginaria * numero_divisor_complejo->parte_imaginaria)) / denominador;
    double parte_imaginaria_ = ((parte_imaginaria * numero_divisor_complejo->parte_real) + (parte_real * numero_divisor_complejo->parte_imaginaria)) / denominador; 
    /*Gracias al polimorfismo, puedo crear un unique pointer Complejo con el resultado de la division de Complejos, y se me convierte
    implicitamente en un unique pointer Numero.*/ 
    unique_ptr<Complejo> resultado_real = make_unique<Complejo>(parte_real_, parte_imaginaria_);
    return resultado_real;
}

string Complejo::toString(){
    //Comienzo a construir el numero imaginario en un string, para luego devolverlo.
    /*Para saber si el signo de la parte imaginaria es + o -, tengo que fijarme si la parte imaginaria es mayor o igual a cero (+), o si es 
    menor a cero (-). Para lograr esto, utilizo un operador ternario dentro de la concatenacion. Hago esto para darle al numero complejo 
    un formato string a la hora de mostrarlo por la terminal.
    Para no tener una contradiccion de signos con el que agregue anteriormente, si el valor de la parte imaginaria es negativo, cuando 
    concateno este valor, hay que invertirle su signo. Para eso, uso otro operador ternario: si la parte imagianria es mayor o igual a 
    cero, uso el valor tal cual en to_string. Pero, si el valor es menor a cero, como ya inclui en el string su simbolo mediante el uso
    del primer operador ternario, le invierto el signo al valor de esta parte. Logro esto agregando un menos adelante del valor, dentro del
    to_string.*/
    string complejo_a_string = "(" + to_string(parte_real) + ((parte_imaginaria < 0) ? " - " : " + ") + ((parte_imaginaria < 0) ? to_string(-parte_imaginaria) : to_string(parte_imaginaria)) + "i)";
    return complejo_a_string;
}