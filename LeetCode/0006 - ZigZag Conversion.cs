public class Solution
{
    public string Convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        if (s.Length < numRows) return s;

        int x = 0, y = 0;
        bool isRow = true;
        List<List<char>> c = new List<List<char>>();

        for (int i = 0; i < numRows; i++)
        {
            c.Add(new List<char>());
            for (int j = 0; j < s.Length; j++) c[i].Add(' ');
        }

        for (int i = 0; i < s.Length; i++)
        {
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