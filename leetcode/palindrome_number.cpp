#include <iostream>

class PalindromeNumber
{
public:
    bool isPalindrome(int x) 
    {
        // reversed -1 is 1-. So negative number is not palindrome
        // 0 is palindrome number
        // x % 10 == 0 like 10, 100 etc. are not palindrome number
        if(x < 0 || x != 0 && x % 10 == 0) return 0;

        int reversed = 0;

        while (x > reversed)
        {
            // get the last digit of x by x % 10
            // append the digit to reversed by adding to reversed * 10
            reversed = reversed * 10 + x % 10;
            // remove the last digit of x
            x /= 10;

            // the loop should break when x has less or equal digits as reversed.
        }

        // 121 should have x = 1, reversed = 12
        // 1221 should have x = 12, reversed = 12

        return (x == reversed   // for even digits number (e.g., 1221)
                || x == reversed / 10);  // for odd digits number (e.g., 121)
    }
};
