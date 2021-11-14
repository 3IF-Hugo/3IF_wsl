#include <vector>

vector<int> twoSum(vector<int>& nums, int target) {  
        int sum=0;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                sum = nums[i]+nums[j];
                if(sum == target && i != j)
                {
                    v = { i, j};
                    break;
                }
            }
        }
        return v;
    }
}

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ht;
        int size = nums.size();
        vector<int> v;
        for(int i=0; i < size; i++)
        {
            if(ht.find(nums[i]) == nums[i])
            {
                v = {i, ht[nums[i]]};
                return 
            }
            ht[target - nums[i]] = i;
        }
    }
};
*/