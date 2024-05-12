#ifndef MYBINARYSEARCHTREE_HPP
#define MYBINARYSEARCHTREE_HPP
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../bst/bst.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <iostream>
#include <random>

using namespace std;


namespace miotest{

    void testBinarySearchTree(){
        unsigned long value;
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> dist(1, 1000);
        try
        {
            lasd::BST<int> bst1;
            for (unsigned long i = 0; i <= 100; i++)
            {
                bst1.Insert(dist(gen));
            }
            cout<<"Ottieni il minimo: ";
            int min=bst1.Min();
            cout<<min<<endl;
            cout<<"Rimuovi il minimo"<<endl;
            bst1.RemoveMin();
            cout<<"Ottieni e rimuovi il nuovo minimo: ";
            min=bst1.MinNRemove();
            cout<<min<<endl;

            lasd::BST<int> bst2(bst1);
            lasd::BST<int> bst3(move(bst1));

            if(bst2==bst3){
                cout<<"bst2 è uguale a bst3"<<endl;
            }

            cout<<"Ottieni il massimo (da bst2): ";
            int max=bst2.Max();
            cout<<max<<endl;
            cout<<"Rimuovi il massimo"<<endl;
            bst2.RemoveMax();
            cout<<"Ottieni e rimuovi il nuovo massimo: ";
            max=bst2.MaxNRemove();
            cout<<max<<endl;

            value=dist(gen);
            cout << ((bst2.Exists(value)) ? "Il valore " + to_string(value) + " e' presente" : "il valore " + to_string(value) + " non e' presente") << "!" << endl;

            cout<<"Ottieni il predecessore di "<<value<<": ";
            int predecessor=bst2.Predecessor(value);
            cout<<predecessor<<endl;
            cout<<"Rimuovi il predecessore"<<endl;
            bst2.RemovePredecessor(value);
            cout<<"Ottieni e rimuovi il nuovo predecessore: ";
            predecessor=bst2.PredecessorNRemove(value);
            cout<<predecessor<<endl;

            value=dist(gen);

            cout<<"Ottieni il successore di "<<value<<": ";
            int successor=bst2.Successor(value);
            cout<<successor<<endl;
            cout<<"Rimuovi il successore"<<endl;
            bst2.RemoveSuccessor(value);
            cout<<"Ottieni e rimuovi il nuovo successore: ";
            successor=bst2.SuccessorNRemove(value);
            cout<<successor<<endl;


            cout<<"Inserimento (con move) di un elemento: ";
            value=dist(gen);
            cout << ((bst2.Insert(value)) ? "Il valore " + to_string(move(value)) + " e' stato inserito" : "il valore " + to_string(move(value)) + "e' presente, non e' stato inserito") << "!" << endl;
            cout<<"Inserimento di un elemento già presente: ";
            cout << ((bst2.Insert(value)) ? "Il valore " + to_string(value) + " e' stato inserito" : "il valore " + to_string(value) + " e' presente, non e' stato inserito") << "!" << endl;

            cout<<"Rimozione di un elemento: ";
            value=dist(gen);
            cout << ((bst2.Remove(value)) ? "Il valore " + to_string(move(value)) + " e' stato rimosso" : "il valore " + to_string(move(value)) + " non e' presente, non e' stato rimosso") << "!" << endl;

            cout<<endl<<"Pre Order Iterator: "<<endl;
            lasd::BTPreOrderIterator<int> itr1(bst2);
            while(!itr1.Terminated()){
                cout<<itr1.operator*()<<" ";
                ++itr1;
            }
            cout<<endl<<"In Order Iterator: "<<endl;
            lasd::BTInOrderIterator<int> itr2(bst2);
            while(!itr2.Terminated()){
                cout<<itr2.operator*()<<" ";
                ++itr2;
            }
             cout<<endl<<"Post Order Iterator: "<<endl;
            lasd::BTPostOrderIterator<int> itr3(bst2);
            // while(!itr3.Terminated()){
            //     cout<<itr3.operator*()<<" ";
            //     ++itr3;
            // }
            cout<<endl<<"Breadth Iterator: "<<endl;
            lasd::BTBreadthIterator<int> itr4(bst2);
            while(!itr4.Terminated()){
                cout<<itr4.operator*()<<" ";
                ++itr4;
            }

            bst2.Clear();
            cout<<endl<<"Dimensione di bst2 dopo la clear: "<<bst2.Size()<<endl;
            cout<<endl;

        }catch(exception& exc){
            cout<<exc.what()<<endl;
        }

    }


}
#endif