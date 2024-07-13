// https://leetcode.com/problems/lemonade-change/
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        // 5 ,10,20 ke bill ko alag consider karna hai
        if (bills[0] != 5)
            return false;
        int count5 = 1;
        int count10 = 0;
        int count20 = 0;
        for (int i = 1; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                count5++;
            else if (bills[i] == 10)
            {
                if (count5 == 0)
                    return false;
                count5--;
                count10++;
            }
            else if (bills[i] == 20)
            {
                if (count5 >= 3 || (count10 >= 1 && count5 >= 1))
                {
                    if (count10 >= 1 && count5 >= 1)
                    {
                        count10--;
                        count5--;
                    }
                    else
                        count5 -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};