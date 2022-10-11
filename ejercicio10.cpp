/* 10) Dada una lista simple de alumnos (n° de documento y nombre) ordenada por documento. De
cada alumno depende una sublista de exámenes rendidos (fecha, código y nota). Hacer una
función que dada la estructura informe número de documento, nombre y promedio de cada
alumno.*/

#include <iostream>
#include <string.h>

using namespace std;

struct Examen
{
  int fecha, codMat, nota;
};

struct NodoSL
{
  Examen info;
  NodoSL *sig;
};

struct Alumno
{
  int dni;
  string nom;
  NodoSL *subListaExa;
};

struct NodoL
{
  Alumno info;
  NodoL *sig;
};

void generarLista(NodoL *&lista);
NodoL *buscarInsertar(NodoL *&lista, Alumno al);
void insertar(NodoSL *&lista, Examen ex);
void ej10(NodoL *&lista);

int main()
{
  NodoL *listaAlumnos = NULL;
  generarLista(listaAlumnos);
  ej10(listaAlumnos);
  return 0;
}

void ej10(NodoL *&lista)
{
  NodoL *p = lista;
  NodoSL *q;

  while (p != NULL)
  {
    cout << "Alumno: " << p->info.nom << endl;
    cout << "DNI: " << p->info.dni << endl;

    int sumaNotas = 0, cantNotas = 0, promedio;
    q = p->info.subListaExa;
    while (q != NULL)
    {
      sumaNotas += q->info.nota;
      cantNotas++;
      q = q->sig;
    }

    promedio = sumaNotas / cantNotas;
    cout << "Promedio: " << promedio << endl;
    p = p->sig;
  }
}

void generarLista(NodoL *&lista)
{
  Alumno alu;
  Examen exa;
  NodoL *p;

  cout << "DNI alumno: ";
  cin >> alu.dni;
  while (alu.dni != 0) // ingresa datos del examen
  {
    cout << "Nombre alumno: ";
    cin >> alu.nom;
    cout << "Fecha examen: ";
    cin >> exa.fecha;
    cout << "Codigo materia rendida: ";
    cin >> exa.codMat;
    cout << "Nota: ";
    cin >> exa.nota;

    alu.subListaExa = NULL;
    p = buscarInsertar(lista, alu);

    insertar(p->info.subListaExa, exa);

    cout << "DNI alumno: ";
    cin >> alu.dni;
  }
}

NodoL *buscarInsertar(NodoL *&lista, Alumno al)
{
  NodoL *ant, *p = lista;
  while (p != NULL && p->info.dni < al.dni)
  {
    ant = p;
    p = p->sig;
  }
  if (p != NULL && al.dni == p->info.dni)
    return p;
  else
  {
    NodoL *n = new NodoL;
    n->info = al;
    n->sig = p;
    if (p != lista)
      ant->sig = n;
    else
      lista = n;
    return n;
  }
}

void insertar(NodoSL *&lista, Examen ex) // ordenado por fecha
{
  NodoSL *n, *p, *ant;
  n = new NodoSL;
  n->info = ex;
  p = lista;
  while (p != NULL && p->info.fecha < ex.fecha)
  {
    ant = p;
    p = p->sig;
  }
  n->sig = p;
  if (p != lista)
    ant->sig = n;
  else
    lista = n;
}