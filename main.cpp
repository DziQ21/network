#include <iostream>
#include "package.hpp"
#include "storage_types.hpp"
#include "nodes.hpp"


//void print_opt(std::optional<int> opt) {
//    if (opt) {  // sprawdź, czy `opt` zawiera wartość; równoważnie: opt.has_value()
//        // dostęp do wartości odbywa się jak w przypadku wskaźnika (*p, p->x); równoważnie: opt.value()
//        std::cout << "opt has a value: " << *opt << std::endl;
//    } else {
//        std::cout << "opt is empty" << std::endl;
//    }
//}

int main() {

    Package p1;
    Package p2;
    Package p3(3);

    std::cout << p1.get_id() << p2.get_id() << p3.get_id() << std::endl;
    PackageQueue L1(LIFO);
    std::cout << L1.empty() << std::endl;
    L1.push(std::move(p1));
    L1.push(std::move(p2));
    L1.push(std::move(p3));
    std::cout << L1.empty() << std::endl;

    std::cout << L1.size() << std::endl;

    for(auto it = L1.begin(); it != L1.end(); it++)
    {
        std::cout << it->get_id() << std::endl;
    }
    std::cout << L1.pop().get_id();

    std::vector<Worker> w1;

//    std::optional<int> opt = std::nullopt;
//    print_opt(opt);
//
//    opt.emplace(1);  // umieść wartość "w miejscu" (tj. bez wykonywania zbędnej kopii obiektu)
//    print_opt(opt);
//
//    opt = 3;  // umieść wartość za pomocą przypisania
//    print_opt(opt);
//
//    opt.reset();  // usuń wartość
//    print_opt(opt);

    return 0;
}
