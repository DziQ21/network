//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_NODES_HPP
#define NETWORK_NODES_HPP

#include "types.hpp"
#include "Package.hpp"
#include "Queue.hpp"
#include "storage_types.hpp"
#include <map>
#include <memory>
#include <optional>

enum ReceiverType {WORKER, STOREHOUSE};

class IPackageReceiver {
public:

    virtual void receive_package(Package &&) = 0;
    virtual ElementID get_id() const = 0;
    virtual ReceiverType get_receiver_type() const = 0;

    virtual IPackageStockPile::const_iterator begin() const = 0;
    virtual IPackageStockPile::const_iterator cbegin() const = 0;
    virtual IPackageStockPile::const_iterator end() const = 0;
    virtual IPackageStockPile::const_iterator cend() const = 0;

};

class Storehouse {
public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d);
};

class ReceiverPreferences {
public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    ReceiverPreferences(ProbabilityGenerator pg);
    void add_receiver(IPackageReciever* r);
    void remove_receiver(IPackageReciever* r);
    IPackageReciever* choose_receiver();
    preferences_t& get_preferences() const;

    const_iterator begin() const { return preferences_.begin(); }
    const_iterator cbegin() const { return preferences_.cbegin(); }
    const_iterator end() const { return preferences_.end(); }
    const_iterator cend() const { return preferences_.cend(); }

private:
    preferences_t preferences_;
};

class PackageSender {
public:
    ReceiverPreferences receiver_preferences_;
    PackageSender(PackageSender&&) = default;
    void send_package();
    std::optional<Package>& get_sending_buffer();
protected:
    void push_package(Package&&);
};

class Ramp : public IPackageReceiver, public PackageSender{
private:
    ElementID ID_;
    ReceiverType receiverType_;
public:
    Ramp(ElementID id, TimeOffset di);
    void deliver_goods(Time t);
    TimeOffset get_deliver_interval(void);
    ElementID get_id() const override {return ID_;};
    ReceiverType get_receiver_type() const override {return receiverType_;}
};

class Worker : public IPackageReceiver, public PackageSender{
private:
    ElementID ID_;
    ReceiverType receiverType_;
    std::unique_ptr<IPackageQueue> queue_;
    TimeOffset pd_;
public:
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q);
    void do_work(Time t);
    TimeOffset get_processing_duration(void);
    Time get_package_processing_start_time(void);
    ElementID get_id() const override {return ID_;};
    ReceiverType get_receiver_type() const override {return receiverType_;}
};


#endif //NETWORK_NODES_HPP
