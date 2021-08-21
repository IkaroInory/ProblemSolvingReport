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
        }

        return ans;
    }
}