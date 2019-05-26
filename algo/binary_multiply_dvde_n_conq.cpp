/*input
1010
11
*/
#include <iostream>
#include <string>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
class binary_mult
{
public:
	string a,b;
	void inputfn()
	{
		cin>>a;
		cin>>b;
	}

	string addfn( string X, string Y ) 
	{ 
		// cout << "in add fn:"<< endl;
		// watch(X);
		// watch(Y);
		int la=X.length();
		int lb=Y.length();
		string * x=la>lb?&Y:&X;   //std::string is class in c++ which gives an object to which we can have pointer 
		for (int i = 0; i < (int)abs(la-lb); ++i)  //I am making length of both strings equal
		{
			*x="0"+*x;
		}
		
		
		// watch(X);
		// watch(Y);
		string result=""; 
		int carry = 0; 
		int n=X.length();
		// watch(n);
		for (int i = n-1 ; i >= 0 ; i--) 
		{ 
			int aBit = X.at(i) - '0'; 
			int bBit = Y.at(i) - '0';  
			int sum = (aBit ^ bBit ^ carry)+'0'; 
			// watch((char)sum);
			result = (char)sum + result;  
			carry = (aBit&bBit) | (bBit&carry) | (aBit&carry); 
			// watch(carry);
		} 
		if (carry==1) result = '1' + result; 
		// watch(result);
		return result; 
	}

	long int multfn(string X,string Y)
	{
		
		int la=X.length();
		int lb=Y.length();
		string * x=la>lb?&Y:&X;   //std::string is class in c++ which gives an object to which we can have pointer 
		for (int i = 0; i < (int)abs(la-lb); ++i)  //I am making length of both strings equal
		{
			*x="0"+*x;
		}
		int n=X.length();
		// watch(X);
		// watch(Y);
		// watch(n);
		if (n == 0) return 0; 
		if (n == 1)
		{
			// cout << "n==1 "<< ((X[0] - '0')*(Y[0] - '0'))<<endl;
		 return ((X[0] - '0')*(Y[0] - '0'));
		}
		int fh = n/2;  
		int sh = (n-fh); 
		string Xl = X.substr(0, fh); 
		string Xr = X.substr(fh, sh);  
		string Yl = Y.substr(0, fh); 
		string Yr = Y.substr(fh, sh); 
		// watch(Xl);
		// watch(Yl);
		// watch(Xr);
		// watch(Yr);
		long int P1 = multfn(Xl, Yl); 
		long int P2 = multfn(Xr, Yr); 
		long int P3 = multfn(addfn(Xl, Xr), addfn(Yl, Yr));  
		return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
	}

	

	void decToBinary(long int n) 
	{ 
	    int binaryNum[1000]; 
	    int i = 0; 
	    while (n > 0) { 
	        binaryNum[i] = n % 2; 
	        n = n / 2; 
	        i++; 
	    } 
	    for (int j = i - 1; j >= 0; j--) 
	        cout << binaryNum[j]; 
	}
};

int main()
{
	binary_mult obj1;
	obj1.inputfn();
	long int result=obj1.multfn(obj1.a,obj1.b);
	cout<< "result in long: "<< result <<endl;
	cout << "result in binaryNum: ";obj1.decToBinary(result);
}



