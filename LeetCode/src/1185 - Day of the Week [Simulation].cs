public class Solution
{
    public string DayOfTheWeek(int day, int month, int year)
    {
        string[] week = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
        int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            days[2]++;

        int amount = 0;
        for (int i = 1971; i < year; i++)
            amount += 365 + Convert.ToInt32((i % 4 == 0 && i % 100 != 0) || i % 400 == 0);
        for (int i = 1; i < month; i++)
            amount += days[i];
        amount += day - 1;

        return week[amount % 7];
    }
}