//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_FACTORY_HPP
#define NETWORK_FACTORY_HPP
#include "storage_types.hpp"
#include "nodes.hpp"
#include <vector>

//hejtu paweł neichktoś pwoe miczy to
//std::move ejst okej bo ja sam nei wiem i nei mam pojecia co robie

template <class Node>
class NodeCollection {
public:
    using container_t = typename std::vector<Node>;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;
private:
    container_t container;
public:
    void add(Node&& node);
    void remove_by_id(ElementID id);


    NodeCollection<Node>::iterator find_by_id(ElementID id){return container.begin()+id;};
    NodeCollection<Node>::const_iterator find_by_id(ElementID id) const{return container.cbegin()+id;};
    NodeCollection<Node>::const_iterator cbegin() const{return container.cbegin();};
    NodeCollection<Node>::const_iterator cend() const{return container.cend();};
    NodeCollection<Node>::iterator begin() const{return container.begin();};
    NodeCollection<Node>::iterator end() const{return container.end();};

};

class Factory {
private:
    void remove_receiver(NodeCollection<Ramp>::const_iterator& collection, ElementID id);
    NodeCollection<Ramp> ramp_container;
    NodeCollection<Worker> worker_container;
    NodeCollection<Storehouse> storehouse_container;
public:
    void add_ramp(Ramp&& r){ramp_container.add(std::move(r));};
    void remove_ramp(ElementID id){ramp_container.remove_by_id(id);};
    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id) {return ramp_container.find_by_id(id);};
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const {return ramp_container.find_by_id(id);};
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const{return ramp_container.cbegin();};
    NodeCollection<Ramp>::const_iterator  ramp_cend() const{return ramp_container.cend();};

    void add_worker(Worker&&);
    void remove_worker(ElementID id);
    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id) {return worker_container.find_by_id(id);};
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id) const {return worker_container.find_by_id(id);};
    NodeCollection<Worker>::const_iterator worker_cbegin() const {return worker_container.cbegin();};
    NodeCollection<Worker>::const_iterator  worker_cend() const {return worker_container.cend();};

    void add_storehouse(Storehouse&&);
    void remove_storehouse(ElementID id);
    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id) {return storehouse_container.find_by_id(id);};
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id) const {return storehouse_container.find_by_id(id);};
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin() const {return storehouse_container.cbegin();};
    NodeCollection<Storehouse>::const_iterator  storehouse_cend() const {return storehouse_container.cend();};

    bool is_consistent();
    void do_deliveries(Time);
    void do_package_passing();
    void do_work(Time);


};

#endif //NETWORK_FACTORY_HPP
