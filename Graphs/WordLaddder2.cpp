class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        int level=0;
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        q.push({beginWord});
        vector<vector<string>>ans;
        while(!q.empty())
        {

           vector<string>vec=q.front();
           q.pop();
        //    erase all the elements that has been used in previous levels from the word list set
           if(vec.size()>level)
           {
            level+=1;
            for(auto i:usedOnLevel)
            {
                st.erase(i);
            }
           }
         string word=vec.back();
        //  storing the answers
         if (word==endWord)
         {
            // the first sequence where we reached the end word (it has to be the shortest because we are traversing level wise in the ascending order of level)
            if(ans.size()==0)
            ans.push_back(vec);
          else if(ans[0].size()==vec.size())
          ans.push_back(vec);
         }
         for(int i=0;i<word.length();i++)
         {
            char original=word[i];
            for (char c='a';c<='z';c++)
            {
             word[i]=c;
             if(st.find(word)!=st.end())
             {
                vec.push_back(word);
                usedOnLevel.push_back(word);
                q.push(vec);
                vec.pop_back();
             }
            }
            word[i]=original;
         }
        }
        return ans;
    }
};
