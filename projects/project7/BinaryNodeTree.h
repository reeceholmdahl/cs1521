/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Header file for a pointer-based implementation of the ADT binary
 *  tree.
 *
 *  Adapted from pages 480-482 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Reece Holmdahl (5727889) - Edited to implement project7 methods
 *
 *  @date 02 Apr 2021
 *
 *  @version 7.0 */

#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>

#include "BinaryTreeInterface.h"

/** @class BinaryNodeTree BinaryNodeTree.h "BinaryNodeTree.h"
 *
 *  Specification of a link-based ADT binary tree. */
template <typename ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
protected:
   class BinaryNode;

   using BinaryNodePtr = std::shared_ptr<BinaryNode>;

private:
   BinaryNodePtr rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------

   int getHeightHelper(BinaryNodePtr subTreePtr) const;

   int getNumberOfNodesHelper(BinaryNodePtr subTreePtr) const;

   // Recursively adds a new node to the tree in a left/right fashion to
   // keep the tree balanced.
   auto balancedAdd(BinaryNodePtr subTreePtr,
                    BinaryNodePtr newNodePtr);

   // Removes the target value from the tree by calling moveValuesUpTree
   // to overwrite value with value from child.
   auto removeValue(BinaryNodePtr subTreePtr,
                    const ItemType& target,
                    bool& success);

   // Copies values up the tree to overwrite value in current node until
   // a leaf is reached; the leaf is then removed, since its value is
   // stored in the parent.
   auto moveValuesUpTree(BinaryNodePtr subTreePtr);

   // Recursively searches for target value in the tree by using a
   // preorder traversal.
   auto findNode(BinaryNodePtr treePtr,
                 const ItemType& target) const;

   // Copies the tree rooted at treePtr and returns a pointer to
   // the copy.
   auto copyTree(const BinaryNodePtr& treePtr) const;

   // Recursive traversal helper methods:
   void preorder(void visit(ItemType&),
                 BinaryNodePtr treePtr);
   void inorder(void visit(ItemType&),
                BinaryNodePtr treePtr);
   void postorder(void visit(ItemType&),
                  BinaryNodePtr treePtr);

  // Tools for manipulating BinaryNodes:

   bool isLeaf(const BinaryNodePtr nodePtr) const;

   auto getRootPtr() const;
   void setRootPtr(BinaryNodePtr newRootPtr);

  // Recursive helper for displayBinaryTree()
  void displayTree(BinaryNodePtr nodePtr, int depth = 0) const;

  // Recursive helper method for mirror()
  void mirrorTree(BinaryNodePtr nodePtr);

  // Recursive helper method for isBST()
  bool isBinarySearchTree(BinaryNodePtr nodePtr, int greaterThan, int lessThan) const;

  // Recursive helper method for minimum()
  ItemType findMinimum(BinaryNodePtr nodePtr, ItemType parent) const;

  // Recursive helper method for maximum()
  ItemType findMaximum(BinaryNodePtr nodePtr, ItemType parent) const;

  // Recursive helper method for printRootToLeafPaths()
  void printPaths(BinaryNodePtr nodePtr, ItemType path[], int depth) const;

  // Recursive helper method for doesSomePathSumTo()
  bool doesPathSumTo(BinaryNodePtr nodePtr, int checkSum, int sum) const;

public:
  //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree() = default;

   explicit BinaryNodeTree(const ItemType& rootItem);

   BinaryNodeTree(const ItemType& rootItem,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                  const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);

   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);

   ~BinaryNodeTree() override = default;

   //------------------------------------------------------------
   // Public BinaryTreeInterface Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const override;

   int getHeight() const override;

   int getNumberOfNodes() const override;

   ItemType getRootData() const override;

   void setRootData(const ItemType& newData) override;

   bool add(const ItemType& newData) override;

   bool remove(const ItemType& data) override;

   void clear() override;

   ItemType getEntry(const ItemType& anEntry) const override;

   bool contains(const ItemType& anEntry) const override;

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&) ) override;
   void inorderTraverse(void visit(ItemType&) ) override;
   void postorderTraverse(void visit(ItemType&) ) override;

   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinaryNodeTree& operator=(const BinaryNodeTree& rhs);

  /** Displays the binary tree. */
  void display() const;

  /** Flips/mirrors the binary tree. */
  void mirror();

  /** Tests if this binary tree is a binary search tree (BST). */
  bool isBST() const;

  /** Minimal valued item of this binary tree. */
  ItemType minimum() const;

  /** Maximum valued item of this binary tree. */
  ItemType maximum() const;

  /** Print root-leaf paths. */
  void printRootToLeafPaths() const;

  /** Does some path sum to some value? */
  bool doesSomePathSumTo(int sum) const;
};

#include "BinaryNode.h"

#include "BinaryNodeTree.cpp"

#endif
