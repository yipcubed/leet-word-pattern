#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/word-pattern/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss{str};
        map<char,string> c2s;
        map<string, char> s2c;
        string word;
        int i = 0;
        while (i < pattern.length() && ss >> word) {
            char c = pattern[i];
            if (c2s.count(c)) {
                if (c2s[c] != word || s2c[word] != c)
                    return false;
            } else {
                if (s2c.count(word)) return false;
                c2s[c] = word;
                s2c[word] = c;
            }
            ++i;
        }
        return i == pattern.length() && !ss.good();
    }
};

void test1() {
    vector<int> v1{1,2,3,4,5,6,7,8};
    string p1 = "abba", s1 = "dog cat cat dog";

    cout << "1 ? " << Solution().wordPattern(p1,s1) << endl;

    string pattern = "abba", str = "dog cat cat fish";
    cout << "0 ? " << Solution().wordPattern(pattern,str) << endl;

    pattern = "aaaa", str = "dog cat cat dog";
    cout << "0 ? " << Solution().wordPattern(pattern,str) << endl;

    pattern = "abba", str = "dog dog dog dog";
    cout << "0 ? " << Solution().wordPattern(pattern,str) << endl;

    pattern = "ab", str = "dog dog";
    cout << "0 ? " << Solution().wordPattern(pattern,str) << endl;

}

void test2() {

}

void test3() {

}