//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_FACTORY_HPP
#define NETWORK_FACTORY_HPP
#include "storage_types.hpp"
#include "nodes.hpp"
#include <vector>


template <class Node>

class NodeCollection {
public:
    void add(Node&&(node));
    void remove_by_id(ElementID id);

    using container_t = typename std::vector<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
    NodeCollection<Node>::iterator find_by_id(ElementID id);
    NodeCollection<Node>::const_iterator find_by_id(ElementID id) const;


};

class Factory {
private:
    void remove_receiver(NodeCollection<Ramp>::const_iterator& collection, ElementID id);
public:
    void add_ramp(Ramp&&);
    void remove_ramp(ElementID id);
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const;
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const;
    NodeCollection<Ramp>::const_iterator  ramp_cend() const;

    void add_worker(Worker&&);
    void remove_worker(ElementID id);
    NodeCollection<Ramp>::iterator find_worker_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator find_worker_by_id(ElementID id) const;
    NodeCollection<Ramp>::const_iterator worker_cbegin() const;
    NodeCollection<Ramp>::const_iterator  worker_cend() const;

    void add_storehouse(Storehouse&&);
    void remove_storehouse(ElementID id);
    NodeCollection<Ramp>::iterator find_storehouse_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator find_storehouse_by_id(ElementID id) const;
    NodeCollection<Ramp>::const_iterator storehouse_cbegin() const;
    NodeCollection<Ramp>::const_iterator  storehouse_cend() const;

    bool is_considered();
    void do_deliveries(Time);
    void do_package_passing();
    void do_work(Time);

};

#endif //NETWORK_FACTORY_HPP
