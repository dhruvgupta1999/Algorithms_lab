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

	
	using namespace std;
	

typedef struct Graph
{
	int V; //no. of vertex
	int E; //no. of edges
    int ** adj; // for adj matrix
}graph;


 graph * adjmatrixofgraph(int vertex,int edges)
{
    graph * G=(graph *)malloc(sizeof(graph));
    
    G->V=vertex;G->E=edges;
	G->adj=(int **)malloc(sizeof(vertex*vertex));
	
	for (int i = 0; i < vertex; ++i)
		for (int j = 0; j < vertex; ++j)
			G->adj[i][j]=0;
	
	int a,b;
	for (int i = 0; i < edges; ++i)
	{
		cin>>a>>b;
		G->adj[a][b]=1;
		G->adj[b][a]=1;    //NOTE: COMMENT OUT THIS LINE IN CASE OF DIRECTED GRAPH
	}

    return G;
}










	int main()
	{
		std::ios::sync_with_stdio(false);
		int n;
		int p,q,tmp; //tmp variable
		//cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		int v,e;
		cin>>v>>e;
		graph * G=adjmatrixofgraph(v,e);
		for (int i = 0; i < v; ++i)
		{
			for (int j = 0; j < v; ++j)
			{
				cout << G->adj[i][j]<<" ";
				
			}
			cout<<endl;
		}
		return 0;
	}

