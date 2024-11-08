#include <iostream>
#include "List.hpp"

int main() {
    List e;

    // Test metody push_front
    for (int i = 0; i < 5; i++) {
        e.push_front(i);
    }
    std::cout << "Po dodaniu 5 elementów na początek (push_front):\n";
    e.display();

    // Test metody push_back
    e.push_back(100);
    std::cout << "\nPo dodaniu elementu 100 na koniec (push_back):\n";
    e.display();

    // Test metody insert_at (wstawienie na początek)
    e.insert_at(500, 0);
    std::cout << "\nPo wstawieniu elementu 500 na indeks 0 (insert_at):\n";
    e.display();

    // Test metody insert_at (wstawienie w środku)
    e.insert_at(250, 3);
    std::cout << "\nPo wstawieniu elementu 250 na indeks 3 (insert_at):\n";
    e.display();

    // Test metody remove_first
    e.remove_first();
    std::cout << "\nPo usunięciu pierwszego elementu (remove_first):\n";
    e.display();

    // Test metody remove_last
    e.remove_last();
    std::cout << "\nPo usunięciu ostatniego elementu (remove_last):\n";
    e.display();

    // Test metody remove_at (usunięcie elementu z określonego indeksu)
    e.remove_at(2);
    std::cout << "\nPo usunięciu elementu na indeksie 2 (remove_at):\n";
    e.display();

    // Test metody display_reversed
    std::cout << "\nWyświetlanie listy w odwrotnej kolejności (display_reversed):\n";
    e.display_reversed();

    // Test metody display_next (wyświetlenie kolejnych elementów od danego indeksu)
    std::cout << "\nWyświetlanie elementów zaczynając od indeksu 1 (display_next):\n";
    e.display_next(1);

    // Test metody display_previous (wyświetlenie poprzednich elementów od danego indeksu)
    std::cout << "\nWyświetlanie elementów wstecz zaczynając od indeksu 3 (display_previous):\n";
    e.display_previous(3);

    // Test operatora []
    std::cout << "\nDostęp do elementu na indeksie 1 za pomocą operatora []: " << e[1] << "\n";

    // Test operatora << dla listy
    std::cout << "\nWyświetlanie listy za pomocą operatora <<:\n";
    std::cout << e;

    // Test metody purge
    e.purge();
    std::cout << "\nPo wyczyszczeniu listy (purge):\n";
    e.display();

    // Test ponownego dodania elementów po wyczyszczeniu
    for (int i = 0; i < 5; i++) {
        e.push_back(i * 10);
    }
    std::cout << "\nPo dodaniu elementów po wyczyszczeniu listy:\n";
    e.display();

    return 0;


    //Dopisanie z drugiej lokalizacji
}