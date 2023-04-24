class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            int current = nums.at(i);
            auto iter = map.find(target-current);
            if(iter !=map.end()){
                result.push_back(i);
                result.push_back(iter->second);
                break;
            }
            map[current] = i;
        }
        return result;
    }
};