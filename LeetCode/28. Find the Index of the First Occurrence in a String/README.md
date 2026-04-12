# 28. Find the Index of the First Occurrence in a String

## Metadata
- Platform: LeetCode
- Difficulty: Easy
- Language: C++
- Topics: Two Pointers, String, String Matching
- Problem: [https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1975974967/](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1975974967/)

## Solution

```cpp
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
```
