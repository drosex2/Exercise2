
namespace lasd {

/* ************************************************************************** */
//NODE
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
    return this==&node;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
    return this!=&node;
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept{
    return !HasLeftChild() && !HasRightChild();
}


// BINARY TREE

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binTree) const noexcept{
    if(this == &binaryTree){
        return true;
    }
        

    if(dimensione == 0 && binaryTree.dimensione == 0)
    {
        return true;
    }
    

  return dimensione == binaryTree.dimensione ; //DA FINIRE
}



template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const{
    PreOrderTraverse(fun,&Root());
}


template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const{
    PreOrderTraverse(fun,&Root());
}


template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const{
    PostOrderTraverse(fun,&Root());
}


template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const{
    InOrderTraverse(fun,&Root());
}


template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const{
    BreadthTraverse(fun,&Root());
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun,const Node* node) const{
    fun(node->Element());
    if(node->HasLeftChild()){
        PreOrderTraverse(fun,&node->LeftChild());
    }
    if(node->HasRightChild()){
        PreOrderTraverse(fun,&node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun,const Node* node) const{
    if(node->HasLeftChild()){
        InOrderTraverse(fun,&node->LeftChild());
    }
    
    fun(node->Element());
    
    if(node->HasRightChild()){
        InOrderTraverse(fun,&node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun,const Node* node) const{
    if(node->HasLeftChild()){
        PostOrderTraverse(fun,&node->LeftChild());
    }
    if(node->HasRightChild()){
        PostOrderTraverse(fun,&node->RightChild());
    }
    fun(node->Element());
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun,const Node* node) const{
    QueueLst<BinaryTree<Data>::Node*> queue; //coda di  puntatori a nodi
    if(node!=nullptr){
        queue.Enqueue(node);
    }
    while(!queue.Empty()){
        BinaryTree<Data>::Node *curr=queue.HeadNDequeue();

        fun(curr->Element());
        if(curr->HasLeftChild()){
            queue.Enqueue(&curr->LeftChild());
        }
        if(curr->HasRightChild()){
            queue.Enqueue(&curr->RightChild());
        }
    }
}

//MUTABLE BINARY TREE
template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun){
    PreOrderMap(fun,&Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun){
    PreOrderMap(fun,&Root());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun){
    InOrderMap(fun,&Root());
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun){
    PostOrderMap(fun,&Root());
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun){
    BreadthMap(fun,&Root());
}


template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, const Node* node){
    fun(node->Element());
    if(node->HasLeftChild()){
        PreOrderMap(fun,&node->LeftChild());
    }
    if(node->Element()){
        PreOrderMap(fun,&node->RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, const Node* node){
    if(node->HasLeftChild()){
        InOrderMap(fun,&node->LeftChild());
    }
    fun(node->Element());
    if(node->HasRightChild()){
        InOrderMap(fun,&node->RightChild());
    }
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, const Node* node){
    if(node->HasLeftChild()){
        PostOrderMap(fun,&node->LeftChild());
    }
    if(node->HasRightChild()){
        PostOrderMap(fun,&node->RightChild());
    }
    fun(node->Element());
}

template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, const Node* node){
    QueueLst<BinaryTree<Data>::Node*> queue;

    if(node!=nullptr){
        queue.Enqueue(node);
    }

    while(!queue.Empty()){
        BinaryTree<Data>::Node* curr=queue.HeadNDequeue();

        fun(curr->Element());
        if(curr->HasLeftChild()){
            queue.Enqueue(&curr->LeftChild());
        }
        if(curr->HasRightChild()){
            queue.Enqueue(&curr->RightChild());
        }
    }
}
/* ************************************************************************** */

}
