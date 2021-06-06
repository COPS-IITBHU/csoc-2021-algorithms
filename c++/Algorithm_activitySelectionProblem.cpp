//Activity Selection Problem
#include <bits/stdc++.h>

using namespace std; 

// Structure represents an activity having starting and ending time. 
struct activity 
{ 
    int start, end; 
}; 

// Function for sorting activities according to their ending time 
bool sort_activity(activity s1, activity s2) 
{ 
    return (s1.end< s2.end); 
} 

// 	Printing maximum number of activities that can be 
//	done by a single person at a time. 

void print_Max_Activities(activity arr[], int n) 
{ 
    // Sorting activities according to finish time 
	sort(arr, arr+n, sort_activity); 

	cout<< "Following activities are selected \n"; 

    // Selecting first activity
    int i = 0; 
	cout<< "(" <<arr[i].start<< ", " <<arr[i].end << ")\n"; 

    // Consider the remaining activities
    for (int j = 1; j < n; j++) 
    { 
    	// Selecting the activity if it has start time greater than or equal
    	// to the finish time of previously selected activity
      	if (arr[j].start>= arr[i].end) 
      	{	 
			cout<< "(" <<arr[j].start<< ", "<<arr[j].end << ") \n"; 
			i = j; 
      	} 
    } 
} 

// Driver program 
int main() {   
    int n;
    cout<<"Enter the number of activities : ";
    cin>>n;
    activity arr[n];
	for(int i=0; i<n; i++)
	{
	    cout<<"Enter the starting time of activity "<<i+1<<" : ";
        cin>>arr[i].start;
        cout<<"Enter the ending time of activity "<<i+1<<" : ";
        cin>>arr[i].end;
		
    }
	print_Max_Activities(arr, n); 
    return 0; 
}
