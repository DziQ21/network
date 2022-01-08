//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#include "factory.hpp"

enum NodeColor {NONVISITED, VISITED, VERIFIED};

template<class Node>
void NodeCollection<Node>::add(Node &&node) {
    container.push_back(std::move(node));
}

template<class Node>
void NodeCollection<Node>::remove_by_id(ElementID id) {
    container.erase(container.begin()+id);
}



//zaczynam to pisaćboze broń kudzi przed tym kodem/

bool has_reachable_storehouse(const PackageSender* sender, std::map<const PackageSender*, NodeColor>& node_colors){
    return true;
}
bool Factory::is_consistent() {
    std::map<const PackageSender*, NodeColor> node_colors;
    for(auto i = ramp_cbegin();i<ramp_cend();i++){
        node_colors.insert(std::pair<const PackageSender*, NodeColor>((PackageSender*)(&(*i)),NONVISITED)); //i ozbaczył że wksażniki były dobre
    }
    for(auto i = worker_cbegin();i<worker_cend();i++){
        node_colors.insert(std::pair<const PackageSender*, NodeColor>((PackageSender*)(&(*i)),NONVISITED));
    }
      //serio neich ktośzerknie bo jak widze te wskazniki to dziwnie sieczuje~~paweł
    try{
        for(auto i = ramp_cbegin();i<ramp_cend();i++){
            has_reachable_storehouse(&(*i),node_colors);//dobra popełniłem cos trasznego z tymi wskaznikami
        }
    } catch (std::logic_error    &e){
        throw e;
    }
    return true;
}


void Factory::do_deliveries(Time) {

}

void Factory::do_package_passing() {

}

void Factory::do_work(Time) {

}
