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