/*
* Author: Brenden Abbott
* Student Number: 0952301
*/
#pragma once
#include "Patient.h"
#include "LinkedList.h"

template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;

public:
	PriorityQueue() {}

	void enqueue(const Patient& patient) {

		auto* current = this->patients_.begin();
		/*LinkedList::Node* node = new LinkedList::Node();*/

		// Add patient to back if list is empty 
		if (patients_.empty()) {
			patients_.push_back(patient);
			return;
		}
		else {
			//Add patient to front if get_score() larger than begin patient
			if (patient.get_score() > current->data.get_score()) {
				patients_.push_front(patient);
			}
			else {
				while (current != nullptr) {
					//Add patient before current if score is larger than current
					if (patient.get_score() > current->data.get_score()) {
						patients_.insert_before(current, patient);
						return;
					}
					current = current->next;
				}
				//Add patient to back if its not great than any scores and current iterates to nullptr
				if (current == nullptr) {
					patients_.push_back(patient);
				}
				
			}
		}
	}

	T dequeue() {
		return patients_.pop_front();
	}

	auto* begin() {
		return patients_.begin();
	}

	size_t size() {
		return patients_.size();
	}

	bool empty() {
		if (patients_.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};
