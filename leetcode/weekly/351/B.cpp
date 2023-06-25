#include<iostream>
#include<vector>
#include<set>
#include<string>
#define ll long long
using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) 
    {
        long long int a = num1, b = num2;
        long long ans = 0;
        while(a)
        {
            if(ans>a) ;
            else if(__builtin_popcountll(a) <= ans) break;
            a -= b;
            if(a<=0) return -1;
            ans++;
        }
        cout<<a<<endl;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.makeTheIntegerZero(112577768,-501662198) << endl;
    return 0;
}

/*
112577768
-501662198
*/