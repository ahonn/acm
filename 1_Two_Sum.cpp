// Two Sum

// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        map<int, int> mp;
        int find;
        vector<int> v;
        for(int i = 0;i < length; i++) {
            find = mp[target -nums[i]];
            if(find) {
                v.push_back(find);
                v.push_back(i+1);
                break;
            }
            mp[nums[i]] = i+1;
        }
        return v;
    }
};