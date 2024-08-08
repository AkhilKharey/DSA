// https://leetcode.com/problems/next-greater-element-i/
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        st.push(-1);
        vector<int> nextGreater;
        unordered_map<int, int> mpp;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            int temp = nums2[i];
            mpp[temp] = i; // marking to use later
            if (st.top() > temp || st.top() == -1)
            {
                // agar bada element mila to next greater me dal do aur stack me bhi dal do
                nextGreater.push_back(st.top());
                st.push(temp);
            }
            else if (st.top() < temp)
            {
                // agar top pe greater element na mile to tb tak pop karo
                //  jab tak greater element na mil jae ya fir agar -1 na mil jae
                while (st.top() < temp && st.top() != -1)
                {
                    st.pop();
                }
                nextGreater.push_back(st.top());
                st.push(temp);
            }
        }
        reverse(nextGreater.begin(), nextGreater.end());
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(nextGreater[mpp[nums1[i]]]);
        }
        return ans;
    }
};