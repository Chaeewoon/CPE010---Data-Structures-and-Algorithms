#ifndef BST_H
#define BST_H

template<typename T>
class BinarySearchTree{
    private:
        T key;
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;
    public:
        //constructor:
        BinarySearchTree(T value);
        // insertion
        void insert(T value);
        //traversal
        void preOrder();
        void inOrder();
        void postOrder();
        //searching
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template<typename T> // recursive calling
void BinarySearchTree<T>::insert(T value){
    //go to left if : value < key
    if(value < key){
        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        }else{
            //go back to start so the value on this will become the key
            left->insert(value);
        }
    }

    //go to right if : value > key
    else if( value > key){
        if(right == nullptr){
            right = new BinarySearchTree<T>(value);
        }else{
            //go back to start so the value on this will become the key
            right->insert(value);
        }
    }
}

template<typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout << key << " ";
    if(left != nullptr){
        //recursive calling
        left->preOrder();
    }
    if(right != nullptr){
        //recursive calling
        right->preOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        //recursive calling
        left->inOrder();
    }

    std::cout << key << " ";
    
    if(right != nullptr){
        //recursive calling
        right->inOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::postOrder(){
    if(left != nullptr){
        //recursive calling
        left->postOrder();
    }
    
    if(right != nullptr){
        //recursive calling
        right->postOrder();
    }

    std::cout << key << " ";
}

#endif