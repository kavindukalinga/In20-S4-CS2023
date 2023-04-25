#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


struct node * getmin(struct node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

void traverseInOrder(struct node *root) {
    if (root == NULL)  return;
    traverseInOrder(root->left );
    cout <<root->key <<" ";
    traverseInOrder(root->right);

}

struct node *insertNode(struct node *node, int key) {
    if (node == NULL){
        struct node *node = (struct node*)malloc(sizeof(node)) ;
        node->key = key;
        node->left = NULL; 
        node->right =NULL;
        return node;

    }
    else if (key <= node->key) {
         node -> left = insertNode(node->left , key);
    }
    else {
         node -> right = insertNode(node->right,key);
        
    }
    return node;

}


struct node *deleteNode(struct node *root, int key) {
    if (root == NULL ){return root;}
    else if (key < root->key) { root->left = deleteNode(root->left , key);}
    else if (key > root->key) {root->right = deleteNode(root->right , key);}
    else{
        if (root->left == NULL && root->right==NULL){
        delete root;
        root=NULL;
        return root;
        

    }
    else if (root-> left  == NULL ) {
        struct node * temp = root ;
        root = root->right;
        delete(temp);
        return root;
    }

    else if (root->right == NULL) {
        struct node * temp = root ;
        root = root->left;
        delete(temp);
        return root;
    }

    else{
        struct node * temp = getmin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
    }
    }

 return root;
}

int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: 
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: 
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
  

}
/* While Running:

Sample Inputs
1 1
1 2
1 3
1 4
1 5
1 6
2 3
-1

Sample Output
1 2 4 5 6

*/
