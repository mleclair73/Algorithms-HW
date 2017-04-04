/**
* Assignment 3b EECE 2560													Ningfang Mi
* March 22, 2017															ningfang@ece.neu.edu
* Malcolm Leclair & Erik Gentile
*
* Declaration of heap template class. Contains declarations and
* definitions parent(), left(), right(), getItem(), initializeMaxHeap(),
* maxHeapify(), buildMaxHeap(), and heapSort()
**/

#ifndef HEAP_CLASS
#define HEAP_CLASS

#include <vector>

using namespace std;

template<typename T>
class heap
{
  private:
    // heap is implemented as a vector type T
    vector<T> heapVector;

	// heapSize = number of elements in the heap
	int heapSize;

  public:

    // returns the parent of an element in the heap
    int parent(const int &n);

    // returns the left child of an element in the heap
    int left(const int &n);

    // returns the right child of an element in the heap
    int right(const int &n);

    // returns the nth element of the heap
    T getItem(const int &n);

    // MAX MEAP FUNCTIONS //
    // initialize max heap
	   void initializeMaxHeap(const vector<T> &vect);

    // builds max heap out of unsorted vector
    void buildMaxHeap();

    // maxHeapify
    void maxHeapify(const int &n);

    // sort heap using heapsort
    void heapSort(const vector<T> &vect);

};


template<typename T>
int heap<T>::parent(const int&n)
{
	return floor(n / 2);
}

template<typename T>
int heap<T>::left(const int &n)
{
	return 2*n;
}

template<typename T>
int heap<T>::right(const int &n)
{
	return 2*n + 1;
}

template<typename T>
T heap<T>::getItem(const int&n)
{
	return heapVector.at(n);
}

// ensures that the heap is a Max Heap starting at element n,
// and recurring  down if any changes are made
template<typename T>
void heap<T>::maxHeapify(const int &n)
{
  int l = left(n);
	int r = right(n);
	int largest;

	if ((l <= heapSize) && (heapVector.at(l) > heapVector.at(n)))
	{
		largest = l;
	}

	else
	{
		largest = n;
	}

	if ((r <= heapSize) && (heapVector.at(r)) > (heapVector.at(largest)))
	{
		largest = r;
	}

	if (largest != n)
	{
		swap(heapVector.at(n), heapVector.at(largest));

		maxHeapify(largest);
	}
	// int l = left(n);
	// int r = right(n);
	// int largest = 0;
  //
	// if ((l <= heapSize) && (heapVector.at(l) > heapVector.at(n)))
	// {
	// 	largest = l;
	// }
	// else
	// {
	// 	largest = n;
	// }
  // if ((r <= heapSize) && (heapVector.at(r)) > (heapVector.at(largest)))
	// {
	// 	largest = r;
	// }
  //
  // // if the parent is not the largest, swap the parent and the largest
	// if (largest != n)
	// {
	// 	swap(heapVector.at(n), heapVector.at(largest));
  //
  //   // apply max heapify down the heap from the prev position of largest
	// 	maxHeapify(largest);
	// }
}

// converts the values stored in heapVector to a Max Heap using
// maxHeapify
template<typename T>
void heap<T>::buildMaxHeap()
{
	heapSize = heapVector.size() - 1;

	for (int i = floor(heapVector.size()/2); i >= 1; i--)
	{
		maxHeapify(i);
	}

}

// take a vector and convert it into a Max Heap
template<typename T>
void heap<T>::initializeMaxHeap(const vector<T> &vect)
{
  // null first value
	heapVector.push_back("");

  // fill heap with values from the vector vect
	for (int i = 0; i < vect.size(); i++)
	{
		heapVector.push_back(vect[i]);
	}
  // turn the heap vector into a Max Heap
	buildMaxHeap();
}

// sort a vector in increasing order using Max Heap
template<typename T>
void heap<T>::heapSort(const vector<T> &vect)
{
	initializeMaxHeap(vect);

  // for all but the last two elements of the heap
	for (int i = heapVector.size()-1; i >= 2; i--)
	{
    // place the largest element at the end of the heap,
    // shrink the heap and ensure the heap is still a max heap
		swap(heapVector.at(1), heapVector.at(i));
		heapSize--;
		maxHeapify(1);
		// counting from zero or 1??
	}
}// end heapSort

#endif //HEAP_CLASS
