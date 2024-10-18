#include <iostream>
using namespace std;

class complex {
	float real;
	float imag;
	public :
		complex (){
			real = 0;
			imag  = 0;
		}
		complex (float rl, float ig){
			real = rl;
			imag = ig;
		}
		
		void setComplex() {
			cout << "Enter value of real number : ";
			cin >> real;
			cout << "Enter value of imaginary number : ";
			cin >> imag;
		}
		
		void printComplex() {
			cout << "Complex number : " << real << "+" << imag << "i" << endl;
		}
		
		complex operator + (complex num){
			complex temp;
			temp.real = real + num.real;
			temp.imag = imag + num.imag;
			return temp;
		}
		
		complex operator * (complex num){
			complex temp;
			temp.real = real * num.real - imag * num.imag;
			temp.imag = real*num.imag + num.real * imag;
			return temp;
		}
		
		friend complex operator - (complex a, complex b);
		friend complex operator / (complex a, complex b);
};

	complex operator - (complex a, complex b){
		complex temp;
		temp.real = a.real - b.real;
		temp.imag = a.imag - b.imag;
		return temp;
	}
	
	complex operator / (complex a, complex b){
		complex temp;
		temp.real = (a.real*b.real + a.imag*b.imag)/(b.real*b.real + b.imag*b.imag);
		temp.imag = (a.imag*b.real - a.real*b.imag)/(b.real*b.real + b.imag*b.imag);
		return temp;
	}
int main (){
	complex p;
	p.setComplex();
	complex q;
	q.setComplex();
	complex w = p + q;
	complex x = p - q; 
	complex y = p * q;
	complex z = p / q;
	w.printComplex();
	x.printComplex();
	y.printComplex();
	z.printComplex();
	return 0;
}
