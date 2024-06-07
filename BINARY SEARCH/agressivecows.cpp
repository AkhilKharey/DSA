 bool isPossible(int k,int n,vector<int> &stalls,int mid){ //gfghttps://practice.geeksforgeeks.org/problems/aggressive-cows/1
        int cowcnt=1;
        int coord=stalls[0];
        for(int i=1;i<n;i++){
            
                if(stalls[i]-coord>=mid )
                {
                    cowcnt++;
                    coord=stalls[i];
                }
                if(cowcnt==k)
                return true;
            }
            return false;
        }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=0;
        int e=stalls[n-1]-stalls[0];
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e)
        {
            if(isPossible(k,n,stalls,mid))
            {
                ans=mid;
                s=mid+1;    
            }
            else
            e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;