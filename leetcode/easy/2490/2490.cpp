#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
            char base = sentence[0];
            for(int i=1;i<sentence.size();i++)
            {
                if(sentence[i]==" ") 
                {
                    if(sentence[i-1] != sentence[i+1]) return 0;
                }
            }
            if(sentence[0]!=sentence[sentence.size()-1]) return 0;
            return 1;
    }
};