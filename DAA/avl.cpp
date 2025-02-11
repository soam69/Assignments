#include <iostream>
using namespace std;

class node {
        string word;
        string meaning;
        node* left, *right;
    public:
        node (){
            word = "NULL";
            meaning = "NULL";
            left = right = NULL;
        }
        friend class avlTree;    
};

class avlTree {
    public:
        node *root;
        avlTree(){
            root = NULL;
        }
        void insert(){
            char choice;
            do{
                node *temp = new node;
                cout << "Enter the Word : ";
                cin >> temp->word;
                cout << "Enter the meaning of " << temp->word << " : ";
                cin >> temp->meaning;
                root = insert(root,temp);
                cout << "Would you like to insert more words ? (y/n) : ";
                cin >> choice;
            } while (choice == 'Y' || choice == 'y');
        }

        node* insert(node *root, node* temp){
            if (root == NULL){
                root = new node;
                root->word = temp->word;
                root->meaning = temp->meaning;
                root->right = root->left = NULL;
                return root;
            }
            else if (temp->word > root->word ){
                root->right = insert (root->right,temp);
            }
            else if (temp->word < root->word){
                root->left = insert(root->left,temp);
            }
            return root;
        }

        void display(node* root){
            if ( root == NULL){
                return;
            }
            display(root->left);
            cout << "Word : " << root->word << endl;
            cout << "Meaning : " << root->meaning << endl << endl;
            display (root->right);
        }


        

};



int main(){
    avlTree tree;
    tree.insert();
    tree.display(tree.root);
    return 0;
}