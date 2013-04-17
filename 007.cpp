/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
http://projecteuler.net/problem=7
*/
/*
10001. sıradaki asal sayı nedir? (not: Asal sayılar: 2,3,5,7,11,…)
http://fatihsultan.wordpress.com/2006/09/21/euler-projesi-7-8-9-soru/
*/
/*
real  0m1.018s
user	0m1.008s
sys	0m0.000s

*/
#include  <iostream>

using namespace std;

/**
*@return n asal ise true, degilse false dondur
*/
bool isPrime(int n){
	
	for(int i=2; i<=n/2; i++)
		if(n % i == 0)
			return false;

	return true;
}

int main(){
	const int GOAL = 10001;

	int counter = 0; 
	int lastPrime;
	for(int i=2; ; i++){
		if( isPrime(i) ){
		//cout << counter << ". " << i << endl;
			counter++;
		}

		if(counter == GOAL){
			lastPrime = i;
			break;
		}
	}

	cout << "result: " << lastPrime << endl;
	return 0;
}
