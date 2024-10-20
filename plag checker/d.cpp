#include <iostream>
#include <vector>

std::vector<int> findEvenNumbers(const std::vector<int>& arr) {
    std::vector<int> evenNumbers;
    for (int num : arr) {
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        }
    }
    return evenNumbers;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> even = findEvenNumbers(vec);

    std::cout << "Even numbers: ";
    for (int i=0;i<even.size();i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
