//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//
#include "nodes.hpp"

using preferences_t = std::map<IPackageReceiver*, double>;
using const_iterator = preferences_t::const_iterator;

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d) {

}


preferences_t &ReceiverPreferences::get_preferences() const {return preferences_;} //???

void Worker::do_work(Time t) {
    // zapamiętać kiedy robotnik zaczął przetwarzanie (wartość t), i przy każdym kolejnym t sprawdzać, czy czas przetworzenia
    //czyli pd_ dobiegł do końca
}

