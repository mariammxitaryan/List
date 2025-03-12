#include "listHeader.hpp"

/**
 * @brief Default constructor for a list node.
 * 
 * Initializes a new node with the provided value, setting next and prev pointers to nullptr.
 * 
 * @param value The value to store in the node.
 */
template <typename T>
List<T>::Node::Node(const T& value) : data(value), next(nullptr), prev(nullptr) { }

/**
 * @brief Variadic constructor for a list node, forwarding arguments to construct the node's data.
 * 
 * This constructor uses perfect forwarding to initialize the node's data, leaving next and prev pointers as nullptr.
 * 
 * @param args The arguments to construct the node's data.
 */
template <typename T>
template<typename... Args>
List<T>::Node::Node(Args&&... args) : data(std::forward<Args>(args)...), next(nullptr), prev(nullptr) { }

/**
 * @brief Constructor for an iterator, initializing it with a node pointer.
 * 
 * This constructor initializes an iterator to point to the specified node.
 * 
 * @param ptr A pointer to the node the iterator will reference.
 */
template <typename T>
List<T>::iterator::iterator(Node* ptr) : node_ptr(ptr) { }

/**
 * @brief Dereference operator for iterator, returning a reference to the node's data.
 * 
 * This operator allows the iterator to access the data in the node it is pointing to.
 * 
 * @return A reference to the data stored in the current node.
 */
template <typename T>
typename List<T>::iterator::reference List<T>::iterator::operator*() { 
    return node_ptr->data;
}

/**
 * @brief Arrow operator for iterator, returning a pointer to the node's data.
 * 
 * This operator provides access to the data in the current node through pointer dereferencing.
 * 
 * @return A pointer to the data stored in the current node.
 */
template <typename T>
typename List<T>::iterator::pointer List<T>::iterator::operator->() {
    return &node_ptr->data;
}

/**
 * @brief Prefix increment operator for iterator, moving it to the next node.
 * 
 * This operator advances the iterator to the next node in the list.
 * 
 * @return A reference to the updated iterator.
 */
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

/**
 * @brief Postfix increment operator for iterator, returning a copy of the iterator before moving it to the next node.
 * 
 * This operator allows the iterator to move to the next node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was incremented.
 */
template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    iterator tmp = *this;
    node_ptr = node_ptr->next;
    return tmp;
}

/**
 * @brief Prefix decrement operator for iterator, moving it to the previous node.
 * 
 * This operator moves the iterator to the previous node in the list.
 * 
 * @return A reference to the updated iterator.
 */
template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

/**
 * @brief Postfix decrement operator for iterator, returning a copy of the iterator before moving it to the previous node.
 * 
 * This operator allows the iterator to move to the previous node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was decremented.
 */
template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) {
    iterator tmp = *this;
    node_ptr = node_ptr->prev;
    return tmp;
}

/**
 * @brief Equality comparison operator for iterators, checking if two iterators point to the same node.
 * 
 * This operator returns true if the two iterators point to the same node, otherwise false.
 * 
 * @param other The iterator to compare against.
 * @return true if the iterators are equal, false otherwise.
 */
template <typename T>
bool List<T>::iterator::operator==(const iterator& other) const {
    return node_ptr == other.node_ptr;
}

/**
 * @brief Inequality comparison operator for iterators, checking if two iterators point to different nodes.
 * 
 * This operator returns true if the two iterators do not point to the same node, otherwise false.
 * 
 * @param other The iterator to compare against.
 * @return true if the iterators are not equal, false otherwise.
 */
template <typename T>
bool List<T>::iterator::operator!=(const iterator& other) const {
    return node_ptr != other.node_ptr;
}

/**
 * @brief Constructor for a const iterator, initializing it with a node pointer.
 * 
 * This constructor initializes a const iterator to point to the specified node, preventing modification of data.
 * 
 * @param ptr A pointer to the node the iterator will reference.
 */
template <typename T>
List<T>::const_iterator::const_iterator(Node* ptr) : node_ptr(ptr) { }

/**
 * @brief Dereference operator for const iterator, returning a const reference to the node's data.
 * 
 * This operator allows the const iterator to access the data in the node it is pointing to, without modification.
 * 
 * @return A const reference to the data stored in the current node.
 */
template <typename T>
typename List<T>::const_iterator::reference List<T>::const_iterator::operator*() const {
    return node_ptr->data;
}

/**
 * @brief Arrow operator for const iterator, returning a const pointer to the node's data.
 * 
 * This operator provides access to the data in the current node through pointer dereferencing, preventing modification.
 * 
 * @return A const pointer to the data stored in the current node.
 */
template <typename T>
typename List<T>::const_iterator::pointer List<T>::const_iterator::operator->() const {
    return &node_ptr->data;
}

/**
 * @brief Prefix increment operator for const iterator, moving it to the next node.
 * 
 * This operator advances the const iterator to the next node in the list, without modifying the data.
 * 
 * @return A reference to the updated iterator.
 */
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

/**
 * @brief Postfix increment operator for const iterator, returning a copy of the iterator before moving it to the next node.
 * 
 * This operator allows the const iterator to move to the next node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was incremented.
 */
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int) {
    typename List<T>::const_iterator tmp = *this;
    node_ptr = node_ptr->next;
    return tmp;
}

/**
 * @brief Prefix decrement operator for const iterator, moving it to the previous node.
 * 
 * This operator moves the const iterator to the previous node in the list, without modifying the data.
 * 
 * @return A reference to the updated iterator.
 */
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

/**
 * @brief Postfix decrement operator for const iterator, returning a copy of the iterator before moving it to the previous node.
 * 
 * This operator allows the const iterator to move to the previous node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was decremented.
 */
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int) {
    typename List<T>::const_iterator tmp = *this;
    node_ptr = node_ptr->prev;
    return tmp;
}

/**
 * @brief Equality comparison operator for const iterators, checking if two iterators point to the same node.
 * 
 * This operator returns true if the two const iterators point to the same node, otherwise false.
 * 
 * @param other The iterator to compare against.
 * @return true if the iterators are equal, false otherwise.
 */
template <typename T>
bool List<T>::const_iterator::operator==(const typename List<T>::const_iterator& other) const {
    return node_ptr == other.node_ptr;
}

/**
 * @brief Inequality comparison operator for const iterators, checking if two iterators point to different nodes.
 * 
 * This operator returns true if the two const iterators do not point to the same node, otherwise false.
 * 
 * @param other The iterator to compare against.
 * @return true if the iterators are not equal, false otherwise.
 */
template <typename T>
bool List<T>::const_iterator::operator!=(const typename List<T>::const_iterator& other) const {
    return node_ptr != other.node_ptr;
}

/**
 * @brief Constructor for reverse iterator, initializing it with a node pointer.
 * 
 * This constructor initializes the reverse iterator to point to the specified node.
 * 
 * @param ptr A pointer to the node the reverse iterator will reference.
 */
template <typename T>
List<T>::reverse_iterator::reverse_iterator(Node* ptr) : node_ptr(ptr) { }

/**
 * @brief Dereference operator for reverse iterator, returning a reference to the node's data.
 * 
 * This operator allows the reverse iterator to access the data in the node it is pointing to.
 * 
 * @return A reference to the data stored in the current node.
 */
template <typename T>
typename List<T>::reverse_iterator::reference List<T>::reverse_iterator::operator*() { 
    return node_ptr->data;
}

/**
 * @brief Arrow operator for reverse iterator, returning a pointer to the node's data.
 * 
 * This operator provides access to the data in the current node through pointer dereferencing.
 * 
 * @return A pointer to the data stored in the current node.
 */
template <typename T>
typename List<T>::reverse_iterator::pointer List<T>::reverse_iterator::operator->() {
    return &node_ptr->data;
}

/**
 * @brief Prefix increment operator for reverse iterator, moving it to the previous node.
 * 
 * This operator advances the reverse iterator to the previous node in the list.
 * 
 * @return A reference to the updated reverse iterator.
 */
template <typename T>
typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator++() {
    node_ptr = node_ptr->prev;
    return *this;
}

/**
 * @brief Postfix increment operator for reverse iterator, returning a copy of the iterator before moving it to the previous node.
 * 
 * This operator allows the reverse iterator to move to the previous node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was incremented.
 */
template <typename T>
typename List<T>::reverse_iterator List<T>::reverse_iterator::operator++(int) {
    reverse_iterator tmp = *this;
    node_ptr = node_ptr->prev;
    return tmp;
}

/**
 * @brief Prefix decrement operator for reverse iterator, moving it to the next node.
 * 
 * This operator moves the reverse iterator to the next node in the list.
 * 
 * @return A reference to the updated reverse iterator.
 */
template <typename T>
typename List<T>::reverse_iterator& List<T>::reverse_iterator::operator--() {
    node_ptr = node_ptr->next;
    return *this;
}

/**
 * @brief Postfix decrement operator for reverse iterator, returning a copy of the iterator before moving it to the next node.
 * 
 * This operator allows the reverse iterator to move to the next node after returning the original iterator.
 * 
 * @return A copy of the iterator before it was decremented.
 */
template <typename T>
typename List<T>::reverse_iterator List<T>::reverse_iterator::operator--(int) {
    reverse_iterator tmp = *this;
    node_ptr = node_ptr->next;
    return tmp;
}

/**
 * @brief Equality comparison operator for reverse iterators, checking if two iterators point to the same node.
 * 
 * This operator returns true if the two reverse iterators point to the same node, otherwise false.
 * 
 * @param other The reverse iterator to compare against.
 * @return true if the iterators are equal, false otherwise.
 */
template <typename T>
bool List<T>::reverse_iterator::operator==(const reverse_iterator& other) const {
    return node_ptr == other.node_ptr;
}

/**
 * @brief Inequality comparison operator for reverse iterators, checking if two iterators point to different nodes.
 * 
 * This operator returns true if the two reverse iterators do not point to the same node, otherwise false.
 * 
 * @param other The reverse iterator to compare against.
 * @return true if the iterators are not equal, false otherwise.
 */
template <typename T>
bool List<T>::reverse_iterator::operator!=(const reverse_iterator& other) const {
    return node_ptr != other.node_ptr;
}

/**
 * @brief Constructs an empty list.
 * 
 * This constructor initializes the list with no elements. Both `head` and `tail` are set to `nullptr`, 
 * and the size of the list is set to zero.
 */
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) { }

/**
 * @brief Destroys the list and frees all allocated memory.
 * 
 * This destructor clears all elements from the list by calling `clear()`, ensuring that all dynamically
 * allocated memory is properly released when the list is destroyed.
 */
template <typename T>
List<T>::~List() {
    clear();
}


/**
 * @brief Move assignment operator for the List class, transferring ownership from another List.
 * 
 * This operator moves the data from the given `other` list to the current list and clears the `other`.
 * It ensures no self-assignment occurs and avoids unnecessary allocations.
 * 
 * @param other The List object to move data from.
 * @return A reference to the current List object after the move.
 */
template <typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        size = other.size;

        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }
    return *this;
}

/**
 * @brief Copy assignment operator for the List class, copying elements from another List.
 * 
 * This operator clears the current list and copies elements from the given `other` list.
 * It prevents self-assignment and performs a deep copy of the elements.
 * 
 * @param other The List object to copy from.
 * @return A reference to the current List object after the copy.
 */
template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) {
        clear();
        for (Node* current = other.head; current; current = current->next) {
            push_back(current->data);
        }
    }
    return *this;
}

/**
 * @brief Assignment operator for the List class using an initializer list.
 * 
 * This operator clears the current list and initializes it using the elements in the provided initializer list.
 * 
 * @param list The initializer list to assign to the current List.
 * @return A reference to the current List object after the assignment.
 */
template <typename T>
List<T>& List<T>::operator=(std::initializer_list<typename List<T>::value_type> list) {
    clear();
    for (const auto& elem : list) {
        push_back(elem);
    }
    return *this;
}

/**
 * @brief Assigns multiple instances of a value to the list.
 * 
 * This function clears the current list and then adds `count` instances of `value` to the list.
 * 
 * @param count The number of times to add `value` to the list.
 * @param value The value to be inserted into the list.
 */
template <typename T>
void List<T>::assign(typename List<T>::size_type count, const T& value) {
    clear();
    for (typename List<T>::size_type i = 0; i < count; ++i) {
        push_back(value);
    }
}

/**
 * @brief Assigns elements from an input iterator range to the list.
 * 
 * This function clears the current list and then copies elements from the iterator range `[first, last)` to the list.
 * 
 * @param first The starting iterator of the range.
 * @param last The ending iterator of the range.
 */
template <typename T>
template<class InputIt>
void List<T>::assign(InputIt first, InputIt last) {
    clear();
    while (first != last) {
        push_back(*first++);
    }
}

/**
 * @brief Assigns elements from an initializer list to the list.
 * 
 * This function clears the current list and assigns the elements from the provided initializer list to the list.
 * 
 * @param ilist The initializer list to assign to the current list.
 */
template <typename T>
void List<T>::assign(std::initializer_list<typename List<T>::value_type> ilist) {
    clear();
    for (const auto& elem : ilist) {
        push_back(elem);
    }
}

/**
 * @brief Accessor to the front element of the list.
 * 
 * This function returns the reference to the front element of the list.
 * If the list is empty, an exception is thrown.
 * 
 * @return A reference to the front element.
 * @throw std::out_of_range if the list is empty.
 */
template <typename T>
typename List<T>::reference List<T>::front() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

/**
 * @brief Const accessor to the front element of the list.
 * 
 * This function returns a const reference to the front element of the list.
 * If the list is empty, an exception is thrown.
 * 
 * @return A const reference to the front element.
 * @throw std::out_of_range if the list is empty.
 */
template <typename T>
typename List<T>::const_reference List<T>::front() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

/**
 * @brief Accessor to the back element of the list.
 * 
 * This function returns the reference to the back element of the list.
 * If the list is empty, an exception is thrown.
 * 
 * @return A reference to the back element.
 * @throw std::out_of_range if the list is empty.
 */
template <typename T>
typename List<T>::reference List<T>::back() {
    if (!tail) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

/**
 * @brief Const accessor to the back element of the list.
 * 
 * This function returns a const reference to the back element of the list.
 * If the list is empty, an exception is thrown.
 * 
 * @return A const reference to the back element.
 * @throw std::out_of_range if the list is empty.
 */
template <typename T>
typename List<T>::const_reference List<T>::back() const {
    if (!tail) {
        throw std::out_of_range("List is empty");
    }
    return tail->data;
}

/**
 * @brief Clears the list, deleting all nodes.
 * 
 * This function deallocates all the nodes in the list, effectively making it empty.
 */
template <typename T>
void List<T>::clear() {
    Node* current = head;
    while (current) {
        Node* tmp = current->next;
        delete current;
        current = tmp;
    }
    head = tail = nullptr;
    size = 0;
}

/**
 * @brief Adds an element to the back of the list.
 * 
 * This function creates a new node with the provided value and appends it to the end of the list.
 * 
 * @param value The value to add to the list.
 */
template <typename T>
void List<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    ++size;
}

/**
 * @brief Inserts a value before the given iterator position in the list.
 * 
 * This function inserts a new node with the provided value at the specified position, shifting other elements accordingly.
 * 
 * @param pos The iterator position where the new node should be inserted.
 * @param value The value to insert.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::const_iterator pos, const T& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(value);
    typename List<T>::Node* current = pos.node_ptr;
    if (!current) {
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    else {
        if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    ++size;
    return typename List<T>::iterator(new_node);
}

/**
 * @brief Inserts a rvalue before the given iterator position in the list.
 * 
 * This function inserts a new node with the provided rvalue at the specified position.
 * 
 * @param pos The iterator position where the new node should be inserted.
 * @param value The rvalue to insert.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::const_iterator pos, T&& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::move(value));
    typename List<T>::Node* current = pos.node_ptr;
    if (!current) {
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    else {
        if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    ++size;
    return typename List<T>::iterator(new_node);
}

/**
 * @brief Inserts multiple copies of a value before the given iterator position in the list.
 * 
 * This function inserts `count` copies of `value` before the specified iterator position.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param count The number of times to insert `value`.
 * @param value The value to insert.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::const_iterator pos, typename List<T>::size_type count, const T& value) {
    typename List<T>::iterator iter = iterator(pos);
    for (typename List<T>::size_type i = 0; i < count; ++i) {
        iter = insert(iter, value);
    }
    return iter;
}

/**
 * @brief Inserts multiple copies of an rvalue before the given iterator position in the list.
 * 
 * This function inserts `count` copies of the rvalue before the specified iterator position.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param count The number of times to insert the rvalue.
 * @param value The rvalue to insert.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, typename List<T>::size_type count, T&& value) {
    typename List<T>::iterator iter = iterator(pos);
    for (typename List<T>::size_type i = 0; i < count; ++i) {
        iter = insert(iter, std::move(value));
    }
    return iter;
}

/**
 * @brief Inserts multiple copies of a value before the given iterator position in the list.
 * 
 * This function inserts `count` copies of `value` before the specified iterator position.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param count The number of times to insert `value`.
 * @param value The value to insert.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, typename List<T>::size_type count, T& value) {
    typename List<T>::iterator iter = iterator(pos);
    for (typename List<T>::size_type i = 0; i < count; ++i) {
        iter = insert(iter, value);
    }
    return iter;
}


/**
 * @brief Inserts a value before the specified iterator position in the list.
 * 
 * This function creates a new node with the provided value and inserts it at the position specified
 * by the iterator. If the position is null (end of the list), the new node is added to the end.
 * 
 * @param pos The iterator position where the new node should be inserted.
 * @param value The value to insert into the list.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, T& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(value);
    typename List<T>::Node* current = pos.node_ptr;

    if (!current) {
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    else {
        if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    ++size;
    return typename List<T>::iterator(new_node);
}

/**
 * @brief Inserts an r-value before the specified iterator position in the list.
 * 
 * This function creates a new node with the provided r-value reference (value) and inserts it at the 
 * position specified by the iterator. If the position is null (end of the list), the new node is 
 * added to the end.
 * 
 * @param pos The iterator position where the new node should be inserted.
 * @param value The r-value to insert into the list.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, T&& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::move(value));
    typename List<T>::Node* current = pos.node_ptr;

    if (!current) {
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    else {
        if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    ++size;
    return typename List<T>::iterator(new_node);
}

/**
 * @brief Inserts a range of elements before the specified iterator position in the list.
 * 
 * This function inserts elements in the range [first, last) before the given position in the list.
 * Each element from the range is inserted one by one.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param first The beginning iterator of the range to insert.
 * @param last The ending iterator of the range to insert.
 * @return An iterator pointing to the last inserted node.
 */
template <typename T>
template<class InputIt>
typename List<T>::iterator List<T>::insert(typename List<T>::const_iterator pos, InputIt first, InputIt last) {
    typename List<T>::iterator iter = pos;
    while (first != last) {
        iter = insert(iter, *first);
        ++first;
    }
    return iter;
}

/**
 * @brief Inserts a range of elements before the specified iterator position in the list.
 * 
 * This function inserts elements in the range [first, last) before the given position in the list.
 * Each element from the range is inserted one by one, using an iterator.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param first The beginning iterator of the range to insert.
 * @param last The ending iterator of the range to insert.
 * @return An iterator pointing to the last inserted node.
 */
template <typename T>
template<class InputIt>
typename List<T>::iterator List<T>::insert(typename List<T>::iterator pos, InputIt first, InputIt last) {
    typename List<T>::iterator iter = pos;
    while (first != last) {
        iter = insert(iter, *first);
        ++first;
    }
    return iter;
}

/**
 * @brief Inserts an initializer list before the specified iterator position in the list.
 * 
 * This function inserts the elements from the initializer list before the given position in the list.
 * 
 * @param pos The iterator position where the new nodes should be inserted.
 * @param ilist The initializer list containing the elements to insert.
 * @return An iterator pointing to the last inserted node.
 */
template <typename T>
typename List<T>::iterator List<T>::insert(typename List<T>::const_iterator pos, std::initializer_list<T> ilist) {
    return insert(pos, ilist.begin(), ilist.end());
}

/**
 * @brief Constructs and inserts an element in-place before the given iterator position in the list.
 * 
 * This function uses the perfect forwarding of arguments to construct a new element in place at 
 * the specified position in the list.
 * 
 * @param pos The iterator position where the new node should be inserted.
 * @param args The arguments to construct the new element in-place.
 * @return An iterator pointing to the newly inserted node.
 */
template <typename T>
template<typename... Args>
typename List<T>::iterator List<T>::emplace(typename List<T>::const_iterator pos, Args&&... args) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::forward<Args>(args)...);
    typename List<T>::Node* current = pos.node_ptr;

    if (!current) {
        if (!head) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
    else {
        if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
        }
    }
    ++size;
    return typename List<T>::iterator(new_node);
}

/**
 * @brief Removes the element at the specified iterator position from the list.
 * 
 * This function deletes the node at the position specified by the iterator and adjusts the list 
 * accordingly.
 * 
 * @param pos The iterator position to remove.
 * @return An iterator pointing to the next node after the removed element.
 */
template <typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator pos) {
    typename List<T>::Node* current = pos.node_ptr;
    if (!current) {
        return end();
    }
    typename List<T>::Node* next_node = current->next;

    if (current == head) {
        head = current->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
    }
    else if (current == tail) {
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    --size;

    return typename List<T>::iterator(next_node);
}

/**
 * @brief Removes the element at the specified constant iterator position from the list.
 * 
 * This function removes the element at the position specified by a constant iterator and adjusts 
 * the list accordingly.
 * 
 * @param pos The constant iterator position to remove.
 * @return An iterator pointing to the next node after the removed element.
 */
template <typename T>
typename List<T>::iterator List<T>::erase(const_iterator pos) {
    return erase(typename List<T>::iterator(const_cast<typename List<T>::Node*>(pos.node_ptr)));
}

/**
 * @brief Removes elements in the range [first, last) from the list.
 * 
 * This function removes nodes from the list, starting from the iterator 'first' up to (but not including)
 * the iterator 'last'.
 * 
 * @param first The starting iterator of the range to remove.
 * @param last The ending iterator of the range to remove.
 * @return An iterator pointing to the position after the last removed element.
 */
template <typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator first, typename List<T>::iterator last) {
    while (first != last) {
        first = erase(first);
    }
    return last;
}

/**
 * @brief Removes elements in the range [first, last) from the list using constant iterators.
 * 
 * This function removes nodes from the list, starting from the constant iterator 'first' up to (but not 
 * including) the constant iterator 'last'.
 * 
 * @param first The starting constant iterator of the range to remove.
 * @param last The ending constant iterator of the range to remove.
 * @return An iterator pointing to the position after the last removed element.
 */
template <typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::const_iterator first, typename List<T>::const_iterator last) {
    while (first != last) {
        first = erase(typename List<T>::iterator(const_cast<typename List<T>::Node*>(first.node_ptr)));
    }
    return last;
}

/**
 * @brief Constructs and appends a new element to the end of the list.
 * 
 * This function constructs a new node in-place at the end of the list using the provided arguments 
 * and appends it to the list. It handles perfect forwarding of arguments.
 * 
 * @param args The arguments to construct the new element.
 * @return A reference to the data of the newly appended node.
 */
template <typename T>
template<typename... Args>
typename List<T>::reference List<T>::emplace_back(Args&&... args) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::forward<Args>(args)...);
    if (!tail) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    ++size;
    return new_node->data;
}

/**
 * @brief Appends a range of elements to the end of the list.
 * 
 * This function appends the elements from the provided range (using `std::ranges::range`) 
 * to the end of the list by calling `emplace_back` for each element.
 * 
 * @param rg The range of elements to append.
 */
template <typename T>
template<std::ranges::range R>
void List<T>::append_range(R&& rg) {
    for (auto&& elem : rg) {
        emplace_back(std::forward<decltype(elem)>(elem));
    }
}

/**
 * @brief Removes the last element from the list.
 * 
 * This function removes the last node from the list and adjusts the list accordingly. 
 * If the list becomes empty, both head and tail are set to null.
 */
template <typename T>
void List<T>::pop_back() {
    if (!head) {
        return; 
    }

    typename List<T>::Node* temp = tail;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr; 
    }

    delete temp;
    --size;
}

/**
 * @brief Adds an element to the front of the list.
 * 
 * This function inserts a new node at the front of the list with the provided value.
 * 
 * @param value The value to insert at the front of the list.
 */
template <typename T>
void List<T>::push_front(const T& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(value);
    if (!head) {
        head = tail = new_node;
    }
    else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    ++size;
}

/**
 * @brief Adds an r-value element to the front of the list.
 * 
 * This function inserts a new node at the front of the list with the provided r-value (move semantics).
 * 
 * @param value The r-value to insert at the front of the list.
 */
template <typename T>
void List<T>::push_front(T&& value) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::move(value));
    if (!head) {
        head = tail = new_node;
    }
    else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    ++size;
}

/**
 * @brief Prepends a range of elements to the front of the list.
 * 
 * This function prepends the elements from the provided range (using `std::ranges::range`) 
 * to the front of the list by calling `emplace_front` for each element in reverse order.
 * 
 * @param rg The range of elements to prepend.
 */
template <typename T>
template<std::ranges::range R>
void List<T>::prepend_range(R&& rg) {
    for (auto it = std::rbegin(rg); it != std::rend(rg); ++it) {
        emplace_front(*it);
    } 
}

/**
 * @brief Constructs and prepends a new element to the front of the list.
 * 
 * This function constructs a new node in-place at the front of the list using the provided arguments 
 * and prepends it to the list. It handles perfect forwarding of arguments.
 * 
 * @param args The arguments to construct the new element.
 * @return A reference to the data of the newly prepended node.
 */
template <typename T>
template<typename... Args>
typename List<T>::reference List<T>::emplace_front(Args&&... args) {
    typename List<T>::Node* new_node = new typename List<T>::Node(std::forward<Args>(args)...);
    if (!head) {
        head = tail = new_node;
    }
    else {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    ++size;
    return new_node->data;
}

/**
 * @brief Removes the first element from the list.
 * 
 * This function removes the first node from the list and adjusts the list accordingly. 
 * If the list becomes empty, both head and tail are set to null.
 */
template <typename T>
void List<T>::pop_front() {
    if (!head) {
        return; 
    }

    typename List<T>::Node* temp = head;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr; 
    }

    delete temp;
    --size;
}

/**
 * @brief Resizes the list to the specified size.
 * 
 * This function adjusts the list size to match the specified count. If the list needs to shrink, 
 * elements are removed from the back. If the list needs to grow, default-constructed elements are appended.
 * 
 * @param count The new size of the list.
 */
template <typename T>
void List<T>::resize(size_type count) {
    if (count < size) {
        while (size > count) {
            pop_back();
        }
    }
    else if (count > size) {
        while (size < count) {
            emplace_back();
        }
    }
}


/**
 * @brief Resizes the list to the specified size, filling with a default value if expanding.
 * 
 * This function adjusts the list size to match the specified count. If the list needs to shrink, 
 * elements are removed from the back. If the list needs to grow, the specified `value` is appended 
 * to the list until it reaches the desired size.
 * 
 * @param count The new size of the list.
 * @param value The value to append when expanding the list.
 */
template <typename T>
void List<T>::resize(typename List<T>::size_type count, const typename List<T>::value_type& value) {
    if (count < size) {
        while (size > count) {
            pop_back();
        }
    }
    else if (count > size) {
        while (size < count) {
            emplace_back(value);
        }
    }
}

/**
 * @brief Swaps the contents of the list with another list.
 * 
 * This function swaps the contents (head, tail, and size) of the current list with another list.
 * It provides a fast way to exchange the contents of two lists.
 * 
 * @param other The other list whose contents will be swapped with this list.
 */
template <typename T>
void List<T>::swap(List<T>& other) {
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(size, other.size);
}

/**
 * @brief Returns an iterator pointing to the first element in the list.
 * 
 * This function provides an iterator that can be used to traverse the list from the beginning.
 * 
 * @return An iterator pointing to the first element in the list.
 */
template <typename T>
typename List<T>::iterator List<T>::begin() {
    return typename List<T>::iterator(head);
}

/**
 * @brief Returns an iterator pointing past the last element in the list.
 * 
 * This function provides an iterator that marks the end of the list, which is used for traversal.
 * 
 * @return An iterator pointing past the last element in the list (i.e., `nullptr`).
 */
template <typename T>
typename List<T>::iterator List<T>::end() {
    return typename List<T>::iterator(nullptr);
}

/**
 * @brief Returns a constant iterator pointing to the first element in the list.
 * 
 * This function provides a constant iterator to allow read-only access to the list's elements 
 * from the beginning.
 * 
 * @return A constant iterator pointing to the first element in the list.
 */
template <typename T>
typename List<T>::const_iterator List<T>::cbegin() const {
    return typename List<T>::const_iterator(head);
}

/**
 * @brief Returns a constant iterator pointing past the last element in the list.
 * 
 * This function provides a constant iterator that marks the end of the list for read-only access.
 * 
 * @return A constant iterator pointing past the last element in the list (i.e., `nullptr`).
 */
template <typename T>
typename List<T>::const_iterator List<T>::cend() const {
    return typename List<T>::const_iterator(nullptr);
}

/**
 * @brief Returns a constant reverse iterator pointing to the last element in the list.
 * 
 * This function provides a constant reverse iterator for read-only access to the list's elements 
 * starting from the last element.
 * 
 * @return A constant reverse iterator pointing to the last element in the list.
 */
template <typename T>
typename List<T>::const_reverse_iterator List<T>::rbegin() const {
    return typename List<T>::reverse_iterator(tail); 
}

/**
 * @brief Returns a constant reverse iterator pointing before the first element in the list.
 * 
 * This function provides a constant reverse iterator that marks the end of the reverse traversal.
 * 
 * @return A constant reverse iterator pointing past the first element in the list (i.e., `nullptr`).
 */
template <typename T>
typename List<T>::const_reverse_iterator List<T>::rend() const {
    return typename List<T>::reverse_iterator(nullptr); 
}

/**
 * @brief Returns a reverse iterator pointing to the last element in the list.
 * 
 * This function provides a reverse iterator to traverse the list from the end to the beginning.
 * 
 * @return A reverse iterator pointing to the last element in the list.
 */
template <typename T>
typename List<T>::reverse_iterator List<T>::rbegin() {
    return typename List<T>::reverse_iterator(tail); 
}

/**
 * @brief Returns a reverse iterator pointing before the first element in the list.
 * 
 * This function provides a reverse iterator that marks the end of the reverse traversal.
 * 
 * @return A reverse iterator pointing past the first element in the list (i.e., `nullptr`).
 */
template <typename T>
typename List<T>::reverse_iterator List<T>::rend() {
    return typename List<T>::reverse_iterator(nullptr);   
}

/**
 * @brief Returns the size of the list.
 * 
 * This function returns the number of elements in the list.
 * 
 * @return The size of the list.
 */
template <typename T>
typename List<T>::size_type List<T>::getSize() const {
    return size;
}

/**
 * @brief Checks whether the list is empty.
 * 
 * This function checks if the list contains any elements by comparing the `begin` and `end` iterators.
 * 
 * @return `true` if the list is empty, `false` otherwise.
 */
template <typename T>
bool List<T>::empty() {
    return begin() == end();
}
