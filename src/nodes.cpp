//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//
#include "nodes.hpp"

using preferences_t = std::map<IPackageReceiver*, double>;
using const_iterator = preferences_t::const_iterator;

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d) {

}


preferences_t &ReceiverPreferences::get_preferences() const {
    return preferences_; //TODO do poprawy
}

ReceiverPreferences::ReceiverPreferences(ProbabilityGenerator pg) {

}

void ReceiverPreferences::add_receiver(IPackageReceiver *r) {

    preferences_.emplace(r); // TODO do poprawy

}

void ReceiverPreferences::remove_receiver(IPackageReceiver *r) {

}

IPackageReceiver *ReceiverPreferences::choose_receiver() {
    return nullptr;
}


void PackageSender::push_package(Package &&p) {
    bufor_.emplace(p);
}

std::optional<Package> &PackageSender::get_sending_buffer() {
    return bufor_;
}

void PackageSender::send_package() {
    if(bufor_){
        receiver_preferences_.choose_receiver()->receive_package(bufor_->get_id());
    }

}

Ramp::Ramp(ElementID id, TimeOffset di) {

}

void Ramp::deliver_goods(Time t) {

}

TimeOffset Ramp::get_deliver_interval() {
    return 0;
}


void Worker::do_work(Time t) {
    // zapamiętać kiedy robotnik zaczął przetwarzanie (wartość t), i przy każdym kolejnym t sprawdzać, czy czas przetworzenia
    // czyli pd_ dobiegł do końca
    // wziąć pod uwagę to, że przetwarzany przez 1 turę produkt potem mógł znaleźć się w buforze, i to też trzeba uwzględnić
}

Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q): ID_(id), pd_(pd) {
    queue_ = std::move(q); // TODO nie jestem pewien czy dobrze
}

TimeOffset Worker::get_processing_duration() {
    return pd_;
}

Time Worker::get_package_processing_start_time() {
    return 0;
}

