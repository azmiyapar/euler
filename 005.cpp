/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
http://projecteuler.net/problem=5
*/
/*
1 den 20 (dahil) ye kadar her bir sayı ile tam bölünebilen en küçük sayı kaçtır?
http://fatihsultan.wordpress.com/2006/09/18/euler-projesi-4-5-6-soru/
*/
/*
real  0m7.898s
user	0m7.892s
sys	0m0.000s
*/
/*
Not:
Sayiyi aramaya 1 den başlamaya gerek yok, asal sayilarin çarpımından başlanabilir.

1.Başla
2.1-20 arasındaki sayilari vec'e ata
3.döngiye gir
4.start sayisindan kontrole başla
start sayisini, vec'teki sayilara(1,2,3,...,20) böl
5.Eğer tam bölünmezse control = false yap ve kontrol edilen sayiyi 1 arttırıp adım 4'e git
Eğer tam bölnürse aranan sayı budur. sayıyı ekrana yaz ve döngüden çık
6.Bitir
*/
#include  <iostream>
#include  <vector>

using namespace std;

int main(){

	const int TARGET = 20;
	int start = 2*3*5*7*11*13*17*19;
	bool control;

	vector<int> vec;
	for(int i=1; i<=TARGET; i++)
		vec.push_back(i);

	for(int i=start; ; i++)
	{
		control = true;
		for(int j=0; j<vec.size(); j++)
		{
			if(i % vec[j] != 0)//tam bolunemez ise ic donguden cik,
			{
				control = false;
				break;
			}
		}
		
		if(control == true)//control, false bloguna girmediyse, hepsine tam bolunmustur
		{
			cout << i << endl;//bulunan sayiyi yazdir
			break;//sayi bulundu dis donguden cik
		}
	}

	return 0;
}
