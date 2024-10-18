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

	student (string n, int r, char c, string d, string db, long a, string b, string ad, long t ){
		name = n,
		roll = r,
		Class = c;
		division = d;
		dob = db;
		aadhar = a;
		blood = b;
		address = ad;
		tel = t;
		count++;
	}
	
	student(){
		name = "XXX";
		roll = 00;
		Class = 'X';
		division = "X1";
		dob = "00/00/0000";
		aadhar = 1234567890;
		blood = "X+";
		address = "ABC street, XYZ";
		tel = 1234567890;
		count++;
	}
	
	student (student &s){
		name = s.name,
		roll = s.roll,
		Class = s.Class;
		division = s.division;
		dob = s.dob;
		aadhar = s.aadhar;
		blood = s.blood;
		address = s.address;
		tel = s.tel;
		cout << "Object Created Successfully" << endl;
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
	cout << name<< endl;
	cout << roll<< endl;
	cout << Class<< endl;
	cout << division<< endl;
	cout << dob<< endl;
	cout << aadhar<< endl;
	cout << blood<< endl;
	cout << address<< endl;
	cout << tel<< endl << endl;
	
}

};

int student::count = 0;

int main(){
	
	student s1 ("Soham", 23 , 'J', "J1" , "03/03/2004" , 1234567890 , "O+" , "Pune, Maharasthra", 9998887776);
	student s1copy (s1);
	student s2 ;
	s2.getinfo();
	s1copy.printinfo();
	s2.printinfo();
	cout << endl << "Total number of students : " << student::showCount;
}