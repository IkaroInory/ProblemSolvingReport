public class Solution
    {
        public int CompareVersion(string version1, string version2)
        {
            string[] s1 = version1.Split('.');
            string[] s2 = version2.Split('.');

            for(int i = 0; i < Math.Max(s1.Length, s2.Length); i++)
            {
                int x = 0, y = 0;
                if (i < s1.Length)
                {
                    x = int.Parse(s1[i]);
                }
                if (i < s2.Length)
                {
                    y = int.Parse(s2[i]);
                }
                if (x > y) return 1;
                if (x < y) return -1;
            }

            return 0;
        }
    }