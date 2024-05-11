#ifndef MYSTACK_HPP
#define MYSTACK_HPP

/* ************************************************************************** */
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <random>
using namespace std;

void stackVecInt()
{
    cout << "--------------TEST STACKVEC INT--------------" << endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_int_distribution<int> dist(1, 1000);
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackVec<int> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            st.Push(dist(gen));
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<" dimensione: "<<st.Size()<<endl;
        cout<<"Push tot elementi"<<endl;
        unsigned long rand=dist(gen);
        for(unsigned long i=0;i<rand;i++){
            st.Push(dist(gen));
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
}

void stackLstInt()
{
    cout << "--------------TEST STACKLST INT--------------" << endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_int_distribution<int> dist(1, 1000);
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackLst<int> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            st.Push(dist(gen));
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<endl;
        cout<<"Push tot elementi"<<endl;
        unsigned long rand=dist(gen);
        for(unsigned long i=0;i<rand;i++){
            st.Push(dist(gen));
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
}

void stackVecDouble()
{
    cout << "--------------TEST STACKVEC DOUBLE--------------" << endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_real_distribution<double> dist(1.0, 1000.0);
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackVec<double> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            st.Push(dist(gen));
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<" dimensione: "<<st.Size()<<endl;
        cout<<"Push 50 elementi"<<endl;
        for(unsigned long i=0;i<50;i++){
            st.Push(dist(gen));
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
}

void stackLstDouble()
{
    cout << "--------------TEST STACKLST DOUBLE--------------" << endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_real_distribution<double> dist(1.0, 1500.0);
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackLst<double> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            st.Push(dist(gen));
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<endl;
        cout<<"Push tot elementi"<<endl;
        for(unsigned long i=0;i<50;i++){
            st.Push(dist(gen));
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
}
void stackVecString(){
    cout<<"--------------TEST STACKVEC STRING--------------"<<endl;
    std::mt19937 mt(std::random_device{}());
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);
    std::string randomString;
    unsigned long size;
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackVec<string> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            randomString = characters[dist(mt)];
            st.Push(randomString);
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<" dimensione: "<<st.Size()<<endl;
        cout<<"Push 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            randomString = characters[dist(mt)];
            st.Push(randomString);
        }
        cout<<"Dimensione: "<<st.Size()<<endl;
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}

void stackLstString(){
    cout<<"--------------TEST STACKLST STRING--------------"<<endl;
    std::mt19937 mt(std::random_device{}());
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);
    std::string randomString;
    unsigned long size;
    
    cout<<"Inserisci quanti elementi inserire nello stack: ";
    cin>>size;
    lasd::StackLst<string> st;
    cout<<"Creo e riempio di valori random lo stack" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
             randomString = characters[dist(mt)];
            st.Push(randomString);
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            st.Pop();
        }
        
        cout<<"Top dopo aver tolto la metà degli elementi: "<<st.Top()<<endl;
        cout<<"TopNPop: "<<st.TopNPop()<<endl;
        cout<<"Push 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            randomString = characters[dist(mt)];
            st.Push(randomString);
        }
        
        cout<<"Top attuale: "<<st.Top()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}
/* ************************************************************************** */
#endif