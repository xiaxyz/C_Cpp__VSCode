#include <bits\stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> Answer;
        sort(nums.begin(), nums.end());
        int NumI = nums[0];
        for (int i = 0, NumsSize = nums.size(); i < NumsSize; ++i)
        {
            if (nums[i] == NumI && i != 0)
            {
                continue;
            }
            else
            {
                NumI = nums[i];
            }
            int Left = i + 1;
            int Right = nums.size() - 1;
            while (Left < Right)
            {
                if (NumI + nums[Left] + nums[Right] < 0)
                {
                    ++Left;
                    continue;
                }
                else if (NumI + nums[Left] + nums[Right] > 0)
                {
                    --Right;
                    continue;
                }
                else
                {
                    Answer.push_back(vector<int>{NumI, nums[Left], nums[Right]});
                    while (nums[Left] == nums[Left + 1])
                    {
                        ++Left;
                    }
                    while (nums[Right] == nums[Right - 1])
                    {
                        --Right;
                    }
                    ++Left;
                    --Right;
                }
            }
        }
        return Answer;
    }
};
int main(int argc, char **argv)
{
    vector<int> a{0,0,0};
    vector<vector<int>> b = Solution().threeSum(a);
    return 0;
}
