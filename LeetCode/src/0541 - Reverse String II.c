void reverse(char* s, int length)
{
    int len = length;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

char* reverseStr(char* s, int k)
{
    int length = strlen(s);

    for (int i = 0; i < ceil(length / (2.0 * k)); i++)
    {
        int p = 2 * i * k;
        if (length - p < k)
        {
            reverse(&s[p], length - p);
            break;
        }
        reverse(&s[p], k);
    }
    
    return s;
}