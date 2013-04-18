/*
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
http://projecteuler.net/problem=12
*/
/*
 Üçgen sayılar doğal sayıların toplaması ile elde ediliyor. Mesela 7. üçgen sayı 1+2+3+4+5+6+7=28 dir. İlk on terim ise 1,3,6,10,15,21,28,36,45,55,… olur.
Şimdi bu sayıları çarpanlarına ayırdığımızda,
   1: 1
   3: 1,3
   6: 1,2,3,6
  10: 1,2,5,10
  15: 1,3,5,15
  21: 1,3,7,21
  28: 1,2,4,7,14,28 bulunur.
Göründüğü üzere 7. üçgen sayının 5 tane tam böleni vardır. 500 den fazla tam böleni olan ilk üçgen sayı nedir?
http://fatihsultan.wordpress.com/2006/09/27/euler-projesi-10-11-12-soru/
*/
/*
real  9m42.539s
user	9m42.468s
sys	0m0.000s
*/
#include  <iostream>

using namespace std;

int divCount(int n)
{
	int count = 1;// n: '1',
	for(int i=2; i<=n/2; i++)
		if(n % i == 0)
			count++; // n: 1 , '...' , n
	
	count++; // n: 1, ...., 'n' 
	
	return count;
}

int main(){
	const int LIMIT = 500;
	int triangle = 1;
	int counter, result, number=1;

	while(true)
	{
		counter = divCount(number);
		//scout << counter << " , " << number << endl;
		if( counter > LIMIT )
			break;
	
		triangle++;
		number+= triangle;
	}
	
	cout << "triangle: " << triangle << endl;
	cout << "number: " << number << endl;

	return 0;
}