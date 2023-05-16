#include <bits/stdc++.h>
using namespace std;

//function to multiply matrices
int** multiply(int** a, int** b, int** result, int r1, int col1, int r2, int col2)
{
	assert(col1 == r2);
	result = new int*[r1] ;	//allocating memory in heap to safely return the result
	for (int i = 0; i < r1; i++)
	{
		result[i] = new int[col2] ; 
		for (int j = 0; j < col2; j++)
		{
			result[i][j] = 0 ;
			for (int k = 0; k < r2; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;

	ifstream is("HaKaPr_input.txt") ;	//opening file to read input matrices to multiply
	ofstream os("t_a.txt");	//creating file to record time to perform multiplication in milliseconds
	clock_t start, end;
	double t ;
	int c1, c2, r1, col1, r2, col2;
	is>>c1>>c2 ;
	for (int i = 0; i < (c1+c2)/2; i++)
	{
		is>>r1>>col1 ;
		int** m1 = (int**)malloc(sizeof(int*)*r1) ;

		for (int j = 0; j < r1; j++)
		{
			*(m1+j) = (int*)malloc(sizeof(int)*col1) ;
			for (int k = 0; k < col1; k++)
			{
				is>>m1[j][k] ;
			}
		}

		
		is>>r2>>col2 ;
		int** m2 = (int**)malloc(sizeof(int*)*r2) ;

		for (int j = 0; j < r2; j++)
		{
			*(m2+j) = (int*)malloc(sizeof(int)*col2) ;
			for (int k = 0; k < col2; k++)
			{
				is>>m2[j][k] ;
			}
		}


		t=0 ;
		
		for (int l = 0; l < 5; l++) {
			start = clock();
			int** result ; 	
			result = multiply(m1, m2, result, r1, col1, r2, col2);	//performing matrix multiplication
			for(int ii=0; ii<r1; ii++) delete[] result[ii] ;	//clearing memory after use
			delete[] result ;
			end = clock();
			t += double(end - start) / double(CLOCKS_PER_SEC);
		}

		free(m1) ;	//clearing memory after use
		free(m2) ;
		
		t *= 200 ;
		os << t << " ";
		
	}

	return 0;
}
