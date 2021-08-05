/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is 
a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words 
in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

#include <bits/stdc++.h>
using namespace std;

int ladderLength_BFS(string beginWord, string endWord, vector<string>& wordList) {
	//convert wordlist into set of strings to reduce time complexity
    unordered_set<string> lst(wordList.begin(), wordList.end());
    
    //we perform bfs - here we assume edge between adjacent words in transformation sequence
    queue<string> q;
    q.push(beginWord);
    int ladder = 1;
    
    while(!q.empty()){
        int n = q.size();
        //we traverse each level at a time
        for(int i = 0; i < n; i++){
            string word = q.front();
            q.pop();
            
            //if target word is found return the length of the ladder
            if(word == endWord) return ladder;
            
            //push all those words in wordList which can be obtained by changing
            //only 1 letter of current word
            for(int j = 0; j < word.size(); j++){
                char c = word[j];
                for(char k = 'a'; k <= 'z'; k++){
                    word[j] = k;
                    if(lst.find(word) != lst.end()){
                        q.push(word);
                        //erase the pushed word from wordList so that we don't add them multiply times
                        lst.erase(word);
                    }
                }
                word[j] = c;
            }
        }
        ladder++;
    }
    return 0;
}

int main(){
	string start, end;
	int n;
	cin >> start >> end;
	cin >> n;
	vector<string> wordList(n);
	for(int i = 0; i < n; i++){
		cin >> wordList[i];
	}

	cout << ladderLength_BFS(start, end, wordList) << "\n";
	return 0;
}