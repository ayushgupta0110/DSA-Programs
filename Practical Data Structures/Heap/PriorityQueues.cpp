// C++ code to implement priority-queue using array implementation of binary heap
#include<iostream>
using namespace std;

int H[50];
int size = -1;

int parent(int i){
	return (i - 1) / 2;
}

int leftChild(int i){
	return ((2 * i) + 1);
}

int rightChild(int i){
	return ((2 * i) + 2);
}

void shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i]) {
		// Swap parent and current node
		swap(H[parent(i)], H[i]);

		// Update i to parent of i
		i = parent(i);
	}
}

void shiftDown(int i)
{
	int maxIndex = i;

	// Left Child
	int l = leftChild(i);

	if (l <= size && H[l] > H[maxIndex]) {
		maxIndex = l;
	}

	// Right Child
	int r = rightChild(i);

	if (r <= size && H[r] > H[maxIndex]) {
		maxIndex = r;
	}

	// If i not same as maxIndex
	if (i != maxIndex) {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}

void insert(int p)
{
	size = size + 1;
	H[size] = p;

	// Shift Up to maintain heap property
	shiftUp(size);
}

int extractMax()
{
	int result = H[0];

	// Replace the value at the root
	// with the last leaf
	H[0] = H[size];
	size = size - 1;

	// Shift down the replaced element
	// to maintain the heap property
	shiftDown(0);
	return result;
}

// Function to change the priority
// of an element
void changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

int getMax(){
	return H[0];
}

void remove(int i)
{
	H[i] = getMax() + 1;

	shiftUp(i);

	// Extract the node
	extractMax();
}

int main()
{
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	// Priority queue before extracting max
	cout << "Priority Queue : ";
	while (i <= size) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	// Node with maximum priority
	cout << "Node with maximum priority : "
		<< extractMax() << "\n";

	// Priority queue after extracting max
	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= size) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";

	// Change the priority of element
	// present at index 2 to 49
	changePriority(2, 49);
	cout << "Priority queue after "
		<< "priority change : ";
	int k = 0;
	while (k <= size) {
		cout << H[k] << " ";
		k++;
	}

	cout << "\n";

	// Remove element at index 3
	remove(3);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= size) {
		cout << H[l] << " ";
		l++;
	}
	return 0;
}
