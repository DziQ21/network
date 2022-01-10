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
    virtual void push(Package&& P) = 0;
    virtual bool empty() = 0;
    virtual std::size_t size() = 0;
    using const_iterator = std::list<Package>::const_iterator;
    using iterator = std::list<Package>::iterator;

    virtual IPackageStockPile::iterator begin() = 0;
    virtual IPackageStockPile::const_iterator cbegin() const = 0;
    virtual IPackageStockPile::iterator end() = 0;
    virtual IPackageStockPile::const_iterator cend() const = 0;

    virtual ~IPackageStockPile() = default;
};


class IPackageQueue : public IPackageStockPile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0 ;

    ~IPackageQueue() override = default;
};


class PackageQueue: public IPackageQueue{
private:
    std::list<Package> container_;
    PackageQueueType packageQueueType;
public:
    PackageQueue(PackageQueueType typ): packageQueueType(typ) {};
    void push(Package&& P) override;
    bool empty() override;
    std::size_t size() override;
    Package pop() override;
    PackageQueueType get_queue_type() const override {return packageQueueType;};
    IPackageStockPile::iterator begin() override {return container_.begin();};
    IPackageStockPile::const_iterator cbegin() const override {return container_.cbegin();};
    IPackageStockPile::iterator end() override {return container_.end();};
    IPackageStockPile::const_iterator cend() const override {return container_.cend();};

    ~PackageQueue() override = default;
};
#endif //SIEC_STORAGE_TYPES_HPP
