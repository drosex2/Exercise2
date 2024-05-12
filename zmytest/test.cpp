
// #include "..."
#include <iostream>

#include "tests/list.hpp"
#include "tests/vector.hpp"
#include "tests/queue.hpp"
#include "tests/stack.hpp"
#include "tests/binarytree.hpp"
#include "tests/bst.hpp"
#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include <random>
/* ************************************************************************** */

using namespace std;
using namespace miotest;

/* ************************************************************************** */

void mytest() {
    cout<<"WELCOME TO MY TEST!"<<endl;
    // cout << "--------------TEST LIST--------------" << endl;
    // listInt();
    // listDouble();
    // listString();
    // cout << "--------------TEST VECTOR--------------" << endl;
    // vectorInt();
    // vectorDouble();
    // vectorString();
    // cout << "--------------TEST STACK--------------" << endl;
    // stackVecInt();
    // stackLstInt();
    // stackVecDouble();
    // stackLstDouble();
    // stackVecString();
    // stackLstString();
    // cout << "--------------TEST QUEUE--------------" << endl;
    // queueVecInt();
    // queueLstInt();
    // queueVecDouble();
    // queueLstDouble();
    // queueVecString();
    // queueLstString();
    cout << "--------------TEST BINARYTREE--------------" << endl;
    testBinaryTree();
    cout << "--------------TEST BINARY SEARCH TREE--------------" << endl;
    testBinarySearchTree();
    cout<<"END OF MY TEST! GOODBYE!"<<endl;
}
