//
// Created by Alex on 3/22/2022.
//

#ifndef MAIN_CPP_STATES_H
#define MAIN_CPP_STATES_H
#include "State.h"
#include <iostream>
#include <map>

class States {
private:
    std::map<State, bool> states;

public:
    States();
    bool isEnabled(State state) const;
    void enableState(State state);
    void disableState(State state);
};


#endif //MAIN_CPP_STATES_H
