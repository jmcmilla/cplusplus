//Alec Tussey
//for loop prime

#include <iostream>
using namespace std;

int main (){
long int var, i;
	cout << "Please enter integer. Code will break if anything but numbers are used. Don't be a jerk" << endl;
	cin >> var;
	for(i=2; i < 1000; i++){
		if(var % i == 0){
			cout << var << " is not prime" << endl;
			break;
		}
		else{
			cout << var << " is prime" << endl;
			break;
		}
	}
		return 0;
}
