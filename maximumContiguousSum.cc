#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>


using namespace std;

//Brute force
long maximum_sum_subarray(vector<long>& arr, long n);

// DIVIDE AND CONQUER

long max(long leftpart_max, long rightpart_max) 
{ 
	
	if(leftpart_max > rightpart_max )
		return leftpart_max;
	else 
		return rightpart_max;
	
	
}
 

long max(long first, long mid, long last) 
{
	long temp = max(first,mid);
	return max(temp,last);

}
 

long maxCrossingSum(vector<long>& arr, long first, long mid, long last)
{

    long sum = 0;
    long sum_of_leftside = LONG_MIN;
    for (int i = mid; i >= first; i--)
    {
        sum = sum + arr[i];
        if (sum > sum_of_leftside)
          sum_of_leftside = sum;
    }
 
  
    sum = 0;
    long sum_of_rightside = LONG_MIN;
    for (int i = mid+1; i <= last; i++)
    {
        sum = sum + arr[i];
        if (sum > sum_of_rightside)
          sum_of_rightside = sum;
    }
 
	
    return sum_of_leftside + sum_of_rightside;
}
 


long divide_conquer(vector<long>& arr, long first, long last)
{

   if (first == last){
	
     return arr[first];}
 

   long mid = (first + last)/2;
	long maxi=max(divide_conquer(arr, first, mid),
              divide_conquer(arr, mid+1, last),
              maxCrossingSum(arr, first, mid, last));
	
   return maxi;
}


int main(int argc, char *argv[])
{	
	
	if(argc==1)
	{
		cerr << " No file name is specified.. " <<endl;
		exit(0);
	}
	
	long n;
	long result1;
	long max_sum;
	string s =argv[1];
	float start_s;
	float stop_s;
	float start_s1;
	float stop_s1;
	float duration1;
	float duration2;
	vector<long> arr;
	
	ifstream inputfile(argv[1]);
	
	if (inputfile)
	{
		long int number;
		
		while(inputfile >> number)
		{	
			if(inputfile.peek() == ',')
			{
				inputfile.ignore();
			}
			arr.push_back(number);

		}
	}
	
	else
	{
		cerr << "Error opeing the file" << endl;
		exit(0);
	}

	if(arr.size()==0)
	{
		cerr << "NO data in the file" << endl;
		exit(0);
	}	

	n=arr.size();
	
	//Find the contagious sum usin Brute-Force and print to screen

	for(int i=1; i<=2; i++)
	{	
	start_s=clock();
		
	result1=maximum_sum_subarray(arr,n);
	stop_s=clock();
	duration1= float((stop_s-start_s)/(CLOCKS_PER_SEC));
	}
	cout << fixed;
	cout << result1 << "\t" << duration1  << "[secs]"<<endl;

	//divide and conquer
	for(int i=1; i<=2; i++)	
	{	
	start_s1=clock();	
	
	max_sum = divide_conquer(arr, 0, n-1);
	stop_s1=clock();
	duration2 = float((stop_s1-start_s1)/(CLOCKS_PER_SEC));
	}
	cout << max_sum << "\t" << duration2  << "[secs]"<<endl;


}

//Brute Force Algorithm
long maximum_sum_subarray(vector<long>& arr, long n)
{


	long ans=LONG_MIN;
    for(int i=0; i<n; i++ )
	{
		for(int index=i; index<n; index++)
		{
			
			long sum=0;
			for(int k=i;k<=index;k++)
			{
				
				sum=sum+arr[k];
			}							
			ans=max(ans,sum);
			
		}
}
	return ans;
}


