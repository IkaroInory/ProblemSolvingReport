template <typename T>
struct ListNode {
    T val;
    ListNode* next;

    ListNode() : ListNode(0, nullptr) {}
    ListNode(T val) : ListNode(val, nullptr) {}
    ListNode(T val, ListNode* next) : val(val), next(next) {}
};

template <typename T>
class unidirectional_chain {
private:
    int listSize;
    ListNode<T>* first;
    ListNode<T>* last;
public:
    unidirectional_chain() : listSize(0), first(nullptr), last(nullptr) {}
    unidirectional_chain(const unidirectional_chain<T>& list) {
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
        while (cur != nullptr) {
            target = new ListNode<T>(cur->val);
            cur = cur->next;
            target = target->next;
            if (cur->next != nullptr)
                last = target;
        }
        target = nullptr;
    }
    ~unidirectional_chain() {
        while (first != nullptr) {
            ListNode<T>* cur = first->next;
            delete first;
            first = cur;
        }
    }

    friend ostream& operator<<(ostream& out, const unidirectional_chain<T>& list) {
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
        }
        else {
            ListNode<T>* p = first;
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            del = p->next;
            p->next = p->next->next;
            if (p->next->next == nullptr)
                last = p;
        }
        listSize--;
        delete del;
    }
    void insert(int index, const T& element) {
        if (index < 0 || index > listSize) return;
        if (index == 0)
            first = new ListNode<T>(element, first);
        else {
            ListNode<T>* p = first;
            for (int i = 0; i < index - 1; i++)
                p = p->next;
            if (p->next == nullptr) {
                p->next = new ListNode<T>(element, p->next);
                last = p->next;
            }
            else
                p->next = new ListNode<T>(element, p->next);
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
        ListNode<T>* newNode = new ListNode<T>(element);
        if (first == nullptr)
            first = last = newNode;
        else {
            last->next = newNode;
            last = newNode;
        }
        listSize++;
    }

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
        iterator operator++(int) {
            iterator old = *this;
            node = node->next;
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
    };

    iterator begin() {
        return iterator(first);
    }
    iterator end() {
        return iterator();
    }
};