//
// Created by micha on 14.12.2021.
//

#ifndef SIEC_STORAGE_TYPES_HPP
#define SIEC_STORAGE_TYPES_HPP

#include "Package.hpp"

using ElementID = int;
enum PackageQueueType { LIFO, FIFO };

class IPackageStockPile {
public:
    virtual void push(Package&& P) const = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() = 0;
    ///iteratory/ //??
    ~IPackageStockPile();
};
class IPackageQueue {
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0 ;
};


#endif //SIEC_STORAGE_TYPES_HPP
