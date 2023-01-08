
#include <iostream>
using namespace std;

// student record contents
struct node {
	string name;
	double avg;
	node* next;
};

node* n;
node* head = NULL;
node* tail = NULL;

// function that inputs the students name and average into their record
void add_Student_Record() {
	string stuName;
	double stuAvg;
	cout << "Enter the student's name: ";
	cin >> stuName;

	cout << endl << "Enter the student's final average: ";
	cin >> stuAvg;

	n = new node;
	n->name = stuName;
	n->avg = stuAvg;
}

int main() {
	int answer; // Gets input from the user 
	int counter = 0; // counts the number of records
	cout << "Welcome" << endl << "Please select from the following options. Enter the corresponding value 1-4." << endl;
	cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl; 
	cin >> answer; 
	while (answer != 4) {
		if (answer == 1 && counter == 0) { // first record creation 
			add_Student_Record();
			head = n;
			tail = n;
			counter++;
			cout << endl;
			cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl;
			cin >> answer;
		}
		if (answer == 1 && counter > 0) { // if there are already records created
			add_Student_Record();
			tail->next = n; // make next point to the new node
			tail = n; // update tail
			n->next = NULL;
			counter++;
			cout << endl;
			cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl;
			cin >> answer;
		}
		if (answer == 2 && head == NULL) { // no records 
			cout << "No student records" << endl;
			cout << endl;
			cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl;
			cin >> answer;
		}
		if (answer == 2 && head != NULL) { 
			n = head; // start at the beginning
			for (int i = 0; i < counter; i++) {
				cout << n->name << " " << n->avg << endl;
				n = n->next; // advance to the next node
			}
			cout << endl;
			cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl;
			cin >> answer;	
		}
		if (answer == 3) { // Counter
			cout << counter;
			cout << endl << endl;
			cout << "1. Add student record" << endl << "2. Display student records" << endl << "3. Count number of records" << endl << "4. Exit" << endl;
			cin >> answer;
		}
		if (answer == 4) { //Exit
			return 0;
		}
	}
}


