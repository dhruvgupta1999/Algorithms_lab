#include <bits/stdc++.h>

using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main()
{
	int n;
	cout << "Enter number of entries to be retrieved from disk"<< endl;
	cin>>n;
	cout << "Enter track no. of each entry"<< endl;

	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
	int cur_head_at;
	cout << "enter initial position of reader head"<< endl;
	cin>>cur_head_at;
	sort(arr.begin(),arr.begin()+n);
	// for (int i = 0; i < arr.size(); ++i)
	// {
	// 	watch(arr[i]);
	// }
	int tmp;int diff=999999;
	for (int i = 0; i < n; ++i)
	{
		
		if (diff>abs(arr[i]-cur_head_at))
		{
			diff=abs(arr[i]-cur_head_at);
			// watch(diff);
			// cur_head_at=arr[i];
			tmp=i;
			// watch(tmp);
		}
	}
	// watch(tmp);
	cur_head_at=arr[tmp];
	// watch(cur_head_at);
	int next_pos=999999;
	// cur_head_at=next_pos;
	int count=0;;
	while(count!=n)
	{
		count++;
		// watch(tmp);
		cout << cur_head_at<< endl;
		if (tmp==0)
		{
			// watch("cond1");
			arr.erase(arr.begin());
			cur_head_at=arr[tmp];
			continue;
		}

		int xyz=tmp;
		// watch(xyz);
	 for (int i = 0; i < arr.size(); ++i)
	{
		// watch(arr[i]);
	}
		// next_pos=min(abs(cur_head_at-arr[(tmp+1)]))
		if(tmp==arr.size()-1)
		{

			// watch("cond2");
			tmp--	;
			cur_head_at=arr[tmp];
		}
		else
		{
			// watch("cond3");
			tmp=(arr[tmp+1]-cur_head_at)>(cur_head_at-arr[tmp-1])?tmp-1:tmp+1;
			cur_head_at=arr[tmp];
			// watch(cur_head_at);

		}
		arr.erase(arr.begin()+xyz);
		if (tmp>=xyz)
		{
			tmp--;
		}
		// watch(tmp);
		
	}
	
	
}