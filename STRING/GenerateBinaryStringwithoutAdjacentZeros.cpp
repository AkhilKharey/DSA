class Solution
{
public:
    vector<string> validStrings(int n)
    {
        vector<string> res = {"0", "1"};
        if (n == 1)
            return res;
        for (int i = 2; i <= n; i++)
        {
            vector<string> temp;
            for (int j = 0; j < res.size(); j++)
            {
                if (res[j].back() == '1')
                {
                    //  akhri me 1 hai to 1 ya zero kuch bhi laga skte hai
                    temp.push_back(res[j] + "1");
                    temp.push_back(res[j] + "0");
                }
                else
                {
                    //  akhri me zero hai to sirf 1 laga sakte hai
                    temp.push_back(res[j] + "1");
                }
            }
            res = temp;
        }
        return res;
    }
};