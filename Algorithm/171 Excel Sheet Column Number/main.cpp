#include <iostream>
using namespace std;

class Solution 
{
public:
    int titleToNumber(string s) 
    {
        if(!s.length())
            return 0;

        int result = 0;
        for(int i=0;i<s.length();i++)
        {
            result *= 26;
            result += s[i] - 'A'+1;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout<<sol.titleToNumber("AB")<<endl;
    return 0;
}