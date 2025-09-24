#include <iostream>
#include <algorithm> 
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        unordered_map<int, int> map;
        while (i<nums.size())
        {
            if(map.find(target-nums[i])!=map.end()){
                return {i,map[target-nums[i]]};
            }
            else map[nums[i]] = i;
            i++;
        } 
        return {};
    }
};
int main()  {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums,target);
    for(int i = 0; i <res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}