//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
 int atoi(string s) {
        //Your code here
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='-'||s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'
            ||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
            count++;
        }
        if(count==s.length()&&s[s.length()-1]!='-')return stoi(s);
        return -1;
       
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends