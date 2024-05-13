#ifndef MYBINARYTREE_HPP
#define MYBINARYTREE_HPP
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <iostream>
using namespace std;
using namespace miotest;
namespace miotest{

    void testBinaryTree()
    {
        try
        {
            lasd::Vector<string> vec(13);
           
            vec[0]=string("A");
            vec[1]=string("B");
            vec[2]=string("C");
            vec[3]=string("D");
            vec[4]=string("E");
            vec[5]=string("F");
            vec[6]=string("G");
            vec[7]=string("H");
            lasd::BinaryTreeLnk<string> btlnk(vec);

            
            cout<<"btlnk"<<endl;
            MapPreOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapInOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapPostOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapBreadth(btlnk, &MapPrint<string>);
            cout<<endl;
            lasd::BinaryTreeVec<string> btvec(move(vec));
            cout<<"btvec"<<endl;
            MapPreOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapInOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapPostOrder(btvec, &MapPrint<string>);
            cout<<endl;
            MapBreadth(btvec, &MapPrint<string>);
            btvec.Clear();
            vec[0]=string("A");
            vec[1]=string("B");
            vec[2]=string("C");
            vec[3]=string("D");
            vec[4]=string("E");
            vec[5]=string("F");
            vec[6]=string("G");
            vec[7]=string("H");
            vec[8]=string("I");
            lasd::BinaryTreeVec btvec2(vec);
            btvec=(move(btvec2));
            cout<<endl<<"btvec pt2"<<endl;
            MapBreadth(btvec, &MapPrint<string>);
            cout<<endl<<" breadth iterator"<<endl;
            lasd::BTBreadthMutableIterator<string> itr1(btlnk);
            while(!itr1.Terminated()){
                cout<<itr1.operator*()<<" ";
                ++itr1;
            }

            cout<<endl<<" post order iterator"<<endl;
            lasd::BTPostOrderMutableIterator<string> itr2(btlnk);
            // while(!itr2.Terminated()){
            //     cout<<itr2.operator*()<<" ";
            //     ++itr2;
            // }
            cout<<endl<<"pre order mutable iterator"<<endl;
            lasd::BTPreOrderMutableIterator<string> itr3(btlnk);
            while(!itr3.Terminated()){
                cout<<itr3.operator*()<<" ";
                ++itr3;
            }
            cout<<endl<<"in order mutable iterator"<<endl;
            lasd::BTInOrderMutableIterator<string> itr4(btlnk);
            while(!itr4.Terminated()){
                cout<<itr4.operator*()<<" ";
                ++itr4;
            }
            lasd::BTInOrderMutableIterator<string> itr5(itr4);
            itr5.Reset();
            cout<<endl<<"In Order Mutable iterator creato con una copy(primo elemento dopo il reset):"<<endl<<itr5.operator*()<<endl;
            lasd::BTPreOrderMutableIterator<string> itr6(move(itr3));
            itr6.Reset();
            cout<<"Pre Order Mutable Iterator creato con una move(primo elemento dopo il reset):"<<endl<<itr6.operator*()<<endl;

            cout << ((itr5==itr4) ? "I due iteratori sono uguali" : "I due iteratori sono diversi") << "!" << endl;
        }
        catch (exception &exc)
        {
            cout << exc.what() << endl;
        }
    }
}

#endif