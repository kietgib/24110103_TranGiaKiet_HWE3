#include <bits/stdc++.h>
using namespace std;

class Person{
private:
protected:
    string name; 
    string id; 
    string gender;
    int age; 
public:
    Person(){}

    Person(string name, string id, string gender, int age){
        this -> name = name; 
        this -> id = id; 
        this -> gender = gender;
        this -> age = age; 
    }

    virtual void displayInfo (){
        cout<<"General Name: "<<name<<" ,Age: "<<age<<" ,Gender: "<<gender<<" ";
    }

};

//Patient
class Patient : public Person{
private: 
    string address; 
    string healthInsuranceID;
    string nextAppoinment; 
public: 
    Patient(){}
    Patient(string name, string id, string gender, int age, string address, string healthInsuranceID, string nextAppoinment){
        Person(name, id, gender, age); 
        this -> address = address; 
        this -> healthInsuranceID = healthInsuranceID; 
        this -> nextAppointment = nextAppointment;
    }

    void setAge(int age)
    {
        this -> age = age; 
    }

    void setAddress(string address)
    {
        this -> address = address; 
    }

    void setnextAppoinment(string nextAppointment)
    {
        this -> nextAppointment = nextAppointment;
    }

    void displayInfo()override{
        Person::displayInfo();
        cout << " | Address: " << address
             << " | Insurance ID: " << healthInsuranceID
             << " | Next Appt: " << nextAppointment << endl;
    }

    
};

//Chronic Patient
class ChronicPatient : public Patient{
private: 
    string conditionType; 
    string lastCheckup;
public: 
    ChronicPatient(){}
    ChronicPatient(string name, string id, string gender, int age, string address, string healthInsuranceID, string nextAppoinment, string conditionType, string lastCheckup)
                    {
                        Patient(name, id, gender, age, address,healthInsuranceID); 
                        this -> conditionType = conditionType; 
                        this -> lastCheckup = lastCheckup;
                    }

    void displayInfo() override {
        Patient::displayInfo();
        cout << "   [Chronic Condition: " << conditionType
             << " | Last Checkup: " << lastCheckup << "]" << endl;
    }
};

//Docter
class Docter : public Person{
private: 
    string address; 
    string healthInsuranceID;
    string medicalSpecialty;
    vector<int>assignedApptIDs;

public: 
    Docter(){}
    Docter(string name, string id, string gender, int age, string address, string healthInsuranceID, string medicalSpecialty){
        Person(name, id, gender, age);
        this -> healthInsuranceID = healthInsuranceID; 
        this -> medicalSpecialty = medicalSpecialty; 
    }

    void assignAppointment(int apptId) { assignedApptIDs.push_back(apptId); }

    void displayInfo()override{
        cout<<"Health Insurance ID: "<<healthInsuranceID<<" ,Medical Specialty: "<<medicalSpecialty<<endl;
    }
    
};

class Appoinment {
protected:
    string doctorName;
    string time; 
    string date;
    string status;

public:
    Appointment(string doctorName, string date,string time, string status) {
        this->doctorName = doctorName;
        this->date = date;
        this->time = time;
        this->status = status;
    }

    virtual void display() {
        cout << "Doctor: " << doctorName 
             << " | Date: " << date <<" |Time: "<<time
             << " | Status: " << status << endl;
    }
};


class EmergencyPatient : public Patient{

};



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int numPatients;
    cin >> numPatients;
    vector<Patient> patients;
    vector<ChronicPatient> chronicPatients;

    for (int i = 0; i < numPatients; i++) {
        cout<<"Normal_Patient or Chronic_Patient: ";
        string x; 
        cin>>x; 

        if(x == "Normal_Patient")
        {
            vector<Patient>patients
            string name, id, gender, age, address, healthInsuranceID, nextAppoinment;
            getline(cin, name); 
            getline(cin, id); 
            cin>>age; 
            cin.ignore(256,'\n');
            getline(cin, gender); 
            getline(cin, address); 
            getline(cin, healthInsuranceID); 
            getline(cin, nextAppoinment);
            Patient t (name, id, gender, age, address, healthInsuranceID, nextAppoinment); 
            patients.push_back(t);
        }

        else if (x == "Chronic_Patient")
        {
            vector<ChronicPatient>patients2;
            string name,id,gender,age, address, healthInsuranceID, nextAppoinment, conditionType, lastCheckup;
            getline(cin, name); 
            getline(cin, id); 
            cin>>age; 
            cin.ignore(256, '\n');
            getline(cin, gender); 
            getline(cin, address); 
            getline(cin, healthInsuranceID); 
            getline(cin, nextAppoinment);
            getline(cin, conditionType); 
            getline(cin, lastCheckup);
            ChronicPatient s (name, id, gender, age, address, healthInsuranceID, nextAppoinment, conditionType, lastCheckup); 
            patients2.push_back(s);
        }
    }

    // ----- Doctors -----
    int numDoctors;
    cin >> numDoctors;
    vector<Doctor> doctors;

    for (int i = 0; i < numDoctors; i++) {
        string name, id, gender, specialty;
        int age;
        cin >> name >> id >> gender >> age >> specialty;
        doctors.push_back(Doctor(name, id, gender, age, specialty));
    }

    // ----- Appointments -----
    int numAppts;
    cin >> numAppts;
    vector<Appointment> appointments;

    for (int i = 0; i < numAppts; i++) {
        string doc, d, t, st;
        cin >> doc >> d >> t >> st;
        appointments.push_back(Appointment(doc, d, t, st));
    }

    // ====== OUTPUT ======
    cout << "=== Patients ===\n";
    for (auto &p : patients) p.displayInfo();
    for (auto &cp : chronicPatients) cp.displayInfo();

    cout << "\n=== Doctors ===\n";
    for (auto &d : doctors) d.displayInfo();

    cout << "\n=== Appointments ===\n";
    for (auto &appt : appointments) appt.display();

    return 0;
}