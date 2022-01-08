//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#include "factory.hpp"

enum node_color {NONVISITED, VISITED, VERIFIED};

template<class Node>
void NodeCollection<Node>::add(Node &&node) {
    container.push_back(std::move(node));
}

template<class Node>
void NodeCollection<Node>::remove_by_id(ElementID id) {
    container.erase(container.begin()+id);
}



//zaczynam to pisaćboze broń kudzi przed tym kodem
bool Factory::is_consistent() {

    return true; // dodaj logike
}

void Factory::do_deliveries(Time) {

}

void Factory::do_package_passing() {

}

void Factory::do_work(Time) {

}
