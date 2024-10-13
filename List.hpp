#ifndef C188899E_0C33_4B0A_92C3_89E0D3865046
#define C188899E_0C33_4B0A_92C3_89E0D3865046

#include <iostream>

/// @brief Klasa reprezentująca listę dwukierunkową.
class List {
    /// @brief Struktura reprezentująca węzeł na liście.
    struct Node {
        int value;      ///< Wartość przechowywana w węźle.
        Node* prev;     ///< Wskaźnik na poprzedni węzeł.
        Node* next;     ///< Wskaźnik na następny węzeł.

        /// @brief Konstruktor inicjalizujący węzeł wartością.
        /// @param a Wartość do przechowania w węźle.
        Node(int a = 0);

        /// @brief Konstruktor inicjalizujący węzeł wartością i wskaźnikiem na inny węzeł.
        /// @param a Wartość do przechowania w węźle.
        /// @param b Wskaźnik na inny węzeł.
        Node(int a, Node* b);

        /// @brief Przeciążenie operatora << dla struktury Node.
        /// @param stream Strumień wyjściowy.
        /// @param node Wskaźnik na węzeł do wyświetlenia.
        /// @return Referencja do strumienia wyjściowego.
        friend std::ostream& operator<<(std::ostream& stream, const List::Node* node);
    };

    private:
    Node* head;      ///< Wskaźnik na pierwszy węzeł listy.
    Node* tail;      ///< Wskaźnik na ostatni węzeł listy.
    int counter;     ///< Licznik elementów w liście.

    public:
    /// @brief Domyślny konstruktor klasy List.
    List();

    /// @brief Destruktor klasy List.
    ~List();

    /// @brief Dodaje nowy element na końcu listy.
    /// @param i Wartość do dodania.
    void push_back(int i);

    /// @brief Dodaje nowy element na początku listy.
    /// @param i Wartość do dodania.
    void push_front(int i);

    /// @brief Wstawia nowy element na określonym indeksie.
    /// @param value Wartość do wstawienia.
    /// @param index Pozycja, na której ma być wstawiony nowy element.
    void insert_at(int value, int index);

    /// @brief Usuwa pierwszy element z listy.
    void remove_first();

    /// @brief Usuwa ostatni element z listy.
    void remove_last();

    /// @brief Usuwa element na określonym indeksie.
    /// @param index Pozycja elementu do usunięcia.
    void remove_at(int index);

    /// @brief Usuwa wszystkie elementy z listy.
    void purge();

    /// @brief Wyświetla zawartość listy.
    void display() const;

    /// @brief Wyświetla zawartość listy w odwrotnej kolejności.
    void display_reversed() const;

    /// @brief Wyświetla następny element, zaczynając od danego indeksu.
    /// @param index Indeks początkowy do wyświetlenia.
    void display_next(int index) const;

    /// @brief Wyświetla poprzedni element, zaczynając od danego indeksu.
    /// @param index Indeks początkowy do wyświetlenia.
    void display_previous(int index) const;

    /// @brief Przeciążenie operatora [] do dostępu do elementów listy.
    /// @param index Indeks elementu, do którego ma nastąpić dostęp.
    /// @return Stała referencja do wartości na określonym indeksie.
    const int& operator[](int index) const;

    /// @brief Przeciążenie operatora << dla klasy List.
    /// @param stream Strumień wyjściowy.
    /// @param list Lista do wyświetlenia.
    /// @return Referencja do strumienia wyjściowego.
    friend std::ostream& operator<<(std::ostream& stream, const List& list);

    /// @brief Przeciążenie operatora << dla struktury Node.
    /// @param stream Strumień wyjściowy.
    /// @param node Wskaźnik na węzeł do wyświetlenia.
    /// @return Referencja do strumienia wyjściowego.
    friend std::ostream& operator<<(std::ostream& stream, const List::Node* node);
};

#endif /* C188899E_0C33_4B0A_92C3_89E0D3865046 */
