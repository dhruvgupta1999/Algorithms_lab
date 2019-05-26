/*input
5
0 1 1 1 1 0
*/
#include <queue>
#include <iostream>
// #define watch(x) cout << (#x) << " is " << (x) << endl


using namespace std;




class iterative_quicksort
{
public:

int n;
int a[1000];
void inputfn()
{
	// cout << "in input fn"<< endl;
	
	cin>>n;
    // int a[n];

    for (int i = 0; i < n; ++i)
    	cin>>a[i];
    // for (int i = 0; i < n; ++i)
    // {
    // 	cout << a[i]<< endl;
    	
    // }
    // return n;
    
}

void printfn()
{
	// cout << "in printfn"<< endl;
	
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}

int partition(int lo,int hi)
{
    // cout<<"in partition()"<<endl;
    int tmp;
    int  i=lo;
    int pvt=a[hi];
    for(int j=lo;j<hi;j++)
    {
        // cout<<"i="<<i<<endl;
        // cout<<"j="<<j<<endl;
        if(a[j]<=pvt)
        {
           tmp=a[j];
           a[j]=a[i];
           a[i]=tmp;
           i++;
        }
    }
    tmp=a[hi];
    a[hi]=a[i];
    a[i]=tmp;
    
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;

    return i;

}


void quicksort()
{
    int x,lo,hi;
    // cout<<"in quicksort"<<endl;
    queue <pair<int,int>> q;
    q.push(make_pair(0,n-1));
    while(!q.empty())
    {
    	lo=q.front().first;
    	hi=q.front().second;
    	if(lo<hi)
    	{
    		x=this->partition(lo,hi);

    		q.push(make_pair(lo,x-1));
    		q.push(make_pair(x+1,hi));
    	}
    	q.pop();
    }

    this->printfn();
    // for (int i = 0; i < n; ++i)
    // {
    // 	cout << a[i]<< endl;
    	
    // }
}
};

int main(){
    
    iterative_quicksort obj1;
    obj1.inputfn();
    // watch(n);
	obj1.quicksort();


}