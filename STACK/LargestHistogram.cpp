class Solution {
public:
     vector<int> nextSmallerElements(vector<int>& heights,int n)
     { 
         vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            int temp=heights[i];
            
                while(st.top()!=-1 && heights[st.top()]>=temp)
                {
                    st.pop();
                }
                
                ans[i]=st.top();
                st.push(i);
            
        }
       
        return ans;

     }
     vector<int> prevSmallerElements(vector<int>& heights,int n)
     {
        vector<int>ans(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            int temp=heights[i];
            
                while(st.top()!=-1 && heights[st.top()]>=temp)
                {
                    st.pop();
                }
                
                ans[i]=st.top();
                st.push(i);
            
        }
       
        return ans;
     }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextSmallerElements(heights,n); this will store the indexes of next smaller elements;
        vector<int>prev(n);
        prev=prevSmallerElements(heights,n);this will store the indexes of previous smaller elements
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int length=heights[i];
            if(next[i]==-1)
            next[i]=n;
            int breadth=next[i]-prev[i]-1;
            int newarea=length*breadth;
            area=max(area,newarea);
        }
        return area;

    }
};