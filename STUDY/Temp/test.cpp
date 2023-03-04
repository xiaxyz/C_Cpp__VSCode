#include <bits\stdc++.h>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        while (nums1.size() + nums2.size() > 2)
        {
            if (nums1.size() == 0)
            {
                nums2.erase(nums2.begin());
                nums2.pop_back();
            }
            else if (nums2.size() == 0)
            {
                nums1.erase(nums1.begin());
                nums1.pop_back();
            }
            else
            {
                if (nums1.front() < nums2.front())
                {
                    nums1.erase(nums1.begin());
                }
                else
                {
                    nums2.erase(nums2.begin());
                }
                if (nums2.size() != 0 && nums1.back() < nums2.back())
                {
                    nums2.pop_back();
                }
                else
                {
                    nums1.pop_back();
                }
            }
        }
        if (nums1.size() == 2)
        {
            return 1.0 * (nums1[0] + nums1[1]) / 2;
        }
        else if (nums2.size() == 2)
        {
            return 1.0 * (nums2[0] + nums2[1]) / 2;
        }
        else if (nums1.size() == 1)
        {
            if (nums2.size() == 1)
            {
                return 1.0 * (nums1[0] + nums2[0]) / 2;
            }
            else
            {
                return nums1[0];
            }
        }
        else if (nums2.size() == 1)
        {
            if (nums1.size() == 1)
            {
                return 1.0 * (nums2[0] + nums1[0]) / 2;
            }
            else
            {
                return nums2[0];
            }
        }
        return 0;
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // sort(nums1.begin(), nums1.end());
        // if (nums1.size() % 2 == 0)
        // {
        //     return 1.0 * (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
        // }
        // else
        // {
        //     return nums1[nums1.size() / 2];
        // }
    }
};
int main(int argc, char **argv)
{
    vector<int> a{2,2,2,2}, b{2,2,2};
    Solution S;
    string T;
    cin >> T;
    cout << S.findMedianSortedArrays(a, b) << T;
    return 0;
}
