// C++ implementation of Karatsuba algorithm for bit string multiplication. 
#include<iostream> 
#include<stdio.h> 

using namespace std; 

// FOLLOWING TWO FUNCTIONS ARE COPIED FROM http://goo.gl/q0OhZ 
// Helper method: given two unequal sized bit strings, converts them to 
// same length by adding leading 0s in the smaller string. Returns the 
// the new length 

// The main function that adds two bit sequences and returns the addition 
string addfn( string a, string b ) 
{ 
	string result; 
	int length = makeEqualLength(a, b); 
	int carry = 0; 
	for (int i = length-1 ; i >= 0 ; i--) 
	{ 
		int aBit = a.[i] - '0'; 
		int bBit = b.[i] - '0';  
		int sum = (aBit ^ bBit ^ carry)+'0'; 
		result = (char)sum + result;  
		carry = (aBit&bBit) | (bBit&carry) | (aBit&carry); 
	} 
	if (carry) result = '1' + result; 
	return result; 
} 

long int multiply(string X, string Y) 
{ 
	// Find the maximum of lengths of x and Y and make length 
	// of smaller string same as that of larger string 
	// int n = makeEqualLength(X, Y); 

	// Base cases 
	if (n == 0) return 0; 
	if (n == 1) return ((X[0] - '0')*(Y[0] - '0'));

	int fh = n/2; // a half of string, floor(n/2) 
	int sh = (n-fh); // b half of string, ceil(n/2) 

	// Find the a half and b half of a string. 
	// Refer http://goo.gl/lLmgn for substr method 
	string Xl = X.substr(0, fh); 
	string Xr = X.substr(fh, sh); 

	// Find the a half and b half of b string 
	string Yl = Y.substr(0, fh); 
	string Yr = Y.substr(fh, sh); 

	// Recursively calculate the three products of inputs of size n/2 
	long int P1 = multiply(Xl, Yl); 
	long int P2 = multiply(Xr, Yr); 
	long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 

	// Combine the three products to get the final result. 
	return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
} 

// Driver program to test aboev functions 
int main() 
{ 
	printf ("%ld\n", multiply("1100", "1010")); 
	printf ("%ld\n", multiply("110", "1010")); 
	printf ("%ld\n", multiply("11", "1010")); 
	printf ("%ld\n", multiply("1", "1010")); 
	printf ("%ld\n", multiply("0", "1010")); 
	printf ("%ld\n", multiply("111", "111")); 
	printf ("%ld\n", multiply("11", "11")); 
} 
