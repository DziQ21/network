//
// Created by KASIA ŁUSZCZEWSKA on 04.01.2022.
//
#include "nodes.hpp"

using preferences_t = std::map<IPackageReceiver*, double>;
using const_iterator = preferences_t::const_iterator;

Storehouse::Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d): ID_(id) {

}

void Storehouse::receive_package(Package &&)
{
    d_->push(Package());
}


preferences_t const& ReceiverPreferences::get_preferences() const
{
    return preferences_;
}

//TODO: ???
ReceiverPreferences::ReceiverPreferences(ProbabilityGenerator pg)
{

}

void ReceiverPreferences::add_receiver(IPackageReceiver *r)
{
    preferences_.emplace(r, 1);
    for (auto elem : preferences_)
    {
        elem.second = 1 / (double)(preferences_.size()); // skaluje prawd. wylosowania odbiorcy, na tym etapie każdy będzie miał to samo prawd.
    }
}

void ReceiverPreferences::remove_receiver(IPackageReceiver *r)
{
    preferences_.erase(r);
    if (!preferences_.empty())
    {
        for (auto elem: preferences_)
        {
            elem.second = 1 / (double) (preferences_.size());
        }
    }
}

IPackageReceiver *ReceiverPreferences::choose_receiver()
{
    double probability = probability_generator();
    double left_lim = 0;
    double right_lim = 0;

    if (!preferences_.empty())
    {
        for (auto elem: preferences_)
        {
            right_lim += elem.second;
            if (left_lim < probability <= right_lim)
            {
                return elem.first;
            }
            else left_lim += elem.second;
        }
    }

    return nullptr;
}


void PackageSender::push_package(Package &&p)
{
    bufor_.emplace(p);
}

std::optional<Package> const& PackageSender::get_sending_buffer() const
{
    return bufor_;
}

void PackageSender::send_package()
{
    if(bufor_)
    {
        receiver_preferences_.choose_receiver()->receive_package(bufor_->get_id());
        bufor_.reset();
    }
}


Ramp::Ramp(ElementID id, TimeOffset di): ID_(id), di_(di) {}

void Ramp::deliver_goods(Time t)
{
    if (t == 1)
    {
        send_package();
    }
    else if ((t-1)%di_ == 0)
    {
        send_package();
    }
}

TimeOffset Ramp::get_deliver_interval() const
{
    return di_;
}

ElementID Ramp::get_id() const
{
    return ID_;
}


void Worker::do_work(Time t)
{
    if(!bufor_ and queue_) // jeśli bufor jest pusty i jest coś w kolejce
    {
        bufor_.emplace(queue_->pop()); // wstaw do bufora
        package_processing_start_time_ = t; // zapamiętaj czas startu przetwarzania
    }
    else if(bufor_)
    {
        if (t - package_processing_start_time_ == pd_) // jeśli upłynął czas przetwarzania
        {
            push_package(Package());
            bufor_.reset();
        }
    }
}

Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q): ID_(id), pd_(pd)
{
    queue_ = std::move(q);
}

void Worker::receive_package(Package&&)
{
    queue_->push(Package());
}

