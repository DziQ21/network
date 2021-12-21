#include <iostream>
#include "Package.hpp"
#include "storage_types.hpp"


int main() {
    Package p1;
    Package p2;

    std::cout << p1.get_id() << ", " << p2.get_id() << std::endl;
    return 0;
}
