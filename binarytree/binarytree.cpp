
namespace lasd {

/* ************************************************************************** */
//NODE
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
    bool val=true;
    
    if(Element()==node.Element()){
        if(HasLeftChild() && node.HasLeftChild()){

            val=(LeftChild()==node.LeftChild());

        }else if(HasLeftChild()||node.HasLeftChild()){

            val=false;
        }
        if(val==true){

            if(HasRightChild()&& node.HasRightChild()){

                val=(RightChild()==node.RightChild());

            }else if(HasRightChild()||node.HasLeftChild()){

                val=false;
            }
        }
    }else{
        val=false;
    }
    return val;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
    return !(*this==node);
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept{
    return !HasLeftChild() && !HasRightChild();
}


// BINARY TREE

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binTree) const noexcept{
    if(!(this->Empty())&& !(binTree.Empty())){

        if(size==binTree.size)
        {
            return Root()==binTree.Root();
        }else{
            return false;
        }
    }
    if((this->Empty()) && (binTree.Empty())){
        return true;
    }else{
        return false;
    }
}

// template <typename Data>
// bool BinaryTree<Data>::logicEqual( const BinaryTree<Data>::Node& root, const BinaryTree<Data>::Node& cmpRoot) noexcept {
//   if (root.Element() != cmpRoot.Element()){
//     return false;
//   }
    

//   if ((root.HasLeftChild() != cmpRoot.HasLeftChild()) || (root.HasRightChild() != cmpRoot.HasRightChild())){
//     return false;
//   }
    

//   bool left = true;
//   bool right = true;

//   if (root.HasLeftChild() && cmpRoot.HasLeftChild()){
//     left = logicEqual<Data>(root.LeftChild(), cmpRoot.LeftChild());
//   }
    

//   if(left && root.HasRightChild() && cmpRoot.HasRightChild()){
//     right = logicEqual<Data>(root.RightChild(), cmpRoot.RightChild());
//   }
    

//   return left && right;
// }


template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& cmpTree) const noexcept{
    return !(*this==cmpTree);
}

template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const{
    PreOrderTraverse(fun,Root());
}


template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const{
    PreOrderTraverse(fun,Root());
}


template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const{
    PostOrderTraverse(fun,Root());
}


template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const{
    InOrderTraverse(fun,Root());
}


template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const{
    BreadthTraverse(fun,&Root());
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun,const Node& node) const{
    fun(node.Element());
    if(node.HasLeftChild()){
        PreOrderTraverse(fun,node.LeftChild());
    }
    if(node.HasRightChild()){
        PreOrderTraverse(fun,node.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun,const Node& node) const{
    if(node.HasLeftChild()){
        InOrderTraverse(fun,node.LeftChild());
    }
    
    fun(node.Element());
    
    if(node.HasRightChild()){
        InOrderTraverse(fun,node.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun,const Node& node) const{
    if(node.HasLeftChild()){
        PostOrderTraverse(fun,node.LeftChild());
    }
    if(node.HasRightChild()){
        PostOrderTraverse(fun,node.RightChild());
    }
    fun(node.Element());
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun,const Node* node) const{
    QueueLst<const BinaryTree<Data>::Node*> queue; //coda di  puntatori a nodi
    if(node!=nullptr){
        queue.Enqueue(node);
    }
    
    
    while(!queue.Empty()){
        const BinaryTree<Data>::Node* curr=queue.HeadNDequeue();

        fun(curr->Element());
        if(curr->HasLeftChild()){
            queue.Enqueue(&(curr->LeftChild()));
        }
        if(curr->HasRightChild()){
            queue.Enqueue(&(curr->RightChild()));
        }
    }
}

//MUTABLE BINARY TREE
template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun){
    PreOrderMap(fun,Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun){
    PreOrderMap(fun,Root());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun){
    InOrderMap(fun,Root());
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun){
    PostOrderMap(fun,Root());
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun){
    BreadthMap(fun,&Root());
}


template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode& node){
    fun(node.Element());
    if(node.HasLeftChild()){
        PreOrderMap(fun,node.LeftChild());
    }
    if(node.HasRightChild()){
        PreOrderMap(fun,node.RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun,  MutableNode& node){
    if(node.HasLeftChild()){
        InOrderMap(fun,node.LeftChild());
    }
    fun(node.Element());
    if(node.HasRightChild()){
        InOrderMap(fun,node.RightChild());
    }
}

template<typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun,  MutableNode& node){
    if(node.HasLeftChild()){
        PostOrderMap(fun,node.LeftChild());
    }
    if(node.HasRightChild()){
        PostOrderMap(fun,node.RightChild());
    }
    fun(node.Element());
}

template<typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode* node){
    QueueLst<MutableBinaryTree<Data>::MutableNode*> queue;
    if(node!=nullptr)
    {
        queue.Enqueue(node);
    }
    

    while(!queue.Empty()){
        MutableBinaryTree<Data>::MutableNode* curr=queue.HeadNDequeue();

        fun(curr->Element());
        if(curr->HasLeftChild()){
            queue.Enqueue(&(curr->LeftChild()));
        }
        if(curr->HasRightChild()){
            queue.Enqueue(&(curr->RightChild()));
        }
    }
}

//PRE ORDER ITERATOR
//specific constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree){
    if(!tree.Empty()){
        root=tree.Root();
    }
}
//copy e move constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
    return *this;
}

//operator == e !=
template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*()const{
    if(!stack.Empty()){
        return stack.Top()->Element();
    }else{
        throw std::out_of_range("Iterator is teminated!");
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    return root==nullptr && stack.Empty();
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
    if(!Terminated()){
        if(root->HasLeftChild()){
            if(root->HasRightChild()){
                stack.Push(&(root->RightChild()));
            }
            root=&(root->LeftChild());
        }
        else if(root->HasRightChild()){
            root=&(root->RightChild());
        }
        else{
            if(!stack.Empty()){
                root=stack.TopNPop();
            }
            else{
                root=nullptr;
            }
        }

    }else{
        root=nullptr;
        throw std::out_of_range("Iterator is terminated!");
    }

}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept{
    if(root!=nullptr){
        stack.Clear();
        stack.Push(root);
    }
}
//PREORDER MUTABLE ITERATOR

//specific constructor
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const MutableBinaryTree<Data>& tree){
    if(!tree.Empty()){
        root=tree.Root();
    }
}
//copy e move constructor
template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
    return *this;
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
    return *this;
}

//operator == e !=
template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template<typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*(){
    if(!stack.Empty()){
        return const_cast<Data &>(stack.Head()->Element());
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}

/* ************************************************************************** */

}
