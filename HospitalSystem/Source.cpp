#include <bits/stdc++.h>
using namespace std;
class Specilization {
private:
	deque<pair<string ,string>>names;
public:
	void addNewPatient(string s, int status);
	void printAllThePatients(int key);
	void getNextPatient();
};
class System {
public:
	void Display();
	void Run();
};
int main() {
	System r;
	r.Run();

	return 0;
}

void Specilization::addNewPatient(string s, int status)
{

	if (names.size() < 1) {
		if (status == 0) {
			names.push_back(make_pair(s, "Regular"));
		}
		else if (status == 1) {
			names.push_front(make_pair(s, "Urgent"));
		}
	}
	else {
		cout << "Sorry we cant't add more patients for this specialization" << endl;
		cout << '\n';
	}
}

void Specilization::printAllThePatients(int key)
{
	if (names.empty()) return;
	else {
		cout << '\n';
		cout << "There are " << names.size() << " patient(s) in specialization " << key << endl;
		for (const auto& p : names)
			cout << p.first << " " << p.second << endl;
		cout << '\n';
	}
}

void Specilization::getNextPatient()
{
	if (names.empty()) {

		cout << "\nNo patients at the moment. Have rest, Dr :)\n" << endl;


	}
	else {
		cout << names.front().first << " please go with the Dr\n" << endl;
		names.pop_front();
	}
}

void System::Display()
{
	cout << "*************************" << endl;
	cout << "Enter Your Choice:" << endl;
	cout << "1) Add New Patient" << endl;
	cout << "2) Print All The Patients" << endl;
	cout << "3) Get Next Patient " << endl;
	cout << "4) Exit" << endl;
	cout << "*************************" << endl;

}

void System::Run()
{
	int input = 0;
	System show;
	Specilization s[21];
	while (true) {
		show.Display();
		cin >> input;
		if (input == 1) {
			int sp, statue;
			string name;
			cout << "Enter Specialization , name , status" << endl;
			cin >> sp >> name >> statue;
			if (sp <= 20 && sp >= 1) {
				s[sp].addNewPatient(name, statue);
			}
		}
		else if (input == 2) {
			for (size_t i = 1; i < 21; i++)
			{
				s[i].printAllThePatients(i);
			}
		}
		else if (input == 3) {
			int sp;
			cout << "Enter Specialization" << endl;
			cin >> sp;
			s[sp].getNextPatient();
		}
		else if (input == 4) break;

	}

}
