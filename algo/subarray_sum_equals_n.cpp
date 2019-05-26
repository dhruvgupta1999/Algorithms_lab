	
	#include <iostream> 
	#include <vector> 
		
	using namespace std;

	
class sumcheck
{
public:
	int n,size;vector <int> v; int tmp;
	void inputfn()
	{
		printf("Enter sum:\n");
		scanf("%d",&n);
		printf("enter array size:\n");
		scanf("%d",&size);
		printf("enter array elements\n");
		for (int i = 0; i < size; ++i)
		{
			scanf("%d",&tmp);
			v.emplace_back(tmp);

		}


	}

	void checkfn()
	{
		int sum=0;
		int start_index=0;
		int end_index=1;


		for (int i = 0; i < size;)
		{
			
			if(sum!=0)
			{
			    sum-=v[start_index];
			    start_index++;
			}
			// watch(sum);
			// watch(start_index);
			while(i<size && sum<n)
			{
				sum+=v[i];
				i++;
			}
			// watch(sum);
			end_index=i;
			// watch(end_index);
			if (sum==n)
			{
				printf("start_index is %d\n",start_index);
				printf("end_index is %d\n",end_index-1);
				 //don't include end_index while printing
				printf("elements are: \n");
				for (int j = start_index; j < end_index; ++j)
				{
					printf("%d ",v[j]);
				}printf("\n");
			}

			
		}
		if (v[v.size()-1]==n)
		{
			printf("start_index is %d\n",v.size()-1);
				printf("end_index is %d\n",v.size()-1);
				 //don't include end_index while printing
				printf("elements are: %d\n",v[v.size()-1]);
		}

	}



};



int main()
{
	sumcheck obj1;
	obj1.inputfn();
	obj1.checkfn();

}

