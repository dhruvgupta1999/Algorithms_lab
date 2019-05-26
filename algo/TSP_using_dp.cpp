#include<iostream>
#include <utility>
#include <string>
using namespace std;

#define INT_MAX 999999

class tsp_using_dp
{
	public:
int n;
int dist[10][10];
int VISITED_ALL;

int dp[100][10];
string path[100][10];


pair<int,string>  tsp(int mask,int pos){
	
	if(mask==VISITED_ALL){
		return make_pair(dist[pos][0],to_string(pos)+"0");
	}
	if(dp[mask][pos]!=-1){
	cout << "hello"<< endl;
	   return make_pair(dp[mask][pos],path[mask][pos]);
	   
	   
	}
	string str;
	int ans = INT_MAX;
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){
			pair <int,string> tmp=tsp( mask|(1<<city), city);
			int newAns = dist[pos][city] + tmp.first;
			str=newAns<ans?tmp.second:str;
			ans = min(ans, newAns);
		}

	}
	dp[mask][pos] = ans;
	path[mask][pos]=to_string(pos)+str;
	return make_pair(ans,path[mask][pos]);
} 

int main(){
    /* init the dp array */
    cin>>n;
    VISITED_ALL = (1<<n) -1;
    
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cin>>dist[i][j];
    	}
    }
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    pair <int,string> tmp=tsp(1,0);
	cout<<"Travelling Saleman Distance is "<<tmp.first<<endl<<"path is:";
	for (int i = 0; i < tmp.second.length(); ++i)
	{
		cout << tmp.second[i]<< " ";
		
	}

return 0;
}
};

int main()
{
	tsp_using_dp obj1;
	obj1.main();
}
