#include "storage_types.hpp"



IPackageStockPile::~IPackageStockPile() {

}

void PackageQueue::push(Package&& P) const {

}

bool PackageQueue::empty() {
    return false;
}

std::size_t PackageQueue::size() {
    return container_.size();
}

IPackageStockPile::const_iterator PackageQueue::begin() const {
    return container_.begin();
}

IPackageStockPile::const_iterator PackageQueue::cbegin() const {
    return container_.cbegin();
}




Package PackageQueue::pop() {
    return Package();
}
