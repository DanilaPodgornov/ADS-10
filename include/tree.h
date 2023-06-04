// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> pointers {};
        explicit Node(char value): value(value) {}
    };

    Node* addNode(Node* root, std::vector<char> vectorChar) {
        if (nullptr == root) {
            root = new Node('x');
            numberOfElements = vectorChar.size();
        }
        for (int i = 0; i < vectorChar.size(); i++) {
            Node* child = new Node(vectorChar[i]);
            root->pointers.push_back(child);

            std::vector<char> temp = vectorChar;
            temp.erase(temp.begin() + i);
            addNode(child, temp);
        }
        return root;
    }

 public:
    Node* root;
    int numberOfElements;
    explicit Tree(std::vector<char> vector) : numberOfElements(0) {
        root = addNode(root, vector);
    }

    int Fact(int n) const {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    std::vector<char> getPermutation(Node* node, int n,
                                     int localNumberOfElements,
                                     std::vector<char> vector) const {
        if (localNumberOfElements == 0) {
            return vector;
        }
        Node* tempNode = node->pointers[(n - 1) / (Fact(localNumberOfElements)
                                                   / localNumberOfElements)
                                        % localNumberOfElements];
        vector.push_back(tempNode->value);
        int newNumber = localNumberOfElements - 1;
        return getPermutation(tempNode, n, newNumber, vector);
    }
};
#endif  // INCLUDE_TREE_H_
