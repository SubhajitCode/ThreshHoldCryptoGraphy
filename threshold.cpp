#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int fn(vector<int> coeff,int x)
{
	int result=coeff.at(0);int i=1;
	for(auto it=coeff.begin()+1;it!=coeff.end();it++)
	{
		result+=*it*pow(x,i);
		i++;
	}
	return result;
}

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
	int n = p.size();
	int l=(int)(n-1)/2;
	vector<int> shareStorage_f[n+1];
	vector<int> shareStorage_g[n+1];
	vector<int> N;
	auto it1=p.begin();
	auto it2=q.begin();
	while(it1!=p.end())
	{
		vector<int> f,g;
		f.push_back(*it1);
		g.push_back(*it2);
		for(int j=0;j<l;j++)
		{
			f.push_back(rand()%m+1);
			g.push_back(rand()%m+1);
		}
		for(int j=1;j<=n;j++)
		{
			shareStorage_f[j].push_back(fn(f,j));
			shareStorage_g[j].push_back(fn(g,j));
		
		}
		it1++;
		it2++;
	}
	for(int i=1;i<=n;i++)
	{
		int sum1=0,sum2=0;
		for(int j=0;j<n;j++)
		{
			sum1+=shareStorage_f[i].at(j);
			sum2+=shareStorage_g[i].at(j);
				
		}
		N.push_back(sum1*sum2);
	}
	
	return N;

}

float lambda(vector<int> x,int j) //calculates lagrangian coefficients
{
	j--;
      int n=x.size();float prod=1;
      for(int i=0;i<n;i++)
      {
	      if((i)!=j)
		      prod *=(float)(x.at(i)/(x.at(i)-x.at(j)));
      
      }      

      return prod;//value of lambda at j
}

int BGWProduct(vector<int> p,vector<int> q,int m)
{
	vector<int> N=BGWProtocol(p,q,m);
	int n=p.size();float sum=0;
	vector<int> x;
	for(int i=1;i<=n;i++)
	{
		x.push_back(i);
	}//x=1...n
	vector<float> lambdas;
	for(int i=1;i<=n;i++)
		lambdas.push_back(lambda(x,i));
	for(int i=0;i<n;i++)
		sum +=N.at(i)*lambdas.at(i);

return (int)sum;
}




int main()
{
	int bound =5;
	vector<int> primes=findPrimes(bound);
	vector<int>::iterator it;
	int m=findRange(primes);
	cout<<m<<endl;
	vector<int> p={2,2,3},q={4,4,3};
	cout<<"the product is : "<<BGWProduct(p,q,m)<<endl;



return 0;
}

