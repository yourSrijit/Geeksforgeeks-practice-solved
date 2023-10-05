//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
	class Window {
		int hash[26], cnt;

	public:
		Window() noexcept : cnt(0) { fill(begin(hash), end(hash), 0); }
		void add(const char c) noexcept {
			if (++hash[c - 'a'] == 1) ++cnt;
		}
		void remove(const char c) noexcept {
			if (--hash[c - 'a'] == 0) --cnt;
		}
		int different() const noexcept { return cnt; }
	};

public:
	long long int substrCount(string s, int k) {
		Window window1, window2;
		int l1{}, l2{};
		long long int ret{};
		for (auto c : s) {
			window1.add(c);
			while (window1.different() > k) window1.remove(s[l1++]);
			window2.add(c);
			while (window2.different() >= k) window2.remove(s[l2++]);
			ret += (l2 - l1);
		}
		return ret;
	}
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends