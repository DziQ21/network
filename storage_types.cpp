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





Package PackageQueue::pop() {
    if(packageQueueType==LIFO)
        return container_.pop_front();
    else if(packageQueueType==FIFO)
        return container_.pop_back();

}
