//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
          int m = s.length();
    int n = p.length();
    string smallestSubstring = "";

    int minLen = INT_MAX;

    // Generate all substrings of the given string
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            string substr = s.substr(i, j - i + 1);

            // Check if the substring contains all
            // characters of the pattern
            if (containsAllCharacters(substr, p)) {
                int currLen = substr.length();
              
                // Update the smallestSubstring if the
                // current substring is smaller
                if (currLen < minLen) {
                    minLen = currLen;
                    smallestSubstring = substr;
                }
            }
        }
    }

    return smallestSubstring;
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
