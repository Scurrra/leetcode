#include <vector>
#include <numeric>
#include <algorithm>

/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool canThreePartsEqualSum(std::vector<int> &arr)
    {
        int sum = std::accumulate(arr.begin(), arr.end(), 0);

        if (sum == 0)
        {
            int i = 0, part = arr[i++];
            while (part != sum && i < arr.size())
                part += arr[i++];
            if (part != sum || i > arr.size() - 1)
                return false;

            part = arr[i++];
            while (part != sum && i < arr.size())
                part += arr[i++];
            if (part != sum || i > arr.size() - 1)
                return false;

            part = arr[i++];
            while (part != sum && i < arr.size())
                part += arr[i++];
            if (part != sum)
                return false;

            return i <= arr.size();
        }

        if (sum % 3 != 0 || std::abs(sum) < 3)
            return false;

        sum /= 3;

        int i = 0, part = 0;
        while (part != sum && i < arr.size() - 1)
            part += arr[i++];
        if (part != sum)
            return false;

        part = 0;
        while (part != sum && i < arr.size() - 1)
            part += arr[i++];
        if (part != sum)
            return false;

        return true;
    }
};
// @lc code=end
