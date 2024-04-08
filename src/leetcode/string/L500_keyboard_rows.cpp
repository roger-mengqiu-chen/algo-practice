#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2},
            {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}
            };
        vector<string> res = {};

        for(string word: words)
        {
            int row_num = m[tolower(word[0])];
            bool same_row = true;

            for (int i = 1; i < word.length() && same_row; i++)
            {
                same_row = m[tolower(word[i])] == row_num;
            }
            if (same_row)
            {
                res.push_back(word);
            }
        }
        return res;
    }

    // Because we have a small amount of characters, using string will consume less memory and have almost the same performance. 
    // Not going to show the implementation here.
};

int main()
{
    Solution s;
    vector<string> ss = {"Hello","Alaska","Dad","Peace"};
    vector<string> res = s.findWords(ss);
    for (string _ : res)
    {
        cout << _ << " ";
    }
    cout << endl;
}