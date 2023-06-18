/*
 * @lc app=leetcode id=1 lang=rust
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();

        for i in 0..nums.len() {
            let rem = target - nums[i];

            if let Some(&j) = seen.get(&rem) {
                return vec![i as i32, j as i32];
            }

            seen.insert(nums[i], i);
        }

        return vec![];
    }
}
// @lc code=end