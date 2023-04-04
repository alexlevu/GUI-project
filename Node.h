//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_NODE_H
#define MAIN_CPP_NODE_H
#include <string>
#include <vector>

struct Node
{
    std::string data;
    std::vector<Node*> children;
};

#endif //MAIN_CPP_NODE_H
