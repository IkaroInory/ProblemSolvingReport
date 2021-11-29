template <typename T>
struct ListNode {
    T val;
    ListNode* prev;
    ListNode* next;

    ListNode() : ListNode(0, nullptr, nullptr) {}
    ListNode(T val) : ListNode(val, nullptr, nullptr) {}
    ListNode(T val, ListNode* prev, ListNode* next) : val(val), prev(prev), next(next) {}
};

template <typename T>
class bidirectional_chain {
private:
    int listSize;
    ListNode<T>* first;
    ListNode<T>* last;
public:
    class iterator {
    protected:
        ListNode<T>* node;
    public:
        iterator() : node(nullptr) {}
        iterator(ListNode<T>* node) : node(node) {}

        T& operator*() const {
            return node->val;
        }
        T* operator->() const {
            return &node->val;
        }
        iterator operator++() {
            node = node->next;
            return *this;
        }
        iterator operator--() {
            node = node->prev;
            return *this;
        }
        iterator operator++(int) {
            iterator old = *this;
            node = node->next;
            return old;
        }
        iterator operator--(int) {
            iterator old = *this;
            node = node->prev;
            return old;
        }
        bool operator!=(const iterator right) const {
            return node != right.node;
        }
        bool operator==(const iterator right) const {
            return node == right.node;
        }
        int operator-(const iterator right) const {
            return this->node - right.node;
        }
        iterator operator+(int right) const {
            ListNode<T>* res = this->node;
            for (int i = 0; i < right; i++)
                if (res != nullptr)
                    res = res->next;
            return iterator(res);
        }
        iterator operator-(int right) const {
            ListNode<T>* res = this->node;
            for (int i = 0; i < right; i++)
                if (res != nullptr)
                    res = res->prev;
            return iterator(res);
        }
    };

    bidirectional_chain() : listSize(0), first(nullptr), last(nullptr) {}
    bidirectional_chain(const bidirectional_chain<T>& list) {
        listSize = list.listSize;
        if (listSize == 0) {
            first = nullptr;
            last = nullptr;
            return;
        }
        ListNode<T>* cur = list.first;
        ListNode<T>* target = new ListNode<T>(cur->val);
        first = target;
        cur = cur->next;
        target = target->next;
        target->prev = first;
        while (cur != nullptr) {
            ListNode<T>* prev = target;
            target = new ListNode<T>(cur->val);
            cur = cur->next;
            target = target->next;
            target->prev = target;
            if (cur->next != nullptr)
                last = target;
        }
        target = nullptr;
    }
    ~bidirectional_chain() {
        while (first != nullptr) {
            ListNode<T>* cur = first->next;
            delete first;
            first = cur;
        }
    }

    friend ostream& operator<<(ostream& out, const bidirectional_chain<T>& list) {
        if (list.first == nullptr)
            return out;
        out << list.first->val;
        for (ListNode<T>* cur = list.first->next; cur != nullptr; cur = cur->next) {
            out << " " << cur->val;
        }
        return out;
    }

    bool empty() const {
        return listSize == 0;
    }
    int size() const {
        return listSize;
    }
    int indexOf(const T& element) const {
        ListNode<T>* cur = first;
        int index = 0;
        while (cur != nullptr && cur->val != element) {
            cur = cur->next;
            index++;
        }

        return cur == nullptr ? -1 : index;
    }
    void erase(int index) {
        if (index < 0 || index > listSize) return;

        ListNode<T>* del;
        if (index == 0) {
            del = first;
            first = first->next;
            first->prev = nullptr;
        }
        else {
            ListNode<T>* p = first;
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            del = p->next;
            p->next = p->next->next;
            if (p->next->next != nullptr)
                p->next->next->prev = p;
            else
                last = p;
        }
        listSize--;
        delete del;
    }
    void insert(int index, const T& element) {
        if (index < 0 || index > listSize) return;
        if (index == 0)
            first = new ListNode<T>(element, nullptr, first);
        else {
            ListNode<T>* p = first;
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            if (p->next == nullptr) {
                p->next = new ListNode<T>(element, p, p->next);
                last = p->next;
            }
            else
                p->next = new ListNode<T>(element, p, p->next);
        }
        listSize++;
    }
    void clear() {
        while (first != nullptr) {
            ListNode<T>* next = first->next;
            delete first;
            first = next;
        }
        last = nullptr;
        listSize = 0;
    }
    void push_back(const T& element) {
        if (first == nullptr)
            first = last = new ListNode<T>(element);
        else {
            last->next = new ListNode<T>(element, last, nullptr);
            last = last->next;
        }
        listSize++;
    }

    iterator begin() {
        return iterator(first);
    }
    iterator rbegin() {
        return iterator();
    }
    iterator end() {
        return iterator();
    }
    iterator rend() {
        return iterator(last);
    }
};