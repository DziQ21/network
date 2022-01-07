//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#include "factory.hpp"

enum node_color {NONVISITED, VISITED, VERIFIED};

template<class Node>
void NodeCollection<Node>::add(Node &&node) {

}

template<class Node>
void NodeCollection<Node>::remove_by_id(ElementID id) {

}

void Factory::add_ramp(Ramp &&) {

}

void Factory::remove_ramp(ElementID id) {

}

void Factory::add_worker(Worker &&) {

}

void Factory::remove_worker(ElementID id) {

}

void Factory::add_storehouse(Storehouse &&) {

}

void Factory::remove_storehouse(ElementID id) {

}

bool Factory::is_consistent() {

    return true; // dodaj logike
}

void Factory::do_deliveries(Time) {

}

void Factory::do_package_passing() {

}

void Factory::do_work(Time) {

}
