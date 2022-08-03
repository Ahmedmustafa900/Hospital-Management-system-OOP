#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
class password
{
	string code;
public:
	void get_password();
	int verify_password(string);
};
void password::get_password()
{
	cout << "Setting Up The P10 Hospital Management System.....\n";
	cout << "\nPlease Choose A Password For Your System :";
START:
	code.clear();
	char ch;
	int count = 0;
	ch = _getch();
	while (ch != 13)
	{
		if (ch == 8)
		{
			cout << "\b \b";
			code.pop_back();
		}
		if (ch != 8)
		{
			cout << "*";
			code.push_back(ch);
		}
		ch = _getch();
		count++;
	}
	if (count < 5)
	{
		cout << "\n\nYour Password Should Have Minimum Of 5 Characters!!!\n";
		cout << "\n Please Choose A Password For Your System :";
		goto START;
	}
}
int password::verify_password(string pass)
{
	if (pass == code)
		return(1);
}
class doctor
{
	int id;
	int code;
	char name[50];
	int age;
	char qualification[10];
	char specilization[10];
	int experience;
	char state[50];
	char city[50];
public:
	int get_ID();
	void get_info();
	void get_name();
	void get_age();
	void get_code();
	void get_qualification();
	void get_specilization();
	void get_experience();
	void get_state();
	void get_city();
	int verify_specilization(int opt, int flag);
	void display_all(doctor d);
	void display_info(doctor d);
	void modify_info(doctor d, int number, int size);

};
void add_doctor_data();
int verify_alphabet(char* arr, int size);
void modify_doctor_data();
void delete_contents();
void delete_contents1();
void display();
void delete_doctor_data();
int display_doctor_data();
int doctor_number();
long int get_size_of_the_file();
int verify_alphabet(char* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			return(1);
		}
	}
}
int doctor_number()
{
	long int size;
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	return(size);
}
int doctor::verify_specilization(int opt, int flag)
{
	if (opt == code)
	{
		flag++;
		cout << "\n" << "ID------------->\t" << get_ID();
		return(flag);
	}
	else
	{
		return(flag);
	}
}
int doctor::get_ID()
{
	return(id);
}
void doctor::get_info()
{
	cout << "\nEnter Doctor's ID:";
	cin >> id;
NAME:
	cout << "\nEnter Doctor's Name :";
	cin.ignore();
	cin.getline(name, 50);
	int flag;
	int size = strlen(name);
	flag = verify_alphabet(name, size);
	if (flag == 1)
	{
		cout << "\n\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}
	cout << "\nEnter Doctor's Age :";
	cin >> age;
QUALIFICATION:
	cout << "\nEnter Doctor's Qualification:";
	cin.ignore();
	cin.getline(qualification, 50);
	size = strlen(qualification);
	flag = verify_alphabet(qualification, size);
	if (flag == 1)
	{
		cout << "\nQualification should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto QUALIFICATION;
	}
SPECILIZATION:
	cout << "\nEnter Doctor's Specialization:";
	cin.getline(specilization, 50);
	size = strlen(specilization);
	flag = verify_alphabet(specilization, size);
	if (flag == 1)
	{
		cout << "\nSpecilization should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto SPECILIZATION;
	}
	cout << "********************************************************************************";
	cout << "\n\t\t\tCodes For Various Specilizations\n";
	cout << "********************************************************************************";
	cout << "1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\nSelect The Code Basing On The Specilization :";
	cin >> code;
	cout << "********************************************************************************";
	cout << "\nEnter Doctor's Experience:";
	cin >> experience;
STATE:
	cout << "\nEnter Doctor's State:";
	cin.ignore();
	cin.getline(state, 30);
	size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1)
	{
		cout << "\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
CITY:
	cout << "\nEnter Doctor's City :";
	cin.getline(city, 30);
	size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1)
	{
		cout << "\nCity should consist of only alphabets!!! or min of three alphabets\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
}
void doctor::get_name()
{
NAME:
	cin.ignore();
	cout << "\nEnter New Name :";
	cin >> name;
	int flag;
	int size = strlen(name);
	flag = verify_alphabet(name, size);
	if (flag == 1)
	{
		cout << "\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}
}
void doctor::get_age()
{
	cin.ignore();
	cout << "\nEnter New Age :";
	cin >> age;
}
void doctor::get_qualification()
{
QUALIFICATION:
	cin.ignore();
	cout << "\nEnter New Qualification :";
	cin >> specilization;
	int flag;
	int size = strlen(qualification);
	flag = verify_alphabet(qualification, size);
	if (flag == 1)
	{
		cout << "\nQualification should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto QUALIFICATION;
	}
}
void doctor::get_specilization()
{
SPECILIZATION:
	cin.ignore();
	cout << "\nEnter New Specilization :";
	cin >> specilization;
	int flag;
	int size = strlen(specilization);
	flag = verify_alphabet(specilization, size);
	if (flag == 1)
	{
		cout << "\nSpecilization should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto SPECILIZATION;
	}
	cout << "********************************************************************************";
	cout << "\nCodes For Various Specilizations\n";
	cout << "********************************************************************************";
	cout << "1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\nSelect The Code Basing On The Specilization ";
	cin >> code;
}
void doctor::get_experience()
{
	cin.ignore();
	cout << "\nEnter New Experience :";
	cin >> experience;
}
void doctor::get_state()
{
STATE:
	cin.ignore();
	cout << "\nEnter New State :";
	cin >> state;
	int flag;
	int size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1)
	{
		cout << "\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
}
void doctor::get_city()
{
CITY:
	cin.ignore();
	cout << "\nEnter New City :";
	cin >> city;
	int flag;
	int size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1)
	{
		cout << "\nCity should consist of only alphabets(or)min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
}
void doctor::display_info(doctor d)
{
	cout << "\nDoctor's ID:\t " << d.id;
	cout << "\nDoctor's Name :\t" << d.name;
	cout << "\nDoctor's Age:\t" << d.age;
	cout << "\nDoctor's Qualification :\t" << d.qualification;
	cout << "\nDoctor's Specilization :\t" << d.specilization;
	cout << "\nDoctor's Experience:\t" << d.experience;
	cout << "\nDoctor's State :\t" << d.state;
	cout << "\nDoctor's City :\t" << d.city;
}
void doctor::display_all(doctor d)
{
	cout << "\t" << d.id << "\t\t" << d.specilization << "\t\t\t" << d.qualification << "\t\t\t" << d.age << "\n";
}
void doctor::modify_info(doctor d, int number, int size)
{
	if (number == 1)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_name();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		cout << "\n";
		cout << "\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << " \n";
		system("PAUSE");
	}
	else if (number == 2)
	{
		fstream myfile6("doctor8", ios::in | ios::out);
		doctor d1 = d;
		d1.get_age();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 3)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_qualification();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

	else if (number == 4)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_specilization();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 5)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_experience();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 6)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_state();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 7)
	{
		fstream myfile6("doctor8.txt", ios::in | ios::out);
		doctor d1 = d;
		d1.get_city();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&d1, sizeof(d1));
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}

}
class patient
{
	int id;
	int doc_id;
	char name[50];
	int age;
	char occupation[30];
	char state[10];
	char symptoms[70];
	char disease[50];
	char city[10];
	char consultation_date[30];
	char nationality[20];
	char phone_no[20];
	char street[30];
	char door_no[20];
	char condition[30];
	char date_admitted[20];
	char date_discharged[20];
	char discharge_condition[50];
	int bill;
public:
	int get_ID();
	void set_doc_ID();
	void get_info();
	void get_name();
	void get_age();
	void get_occupation();
	void get_state();
	void get_city();
	void get_phone_no();
	void get_nationality();
	void get_street();
	void get_door_no();
	void get_condition();
	void report1(patient);
	void get_discharge_condition();
	void get_date_admitted();
	void get_date_discharged();
	void get_bill();
	void bill1(patient);
	void assign_patient_to_doctor(patient p, int size);
	void display_all(patient p);
	void display_info(patient p);
	void modify_info(patient p, int number, int size);
};
void add_patient_data();
void modify_patient_data();
void delete_patient_data();
void assign_patient();
void display1();
void report();
void bill();
int display_patient_data();
int number();
long int get_size_of_the_file1();
void patient::bill1(patient p)
{
	system("CLS");
	int total;
	cout << "********************************************************************************";
	cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
	cout << "*******************************************************************************";
	cout << "\nHospital Room Charges :\t 1000";
	cout << "\nHospital Care Charges :\t 500";
	cout << "\nHospital Maintaince Charges:\t 500";
	cout << "\nPatient Individual Charges:\t " << p.bill;
	total = 1000 + 500 + 500 + p.bill;
	cout << "\nTotal Fee Charge:\t" << total << "\n";
	cout << "********************************************************************************";
}
void patient::report1(patient p)
{
	system("CLS");
	cout << "********************************************************************************";
	cout << "\n\t\t\tPatient Report\n";
	cout << "********************************************************************************";
	cout << "\nPatient Name:" << p.name;
	cout << "\nPatient Age :" << p.age;
	cout << "\nPatient Symptoms:" << p.symptoms;
	cout << "\nPatient Disease :" << p.disease;
	cout << "\nPatient Admission Date :" << p.date_admitted;
	cout << "\nPatient Discharge Date :" << p.date_discharged;
	cout << "\nPatient Condition At The Time Of Discharge :" << p.discharge_condition;
	cout << "\npatient Consulation Date:" << p.consultation_date;
	cout << "\n";
	cout << "********************************************************************************";
}
int patient::get_ID()
{
	return(id);
}
void patient::set_doc_ID()
{
	cout << "\nPlease Select Your Choice :";
	cin >> doc_id;
}
void patient::get_info()
{
	cout << "\nEnter Patient's ID :";
	cin >> id;
NAME:
	cout << "\nEnter Patient's Name:";
	cin.ignore();
	cin.getline(name, 50);
	int flag;
	int size = strlen(name);
	flag = verify_alphabet(name, size);
	if (flag == 1)
	{
		cout << "\n\nName should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NAME;
	}
	cout << "\nEnter Patient's Age :";
	cin >> age;
OCCUPATION:
	cout << "\nEnter Patient's Occupation :";
	cin.ignore();
	cin.getline(occupation, 30);

	size = strlen(occupation);
	flag = verify_alphabet(occupation, size);
	if (flag == 1)
	{
		cout << "\n\nOccupation should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto OCCUPATION;
	}
STATE:
	cout << "\nEnter Patient's state:";
	cin.getline(state, 30);
	size = strlen(state);
	flag = verify_alphabet(state, size);
	if (flag == 1)
	{
		cout << "\n\nState should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto STATE;
	}
CITY:
	cout << "\nEnter Patient's City:";
	cin.getline(city, 30);
	size = strlen(city);
	flag = verify_alphabet(city, size);
	if (flag == 1)
	{
		cout << "\n\nCity should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto CITY;
	}
NATIONALITY:
	cout << "\nEnter Patient's Nationality :";
	cin.getline(nationality, 30);
	size = strlen(nationality);
	flag = verify_alphabet(nationality, size);
	if (flag == 1)
	{
		cout << "\n\nNationality should consist of only alphabets or min of three alphabets!!!\n";
		cout << "\n";
		system("PAUSE");
		goto NATIONALITY;
	}
	cout << "\nEnter Patient's Phone Number:";
	cin.getline(phone_no, 20);
	cout << "\nEnter Patient's Street Name :";
	cin.getline(street, 30);
	cout << "\nEnter Patient's Symptoms:";
	cin.getline(symptoms, 70);
	cout << "\nEnter Patient's Disease :";
	cin.getline(disease, 30);
	cout << "\nEnter Patient's Door Number :";
	cin.getline(door_no, 20);
	cout << "\nEnter Patient's Condition:";
	cin.getline(condition, 30);
	cout << "\nEnter Admission Date Of The Patient :";
	cin.getline(date_admitted, 20);
	cout << "\nEnter Discharge Date Of The Patient :";
	cin.getline(date_discharged, 20);
	cout << "\nEnter Condition Of The Patient At The Time Of The Discharge :";
	cin.getline(discharge_condition, 50);
	cout << "\nEnter The Patient's Next Consultation Date :";
	cin.getline(consultation_date, 30);
	cout << "\nEnter The Patient's Bill Charges :";
	cin >> bill;
}
void patient::assign_patient_to_doctor(patient p, int size)
{
	long int size1 = size;
	ifstream myfile1("doctor8.txt");
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	cout << "********************************************************************************";
	cout << "\n\t The Following Are The Specilizations Available In The Hospital\n";
	cout << "********************************************************************************";
	cout << "\n1.General Medicine\n2.Cardiology\n3.Neurology\n4.ENT\n";
	cout << "********************************************************************************";
	cout << "\n\nPlease Select Your Choice :";
	int opt, flag = 0;
	int cho;
	cin >> opt;
	myfile1.seekg(0);
	switch (opt)
	{
	case 1:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID's Of The Doctors With The General Medicine Specilization\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verify_specilization(opt, flag);

		}
		myfile1.close();
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "***********************************************************************************";
			fstream myfile6("patient11.txt", ios::in | ios::out);
			patient p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nPatient Has Been Assigned A Doctor Successfully";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	case 2:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID's Of The Doctors With The Cardiology Specilization\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verify_specilization(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("patient11.txt", ios::in | ios::out);
			patient p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nPatient Has Been Assigned A Doctor Successfully";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	case 3:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID's Of The Doctors With The Neurology Specilization\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verify_specilization(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("patient11.txt", ios::in | ios::out);
			patient p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nPatient Has Been Assigned A Doctor Successfully";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}

		break;
	case 4:
		system("CLS");
		cout << "********************************************************************************";
		cout << "\n\t\tID's Of The Doctors With The ENT Specilization\n";
		cout << "********************************************************************************";
		for (int i = 0; i < size; i++)
		{
			cout << "\n";
			myfile1.read((char*)&d, sizeof(d));
			flag = d.verify_specilization(opt, flag);
		}
		if (flag == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Doctors Are Available With The Required Specilization\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\n";
			cout << "********************************************************************************";
			fstream myfile6("patient11.txt", ios::in | ios::out);
			patient p1 = p;
			myfile6.seekp(0);
			myfile6.seekg(0);
			p1.set_doc_ID();
			myfile6.seekp(size1, ios::beg);
			myfile6.write((char*)&p1, sizeof(p1));
			system("CLS");
			cout << "\nPatient Has Been Assigned A Doctor Successfully";
			cout << "\n";
			cout << "\n*****************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
		break;
	default:
		cout << "\nWrong Choice!!!";
	}
}
void patient::get_name()
{
	cout << "\nEnter New Name :";
	cin.ignore();
	cin.getline(name, 50);
}
void patient::get_age()
{
	cout << "\nEnter New Age :";
	cin.ignore();
	cin >> age;
}
void patient::get_occupation()
{
	cout << "\nEnter New Occupation :";
	cin.ignore();
	cin.getline(occupation, 50);
}
void patient::get_state()
{
	cin.ignore();
	cout << "\nEnter New State :";
	cin.getline(state, 20);
}
void patient::get_city()
{
	cin.ignore();
	cout << "\nEnter New City :";
	cin.getline(city, 20);
}
void patient::get_phone_no()
{
	cin.ignore();
	cout << "\nEnter New Phone Number :";
	cin.getline(phone_no, 30);
}
void patient::get_nationality()
{
	cin.ignore();
	cout << "\nEnter New Nationality :";
	cin.getline(nationality, 30);
}
void patient::get_street()
{
	cin.ignore();
	cout << "\nEnter New Street :";
	cin.getline(street, 50);
}
void patient::get_door_no()
{
	cin.ignore();
	cout << "\nEnter New Door Number :";
	cin.getline(door_no, 30);
}
void patient::get_condition()
{
	cin.ignore();
	cout << "\nEnter New Condition :";
	cin.getline(condition, 50);
}
void patient::get_discharge_condition()
{
	cin.ignore();
	cout << "\nEnter New Condition Of The Patient At The Time Of Discharge :";
	cin.getline(discharge_condition, 50);
}
void patient::get_date_admitted()
{
	cin.ignore();
	cout << "\nEnter New Admission Date Of The Patient :";
	cin.getline(date_admitted, 30);
}
void patient::get_date_discharged()
{
	cin.ignore();
	cout << "\nEnter New Discharge Date Of The Patient :";
	cin.getline(date_discharged, 30);
}void patient::get_bill()
{
	cin.ignore();
	cout << "\nEnter New Bill Charge Of The Patient:";
	cin >> bill;
}
void patient::display_all(patient p)
{
	cout << p.id << "\t" << p.age << "\t" << p.symptoms << "\t" << p.date_admitted << "\t\t\t" << p.doc_id << "\n";
}
void patient::display_info(patient p)
{
	cout << "\nPatient's ID:" << p.id;
	cout << "\nPatient's Name :" << p.name;
	cout << "\nPatient's Age :" << p.age;
	cout << "\nPatient's Occupation:" << p.occupation;
	cout << "\nPatient's State:" << p.state;
	cout << "\nPatient's City :" << p.city;
	cout << "\nPatient's Phone Number :" << p.phone_no;
	cout << "\nPatient's Nationality :" << p.nationality;
	cout << "\nPatient's Street:" << p.street;
	cout << "\nPatient's Door Number :" << p.door_no;
	cout << "\nPatient's Condtion :" << p.condition;
	cout << "\nPatient's Condition At The Time Of Discharge:" << p.discharge_condition;
	cout << "\nPatient's Admission Date:" << p.date_admitted;
	cout << "\nPatient's Discharge Date:" << p.date_discharged;
	cout << "\nID Of The Doctor Who Is Treating The Patient:" << p.doc_id;
}
void patient::modify_info(patient p, int number, int size)
{
	if (number == 1)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_name();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 2)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_age();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 3)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_occupation();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 4)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_state();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 5)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_city();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 6)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_phone_no();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 7)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_nationality();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 8)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_street();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 9)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_door_no();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 10)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_condition();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 11)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_discharge_condition();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 12)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_date_admitted();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 13)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_date_discharged();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
	else if (number == 14)
	{
		fstream myfile6("patient11.txt", ios::in | ios::out);
		patient p1 = p;
		p1.get_bill();
		myfile6.seekp(size, ios::beg);
		myfile6.write((char*)&p1, sizeof(p1));
		int total = myfile6.tellp();
		total /= sizeof(p1);
		cout << "\n\n";
		system("PAUSE");
		system("CLS");
		cout << "\nData Successfully Modified\n";
		myfile6.close();
		cout << "\n";
		system("PAUSE");
	}
}
void main()
{
	int counter = 0, y = 0;
	password p;
	p.get_password();
	system("CLS");
START1:
	system("CLS");
	cout << "********************************************************************************\n";
	cout << "\n\t\tWELCOME TO P10 HOSPITAL MANAGEMENT SYSTEM\n\n";
	cout << "********************************************************************************\n";
	cout << "\n\t\t\t\t1.Main Menu\n";
	cout << "\n\t\t\t\t2.Shut Down\n\n";
	cout << "********************************************************************************\n";
	int op, ch, count = 0, x;
	char c;
	string pass;
	cout << "\nPlease Enter Your Choice :";
	cin >> op;
	cout << "\n\n";
	system("PAUSE");
START3:
	switch (op)
	{
	case 1:
		system("CLS");
		cout << "********************************************************************************\n";
		cout << "\t\t\t\tMain Menu\n\n";
		cout << "********************************************************************************\n";
		cout << "\n\n\t\t1.Enter Into Doctor's Database\n";
		cout << "\n\t\t2.Enter into Patient's Database\n";
		cout << "\n\t\t3.Generate Patient's Report\n";
		cout << "\n\t\t4.Generate Patient's Bills\n";
		cout << "\n\t\t5.Exit\n\n";
		cout << "********************************************************************************";
		cout << "\n\n\tPlease Choose Your Choice :";
		cin >> ch;
		switch (ch)
		{
		case 1:
			system("CLS");
		START2:
			count++;
			cout << "\nPlease Enter Your Password To Enter Into This Database :";
			pass.clear();
			c = _getch();
			while (c != 13)
			{
				if (c == 8)
				{
					cout << "\b \b";
					pass.pop_back();
				}
				if (c != 8)
				{
					cout << "*";
					pass.push_back(c);
				}
				c = _getch();
			}
			x = p.verify_password(pass);
			if (x == 1)
			{
				cout << "\n\nAccess Granted ";
				cout << "\n\n";
				system("PAUSE");
				system("CLS");
				while (1)
				{
					system("CLS");
					cout << "********************************************************************************\n";
					cout << "\n\t\t\tWelcome to Doctor's Database\n";
					cout << "\n********************************************************************************\n";
					cout << "\n\t\t1.Add New Doctor's Information\n";
					cout << "\n\t\t2.Edit Doctor's Information\n";
					cout << "\n\t\t3.Display Doctor's Information\n";
					cout << "\n\t\t4.Delete Doctor's Information\n";
					cout << "\n\t\t5.Number Of Doctors In The Hospital\n";
					cout << "\n\t\t6.Clear All The Information In The Database\n";
					cout << "\n\t\t7.Display The Details Of All The Doctors\n";
					cout << "\n\t\t8.Exit\n";
					cout << "\n********************************************************************************\n";
					int opt;
					cout << "Please Choose Your Choice :";
					cin >> opt;
					int y;
					switch (opt)
					{
					case 1:
						system("CLS");
						add_doctor_data();
						break;
					case 2:

						system("CLS");
						modify_doctor_data();

						break;
					case 3:
						system("CLS");
						y = display_doctor_data();
						if (y != 1)
						{
							cout << "\nNo Record To Display!!!\n";
							cout << "\n";
							system("PAUSE");
						}

						break;
					case 4:

						system("CLS");
						delete_doctor_data();
						cout << "\n";
						system("PAUSE");

						break;
					case 5:
						system("CLS");
						cout << "\nNumber Of Doctors In The Hospital are :" << doctor_number();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 6:
						system("CLS");
						delete_contents();
						cout << "\nAll The Contents Of The Database Are Deleted ";
						cout << "\n\n";
						system("PAUSE");
						break;
					case 7:
						system("CLS");
						display();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 8:
						system("CLS");
						goto START3;
						_getch();
					}
				}
			}
			else
			{
				if (count >= 3)
				{
					system("CLS");
					cout << "\n\nAccess Denied!!!You Have Entered Wrong Password Too Many Times\n";
					cout << "\nThis System Will Shut Down.Please Come Back Again\n";
					cout << "\nThank You\n";
					cout << "\n";
					system("PAUSE");
					exit(0);
				}
				cout << "\n\nWrong Password.Access Denied!!!\n";
				goto START2;
			}
		case 2:
			system("CLS");
		START4:
			count++;
			cout << "\nPlease Enter Your Password To Enter Into This Database :";
			pass.clear();
			c = _getch();
			while (c != 13)
			{
				if (c == 8)
				{
					cout << "\b \b";
					pass.pop_back();
				}
				if (c != 8)
				{
					cout << "*";
					pass.push_back(c);
				}
				c = _getch();
			}
			x = p.verify_password(pass);
			if (x == 1)
			{
				cout << "\n\nAccess Granted ";
				cout << "\n\n";
				system("PAUSE");
				system("CLS");
				while (1)
				{
					system("CLS");
					cout << "********************************************************************************\n";
					cout << "\n\t\t\tWelcome To Patient's Database\n\n";
					cout << "********************************************************************************\n";
					cout << "\n\t\t1.Add Patient's Information\n";
					cout << "\n\t\t2.Assign A Patient To A Doctor\n";
					cout << "\n\t\t3.Edit Patient's Information\n";
					cout << "\n\t\t4.Display Patient's Information\n";
					cout << "\n\t\t5.Delete Patient's Information\n";
					cout << "\n\t\t6.No.Of Patients In The Hospital\n";
					cout << "\n\t\t7.Delete All The Contents In The Database\n";
					cout << "\n\t\t8.Display The Details Of All The Patients In The Hospital\n";
					cout << "\n\t\t9.Exit\n\n";
					cout << "********************************************************************************\n";
					int opt;
					cout << "\nPlease Choose Your Choice :";
					cin >> opt;
					int y;
					switch (opt)
					{
					case 1:
						system("CLS");
						add_patient_data();
						break;
					case 2:
						system("CLS");
						assign_patient();
						break;
					case 3:
						system("CLS");
						modify_patient_data();
						break;
					case 4:
						system("CLS");
						y = display_patient_data();
						if (y != 1)
						{
							cout << "\nNo Record To Display!!!\n";
							cout << "\n";
							system("PAUSE");
						}
						break;
					case 5:
						system("CLS");
						delete_patient_data();
						cout << "\n";
						system("PAUSE");
						break;
					case 6:
						system("CLS");
						cout << "\nNo.Of Patient's In The Hospital are :" << number();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 7:
						system("CLS");
						delete_contents1();
						cout << "\nAll The Contents Of The Database Are Deleted";
						cout << "\n\n";
						system("PAUSE");
						break;
					case 8:
						system("CLS");
						display1();
						cout << "\n\n";
						system("PAUSE");
						break;
					case 9:
						system("CLS");
						goto START3;
						_getch();
					}
				}
			}
			else
			{
				if (count >= 3)
				{
					system("CLS");
					cout << "\n\nAccess Denied!!!You Have Entered Wrong Password Too Many Times\n";
					cout << "\nThis System Will Shut Down.Please Come Back Again\n";
					cout << "\nThank You\n";
					cout << "\n";
					system("PAUSE");
					exit(0);
				}
				cout << "\n\nWrong Password.Access Denied!!!\n";
				goto START4;
			}
		case 3:
			system("CLS");
			cout << "\n\n";
			report();
			cout << "\n\n";
			system("PAUSE");
			goto START3;
			break;
		case 4:
			system("CLS");
			bill();
			cout << "\n\n";
			system("PAUSE");
			system("CLS");
			goto START3;
			break;

		case 5:
			cout << "\n";
			cout << "\n";
			goto START1;
		default:
			cout << "\nWrong Choice ";
		}
		break;
	case 2:
		cout << "\n\n";
		exit(0);
		break;
	default:
		cout << "\nWrong Choice ";
	}
	_getch();
}
void add_doctor_data()
{
	doctor d;
	ofstream myfile("doctor8.txt", ios::in | ios::app);
	d.get_info();
	myfile.write((char*)&d, sizeof(d));
	myfile.close();
}
void display()
{
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0;
	doctor d;
	size = size / (sizeof(d));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetails Of All The Doctors In The Hospital\n";
		cout << "********************************************************************************";
		cout << "\t" << "ID" << "\t\t" << "Specilization" << "\t\t" << "Qualification" << "\t\t" << "Age" << "\n";
		ifstream myfile("doctor8.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			cout << "\n\n";
			myfile.read((char*)&d, sizeof(d));
			d.display_all(d);
		}
		cout << "********************************************************************************";
	}
}
int display_doctor_data()
{
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, id, id1, count = 0;
	doctor d1;
	size = size / (sizeof(d1));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\nEnter The ID Of the Doctor You require :";
		cin >> id;
		ifstream myfile1("doctor8.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&d1, sizeof(d1));
			id1 = d1.get_ID();
			if (id == id1)
			{
				count = 1;
				d1.display_info(d1);
				cout << "\n";
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				break;
			}
		}
		myfile1.close();
		return(count);
	}
}

void modify_doctor_data()
{
	int id1;
	long int size = 0;
	size = get_size_of_the_file();
	int i = 0, count = 0, id;
	doctor d2;
	size = size / (sizeof(d2));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!\n";
		cout << "\nNo Record To Modify!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEnter The ID Of The Doctor To Modify Data :";
		cin >> id1;
		ifstream myfile2("doctor8.txt");
		for (i = 0; i < size; i++)
		{
			myfile2.clear();
			myfile2.read((char*)&d2, sizeof(d2));
			id = d2.get_ID();
			if (id == id1)
			{
				size = myfile2.tellg();
				size = size - sizeof(d2);
				count = 1;
				d2.display_info(d2);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				cout << "\nField's Which Can Be Modified\n";
				cout << "\n1.Name\n2.Age\n3.Qualification\n";
				cout << "4.Specilization\n5.Experience\n6.State\n";
				cout << "7.City\n";
				int opt2;
				cout << "\nSelect The Field Which You Want To Modify :";
				cin >> opt2;
				switch (opt2)
				{
				case 1:
					d2.modify_info(d2, opt2, size);
					break;
				case 2:
					d2.modify_info(d2, opt2, size);
					break;
				case 3:
					d2.modify_info(d2, opt2, size);
					break;
				case 4:
					d2.modify_info(d2, opt2, size);
					break;
				case 5:
					d2.modify_info(d2, opt2, size);
					break;
				case 6:
					d2.modify_info(d2, opt2, size);
					break;
				case 7:
					d2.modify_info(d2, opt2, size);
					break;
				default:
					cout << "\nWrong Choice ";
				}
				break;
			}
		}
		myfile2.close();
		if (count == 0)
		{
			cout << "\nRecord Does'nt Exist!!!";
			cout << "\n";
			system("PAUSE");
		}
	}
}
void delete_contents()
{
	ofstream myfile("doctor8.txt");
	myfile.close();
}
void delete_contents1()
{
	ofstream myfile("patient11.txt");
	myfile.close();
}

void delete_doctor_data()
{
	long int size;
	size = get_size_of_the_file();
	doctor d;
	size = size / (sizeof(d));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n\nNo Record To Delete!!!";
		cout << "\n";
	}
	else
	{
		ifstream myfile6("doctor8.txt");
		ofstream myfile7("temp1.txt");
		int id, count = 0, id1, i;
		cout << "\nEnter The ID Of The Doctor Whose Data You Want To Delete :";
		cin >> id;
		for (i = 0; i < size; i++)
		{
			myfile6.read((char*)&d, sizeof(d));
			id1 = d.get_ID();
			if (id != id1)
			{
				myfile7.write((char*)&d, sizeof(d));
			}
			else
			{
				count = 1;
			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("doctor8.txt");
		ifstream myfile8("temp1.txt");
		for (i = 0; i < size - 1; i++)
		{
			myfile8.read((char*)&d, sizeof(d));
			myfile9.write((char*)&d, sizeof(d));
		}
		if (count == 0)
		{
			cout << "\nNo Data Found ";
			cout << "\n\n";
			system("PAUSE");
		}
		else
		{
			cout << "\nData Successfully Deleted\n";
		}
	}
}


long int get_size_of_the_file()
{
	long int size = 0;
	ifstream ifile("doctor8.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);
}

void add_patient_data()
{
	patient p;
	ofstream myfile("patient11.txt", ios::in | ios::app);
	p.get_info();
	myfile.write((char*)&p, sizeof(p));
	myfile.close();
}
void display1()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0;
	patient p;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\n";
		cout << "********************************************************************************";
		cout << "\n\t\t\tDetails Of All The Patients In The Hospital\n";
		cout << "********************************************************************************";
		cout << "ID" << "\t" << "Age" << "\t" << "Illness" << "\t\t" << "Date Admitted" << "\t\t" << "Doctor's ID" << "\n";
		ifstream myfile("patient11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			cout << "\n\n";
			myfile.read((char*)&p, sizeof(p));
			p.display_all(p);
		}
		cout << "********************************************************************************";
	}
}

int display_patient_data()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	patient p1;
	size = size / (sizeof(p1));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1)
			{
				count1 = 1;
				p1.display_info(p1);
				cout << "\n\n";
				system("PAUSE");
				cout << "\n";
				break;
			}
		}
		myfile1.close();
		return(count1);

	}
}

void assign_patient()
{
	patient p;
	int id;
	long int size;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id1;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\n Database Empty!!!\n";
		cout << "\nYou Need To Add Patient's Information First!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEnter ID Of The Patient :";
		cin >> id;
		ifstream myfile("patient11.txt");
		myfile.seekg(0);
		for (i = 0; i < size; i++)
		{
			myfile.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1)
			{
				count = 1;
				size = myfile.tellg();
				size = size - sizeof(p);
				p.assign_patient_to_doctor(p, size);
				break;
			}
		}
		if (count == 0)
		{
			system("CLS");
			cout << "********************************************************************************";
			cout << "\nSorry!No Data Is Available Related To The Given ID\n";
			cout << "********************************************************************************";
			cout << "\n\n";
			system("PAUSE");
		}
	}
}


void modify_patient_data()
{
	int id1;
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, count = 0, id;
	patient p2;
	size = size / (sizeof(p2));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!\n";
		cout << "\nNo Record To Modify!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEnter The ID Of The Patient To Modify Data :";
		cin >> id1;
		ifstream myfile2("patient11.txt");
		myfile2.seekg(0);
		for (i = 0; i < size; i++)
		{
			myfile2.read((char*)&p2, sizeof(p2));
			id = p2.get_ID();
			if (id == id1)
			{
				size = myfile2.tellg();
				size = size - sizeof(p2);
				count = 1;
				p2.display_info(p2);
				cout << "\n";
				system("PAUSE");
				cout << "\n";
				cout << "\nField's Which Can Be Modified\n";
				cout << "\n1.Name\n2.Age\n3.Occupation\n4.State\n";
				cout << "5.City\n6.Phone Number\n7.Nationality\n";
				cout << "\n8.Street\n9.Door Number\n10.Condition\n";
				cout << "11.Discharge Condition\n12.Date Admitted\n";
				cout << "13.Date Discharged\n14.Patient Bill";
				int opt2;
				cout << "\nSelect The Field Which You Want To Modify :";
				cin >> opt2;
				switch (opt2)
				{
				case 1:
					p2.modify_info(p2, opt2, size);
					break;
				case 2:
					p2.modify_info(p2, opt2, size);
					break;
				case 3:
					p2.modify_info(p2, opt2, size);
					break;
				case 4:
					p2.modify_info(p2, opt2, size);
					break;
				case 5:
					p2.modify_info(p2, opt2, size);
					break;
				case 6:
					p2.modify_info(p2, opt2, size);
					break;
				case 7:
					p2.modify_info(p2, opt2, size);
					break;
				case 8:
					p2.modify_info(p2, opt2, size);
					break;
				case 9:
					p2.modify_info(p2, opt2, size);
					break;
				case 10:
					p2.modify_info(p2, opt2, size);
					break;
				case 11:
					p2.modify_info(p2, opt2, size);
					break;
				case 12:
					p2.modify_info(p2, opt2, size);
					break;
				case 13:
					p2.modify_info(p2, opt2, size);
					break;
				case 14:
					p2.modify_info(p2, opt2, size);
					break;
				default:
					cout << "\nWrong Choice ";
				}
				break;
			}
		}
		myfile2.close();
		if (count == 0)
		{
			cout << "\nRecord Does'nt Exist!!!";
			cout << "\n";
			system("PAUSE");
		}
	}
}
void delete_patient_data()
{
	long int size;
	size = get_size_of_the_file1();
	patient p;
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n\nNo Record To Delete!!!";
		cout << "\n";
	}
	else
	{
		ifstream myfile6("patient11.txt");
		ofstream myfile7("temp4.txt");
		int id, count = 0, id1, i;
		cout << "\nEnter The ID Of The Patient Whose Data You Want To Delete :";
		cin >> id;
		for (i = 0; i < size; i++)
		{
			myfile6.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id != id1)
			{
				myfile7.write((char*)&p, sizeof(p));
			}
			else
			{
				count = 1;
			}
		}
		myfile6.close();
		myfile7.close();
		ofstream myfile9("patient11.txt");
		ifstream myfile8("temp4.txt");
		for (i = 0; i < size - 1; i++)
		{
			myfile8.read((char*)&p, sizeof(p));
			myfile9.write((char*)&p, sizeof(p));
		}
		if (count == 0)
		{
			cout << "\nNo Data Found ";
			cout << "\n\n";

		}
		else
		{
			cout << "\nData Successfully Deleted ";
			cout << "\n\n";

		}
	}

}
long int get_size_of_the_file1()
{
	long int size = 0;
	ifstream ifile("patient11.txt");
	ifile.seekg(0, ios::end);
	size = ifile.tellg();
	ifile.close();
	return(size);
}

int number()
{
	long int size;
	patient p;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	return(size);
}

void report()
{
	patient p;
	int id, id1, count = 0;
	long int size;
	size = get_size_of_the_file1();
	size = size / (sizeof(p));
	if (size == 0)
	{
		cout << "\nPatient Database Empty!!!";
		cout << "\nAdd Some Patient's Info First!!!";
		cout << "\n\n";
		system("PAUSE");
	}
	else
	{
		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (int i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p, sizeof(p));
			id1 = p.get_ID();
			if (id == id1)
			{
				count = 1;
				p.report1(p);
				break;
			}
		}
		if (count == 0)
		{
			cout << "\nData Not Available!!!";
		}
	}
}
void bill()
{
	long int size = 0;
	size = get_size_of_the_file1();
	int i = 0, id, id1, count1 = 0;
	patient p1;
	size = size / (sizeof(p1));
	if (size == 0)
	{
		cout << "\nDatabase Empty!!!";
		cout << "\n";
	}
	else
	{
		cout << "\nEnter The ID Of The Patient You Require :";
		cin >> id;
		ifstream myfile1("patient11.txt");
		for (i = 0; i < size; i++)
		{
			myfile1.clear();
			myfile1.read((char*)&p1, sizeof(p1));
			id1 = p1.get_ID();
			if (id == id1)
			{
				count1 = 1;
				p1.bill1(p1);
				break;
			}
		}
		if (count1 == 0)
		{
			cout << "\nData Not Found!!!";
		}
		myfile1.close();
	}
}
