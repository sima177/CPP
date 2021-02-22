/*Given an input stream of n integers the task is to insert integers to stream and print the median of the new stream formed by each insertion of x to the stream.

Example

Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Input:
The first line of input contains an integer N denoting the no of elements of the stream. Then the next N lines contains integer x denoting the no to be inserted to the stream.

Output:
For each element added to the stream print the floor of the new median in a new line.

Constraints:
1<=N<=10^5+7
1<=x<=10^5+7
4
5
15
1 
3
5
10
5
4
4
8
20
2
5
8
14
8
6
*/

// C++ program to find median in 
// stream of running integers
 
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
 
// max heap to store the higher half elements 
priority_queue<int> max_heap_left;
 
// min heap to store the lower half elements
priority_queue<int,vector<int>,greater<int>> min_heap_right;
 
// function to calculate median of stream 
void calculate_median(double x,int &median)
{
    /*  At any time we try to make heaps balanced and 
        their sizes differ by atmost 1. If heaps are 
        balanced,then we declare median as average of 
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined 
        as the top element of heap of larger size  */
      
    // case1(left side heap has more elements)
    if (max_heap_left.size() > min_heap_right.size())
    {
        if (x < median)
        {
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
            max_heap_left.push(x);
        }
        else
            min_heap_right.push(x);
 
        median = ((double)max_heap_left.top()
                +(double)min_heap_right.top())/2;
    }
 
    // case2(both heaps are balanced)
    else if (max_heap_left.size()==min_heap_right.size())
    {
        if (x < median)
        {
            max_heap_left.push(x);
            median = (double)max_heap_left.top();
        }
        else
        {
            min_heap_right.push(x);
            median = (double)min_heap_right.top();
        }
    }
 
    // case3(right side heap has more elements)
    else
    {
        if (x > median)
        {
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
            min_heap_right.push(x);
        }
        else
            max_heap_left.push(x);
 
        median = ((double)max_heap_left.top()
                 + (double)min_heap_right.top())/2.0;
    }
}
 
// Driver program to test above functions
int main()
{   
    // stream of integers
    double arr[100];
    int median = 0;//stores the median 
     
    // size of stream
    int n;
  cin>>n;
  int i;
  for(i=0;i<n;i++)
    cin>>arr[i];
     
    // reading elements of stream one by one
    for (int i=0; i < n; i++)
    {   
        // calculating new median for each 
        // new element added to the stream
        calculate_median(arr[i], median);
        cout << median << endl;
    }
    return 0;
}
