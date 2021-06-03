/*
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum 
of two numbers formed using the elements of the array. All digits in the given array must be used to form 
the two numbers.
*/
#include <bits/stdc++.h>
using namespace std;

//function to calculate sum of large numbers as strings
string stringsum(string str1, string str2){
	// Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
 
    // Initially take carry zero
    int carry = 0;
 
    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

string minimumSum(int a[], int n){
	string n1,n2;
	//stores frequencies of all digits
	int d[10] = {};

	for(int i = 0; i < n; i++){
		d[a[i]]++;
	}

	//add smaller digits in MSB of both numbers, 0 digit is always discarded because being smallest
	//it should be at MSB and 0 at MSB of a number has no value
	for(int i = 1; i < 10; i++){
		while(d[i]){
			n1 += to_string(i);
			d[i]--;

			//if count of current digit = 0 find next smallest digit present in array
			while(i < 10 && d[i] == 0) i++;
			if(i == 10) break;
			
			n2 += to_string(i);
			d[i]--;
		}
	}

	return stringsum(n1,n2);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << minimumSum(a, n) << endl;
	return 0;
}