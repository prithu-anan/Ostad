/*
Using Unordered Map
Time Complexity: Amortised O(n), due to using insert function in loop
Space Complexity: O(n), due to using an unordered map
*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int,int> sum; // O(n) space

    for(int i = 0; i < nums.size(); i++){ // O(n) time
        if(sum.find(target - nums[i]) != sum.end()){
            ans.push_back(i);
            ans.push_back(sum.find(target - nums[i]) -> second);
            return ans;
        }

        sum.insert({nums[i], i}); // Amortised O(n) time
    }

    return ans;
}



/*
Using Binary Search
Time Complexity: O(nlogn), due to using sort function
Space Complexity: O(n), due to using an extra vpi to store indices
*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> mp; // O(n) space
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) // O(n) time
        mp.push_back(make_pair(nums[i], i));
    
    sort(mp.begin(), mp.end()); // O(nlogn) time

    int left = 0, right = mp.size() - 1, sum;

    while(left < right){ // O(n) time
        sum = mp[left].first + mp[right].first;
        if(sum == target){
            ans.push_back(mp[left].second);
            ans.push_back(mp[right].second);
            return ans;
        }
        if(sum < target) left++;
        else right--;
    }
    return ans;
}
