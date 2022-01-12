/* Leandro Lara <llaras1@est.eups.edu.ec>
 * Estructura de datos
 * Arbol con cadena de caracteres (string)
 * 11-01-2022
 */

#include <iostream>
#include <string>

using namespace std;

//crear una estructura (Nodo)
struct Nodo{
    string dato;
    Nodo *izq;
    Nodo *der;
};

//Creacion del arbol
Nodo *crearNodo(string dato){
    Nodo *nuevoNodo=new Nodo();
    nuevoNodo->dato=dato;
    nuevoNodo->izq=NULL;
    nuevoNodo->der=NULL;
    return nuevoNodo;
}

Nodo *arbol=NULL;

void insertarNodo(Nodo *&arbol, string dato){
    //verificar si la etructura esta vacia
    if(arbol==NULL){
        Nodo *nuevoNodo=crearNodo(dato);// asigna a nuevoNodo un nodo
        arbol=nuevoNodo; //arbol sera nuevoNodo
    }else{ //caso contrario
        string datoRaiz=arbol->dato; //el primer dato sera Raiz (padre)
        if(dato<datoRaiz){ //compara dato con raiz
            insertarNodo(arbol->izq,dato); //
        }else{
            insertarNodo(arbol->der,dato);
        }
    }
}

void mostrarNodo(Nodo *arbol,int contador){
    if(arbol==NULL){
        return;
    }else{
        mostrarNodo(arbol->der,contador+1);
        for(int i=0;i<contador;i++){
            cout<<"  ";
        }
        cout<<arbol->dato<<"\n";
        mostrarNodo(arbol->izq,contador+1);
    }
}

bool buscarNodo(Nodo *arbol,string dato){
    if(arbol==NULL){
        return false;
    }else{
        if(dato==arbol->dato){
            return true;
        }else if(dato<arbol->dato){
            return buscarNodo(arbol->izq,dato);
        }else{
            return buscarNodo(arbol->der,dato);
        }
    }
}

void preOrden(Nodo *arbol){
    if(arbol==NULL){
        return ;
    }else{
        cout <<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Nodo *arbol){
    if(arbol==NULL){
        return ;
    }else{
        inOrden(arbol->izq);
        cout <<arbol->dato<<" ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol){
    if(arbol==NULL){
        return ;
    }else{
        inOrden(arbol->izq);
        inOrden(arbol->der);
        cout <<arbol->dato<<" ";
    }
}

int main()
{
    int opc,contador=0;
    string dato, datoBuscar;
    do{
        cout<<"\n +++ Arbol string +++\n";
        cout<<"\n 1. Insertar dato\n";
        cout<<" 2. Mostrar datos\n";
        cout<<" 3. Mostrar pre-orden\n";
        cout<<" 4. Mostrar in-orden\n";
        cout<<" 5. Mostrar post-orden\n";
        cout<<" 6. Buscar datos\n";
        cout<<" 7. Salir\n";
        cout<<" Ingrese su opcion: ";
        cin>>opc;
        switch(opc){
        case 1:
            cout<<" Ingreso de datos\n";
            cout<<" Ingrese una palabra: ";
            cin>>dato;
            insertarNodo(arbol,dato);
            break;
        case 2:
            cout<<" Demostracion de datos\n";
            mostrarNodo(arbol,contador);
            break;
        case 3:
            cout<<" Mostrar pre-orden\n";
            preOrden(arbol);
            break;
        case 4:
            cout<<" Mostrar pre-orden\n";
            inOrden(arbol);
            break;
        case 5:
            cout<<" Mostrar pre-orden\n";
            postOrden(arbol);
            break;
        case 6:
            cout<<" Buscando dato\n";
            cout<<" Palabra a buscar: ";
            cin>>datoBuscar;
            if(buscarNodo(arbol,datoBuscar)){
                cout<<" Dato encontado: "<<datoBuscar<<"\n";
            }else{
                cout<<" Dato no encontrado: "<<datoBuscar<<"\n";
            }
            break;
        case 7:
            cout<<" Hasta la proxima\n";
            break;
        default:
            cout<<" Opcion incorrecta, intente de nuevo.\n";
            break;
        }
    }while(opc!=7);
    return 0;
}
