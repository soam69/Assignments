#include <iostream>
using namespace std;

class graph {
    int cities;
    int cost[10][10];
    public:
        graph(int no){
            cities = no;
            for (int i = 0; i < cities; i++){
                for (int j = 0; j < cities; j++){
                    cost[i][j] = 999;
                }
            }
        }

        void create(){
            char choice;
            for (int i = 0; i < cities; i++){
                for (int j = 0; j < cities; j++){
                    if (i != j && cost[i][j] == 999){
                        cout << "Is there a connection between " << i << " and " << j << " (y/n) : ";
                        cin >> choice;
                        if (choice == 'y'){
                            cout << "Enter cost of path between " << i << " and " << j << " : ";
                            cin >> cost[i][j];
                            cost[j][i] = cost[i][j];
                        }
                    }
                }
            }
        }

        void display(){
            cout << "The adjacency matrix is :" << endl;
            for (int i = 0; i < cities; i++){
                for (int j = 0; j < cities; j++){
                    cout << cost[i][j] << "\t";
                }
                cout << endl;
            }
        }

        int prims(int startVertex){
            int nearest[cities];
            bool selected[cities] = {false};
            int min = 999;
            int mincost = 0;
            int index;

            for (int i = 0; i < cities; i++) {
                nearest[i] = startVertex;
            }

            selected[startVertex] = true;
            for (int i = 0; i < cities - 1; i++) {
                min = 999;
                for (int k = 0; k < cities; k++) {
                    if (!selected[k] && cost[k][nearest[k]] < min) {
                        min = cost[k][nearest[k]];
                        index = k;
                    }
                }

                mincost += min;
                selected[index] = true;

                for (int k = 0; k < cities; k++) {
                    if (!selected[k] && cost[k][index] < cost[k][nearest[k]]) {
                        nearest[k] = index;
                    }
                }
            }

            return mincost;
        }
};

int main(){
    graph map(3);
    int ch;
    while(1){
        cout << "1. Accept\n2. Display\n3. Find MST\n4. Exit\n";
        cin >> ch;
        switch(ch){
            case 1:
                map.create();
                break;
            case 2:
                map.display();
                break;
            case 3:
                cout << "The cost is : " << map.prims(0) << endl;
                break;
            case 4:
                cout << "Thank you!" << endl;
                return 0;
        }
    }
}
