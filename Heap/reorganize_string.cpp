/*
Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each 
other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

-> It has 2 solutions using maxheap and without maxheap
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,char> pic;

//using pq
string reorganize(string s){
	vector<int> count(26);
	priority_queue<pic> pq;

	for(char c: s){
		count[c-'a']++;
	}

	for(int j = 0; j < 26; j++){
		pq.push(make_pair(count[j], j+'a'));
	}

	if(2*pq.top().first - 1 > s.size()) return "NOT POSSIBLE";

	int i = 0;
	while(!pq.empty()){
		pic cur = pq.top();
		pq.pop();
		while(cur.first){
			if(i >= s.size()) i = 1;
			s[i] = cur.second;
			cur.first--;
			i += 2;
		}
	}

	return s;
}


//without using priority queue
string reorganize_without_pq(string s){
        vector<int> count(26);
        int mostfreq = 0;
        
        for(char c: s){
            count[c-'a']++;
            if(count[c-'a'] > count[mostfreq]){
                mostfreq = (c-'a');
            }
        }
        
        if(2*count[mostfreq]-1 > s.size()) return "";
        
        int i = 0;
        while(count[mostfreq]){
            s[i] = ('a' + mostfreq);
            count[mostfreq]--;
            i += 2;
        }
        
        for(int j = 0; j < 26; j++){
            while(count[j]){
                if(i >= s.size()) i = 1;
                s[i] = ('a' + j);
                count[j]--;
                i += 2;
            }
        }
        return s;
}

int main(){
	string s;
	cin >> s;
	cout << reorganize(s) << "\n";
	return 0;
}