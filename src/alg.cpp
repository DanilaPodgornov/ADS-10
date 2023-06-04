// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    if (n > tree.Fact(tree.numberOfElements)) {
        return {};
    }
    std::vector<char> out;
    out = tree.getPermutation(tree.root, n, tree.numberOfElements,
                              std::vector<char> {});
    return out;
}
