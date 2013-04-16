/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
http://projecteuler.net/problem=4
*/
/*
İki üç basamaklı sayının çarpımı ile edilen en büyük Palindrome sayı nedir? (not: Bir palindromik sayı hem baştan hem sondan aynı şekilde okunan sayıdır. İki basamaklı iki sayının çarpımı olarak yazılabilen en büyük palindromik sayı 91×99=9009 dur.)
http://fatihsultan.wordpress.com/2006/09/18/euler-projesi-4-5-6-soru/
*/
/*
real  0m0.824s
user	0m0.816s
sys	0m0.004s
*/

#include  <iostream>
#include  <vector>
#include  <math.h>

using namespace std;

/**
once birler basamagi vector'e atanır, sonre onlar sonra yuzler...
*/
vector<int> parse(int n)
{
	vector<int> v;
	int number = n;
	int digit;
	while(number  >= 10)//'sayi' bir basamakli sayidan buyukse 
	{
		digit = number % 10;
		v.push_back(digit);
		number /= 10;
	}
	//'sayi' bir basamakli ise
	digit = number % 10;
	v.push_back(digit);

	return v;
}

/**
*@param vec sayisi palindrom ise 'true' dondur, degilse 'false' dondur
*dizinin sol ve sag basindan karsilastirma yapmaya baslanir,
*her cevrimde bir ictekilere bakilir
*/
bool isPalindrome(std::vector<int> vec)
{
	for(int i=0;i<vec.size(); i++)
	{
		if( vec[i] != vec[vec.size()-i-1])
			return false;
	}
	return true;

}

int main(){
	const int NUMBER = 999;
	int product;
	int max=0;
	for(int i=NUMBER; i>0; i--) 
	{
		for(int j=NUMBER; j>0; j--) 
		{
			product = i * j;
			if( isPalindrome( parse(product) ) == true ) 
			{
				if(max < product)
					max = product;
				break;
			}
		}
	}

	cout << "max palindrome: " << max << endl;

	return 0;
}
