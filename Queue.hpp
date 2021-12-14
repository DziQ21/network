//
// Created by Paweł on 2021-12-14.
//

#ifndef SIEC_QUEUE_HPP
#define SIEC_QUEUE_HPP
#include <array>
#include <vector>
#include "Product.hpp"

class Queue {
public:
    virtual void Put(Product product) = 0;
    virtual std::vector<Product> GetProducts() = 0;
    virtual Product GetProduct()=0;


};

class Lifo:Queue{

};

class Fifo:Queue{

};
#endif //SIEC_QUEUE_HPP
