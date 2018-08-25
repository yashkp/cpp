#include<iostream>
using namespace std;

typedef struct node{
    int value;
    node *left;
    node *right;
    node(int val){
        this->value=val;
        this->left=NULL;
        this->right=NULL;
    }
}node;

// class Tree{
//     node *root;
//     public:
//         Tree(){
//             root = NULL;
//         }
// };

// node* addnode(int value){
//     node *temp=new node();
//     temp->value=value;
//     temp->left=NULL;
//     temp->right=NULL;

//     return temp;
// }

void preOrder(node *nd){
    if(nd == NULL){
        return;
    }
    cout << nd->value << " ";
    preOrder(nd->left);
    preOrder(nd->right);
}

void postOrder(node *nd){
    if(nd == NULL){
        return;
    }
    postOrder(nd->left);
    postOrder(nd->right);
    cout << nd->value << " ";
}

void InOrder(node *nd){
    if(nd == NULL){
        return;
    }
    InOrder(nd->left);
    cout << nd->value << " ";
    InOrder(nd->right);
}

int main(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    InOrder(root);

    return 0;
}