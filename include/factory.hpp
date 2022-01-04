//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_FACTORY_HPP
#define NETWORK_FACTORY_HPP
#include "storage_types.hpp"
#include "nodes.hpp"
#include <list>


template <class Node>

class NodeCollection {
public:
    void add(Node&&(node));
    void remove_by_id(ElementID id);

    using container_t = typename std::list<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
    NodeCollection<Node>::iterator begin() {return find_by_id(ElementID id);};
    NodeCollection<Node>::const_iterator cbegin() find_by_id(ElementID id);


};

class Factory {
private:
    void NodeCollection<Ramp>::const_iterator remove_receiver();
public:
    void add_ramp(Ramp&&);
    void remove_ramp(ElementID id);
    NodeCollection<Ramp>::iterator begin() find_ramp_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator cbegin() find_ramp_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator ramp_cbegin();
    NodeCollection<Ramp>::const_iterator  ramp_cend();

    bool is_considered(void);
    void do_deliveries(Time);
    void do_package_passing(void);
    void do_work(Time);

};

// czy te klasy Ramps, Workes i Storehouses mam tu wrzucić puste?
#endif //NETWORK_FACTORY_HPP
