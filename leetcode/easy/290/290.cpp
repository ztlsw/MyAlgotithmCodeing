#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> lim;
        istringstream tokenS(s);
        map<string,char> mp;
        map<char,string> mp2;
        string lis;
        while(getline(tokenS,lis,' ')) lim.push_back(lis);
        if(lim.size()!=pattern.size()) return 0;
        for(int i = 0;i<pattern.size();i++)
        {
            if(!mp.count(lim[i])) mp[lim[i]] = pattern[i];
            else if(mp[lim[i]]!=pattern[i]) return 0;
            if(!mp2.count(pattern[i])) mp2[pattern[i]] = lim[i];
            else if(mp2[pattern[i]]!=lim[i]) return 0;
        }
        return 1;
    }
};