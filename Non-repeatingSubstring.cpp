#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[127];
        memset(map, -1, sizeof(map));
        int i = 0,j = 0;
        int res = 0;
        while (j < s.size())
        {
            if(map[s[j]]!=-1){
                i = max(i, map[s[j]]+1);
            }
            map[s[j]] = j;
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};