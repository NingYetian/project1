#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>
// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */

Chain::~Chain()
{
cout << "Destroed chain" << endl;
/* your code here */

clear(); 
delete head_;  //??
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
/* your code here */
Node * newNodeptr = new Node(ndata);

// need a tail ptr points to the last Node
Node * curr = head_;

while(curr->next != head_){
    curr = curr->next;
}
curr->next = newNodeptr;
newNodeptr->next = head_;
//////delete curr;
length_++;
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
/* your code here */
std::cout << "swap started" <<std::endl;

if(i == j){
    return;
}

if(i > j){
    int temp = j;
    j = i;
    i = temp;
}

if(i<j){
    Node * node1 = walk(head_, i);
    Node * node2 = walk(head_, j);

    if(i ==1){
        Node * node2_pre = walk(head_, j-1);
        Node * node1_next = walk(head_, i+1);
        Node * node2_next = walk(head_, j+1);
        if(i == j - 1){
        head_->next = node2;
        node2->next = node1;
        node1->next = node2_next;

        }else{
        head_->next = node2;
        node2->next = node1_next;

        node2_pre->next = node1;
        node1->next = node2_next;
        }
        return;
    }
    Node * node1_pre = walk(head_, i-1);
    Node * node2_pre = walk(head_, j-1);
    Node * node1_next = walk(head_, i+1);//
    Node * node2_next = walk(head_, j+1); //


    if(i == j - 1){
        node1_pre->next = node2;
        node2->next = node1;
        node1->next = node2_next;

    }else{
        node1_pre->next = node2;
        node2->next = node1_next;

        node2_pre->next = node1;
        node1->next = node2_next;
    }

}

std::cout << "swap reached end" <<std::endl;

}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    // this two if can be removed
    if(length_ == 0 || length_ == 1){
        return;
    }
    if(length_ == 2){
        swap(1,2);
        return;
    }

    int i = 1;
    int j = length_;
    for(i=1; i<j; i++){
        swap(i, j);
        cout<<i<<endl;
        cout<<j<<endl;
        j--;
    // int i = 1;
    // int j = length_;
    // while(i<=length_/2){
    //     swap(i,j);
    //     i++;
    //     j--;
    }

    
/* your code here */
std::cout << "reverse ended" <<std::endl;
}

/*
* Modifies the current chain by "rotating" every group of k nodes by one position.
* In every k-node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
 {
/* your code here */

if(length_<2 || k == 1){  
    return;
}

if(k>length_){
    return;
}
Node * node1 = NULL;
Node* node1_pre = NULL;
Node* node1_next = NULL;
Node * node2 = NULL;
Node* node2_next = NULL;
//int a = 0;

for(int i = 1; i<length_; i++){  
        
    if(i % k == 1){
        node1_pre = walk(head_, i-1);  
        node1 = node1_pre->next;
        node1_next = node1->next;
        //a = i;
        //cout<<"a = "<< i<<endl; 

        node2 = walk(node1_pre, k);
        node2_next = node2->next;
    

        node1_pre->next = node1_next;
        node2->next = node1;
        node1->next = node2_next;
 }

 }
 // why this is not working??
// Node * node1 = NULL;
// Node* node1_pre = NULL;
// Node* node1_next = NULL;
// Node * node2 = NULL;
// Node* node2_next = NULL;
// int a = 0;
// int b = 0;

// for(int i = 1; i<length_; i++){   //i=1
        
//     if(i % k == 1){
//        node1 = walk(head_, i);
//        node1_pre = walk(head_, i-1);  //head_
//        node1_next = walk(head_, i+1);
//        a = i;
//        cout<<"a = "<< i<<endl;
//     }
//     if(i % k == 0){
//         node2 = walk(head_, i);
//         //node2_ k steps from node1
//         node2_next = walk(head_, i+1);
//         b=i;
//         cout<<"b = "<<i<<endl;
//     }
//     if(a<b){
      
//         node1_pre->next = node1_next;
//         cout<< "rorate starts 1 "<< head_->next <<endl;
//         node2->next = node1;
//         cout<< "rorate starts 2 "<< head_->next <<endl;
//         node1->next = node2_next;
//         cout<< "rorate starts 3 "<< head_->next <<endl;

//     }

//     }
    

 }

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
/* your code here */
if(head_ == NULL){
    return;
}

// while(length_>0){
//     Node * curr = head_->next;
//     delete head_;
//     head_ = curr;
//     length_--;
//     std::cout << length_ <<std::endl;
// }

// // delete head_;
// head_ = NULL;


if (head_)
    {
        Node *tmp = head_;
        Node *next = NULL;
        for (int i = 0; i < length_; i++)
        {
            next = tmp->next;
            delete tmp;
            tmp = next;
        }
        //this fixed memory leak
        delete tmp; // can't delte next again them are the same thing

        tmp = NULL;
        next = NULL;

    }
    length_ = 0;
    height_ = 0;
    width_ = 0;
    head_ = NULL;

}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* your code here */

head_ = new Node();
Node * curr = other.head_->next; //old chain ptr
Node * newcurr = head_;  //new chain ptr

height_ = other.height_;
width_ = other.width_;
length_ = 0;

while(curr != other.head_){
    Node * newNode = new Node(curr->data);
    curr = curr->next;

    newcurr->next = newNode;
    newcurr = newcurr->next;
    length_++;
}

newcurr->next = head_;
}


