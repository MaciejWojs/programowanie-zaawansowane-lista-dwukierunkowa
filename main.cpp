#include <iostream>
#include "List.hpp"

int main() {
    List e;
    for (int i = 0; i < 30; i++) {
        e.push_front(i);
    }
    std::cout << e;
    e.display_reversed();
}