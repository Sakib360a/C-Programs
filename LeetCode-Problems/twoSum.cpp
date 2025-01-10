#include<bits/stdc++.h>
using namespace std;

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_table; // Create an unordered_map to store the indices of numbers
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Calculate the complement
        if (hash_table.find(complement) != hash_table.end()) {
            // If complement is found in the hash table, return the indices
            return {hash_table[complement], i};
        }
        // Otherwise, add the number and its index to the hash table
        hash_table[nums[i]] = i;
    }
    return {}; // In case no solution is found (though the problem guarantees exactly one solution)
}


int main() {
    // Example 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << "[" << result1[0] << "," << result1[1] << "]" << std::endl; // Output: [0, 1]

    // Example 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << "[" << result2[0] << "," << result2[1] << "]" << std::endl; // Output: [1, 2]

    // Example 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);
    std::cout << "[" << result3[0] << "," << result3[1] << "]" << std::endl; // Output: [0, 1]

    return 0;
}
