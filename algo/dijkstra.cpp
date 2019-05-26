

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
	#define inf 1000000000000000001
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
    #define watch(x) cout << (#x) << " is " << (x) << endl
    #define N 100002
	
	using namespace std;
	int T,V,E;//no of vertex and edges
	vector<pii> adj[N];   //for weighted adj list <vertex,weight>
	void addEdge( int u, int v,int wt) 
	{ 
	    adj[u].push_back(mp(v,wt)); 
	    adj[v].push_back(mp(u,wt)); 
	    //adj[v].push_back(u); 
	} 
	void printGraph() //this function iterates over all lists of all vertexes
	{ 
	    for (int v = 0; v < V; ++v) 
	    { 
	        cout << "\n Adjacency list of vertex " << v << "\n head "<<endl; 
	            
	        for (auto x : adj[v]) 
	           cout << "-> " << x.f; 
	        printf("\n"); 
	    } 
	} 
	
	ll dist[N];

    void dijkstra(ll S)
    {
    	priority_queue <pii,vector<pii>,greater<pii>> pq; //minheap from gfg <priority,vertex>
    	ll tmp;
    	pq.push(mp(0,S));
    	for (int i = 0; i < V; ++i)
    	{
    	    dist[i]=inf;
    	}
    	dist[S]=0;
    	//int count=0;
    	while(!pq.empty())
    	{

    		 int u = pq.top().second; 
    		 tmp=pq.top().f;
    		 if (tmp>dist[u])
    		 {
    		 	pq.pop();
    		 	continue;
    		 }

        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
         
        for (auto i:adj[u]) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (i).first; 
            int weight = (i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 

        }
        }
    }

	int main() 
	{ 
	    std::ios::sync_with_stdio(false);
	    
	    cin>>T;
	    while(T--)
	    {
	    cin>>V>>E; 
	    //adj=(vector<int> *)malloc(V*sizeof(vector<int>)) ; caused memory leak
	    int a,b,wt;
	    mem(adj,0);

	    for (int i = 0; i < E; ++i)
	    {
	    	cin>>a>>b>>wt;
	    	addEdge(a-1,b-1,wt);
	    }

	    int start;
	    cin>>start;
	    //printGraph();
	    dijkstra(start-1);
	    for (int i = 0; i < V; ++i)
	    {
	    	if (dist[i]==inf)
	    	{
	    		cout << -1<< " ";
	    		
	    	}
	    	else if(i!=start-1)
	    	cout<<dist[i]<<" ";
	    }
         cout << endl;

        

	    //printGraph(V); 
	    }
	    return 0; 
	} 
	 