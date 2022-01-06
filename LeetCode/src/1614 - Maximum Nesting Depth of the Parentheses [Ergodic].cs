using System;

public class Solution
{
    public int MaxDepth(string s)
    {
        int depth = 0, top = 0;
        foreach (var c in s)
        {
            if (c == '(') top++;
            else if (c == ')') top--;
            depth = Math.Max(top, depth);
        }
        return depth;
    }
}