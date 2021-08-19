using System;
using System.Collections.Generic;

namespace cs
{
    public class Solution
    {
        public string Convert(string s, int numRows)
        {
            if (numRows == 1) return s;
            if (s.Length < numRows) return s;

            int x = 0, y = 0;
            bool isRow = true;
            List<List<char>> c = new List<List<char>>();

            // Initialize collection.
            for (int i = 0; i < numRows; i++)
            {
                c.Add(new List<char>());
                for (int j = 0; j < s.Length; j++) c[i].Add(' ');
            }

            for (int i = 0; i < s.Length; i++)
            {
                // It will be no downward process when numRows = 2.
                // It means chars are arranged from top to bottom.
                if (numRows == 2) isRow = true;

                if (isRow)
                {
                    c[y++][x] = s[i];
                    if (y == numRows)
                    {
                        x++;
                        y -= 2;
                        isRow = false;
                    }
                }
                else
                {
                    c[y--][x++] = s[i];
                    if (y == -1)
                    {
                        x--;
                        y += 2;
                        isRow = true;
                    }
                }
            }

            string ans = null;
            for (int i = 0; i < numRows; i++)
                for (int j = 0; j < s.Length; j++)
                    if (c[i][j] != ' ') ans += c[i][j];
            return ans;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<string> s = new List<string>
            {
                "PAYPALISHIRING",
                "PAYPALISHIRING",
                "A",
                "A",
                "ABC"
            };
            List<int> numRows = new List<int> { 3, 4, 1, 2, 2 };

            for (int i = 0; i < s.Count; i++)
            {
                Console.WriteLine("Input: {0}, {1}", s[i], numRows[i]);
                Console.WriteLine("Output: {0}", new Solution().Convert(s[i], numRows[i]));
            }
        }
    }
}
