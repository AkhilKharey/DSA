class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int lsum=0;
      for(int i=0;i<k;i++)
      {
        lsum+=cardPoints[i];
      }
      int maxsum=lsum;
      int rindex=cardPoints.size()-1;
      int rsum=0;
      for(int i=k-1;i>=0;i--){
        lsum-=cardPoints[i];
        rsum+=cardPoints[rindex];
        rindex--;
        maxsum =max(maxsum,lsum+rsum);
      }
      return maxsum;
    }
}; 