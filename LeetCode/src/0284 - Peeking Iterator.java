// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> _iterator;
    private Integer _nextValue;

    public PeekingIterator(Iterator<Integer> iterator) {
        _iterator = iterator;
        _nextValue = iterator.next();
    }

    public Integer peek() {
        return _nextValue;
    }

    @Override
    public Integer next() {
        Integer res = _nextValue;
        _nextValue = _iterator.hasNext() ? _iterator.next() : null;
        return res;
    }

    @Override
    public boolean hasNext() {
        return _nextValue != null;
    }
}