/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
http://projecteuler.net/problem=3
*/
/*
“600851475143” sayısının en büyük asal çarpanı kaçtır? 
http://fatihsultan.wordpress.com/2006/09/15/euler-projesi-1-2-3-soru/
*/
/*
real  0m17.957s
user	0m17.949s
sys	0m0.004s
*/
#include  <iostream>
#include  <vector>

using namespace std;

vector<unsigned long int> factors;

/*
asal sayı kontrolu
@param n, asallik kontrolu yapilan sayi
@return n, asal ise true ; asal degil ise false
*/
bool isPrime(unsigned long int n)
{
	if(n % 2 == 0) // cift ise asal degil
		return false;

	for(int i=3; i<=n/2; i+=2) // 3-5-7.. tek sayilari dene
	{
		if(n % i == 0) 
			return false;
	}
	return true;
}

void factor(unsigned long int n)
{
	for(int i=2; i<=n/2;i++)
	{
		if(n % i == 0)//i sayisi NUMBER'in boleni ise
		{
			if( isPrime(i) == true)// ve o bolen sayida asal ise
				factors.push_back(i);//vector'e ekle
		}
	}
}

int main(){

	const unsigned long int NUMBER = 600851475143;

	factor(NUMBER);

//	for(int i=0; i<factors.size(); i++)
//		cout << factors[i] << endl;

	//en son eklenen sayi en buyuktur
	cout << "max prime factor: " << factors[factors.size() - 1];
	return 0;
}
