#ifndef LIST342_H_
#define LIST342_H_
#include <fstream>
#include <string>
#include <ostream>
#include <iostream>
#include "Child.h"

using namespace std;

template<class T>
class List342
{
private:
	struct Node { 
		T* value;
		Node* next = NULL;
	};
	Node* head_;


public:
	List342() {
		head_ = NULL; 
	}

	List342(const List342& list1) { 
		head_ = NULL;
		if (list1.head_ == NULL) {
			return;
		}
		Node* temp = list1.head_;
		while (temp != NULL) {
			this->Insert(temp->value);
			temp = temp->next;
		}
	}

	bool BuildList(string file_name) {
		ifstream inFile;

		inFile.open(file_name);
		if (inFile.is_open()) {
			while (!inFile.eof()) {
				T item;
				inFile >> item;
				this->Insert(&item);
			}
			inFile.close();
		}
		else 
		{
			cout << "File: " << file_name << " not found" << endl;
			return false;
		}
		return true;
	}

	bool Insert(T* obj)
	 {
		Node* ins_node_;
		ins_node_ = new Node;
		ins_node_->value = new T(*obj);
		if (head_ == NULL) {
			head_ = ins_node_;
			return true;
		}
		else if (*obj < *head_->value)
		 {
			ins_node_->next = head_;
			head_ = ins_node_;
			return true;
		}
		else
		 {
			Node* temp = head_;
			while ((temp->next != NULL) && (*(temp->next->value) <= *obj)) {
				temp = temp->next;
			}
			if (*(temp->value) != *obj) { 
				ins_node_->next = temp->next;
				temp->next = ins_node_;
				return true;
			}
			return false;
		}
	}

	bool Remove(T target, T& result) 
	{
		Node* remve_node_;
		if (head_ == NULL) {
			return false;
		}
		else if (*(head_->value) == target) 
		{ 
			remve_node_ = head_;
			head_ = head_->next;
			result = *remve_node_->value; 
			delete remve_node_->value; 
			remve_node_->value = NULL;
			delete remve_node_; 
			remve_node_ = NULL;
			std::cout << "\n\n " << result << "/n/n" << endl;
			return true;
		}
		else 
		{
			Node* temp = head_;
			while ((temp->next != NULL) && (*(temp->next->value) != target)) {
				temp = temp->next;
			}
			if (temp->next == NULL) {
				return false;
			}
			else {
				remve_node_ = temp->next;
				result = *(remve_node_->value);
				temp->next = (temp->next)->next;
				delete remve_node_->value;
				remve_node_->value = NULL;
				delete remve_node_;
				remve_node_ = NULL;
				return true;
			}
		}
	}

	bool Peek(T target, T& result) 
	{ 
		if (head_ == NULL) {
			return false;
		}
		else if (*(head_->value) == target) 
		{
			result = *(head_->value);
			return true;
		}
		else 
		{
			Node* temp = head_;
			while ((temp->next != NULL) && (*(temp->next->value) != target)) {
				temp = temp->next;
			}
			if (temp->next == NULL) {
				return false;
			}
			else {
				result = *(temp->next->value);
				return true;
			}
		}
	}

	bool isEmpty() const
	 {
		if (head_ == NULL)
		 {
			return true;
		}
		return false;
	}

	void DeleteList()
	 {

		if (head_ != NULL) 
		{ 
			Node* temp;
			while (head_ != NULL)
			 {
				temp = head_;
				delete temp->value;
				temp->value = NULL;
				head_ = head_->next;
				delete temp;
				temp = NULL;
			}
		}
	}
	
	bool Merge(List342& list1) 
	{ 
		if (*this == list1)
		{
			return true;
		}
		if (list1.head_ == NULL) 
		{
			return true;
		}
		if (head_ == NULL) 
		{
			head_ = list1.head_;
			list1.head_ = NULL;
			return true;
		}
		else 
		{
			if (*(head_->value) > * (list1.head_->value))
			 {
				Node* temp = head_;
				head_ = list1.head_;
				list1.head_ = list1.head_->next;
				head_->next = temp;
			}
			else if (*(head_->value) == *(list1.head_->value)) 
			{
				Node* temp = list1.head_;
				list1.head_ = list1.head_->next;
				delete temp;
				temp = NULL;
			}
			else 
			{ 
				Node* traverse_ = head_;
				while ((traverse_->next != NULL) && (*((traverse_->next)->value) <= *(list1.head_->value))) 
				{
					traverse_ = traverse_->next;
				}
				if (*(traverse_->value) != *(list1.head_->value)) 
				{
					Node* temp = list1.head_;
					list1.head_ = list1.head_->next;
					temp->next = traverse_->next;
					traverse_->next = temp;
				}
				else
				{
					Node* temp = list1.head_;
					list1.head_ = list1.head_->next;
					delete temp;
					temp = NULL;
				}
			}
		}
		Node* head1 = head_;
		while (list1.isEmpty() != true) 
		{
			if (head1 == NULL) 
			{
				head1 = list1.head_;
				list1.head_ = NULL;
				return true;
			}
			else {
				if (*(head1->next->value) > * (list1.head_->value)) 
				{
					Node* temp = head1->next;
					head1->next = list1.head_;
					list1.head_ = list1.head_->next;
					head1->next->next = temp;
				}
				else if (*(head1->next->value) == *(list1.head_->value)) 
				{
					Node* temp = list1.head_;
					list1.head_ = list1.head_->next;
					delete temp;
					temp = NULL;
				}
				else {
					while ((head1->next->next != NULL) && (*(head1->next->next->value) <= *(list1.head_->value))) 
					{
						head1 = head1->next;
					}
					if (*(head1->next->value) != *(list1.head_->value)) 
					{
						Node* temp = list1.head_;
						list1.head_ = list1.head_->next;
						temp->next = head1->next->next;
						head1->next->next = temp;
					}
					else 
					{
						Node* temp = list1.head_;
						list1.head_ = list1.head_->next;
						delete temp;
						temp = NULL;
					}
				}
			}

		}

		return true;
	}


	friend ostream& operator<<(ostream& outPutStream, const List342& stck)
	{
		List342::Node* temp;
		temp = stck.head_;
		while (temp != nullptr) 
		{

			T crap = *temp->value;
			outPutStream << crap;
			temp = temp->next;
		}
		return outPutStream;
	}



	List342 operator + (const List342& list1) const 
	{
		List342 temp1 = *this;
		List342 temp2 = list1;
		temp1.Merge(temp2);
		return temp1;
	}

	bool operator == (const List342& list1) const 
	{
		Node* head1 = head_;
		Node* head2 = list1.head_;
		while (head1 != NULL && head2 != NULL) 
		{
			if (*(head1->value) == *(head2->value)) 
			{
				head1 = head1->next;
				head2 = head2->next;
			}
			else {
				break;
			}
		}
		if (head1 != NULL && head2 != NULL) 
		{
			if (*(head1->value) == *(head2->value)) 
			{
				return true;
			}
			else {
				return false;
			}
		}
		else 
		{
			if (head1 == NULL && head2 == NULL) 
			{
				return true;
			}
			else return false;
		}
	}

	bool operator != (const List342& list1) const
	 { 
		Node* head1 = head_;
		Node* head2 = list1.head_;
		while (head1 != NULL && head2 != NULL) 
		{
			if (*(head1->value) == *(head2->value)) 
			{
				head1 = head1->next;
				head2 = head2->next;
			}
			else 
			{
				return true;
			}
		}
		if (head1 != NULL && head2 != NULL)
		 {
			if (*(head1->value) == *(head2->value))
			{
				return false;
			}
			else return true;
		}
		else 
		{
			if (head1 == NULL && head2 == NULL) 
			{
				return false;
			}
			else return true;
		}
	}

	List342& operator+=(const List342 list1) 
	{
		List342<T> temp = list1;
		this->Merge(temp);
		return *this;
	}

	List342& operator = (const List342& list1) 
	{
		if (list1.head_ != NULL) 
		{
			this->DeleteList();
			head_ = new Node;
			*(head_->value) = *(list1.head_->value);

			Node* head1 = head_;
			Node* head2 = list1.head_->next;

			while (head2 != NULL) 
			{ 
				Node* temp = new Node;
				*(temp->value) = *(head2->value);
				head1->next = temp;
				head1 = head1->next;
				head2 = head2->next;
			}
			return *this;
		}
		else 
		{ 
			this->DeleteList();
			head_ = NULL;
			return *this;
		}
	}

	~List342() 
	{
		DeleteList();
	}
}; 
#endif 