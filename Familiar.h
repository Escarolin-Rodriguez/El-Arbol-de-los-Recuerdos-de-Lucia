#pragma once
#include <string>
#include <vector>

struct Persona {
    std::string nombre;
    std::string fechaNacimiento;
    std::string relacion;

    Persona* primerHijo;
    Persona* siguienteHermano;

    // Constructor para inicializar los datos de la persona
    Persona(std::string nom, std::string fecha, std::string rel) {
        nombre = nom;
        fechaNacimiento = fecha;
        relacion = rel;
        primerHijo = nullptr;
        siguienteHermano = nullptr;
    }
};

class ArbolGenealogico {
public:
    Persona* raiz;

    ArbolGenealogico() {
        // Inicializamos a Lucía como la matriarca y raíz del árbol
        raiz = new Persona("Lucia", "1956-01-01", "Matriarca");
    }

    // Función recursiva para buscar a una persona por su nombre
    Persona* buscar(Persona* nodo, std::string nombreBuscar) {
        if (nodo == nullptr) return nullptr;
        if (nodo->nombre == nombreBuscar) return nodo;

        // Busca primero en sus hijos
        Persona* encontrado = buscar(nodo->primerHijo, nombreBuscar);
        if (encontrado != nullptr) return encontrado;

        // Si no lo encuentra, busca en sus hermanos
        return buscar(nodo->siguienteHermano, nombreBuscar);
    }

    // Función para insertar un nuevo familiar debajo de su padre/madre
    bool insertar(std::string padreNombre, std::string nom, std::string fecha, std::string rel) {
        Persona* padre = buscar(raiz, padreNombre);
        if (padre == nullptr) return false; // Si el padre no existe, no se puede insertar

        Persona* nuevo = new Persona(nom, fecha, rel);

        // Si el padre no tiene hijos, este es su primer hijo
        if (padre->primerHijo == nullptr) {
            padre->primerHijo = nuevo;
        }
        else {
            // Si ya tiene hijos, buscamos al último hermano para ponerlo al lado
            Persona* temp = padre->primerHijo;
            while (temp->siguienteHermano != nullptr) {
                temp = temp->siguienteHermano;
            }
            temp->siguienteHermano = nuevo;
        }
        return true; // Insertado con éxito
    }

    // Función recursiva para calcular cuántas generaciones hay en total (altura del árbol)
    int calcularGeneraciones(Persona* nodo) {
        if (nodo == nullptr) return 0;
        int maxHijos = 0;
        Persona* hijo = nodo->primerHijo;
        while (hijo != nullptr) {
            int alt = calcularGeneraciones(hijo);
            if (alt > maxHijos) maxHijos = alt;
            hijo = hijo->siguienteHermano;
        }
        return 1 + maxHijos;
    }

    // Función recursiva para contar cuántos descendientes tiene Lucía en total
    int contarDescendientes(Persona* nodo) {
        if (nodo == nullptr) return 0;
        int conteo = 0;
        Persona* hijo = nodo->primerHijo;
        while (hijo != nullptr) {
            conteo += 1 + contarDescendientes(hijo);
            hijo = hijo->siguienteHermano;
        }
        return conteo;
    }

    // Función auxiliar para recolectar los descendientes en una lista
    void recolectarDescendientes(Persona* nodo, std::vector<Persona*>& lista) {
        if (nodo == nullptr) return;
        Persona* hijo = nodo->primerHijo;
        while (hijo != nullptr) {
            lista.push_back(hijo);
            recolectarDescendientes(hijo, lista);
            hijo = hijo->siguienteHermano;
        }
    }
};