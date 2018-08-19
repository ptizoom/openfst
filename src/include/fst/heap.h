// See www.openfst.org for extensive documentation on this weighted
// finite-state transducer library.
//
// Implementation of a heap as in STL, but allows tracking positions in heap
// using a key. The key can be used to do an in-place update of values in the
// heap.

#ifndef FST_HEAP_H_
#define FST_HEAP_H_

#include <utility>
#include <vector>

#include <fst/compat.h>
namespace fst {

// A templated heap implementation that supports in-place update of values.
//
// The templated heap implementation is a little different from the STL
// priority_queue and the *_heap operations in STL. This heap supports
// indexing of values in the heap via an associated key.
//
// Each value is internally associated with a key which is returned to the
// calling functions on heap insert. This key can be used to later update
// the specific value in the heap.
//
// T: the element type of the hash. It can be POD, Data or a pointer to Data.
// Compare: comparison functor for determining min-heapness.

    //TODO:PTZ180527 this code does not respect undefined keys...
    //add a typename  for indexes...
    template <class T, class Compare, typename ID>
class Heap {
 public:
  using Value = T;
  
  static constexpr size_t kNoKey = -1;

  // Initializes with a specific comparator.
  explicit Heap(Compare comp = Compare()) : comp_(comp), size_(0) {}

  // Inserts a value into the heap.
  unsigned int Insert(const Value &value) {
    if (size_ < values_.size()) {
      values_[size_] = value;
      pos_[key_[size_]] = size_;
    } else {
      values_.push_back(value);
      pos_.push_back(size_);
      key_.push_back(size_);
    }
    ++size_;
    return Insert(value, size_ - 1);
  }

  // Updates a value at position given by the key. The pos_ array is first
  // indexed by the key. The position gives the position in the heap array.
  // Once we have the position we can then use the standard heap operations
  // to calculate the parent and child positions.
  void Update(ID key, const Value &value) {
    const auto i = pos_[key];
    const bool is_better = comp_(value, values_[Parent(i)]);
    values_[i] = value;
    if (is_better) {
      Insert(value, i);
    } else {
      Heapify(i);
    }
  }

  // Returns the least value.
  Value Pop() {
    Value top = values_.front();
    Swap(0, size_-1);
    size_--;
    Heapify(0);
    return top;
  }

  // Returns the least value w.r.t.  the comparison function from the
  // heap.
  const Value &Top() const { return values_.front(); }

  // Returns the element for the given key.
  const Value &Get(ID key) const { return values_[pos_[key]]; }

  // Checks if the heap is empty.
  bool Empty() const { return size_ == 0; }

  void Clear() { size_ = 0; }

  size_t Size() const { return size_; }

  void Reserve(ID size) {
    values_.reserve(size);
    pos_.reserve(size);
    key_.reserve(size);
  }

  const Compare &GetCompare() const { return comp_; }

 private:
  // The following private routines are used in a supportive role
  // for managing the heap and keeping the heap properties.

  // Computes left child of parent.
  static ID Left(ID i) {
    return 2 * (i + 1) - 1;  // 0 -> 1, 1 -> 3
  }

  // Computes right child of parent.
  static ID Right(ID i) {
    return 2 * (i + 1);  // 0 -> 2, 1 -> 4
  }

  // Given a child computes parent.
  static ID Parent(ID i) {
    return (i - 1) / 2;  // 0 -> 0, 1 -> 0, 2 -> 0,  3 -> 1,  4 -> 1, ...
  }

  // Swaps a child and parent. Use to move element up/down tree. Note the use of
  // a little trick here. When we swap we need to swap:
  //
  // - the value
  // - the associated keys
  // - the position of the value in the heap
  void Swap(ID j, ID k) {
    const auto tkey = key_[j];
    pos_[key_[j] = key_[k]] = j;
    pos_[key_[k] = tkey] = k;
    using std::swap;
    swap(values_[j], values_[k]);
  }

  // Heapifies the subtree rooted at index i.
  void Heapify(ID i) {
    const auto l = Left(i);
    const auto r = Right(i);
    auto largest = (l < size_ && comp_(values_[l], values_[i])) ? l : i;
    if (r < size_ && comp_(values_[r], values_[largest])) largest = r;
    if (largest != i) {
      Swap(i, largest);
      Heapify(largest);
    }
  }

  // Inserts (updates) element at subtree rooted at index i.
  ID Insert(const Value &value, ID i) {
    ID p;
    while (i > 0 && !comp_(values_[p = Parent(i)], value)) {
      Swap(i, p);
      i = p;
    }
    return key_[i];
  }

 private:
  const Compare comp_;

  std::vector<ID> pos_;
  std::vector<ID> key_;
  std::vector<Value> values_;
  size_t size_;
};

template <class T, class Compare, typename ID>
    constexpr size_t Heap<T, Compare, ID>::kNoKey;

}  // namespace fst

#endif  // FST_HEAP_H_
