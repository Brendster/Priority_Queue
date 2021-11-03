/*
* Author: Brenden Abbott
* Student Number: 0952301
*/
#pragma once

#include <string>

class Ailment
{
	std::string name_;
	int severity_;
	int time_sensitivity_;
	int contagiousness_;

public:
	Ailment() : name_(""), severity_(0), time_sensitivity_(0), contagiousness_(0){}
	Ailment(std::string name, int severity, int time_sensitivity, int contagiousness);

	std::string get_name() const { return name_; }
	int get_severity() const { return severity_; }
	int get_time_sensitivity() const { return time_sensitivity_; }
	int get_contagiousness() const { return contagiousness_; }

	bool operator== (const Ailment& rhs) const;

};

