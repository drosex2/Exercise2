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

            // btlnk.Root()=new NodeLnk
            // btlnk.Root().LeftChild().Element()=string("B");
            // btlnk.Root().RightChild().Element()=string("C");
            // btlnk.Root().LeftChild().LeftChild().Element()=string("D");
            // btlnk.Root().LeftChild().RightChild().Element()=string("E");
            // btlnk.Root().RightChild().LeftChild().Element()=string("F");
            // btlnk.Root().LeftChild().LeftChild().LeftChild().Element()=string("G");
            // btlnk.Root().LeftChild().LeftChild().RightChild().Element()=string("H");
            // btlnk.Root().LeftChild().RightChild().LeftChild().Element()=string("I");
            // btlnk.Root().RightChild().LeftChild().LeftChild().Element()=string("J");
            // btlnk.Root().RightChild().LeftChild().RightChild().Element()=string("K");
            // btlnk.Root().LeftChild().LeftChild().RightChild().LeftChild().Element()=string("N");
            // btlnk.Root().RightChild().LeftChild().RightChild().LeftChild().Element()=string("L");
            // btlnk.Root().RightChild().LeftChild().RightChild().RightChild().Element()=string("M");

            cout<<endl;
            MapPreOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapInOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapPostOrder(btlnk, &MapPrint<string>);
            cout<<endl;
            MapBreadth(btlnk, &MapPrint<string>);
        }
        catch (exception &exc)
        {
            cout << exc.what() << endl;
        }
    }
}

#endif