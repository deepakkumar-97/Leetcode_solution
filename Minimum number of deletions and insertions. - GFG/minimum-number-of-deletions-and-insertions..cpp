//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int  lcs(int i,int j,string& str1, string& str2, vector<vector<int>>&dp){
	    // base condition
	    if(i<0 || j<0) return 0;
	    
	  if(dp[i][j] != -1) return dp[i][j];
	   if(str1[i] == str2[j]) return dp[i][j] = 1+lcs(i-1,j-1,str1,str2,dp);
	   else return dp[i][j] = max(lcs(i-1,j,str1,str2,dp),lcs(i,j-1,str1,str2,dp));
	   
	    
	}	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int l1 = str1.size();
	    int l2 = str2.size();
	    vector<vector<int>> dp(l1,vector<int>(l2,-1));
	    int x = lcs(l1-1,l2-1,str1,str2,dp);
	    
	    
	    
	   //vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
	   //for(int i=1; i<=l1; i++){
	   //    for(int j=1; j<=l2; j++){
	   //        if(str1[i-1] == str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
	   //        else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]);
	   //    }
	   //}
	   // int x = dp[l1][l2];
	   
	    return l1+l2 -2*x;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends