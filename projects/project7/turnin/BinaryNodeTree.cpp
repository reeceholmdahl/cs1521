/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2021
 *
 *  Implementation file for a pointer-based implementation of the ADT binary
 *  tree.
 *
 *  Adapted from pages 482-491 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *  @author Reece Holmdahl (5727889) - edited to implement project 7 requirements
 *
 *  @date 02 Apr 2021
 *
 *  @version 7.0 */

#include <algorithm> // For std::max
#include <iostream>
#include <memory>
#include <new>
#include <climits>

#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNodePtr subTreePtr) const {

   if (subTreePtr) {
      return 1 + std::max(getHeightHelper(subTreePtr->leftChildPtr),
                          getHeightHelper(subTreePtr->rightChildPtr) );
   }

   return 0;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNodePtr subTreePtr) const {

   if (subTreePtr) {
      return 1 +
         getNumberOfNodesHelper(subTreePtr->leftChildPtr) +
         getNumberOfNodesHelper(subTreePtr->rightChildPtr);
   }

   return 0;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(BinaryNodePtr subTreePtr,
                                           BinaryNodePtr newNodePtr) {

   if (!subTreePtr) {
      return newNodePtr;
   }

   if (getHeightHelper(subTreePtr->leftChildPtr) >
       getHeightHelper(subTreePtr->rightChildPtr) ) {
      subTreePtr->rightChildPtr = balancedAdd(subTreePtr->rightChildPtr,
                                              newNodePtr);
   }
   else {
      subTreePtr->leftChildPtr = balancedAdd(subTreePtr->leftChildPtr,
                                             newNodePtr);
   }

   return subTreePtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNodePtr subTreePtr) {

   if (isLeaf(subTreePtr) ) {
      subTreePtr = nullptr;
      return subTreePtr;
   }

   if (getHeightHelper(subTreePtr->leftChildPtr) >
       getHeightHelper(subTreePtr->rightChildPtr) ) {
      subTreePtr->item = subTreePtr->leftChildPtr->item;
      subTreePtr->leftChildPtr = moveValuesUpTree(subTreePtr->leftChildPtr);
   }
   else {
      subTreePtr->item = subTreePtr->rightChildPtr->item;
      subTreePtr->rightChildPtr = moveValuesUpTree(subTreePtr->rightChildPtr);
   }

   return subTreePtr;
}

/** Depth-first search of tree for item.
 *
 *  @param subTreePtr The tree to search.
 *
 *  @param target The target item to find.
 *
 *  @param success Communicate to client whether we found the target.
 *
 *  @return A pointer to the node containing the target. */
template <typename ItemType>
auto BinaryNodeTree<ItemType>::removeValue(BinaryNodePtr subTreePtr,
                                           const ItemType& target,
                                           bool& success) {

   if (!subTreePtr) {
      return BinaryNodePtr(); // A nullptr with type 'BinaryNodePtr'.
   }

   if (subTreePtr->item == target) {
      success = true;
      return moveValuesUpTree(subTreePtr);
   }

   subTreePtr->leftChildPtr = removeValue(subTreePtr->leftChildPtr,
                                          target,
                                          success);
   if (!success) {
      subTreePtr->rightChildPtr = removeValue(subTreePtr->rightChildPtr,
                                              target,
                                              success);
   }

   return subTreePtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::findNode(BinaryNodePtr subTreePtr,
                                        const ItemType& target) const {

   BinaryNodePtr returnPtr;

   if (!subTreePtr) {
      return returnPtr;
   }

   if (subTreePtr->item == target) {
      return subTreePtr;
   }

   returnPtr = findNode(subTreePtr->leftChildPtr,
                        target);
   if (!returnPtr) {
      returnPtr = findNode(subTreePtr->rightChildPtr,
                           target);
   }

   return returnPtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::copyTree(const BinaryNodePtr& subTreePtr) const {

   if (!subTreePtr) {
      return BinaryNodePtr();
   }

   // Copy tree nodes using a preorder traversal
   return std::make_shared<BinaryNode>(subTreePtr->item,
                                       copyTree(subTreePtr->leftChildPtr),
                                       copyTree(subTreePtr->rightChildPtr) );
}

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&),
                                        BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      visit(subTreePtr->item);

      preorder(visit, subTreePtr->leftChildPtr);
      preorder(visit, subTreePtr->rightChildPtr);
   }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&),
                                       BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      inorder(visit, subTreePtr->leftChildPtr);

      visit(subTreePtr->item);

      inorder(visit, subTreePtr->rightChildPtr);
   }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&),
                                         BinaryNodePtr subTreePtr) {

   if (subTreePtr) {
      postorder(visit, subTreePtr->leftChildPtr);
      postorder(visit, subTreePtr->rightChildPtr);

      visit(subTreePtr->item);
   }
}

//////////////////////////////////////////////////////////////
//      Protected Node Access Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isLeaf(BinaryNodePtr nodePtr) const {

   return !nodePtr->leftChildPtr && !nodePtr->rightChildPtr;
}

template <typename ItemType>
auto BinaryNodeTree<ItemType>::getRootPtr() const {

   return rootPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootPtr(BinaryNodePtr newRootPtr) {

   rootPtr = newRootPtr;
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
					  BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
   : rootPtr(std::make_shared<BinaryNode>(rootItem) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                                         const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
   : rootPtr(std::make_shared<BinaryNode>(rootItem,
                                          copyTree(leftTreePtr->rootPtr),
                                          copyTree(rightTreePtr->rootPtr)) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr) {

   try {
      rootPtr = copyTree(treePtr.rootPtr);
   }
   catch (const std::bad_alloc&) {
      clear();
      throw;
   }
}

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {

   return !rootPtr;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {

   return getHeightHelper(rootPtr);
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {

   return getNumberOfNodesHelper(rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::clear() {

   rootPtr.reset();
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {

   if (!isEmpty() ) {
      return rootPtr->item;
   }

   std::string message("BinaryNodeTree::getRootData: called ");
   message += "on an empty tree.";

   throw PrecondViolatedExcep(message);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem) {

   if (isEmpty() ) {
      try {
         rootPtr = std::make_shared<BinaryNode>(newItem);
      }
      catch (const std::bad_alloc&) {
         // What should we do with this? Return something? Throw a
         // different type of exception? Crash?
      }
   }
   else {
      rootPtr->item = newItem;
   }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {

   try {
      rootPtr = balancedAdd(rootPtr,
                            std::make_shared<BinaryNode>(newData) );
   }
   catch (const std::bad_alloc&) {
      return false;
   }

   return true;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target) {

   bool isSuccessful(false);

   rootPtr = removeValue(rootPtr, target, isSuccessful);

   return isSuccessful;
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const {

   auto binaryNodePtr(findNode(rootPtr, anEntry) );

   if (binaryNodePtr) {
      return binaryNodePtr->item;
   }

   std::string message("BinaryNodeTree::getEntry: Entry ");
   message += "not found in this tree.";

   throw NotFoundException(message);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const ItemType& anEntry) const {

   return findNode(rootPtr, anEntry) != nullptr;
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&) ) {

   preorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&) ) {

   inorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&) ) {

   postorder(visit, rootPtr);
}

//////////////////////////////////////////////////////////////
//      Overloaded Operator
//////////////////////////////////////////////////////////////

template <typename ItemType>
BinaryNodeTree<ItemType>&
BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rhs) {

   auto oldTreePtr(rootPtr);

   if (this != &rhs) {
      try {
         rootPtr = copyTree(rhs.rootPtr);
      }
      catch (const std::bad_alloc&) {
         rootPtr = oldTreePtr;
         throw;
      }
   }

   return *this;
}

/** Recursive display tree helper method. */
template <typename ItemType>
void BinaryNodeTree<ItemType>::displayTree(BinaryNodePtr nodePtr, int depth) const {
  
  if (nodePtr->rightChildPtr) {
    displayTree(nodePtr->rightChildPtr, depth + 1);
  }

  for (int i(0); i < depth; ++i) {
    std::cout << "  ";
  }
  
  std::cout << nodePtr->item << std::endl;

  if (nodePtr->leftChildPtr) {
    displayTree(nodePtr->leftChildPtr, depth + 1);
  }
  
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::display() const {
  displayTree(rootPtr, 0);
}

/** Recursive mirror binary tree helper method. */
template <typename ItemType>
void BinaryNodeTree<ItemType>::mirrorTree(BinaryNodePtr nodePtr) {

  if (nodePtr->leftChildPtr) {
    mirrorTree(nodePtr->leftChildPtr);
  }

  if (nodePtr->rightChildPtr) {
    mirrorTree(nodePtr->rightChildPtr);
  }

  BinaryNodePtr temp(nodePtr->leftChildPtr);

  nodePtr->leftChildPtr = nodePtr->rightChildPtr;
  nodePtr->rightChildPtr = temp;
  
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::mirror() {
  mirrorTree(rootPtr);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isBinarySearchTree(BinaryNodePtr nodePtr, int greaterThan, int lessThan) const {

  if (!nodePtr) return true;

  bool leftBST(true);
  if (nodePtr->leftChildPtr) {
    if (nodePtr->leftChildPtr->item <= nodePtr->item
	&& nodePtr->leftChildPtr->item >= greaterThan
	&& nodePtr->leftChildPtr->item <= lessThan) {
      leftBST = isBinarySearchTree(nodePtr->leftChildPtr, greaterThan, nodePtr->item);
    } else {
      return false;
    }
  }
  
  bool rightBST(true);
  if (nodePtr->rightChildPtr) {
    if (nodePtr->rightChildPtr->item >= nodePtr->item
	&& nodePtr->rightChildPtr->item >= greaterThan
	&& nodePtr->rightChildPtr->item <= lessThan) {
      rightBST = isBinarySearchTree(nodePtr->rightChildPtr, nodePtr->item, lessThan);
    } else {
      return false;
    }
  }

  return leftBST && rightBST;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isBST() const {
  return isBinarySearchTree(rootPtr, std::numeric_limits<int>::min(), std::numeric_limits<int>::max() );
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMinimum(BinaryNodePtr nodePtr, ItemType parent) const {

  if (!nodePtr) return parent;

  ItemType min(nodePtr->item < parent ? nodePtr->item : parent);
  ItemType left = findMinimum(nodePtr->leftChildPtr, min);
  ItemType right = findMinimum(nodePtr->rightChildPtr, min);

  return std::min(std::min(left, right), min);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::minimum() const {

  if (!rootPtr) {
    throw PrecondViolatedExcep("Cannot find a maximum value in an empty tree.");
  }
  
  return findMinimum(rootPtr, rootPtr->item);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMaximum(BinaryNodePtr nodePtr, ItemType parent) const {
  
  if (!nodePtr) return parent;

  ItemType max(nodePtr->item > parent ? nodePtr->item : parent);
  ItemType left = findMaximum(nodePtr->leftChildPtr, max);
  ItemType right = findMaximum(nodePtr->rightChildPtr, max);

  return std::max(std::max(left, right), max);
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::maximum() const {

  if (!rootPtr) {
    throw PrecondViolatedExcep("Cannot find a maximum value in an empty tree.");
  }
  
  return findMaximum(rootPtr, rootPtr->item);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::printPaths(BinaryNodePtr nodePtr, ItemType path[], int depth) const {
  if (nodePtr) {
    path[depth] = nodePtr->item;
    printPaths(nodePtr->leftChildPtr, path, depth + 1);
    printPaths(nodePtr->rightChildPtr, path, depth + 1);

    if (!nodePtr->leftChildPtr && !nodePtr->rightChildPtr) {
      for (int i(0); i <= depth; ++i) {
	std::cout << path[i] << ' ';
      }
      std::cout << std::endl;
    }
  }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::printRootToLeafPaths() const {
  ItemType path[getHeight()];
  printPaths(rootPtr, path, 0);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesPathSumTo(BinaryNodePtr nodePtr, int checkSum, int sum) const {

  if (!nodePtr) {
    return false;
  }
  
  if (!nodePtr->leftChildPtr && !nodePtr->rightChildPtr) {
    return sum + nodePtr->item == checkSum;
  } else {
    bool left(doesPathSumTo(nodePtr->leftChildPtr, checkSum, sum + nodePtr->item));
    bool right(doesPathSumTo(nodePtr->rightChildPtr, checkSum, sum + nodePtr->item));
    return left || right;
  }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesSomePathSumTo(int sum) const {
  return doesPathSumTo(rootPtr, sum, 0);
}
