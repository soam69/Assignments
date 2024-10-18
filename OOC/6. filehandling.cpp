/* Soham Pankhade 
PRN – 1032233543 */
#include <iostream>
#include <fstream>

using namespace std;
	int uppCase = 0;
	int letter = 0;
	int digit = 0;
	int whSpace = 0;
	int vowel = 0;

void counter(char a){
	if ( a >= 'A' && a <= 'Z' ){
		uppCase++;
	}
	if ( (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') ){
		letter++;
	}
	if ( a >= '0' && a <= '9' ){
		digit++;
	}
	if ( a == ' ' ){
		whSpace++;
	}
	if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' ){
		vowel++;
	}
}


int main(){
	char current;
	ifstream file ("book.txt");
	while (!file.eof()){
		current = file.get();
		counter (current);
	}
	file.close();
	
	ofstream out ("dest.txt");
	out << "The number of Upper case characters is : " << uppCase << endl;
	out << "The number Letters is : " << letter << endl;
	out << "The number of digits is : " << digit << endl;
	out << "The number of White spaces is : " << whSpace << endl;
	out << "The number of vowels is : " << vowel << endl;
	out.close();
	return 0;
}
