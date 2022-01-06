using System;
using System.Collections.Generic;

public class Solution
{
    public int MaxDepth(string s)
    {
        int depth = 0;
        Stack<char> list = new Stack<char>();
        foreach (var c in s)
        {
            if (c == '(') list.Push(c);
            else if (c == ')') list.Pop();
            depth = Math.Max(list.Count, depth);
        }
        return depth;
    }
}