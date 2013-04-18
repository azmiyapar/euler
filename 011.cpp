/*


In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 20×20 grid?
http://projecteuler.net/problem=11
*/
/*
Yukaridaki 20×20 lik matristeki herhangi sıradaki (sağa, sola, aşağı, yukarı, çapraz) dört sayının çarpımı en fazla kaçtır?
http://fatihsultan.wordpress.com/2006/09/27/euler-projesi-10-11-12-soru/
*/
/*
real  0m0.002s
user	0m0.000s
sys	0m0.000s
*/
/*
1.Başla
2.Dosyayı oku ,read_file()
2.1.Sayıları 20*20 lik 'number' matrisine ata
3.fromlefttoright_and_fromuptodown()
3.1.Yatay ve dikey çarpımları hesapla
3.2.Eğer çarpım sonucu en büyük değer burdaysa değeri 'max' değişkenine ata
4.diagonalfromlefttoright()
4.1.sol yukardan sağ aşağı yönde çapraz çarpımları hesapla
4.2.Eğer çarpım sonucu en büyük değer burdaysa değeri 'max' değişkenine ata
5.diagonalfromrighttoleft()
5.1.Sağ yukarıdan sol aşağıya çapraz çarpımları hesapla
5.2.Eğer çarpım sonucu en büyük değer burdaysa değeri 'max' değişkenine ata
6.En büyük çarpımı, 'max' ı, ekrana yaz.
7.Bitir

*/

#include  <iostream>
#include  <fstream>
#include <cstring>

using namespace std;

	const int COLS = 20;
	const int ROWS = 20;
	int number[ROWS][COLS];
	const char *FILENAME = "file.txt";
	int maximum = 0;


void read_file(){
	int col = 0, row = 0;

		ifstream file;
    file.open( FILENAME );

    if(!file.is_open()) {
        cout << "Error" << endl;
    } else {
        string line;
        while(!file.eof())
        {
					if(row == ROWS)
						break;
            getline(file, line);
            char *ch;
        		ch = new char[line.size()+1];
						strcpy(ch,line.c_str());

			sscanf(ch, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&number[row][col], &number[row][col+1], &number[row][col+2], &number[row][col+3], &number[row][col+4], &number[row][col+5], &number[row][col+6], &number[row][col+7], &number[row][col+8], &number[row][col+9], &number[row][col+10], &number[row][col+11], &number[row][col+12], &number[row][col+13], &number[row][col+14], &number[row][col+15], &number[row][col+16], &number[row][col+17], &number[row][col+18], &number[row][col+19] );

				col = 0;
				row++;
        }
				file.close();
    }

}

void 	fromlefttoright_and_fromuptodown(){
	int	productLeftToRight, productUpToDown;
	// LEFT TO RIGHT & UP TO DOWN
	for(int i=0; i<ROWS-3; i++)
	{
		for(int j=0; j<COLS-3; j++)
		{
			//LEFT TO RIGHT
			productLeftToRight = number[i][j] * number[i][j+1] * number[i][j+2] * number[i][j+3];
			//UP TO DOWN
			productUpToDown = number[i][j] * number[i+1][j] * number[i+2][j] * number[i+3][j];

			if(productLeftToRight > maximum){
				maximum = productLeftToRight;
			}
			if(productUpToDown > maximum){
				maximum = productUpToDown;
			}
		}
	}

}

void	diagonalfromlefttoright(){
	int productDiagonalLeftToRight;
// DIAGONAL LEFT TO RIGHT
	for(int i=0; i<ROWS-3; i++)
	{
		for(int j=0; j<COLS-3; j++)
		{
			productDiagonalLeftToRight = number[i][j] * number[i+1][j+1] * number[i+2][j+2] * number[i+3][j+3];
			if(productDiagonalLeftToRight > maximum)
				maximum = productDiagonalLeftToRight;
		}
	}

}

void diagonalfromrighttoleft(){
	int productDiagonalRightToLeft;
	// DIAGONAL RIGHT TO LEFT
	for(int i=0; i<ROWS-3; i++)
	{
		for(int j=3; j<COLS; j++)
		{
			productDiagonalRightToLeft = number[i][j] * number[i+1][j-1] * number[i+2][j-2] * number[i+3][j-3];
			if(productDiagonalRightToLeft > maximum)
				maximum = productDiagonalRightToLeft;
		}
	}
}

int main(){

	read_file();
	fromlefttoright_and_fromuptodown();
	diagonalfromlefttoright();
	diagonalfromrighttoleft();
	

	cout << "maximum: " << maximum << endl;
	return 0;
}
