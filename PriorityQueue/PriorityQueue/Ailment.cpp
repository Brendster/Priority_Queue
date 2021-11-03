/*
* Author: Brenden Abbott 
* Student Number: 0952301
*/
#include "Ailment.h"

Ailment::Ailment(std::string name, int severity, int time_sensitivity, int contagiousness) {
	name_ = name;
	severity_ = severity;
	time_sensitivity_ = time_sensitivity;
	contagiousness_ = contagiousness;
}

bool Ailment::operator== (const Ailment& rhs) const {

    if (this->get_name() == rhs.get_name() &&
        this->get_severity() == rhs.get_severity() &&
        this->get_time_sensitivity() == rhs.get_time_sensitivity() &&
        this->get_contagiousness() == rhs.get_contagiousness()) {
        return true;
    }
    else {
        return false;
    }
}