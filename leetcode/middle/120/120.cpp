#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int> v1,v2;
        int len = triangle.size();
        for(int i = 0;i<len;i++)
        {
            v2 = v1;
            v1.clear();
            //cout<<"111"<<endl;
            if(i == 0)
            {
                v1.push_back(triangle[i][0]);
                continue;
            }
            for(int j = 0;j<triangle[i].size();j++)
            {
                int lim = triangle[i][j];
                if(j == triangle[i].size()-1) lim += v2[j-1];
                else if(j == 0) lim += v2[0];
                else lim += min(v2[j-1],v2[j]);
                v1.push_back(lim);
                
            }
        }
        sort(v1.begin(),v1.end());
        return v1[0];
    }
};