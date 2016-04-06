#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        dungeon[m-1][n-1] = max(0-dungeon[m-1][n-1], 0);
        for (int i = m - 2; i >= 0; --i) 
        {
            dungeon[i][n-1] = max(dungeon[i+1][n-1]-dungeon[i][n-1], 0);
        }
        for (int j = n - 2; j >= 0; --j) 
        {
            dungeon[m-1][j] = max(dungeon[m-1][j+1]-dungeon[m-1][j], 0);
        }
        for (int i = m - 2; i >= 0; --i) 
        {
            for (int j = n - 2; j >= 0; --j) 
            {
                dungeon[i][j] = max(min(dungeon[i][j+1], dungeon[i+1][j])-dungeon[i][j], 0);
            }
        }
        return dungeon[0][0] + 1;
    }
};

int main()
{
    int A1[] = {-2,-3,3};
    int A2[] = {-5,-10,1};
    int A3[] = {10,30,-5};
    vector<vector<int> > dungeon;
    dungeon.push_back(vector<int>(A1,A1+3));
    dungeon.push_back(vector<int>(A2,A2+3));
    dungeon.push_back(vector<int>(A3,A3+3));

    Solution sol;
    cout<<sol.calculateMinimumHP(dungeon)<<endl;
}