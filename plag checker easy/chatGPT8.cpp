#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true; // Found a duplicate
        }
        seen.insert(num);
    }
    
    return false; // No duplicates found
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 1}; // Example array
    
    if (containsDuplicate(nums)) {
        std::cout << "Array contains duplicates." << std::endl;
    } else {
        std::cout << "Array does not contain duplicates." << std::endl;
    }
    
    return 0;
}
