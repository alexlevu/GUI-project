//
// Created by Alex on 3/22/2022.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST; i++) {
        states[static_cast<State>(i)] = false;
    }
}


void States::enableState(State state) {
    states[state] = true;
}

void States::disableState(State state) {
    states[state] = false;
}

bool States::isEnabled(State state) const
{
    return states.at(state);
}

