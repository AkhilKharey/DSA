class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s==goal) return true;
        string temp=s;
        for(int i=0;i<s.length();i++)
        {
           char tempchar=s[0];
           s.erase(0,1);
           s.push_back(tempchar);
           if(s==goal) return true;
           if(s==temp) return false;
        } 
        return false;
    }
};