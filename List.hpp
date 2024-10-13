#ifndef C188899E_0C33_4B0A_92C3_89E0D3865046
#define C188899E_0C33_4B0A_92C3_89E0D3865046

#include <iostream>

class List {
    struct Node {
        int value;
        Node* prev;
        Node* next;

        Node(int a = 0);

        Node(int a, Node* b);

        friend std::ostream& operator<<(std::ostream& stream, const List::Node* node);
    };

    private:
    Node* head;
    Node* tail;
    int counter;

    public:
    /// @brief Domyślny konstruktor klasy List.
    List();

    /// @brief Destruktor klasy List.
    ~List();
    void push_back(int i);
    void push_front(int i);
    void insert_at(int value, int index);
    void remove_first();
    void remove_last();
    void remove_at(int index);
    void purge();

    friend std::ostream& operator<<(std::ostream& stream, const List::Node* node);
};

#endif /* C188899E_0C33_4B0A_92C3_89E0D3865046 */
