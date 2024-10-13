//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution
{
    public:
    
   bool isValid(string& s, string& p, int mid, int& start) {
    // Count the frequency of each character in p
    int count[256];
    memset(count, 0, sizeof(count));

    // Stores number of distinct characters in p
    int distinct = 0;

    // Count the frequency of each character in p
    for (char x : p) {
        if (count[x] == 0)
            distinct++;
        count[x]++;
    }

    // Stores the number of characters in a substring of size
    // mid in s whose frequency is the same as the frequency in p
    int curr_count = 0;
    for (int i = 0; i < s.size(); i++) {
        count[s[i]]--;
        if (count[s[i]] == 0) {
            curr_count++;
        }

        if (i >= mid) {
            count[s[i - mid]]++;
            if (count[s[i - mid]] == 1) {
                curr_count--;
            }
        }

        if (i >= mid - 1) {
            // Substring of length mid found which contains
            // all the characters of p
            if (curr_count == distinct) {
                start = (i - mid) + 1;
                return true;
            }
        }
    }

    return false;
}
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
         int m = s.length();
    int n = p.length();

    // If s is smaller than p, it's impossible
    if (m < n) return "-1"; 

    int minLength = INT_MAX;

    // Lower bound and Upper Bound for Binary Search
    // The smallest valid window size is n (size of p)
    int low = n, high = m; 

    // Stores starting index of the min-length substring
    int idx = -1;

    // Applying Binary Search on the answer
    while (low <= high) {
        int mid = (low + high) / 2;
        int start;

        // If a substring of length mid is found which
        // contains all the characters of p, then
        // update minLength and high, otherwise update low
        if (isValid(s, p, mid, start)) {
            if (mid < minLength) {
                minLength = mid;
                idx = start;
            }
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (idx == -1) return "-1";

    return s.substr(idx, minLength);
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
