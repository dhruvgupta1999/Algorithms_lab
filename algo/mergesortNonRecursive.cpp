

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
    #define watch(x) cout << (#x) << " is " << (x) << endl
    #define N 20002
	
	using namespace std;

	int main()
	{
		
		std::ios::sync_with_stdio(false);
		ll T,n,m;
		ll p,q,tmp; //tmp variable
		//cin>>T;
		string line;
		//cin.ignore(); //must be there when using getline(cin, s)
		while(getline( cin, line ))
		{
			vi a;
			istringstream iss( line );
			while(iss>>tmp)
			{
				
				a.eb(tmp);
			}

			n=a.size();
			
			int b[n];
			if (n==1)
			{
				cout << a[0]<< endl;
				continue;
			}

			int i =2;
			while(i<=2*n)
			{
				for (int j = 0; j < n/i + 1; ++j)
				{
					int low=i*j;
					int high=i*(j+1);
					
					int mid=(low+high)/2;
					if(high>n)
						high=n;
					p=low;
					q=mid;
					for (int k = 0; k < high-low; ++k)
					{
						/* code */
						if (p>=mid && q<high)
						{
							b[k+(i*j)]=a[q];
							q++;
						}
						else if (q>=high && p<mid)
						{
							b[k+(i*j)]=a[p];
							p++;
						}
						else if (a[p]<=a[q])
						{
							/* code */
							b[k+(i*j)]=a[p];
							p++;

						}
						else if (a[q]<a[p])
						{
							b[k+(i*j)]=a[q];
							q++;
						}

					}
				}
				i*=2;

				for (int j = 0; j < n; ++j)
				{
					a[j]=b[j];
				}


			}
			for (int j = 0; j < n; ++j)
			{
				cout << a[j]<<" ";
				
			}
			cout<< endl;
			
		}
		return 0;
	}

