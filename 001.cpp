/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
http://projecteuler.net/problem=1
*/
/*
1000 den küçük 3 veya 5 in katı olan doğal sayıların toplamı nedir?
http://fatihsultan.wordpress.com/2006/09/15/euler-projesi-1-2-3-soru/
*/
/*
real  0m0.002s
user	0m0.000s
sys	0m0.000s
*/
#include <iostream>

using namespace std;

int main(){

	const	int LIMIT = 1000;
	int total = 0;
	for(int i=3; i<LIMIT; i++){
		if(i%3==0 || i%5==0)
			total += i;
	}

	cout << "result: " << total << endl;

	return 0;
}
