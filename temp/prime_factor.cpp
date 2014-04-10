#include <iostream>
#include <vector>

#define NUM 30
using namespace std;



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
	vector<int> factors;
	while(i < NUM)
	{
		if((0 == NUM% i ) and isPrime(i)) 
		{
			factors.push_back(i);
		}
		i++;
	}	
	
	for(int i = 0; i < factors.size(); ++i)
	{
		cout<<factors[i]<<endl;
		
	}
	return 0;
}
