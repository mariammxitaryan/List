#include "listHeader.hpp"
#include <list>

int main() {
    List<int> lst;

    // Using push_back and emplace_back
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    lst.emplace_back(40);
    lst.emplace_back(50);

    // Printing front and back elements
    std::cout << "Front element: " << lst.front() << std::endl;
    std::cout << "Back element: " << lst.back() << std::endl;

    // Iterating over the list using iterator
    std::cout << "List contents using iterator: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Inserting element using insert
    auto it = lst.begin();
    lst.insert(it, 5);
    std::cout << "After insert at the beginning: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Inserting multiple elements using insert with size
    lst.insert(lst.begin(), (List<int>::size_type)2, 15);
    std::cout << "After inserting 15 twice at the beginning: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Erasing elements using erase
    lst.erase(lst.begin());
    std::cout << "After erasing first element: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Erasing elements using erase by range
    it = lst.begin();
    lst.erase(it, lst.end());
    std::cout << "After erasing all elements: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Pushing elements back again
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // Using resize
    lst.resize(5, 99);
    std::cout << "After resizing to 5 elements, with default value 99: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using pop_back and pop_front
    lst.pop_back();
    lst.pop_front();
    std::cout << "After popping back and front: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using reverse_iterator and const_reverse_iterator
    std::cout << "List contents using reverse_iterator: ";
    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using append_range (assuming you've defined it correctly)
    std::vector<int> vec = {1, 2, 3};
    lst.append_range(vec);
    std::cout << "After appending range: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using prepend_range (assuming you've defined it correctly)
    std::list<int> prepend_list{4, 5, 6};
    lst.prepend_range(prepend_list);
    std::cout << "After prepending range: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using emplace_front with variadic template arguments
    lst.emplace_front(100);
    std::cout << "After emplacing front: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using emplace_back with variadic template arguments
    lst.emplace_back(200);
    std::cout << "After emplacing back: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using swap
    List<int> another_lst;
    another_lst.push_back(999);
    another_lst.push_back(888);

    lst.swap(another_lst);
    std::cout << "After swap: ";
    std::cout << "lst: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    std::cout << "another_lst: ";
    for (auto it = another_lst.begin(); it != another_lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using clear
    lst.clear();
    std::cout << "After clear, lst is empty: " << lst.getSize() << " elements." << std::endl;

    return 0;
}
