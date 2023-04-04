//
// Created by Alex on 4/17/2022.
//

#include "NAryTree.h"
std::ostream &operator<<(std::ostream &out, const NAryTree &tree)
{
    tree.print(out, tree.root);
    return out;
}

void NAryTree::insert(Node *node, std::string item)
{
    Node* n = new Node;
    n->data = item;
    node->children.push_back(n);
}

void NAryTree::insert(std::string path, std::string item)
{
    if(root == nullptr)
    {
        root = new Node;
        root->data = path;
        Node* n = new Node;
        n->data = item;
        root->children.push_back(n);
        return;
    }
    std::vector<std::string> paths = split(path);
    Node *n = find(root, paths[0]);
    for(int i=1; i<paths.size();i++)
    {
        if(n == nullptr)
        {
            break;
        }
        n = find(n, paths[i]);
    }
    if(n != nullptr)
    {
        insert(n,item);
    }

}

Node *NAryTree::find(Node* node, std::string path)
{
    if(node->data == path)
    {
        return node;
    }

    for(Node* n : node->children)
    {
        node = find(n, path);
    }
    return node;
}

void NAryTree::print(std::ostream &out, Node *node) const
{
    if(node->children.size() == 0)
    {
        out << node->data;
        return;
    }
    out << node->data << "/";
    for(Node* n : node->children)
    {
        print(out, n);
    }

}

std::vector<std::string> NAryTree::split(std::string path)
{
    std::vector<std::string> s;

    std::string str = path;

    int idx = str.find("/");
    while(idx != std::string::npos)
    {
        std::string sub = str.substr(0, idx);
        str = str.substr(idx+1);
        s.push_back(sub);
        idx = str.find("/");
    }
    if(str.size() > 0)
    {
        s.push_back(str);
    }
    return s;
}