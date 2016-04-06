#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int findMin(vector<int> &num) 
    {
        if(num.empty())
            return 0;
        else if(num.size() == 1)
            return num[0];
        else
        {
            for(vector<int>::size_type st = 1; st < num.size(); st ++)
            {
                if(num[st-1] > num[st])
                    return num[st];
            }
            return num[0];
        }
    }
};

int main()
{
    int A[] = {10,10,10,1,10};
    vector<int> test(A,A+5);
    Solution sol;
    cout << sol.findMin(test)<<endl;
    return 0;
}