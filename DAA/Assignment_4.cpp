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

        void inOrder(node* root){
            if ( root == NULL){
                return;
            }
            inOrder(root->left);
            cout << "Word : " << root->word << endl;
            cout << "Meaning : " << root->meaning << endl << endl;
            inOrder (root->right);
        }
        
        void preOrder(node* root){
            if ( root == NULL){
                return;
            }
            cout << "Word : " << root->word << endl;
            cout << "Meaning : " << root->meaning << endl << endl;
            preOrder (root->left);
            preOrder (root->right);
        }
        
        void postOrder(node* root){
            if ( root == NULL){
                return;
            }
            postOrder (root->left);
            postOrder (root->right);
            cout << "Word : " << root->word << endl;
            cout << "Meaning : " << root->meaning << endl << endl;
            
        }
        
        int height (node* root){
            int h = 0;
            if (root != NULL){
                h = max( height(root->left),height (root->right)) + 1;
            }
            return h;
        }

        int diff (node* root){
            return height (root->left) - height(root->right);
        }

        node* llRotaion (node *parent){
            node* temp = parent->left;
            parent->left = temp->right;
            temp->right = parent;
            return temp;
        }

        node* rrRotaion (node *parent){
            node* temp = parent->right;
            parent->right = temp->left;
            temp->left = parent;
            return temp;
        }

        node* lrRotaion (node *parent){
            node* temp = parent->left;
            parent->left = rrRotaion(temp);
            return llRotaion(parent);
        }

        node* rlRotaion (node *parent){
            node* temp = parent->right;
            parent->right = llRotaion(temp);
            return rrRotaion(parent);
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
        

        node* balance(node *temp){
            int balFactor = diff(temp);
            if(balFactor > 1){
                if(diff(temp->left) > 0) temp = llRotaion(temp);
                else temp = lrRotaion(temp);
            }
            else if(balFactor < -1){
                if(diff(temp->right) > 0) temp = rlRotaion(temp);
                else temp = rrRotaion(temp);
            }
            return temp;
        }


        

};



int main(){
    avlTree dictionary;
    int ch;
    while(1){
        cout << "1. Insert data\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. Level order traversal\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                dictionary.insert();
                break;
            case 2:
                cout << "Preorder traversal is:\n";
                dictionary.preOrder(dictionary.root);
                break;
            case 3:
                cout << "Inorder traversal is:\n";
                dictionary.inOrder(dictionary.root);
                break;
            case 4:
                cout << "Postorder traversal is:\n";
                dictionary.postOrder(dictionary.root);
                break;
            case 5:
                cout << "Level order traversal is:\n";
                dictionary.display(dictionary.root);
                break;
            case 6:
                cout << "Thank You!";
                return 0;
        }
    }
}