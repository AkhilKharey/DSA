class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      set<string>st;
      for(int i=0;i<wordList.size();i++)
      {
        st.insert(wordList[i]);
      }
      queue<pair<string,int>>q;
    //   if(st.find(endWord)==st.end()){
    //     return 0;
    //   }
      q.push({beginWord,1});
      st.erase(beginWord);
      while(!q.empty())
      {
        string word=q.front().first;
        int number=q.front().second;
        if(word==endWord)
        return number;
        q.pop();
        for(int i=0;i<word.length();i++)
        {
        for(char c='a';c<='z';c++)
        {
           string tempword;
           tempword=word;
           tempword[i]=c;
           if(st.find(tempword)!=st.end())
           {
            st.erase(tempword);
          q.push({tempword,number+1});

           }

        }
        }
      }
      return 0;

    }
};  