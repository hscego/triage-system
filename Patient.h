// Hannah Scego
// Patient.h

#ifndef PATIENT_H
#define PATIENT_H
#include <queue>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    string name;
    int priorityCode;
    int arrivalOrder;

public:
    Patient(string name, int priorityCode, int arrivalOrder)
        : name(name), priorityCode(priorityCode), arrivalOrder(arrivalOrder) {}

    // Getters
    string getName() const { return name; }
    int getPriorityCode() const { return priorityCode; }
    int getArrivalOrder() const { return arrivalOrder; }

    bool operator<(const Patient& other) const {
        return priorityCode > other.priorityCode || (priorityCode == other.priorityCode && arrivalOrder > other.arrivalOrder);
    }

    bool operator>(const Patient& other) const {
        return priorityCode < other.priorityCode || (priorityCode == other.priorityCode && arrivalOrder < other.arrivalOrder);
    }

    string toPatientString() const {
         return name + " { priority =" + std::to_string(priorityCode) + ", arrival =" + std::to_string(arrivalOrder) + " }";
         }

};

#endif // PATIENT_H
