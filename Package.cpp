//
// Created by Paweł on 2021-12-14.
//

#include "Package.hpp"

Package::Package() {
    if(!freed_IDs.empty()) {
        ID_ = *freed_IDs.begin(); //przypisuje minimalny element
        assigned_IDs.insert(ID_); // aktualizuje assigned
    }
    else if(!assigned_IDs.empty()) {
        ID_ = *assigned_IDs.rbegin() + 1; //przypisuje maksymalny element + 1
        assigned_IDs.insert(ID_);
    }
    else {
        ID_ = 1;
        assigned_IDs.insert(ID_);
    }
}

// konstruktor przypisujący id, które pobralismy z pliku, wstawia id do assigned ids
Package::Package(ElementID id): ID_(id) {
    //TODO: chyba trzeba sprawdzić, czy wcześniej nie użyliśmy już tego id, ale nie jestem do końca pewien
    // czy jest to konieczne, bo wczytujemy raczej na początku symulacji gdzie assigned_IDs jest puste
    assigned_IDs.insert(ID_);
}

Package::Package(Package &&P) {
    // nie wiem czy dobrze rozumiem o co chodzi
    ID_ = P.get_id();
    assigned_IDs.insert(ID_);
    //???
}

Package::~Package(){
    assigned_IDs.erase(ID_);
    freed_IDs.insert(ID_);
}
//PackageQueue::PackageQueueType(){

//}