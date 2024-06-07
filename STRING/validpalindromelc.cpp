// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters 
// include letters and numbers
class Solution {
    private:
    char tolowercase(char ch){
    if(ch>='a'&&ch<='z')
    return ch;
    else{
    char temp=ch-'A'+'a';
    return temp;
    }
    }
    bool valid(char ch){
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
        {
            return 1;
        }
        return 0;
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(valid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
         int st=0;
    int e=temp.length()-1;
    while(st<e)
    {
     if(tolowercase(temp[st++])!=tolowercase(temp[e--]))
     return false;
    }
    return true;
    }
};