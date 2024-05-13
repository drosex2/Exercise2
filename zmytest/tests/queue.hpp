#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

/* ************************************************************************** */
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"
#include "../../vector/vector.hpp"
#include "../../container/container.hpp"
#include "../../container/mappable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../container.hpp"
#include <random>
#include <string>
using namespace std;
using namespace miotest;
void queueVecInt(){
    cout<<"--------------TEST QUEUEVEC INT--------------"<<endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_int_distribution<int> dist(1, 1000);
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueVec<int> que;
    lasd::QueueVec<int> que2;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            que.Enqueue(dist(gen));
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<" dimensione: "<<que.Size()<<endl;
        cout<<"Enqueue tot elementi"<<endl;
        unsigned long rand=dist(gen);
        for(unsigned long i=0;i<rand;i++){
            que.Enqueue(dist(gen));
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
        
        lasd::QueueVec<int> que2;

        que2.Enqueue(1);
        que2.Enqueue(2);
        que2.Enqueue(3);
        lasd::SortableVector<int> vec(3);
        vec[0]=1;
        vec[1]=2;
        vec[2]=3;
        lasd::QueueVec<int> que3(vec);
        if(que2==que3){
            cout<<"corretto!"<<endl;
        }else{
            cout<<"false"<<endl;
        }
        
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}
void queueLstInt(){
    cout<<"--------------TEST QUEUELST INT--------------"<<endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_int_distribution<int> dist(1, 1000);
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueLst<int> que;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            que.Enqueue(dist(gen));
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<endl;
        cout<<"Enqueue tot elementi"<<endl;
        unsigned long rand=dist(gen);
        for(unsigned long i=0;i<rand;i++){
            que.Enqueue(dist(gen));
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}
void queueVecDouble(){
    cout<<"--------------TEST QUEUEVEC DOUBLE--------------"<<endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_real_distribution<double> dist(1.0, 1000.0);
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueVec<double> que;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            que.Enqueue(dist(gen));
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<" dimensione: "<<que.Size()<<endl;
        cout<<"Enqueue 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            que.Enqueue(dist(gen));
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}

void queueLstDouble(){
    cout<<"--------------TEST QUEUELST DOUBLE--------------"<<endl;
    unsigned long size;
    default_random_engine gen(random_device{}()); 
    uniform_real_distribution<double> dist(1, 1000);
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueLst<double> que;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            que.Enqueue(dist(gen));
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<endl;
        cout<<"Enqueue 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            que.Enqueue(dist(gen));
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}
void queueVecString(){
    cout<<"--------------TEST QUEUEVEC STRING--------------"<<endl;
    std::mt19937 mt(std::random_device{}());
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);
    std::string randomString;
    unsigned long size;
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueVec<string> que;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
            randomString = characters[dist(mt)];
            que.Enqueue(randomString);
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<" dimensione: "<<que.Size()<<endl;
        cout<<"Enqueue 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            randomString = characters[dist(mt)];
            que.Enqueue(randomString);
        }
        cout<<"Dimensione: "<<que.Size()<<endl;
        cout<<"Head attuale: "<<que.Head()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}

void queueLstString(){
    cout<<"--------------TEST QUEUELST STRING--------------"<<endl;
    std::mt19937 mt(std::random_device{}());
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::uniform_int_distribution<int> dist(0, characters.length() - 1);
    std::string randomString;
    unsigned long size;
    
    cout<<"Inserisci quanti elementi inserire nella coda: ";
    cin>>size;
    lasd::QueueLst<string> que;
    cout<<"Creo e riempio di valori random la coda" <<endl;
    try{
        for(unsigned long i=0;i<size;i++){
             randomString = characters[dist(mt)];
            que.Enqueue(randomString);
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
        for(unsigned long i=0;i<size/2;i++){
            que.Dequeue();
        }
        
        cout<<"Head dopo aver tolto la metà degli elementi: "<<que.Head()<<endl;
        cout<<"HeadNDequeue: "<<que.HeadNDequeue()<<endl;
        cout<<"Enqueue 100 elementi"<<endl;
        for(unsigned long i=0;i<100;i++){
            randomString = characters[dist(mt)];
            que.Enqueue(randomString);
        }
        
        cout<<"Head attuale: "<<que.Head()<<endl;
    }catch(exception& exc){
        cout<<exc.what()<<endl;
    }
    
}

/* ************************************************************************** */
#endif