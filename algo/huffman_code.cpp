#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <utility>

#define f first
#define s second
#define pistr pair<int,string>
#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std; 

class huffman_code
{
public:
	map <char,int> freq_dict;
	map < char,string>  result_list;
	priority_queue <pistr,vector<pistr>,greater<pistr>> pq; //the added frequency and the characters involved in pistr 
	//  vector<pistr>,greater<pistr> these two arguments are required to make it minheap
	int n;
	void inputfn()
	{
		
		cout << "Enter no. of characters"<< endl;
		cin>>n;
		// watch(n);
		char ch;int p;
		cout<<"enter characters and their respective frrequencies"<<endl;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>ch;
			cin>>p;
			// watch(ch);
			// watch(p);
			freq_dict.insert(make_pair(ch,p));

			// watch(1);
			result_list.insert(make_pair(ch,""));
			// watch(2);
		}

		// watch(3);

		huffman_encoder();


	}

	void huffman_encoder()
	{
		// watch("in encoder");
		for (auto x: freq_dict)
		{
			// watch(x.f);
			// watch(x.s);
			string tmp(1,x.f);
			pq.push(make_pair(x.s,tmp));
		}
		// watch(1);
		if (pq.size()==1) //base case
		{
			result_list[pq.top().s[0]]="0";
			outputfn();
		}
		string a,b;int sum;
		pair <int,string> top;
		
		while(pq.size()>1)
		{
		// watch("infinite loop");
		sum=0;
		top=pq.top();
		// cout << "top is"<<top.s<<top.f<< endl;
		
		a=(top.s);
		// watch(a);
		sum=top.f;
		pq.pop();
		top=pq.top();
		b=(top.s);
		// watch(b);
		sum+=top.f;
		// watch(sum);
		for(auto x:a)
		{
			result_list[x]='0'+result_list[x];
		}
		for(auto x:b)
		{
			result_list[x]='1'+result_list[x];
		}
		pq.pop();
		pq.push(make_pair(sum,a+b));
		}
		outputfn();

	}

	void outputfn()
	{
		// watch("outputfn");
		for(auto x: result_list)
		{
			cout << x.f<<" "<<x.s<< endl;
			
		}
	}





};

int main()
{
	huffman_code obj1;
	obj1.inputfn();
}