/*
Given a string of length m containing lowercase alphabets only. We need to find the n-th permutation of string lexicographically.
*/// C++ program to print
// n-th permutation
#include <bits/stdc++.h>
using namespace std;
  
#define ll long long int
  
const int MAX_CHAR = 26;
const int MAX_FACT = 20;
ll fact[MAX_FACT];
  
// Utility for calculating factorials
void precomputeFactorials()
{
    fact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++)
        fact[i] = fact[i - 1] * i;
}
  
// Function for nth permutation
void nPermute(char str[], int n)
{
    precomputeFactorials();
  
    // Length of given string
    int len = strlen(str);
  
    // Count frequencies of all
    // characters
    int freq[MAX_CHAR] = { 0 };
    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;
  
    // Out string for output string
    char out[MAX_CHAR];
  
    // Iterate till sum equals n
    int sum = 0;
    int k = 0;
  
    // We update both n and sum in this
    // loop.
    while (sum != n) {
  
        sum = 0;
        // Check for characters present in freq[]
        for (int i = 0; i < MAX_CHAR; i++) {
            if (freq[i] == 0)
                continue;
  
            // Remove character
            freq[i]--;
  
            // Calculate sum after fixing
            // a particuar char
            int xsum = fact[len - 1 - k];
            for (int j = 0; j < MAX_CHAR; j++)
                xsum /= fact[freq[j]];
            sum += xsum;
  
            // if sum > n fix that char as
            // present char and update sum
            // and required nth after fixing
            // char at that position
            if (sum >= n) {
                out[k++] = i + 'a';
                n -= (sum - xsum);
                break;
            }
  
            // if sum < n, add character back
            if (sum < n)
                freq[i]++;
        }
    }
  
    // if sum == n means this
    // char will provide its
    // greatest permutation
    // as nth permutation
    for (int i = MAX_CHAR - 1;
         k < len && i >= 0; i--)
        if (freq[i]) {
            out[k++] = i + 'a';
            freq[i++]--;
        }
  
    // append string termination
    // character and print result
    out[k] = '\0';
    cout << out;
}
  
// Driver program
int main()
{
    int n;
    cin >> n;
    char str[100];
    cin >> str;
  
    nPermute(str, n);
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// string getPermutation(string s, int k){
// 	int n = s.length();
// 	if(n == 1) return s;

// 	sort(s.begin(), s.end());

// 	string res = "";
// 	int fact = 1;
// 	for(int i = 1; i <= n; i++){
// 		fact = fact*i;
// 	}
// 	k = k-1;
// 	for(int i = 0; i < n; i++){
// 		fact = fact/(n-i);
// 		int index = k/fact;
// 		res += s[index];
// 		s.erase(s.begin() + index);
// 		k = k-index*fact;
// 	}

// 	return res;
// }

// int main()
// {
// 	int k;
// 	cin >> k;
// 	string s;
// 	cin >> s;
// 	cout << getPermutation(s, k) << "\n";
// 	return 0;
// }