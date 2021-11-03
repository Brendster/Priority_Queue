/*
* Author: Brenden Abbott
* Student Number: 0952301
*/
#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>


class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;

public:
	//Constructors
	Patient() : name_(""){}
	Patient(std::string const& name) : name_(name){}


	std::string get_name() const { return name_; }

	LinkedList<Ailment> get_ailments() const { return ailments_; }

	void add_ailment(const Ailment& newAilment);

	int get_score() const;

	bool operator== (const Patient& rhs) const;
};





