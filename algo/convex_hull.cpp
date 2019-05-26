/*input

*/
//INCOMPLETE CODE INEFFICIENT AND COMPLEX (TO BE SCRAPPED)
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
#define vpii vector < pair < int,int > >
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
#define N 100002

using namespace std;
ll T,n,m;
set<pii> final_result;
typedef struct coeff
{
	int a;
	int b;
	int c;
}coeff;

typedef struct segr
{
	vpii left;
	vpii right;
	vpii same_line;
}segr;

float my_determinant(pii a,pii b, pii c)
{
	float det=0.5*((a.f*(b.s-c.s))-(b.f*(a.s-c.s))+(c.f*(a.s-b.s)));
	return det;
}

segr* mysegregate(vpii &arr,pii min_point,pii max_point)
{
	// watch("in serg");
	vpii left,right,same_line;pii tmp;
	for (int i = 0; i < arr.size(); ++i)
	{
		tmp=arr[i];
		if ((tmp.f==min_point.f && tmp.s==min_point.s)||(tmp.f==max_point.f && tmp.s==max_point.s))
		{
			continue;
		}
		float det=my_determinant(min_point,max_point,tmp);
		if (det>0)
		{
			left.eb(tmp);
			// lflag++;
		}
		if(det<0)
		{
			right.eb(tmp);
			// rflag++;
		}
		else
		{
			same_line.eb(tmp);
		}
		

	}
	segr * seg_ptr=(segr*)(malloc(sizeof(segr)));
	seg_ptr->left=left;
	seg_ptr->right=right;
	seg_ptr->same_line=same_line;
	// watch("out serge");
	return seg_ptr;
}





coeff * line_bw_points(pii P,pii Q)
{
	int a=Q.second - P.second;
	int b = P.first - Q.first;
	int c = a*(P.first) + b*(P.second); 
	coeff * p =(coeff *)(malloc(sizeof(coeff)));
	p->a=a;
	p->b=b;
	p->c=c;
	return p;
}

float point_distance_to_line(pii tmp,coeff * ptr)
{
	int a=ptr->a;
	int b=ptr->b;
	int c=ptr->c;
	float d = fabs((a * tmp.f + b * tmp.s + c)) /  
             (sqrt(a * a + b * b)); 

    return d;
}

void myhull(vpii &arr,pii lp,pii rp)
{
	// watch("in hull");
	// pair <int,pii> coeff;
	coeff * ptr= line_bw_points(lp,rp);
	float max_dist=0;
	pii max_point;
	for (int i = 0; i < arr.size(); ++i)
	{
		float dist=point_distance_to_line(arr[i],ptr);
		if (dist>max_dist)
		{
			max_dist=dist;
			max_point=arr[i];
		}
	}
	segr * seg_ptr=mysegregate(arr,lp,max_point);
	if (max_dist==0)
	{
		// watch("outhull");
		return;//can add points in same line if required (not done as of now)
	}
	final_result.insert(max_point);
	
	myhull(seg_ptr->left,lp,max_point);
	myhull(seg_ptr->right,rp,max_point);


}

int main()
{
	// std::ios::sync_with_stdio(false);
	
	// ll p=0,q=0,tmp=0,sum=0; //tmp variable
	// watch(0);
	vpii point_set;
	pii tmp;
	cin>>n;
	// vpii point_set[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp.f>>tmp.s;
		point_set.push_back(make_pair(tmp.f,tmp.s));
		// watch("input");

	}
	// int o,w;
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin>>o>>w;
	// 	point_set[i].f=o;
	// 	point_set[i].s=w;
	// }
	
	// watch(1);
	int min=999999,max=-999999;
	pii min_point,max_point;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if (point_set[i].f<min)
		{
			min=point_set[i].f;
			min_point=point_set[i];
		}
		if (point_set[i].f>max)
		{
			max=point_set[i].f;
			max_point=point_set[i];
		}
	}
	final_result.insert(min_point);
	final_result.insert(max_point);
	watch(2);

	segr * seg_ptr=mysegregate(point_set,min_point,max_point);
	watch(3);
	myhull(seg_ptr->left,min_point,max_point);
	myhull(seg_ptr->right,min_point,max_point);
	// watch("terms processed");
	cout << "the points that form the hull are as follows:"<< endl;
	
	for(auto x: final_result)
	{
		 cout<<x.first<<" "<<x.second<<endl;
	}

	return 0;
}

