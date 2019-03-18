#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int> findPrimes(int bound)
{
	vector<int> primes;
	for(int j=2;j<=bound;j++)
	{
		bool flag=true;
		for(int i=2;i<=(int)sqrt(j);i++)
		{
			if(j%i==0)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			cout<<"prime is : "<<j<<endl;
			primes.push_back(j);
		}

	}
	return primes;
}

int findRange(vector<int> vec)
{
	int result=1;
	for(auto it=vec.begin();it!=vec.end();it++)
	{
		result*=*it;
	}
	return result;

}
vector<int> findCoPrimes(int m)
{
	vector<int> vec;
	for(int i=2;i<m;i++)
	{
		if(__gcd(i,m)==1)
			vec.push_back(i);
	
	}
	return vec;

}

vector<int> BGWProtocol(vector<int> p,vector<int> q,int m)
{
	int n=p.size();
	int l=(int)(n-1)/2;
	vector<int> shareStorage_f[n];
	vector<int> shareStorage_g[n];
	auto it1=p.begin();
	auto it1=p.begin();
	auto it2=q.begin();
	while(it1!=p.end())
	{
		vector<int> f,g;
		f.pus_back(*it1);
		g.push_back(*it2);
		for(int j=0;j<l;j++)
		{
			f.push_back(rand()%m+1);
			g.pus_back(rand()%m+1);
		}
		for(int j=1;j<=n;j++)
		{
			
		
		}
		it1++;
		it2++;
	}
}
int f(vector<int> coeff,int x)
{
	int result=coeff.at(0);int i=1;
	for(auto it=coeff.begin()+1;it!=coeff.end();it++)
	{
		result+=*it*pow(x,i);
		i++;
	}
	return result;
}


int main()
{
	int bound =5;
	vector<int> primes=findPrimes(bound);
	vector<int>::iterator it;
	int m=findRange(primes);
	cout<<m<<endl;



return 0;
}

