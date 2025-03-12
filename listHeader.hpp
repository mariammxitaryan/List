#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T&);
        template<typename... Args>
        Node(Args&&...);
    }

    Node* head;
    Node* timeva;
    size_t size;

public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type= std::ptrdiff_t;
    using reference = value_type&;
    using const_refernce = const value_type&;
    using pointer = Allocator::pointer;
    using const_pointer = Allocator::const_pointer;
    using reverese_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    class iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(Node*);
        reference operator*();
        pointer operator->();
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
    private:
        Node* node_ptr;
    };

    class const_iterator {
        public:
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = const T;
            using difference_type = std::ptrdiff_t;
            using pointer = const T*;
            using reference = const T&;

            const_iterator(Node*);

            reference operator*() const;
            pointer operator->() const;
            const_iterator& operator++();
            const_iterator& operator--();
            const_iterator operator++(int);
            const_iterator operator--(int);
            bool operator==(const const_iterator&) const;
            bool operator!=(const const_iterator&) const;
        private:
            Node* node_ptr;
    };

    class reverse_iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        reverse_iterator(Node*);
        reference operator*();
        pointer operator->();
        reverse_iterator& operator++();
        reverse_iterator& operator--();
        reverse_iterator operator++(int);
        reverese_iterator operator--(int);
        bool operator==(const reverse_iterator&) const;
        bool operator!=(const reverse_iterator&) const;
    private:
        Node* node_ptr;
    };

    class const_reverse_iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = const T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        const_reverse_iterator(Node*);
        reference operator*() const;
        pointer operator->() const;
        const_reverse_iterator& operator++();
        const_reverse_iterator& operator--();
        const_reverse_iterator operator++(int);
        const_reverse_iterator operator--(int);
        bool operator==(const const_reverse_iterator&) const;
        bool operator!=(const const_reverse_iterator&) const;
    private:
        Node* node_ptr;
    };

    List();
    ~List();
    List& operator=(List&&) noexcept;
    List& operator=(const List&);
    List& operator=(std::initializer_list<value_type>);
    void assign(size_type, const T&);

    template<class InputIt>
    void assign(InputIt, InputIt);

    void assign(std::iterator_list<value_type>);

    reference front();
    const_reference front() const;
    size_type size();
    reference back(); 
    const_reference back() const;
    void clear();
    void push_back(const T&);
    iterator insert(const_iterator, const T&);
    iterator insert(const_iterator, T&&);
    iterator insert(const_iterator, size_type, const T&);

    template<class InputIt>
    iterator insert(const_iterator, InputIt, InputIt);

    iterator insert(const_iterator, std::initializer_list<T>);

    template<typename... Args>
    iterator emplace(const_iterator, Args&&...);
    iterator erase(iterator);
    iterator erase(const_iterator);
    iterator erase(iterator, iterator);
    iterator erase(const_iterator, const_iterator);
    
    template <typename... Args>
    void emplace_back(Args&&...) ;

    template<typename... Args>
    reference emplace_back(Args&&...);

    template<std::ranges::range R>
    void append_range(R&&);

    void pop_back();
    void push_front(const T&);
    void push_front(T&& value);

    template<std::ranges::range R>
    void prepend_range(R&&);

    template<typename... Args>
    void emplace_front(Args&&...);

    template<typename... Args>
    reference emplace_front(Args&&...);

    void pop_front();
    void resize(size_type);
    void resize(size_type, const value_type&);
    void swap(List&);
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
    size_type size() const;
    bool empty();
};

#endif