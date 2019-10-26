/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (curDim < 0 || curDim >= Dim) {
       return false;
     } else if (first[curDim] > second[curDim]) {
       return false;
     } else if (first[curDim] < second[curDim]) {
       return true;
     } else {
       return first < second;
     }
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     double current_dist = 0.0;
     double potential_dist = 0.0;

     for (unsigned i = 0; i < Dim; i++) {
       current_dist += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
       potential_dist += (potential[i] - target[i]) * (potential[i] - target[i]);
     }

     if (potential_dist > current_dist) {
       return false;
     } else if (potential_dist < current_dist) {
       return true;
     } else {
       return potential < currentBest;
     }
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

     if (newPoints.empty()) {
       size = 0;
       root = NULL;
     } else {
       size = 0;
       vector<Point<Dim>> points = newPoints;
       build(points, 0, points.size() - 1, root, 0);
     }

}


template <int Dim>
void KDTree<Dim>::build(vector<Point<Dim>>& newPoints, int left, int right, KDTreeNode*& subroot, int size_) {

  if (left > right) {
    return;
  }

  size_t median = (left + right) / 2;

  Point<Dim> temp = select(newPoints, left, right, median, size_);
  subroot = new KDTreeNode(temp);

  size++;

  build(newPoints, left, median - 1, subroot->left, (size_ + 1) % Dim);
  build(newPoints, median + 1, right, subroot->right,(size_ + 1) % Dim);
}

template <int Dim>
Point<Dim> KDTree<Dim>::select(vector<Point<Dim>>& newPoints_, int left, int right, size_t limit, int size_) {

  if (left == right) {// if only 1 element present
    return newPoints_[left];
  }

  size_t pivotIndex = (left + right) / 2;
  pivotIndex = partition(newPoints_, left, right, pivotIndex, size_);

  if (limit == pivotIndex) {
    return newPoints_[limit];
  } else if (limit < pivotIndex){
    return select(newPoints_, left, pivotIndex - 1, limit, size_);
  } else {
    return select(newPoints_, pivotIndex + 1, right, limit, size_);
  }

}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& newPoints_, int left, int right, size_t pivotIndex, int size_) {

  Point<Dim> pivot = newPoints_[pivotIndex];

  swap(newPoints_[pivotIndex], newPoints_[right]);

  size_t index = left;

  for (unsigned i = left; i < right; i++) {
    if (smallerDimVal(newPoints_[i], pivot, size_) == true) {
      swap(newPoints_[index], newPoints_[i]);
      index++;
    }
  }

  swap(newPoints_[right], newPoints_[index]);
  return index;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

     return Point<Dim>();
}
