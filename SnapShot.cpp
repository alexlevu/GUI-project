//
// Created by Alex on 3/27/2022.
//

#ifndef MAIN_CPP_SNAPSHOT_CPP
#define MAIN_CPP_SNAPSHOT_CPP
#include "SnapShot.h"

template<class T>
void SnapShot<T>::getSnapshot(T data)
{
    list.push(data);
}

template<class T>
T SnapShot<T>::getData1() {
    T temp = list.top();
    list.pop();
    return temp;

}

template<class T>
bool SnapShot<T>::listIsEmpty() {
    if (list.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif //MAIN_CPP_SNAPSHOT_CPP
