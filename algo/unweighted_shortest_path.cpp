

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
    #define N 100002
	
	using namespace std;
	
	vector<int> adj[N];   //NOTE :Allocate Memory to this vector using "adj=(vector<int> *)malloc(V*size(vector<int>))"
	void addEdge( int u, int v) 
	{ 
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	} 
	void printGraph(int V) //this function iterates over all lists of all vertexes
	{ 
	    for (int v = 0; v < V; ++v) 
	    { 
	        //cout << "\n Adjacency list of vertex " << v << "\n head "; 
	            
	        for (auto x : adj[v]) 
	           cout << "-> " << x; 
	        printf("\n"); 
	    } 
	} 


	ll cq[N];  //for distance from start vertex
	bool visited[N];
	void bfs(int s)
	{
		ll count=1;
		list <int> queue;
		visited[s] = true;
		queue.push_back(s);
		vector<int>::iterator i;
		while (!queue.empty())
		{
			s = queue.front();
			if(cq[s]!=-1)
			count=cq[s] + 1;
			
			
			queue.pop_front();
			for (i = adj[s].begin(); i != adj[s].end(); ++i)
			{
	
				if (!visited[*i])
				{
					cq[*i]=count;// distance from start node
					
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}
	
	
	int main() 
	{ 
	    std::ios::sync_with_stdio(false);
	    int T,V,E,S;//no of vertex and edges
	    cin>>T;
	    while(T--)
	    {
	    cin>>V>>E; 
	    //adj=(vector<int> *)malloc(V*sizeof(vector<int>)) ; caused memory leak
	    int a,b;
	    mem(adj,0);
	    for (int i = 0; i < E; ++i)
	    {
	    	cin>>a>>b;
	    	addEdge(a,b);
	    }
	    cin>>S;
	    bfs(S);
	    //see cq[] to get distance
	    printGraph(V); 
	    }
	    return 0; 
	} 
	