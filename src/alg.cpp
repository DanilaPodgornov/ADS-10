// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <vector>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int Fact(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> out;
    out = tree.getPermutation(tree.root, n, tree.numberOfElements,
                              std::vector<char> {});
    return out;
}
