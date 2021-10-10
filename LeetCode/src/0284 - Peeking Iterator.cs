// C# IEnumerator interface reference:
// https://docs.microsoft.com/en-us/dotnet/api/system.collections.ienumerator?view=netframework-4.8

class PeekingIterator
{
    private IEnumerator<int> _iter;
    private bool _hasNext;

    public PeekingIterator(IEnumerator<int> iterator)
    {
        _iter = iterator;
        _hasNext = iterator.MoveNext();
    }

    public int Peek()
    {
        return _iter.Current;
    }

    public int Next()
    {
        int res = _iter.Current;
        _hasNext = _iter.MoveNext();
        return res;
    }

    public bool HasNext()
    {
        return _hasNext;
    }
}