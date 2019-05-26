//MATRIX MULTIPLICATION IS ASSOCIATIVE 

/*input

*/
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
#define vpi vector <pair<int,int>>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 100002

using namespace std;

class matrix_chain
{
public:

	int num_of_matrices;
	int arr[T][T]={0};

	void inputfn()
	{
		int n,m;
		cout << "Enter number of matrices"<< endl;
		cin>>num_of_matrices;	
		while(num_of_matrices--)
		{
			cin>>n>>m;
			if (v.size()==0)
			{
				mchain.eb(mp(n,m));
			}
			else if (v.back().s==n)
			{
				mchain.eb(mp(n,m));
			}
			else
			{
				cout << "Invalid value entered...Enter this matrix again."<< endl;
				num_of_matrices++;
			}
		
		}
	}

	void best_mult_path()
	{
		int range=1;
		int lowside=0;
		while(range+lowside<num_of_matrices)
		{
			
			while(range+lowside<num_of_matrices)
			{

			}
			lowside=0;
			range++;
		}

	}

	void outputfn()
	{
		
	}


};


int main()
{
	
}

