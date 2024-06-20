class Solution {

    private:
         int ballCount(vector<int>&position,int mid)
         {
            int ball=1;
           int start=position[0];
           for(int i=1;i<position.size();i++)
           {
              int diff=position[i]-start;
                if(diff>=mid)  
                 {
                    ball++;
                    start=position[i];
                }
           }
           return ball;
         }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position[0];
        int mid=low+(high-low)/2;
        int ans=0;
        int curMax = 0;
        while(low<=high)
        {
         if(ballCount(position,mid)<m)
         {
           high=mid-1;
         }
         else {

         low=mid+1;
         curMax = max(curMax, mid);
         } 
         mid=low+(high-low)/2;
        }
         return low-1;
    }
};