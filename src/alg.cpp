// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> temp = tree.getPermutations();
    if (temp.size() >= n) {
        return temp[n - 1];
    } else {
        return {};
    }
}
