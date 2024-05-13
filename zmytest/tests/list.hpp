#ifndef MYLIST_HPP
#define MYLIST_HPP

/* ************************************************************************** */
#include "../../list/list.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <random>
using namespace std;
using namespace miotest;
void listInt()
{

    cout << "--------------TEST LIST INT--------------" << endl;

    unsigned long size, value;
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(1, 1000);
    try
    {
        lasd::List<int> lista;

        cout << "Inserisci la nuova dimensione della lista: ";
        cin >> size;

        for (unsigned long i = 0; i <= size; i++)
        {
            lista.InsertAtFront(dist(gen));
        }

        cout << "Front Pre-remove: " << lista.Front() << endl;
        lista.RemoveFromFront();
        cout << "Front Post-Remove: " << lista.Front() << endl;
        cout << "Eseguo 20 Remove from front" << endl;
        for (unsigned long i = 0; i <= 20; i++)
        {
            lista.RemoveFromFront();
        }

        cout << "Valore di Front:" << lista.Front() << endl;
        cout << "Incremento  tutti i nodi con MapPreOrder" << endl;
        MapPreOrder(lista, &MapIncrement<int>);
        cout << "Valore di Front:" << lista.Front() << endl;
        cout << "Inserisci un valore da cercare nella lista: ";
        cin >> value;

        cout << ((lista.Exists(value)) ? "Il valore " + to_string(value) + " e' presente" : "il valore " + to_string(value) + " non e' presente") << "!" << endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
}
void listDouble()
{
    cout << "--------------TEST LIST DOUBLE--------------" << endl;
    unsigned long size;
    default_random_engine gen(random_device{}());
    uniform_real_distribution<double> dist(1, 1000);
    try
    {
        lasd::List<double> lista;

        cout << "Inserisci la nuova dimensione della lista: ";
        cin >> size;

        for (unsigned long i = 0; i <= size; i++)
        {
            lista.InsertAtFront(dist(gen));
        }
        cout << "Front Pre-remove: " << lista.Front() << endl;
        lista.RemoveFromFront();
        cout << "Front Post-Remove: " << lista.Front() << endl;
        cout << "Eseguo 300 insert in coda" << endl;
        for (unsigned long i = 0; i <= 300; i++)
        {
            lista.InsertAtBack(dist(gen));
        }
        cout << "Eseguo 200 Remove from front" << endl;

        for (unsigned long i = 0; i <= 200; i++)
        {
            lista.RemoveFromFront();
        }

        FoldPostOrder(lista, &FoldAdd<double>, 0.32);
    }
    catch (exception &exc)
    {
        cout << exc.what() << endl;
    }
}
void listString()
{
    cout << "--------------TEST LIST STRING--------------" << endl;
    std::mt19937 mt(std::random_device{}());
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);
    std::string randomString;
    unsigned long size, index;
    try
    {
        lasd::List<string> lista;

        cout << "Inserisci una dimensione: ";
        cin >> size;

        for (unsigned long i = 0; i < size; i++)
        {
            randomString = characters[dist(mt)];
            lista.InsertAtFront(randomString);
        }

        cout << "Front attuale:" << lista.Front() << endl;
        FoldPostOrder(lista, &FoldAdd<string>, string(""));
        lista.RemoveFromFront();
        FoldPreOrder(lista, &FoldAdd<string>, string(""));
        cout << "Inserisci un indice: ";
        cin >> index;

        cout << "Value: " << lista.operator[](index) << endl;
    }
    catch (exception &exc)
    {
        cout << exc.what() << endl;
    }
}

/* ************************************************************************** */
#endif