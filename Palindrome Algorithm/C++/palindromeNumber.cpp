/*Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */
#include<bits/stdc++.h>
using namespace std;
 bool isPalindrome(long long int x) {
      if(x<0)
      return false;
      long long int x1=x;
      long long int rev=0;
      while(x1>0)
      {
          int dig=x1%10;
          rev=rev*10+dig;
          x1=x1/10;

      }  

      if(rev==x)
      return true;
      return false;
    }
