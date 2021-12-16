//
// Created by Paweł on 2021-12-14.
//

#ifndef SIEC_PACKAGE_HPP
#define SIEC_PACKAGE_HPP

#include <set>
#include "types.hpp"


class Package {
private:
    static std::set<ElementID> assigned_IDs; // przechowuje przydzielone obecnie id
    static std::set<ElementID> freed_IDs; // przechowuje wartości użytych kiedyś, ale zwolnionych id
    ElementID ID_;
public:
    Package();
    Package(ElementID id);
    Package(Package&& P);
    ElementID get_id() const {return ID_;}
    ~Package();
    //TODO: w UML w klasie Package jest ten operator tylko nie wiem czy teraz czy na późniejszych etapach
    // bo nie wiem jak miałby niby działać. Przypisać nowemu produktowi id starego produktu, po czym usunac stary? troche bez sensu, Michal
//    operator=(Package&& P)
};


#endif //SIEC_PACKAGE_HPP
