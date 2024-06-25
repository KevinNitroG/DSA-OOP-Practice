// https://leetcode.com/problems/global-and-local-inversions/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool isIdealPermutation(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            if (abs(nums[i] - i) > 1)
                return false;
        return true;
    }
};
