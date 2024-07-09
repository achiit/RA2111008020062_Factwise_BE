#include <iostream>
#include <string>
#include <vector>

int letterCount(int num) {
    std::vector<std::string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                                     "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    if (num == 1000) return 11; 
    
    int count = 0;
    
    if (num >= 100) {
        count += ones[num / 100].length() + 7; 
        if (num % 100 != 0) count += 3;
        num %= 100;
    }
    
    if (num >= 20) {
        count += tens[num / 10].length();
        if (num % 10 != 0) count += ones[num % 10].length();
    } else {
        count += ones[num].length();
    }
    
    return count;
}

int main() {
    int total = 0;
    for (int i = 1; i <= 1000; i++) {
        total += letterCount(i);
    }
    std::cout << "Total letters: " << total << std::endl;
    return 0;
}