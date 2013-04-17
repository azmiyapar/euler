For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
http://projecteuler.net/problem=9
*/
/*
a+b+c=1000 eşitliğini sağlayan a,b,c Pisagor üçlülerinin çarpımı kaçtır?
(not: Bir Pisagor üçlüsü, a < b < c ve a² + b² = c² ifadelerini sağlayan üç doğal sayıdır.)
http://fatihsultan.wordpress.com/2006/09/21/euler-projesi-7-8-9-soru/
*/
/*
real  0m0.070s
user	0m0.064s
sys	0m0.004s
*/
#include  <iostream>

using namespace std;

int main()
{
	
	const int TARGET = 1000;
	int a, b, c, sum;

	// a < b < c
	for(int i=1; i<TARGET; i++)	//c
	{
		for(int j=1; j<i; j++) //b < c
		{
			for(int k=1; k<j; k++)//a < b
			{
				sum = i + j + k;
				if(sum > TARGET)
					break;
				else if( sum == TARGET)
				{
					if(k*k + j*j == i*i ) // a*a + b*b == c*c
					{
						cout << "a*b*c = " << i*j*k << endl;
						return 0;//sonuc bulununca programı sonlandir
					}
				}	
			}
		}
	}
	return 0;
}
