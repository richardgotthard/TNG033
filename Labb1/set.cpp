#include "set.hpp"

// Default constructor




//skapar en nod som sätter sig på samma plats som första noden (dummyn)
Set::Set() 
{
	head = new Node(0, nullptr);
    // implement before HA session week 46
}

// Constructor for creating a set from an int

//sätter in ett huvud vid punkten v
Set::Set(int v): Set()
{
	insert(head, v);
    // implement before HA session week 46
}
//insert nod vid visst value
void Set::insert(Node* p, int value) const {
    
	p->next = new Node(value, p->next);

}   
//will insert value last
void Set::insert(int value) const {

	Node* ptr = head;
	
	while ((ptr->next != nullptr) && (ptr->next->value < value)) {
		ptr = ptr->next;
	} 

	if (ptr->next == nullptr || ptr->next->value != value) {

		insert(ptr, value);
	}

}
//deletes node by pointing to a point
void Set:: remove(Node* p) {

	delete p;
}

// Constructor creating a set
// of a sorted array of n intgers
Set::Set(const int a[], int n) : Set()
{
	for (int i = 0; i < n; i++) {
		insert(a[i]);
	}
   
}

// copy constructor
//adds another set into a set
Set::Set(const Set& source) : Set()
{
	
	Node* p = source.head->next;
	Node* newCopy = head;

	while (p != nullptr) {
		insert(newCopy, p->value);
		newCopy = newCopy->next;
			p = p->next;
	}
    // Add code
    // implement before HA session week 46
}

// Destructor: deallocate all nodes
// deallocates automatically
Set::~Set() 
{ 
	Node* current = head;
	Node* next;

	while (current != NULL) {
		next = current->next;
		remove(current);
		current = next;
	}
    // implement before HA session week 46
}

// Test if set is empty
// returns true or false depending if the function is empty or not
bool Set::empty() const 
{
    // implement before HA session week 
	return (head->next == nullptr);
}

// Return number of elements in the set
// shows how many sets are in the function
int Set::cardinality() const 
{
	int howMany = 0;

	Node* curr = head->next;

	while (curr != nullptr) {
		curr = curr->next;
		howMany++;
	}

	return howMany;
}

// Test if x is an element of the set
bool Set::member(int x) const 
{

	Node* refr = head->next;

	while((refr != nullptr) && (refr->value != x))
	{
		refr = refr->next;
	}

	if (refr == nullptr) {
		return false;
	}
	else {
		return true;
	}
    // implement before HA session week 46
}

// Assignment operator
Set& Set::operator=(Set s){


	std::swap(head, s.head);

	return *this;
}
// looks if the set is bigger or the smaller then the other set
bool Set::operator<=(const Set& b) const 
{

	Set set1 = b;
	Node* temp = head->next;

	while (temp != nullptr) {
		if (!set1.member(temp->value)) {
			
			return false;
		}

		temp = temp->next;
	}
    
	return true;
}
//checks if the set is the same as the other set
bool Set::operator==(const Set& b) const 
{	
	Set temp = *this;

	if (temp <= b && b <= temp) {
		return true;
	}
	else { 
		return false;
	}
	
}
//looks if the set is the same
bool Set::operator!=(const Set& b) const 
{
	Set temp = *this;

	if ((temp == b) == false) {
		return true;
	}
	else {
		return false;
	}
 
}
//checks if the set is smaller or not
bool Set::operator<(const Set& b) const 
{
	Set temp = *this;

	if (temp != b && temp <= b) {
		return true;
	}

    return false;
}

// Set union
// Repeated values are not allowed
// merge sets
Set Set::operator+(const Set& b) const
{
	Set mergedSet = Set();
	Node* p1 = head->next;
	Node* p2= b.head->next;
	Node* p3 = mergedSet.head;

	while (p1 != nullptr && p2 != nullptr) {
		if (p1->value < p2->value) {
			mergedSet.insert(p3, p1->value);
			p1 = p1->next;
			p3 = p3->next;
		}
		else if (p2->value < p1->value) {
			mergedSet.insert(p3, p2->value);
			p2 = p2->next;
			p3 = p3->next;
		}
		else {
			mergedSet.insert(p3, p1->value);
			p3 = p3->next;
			p2 = p2->next; 
			p1 = p1->next;
		}
	}

	while (p1 != nullptr) {
		mergedSet.insert(p3, p1->value);
		p1 = p1->next;
		p3 = p3->next;
	}
	while (p2 != nullptr) {
		mergedSet.insert(p3, p2->value);
		p2 = p2->next;
		p3 = p3->next;
	}

	return mergedSet;

	// implement before HA session week 45

}
// multiplies two sets into each other
Set Set::operator*(const Set& b) const 
{
	Set intersectSet = Set();

	Set set1 = *this;

	Node* temp = b.head->next;

	while (temp != nullptr) {
		if (set1.member(temp->value)) {
			intersectSet.insert(temp->value);
		}

		temp = temp->next;
	}

    return intersectSet;
}

// Set difference
// removes curtain sets.
Set Set::operator-(const Set& b) const 
{
	Set diffSet = Set();

	Set set1 = b;

	Node* temp = head->next;

	while (temp != nullptr) {
		if (!set1.member(temp->value)) {
			diffSet.insert(temp->value);
		}

		temp = temp->next;
	}
	return diffSet; 
}

// Set union with set {x}
//
Set Set::operator+(int x) const 
{
	Set temp = *this;
   temp = temp + Set{x};

	return temp;  // to be deleted
}

// Set difference with set {x}
//
Set Set::operator-(int x) const 
{
	Set temp = *this;

	temp = temp - Set{x};

    return temp;  // to be deleted
}



std::ostream& operator<<(std::ostream& os, const Set& theSet) 
{
	if (theSet.empty())
	{
		os << "Set is empty!";
	}
    else
	{
        Set::Node* temp = theSet.head->next;
        os << "{ ";



        while (temp)
		{
            os << temp->value << " ";
            temp = temp->next;
        }
        os << "}";
    }

    return os;
}
