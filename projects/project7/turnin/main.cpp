// My ID: 5727889

//#define DTOR_TEST
#define DISPLAY_TREES
#define MIRROR_TREES
#define BST_VERIFY
#define MIN_MAX_TREES
#define ROOT_LEAF_TREES
#define PATH_SUM_TO_TREES

#include <iostream>

#include "BinaryNodeTree.h"

int main() {

  BinaryNodeTree<int> intTree(5);
  intTree.add(8);
  intTree.add(4);
  intTree.add(3);
  intTree.add(1);
  intTree.add(7);
  intTree.add(6);
  intTree.add(2);

  BinaryNodeTree<char> charTree('a');
  charTree.add('b');
  charTree.add('c');
  charTree.add('d');
  charTree.add('e');
  charTree.add('f');
  charTree.add('g');
  charTree.add('h');
  charTree.add('i');
  charTree.add('j');
  charTree.add('k');

  BinaryNodeTree<std::string> strTree("ghi");
  strTree.add("abc");
  strTree.add("jkl");
  strTree.add("def");
  strTree.add("mno");
  
#ifdef DISPLAY_TREES
  std::cout << "Displaying the Binary Tree (type int):" << std::endl;
  intTree.display();

  std::cout << "\nDisplaying the Binary Tree (type char):" << std::endl;
  charTree.display();

  std::cout << "\nDisplaying the Binary Tree (type string):" << std::endl;
  strTree.display();

#else
  std::cout << "Skipping displaying the trees." << std::endl;
#endif

#ifdef MIRROR_TREES
  std::cout << "\n\nMirroring the Binary Tree (type int):" << std::endl;
  intTree.mirror();
  intTree.display();
  
  std::cout << "\nMirroring the Binary Tree (type char):" << std::endl;
  charTree.mirror();
  charTree.display();

#else
  std::cout << "Skipping mirroring the trees." << std::endl;
#endif
  
  BinaryNodeTree<int> bst(50);
  bst.add(30);
  bst.add(70);
  bst.add(20);
  bst.add(60);
  bst.add(40);
  bst.add(10);
  bst.add(80);

#ifdef BST_VERIFY
  BinaryNodeTree<int> not_bst(50);
  not_bst.add(80);
  not_bst.add(40);
  not_bst.add(30);
  not_bst.add(10);
  not_bst.add(70);
  not_bst.add(60);
  not_bst.add(20);

  BinaryNodeTree<int> pseudo_bst(50);
  pseudo_bst.add(30);
  pseudo_bst.add(70);
  pseudo_bst.add(20);
  pseudo_bst.add(10);
  pseudo_bst.add(40);
  pseudo_bst.add(10);
  pseudo_bst.add(80);

  BinaryNodeTree<int> pseudo_bst2(50);
  pseudo_bst2.add(30);
  pseudo_bst2.add(70);
  pseudo_bst2.add(20);
  pseudo_bst2.add(60);
  pseudo_bst2.add(55);
  pseudo_bst2.add(10);
  pseudo_bst2.add(80);

  std::cout << "\n\n";
  
  bst.display();
  std::cout << "Is BST? " << bst.isBST() << "\n" << std::endl;

  not_bst.display();
  std::cout << "Is BST? " << not_bst.isBST() << "\n" << std::endl;

  pseudo_bst.display();
  std::cout << "Is BST? " << pseudo_bst.isBST() << "\n" << std::endl;

  pseudo_bst2.display();
  std::cout << "Is BST? " << pseudo_bst2.isBST() << std::endl;
  
#else
  std::cout << "Skipping BST verification." << std::endl;
#endif

#ifdef MIN_MAX_TREES
  std::cout << "\n\nMinimum value of binary tree (type int): " << intTree.minimum() << std::endl;
  std::cout << "Minimum value of binary tree (type char): " << charTree.minimum() << std::endl;
  std::cout << "Minimum value of binary tree (type string): " << strTree.minimum() << std::endl;
  
  std::cout << "\nMaximum value of binary tree (type int): " << intTree.maximum() << std::endl;
  std::cout << "Maximum value of binary tree (type char): " << charTree.maximum() << std::endl;
  std::cout << "Maximum value of binary tree (type string): " << strTree.maximum() << std::endl;

#else
  std::cout << "Skipping minimum and maximum values of trees." << std::endl;
#endif

#ifdef ROOT_LEAF_TREES
  std::cout << "\n\nPrinting root-leaf paths (type int):" << std::endl;
  intTree.printRootToLeafPaths();

  std::cout << "\nPrinting root-leaf paths (type char):" << std::endl;
  charTree.printRootToLeafPaths();

  std::cout << "\nPrinting root-leaf paths (int bst tree):" << std::endl;
  bst.printRootToLeafPaths();

  std::cout << "\nPrinting root-leaf paths (type string):" << std::endl;
  strTree.printRootToLeafPaths();
  
#else
  std::cout << "Skipping root-leaf paths for trees." << std::endl;
#endif

#ifdef PATH_SUM_TO_TREES
  std::cout << "\n\n";
  
  intTree.display();
  
  std::cout << "\nDoes some path sum to 20 (int tree): "
	    << intTree.doesSomePathSumTo(20) << std::endl;

  std::cout << "\nDoes some path sum to 11 (int tree): "
	    << intTree.doesSomePathSumTo(11) << std::endl;

  std::cout << "\nDoes some path sum to 12 (int tree): "
	    << intTree.doesSomePathSumTo(12) << std::endl;

  std::cout << "\nDoes some path sum to 5 (int tree): "
	    << intTree.doesSomePathSumTo(5) << std::endl;
  
#else
  std::cout << "Skipping tree path sum to checks." << std::endl;
#endif
  
  return EXIT_SUCCESS;
}
