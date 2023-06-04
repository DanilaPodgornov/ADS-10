// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    bool Root = false;
    char value;
    std::vector<Node*> pointers;
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> temp;
    void searchPerms(Node* root, std::vector<char> vector) {
        if (!root->Root)
            vector.push_back(root->vlaue);
        if (root->pointers.empty()) {
            temp.push_back(vector);
        } else {
            for (Node* child : root->pointers) {
                searchPerms(child, vector);
            }
        }
    }
    
    void addNode(Node* root, const std::vector<char>& vector) {
        for (char c : vector) {
            Node* tmp = new Node;
            tmp->value = c;
            root->pointers.push_back(tmp);
            std::vector<char> remainingChars(vector);
            remainingChars.erase(std::find(remainingChars.begin(), \
                remainingChars.end(), c));
            addNode(tmp, remainingChars);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vector) {
        root = new Node;
        root->Root = true;
        addNode(root, vector);
        std::vector<char> current;
        searchPerms(root, current);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return perms;
    }
};
#endif  // INCLUDE_TREE_H_
