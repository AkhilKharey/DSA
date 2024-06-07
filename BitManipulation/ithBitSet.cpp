// to check if ith bit is set   
class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int mask=1<<k;
        bool set=mask&n;
        return set;
        
    }
};
// to set
class solution
{
public:
    int setKthBit(int N, int K)
    {
        // Write Your Code here
         int mask=1<<K;
         N=N|mask;
         return N;
    }
    
};