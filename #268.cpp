/*

Problem Description:

This problem was asked by Indeed.

Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.

*/

// Logic: Terminating conditions: 1) If the remainder of the number left is not equal to zero (false)
//                                2) If number is equal to 1 (true)
// In simple terms, keep a track on the *remainder* and *quotient* of the given number
bool isPowerOfFour(int n)
{
    // fact: 0 is not a power of any number
    if (n == 0)
        return false;
    while (n != 1)
    {
        // Remainder
        if (n % 4 != 0)
            return false;
        // Quotient
        else
            n = n / 4;
    }
    // if the remainder is 1 the num is clearly divisible by 4
    if (n == 1)
        return true;
    // non-void -> return
    return true;
}

// Another solution

bool isPowerOfFour(unsigned int n)
{
    return n != 0 && ((n & (n - 1)) == 0) && !(n & 0xAAAAAAAA);
}

/*
Time Complexity: O(log4(N)) < O(log2(N))
Space Complexity: O(1)
*/