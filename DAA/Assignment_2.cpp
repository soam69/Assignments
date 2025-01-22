#include <iostream>
using namespace std;

class gNode {
		int id;
		string name;
		gNode *next;
	public:	
		gNode(){
			id = -1;
			name = "NULL";
			next = NULL;
		}
		friend class graph;
};

gNode stack[20];
int stackTop = -1;

void push(gNode *temp){
		stackTop++;
		stack[stackTop] = *temp;
}

gNode* pop (){
		return &stack[stackTop--];
}

gNode queue[20];
int rear = -1 ,front = -1;

void enqueue(gNode *temp){
		queue[++rear] = *temp;
}

gNode* dequeue (){
		return &queue[++front];
}

class graph {
		gNode *head[20];
		int n;
		bool visited[20] = {false};
	public :
		
		graph(int m){
			n = m;
			for ( int i = 0; i < n; i++ ){
				head[i] = new gNode;
				cout << "Enter name of user " << i << " : ";
				cin >> head[i]->name;
				head[i]->id = i;
				head[i]->next = NULL;	
			}
		}
		void create(){
			for (int i = 0; i < n; i++){
				gNode *temp = head[i];
				char choice;
				do{
					int adVert;
					cout << "Enter id of friend of " << head[i]->name  <<  " :";
					cin >> adVert;
					if ( adVert == i ){
						cout << "Self loop not allowed";
					}
					else{
						gNode *curr = new gNode;
						curr->id = adVert;
						curr->name = head[adVert]->name;
						temp->next = curr;
						temp = temp->next;
					}
					cout << "Would you like to continue : y/n ? : ";
					cin >> choice;
				} while (choice == 'y' || choice == 'Y');

			}
		}
		void display(){
			for ( int i = 0; i < n; i++){
				cout << "Friends of " << head[i]->name << " : ";
				gNode *temp = head[i]->next;

				while(temp != NULL){
					cout << temp->name << "-->";
					temp = temp->next;
					
				}
				cout << endl;
			}
		}

		void depthFirstSearch(int v){
			cout << head[v]->name << endl;
			visited[v] = true;
			gNode *temp = head[v]->next;
			while (temp != NULL){
				int w = temp->id;
				if (!visited[w]){
					depthFirstSearch(w);
				}
				temp = temp->next;
			}
		}

		void depthFirstSearch(){
			for (int i = 0; i < n; i++ ){
				visited[i] = false;
			}
			
			int startPoint;
			cout << "Enter id of starting point for traversal : ";
			cin >> startPoint;
			depthFirstSearch(startPoint);
		}
		
		void depthFirstSearchNR (int v){
			for ( int i = 0; i < n; i++ ){
				visited[i] = false;
			}
			push(head[v]);
			visited[v] = true;
			do{
				
				gNode *temp = pop();
				while (temp != NULL){
					int w = temp->id;
					if (!visited[w]){
						depthFirstSearch(w);
					}
				temp = temp->next;
				}
			}while (stackTop != -1);

		}

		void breadthFirstSearch (int v){
			for ( int i = 0; i < n; i++ ){
				visited[i] = false;
			}
			enqueue(head[v]);
			visited[v] = true;
			do{
				
				gNode *temp = dequeue();
				while (temp != NULL){
					int w = temp->id;
					if (!visited[w]){
						depthFirstSearch(w);
					}
				temp = temp->next;
				}
			}while (front != rear);

		}
	
	
};

int main(){
	graph vert(3);
	int ch;
	int start = -1;
    while(1){
        cout << "1. Accept friends\n2. Display network\n3. DFS (Recusrive)\n4. DFS (Non Recusrive)\n5. BFS\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                vert.create();
                break;
            case 2:
                vert.display();
                break;
            case 3:
                vert.depthFirstSearch();
                break;
            case 4:
				
				cout << "Enter starting vertex : ";
				cin >>start;
                vert.depthFirstSearchNR(start);
                break;
            case 5:
				cout << "Enter starting vertex : ";
				cin >>start;
                vert.breadthFirstSearch(start);
                break;
            case 6:
                cout << "Thank You!";
                return 0;
        }
    }
}
