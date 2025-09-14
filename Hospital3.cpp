#include <bits/stdc++.h>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    string id;
    string gender;
    int age;
public:
    Person() {}
    Person(string name, string id, string gender, int age)
        : name(name), id(id), gender(gender), age(age) {}

    virtual void displayInfo() {
        cout << "General Name: " << name
             << " | ID: " << id
             << " | Age: " << age
             << " | Gender: " << gender;
    }
};

// Forward declaration
class Doctor;

// Appointment class
class Appointment {
protected:
    string doctorName;
    string patientName;
    string date;
    string time;
    string reason;
    string status; // scheduled, completed, cancelled
public:
    Appointment() {}
    Appointment(string doctorName, string patientName, string date, string time,
                string reason, string status)
        : doctorName(doctorName), patientName(patientName), date(date),
          time(time), reason(reason), status(status) {}

    virtual void display() {
        cout << doctorName << " " << date << " " << time << " " << status << endl;
    }

    void cancel() { status = "Cancelled"; }
    void complete() { status = "Completed"; }

    // Getters
    string getDoctorName() const { return doctorName; }
    string getPatientName() const { return patientName; }
    string getDate() const { return date; }
    string getTime() const { return time; }
    string getStatus() const { return status; }
};

// Patient class
class Patient : public Person {
protected:
    string address;
    string healthInsuranceID;
    string nextAppointment;
    vector<Appointment> appHistory;
public:
    Patient() {}
    Patient(string name, string id, string gender, int age,
            string address, string healthInsuranceID, string nextAppointment)
        : Person(name,id,gender,age), address(address),
          healthInsuranceID(healthInsuranceID), nextAppointment(nextAppointment) {}

    virtual void scheduleAppointment(string doctorName, string date, string time,
                                     string reason) {
        Appointment a(doctorName, name, date, time, reason, "Scheduled");
        appHistory.push_back(a);
    }

    void addAppointment(Appointment a) { appHistory.push_back(a); }

    virtual void displayInfo() override {
        Person::displayInfo();
        cout << " | Address: " << address
             << " | Health Insurance ID: " << healthInsuranceID
             << " | Next Appointment: " << nextAppointment << endl;
        for(auto &a: appHistory) a.display();
    }
};

// ChronicPatient class
class ChronicPatient : public Patient {
    string conditionType;
    string lastCheckup;
public:
    ChronicPatient() {}
    ChronicPatient(string name, string id, string gender, int age,
                   string address, string healthInsuranceID, string nextAppointment,
                   string conditionType, string lastCheckup)
        : Patient(name,id,gender,age,address,healthInsuranceID,nextAppointment),
          conditionType(conditionType), lastCheckup(lastCheckup) {}

    void scheduleAppointment(string doctorName, string date, string time,
                             string reason) override {
        // Chronic patients may need more frequent appointments
        Appointment a(doctorName, name, date, time, reason, "Scheduled");
        appHistory.push_back(a);
    }

    void displayInfo() override {
        Patient::displayInfo();
        cout << "   [Chronic Condition: " << conditionType
             << " | Last Checkup: " << lastCheckup << "]" << endl;
    }
};

// Doctor class
class Doctor : public Person {
    string address;
    string healthInsuranceID;
    string medicalSpecialty;
    vector<Appointment> appointments;
public:
    Doctor() {}
    Doctor(string name,string id,string gender,int age,
           string address,string healthInsuranceID,string medicalSpecialty)
        : Person(name,id,gender,age), address(address), 
          healthInsuranceID(healthInsuranceID), medicalSpecialty(medicalSpecialty) {}

    void addAppointment(Appointment a) { appointments.push_back(a); }

    void displayInfo() override {
        Person::displayInfo();
        cout << " | Address: " << address
             << " | Health Insurance ID: " << healthInsuranceID
             << " | Medical Specialty: " << medicalSpecialty << endl;

        if(!appointments.empty()){
            cout << "Next Appointments:" << endl;
            for(auto &a: appointments){
                cout << a.getDate() << " " << a.getTime()
                     << " Room: N/A Patient Name: " << a.getPatientName()
                     << " | Status: " << a.getStatus() << endl;
            }
        }
    }
};

// Main
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    int numPatients;
    cin >> numPatients; cin.ignore();
    vector<Patient*> allPatients;

    for(int i=0;i<numPatients;i++){
        string type;
        cin >> type; cin.ignore();
        if(type=="Normal_Patient"){
            string name,id,gender,address,health,nextApp;
            int age;
            getline(cin,name);
            getline(cin,id);
            getline(cin,gender);
            cin >> age; cin.ignore();
            getline(cin,address);
            getline(cin,health);
            getline(cin,nextApp);
            Patient* p = new Patient(name,id,gender,age,address,health,nextApp);
            int numApp; cin >> numApp; cin.ignore();
            for(int j=0;j<numApp;j++){
                string doc,date,time,status;
                cin >> doc >> date >> time >> status; cin.ignore();
                Appointment a(doc,name,date,time,"Checkup",status);
                p->addAppointment(a);
            }
            allPatients.push_back(p);
        } else if(type=="Chronic_Patient"){
            string name,id,gender,address,health,nextApp,cond,last;
            int age;
            getline(cin,name);
            getline(cin,id);
            getline(cin,gender);
            cin >> age; cin.ignore();
            getline(cin,address);
            getline(cin,health);
            getline(cin,nextApp);
            getline(cin,cond);
            getline(cin,last);
            ChronicPatient* cp = new ChronicPatient(name,id,gender,age,address,health,nextApp,cond,last);
            int numApp; cin >> numApp; cin.ignore();
            for(int j=0;j<numApp;j++){
                string doc,date,time,status;
                cin >> doc >> date >> time >> status; cin.ignore();
                Appointment a(doc,name,date,time,"Checkup",status);
                cp->addAppointment(a);
            }
            allPatients.push_back(cp);
        }
    }

    // Doctors
    int numDoctors; cin >> numDoctors; cin.ignore();
    vector<Doctor> doctors;
    for(int i=0;i<numDoctors;i++){
        string name,id,gender,address,health,specialty;
        int age;
        getline(cin,name);
        getline(cin,id);
        getline(cin,gender);
        cin >> age; cin.ignore();
        getline(cin,address);
        getline(cin,health);
        getline(cin,specialty);
        doctors.push_back(Doctor(name,id,gender,age,address,health,specialty));
    }

    cout << "====== PATIENTS ======" << endl;
    for(auto p: allPatients) p->displayInfo();

    cout << "====== DOCTORS ======" << endl;
    for(auto &d: doctors) d.displayInfo();

    // free memory
    for(auto p: allPatients) delete p;

    return 0;
}
