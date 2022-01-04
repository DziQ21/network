//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_FACTORY_HPP
#define NETWORK_FACTORY_HPP
#include "storage_types.hpp"

template <class Node>
class NodeCollection {
public:
    void add(Node&&(node));
    void remove_by_id(ElementID id);
    



};
#endif //NETWORK_FACTORY_HPP
