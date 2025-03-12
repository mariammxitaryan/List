```markdown
# List Class Implementation in C++

## Overview

This project provides a custom implementation of a **Doubly Linked List** in C++. The class `List<T>` supports a wide range of operations commonly associated with linked lists, such as adding, removing, and accessing elements, as well as a few advanced features such as range insertion, emplacing elements at both ends, and more.

The primary goal of this implementation is to demonstrate the versatility and flexibility of C++ while providing the user with a well-structured and intuitive linked list container. This implementation can be used as a foundation for further customizations or as a learning tool for understanding linked list operations.

## Key Features

- **Insert Elements**: Insert elements at various positions within the list, such as the front, back, or specific iterator positions.
- **Range Operations**: Append or prepend entire ranges (e.g., from `std::ranges::range` or other containers).
- **Element Removal**: Remove elements from the front or back of the list.
- **Efficient Resize**: Resize the list to a specified size, filling with a default value if necessary.
- **Iterator Support**: Full iterator support for both const and non-const iterators, as well as reverse iteration.
- **Memory Management**: Automatic memory management, with elements dynamically allocated and deallocated when necessary.

## Installation

To use the `List<T>` class in your project, simply include the header file `List.hpp` and link to the implementation in your build system.

```bash
# Clone the repository

# Or download the List.hpp and List.cpp files and add them to your project
```

## Example Usage

Here is an example of how to use the `List<T>` class in your C++ program:

```cpp
#include "List.hpp"

int main() {
    // Create a list of integers
    List<int> myList;

    // Emplace elements at the back of the list
    myList.emplace_back(10);
    myList.emplace_back(20);

    // Emplace elements at the front of the list
    myList.emplace_front(5);

    // Pop an element from the back
    myList.pop_back();

    // Resize the list to a specific size
    myList.resize(5, 0);  // Fill the list with zeros

    // Iterate through the list and print elements
    for (auto& elem : myList) {
        std::cout << elem << " ";
    }

    return 0;
}
```

## Functions Supported

### Insertion and Emplacement
- `emplace_back(...)`: Adds an element to the back of the list.
- `emplace_front(...)`: Adds an element to the front of the list.
- `insert(...)`: Inserts one or more copies of a value at a specific position.
- `append_range(...)`: Appends elements from a range (e.g., from another container or array).
- `prepend_range(...)`: Prepends elements from a range.

### Removal
- `pop_back()`: Removes the last element of the list.
- `pop_front()`: Removes the first element of the list.

### Resizing and Swapping
- `resize(...)`: Resizes the list to the given size, optionally filling with a specified value.
- `swap(...)`: Swaps the contents of the list with another list.

### Iteration
- `begin()`, `end()`: Get iterators to the first and past-the-last elements.
- `rbegin()`, `rend()`: Get reverse iterators to the last and before-first elements.
- `cbegin()`, `cend()`: Const iterators for read-only access.

### Utility
- `getSize()`: Returns the number of elements in the list.
- `empty()`: Checks if the list is empty.

```
