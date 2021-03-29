/*
Given a stream of characters and we have to find first non repeating character each time a character is inserted to the stream.
*/
#include <bits/stdc++.h>
using namespace std;

/*
in this problem we use a queue of char data type and an array which stores frequency of every character in the string
first enqueue the current character in the queue and increment its frequency
now start while loop with condition that the queue is not empty
first check if the frequency of the current front element is greater than 1 or not
if greater than 1 that means the this char is repeating hence pop the character 
else add it to the result string because the current first non repeating character
at the end check if the queue is empty, if empty enqueue '#' that means currently there is no 'non-repeating char'
*/
string firstNonRepeating(string s){
	int n = s.length();
	string res = "";
	int a[26] = {0};
	queue<char> q;
	for(int i = 0; i < n; i++)
	{
		q.push(s[i]);
		a[s[i]-'a']++;

		while(!q.empty())
		{
			if(a[q.front()-'a'] > 1)
				q.pop();
			else
			{
				res += q.front();
				break;
			}
		}
		if(q.empty())
			res += "#";
	}
	return res;
}

int main(){
	string s;
	cin >> s;
	string res = firstNonRepeating(s);
	cout << res;
	return 0;
}