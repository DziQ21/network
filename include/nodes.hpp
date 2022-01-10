//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//

#ifndef NETWORK_NODES_HPP
#define NETWORK_NODES_HPP

#include "types.hpp"
#include "Package.hpp"
#include "Queue.hpp"
#include "storage_types.hpp"
#include "helpers.hpp"
#include <map>
#include <memory>
#include <optional>

enum ReceiverType {WORKER, STOREHOUSE};

class IPackageReceiver {
public:

    virtual void receive_package(Package&&) = 0;
    virtual ElementID get_id() const = 0;
    virtual ReceiverType get_receiver_type() const = 0;

    virtual IPackageStockPile::const_iterator begin() const = 0;
    virtual IPackageStockPile::const_iterator cbegin() const = 0;
    virtual IPackageStockPile::const_iterator end() const = 0;
    virtual IPackageStockPile::const_iterator cend() const = 0;
    virtual ~IPackageReceiver() = default;
};


class ReceiverPreferences {
public:
    using preferences_t = std::map<IPackageReceiver*, double>;
    using const_iterator = preferences_t::const_iterator;

    ReceiverPreferences(ProbabilityGenerator &pg);
    ReceiverPreferences() = default;
    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    preferences_t const& get_preferences() const;

    const_iterator begin() const { return preferences_.begin(); }
    const_iterator cbegin() const { return preferences_.cbegin(); }
    const_iterator end() const { return preferences_.end(); }
    const_iterator cend() const { return preferences_.cend(); }

private:
    preferences_t preferences_;
    ProbabilityGenerator pg_;
};


class PackageSender {
private:
    std::optional<Package> bufor_ = std::nullopt;
public:
    ReceiverPreferences receiver_preferences_;

    PackageSender(PackageSender&&) = default;
    PackageSender() = default;
    void send_package();
    std::optional<Package> const& get_sending_buffer() const;
protected:
    void push_package(Package&& p);
};


class Ramp : public PackageSender{
private:
    ElementID ID_;
    TimeOffset di_;
public:
    Ramp(ElementID id, TimeOffset di);
    void deliver_goods(Time t);
    TimeOffset get_deliver_interval() const;
    ElementID get_id() const;

};

class Worker : public IPackageReceiver, public PackageSender{
private:
    ElementID ID_;
    std::unique_ptr<IPackageQueue> queue_;
    TimeOffset pd_;
    std::optional<Package> bufor_ = std::nullopt;
    Time package_processing_start_time_;
public:

    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q);
    void receive_package(Package&&) override;
    void do_work(Time t);
    TimeOffset get_processing_duration() const {return pd_;};
    Time get_package_processing_start_time() const {return package_processing_start_time_;};
    ElementID get_id() const override {return ID_;};
    ReceiverType get_receiver_type() const override {return WORKER;}
};


class Storehouse : public IPackageReceiver{
private:
    ElementID ID_;
    std::unique_ptr<IPackageStockPile> d_;
public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d = std::make_unique<IPackageStockpile>(PackageQueue(FIFO)));
    void receive_package(Package&&) override;
    ElementID get_id() const override {return ID_;};
    ReceiverType get_receiver_type() const override {return STOREHOUSE;}
};


#endif //NETWORK_NODES_HPP
