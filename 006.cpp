/*
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
http://projecteuler.net/problem=6
*/
/*
İlk 100 sayının kareleri toplamı ile toplamının karesinin farkı kaçtır? (not: ilk 10 sayının kareleri toplamı: 1² + 2² + … + 10² = 385 ve ilk 10 sayının toplamının karesi: (1 + 2 + … + 10)² = 55² = 3025 ise farkı 3025 385 = 2640 tır.)
http://fatihsultan.wordpress.com/2006/09/18/euler-projesi-4-5-6-soru/
*/
/*
real  0m0.002s
user	0m0.000s
sys	0m0.000s
*/
/*
1.Başla
2.Döngüye gir
3.Her sayını karesini al
4.Kareleri squaresofnumbers değişkeninde topla
5.Döngüden çık
6.Döngüye gir
7.sayilari sumofnumbers değişkeninde topla
8.sumofnumbers'in karesini al ve yine sumofnumbers değişkenine ata
9.farkları yazdir
10.Bitir
*/
#include  <iostream>

using namespace std;

int main(){
	const int LIMIT = 100;
	int sumofnumbers = 0, squaresofnumbers = 0;

	//karelerin toplami
	for(int i=1; i<=LIMIT; i++)
		squaresofnumbers += i*i;

	//toplamlarin karesi
	for(int i=1; i<=LIMIT; i++)
		sumofnumbers += i;
	sumofnumbers = sumofnumbers * sumofnumbers;

	cout << sumofnumbers - squaresofnumbers << endl;
	return 0;
}
