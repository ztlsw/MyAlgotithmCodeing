#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

class WordDictionary {
private:
    int idx = 0;
    vector<bool> isend;
    int lim[26] = {0};
    vector<vector<int>> vto; 
public:
    WordDictionary() {
        vto.push_back(vector<int>(lim,lim+26));
        isend.push_back(0);
    }
    void addWord(string word) {
        int base = 0;
        for(auto &c : word)
        {
            if(vto[base][c-'a'] == 0)
            {
                vto.push_back(vector<int>(lim,lim+26));
                vto[base][c-'a'] = ++idx;
                isend.push_back(0);
            }
            base = vto[base][c-'a'];
        }
        isend[base] = 1;
    }
    
    bool search(string word) 
    {
        return dfs(0,word,0);
    }
    inline bool dfs(int Index,string &word,int idx)
    {
        if(Index == word.size()) return isend[idx];
        char c = word[Index];
        if(c>='a'&&c<='z')
        {
            if(vto[idx][c-'a']) return dfs(Index+1,word,vto[idx][c-'a']);
        }
        else
        {
            bool flag = 0;
            for(int i = 0;i<26;i++)
            {
                if(vto[idx][i])
                {
                    flag|=dfs(Index+1,word,vto[idx][i]);
                }
            }
            return flag;
        }
    return false;    
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */