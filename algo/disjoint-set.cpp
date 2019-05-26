
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	
	using namespace std;
	
int djsize;
int *djset;

void makeset(int djset_size)                 //implementation from narsimha karumanchi
{
	djset=new int[djset_size];
	djsize=djset_size;
	for (int i = 0; i <djsize; ++i)
	{
		djset[i]=-1;
	}
}

int find(int X)
{
    if(!(X>=0 && X<djsize))
    	return -1;
    if (djset[X]<0)
    {
    	return X;
    }
    else
    	return find(djset[X]);
}

void unionbysize(int root1,int root2)
{
	int a=find(root1);
	int b=find(root2);
	if (a==b)
	{
		return;
	}
	if (djset[a]<djset[b])
	{
		djset[a]+=djset[b];
		djset[b]=a;
	}
	else
	{
		djset[b]+=djset[a];
		djset[a]=b;
	}
}

int main()
	{
		makeset(20);
		unionbysize(1,3);
		unionbysize(2,7);
		unionbysize(14,3);
		unionbysize(8,3);
		unionbysize(12,7);

cout << "output starts here"<< endl;

		cout << find(1)<< endl;
		cout << find(3)<< endl;
		cout << find(12)<< endl;
		cout << find(7)<< endl;
		cout << find(8)<< endl;
		
		cout << "output ends here"<< endl;
		
		
		
	}

