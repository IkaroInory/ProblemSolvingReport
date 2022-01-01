public class Solution
{
    public int[][] Construct2DArray(int[] original, int m, int n)
    {
        if (original.Length != m * n) return new int[][] { };

        int[][] res = new int[m][];
        for (int i = 0; i < m; i++)
        {
            int[] temp = new int[n];
            for (int j = 0; j < n; j++)
                temp[j] = original[i * n + j];
            res[i] = temp;
        }

        return res;
    }
}