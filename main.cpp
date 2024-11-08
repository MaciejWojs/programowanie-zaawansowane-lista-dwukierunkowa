#include <iostream>
#include "List.hpp"

int main() {
    List e;

    // Dodajemy 30 elementów na początek listy
    for (int i = 0; i < 30; i++) {
        e.push_front(i);
    }
    std::cout << "Po dodaniu 30 elementów na początek (push_front):\n";
    e.display();

    // Dodajemy element na końcu listy
    e.push_back(1000);
    std::cout << "\nPo dodaniu elementu 1000 na koniec (push_back):\n";
    e.display();

    // Wstawiamy element na indeksie 0
    e.insert_at(5000, 0);
    std::cout << "\nPo wstawieniu elementu 5000 na początku (insert_at na indeks 0):\n";
    e.display();

    // Usuwamy pierwszy element
    e.remove_first();
    std::cout << "\nPo usunięciu pierwszego elementu (remove_first):\n";
    e.display();

    // Usuwamy ostatni element
    e.remove_last();
    std::cout << "\nPo usunięciu ostatniego elementu (remove_last):\n";
    e.display();

    // Oczyszczenie całej listy
    e.purge();
    std::cout << "\nPo wyczyszczeniu listy (purge):\n";
    e.display();

    // Dodajemy ponownie 30 elementów na początek listy
    for (int i = 0; i < 30; i++) {
        e.push_front(i);
    }
    std::cout << "\nPo ponownym dodaniu 30 elementów na początek (push_front):\n";
    e.display();

    return 0;


    //Dopisanie z drugiej lokalizacji
}