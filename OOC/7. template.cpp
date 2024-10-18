/*Soham Pankhade
PRN : 1032233453 */
#include <iostream>
using namespace std;
template <class T>

class Data{
	T arr[20];
	int size;
	public:
	void getData(){
		cout << "Enter number of elements you want to enter : ";
		cin >> size;
		for (int i = 0; i < size ; i++){
			cout << "Element No " << i+1 << " :";
			cin >> arr[i];
		}
	}
	void sortItOut(){
		for (int i = 0; i < size - 1; i++){
			for ( int j = 0; j < size - i - 1; j++ ){
				if (arr[j] > arr[j+1]){
					swap (arr[j],arr[j+1]);
				}
			}
		}
	}
	void displayArray(){
		for (int i=0;i<size;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
		
	
	
};

int main(){
	int choice;
	cout << "What type of data you want to enter" << endl << "1.Integer\n2.Float : ";
	cin >> choice;
	switch (choice){
		case 1 :
			Data <int> d1;
			d1.getData();
			cout << "Array Before sorting : "; 
			d1.displayArray();
			d1.sortItOut();
			cout << "Array After sorting : " ;
			d1.displayArray();
			break;
			
		case 2 :
			Data <float> d2;
			d2.getData();
			cout << "Array Before sorting : " ; 
			d2.displayArray();
			d2.sortItOut();
			cout << "Array After sorting : " ;
			d2.displayArray();
			break;

		default :
			cout << "Invalid choice. Exiting program...\n";
			break;
			
			
	}
	
}
