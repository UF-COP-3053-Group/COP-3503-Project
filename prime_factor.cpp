#include <iostream>
using namespace std;

const unsigned long  upperBound =  6008;
 

bool isPrime(int n)
{
	int j = 2;
	while(j < n)
	{
		if(0 == n % j)	
			return false;
		j++;	
	}
	return true;
}

int main()
{
	int i = 2;
	int max;	
	while(i < upperBound)
	{
		if((0 == upperBound % i ) and isPrime(i)) 
		{
			max = i;
		}
		i++;
	}	
	cout<<max<<endl;
	return 0;
}
