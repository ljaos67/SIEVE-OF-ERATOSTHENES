/********************************************************************************
CSCI 340 -Assignment 03 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
TA: Saiteja Alubelli
Date Due: September 23,2020

Purpose: The following program is made to mimic the algorithm Eratosthenes sieve.
The set container is filled with values up to a certain range. The set is then
fed into the function "sieve()" where non-prime numbers are separated from prime
numbers. The altgorithm uses an indexing variable to seperate values in the set
that have a multiple other than 1 and the number itself. There is also a "print"
function that prints the values in a set with specific formatting.

*/


// Preprocessing directives
// Input/output stream, set containter, iterator (probably not neeeded), vector
// to store values after finding out they are non-prime, and iomanip for spacing
// and format options

#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <iomanip>

using namespace std;

// Sieve takes the upper bound of the set range as input by the user and the 
// address of the set to be sorted
// m is used to remove multiples from the set and indexed for each pass
// the for loop iterates through the set and derferences the iterator for 
// comparison. If the M value equals the set value, that value is skipped. 
// Otherwise, if the set value doesn't have a remainder after the 
// percent modulus with the indexing value, then the number is not prime and 
// needs to be removed from the set. I stored these values into a vector 
// because I was having issues when I used the erase.() function in this loop.
// I believe its because erase() messes with the iterator range which causes 
// a seg fault in the for loop. Since all the values in vector are the non-
// prime values of set, I just did a seperate loop iterating  through the 
// vector and removing all of the vector values from set. This is how I avoided
// the range issues. 

void sieve(set<int>& s, int n)
{
	int m=2;
	int a =0;
	vector<int>v;
	while(m<=n)
	{
		for(auto it=s.begin();it!=s.end();++it)
		{
			a=*it;
			if(a==m)
				continue;
			else
			{
				if(a%m==0)
					v.push_back(a);
			}
		}
		m++;
	}
	int val=v.size();
	for(int i=0; i<val;i++)
	{
		s.erase(v[i]);

	}

}
// This function simply prints out the values of a set with specific format 
// preferences. 'r' is a variable used to count integers in a row so that when
// 16 objects have printed, an if statement triggers and prints a newline. 
// Also since I used iterators I display the derefereced iterator for the value
void print_primes(const set<int>& s)
{
	int r=0;
	for(auto it=s.begin(); it!=s.end();++it)
	{
		if(r==15)
		{
			cout<<setw(5)<< *it << endl;
			r=0;
		}
		else
		{
			cout<<setw(5)<<*it;
			r++;
		}	
	}
}

int main()
{
	set <int> s;
	int n;
	int a;
	cin>> n;
	// If the user inputs a range that's too low, they are asked to re-enter
	while(n<2)
	{
		cout<<"The value entered:" << n << " is too low" << endl;
		cout<<"Please enter another value"<<endl;
		cout<<"Upper limit for the set of primes: :";
		cin>>n;
	}
	cout<< "Upper limit for the set of primes: "<< n << "\n\n";
	a=n;
	// Fills set range with input values
	while(a>1)
	{
		s.insert(a);
		a--;
	}
	sieve(s,n);
	print_primes(s);
	cout<<"\n";
	return 0;
}
