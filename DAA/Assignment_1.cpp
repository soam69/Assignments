#include <iostream>
using namespace std;
 
class user{
		long mobileNo;
		string name;
		float billAmount;
	public:
		user(){
			mobileNo = 0;
			name = "NULL";
			billAmount = 0;
		}
		friend class record;
};

class record{
		int n;
		user cust[10];	
	public:
		record (int m){
			n = m;
		}
		void accept(){
			for (int i=0;i<n;i++){
				cout << "Enter name for user " << i+1 << " : ";
				cin >> cust[i].name;
				cout << "Enter mobile number for user " << i+1 << " : ";
				cin >> cust[i].mobileNo;
				cout << "Enter bill amount for user " << i+1 << " : ";
				cin >> cust[i].billAmount;
			}
 
		}
		void display(){
			for (int i=0;i<n;i++){
				cout << "User " << i+1 << " Name : " << cust[i].name << endl;
				cout << "User " << i+1 << " Mobile no. : " << cust[i].mobileNo << endl;
				cout << "User " << i+1 << " Bill amount : " << cust[i].billAmount << endl;
			}
		}
 
		void linearSearch(){
			long target;
			cout << "Enter mobile no. to search in database :";
			cin >> target;
			for (int i=0; i<n; i++){
				if ( cust[i].mobileNo == target ){
					cout <<" Name : " << cust[i].name << endl;
					cout <<" Mobile no. : " << cust[i].mobileNo << endl;
					cout <<" Bill amount : " << cust[i].billAmount << endl;
					return;
				}
 
			}
			cout << "No user exists with mobile no. " << target << endl;
		}
 
		void adjust(int n,int i){
			while(2*i+1<=n){
				int j = 2*i+1;
				if ((j+1 <= n) and (cust[j+1].mobileNo > cust[j].mobileNo)){
					j++;
					}
				if (cust[i].mobileNo >= cust[j].mobileNo){
						break;
					}
					else{
						swap (cust[i] , cust[j]);
					}
				}
 
			}
 
 
 
		void heapSort(){
			int nn = n;
			for (int i = (nn/2)-1; i >=0; i--){
				adjust(nn-1, i);
			}
			while (nn > 0){
				swap (cust[0] , cust[nn-1]);
				nn--;
				adjust(nn-1,0);
			}
		}
		int binarySearch(){
			long no;
			cout << "Enter the no. to search: ";
			cin >> no;
			int l = 0;
			int r = n - 1;
			while(l <= r){
				int mid = (l+r)/2;
				if(cust[mid].mobileNo == no){ 
					return mid;
				}
				else if(cust[mid].mobileNo < no){
					l = mid + 1;
				}
				else{
					r = mid - 1;
				}
			}
            return -1;
		}
		void printUser(int i){
			if(i == -1) cout << "User not found\n";
			else{
				cout << "Name: " << cust[i].name << endl;
				cout << "Phone No.: " << cust[i].mobileNo << endl;
				cout << "Bill Amount: " << cust[i].billAmount << endl;
			}
			cout << endl;
		}
		void quickSort(int p, int r){
			if(p < r){
				int q = partition(p, r);
				quickSort(p, q - 1);
				quickSort(q + 1, r);
			}
		}
		int partition(int p, int r){
			int x = cust[r].billAmount;
			int i = p - 1;
			for(int j = p; j < r; j++){
				if(cust[j].billAmount <= x){
					i++;
					swap(cust[i], cust[j]);
				}
			}
			swap(cust[i+1], cust[r]);
			return i+1;
		}
};

int main(){
	int n, choice;
	cout << "Enter no. of users: ";
	cin >> n;
	record jio(n);
    while(1){
        cout << "1. Accept records\n2. Display records\n3. Sort using HeapSort ( By Mobile Number )\n";
        cout << "4. Sort using Quick Sort ( By Bill Amount )\n5. Search using Linear Search\n6. Search using Binary search\n7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            jio.accept();
                break;
            case 2:
            jio.display();
                break;
            case 3:
                jio.heapSort();
                break;
            case 4:
				jio.quickSort(0, n - 1);
                break;
            case 5:
				jio.linearSearch();
                break;
            case 6:
				jio.printUser(jio.binarySearch());
                break;
            case 7:
                cout << "Thank You";
                return 0;
        }
    }
}