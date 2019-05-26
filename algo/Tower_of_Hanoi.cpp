

	#include <iostream> 
	#include <vector> 
		
	using namespace std;
	

class TowerOfHanoi
{
	
	public:
	#define left_rod 1
	#define mid_rod 2
	#define right_rod 3
		int n;
		// int left_rod;
		// int mid_rod


	   // typedef struct move_param 
	   //  {
	   //  	int disk_no;
	   //  	int to_rod;
	   //  	int from_rod;
	   //  	struct move_param * next;
	   //  }move_param; 

	   //  move_param * a[100]

		vector < pair< int , pair <int , int> > >move_param[100];
		int state_param[100];


	    void inputfn()
	    {
	    	// int n;
	    	scanf("%d",&n);
	    	// this -> 

	    	// void construct_series(n)
	    }
	    void construct_series()
	    {
	    	int odd_skip_value,even_skip_value;
	    	if(n%2==0)
	    	{
	    		odd_skip_value=1;
	    		even_skip_value=2;
	    	}
	    	else
	    	{
	    		odd_skip_value=2;
	    		even_skip_value=1;
	    	}
	    	
            for (int i = 0; i <100; ++i)
            {
            	state_param[i]=left_rod;
            }
	    	int start_rod,aux_rod,other_rod;
	    	if (n%2==0)
	    	 {
	    	 	start_rod=left_rod;
	    	 	aux_rod=mid_rod; //aux_rod is the rod where we move disk1 in our first move
	    	 	other_rod=right_rod;
	    	 } 
	    	 else
	    	 {
	    	 	start_rod=left_rod;
	    	 	aux_rod = right_rod;
	    	 	other_rod=mid_rod;
	    	 }
	    	 move_param[1].push_back(make_pair(1,make_pair(start_rod,aux_rod))); // for i disks we address as move_param[i]
	    	 state_param[1]=aux_rod;
	    	 for (int i = 2; i <=n; ++i)
	    	 {
	    	 	for (uint j = 0; j < move_param[i-1].size(); ++j)
	    	 	{
	    	 		move_param[i].push_back(move_param[i-1][j]);
	    	 		state_param[move_param[i-1][j].first]=move_param[i-1][j].second.second;
                    cout<<"My name is Dhruv"<<endl;

	    	 	}
	    	 	if(i%2==0)
	    	 	{
	    	 	move_param[i].push_back(make_pair(i,make_pair(start_rod,other_rod)));
	    	 	state_param[i]=other_rod;
	    	 	// watch(i);
	    	 	// watch(state_param[i]);
	    	     }
	    	    else
	    	    {
	    	    	move_param[i].push_back(make_pair(i,make_pair(start_rod,aux_rod)));
	    	    	state_param[i]=aux_rod;
	    	    	// watch(i);
	    	 	// watch(state_param[i]);
	    	    }
	    	    for (uint j = 0; j < move_param[i-1].size(); ++j)
	    	 	{
	    	 		int from=state_param[move_param[i-1][j].first];
	    	 		// watch(from);
	    	 		int to=from+((move_param[i-1][j].first%2==0)?even_skip_value:odd_skip_value);
	    	 		to=to%3?to%3:3;
	    	 		// watch(to);
	    	 		move_param[i].push_back(make_pair(move_param[i-1][j].first,make_pair(from,to)));
	    	 		state_param[move_param[i-1][j].first]=to;
	    	 		// watch(move_param[i-1][j].first);
	    	 	    // watch(state_param[move_param[i-1][j].first]);
	    	 	}

	    	 }
	    	 // thoutput_answer();
	    }

	    void output_answer()
	    {
	    	for (uint i = 0; i < move_param[n].size(); ++i)
	    	{
	    		/* code */
	    		printf("Move disk %d from rod %d to rod %d\n",move_param[n][i].first,move_param[n][i].second.first,move_param[n][i].second.second);
	    	}
	    	
	    }

};

	

		
	


int main()
		{
			TowerOfHanoi obj1;
			obj1.inputfn();
			obj1.construct_series();
			obj1.output_answer();


		}