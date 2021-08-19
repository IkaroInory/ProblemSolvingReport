using System;
using System.Collections.Generic;

namespace cs
{
    public class Solution
    {
        public bool IsVowels(char c)
        {
            return "aeiouAEIOU".IndexOf(c) >= 0;
        }
        public void Swap(char[] s, int a, int b)
        {
            var temp = s[a];
            s[a] = s[b];
            s[b] = temp;
        }
        public string ReverseVowels(string s)
        {
            int left = 0, right = s.Length - 1;
            char[] str = s.ToCharArray();
            while (left < right)
            {
                if (IsVowels(str[left]) && IsVowels(str[right])) Swap(str, left++, right--);
                if (!IsVowels(str[left])) left++;
                if (!IsVowels(str[right])) right--;
            }
            return new string(str);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<string> s = new List<string>
            {
                "hello",
                "leetcode"
            };

            foreach(var p in s)
            {
                Console.WriteLine("Input: {0}", p);
                Console.WriteLine("Output: {0}", new Solution().ReverseVowels(p));
            }
        }
    }
}
