class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
        return {{1}};
        if(numRows==2)
        return {{1},{1,1}};
    vector<vector<int>>ans;
    ans.push_back({1});
    ans.push_back({1,1});
    for(int i=3;i<=numRows;i++)
    {
        vector<int>v(ans.back());
        vector<int>temp;
        temp.push_back(1);
        int start=0;
        int end=1;
        while(end<v.size())
        {
            temp.push_back(v[start]+v[end]);
            start++;
            end++;
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
    }
};