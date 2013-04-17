/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
http://projecteuler.net/problem=10
*/
/*
İki milyondan küçük tüm asal sayıların toplamı nedir?
http://fatihsultan.wordpress.com/2006/09/27/euler-projesi-10-11-12-soru/
*/
/*
real  2m28.699s
user	2m24.449s
sys	0m0.096s
*/
#include  <iostream>

using namespace std;

bool isPrime(int n){

	for(int i=3; i<=n/2; i+=2)
		if(n % i == 0)
			return false;

	return true;
}

int main()
{
	const int TARGET = 2000000;
//cift asal sadece 2 dir
//for dongusunde cift sayilarin kontrol edilmesine gerek yoktur.
	long int sumofprimes =2;
	for(int i=3; i<TARGET; i+=2)
	{
		if( isPrime(i) == true )
			sumofprimes += i;
	}

	cout << "result: " << sumofprimes << endl;

	return 0;
}
