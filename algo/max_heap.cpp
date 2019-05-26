#include <bits/stdc++.h>
using namespace std;

int arr[1000];int n;
void Max_heapify()
{
	for(int i =(int)floor(n/2.0);i>0;i--)
	{
		
		
			bool heap=false;
			int k=i;
			int v=arr[k];
			while(heap!=true)
			{
				int j=2*k;
				if(j<n)
				{
					if(arr[j+1]>arr[j])
						j++;
				}
				if(v>=arr[j])
						heap=true;
				else
				{
						arr[k]=arr[j];
						k=j;
				}
				
			}
			arr[k]=v;
			
		
	}
	// cout << "heap is:"<< endl;
		
	// 	for (int i = 1; i <= n; ++i)
	// 	{
	// 		cout << arr[i]<< endl;
			
	// 	}
}

int extract_max_heap()
{
	int v=arr[1];
	arr[1]=arr[n];
	n--;
	Max_heapify();
	return v;
}

void heap_increase_key(int new_key)
{
	arr[n+1]=new_key;
	n++;
	Max_heapify();
	
}


int main()
{
	cout << "enter no. of elements to enter"<< endl;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	Max_heapify();
	while(1)
	{
		cout << "press 1 to push 2 to pop"<< endl;
		int tmp;
		cin>>tmp;
		if(tmp==1)
		{
		cout << "enter element to push"<< endl;
		cin>>tmp;
			
		heap_increase_key(tmp);
		
		}
		else
		{
			int v=extract_max_heap();
			cout << "element popped is:"<< endl;
			
			cout << v<< endl;
			
		}
		
		
	}
	
}