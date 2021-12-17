//
// Created by micha on 14.12.2021.
//

#ifndef SIEC_STORAGE_TYPES_HPP
#define SIEC_STORAGE_TYPES_HPP

#include "Package.hpp"
#include <list>

enum PackageQueueType { LIFO, FIFO };


class IPackageStockPile {
public:
    virtual void push(Package&& P) const = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() = 0;
    ///iteratory/ //??
    using const_iterator = std::list<Package>::const_iterator;

    IPackageStockPile::const_iterator begin() const = 0;
    IPackageStockPile::const_iterator cbegin() const = 0;
    IPackageStockPile::const_iterator end() const = 0;
    IPackageStockPile::const_iterator cend() const = 0;

    virtual ~IPackageStockPile(){};
};


class IPackageQueue : public IPackageStockPile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() = 0 ;
};


class PackageQueue: public IPackageQueue{
private:
    std::list<Package> container_;
    PackageQueueType packageQueueType;
public:
    void push(Package&& P) const override;
    bool empty() override;
    std::size_t size() override;
    Package pop()override;
    PackageQueueType get_queue_type() override {return packageQueueType;};
    IPackageStockPile::const_iterator begin() const override;
    IPackageStockPile::const_iterator cbegin() const override;
    IPackageStockPile::const_iterator end() const override {return container_.cend();};
    IPackageStockPile::const_iterator cend() const override {return container_.cend();};
};
#endif //SIEC_STORAGE_TYPES_HPP
