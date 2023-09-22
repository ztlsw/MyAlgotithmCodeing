#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
struct TrieNode
{
    vector<TrieNode *>child;
    bool isEnd;
    TrieNode()
    {
        this->child = vector<TrieNode *>(26,nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode * root,const string & word)
{
    TrieNode * node = root;
    for(auto c : word)
    {
        if(node->child[c-'a'] == nullptr) node->child[c-'a'] = new TrieNode();
        node = node->child[c-'a'];
    }
    node->isEnd = true;
}

class WordDictionary {
private:
    TrieNode *trie;
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(trie,word);
    }
    
    bool search(string word) {
        return dfs(word,0,trie);
    }

    inline bool dfs(const string & word,int Index,TrieNode * node)
    {
        if(Index == word.size()) return node->isEnd;
        char ch = word[Index];
        if(ch>='a' && ch<='z')
        {
            TrieNode * child = node->child[ch-'a'];
            if(child != nullptr && dfs(word,Index +1 ,child)) return true;
        }
        else if(ch == '.')
        {
            for(int i = 0;i<26;i++)
            {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, Index + 1, child)) return true;
            }
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