#include<bits/stdc++.h>
using namespace std ;


void generate(int n, int m, ofstream &os ) {
	os<<n<<" "<<m<<endl ;
	for (int i = 0; i < n; i++)
	{ 
		for(int j=0; j<m; j++) {
			os<<rand()%10+1<<" " ;
		}
		os<<endl ;
	}
	//os<<endl ;
}


int main(int argc, char const *argv[])
{
	ofstream os("input.txt") ;
	os<<50<<" "<<20<<endl ;

	for(int i=4; i<=200; i+=4) {
		os<<i<<" "<<i<<endl ;
		for(int j=0; j<i; j++) {
			for(int k=0; k<i; k++) {
				os<<rand()%10+1<<" " ;
			}
			os<<endl ;
		}
		//os<<endl ;
	}

	//os<<20<<endl<<endl ;
	
	generate(4, 2, os) ;
	generate(2, 8, os) ;
	generate(10, 20, os) ;
	generate(20, 30, os) ;
	generate(50, 5, os) ;
	generate(5, 10, os) ;
	generate(47, 34, os) ;
	generate(34, 67, os) ;
	generate(101, 49, os) ;
	generate(49, 99, os) ;
	generate(64, 11, os) ;
	generate(11, 25, os) ;
	generate(46, 23, os) ;
	generate(23, 46, os) ;
	generate(6,37, os) ;
	generate(37, 3, os) ;
	generate(46, 72, os) ;
	generate(72, 31, os) ;
	generate(51, 31, os) ;
	generate(31, 62, os) ;


	return 0;
}