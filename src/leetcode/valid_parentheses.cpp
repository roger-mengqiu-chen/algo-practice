#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.length() % 2 != 0) return false;

        stack<char> st;  // we can use string here to reduce memory usage. But using stack makes more sense. 

        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[') st.push(c);

            else 
            {
                if(st.empty()) return false;

                char t = st.top();
                st.pop();
                if((c == ')' && t != '(')
                    || (c == ']' && t != '[')
                    || (c == '}' && t != '{'))
                    return false;
            }
        }
        return st.empty();
    }
};
