// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator<E> implements Iterator<E> {
    private Iterator<E> _iter;
    private E _next;

    public PeekingIterator(Iterator<E> iterator) {
        _iter = iterator;
        _next = iterator.next();
    }

    public E peek() {
        return _next;
    }

    @Override
    public E next() {
        E res = _next;
        _next = _iter.hasNext() ? _iter.next() : null;
        return res;
    }

    @Override
    public boolean hasNext() {
        return _next != null;
    }
}