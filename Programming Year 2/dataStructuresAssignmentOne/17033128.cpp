//name the file using your student ID
//e.g 012345678.cpp


// do not change the declaration section !
#include <iostream>
using namespace std;

class Node
{
public:
	Node(int value, Node* nextptr = nullptr, Node* prevptr = nullptr,
		int currentpriority = 0);

	int getVal(void);

	Node* getNext(void);

	Node* getPrev(void);

	void setVal(int value);

	void setPrev(Node* prevptr);

	void setNext(Node* nextptr);

	int getPriority(void);

	void setPriority(int priority);


private:
	Node* next;
	Node* prev;
	int priority;
	int value;
};

class Stack
{
public:
	Stack(void);

	~Stack(void);

	void Push(int value);

	Node* NodePop(void);

	int Pop(void);

private:

	Node* top;
};

class Queue
{
public:
	Queue(void);

	~Queue(void);

	void virtual Enqueue(int i, int priority = 1);

	int virtual Dequeue(void);

protected:

	Node* back;
	Node* front;

private:

	virtual Node* NodeDequeue(void);
};

class Scheduler : public Queue {
public:

	void Enqueue(int value, int priority = 0) override;
	int Dequeue() override;
	//you can only overide PUBLIC methods from the Queue class
private:
	//you can add private methods and attributes
	Node* NodeDequeue(void);
};

//-------------------------------YOUR implementation goes here!!!-----------------------

/*
	---NODE---
*/

// Constructor initializes the node with given value, next pointer, previous pointer, and priority
Node::Node(int value, Node* nextptr, Node* prevptr, int currentpriority)
	: value(value), next(nextptr), prev(prevptr), priority(currentpriority) {
}

// Returns the value of the node
int Node::getVal(void) {
	return value;
}

// Returns the next node pointer;
Node* Node::getNext(void) {
	return next;
}

// Returns the previous node pointer
Node* Node::getPrev(void) {
	return prev;
}

// Sets the value of the node.
void Node::setVal(int value) {
	this->value = value;
}

// Sets the previous node pointer
void Node::setPrev(Node* prevptr) {
	this->prev = prevptr;
}

// Sets the next node pointer
void Node::setNext(Node* nextptr) {
	this->next = nextptr;
}

// Returns the priority of the node
int Node::getPriority(void) {
	return priority;
}

// Sets the priority of the node
void Node::setPriority(int priority) {
	this->priority = priority;
}

/*
	---STACK---
*/

// Constructor initializes the top pointer to nullptr
Stack::Stack(void) : top(nullptr) {
}

// Destructor deallocates all nodes in the stack
Stack::~Stack(void) {
	while (top != nullptr) { // Loop until the stack is empty
		Node* temp = top; // Store the current top node
		top = top->getNext(); // Move top to the next node
		delete temp; // Delete the old top node
	}
}

// Push method adds a new node with given value to the top of the stack;
void Stack::Push(int value) {
	Node* newNode = new Node(value, top); // Create a new node
	top = newNode; // Set top to the new node
}

// NodePop method removes and returns the top node
Node* Stack::NodePop(void) {
	if (top == nullptr) throw "Empty stack."; // Throw exception if the stack is empty
	Node* temp = top; // Store the current top node
	top = top->getNext(); // Move top to the next node
	return temp; // Return the old top node
}

// Pop method removes and returns the value of the top node
int Stack::Pop(void) {
	Node* temp = NodePop(); // Get the top node
	int value = temp->getVal(); // Get the value of the top node
	delete temp; // Delete the top node
	return value; // Return the value
}

/*
	---QUEUE---
*/

// Constructor initializes front and back pointers to nullptr
Queue::Queue(void) : front(nullptr), back(nullptr){
}

// Destructor deallocates all nodes in the queue
Queue::~Queue(void) {
	while (front != nullptr) { // Loop until the queue is empty
		Node* temp = front; // Store the current front node
		front = front->getNext(); // Move front to the next node
		delete temp; // Delete the old front node
	}
}

// Enqueue method adds a new node with given value and priority to the back of the queue
void Queue::Enqueue(int i, int priority) {
	Node* newNode = new Node(i, nullptr, back, priority); // Create a new node
	if (back != nullptr) { // If the queue is not empty
		back->setNext(newNode); // Link the current back node to the new node
	} else { 
		front = newNode; // If the queue is empty, set front to the new node
	}
	back = newNode; // Set back to the new node
}

// Dequeue method removes and returns the value of the front node
int Queue::Dequeue(void) {
	try {
		Node* temp = NodeDequeue(); // Get the front node
		int value = temp->getVal(); // Get the value of the front node
		delete temp; // Delete the front node
		return value; // Return the value
	}
	catch (const char* e) { // Catch exception if the queue is empty
		cerr << e << endl; // Print the error message
		return -1; // Return -1 to indicate an error
	}
}

// NodeDequeue method removes and returns the front node.
Node* Queue::NodeDequeue(void) {
	if (front == nullptr) throw "Empty queue."; // Throw exception if the queue is empty
	Node* temp = front; // Store the current front node
	front = front->getNext(); // Move front to the next node
	if (front != nullptr) { // If the queue is not empty
		front->setPrev(nullptr); // Set the previous pointer of the new front node to nullptr
	} else { 
		back = nullptr; // If the queue is empty, set back to nullptr
	}
	return temp; // Return the old front node
}



// ************************** Scheduler ***************************************
// 
// depending on your implementation you may override any PUBLIC methods INHERITED from the Queue class
// as well as add ANY private methods in Scheduler class

//O(n) miserably slow... needs to be optimised using a binary heap but I can't figure it out on time

// Enqueue method to add a new node with given value and priority to the queue;
void Scheduler::Enqueue(int value, int priority) {

	// Create a new node with the given value and priority, and set its previous pointer to the current back node
	Node* newNode = new Node(value, nullptr, back, priority);

	// If the queue is empty, set both front and back pointers to the new node
	if (back == nullptr) {
		front = back = newNode;
	}
	else {
		// Otherwise, link the current back node to the new node and update the back pointer
		back->setNext(newNode);
		newNode->setPrev(back);
		back = newNode;
	}
}

// Dequeue method to remove and return the value of the node with the highest priority
int Scheduler::Dequeue() {
	// Check if the queue is empty
	if (front == nullptr) {
		throw "Error: Empty"; //exception handling
		return -1; // Return an invalid process ID to indicate an error
	}

	// Find the node with the highest priority.
	Node* highestPriorityNode = NodeDequeue();
	int processID = highestPriorityNode->getVal(); // Get the procss ID of the highest priority node
	delete highestPriorityNode; // Delete the highest priority node
	return processID; // Return the process ID
}

// NodeDequeue method to find and remove the node with the highest priority;
Node* Scheduler::NodeDequeue() {
	// Check if the queue is empty
	if (front == nullptr) throw "Empty queue."; // Throw an exception if the queue is empty

	// Initialize the highest priority node as the front node
	Node* highestPriorityNode = front;
	Node* selectedNode = front->getNext(); // Start with the next node.

	// Traverse the queue to find the node with the highest priority
	while (selectedNode != nullptr) {
		// Update the highest priority node if a node with a higher priority is found
		if (selectedNode->getPriority() > highestPriorityNode->getPriority()) {
			highestPriorityNode = selectedNode;
		}
		selectedNode = selectedNode->getNext(); // Moveto the next node
	}

	// Remove the highest priority node from the queue.
	if (highestPriorityNode->getPrev() != nullptr) {
		// If the highest priority node is not the front node, update the previous node's next pointer
		highestPriorityNode->getPrev()->setNext(highestPriorityNode->getNext());
	}
	else {
		// If the highest priority node is the front node, update the front pointer
		front = highestPriorityNode->getNext();
	}

	if (highestPriorityNode->getNext() != nullptr) {
		// If the highest priority node is not the back node, update the next node's previous pointer
		highestPriorityNode->getNext()->setPrev(highestPriorityNode->getPrev());
	}
	else {
		// If the highest priority node is the back node, update the back pointer.
		back = highestPriorityNode->getPrev();
}


	return highestPriorityNode; // Return the highest priority node
}


//-------------------------------YOUR implementation ends here!!!!-----------------------



//----------------------------- YOUR code testing --------------------------
// comment out or delete this section AFTER you finished your testing

#include <time.h>       /* time */
#include <chrono>
#include <cstdlib>

using namespace std::chrono;

void stackBasicTest(int COUNT, int input[]) {
	std::cout << "01. STACK BASIC TEST\n";

	Stack myStack;
	std::cout << "Push: \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << input[i] << " ";
		myStack.Push(input[i]);
	}
	std::cout << "\nPop:  \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << myStack.Pop();
		std::cout << " ";
	}
}

void stackEmptyExceptionTest(int COUNT, int input[]) {
	Stack myStack;
	std::cout << "\n\n02. EMPTY STACK EXCEPTION TEST\n";
	myStack.Push(1);
	try {
		myStack.Pop();
		myStack.Pop();
	}
	catch (const char* msg) {
		std::cout << msg << endl;
	}
}

void queueBasicTest(int COUNT, int input[]) {
	std::cout << "\n\n03. QUEUE BASIC TEST\n";
	Queue myQueue;
	std::cout << "Enqueue: \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << input[i] << " ";
		myQueue.Enqueue(input[i]);
	}
	std::cout << "\nDequeue: \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << myQueue.Dequeue();
		std::cout << " ";
	}
}

void queueEmptyExceptionTest(int COUNT, int input[]) {
	Queue myQueue;
	std::cout << "\n\n04. EMPTY QUEUE EXCEPTION TEST\n";
	myQueue.Enqueue(1);
	try {
		myQueue.Dequeue();
		myQueue.Dequeue();
	}
	catch (const char* msg) {
		std::cout << msg << endl;
	}
}

void schedulerBasicTest(int COUNT, int input[]) {
	std::cout << "\n\n05. SCHEDULER BASIC TEST\n";
	Scheduler myScheduler;
	std::cout << "Enqueue: \n";
	for (int i = 0; i < COUNT; i++) {
		myScheduler.Enqueue(input[i], input[i]);
		std::cout << input[i] << " ";
	}
	std::cout << "\nDequeue: \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << myScheduler.Dequeue();
		std::cout << " ";
	}
}

void schedulerPriorityRangeTest() {
	std::cout << "\n\n06. SCHEDULER PRIORITY RANGE TEST\n";
	Scheduler myScheduler;
	std::cout << "Enqueue(1,11): ";
	try {
		myScheduler.Enqueue(1, 11);
		std::cout << myScheduler.Dequeue();
	}
	catch (const char* msg) {
		std::cout << msg << endl;
	}
}

void schedulerEmptyExceptionTest() {
	Scheduler myScheduler;
	std::cout << "\n\n07. EMPTY SCHEDULER EXCEPTION TEST\n";
	myScheduler.Enqueue(1, 1);
	try {
		myScheduler.Dequeue();
		myScheduler.Dequeue();
	}
	catch (const char* msg) {
		std::cout << msg << endl;
	}
}

void schedulerBlockingTest(int COUNT, int input[]) {
	Scheduler myScheduler;
	std::cout << "\n\n08. SCHEDULER BLOCKING TEST\n";
	std::cout << "Enqueue: \n";
	for (int i = 0; i < COUNT; i++) {
		myScheduler.Enqueue(input[i], input[i]);
		std::cout << input[i] << " ";
	}
	std::cout << endl;
	for (int i = 0; i < 100; i++) {
		std::cout << "\rEnqueue: 10 ";
		myScheduler.Enqueue(10, 10);
		std::cout << "  Dequeue: ";
		std::cout << myScheduler.Dequeue();
		std::cout << " ";
	}
	std::cout << "\nBlocked items: \n";
	for (int i = 0; i < COUNT; i++) {
		std::cout << myScheduler.Dequeue() << " ";
	}
}

void schedulerPerformanceTest(int COUNT, int input[]) {
	cout << "\n\n09. SCHEDULER PERFOMANCE TEST\n";
	int qSize = 1000000;
	int duration1 = 0;
	int duration2 = 0;
	int x = 0;

	cout << "Initializing Scheduler 1 with " << COUNT << " Elements\n";
	Scheduler myScheduler1;
	for (int i = 0; i < qSize; i++) {
		for (int i = 0; i < COUNT; i++) {
			myScheduler1.Enqueue(input[i], input[i]);
			//cout << input[i] << " ";
		}
	}

	cout << "initializing Scheduler 2 with " << COUNT << " Elements\n";
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	myScheduler1.Enqueue(10, 10);
	x = myScheduler1.Dequeue();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout << "\nDequeue = " << x << " Time used : " << duration1 << " microseconds." << endl << endl;

	Scheduler myScheduler2;
	qSize = 2 * qSize;
	for (int i = 0; i < qSize; i++) {
		for (int i = 0; i < COUNT; i++) {
			myScheduler2.Enqueue(input[i], input[i]);
			//cout << input[i] << " ";
		}
	}


	t1 = high_resolution_clock::now();
	myScheduler2.Enqueue(10, 10);
	x = myScheduler2.Dequeue();
	t2 = high_resolution_clock::now();
	duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	cout << "\nDequeue = " << x << " Time used : " << duration2 << " microseconds." << endl << endl;

	double ratio = (double)duration2 / duration1;
	std::cout << "ratio: " << ratio;
}

int main(void) {
	int const COUNT = 20;
	int input[COUNT] = { 1,2,3,4,5,9,8,7,6,10, 1,2,3,4,5,9,8,7,6,10 };

    stackBasicTest(COUNT, input);
    stackEmptyExceptionTest(COUNT, input);
    queueBasicTest(COUNT, input);
    queueEmptyExceptionTest(COUNT, input);
    schedulerBasicTest(COUNT, input);
    schedulerPriorityRangeTest();
    schedulerEmptyExceptionTest();
    schedulerBlockingTest(COUNT, input);
    schedulerPerformanceTest(COUNT, input);
    getchar();
}

