/*	
	Name : Soham Pankhade
	PRN : 1032233453
	Roll No. 23 :
*/

#include <iostream>
using namespace std;

class student {
private : 
	string name;
	int roll;
	char Class;
	string division;
	string dob;
	unsigned long long aadhar;
	string blood;
	string address;
	unsigned long long tel;
	static int count;

public :
        student (){
            count++;
        }
        static int showCount (){
		return count;
	}


	void getinfo (){
	cout << "Enter your name : "<< endl;
	getline (cin>>ws,name);
	cout << "Enter roll no : " << endl;
	cin >> roll;
	cout << "Enter class : " << endl;
	cin >> Class;
	cout << "Enter division : " << endl;
	getline (cin>>ws,division);
	cout << "Enter dob : " << endl;
	getline (cin>>ws,dob);
	cout << "Enter aadhar no. : " << endl;
	cin >> aadhar;
	cout << "Enter blood group : " << endl;
	getline (cin>>ws,blood);
	cout << "Enter address : " << endl;
	getline (cin>>ws,address);
	cout << "Enter telephone no. : " << endl;
	cin >> tel;
}

	void printinfo (){
	cout << "Name : "<< name<< endl;
	cout << "Roll No : "<< roll<< endl;
	cout << "Class : "<< Class<< endl;
	cout << "Division : "<< division<< endl;
	cout << "Date of birth : "<< dob<< endl;
	cout << "Aadhar No. : "<< aadhar<< endl;
	cout << "Bloog Group : "<< blood<< endl;
	cout << "Address : "<< address<< endl;
	cout << "Telephone No.: "<< tel<< endl << endl;
	
}

    ~student (){
    }
};
int student::count = 0;

int main(){
	
	student s1 ;
    student s2;
	s1.getinfo();
    s2.getinfo();
    s1.printinfo();
	s2.printinfo();
	cout << endl << "Total number of students : " << student::showCount() << endl;

}