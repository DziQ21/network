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
    if (node_colors[sender]==VERIFIED)
        return true;
    node_colors[sender]=VISITED;
    if(sender->receiver_preferences_.get_preferences().empty())
        throw std::logic_error("non defined recivers");
    bool czy_nadawca_ma_choć_jednego_odbiorcę_innego_niż_siebie_samego = false;
    auto a=sender->receiver_preferences_.get_preferences();
    for(auto &i:a){
        if(i.first->get_receiver_type()==STOREHOUSE){
            czy_nadawca_ma_choć_jednego_odbiorcę_innego_niż_siebie_samego = true;
        }else
        {
            auto worker=(Worker*)i.first;
            if(sender==worker){
                continue;
            }else
            {
                czy_nadawca_ma_choć_jednego_odbiorcę_innego_niż_siebie_samego = true;
            }
            if(node_colors[worker]==NONVISITED){
                has_reachable_storehouse(worker,node_colors);
            }
        }

    }
    node_colors[sender]=VERIFIED;
    if(czy_nadawca_ma_choć_jednego_odbiorcę_innego_niż_siebie_samego){
        return true;
    }
    throw std::logic_error("niema zweryfikwoanego odbiorcy")
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
    } catch (std::logic_error &e){
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
