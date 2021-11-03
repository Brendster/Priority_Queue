/*
* Author: Brenden Abbott
* Student Number: 0952301
*/
#include "Patient.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

PriorityQueue<Patient> queue;
LinkedList<Patient> historyList;

int main(int argc, char* argv[])
{
	int userSelection = -1;

	while (userSelection != 0) {
		//Title Box
		cout << "****************************************************" << endl;
		cout << "* Welcome to Fanshawe College Medical Center F2021 *" << endl;
		cout << "* Brenden Abbott                                   *" << endl;
		cout << "****************************************************" << endl;

		//Menu display 
		cout << "Please Make A Selection: " << endl;
		cout << endl;
		cout << "	1 - Add Patient" << endl;
		cout << "	2 - Process Next Patient In Queue" << endl;
		cout << "	3 - Display Queue" << endl;
		cout << "	4 - View Processed Patients History" << endl;
		cout << "	5 - Load Queue" << endl;
		cout << "	6 - Save Queue" << endl;
		cout << "	0 - Exit" << endl;

		cin >> userSelection;

		string name;
		string ailmentName;
		int severity;
		int timeC;
		int contagiousness;


		if (userSelection == 1) {
			bool ifCont = true;

			cout << endl;
			cout << "Enter patient name: ";
			cin.ignore();
			getline(cin, name);

			Patient newPatient(name);


			//If ailmentName is empty end case instead adding another ailment
			while (ifCont) {

				cout << "	Enter ailment (leave blank when done): ";
				/*cin.ignore();*/
				getline(cin, ailmentName);
				if (ailmentName.empty()) {
					ifCont = false;
					break;
				}
				cout << "	Enter severity: ";
				cin >> severity;
				cout << "	Enter time criticality: ";
				cin >> timeC;
				cout << "	Enter contagiousness: ";
				cin >> contagiousness;
				cout << endl;
				cin.ignore();
				newPatient.add_ailment(Ailment(ailmentName, severity, timeC, contagiousness));
			}
			queue.enqueue(newPatient);

		}

		if (userSelection == 2) {
			cout << endl;
			cout << queue.begin()->data.get_name() << " moved to patient room!" << endl;
			historyList.push_front(queue.dequeue());

			if (queue.begin() == nullptr) {
				cout << "Last patient in queue already processed. No next patient in queue!" << endl;
			}
			else {
				cout << "Next in queue: " << queue.begin()->data.get_name() << " with priority score " << queue.begin()->data.get_score() << endl;
				cout << endl;
			}
		}

		if (userSelection == 3) {
			int posCounter = 0;
			auto* current = queue.begin();

			cout << endl;
			cout << "Patients In Queue:\n" << endl;

			while (current != nullptr) {
				string ailments = "";
				auto* currentAilment = current->data.get_ailments().begin();

				while (currentAilment != nullptr) {
					ailments += currentAilment->data.get_name() + ", ";
					currentAilment = currentAilment->next;
				}

				cout << posCounter << " : " << current->data.get_name() << " - " << current->data.get_score() << " - " << ailments << endl;

				++posCounter;
				current = current->next;
			}

			cout << endl;
		}

		if (userSelection == 4) {
			auto* current = historyList.begin();

			cout << "\nHistory: " << endl;

			while (current != nullptr) {
				string ailments = "";
				auto* currentAilment = current->data.get_ailments().begin();

				while (currentAilment != nullptr) {
					ailments += currentAilment->data.get_name() + ", ";
					currentAilment = currentAilment->next;
				}

				cout << current->data.get_name() << " - " << current->data.get_score() << " - " << ailments << endl;

				current = current->next;
			}
			cout << endl;
		}

		if (userSelection == 5) {
			string filePath;
			string line;
			string data;
			stringstream ss(line);

			cout << endl;
			cout << "Enter path to file: ";
			cin >> filePath;
			cout << endl;

			ifstream csvFile(filePath);

			if (!csvFile.is_open()) {
				cout << "Could not open file check path\n" << endl;
			}

			if (csvFile.good()) {
				//Counter to see position for adding ailments in order
				int counter = 0;

				while (getline(csvFile, line)) {
					//stringstream object created to parse lines from csv file
					stringstream ss(line);

					getline(ss, data, ',');
					//First string value is patient name so create a patient object 
					Patient newPatient(data);

					string ailmentName = "";
					int severity = 0;
					int timeC = 0;
					int contag = 0;

					//While loop for setting patient ailments
					while (getline(ss, data, ',')) {
						if (ss.peek() == ',') ss.ignore();

						if (counter == 0) {
							ailmentName = data;
						}
						if (counter == 1) {
							severity = stoi(data);
						}
						if (counter == 2) {
							timeC = stoi(data);
						}
						if (counter == 3) {
							contag = stoi(data);
						}
						++counter;
					}
					newPatient.add_ailment(Ailment(ailmentName, severity, timeC, contag));

					queue.enqueue(newPatient);
					//reset the ailment pos counter to 0
					counter = 0;
				}
				cout << "Patients loaded from file! Choose option 3 at the menu to display the queue\n" << endl;
			}
			csvFile.close();
		}

	} //End While loop if userValue = 0
	
	return 0;
} //End main
