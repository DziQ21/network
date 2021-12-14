//
// Created by Paweł on 2021-12-14.
//

#ifndef SIEC_PRODUCT_HPP
#define SIEC_PRODUCT_HPP

#include <set>
#include "types.hpp"

//TODO: każdy produkt ma swój unikalny numer seryjny, możliwie niski
//TODO: konstruktor przyjmujący ID produktu, potrzebny pod kątem wczytywania danych z pliku


class Product {
private:
    static std::set<ElementID> assigned_IDs; // przechowuje przydzielone obecnie id
    static std::set<ElementID> freed_IDs; // przechowuje wartości użytych kiedyś, ale zwolnionych id
    ElementID ID_;
public:
    Product();
    Product(ElementID id);
    Product(Product&& P);
    ElementID get_id() const {return ID_;}
    ~Product();
    //TODO: w UML w klasie Package jest ten operator tylko nie wiem czy teraz czy na późniejszych etapach
    //bo nie wiem jak miałby niby działać. Przypisać nowemu produktowi id starego produktu, po czym usunac stary? troche bez sensu
//    operator=(Product&& P)
};


#endif //SIEC_PRODUCT_HPP
