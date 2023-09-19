#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
class Solution 
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        if(k<=numOnes)
            return k;
        else if(k<=numOnes+numZeros)
            return numOnes;
        else return numOnes-(k-numOnes-numZeros);
    }
};