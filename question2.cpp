#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxScore(std::vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += cardPoints[i];
        }
        
        if (k == N) return sum;
        
        long long count = 0;
        for (int i = 0; i < N - k; i++) {
            count += cardPoints[i];
        }
        
        long long res = sum - count;
        
        for (int i = N - k; i < N; i++) {
            count += cardPoints[i] - cardPoints[i - N + k];
            res = std::max(res, sum - count);
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    
    int N, k;
    std::cout << "Enter the number of cards: ";
    std::cin >> N;
    
    std::vector<int> cardPoints(N);
    std::cout << "Enter the points for each card: ";
    for (int i = 0; i < N; i++) {
        std::cin >> cardPoints[i];
    }
    
    std::cout << "Enter the value of k: ";
    std::cin >> k;
    
    long long result = solution.maxScore(cardPoints, k);
    std::cout << "Maximum score: " << result << std::endl;
    
    return 0;
}