/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int _nextV;
    bool _hasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _hasNext = Iterator::hasNext();
        if (_hasNext) {
            _nextV = Iterator::next();
        }
	}
	
	int peek() {
        return _nextV;
	}
	
	int next() {
	    int res = _nextV;
        _hasNext = Iterator::hasNext();
        _nextV = _hasNext ? Iterator::next() : 0;
        return res;
	}
	
	bool hasNext() const {
	    return _hasNext;
	}
};