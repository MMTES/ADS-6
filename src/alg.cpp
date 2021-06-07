// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string> tree;
  char difFromAToa = 'a' - 'A';
  std::string wordc = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File read error" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char sym = file.get();
    if ((sym >= 'A' && sym <= 'Z') || (sym >= 'a' && sym <= 'z')) {
      if (sym >= 'A' && sym <= 'Z')
        sym += difFromAToa;
      wcount += sym;
    } else if (wcount != "") {
      tree.add(wcount);
      wcount = "";
    }
  }
  file.close();
  return tree;
}
