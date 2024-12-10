#include <iostream>
#include <vector>
using namespace std;
int pid;
int did;
class Patient{
    public:
   string Name,Gender;
   int Age;
   int ID;
   Patient(string Name,string Gender,int Age){
     this->ID=pid++;
     this->Name=Name;
     this->Gender=Gender;
     this->Age=Age;
   }
};

class Doctor{
   public:
   string Name,Gender;
   int Age;
   int ID;
   Doctor(string Name,string Gender,int Age){
     this->ID=did++;
     this->Name=Name;
     this->Gender=Gender;
     this->Age=Age;
   }
};

class Appointments{
    public:
    int patientID;
    int doctorID;
    string Date;
    Appointments(int patientID,int doctorID,string Date){
        this->Date=Date;
        this->doctorID=doctorID;
        this->patientID=patientID;
    } 
};

vector<Patient> allpatient;
vector<Doctor> alldoctor;
vector<Appointments> allapp;

bool ispatient(int ID){
    for(int i=0;i<allpatient.size();i++){
        if(allpatient[i].ID==ID) return true;
    }
    return false;
}

bool isdoctor(int ID){
    for(int i=0;i<alldoctor.size();i++){
        if(alldoctor[i].ID==ID) return true;
    }
    return false;
}

void addpatient(){
    string n,g;
    int a;
   cout<<"Give the Name of Patient :"<<endl;
   cin>>n;
   cout<<"Give the Gender of Patient :"<<endl;
   cin>>g;
   cout<<"Give the Age of Patient :"<<endl;
   cin>>a;
   if(a<=0 || a>120) {
    cout<<"Invalid Age of Patient"<<endl;
    return;
   } 
   Patient p(n,g,a);
   allpatient.push_back(p);
}

void adddoctor(){
    string n,g;
    int a;
   cout<<"Give the Name of Doctor :"<<endl;
   cin>>n;
   cout<<"Give the Gender of Doctor :"<<endl;
   cin>>g;
   cout<<"Give the Age of Doctor :"<<endl;
   cin>>a;
   if(a<=0 || a>120) {
    cout<<"Invalid Age of Doctor"<<endl;
    return;
   } 
   Doctor d(n,g,a);
   alldoctor.push_back(d);
}

void ScheduleAppointments(){
    int patientID;
    int doctorID;
    int d,m,y;
    string Date;

   cout<<"Give the Patient ID"<<endl;
    cin>>patientID;
     if(!ispatient(patientID)){
        cout<<"Pateint ID is invalid "<<endl;
        cout<<"Appointment schedule unsucessfull!"<<endl;
        return;
    }

    cout<<"Give the Doctor ID"<<endl;
    cin>>doctorID;
    if(!isdoctor(doctorID)){
        cout<<"Doctor ID is invalid "<<endl;
        cout<<"Appointment schedule unsucessfull!"<<endl;
        return;
    }

    cout<<"Give the Day of Appointment "<<endl;
    cin>>d;
    if(d<=0 || d>31) {
        cout<<"Invalid date of Appointment "<<endl;
        return;
    }

    cout<<"Give the Month of Appointment "<<endl;
    cin>>m;
    if(m<=0 || m>12) {
        cout<<"Invalid date of Appointment "<<endl;
        return;
    }

    cout<<"Give the Year of Appointment "<<endl;
    cin>>y;

    Date=to_string(d)+"-"+to_string(m)+"-"+to_string(y);
    Appointments a(patientID,doctorID,Date);
    allapp.push_back(a);
    cout<<"Your Appointment is booked!"<<endl;
}
void viewpatients(){
    if(allpatient.size()==0) {
        cout<<endl<<"There is no any Patient"<<endl;
        return;
    }
    cout<<"---------*****---------"<<endl<<endl;
    for(int i=0;i<allpatient.size();i++){
        cout<<"Patient :"<<allpatient[i].Name<<endl;
        cout<<"Gender :"<<allpatient[i].Gender<<endl;
        cout<<"Age :"<<allpatient[i].Age<<endl;
        cout<<"Patient ID:"<<allpatient[i].ID<<endl;
        cout<<endl<<endl;
    }
    cout<<"---------*****---------"<<endl<<endl;
}

void viewdoctors(){
    if(alldoctor.size()==0) {
        cout<<"There is no any Doctor"<<endl;
        return;
    }
    cout<<"---------*****---------"<<endl<<endl;
    for(int i=0;i<alldoctor.size();i++){
        cout<<"Doctor :"<<alldoctor[i].Name<<endl;
        cout<<"Gender :"<<alldoctor[i].Gender<<endl;
        cout<<"Age :"<<alldoctor[i].Age<<endl;
        cout<<"Doctor ID:"<<alldoctor[i].ID<<endl;
        cout<<endl<<endl;
    }
    cout<<"---------*****---------"<<endl<<endl;
}

void viewAppointments(){
    if(allapp.size()==0) {
        cout<<"There is no any Appointment"<<endl;
        return;
    }
    cout<<"---------*****---------"<<endl<<endl;
   for(int i=0;i<allapp.size();i++){
        cout<<"pateint ID :"<<allapp[i].patientID<<endl;
        cout<<"Doctor ID:"<<allapp[i].doctorID<<endl;
        cout<<"Date :"<<allapp[i].Date<<endl;
        cout<<endl<<endl;
    }
    cout<<"---------*****---------"<<endl<<endl;
}

int main(){
    pid=1;
    did=1;
    int choice;
    do{
      cout<<"1. Add Patient"<<endl;
      cout<<"2. Add Doctors"<<endl;
      cout<<"3. Schedule Appointments"<<endl;
      cout<<"4. View Patients"<<endl;
      cout<<"5. View Doctors"<<endl;
      cout<<"6. View Appointments"<<endl;
      cout<<"0. Exit"<<endl;
      cout<<"Give your choice"<<endl;
      cin>>choice;

      switch(choice){
        case 0:
        break;
        case 1:
        addpatient();
        break;
        case 2:
        adddoctor();
        break;
        case 3:
        ScheduleAppointments();
        break;
        case 4:
        viewpatients();
        break;
        case 5:
        viewdoctors();
        break;
        case 6:
        viewAppointments();
        break;
        default:
        cout<<"Invalid choice!"<<endl<<endl<<endl;
      }

    }while(choice!=0);
    return 0;
}