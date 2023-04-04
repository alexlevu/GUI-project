//
// Created by Alex on 3/27/2022.
//

#ifndef MAIN_CPP_SNAPSHOT_H
#define MAIN_CPP_SNAPSHOT_H
#include <stack>

template<class T>
class SnapShot {
private:
    //T data;
    std::stack<T> list;

public:

    void getSnapshot(T data);
    T getData1();
    bool listIsEmpty();

};

#include "SnapShot.cpp"
#endif //MAIN_CPP_SNAPSHOT_H
