//
// Created by micha on 17.12.2021.
//

#ifndef SIEC_TYPES_HPP
#define SIEC_TYPES_HPP

#include <cstdlib>
#include <iostream>
#include <functional>

using ElementID = int;

using Time = int;
using TimeOffset = int;
using ProbabilityGenerator = std::function<double()>;

#endif //SIEC_TYPES_HPP
