//
// Created by Paweł on 2021-12-14.
//

#ifndef SIEC_QUEUE_HPP
#define SIEC_QUEUE_HPP
#include <array>
#include <vector>
#include "Package.hpp"

// Tak wygląda interfejs
// uzupełnij to zgodnie z tym ale patrz na sam koniec dokumentu ->https://home.agh.edu.pl/~mdig/dokuwiki/doku.php?id=teaching:programming:soft-dev:topics:net-simulation:part_storage
class IPackageStockpile {
public:
    virtual void Put(Package product) = 0;
    virtual std::vector<Package> GetProducts() = 0;
    virtual Package GetProduct()=0;


};

class Lifo:IPackageStockpile{

};

class Fifo:IPackageStockpile{

};
#endif //SIEC_QUEUE_HPP
