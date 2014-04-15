/*
* Author: Hanif Ahmed
* This program implements the sieve of erastones to find primes numbers from
* 2 to n.//
*
*/




#include <fstream>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
/*
* function that finds primes from 2 to n.
*
*
*/
vector<int> primes(int n)
{
	//only need to check up to sqrt(n).
	int uBound = (int) sqrt(n);
	vector<int> primes;
	vector<int> primes2;	

	//Populate a vector with ints from 2 to n.
	for(int i = 2; i < n; ++i)	
	{
		primes.push_back(i);
	}
	
	//Replace the composite numbers with 0.
	for(int step = 2; step <= uBound; step++)
	{
		for(int i = step-1; i < primes.size(); i++)
		{
			if(0 == primes[i] % step)
				primes[i] = 0;
		}
	}

	//Copy the non zero terms (primes) to 
	//a new vector.
	for(int i = 0; i < primes.size(); ++i)
	{

		if(0 != primes[i])
			primes2.push_back(primes[i]);
	}	

	return primes2;
}

int main()
{

	//vector that holds first 100 primes
	vector<int> myvect = primes(1000);
	
	for(int i = 0; i < myvect.size(); ++i)
	{
		cout<<myvect[i]<<endl;

	}

	//Uncomment to write primes to a file.
	/*
	ofstream myfile;
	myfile.open("primeNums.txt");
	for(int i = 0; i < myvect.size(); i++)
	{
		myfile<<myvect[i]<<"\n";
	}
	
	myfile.close();
//	cout<<myvect[10000]<<endl;
	*/


	return 0;	
}
