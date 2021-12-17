//
// Created by micha on 14.12.2021.
//

#ifndef SIEC_STORAGE_TYPES_HPP
#define SIEC_STORAGE_TYPES_HPP

#include "Package.hpp"

enum PackageQueueType { LIFO, FIFO };


class IPackageStockPile {
public:
    virtual void push(Package&& P) const = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() = 0;
    ///iteratory/ //??
    using const_iterator = std::list<Package>::const_iterator;

    IPackageStockpile::const_iterator begin() const = 0;
    IPackageStockpile::const_iterator cbegin() const = 0;
    IPackageStockpile::const_iterator end() const = 0;
    IPackageStockpile::const_iterator cend() const = 0;

    virtual ~IPackageStockPile(){};
};

class IPackageQueue {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0 ;
};


#endif //SIEC_STORAGE_TYPES_HPP
