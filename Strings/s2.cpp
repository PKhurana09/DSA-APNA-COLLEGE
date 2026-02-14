// 13. Roman to Integer

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int romanToInt(string s);

int main(void){

    return EXIT_SUCCESS;
}

int romanToInt(string s){
    int n = s.size();
    unordered_map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;

    for (int i = 0; i < n; i++) {
        // If current value is less than next value → subtract
        if (i < n - 1 && table[s[i]] < table[s[i + 1]]) {
            ans -= table[s[i]];
        }else {
            ans += table[s[i]];
        }
    }

    return ans;
}
