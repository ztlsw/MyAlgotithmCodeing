#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#define ll long long
using namespace std;
class Solution {
public:
    int calculate(string s) 
    {
        stack<char> st;
        stack<ll> num;
        s+='+';
        ll len = s.size();
        ll base = 1,lim = 0;
        num.push(0);
        for(int i = 0;i<len;i++)
        {
            if(s[i] == ' ') continue;
            if(isdigit(s[i]))
            {
                ll j = i;
                lim = 0;
                while(j<len&&isdigit(s[j]))
                {
                    lim = lim*10+s[j]-'0';
                    j++;
                }
                i = j-1;
                num.push(lim);
                base = 1;
            }
            else
            {
                if(st.empty()||s[i]=='(')
                {
                    st.push(s[i]);
                    if(s[i] == '(') base = 0;
                    continue;
                }
                if(st.top() == '+')
                {
                    lim = num.top();
                    num.pop();
                    lim+=num.top();
                    num.pop();
                    num.push(lim);
                    st.pop();
                    st.push(s[i]);
                }
                else if(st.top() == '-')
                {
                    lim = num.top();
                    num.pop();
                    lim-=num.top();
                    num.pop();
                    num.push(-1*lim);
                    st.pop();
                    st.push(s[i]);
                }
                else if(st.top() == '(')
                {
                    if(i!=0&&base == 0)
                    {
                        num.push(0);
                    }
                    st.push(s[i]);
                }
                if(s[i] == ')')
                {
                    st.pop();
                    st.pop();
                }
                base = 1;
            }
        }
        return num.top();
    }
};
int main()
{
    Solution a;
    cout<<a.calculate("1-(      -2)")<<endl;
    return 0;
}