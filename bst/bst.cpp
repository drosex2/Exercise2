
namespace lasd {

/* ************************************************************************** */
//constructor from traversable container
template<typename Data>
BST<Data>::BST(const TraversableContainer<Data>& traversableCon) {
    size=traversableCon.size;
    traversableCon.Traverse(
        [this](const Data& data){
            Insert(data);
        }
    );
}

//from mappableContainer
    template<typename Data>
    BST<Data>::BST(MappableContainer<Data>&& mappableCon) {
        size=mappableCon.size;
        
        mappableCon.Map(
            [this]( Data& data){
                Insert(std::move(data));
            }
        );
        
    }

template<typename Data>
BST<Data>::BST(const BST<Data>& BST): BinaryTreeLnk<Data>::BinaryTreeLnk(BST){}

template<typename Data>
BST<Data>::BST(BST<Data>&& BST)noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(BST)){}


template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& BST){
  BinaryTreeLnk<Data>::operator=(BST);
  return *this;
}
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& BST)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(BST));
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& BST)const noexcept{
    if(size!=BST.size){
        return false;
    }
    else{
        BTInOrderIterator<Data> it1(*this);
        BTInOrderIterator<Data> it2(BST);
        bool val=true;
        while(!it1.Terminated && val==true){
            if(*it1!=*it2){
                val=false
            }
            ++it1;
            ++it2;
        }
        return val;
    }
}
template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& BST)const noexcept{
    return !(*this==BST);
}

template <typename Data>
const Data& BST<Data>::Min() const{
    if(root!=nullptr){
        return FindPointerToMin(root)->Element();
    }
    else{
        throw std::length_error("The tree is empty!");
    }
}

template <typename Data>
Data BST<Data>::MinNRemove() {
    if(root!=nullptr){
        NodeLnk* nodeMin= DetachMin(root);
        Data min=nodeMin->Element();
        delete nodeMin;
        return min;
    }
    else{
        throw std::length_error("The tree is empty!");
    }
    
}
template <typename Data>
void BST<Data>::MinNRemove() {
    if(root!=nullptr){
        NodeLnk* nodeMin= DetachMin(root);
        delete nodeMin;
    }
    else{
        throw std::length_error("The tree is empty!");
    }
    
}

template <typename Data>
const Data& BST<Data>::Max() const{
    if(root!=nullptr){
        return FindPointerToMax(root)->Element();
    }
    else{
        throw std::length_error("The tree is empty!");
    }
}

template <typename Data>
Data BST<Data>::MaxNRemove() {
    if(root!=nullptr){
        NodeLnk* nodeMax= DetachMax(root);
        Data max=nodeMax->Element();
        delete nodeMax;
        return max;
    }
    else{
        throw std::length_error("The tree is empty!");
    }
    
}
template <typename Data>
void BST<Data>::MaxNRemove() {
    if(root!=nullptr){
        NodeLnk* nodeMax= DetachMax(root);
        delete nodeMax;
    }
    else{
        throw std::length_error("The tree is empty!");
    }
    
}


template<typename Data>
const Data& BST<Data>::Predecessor(const Data& value) const
{
  if(root!=nullptr)
    NodeLnk *pred = FindPointerToPredecessor(root, value);
    if(pred == nullptr)
       throw std::length_error("There isn't a predecessor");
    else
      return pred->Element();
     
  else
  {
    throw std::length_error("The tree is empty.");
  }


}


template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& value)
{
  Data pred = Predecessor(value);
  Remove(pred);
  return pred;
}


template<typename Data>
void BST<Data>::RemovePredecessor(const Data& value)
{
   const Data& pred = Predecessor(value);
   Remove(pred);
}


template<typename Data>
const Data& BST<Data>::Successor(const Data& value) const
{
  if(root!=nullptr)
    NodeLnk *succ = FindPointerToSuccessor(root, value);
    if(succ == nullptr)
       throw std::length_error("There isn't a successor");
    else
      return succ->Element();
     
  else
  {
    throw std::length_error("The tree is empty.");
  }
}


template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& value)
{
  Data succ = Successor(value);
  Remove(succ);
  return succ;
}


template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& value)
{
  const Data& succ = Successor(value);
  Remove(succ);
}

template <typename Data>
const BinaryTreeLnk<Data>::NodeLnk& BST<Data>::Root() const {
    if (root == nullptr){
        throw std::out_of_range("L'albero è vuoto!");
    }
    else{
        return *root;
    }    
}

template<typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept
{
    return (FindPointerTo(root, value) != nullptr);
}

template <typename Data>
bool BST<Data>::Insert(const Data & value){
  NodeLnk*& ptr=FindPointerTo(root, value);
  if(ptr==nullptr){
    puntatore=new NodeLnk(value);
    size++;
    return true;
  }else{
    return false;
  }
}

template <typename Data>
bool BST<Data>::Insert(Data && value){
  NodeLnk*& ptr=FindPointerTo(root, value);
  if(ptr==nullptr){
    puntatore=new NodeLnk(std::move(value));
    size++;
    return true;
  }else{
    return false;
  }
}

template<typename Data>
void BST<Data>::Remove(const Data& value)
{
  delete Detach(FindPointerTo(root, value));
}
//auxiliary functions

template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node){
    Data val=node->Elemento();
    node->left=nullptr;
    node->right=nullptr;
    delete node;
    return val;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* Detach(NodeLnk*& node ) noexcept{
    if(node != nullptr){
    if(node->left == nullptr){
      return Skip2Right(node);
    }
    else if(node->right == nullptr){
      return Skip2Left(node);
    }
    else{
      NodeLnk* max = DetachMax(node->left);
      std::swap(node->element, max->element);
      return max;
    }
  }
  return nullptr;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* DetachMin(NodeLnk*& node ) noexcept{
    return Skip2Right(FindPointerToMin(node));
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* DetachMax(NodeLnk*& node ) noexcept{
    return Skip2Left(FindPointerToMax(node));
}
/* ************************************************************************** */

}
