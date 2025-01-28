// Hannah Scego
// PatientPriorityQueue.h

#ifndef PATIENTPRIORITYQUEUE_H
#define PATIENTPRIORITYQUEUE_H

#include <iostream>
#include <queue>
#include <string>
#include "Patient.h"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class PatientPriorityQueue {
private:
    vector<Patient> heap;
    int nextPatientNumber = 1;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    PatientPriorityQueue() {}

    void add(string name, int priorityCode) {
        Patient newPatient(name, priorityCode, nextPatientNumber++);
        heap.push_back(newPatient);
        heapifyUp(heap.size() - 1);
    }

    Patient peek() const {
        if (!heap.empty())
            return heap[0];
        throw logic_error("Queue is empty");
    }

    Patient remove() {
        if (heap.empty())
            throw logic_error("Queue is empty");

        Patient top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return top;
    }

    int size() const {
        return heap.size();
    }

    string to_string() const {
        stringstream ss;
        for (const auto& patient : heap) {
            ss << patient.toPatientString() << "\n";
        }
        return ss.str();
    }
};

#endif // PATIENTPRIORITYQUEUE_H
