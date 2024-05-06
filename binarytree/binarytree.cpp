
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
        root=&tree.Root();
        stack.Push(root);
    }else{
        root=nullptr;
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
//operator*
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
    return stack.Empty();
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
    const typename BinaryTree<Data>::Node*  current= stack.TopNPop();
    if(current!=nullptr){
        if(current->HasLeftChild()){
            if(current->HasRightChild()){
                stack.Push(&(current->RightChild()));
            }
            stack.Push(&(current->LeftChild()));
        }
        else if(current->HasRightChild()){
            stack.Push(&(current->RightChild()));
        }

    }else{
        //current=nullptr;
        throw std::out_of_range("Iterator is terminated!");
    }
    return *this;
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
        root=&tree.Root();
        stack.Push(root);
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
        return const_cast<Data &>(stack.Top()->Element());
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}
//POST ORDER ITERATOR 
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Empty()){
        root=nullptr;
    }else{
        root=&(tree.Root());
        LeftMostLeaf(root);
    }
}

//copy e move constructor
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
    return *this;
}

//operator == e !=
template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*()const{
    if(!stack.Empty()){
        return stack.Top()->Element();
    }else{
        throw std::out_of_range("Iterator is teminated!");
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    return stack.Empty();
}


template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
    const typename BinaryTree<Data>::Node* current= stack.TopNPop();
    if(current!=nullptr){
        if(stack.Top()->HasRightChild() && (&stack.Top()->RightChild()!=current)){
            
            current=&stack.Top()->RightChild();
            LeftMostLeaf(current);
        }

    }else{
        //current=nullptr;
        throw std::out_of_range("Iterator is terminated!");
    }
    return *this;

}


template <typename Data>
void BTPostOrderIterator<Data>::LeftMostLeaf(const typename BinaryTree<Data>::Node* curr){
  while(curr->HasLeftChild()){
    stack.Push(curr);
    curr=&(curr->LeftChild());
  }
  if(curr->HasRightChild()){
    stack.Push(curr);
    curr=&(curr->RightChild());
    LeftMostLeaf(curr);
  }
    
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept{
    if(root!=nullptr){
        stack.Clear();
        LeftMostLeaf(root);
    }
}
//POSTORDER MUTABLE ITERATOR

//specific constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const MutableBinaryTree<Data>& tree){
    if(tree.Empty()){
        root=nullptr;
    }else{
        root=&(tree.Root());
        LeftMostLeaf(root);
    }
}
//copy e move constructor
template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
/////////

//operator == e !=
template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template<typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*(){
    if(!stack.Empty()){
        return const_cast<Data &>(stack.Top()->Element());
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}
//IN ORDER ITERATOR

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree){
    if(tree.Empty()){
        root=nullptr;
    }else{
        root=&(tree.Root());
        PushLeftNodes(root);
    }
}

//copy e move constructor
template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
    return *this;
}

//operator == e !=
template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*()const{
    if(!stack.Empty()){
        return stack.Top()->Element();
    }else{
        throw std::out_of_range("Iterator is teminated!");
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    return stack.Empty();
}


template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
    const typename BinaryTree<Data>::Node* current= stack.TopNPop();
    if(current!=nullptr){
        if(current->HasRightChild()){
            
            current=&(current->RightChild());
            stack.Push(current);
            PushLeftNodes(current);
        }

    }else{
        //current=nullptr;
        throw std::out_of_range("Iterator is terminated!");
    }
    return *this;

}


template <typename Data>
void BTInOrderIterator<Data>::PushLeftNodes(const typename BinaryTree<Data>::Node* curr){
  
    if(curr->HasLeftChild()){
      stack.Push(curr);
      PushLeftNodes(&(curr->LeftChild()));
    }
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept{
    if(root!=nullptr){
        stack.Clear();
        PushLeftNodes(root);
    }
}
//INORDER MUTABLE ITERATOR

//specific constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const MutableBinaryTree<Data>& tree){
    if(tree.Empty()){
        root=nullptr;
    }else{
        root=&(tree.Root());
        PushLeftNodes(root);
    }
}
//copy e move constructor
template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& iterator){
    stack=iterator.stack;
    root=iterator.root;
}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& iterator)noexcept{
    std::swap(stack,iterator.stack);
    std::swap(root,iterator.root);
}

//copy e move assignment
// template <typename Data>
// BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& iterator){
//     stack=iterator.stack;
//     root=iterator.root;
//     return *this;
// }

// template <typename Data>
// BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data>&& iterator)noexcept{
//     std::swap(stack,iterator.stack);
//     std::swap(root,iterator.root);
//     return *this;
// }

//operator == e !=
template <typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data>& iterator)const noexcept{
    if((stack == iterator.stack)&&(root==iterator.root)){
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data>& iterator)const noexcept{
    return !(*this==iterator);
}

template<typename Data>
Data& BTInOrderMutableIterator<Data>::operator*(){
    if(!stack.Empty()){
        return const_cast<Data &>(stack.Top()->Element());
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}
//BREADTH ITERATOR
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree){
  if (tree.Empty()) {
    root = nullptr;
  } else {
    root = &(tree.Root());
    queue.Enqueue(root);
  }
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator){
    queue=iterator.queue;
    root=iterator.root;
}

template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept{
    std::swap(queue,iterator.queue);
    std::swap(root,iterator.root);
}

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator){
    queue=iterator.queue;
    root=iterator.root;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator)noexcept{
    std::swap(queue,iterator.queue);
    std::swap(root,iterator.root);
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept{
    return ((queue==iterator.queue) && (root==iterator.root));
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept{
    return !(*this==iterator);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const{
    if(!queue.Empty()){
        return queue.Head()->Element(); 
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    return queue.Empty();
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
    const typename BinaryTree<Data>::Node & current= *(queue.HeadNDequeue());
    if(current.HasLeftChild()){
        queue.Enqueue(&current.LeftChild());
    }
    if(current.HasRightChild()){
        queue.Enqueue(&current.RightChild());
    }
    return *this;
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept{
    if(root!=nullptr){
        queue.Clear();
        queue.Enqueue(root);
    }
}

//BREADTH MUTABLE ITERATOR
template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const MutableBinaryTree<Data>& tree){
  if (tree.Empty()) {
    root = nullptr;
  } else {
    root = &(tree.Root());
    queue.Enqueue(root);
  }
}

template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& iterator){
    queue=iterator.queue;
    root=iterator.root;
}

template<typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& iterator) noexcept{
    std::swap(queue,iterator.queue);
    std::swap(root,iterator.root);
}

// template <typename Data>
// BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& iterator){
//     BTBreadthIterator<Data>::operator=(iterator);
//     return *this;
// }

// template <typename Data>
// BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data>&& iterator)noexcept{
//     BTBreadthIterator<Data>::operator=(std::move(iterator));
//     return *this;
// }

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data>& iterator) const noexcept{
    return ((queue==iterator.queue) && (root==iterator.root));
}

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data>& iterator) const noexcept{
    return !(*this==iterator);
}

template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*() {
    if(!queue.Empty()){
        return const_cast<Data &>(queue.Head()->Element());
    }else{
        throw std::out_of_range("Iterator is terminated!");
    }
}

/* ************************************************************************** */



}
