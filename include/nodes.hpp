//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_NODES_HPP
#define NETWORK_NODES_HPP

#include "types.hpp"
#include "package.hpp"
#include "Queue.hpp"
#include "storage_types.hpp"
#include <memory>
#include <optional>

enum ReceiverType {};

class IPackageReciever {
private:
    ElementID ID_;
public:
    virtual void receive_package(Package &&) = 0;
    virtual ElementID get_id() const {return ID_;}
};

class Storehouse {
public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d);
};

class ReceiverPreferences {
public:
    unsigned int preferences_t;
    ReceiverPreferences(ProbabilityGenerator pg);
    void add_receiver(IPackageReciever* r);
    void remove_receiver(IPackageReciever* r);
    IPackageReciever*(choose_receiver(void));
    preferences_t&(get_preferences(void));

};

class PackageSender {
public:
    unsigned receiver_preferences_(ReceiverPreferences);
    PackageSender(PackageSender&&);
    void send_package(void);
    std::optional<Package&> get_sending_buffer(void); //nie wiem czemu to optional nie działa ._.
protected:
    void push_package(Package&&);
};

class Ramp {
public:
    Ramp(ElementID id, TimeOffset di);
    void deliver_goods(Time t);
    TimeOffset get_deliver_interval(void);
    ElementID get_id(void);
};

class Worker {
public:
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q); //tu ma być typ void, ale ja daję, to po mnie krzyczy ._.
    void do_work(Time t);
    TimeOffset get_processing_duration(void);
    Time get_package_processing_start_time(void);
};


#endif //NETWORK_NODES_HPP
