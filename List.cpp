#include "List.hpp"

List::Node::Node(int a) : value(a), prev(nullptr), next(nullptr) {}
List::Node::Node(int a, Node* b) : value(a), prev(b), next(nullptr) {}
std::ostream& operator<<(std::ostream& stream, const List::Node* node) {
    stream << node->value;
    return stream;
}

List::List() : head(nullptr), tail(nullptr), counter(0) {}

List::~List() {
    purge()
}

void List::push_back(int i) {
    if (head == nullptr) {
        head = new Node(i);
        tail = head;
    } else {
        tail->next = new Node(i, tail);
        tail = tail->next;
    }

    ++counter;
}
void List::push_front(int i) {
    if (head == nullptr) {
        head = new Node(i);
        tail = head;
    } else {
        // tail->next = new Node(i, tail);
        // tail = tail->next;
        Node* temp = head;
        head->prev = new Node(i);
        head = head->prev;
        head->next = temp;
    }

    ++counter;
}

void List::insert_at(int value, int index) {
    std::cout << "counter: " << counter << '\n';
    if (index < 0) {
        std::cout << "Index cant be negative";
        exit(0);
    } else if (index == 0) {
        push_front(value);
    } else if (index == counter) {
        push_back(value);
    } else {
        if (index > counter) {
            std::cout << "Can't insert value at this index: " << index << '\n';
            return;
        }

        Node* current = head;
        for (int i = 0; i <= index - 1; i++) {
            current = current->next;
        }

        // std::cout << "current: " << current->value << " at index: " << index << '\n';
        Node* temp = current;
        Node* temp_prev = current->prev;

        current = new Node(value);
        temp_prev->next = current;
        current->prev = temp_prev;
        current->next = temp;


        ++counter;
    }
}

void List::remove_first() {
    if (head == nullptr) {
        std::cout << "Cant remove first element from empty list!\n";
        exit(0);
    }

    if (counter > 1) {
        Node* temp = head->next;
        delete head;
        head = temp;
        head->prev = nullptr;
        if (counter == 2) {
            head = tail;
        }
    } else if (counter == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    --counter;
}

void List::remove_last() {
    if (tail == nullptr) {
        std::cout << "Cant remove last element from empty list!\n";
        exit(0);
    }

    if (counter > 2) {
        Node* temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
    } else if (counter == 2) {
        Node* temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        head = tail;
    } else if (counter == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    --counter;
}

void List::purge() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    counter = 0;
}

void List::remove_at(int index) {
    if (index < 0) {
        std::cout << "Index cant be negative\n";
        return;
    }

    if (index > counter - 1) {
        std::cout << "Index out of bound\n";
        return;
    }

    if (index == 0) {
        remove_first();
    } else if (index == counter - 1) {
        remove_last();
    } else {

        Node* current = head;
        for (int i = 0; i <= index - 1; i++) {
            current = current->next;
        }

        std::cout << current->value << '\n';
        Node* temp_prev = current->prev;
        Node* temp_next = current->next;

        delete current;
        temp_prev->next = temp_next;
        temp_next->prev = temp_prev;

    }
    --counter;
}

void List::purge() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    counter = 0;
}

void List::display() const {
    std::cout << *this << '\n';
}

void List::display_reversed() const {
    if (tail != nullptr) {
        Node* current = tail;
        while (current->prev != nullptr) {
            std::cout << current << ", ";
            current = current->prev;
        }
        std::cout << current << '\n';
    }
}

void List::display_next(int index) const {
    if (index < 0) {
        std::cout << "Index cant be negative\n";
        return;
    }

    if (index > counter - 1) {
        std::cout << "Index out of bound\n";
        return;
    }

    if (counter - 2 >= index) {
        std::cout << (*this)[index + 1] << '\n';
    } else if (counter - 1 == index) {
        std::cout << "There isn't a next element\n";
    }
}

void List::display_previous(int index) const {
    if (index < 0) {
        std::cout << "Index cant be negative\n";
        return;
    }

    if (index > counter - 1) {
        std::cout << "Index out of bound\n";
        return;
    }

    if (index < 1) {
        std::cout << "There isn't a next element\n";
    } else {
        std::cout << (*this)[index - 1] << '\n';
    }

}