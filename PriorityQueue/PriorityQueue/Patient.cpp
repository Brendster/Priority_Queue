/*
* Author: Brenden Abbott
* Student Number: 0952301
*/
#include "Patient.h"

void Patient::add_ailment(const Ailment& newAilment) {
	ailments_.push_back(newAilment);
}

int Patient::get_score() const {
	int score = 0;

	auto* ailment = this->get_ailments().begin();
	while (ailment != nullptr)
	{
		score += (ailment->data.get_severity() * ailment->data.get_time_sensitivity()) + ailment->data.get_contagiousness();
		ailment = ailment->next;
	}

	return score;
}

bool Patient::operator== (const Patient& rhs) const {

	if (this->get_name() == rhs.get_name()) {
		return true;
	}
	else {
		return false;
	}
}