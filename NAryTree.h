//
// Created by Alex on 4/17/2022.
//

#ifndef MAIN_CPP_NARYTREE_H
#define MAIN_CPP_NARYTREE_H

#include "Node.h"
#include <iostream>
class NAryTree
{
private:
    Node* root = nullptr;
    void insert(Node* node, std::string item);
    Node* find(Node* node, std::string path);
    void print(std::ostream& out, Node* node) const;
    std::vector<std::string> split(std::string path);
public:
    NAryTree(){}
    void insert(std::string path, std::string item);
    friend std::ostream& operator<<(std::ostream& out, const NAryTree& tree);

};

#endif //NARYTREE_NARYTREE_H