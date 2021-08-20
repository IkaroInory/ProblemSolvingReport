using System;
using System.Collections.Generic;

namespace cs
{
    public class Solution
    {
        public string Reverse(char[] c)
        {
            int length = c.Length;
            for (int i = 0; i < length / 2; i++)
            {
                char temp = c[i];
                c[i] = c[length - 1 - i];
                c[length - 1 - i] = temp;
            }
            return new string(c);
        }
        public string ReverseStr(string s, int k)
        {
            int length = s.Length;
            string ans = null;

            for (int i = 0; i < Math.Ceiling(length / (2.0 * k)); i++)
            {
                int p = i * 2 * k;
                if (length - p < k)
                {
                    ans += Reverse(s.ToCharArray(p, length - p));
                    break;
                }
                ans += Reverse(s.ToCharArray(p, k));

                if (length - p >= k && length - p < 2 * k) ans += s.Substring(p + k, length - p - k);
                else ans += s.Substring(p + k, k);
                continue;
            }
            return ans;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<string> s = new List<string>
            {
                "abcde",
                "abcdefg",
                "abcd",
                "abcd"
            };
            List<int> k = new List<int>
            {
                2,
                2,
                2,
                4
            };

            for (int i = 0; i < s.Count; i++)
            {
                Console.WriteLine("Input: {0}, {1}", s[i], k[i]);
                Console.WriteLine("Output: {0}", new Solution().ReverseStr(s[i], k[i]));
            }
        }
    }
}
