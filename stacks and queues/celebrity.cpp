/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
*/
#include <bits/stdc++.h>
using namespace std;

//stack approach
int findCeleb(vector<vector<int>> m, int n)
{
	stack<int> s;
   	for(int i = 0; i < n; i++)
        s.push(i);
        
    while(s.size() > 1)
    {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();
        if(m[i][j] == 1)
        {
            s.push(j);
        }
        else{
            s.push(i);
        }
    }
    
    int p = s.top(); s.pop();
    for(int i = 0; i < n; i++)
    {
        if(i != p && (m[i][p] == 0 || m[p][i] == 1))
            return -1;
    }
    return p;
}

//two pointer approach
int findCeleb_usingTwoPointers(vector<vector<int>> m, int n)
{
	// Initialize two pointers 
    // as two corners
    int a = 0;
    int b = n - 1;
 
    // Keep moving while 
    // the two pointers
    // don't become same. 
    while (a < b)
    {
        if (m[a][b] == 1)
            a++;
        else
            b--;
    }
 
    // Check if a is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't 
        // know 'a' or 'a' doesn't
        // know any person, return -1
        if ( (i != a) && (m[i][a] == 0 || m[a][i] == 1))
            return -1;
    }
 
    return a;
}
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a;
	for(int i = 0; i < n; i++)
	{
		a.push_back({});
		for(int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	cout << "celebrity is " << findCeleb(a, n) << endl;
	return 0;
}