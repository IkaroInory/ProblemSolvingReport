using System;
using System.Collections.Generic;

public class Solution
{
    public string SimplifyPath(string path)
    {
        string[] elements = path.Split('/', StringSplitOptions.RemoveEmptyEntries);
        Stack<string> list = new Stack<string>();
        foreach (var s in elements)
        {
            if (s == ".") continue;
            if (s == "..")
            {
                if (list.Count == 0) continue;
                list.Pop();
            }
            else
                list.Push(s);
        }

        string res = "";
        while (list.Count != 0)
            res = "/" + list.Pop() + res;

        return res == "" ? "/" : res;
    }
}