#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class DateDefine
{
public:
    DateDefine(int Y = 0, int M = 0, int D = 0);
    friend ostream &operator<<(ostream &Out, DateDefine Date);
    friend istream &operator>>(istream &In, DateDefine Date);
    void SetYear(int Y);
    void SetMonth(int M);
    void SetDay(int D);
    void Set(int Y, int M, int D);

protected:
    int Year;
    int Month;
    int Day;
};
DateDefine::DateDefine(int Y, int M, int D)
{
    Year = Y;
    Month = M;
    Day = D;
}
ostream &operator<<(ostream &Out, DateDefine Date)
{
    Out << Date.Year << "-" << Date.Month << "-" << Date.Day;
    return Out;
}
istream &operator>>(istream &In, DateDefine Date)
{
    string DataTemp;
    getline(In, DataTemp, '-');
    Date.Year = atoi(DataTemp.c_str());
    getline(In, DataTemp, '-');
    Date.Month = atoi(DataTemp.c_str());
    cin >> DataTemp;
    Date.Day = atoi(DataTemp.c_str());
    return In;
}
void DateDefine::SetYear(int Y)
{
    Year = Y;
}
void DateDefine::SetMonth(int M)
{
    Month = M;
}
void DateDefine::SetDay(int D)
{
    Day = D;
}
void DateDefine::Set(int Y, int M, int D)
{
    SetYear(Y);
    SetMonth(M);
    SetDay(D);
}

class Student
{
public:
    Student(int SID = 0, string SN = "", string G = "", unsigned int A = 0, string C = "");
    ~Student();
    friend class Student_Collection;
    int GetID();

protected:
    int StuID;
    string StuName;
    string Gender;
    unsigned int Age;
    string Class;
};
Student::Student(int SID, string SN, string G, unsigned int A, string C)
{
    StuID = SID;
    StuName = SN;
    Gender = G;
    Age = A;
    Class = C;
}
Student::~Student()
{
}
int Student::GetID()
{
    return StuID;
}

class Student_Collection
{
public:
    Student_Collection();
    ~Student_Collection();
    void ReadFile(string F = "SASStudent.txt");
    void WriteFile(string F = "SASStudent.txt");
    bool CheckDuplicateID(int SID);
    void Search();
    int Search_StuID(int SID);
    int Search_StuName(string StuName);
    void Create(int SID, string SN, string G, unsigned int A, string C);
    void Create(string SN, string G, unsigned int A, string C);
    void Update(int Mark);
    void Delete(int Mark);

protected:
    vector<Student> StudentCollection;
};
Student_Collection::Student_Collection()
{
}
Student_Collection::~Student_Collection()
{
}
void Student_Collection::ReadFile(string F)
{
    ifstream File(F);
    Student Temp;
    while (!File.eof())
    {
        File >> Temp.StuID >> Temp.StuName >> Temp.Gender >> Temp.Age >> Temp.Class;
        StudentCollection.push_back(Temp);
    }
    File.close();
}
void Student_Collection::WriteFile(string F)
{
    ofstream File(F);
    for (int i = 0; i < StudentCollection.size(); ++i)
    {
        File << StudentCollection[i].StuID << " " << StudentCollection[i].StuName << " " << StudentCollection[i].Gender << " " << StudentCollection[i].Age << " " << StudentCollection[i].Class << endl;
    }
    File.close();
}
bool Student_Collection::CheckDuplicateID(int SID)
{
    for (int i = 0; i < StudentCollection.size(); ++i)
    {
        if (StudentCollection[i].StuID == SID)
        {
            return true;
        }
    }
    return false;
}
void Student_Collection::Search()
{
    cout << "Place select the number of corresponding commands(1.Search by ID 2.Search by name):";
    int Select;
    cin >> Select;
    if (Select == 1)
    {
        cout << "Place enter the student ID:";
        int SID;
        cin >> SID;
        Search_StuID(SID);
    }
    else if (Select == 2)
    {
        cout << "Place enter the student name:";
        string SN;
        cin >> SN;
        Search_StuName(SN);
    }
}
int Student_Collection::Search_StuID(int SID)
{
    for (int i = 0; i < StudentCollection.size(); ++i)
    {
        if (StudentCollection[i].StuID == SID)
        {
            return i;
        }
    }
    return -1;
}
int Student_Collection::Search_StuName(string SN)
{
    int Flag = 0, Record = -1;
    for (int i = 0; i < StudentCollection.size(); ++i)
    {
        if (StudentCollection[i].StuName == SN)
        {
            if (Flag = 0)
            {
                Record = i;
                Flag = 1;
            }
            else
            {
                cout << "Find mutiple values, place search by ID(Place enter the ID):";
                int SID;
                cin >> SID;
                return Search_StuID(SID);
            }
        }
    }
    return Record;
}
void Student_Collection::Create(int SID, string SN, string G, unsigned int A, string C)
{
    if (!CheckDuplicateID(SID))
    {
        StudentCollection.push_back(Student(SID, SN, G, A, C));
    }
}
void Student_Collection::Create(string SN, string G, unsigned int A, string C)
{
    StudentCollection.push_back(Student(StudentCollection.size() + 10000001, SN, G, A, C));
}
void Student_Collection::Update(int Mark)
{
    cout << "Plase enter what you want to Update:";
    string Need_Update;
    cin >> Need_Update;
    if (Need_Update.find("ID") != string::npos || Need_Update.find("学号") != string::npos || Need_Update.find("xuehao") != string::npos)
    {
        cout << "Plase enter the student's ID(enter \"exit\" to abandon):";
        string WillUpdate;
        cin >> WillUpdate;
        while (CheckDuplicateID(atoi(WillUpdate.c_str())))
        {
            cout << "the student's ID is repeat, plase re-enter:";
            cin >> WillUpdate;
            if (WillUpdate.find("exit") != string::npos)
            {
                break;
            }
        }
        if (WillUpdate.find("exit") == string::npos)
        {
            StudentCollection[Mark].StuID = atoi(WillUpdate.c_str());
        }
    }
    if (Need_Update.find("Name") != string::npos || Need_Update.find("name") != string::npos || Need_Update.find("姓名") != string::npos || Need_Update.find("xingming") != string::npos)
    {
        cout << "Plase enter the name(enter \"exit\" to abandon):";
        string WillUpdate;
        cin >> WillUpdate;
        if (WillUpdate.find("exit") == string::npos)
        {
            StudentCollection[Mark].StuName = WillUpdate;
        }
    }
    if (Need_Update.find("Gender") != string::npos || Need_Update.find("gender") != string::npos || Need_Update.find("性别") != string::npos || Need_Update.find("xingbie") != string::npos)
    {
        cout << "Plase enter the gender(Male or Female)(enter \"exit\" to abandon):";
        string WillUpdate;
        cin >> WillUpdate;
        if (WillUpdate.find("exit") == string::npos)
        {
            StudentCollection[Mark].Gender = WillUpdate;
        }
    }
    if (Need_Update.find("Age") != string::npos || Need_Update.find("age") != string::npos || Need_Update.find("年龄") != string::npos || Need_Update.find("nianling") != string::npos)
    {
        cout << "Plase enter the age(enter \"exit\" to abandon):";
        string WillUpdate;
        cin >> WillUpdate;
        if (WillUpdate.find("exit") == string::npos)
        {
            StudentCollection[Mark].Age = atoi(WillUpdate.c_str());
        }
    }
    if (Need_Update.find("Class") != string::npos || Need_Update.find("class") != string::npos || Need_Update.find("班级") != string::npos || Need_Update.find("banji") != string::npos)
    {
        cout << "Plase enter the class(enter \"exit\" to abandon):";
        string WillUpdate;
        cin >> WillUpdate;
        if (WillUpdate.find("exit") == string::npos)
        {
            StudentCollection[Mark].Class = WillUpdate;
        }
    }
}
void Student_Collection::Delete(int Mark)
{
    StudentCollection.erase(StudentCollection.begin() + Mark);
}

class Class
{
public:
    Class(string CN = "", float C = 0, DateDefine ST = DateDefine());
    ~Class();
    friend class Class_Collection;
    void Set(string CN = "", float C = 0, DateDefine ST = DateDefine());

protected:
    string ClassName;
    float Credit;
    DateDefine StartTime;
};
Class::Class(string CN, float C, DateDefine ST)
{
    Set(CN, C, ST);
}
Class::~Class()
{
}
void Class::Set(string CN, float C, DateDefine ST)
{
    ClassName = CN;
    Credit = C;
    StartTime = ST;
}

class Class_Collection
{
public:
    Class_Collection();
    ~Class_Collection();
    void ReadFile(string F = "SASClass.txt");
    void WriteFile(string F = "SASClass.txt");

protected:
    vector<Class> ClassCollection;
};
Class_Collection::Class_Collection()
{
}
Class_Collection::~Class_Collection()
{
}
void Class_Collection::ReadFile(string F)
{
    ifstream File(F);
    Class Temp;
    while (!File.eof())
    {
        File >> Temp.ClassName >> Temp.Credit >> Temp.StartTime;
        ClassCollection.push_back(Temp);
    }
    File.close();
}
void Class_Collection::WriteFile(string F)
{
    ofstream File(F);
    for (int i = 0; i < ClassCollection.size(); ++i)
    {
        File << ClassCollection[i].ClassName << " " << ClassCollection[i].Credit << " " << ClassCollection[i].StartTime << endl;
    }
    File.close();
}

class Teacher
{
public:
    Teacher(int TID = 0, string TN = "", string TT = "");
    ~Teacher();
    friend class Teacher_Collection;
    void Set(int TID, string TN, string TT);
    int GetID();

protected:
    int TeacherID;
    string TeacherName;
    string TeacherTitle;
};
Teacher::Teacher(int TID, string TN, string TT)
{
    Set(TID, TN, TT);
}
Teacher::~Teacher()
{
}
void Teacher::Set(int TID, string TN, string TT)
{
    TeacherID = TID;
    TeacherName = TN;
    TeacherTitle = TT;
}
int Teacher::GetID()
{
    return TeacherID;
}

class Teacher_Collection
{
public:
    Teacher_Collection();
    ~Teacher_Collection();
    void ReadFile(string F = "SASTeacher.txt");
    void WriteFile(string F = "SASTeacher.txt");

protected:
    vector<Teacher> TeacherCollection;
};
Teacher_Collection::Teacher_Collection()
{
}
Teacher_Collection::~Teacher_Collection()
{
}
void Teacher_Collection::ReadFile(string F)
{
    ifstream File(F);
    Teacher Temp;
    while (!File.eof())
    {
        File >> Temp.TeacherID >> Temp.TeacherName >> Temp.TeacherTitle;
        TeacherCollection.push_back(Temp);
    }
    File.close();
}
void Teacher_Collection::WriteFile(string F)
{
    ofstream File(F);
    for (int i = 0; i < TeacherCollection.size(); ++i)
    {
        File << TeacherCollection[i].TeacherID << " " << TeacherCollection[i].TeacherName << " " << TeacherCollection[i].TeacherTitle << endl;
    }
    File.close();
}

class Attendance
{
public:
    Attendance(DateDefine AD = DateDefine(), int CN = 0, string CI = NULL, string SI = NULL, string AT = "");
    ~Attendance();
    friend class Attendance_Collection;
    void Set(DateDefine AD, int CN, string CI, string SI, string AT);

protected:
    DateDefine AbsenceDate;
    int CourseNumber;
    string CourseInformation;
    string StudentInformation;
    string AbsenceType;
};
Attendance::Attendance(DateDefine AD, int CN, string CI, string SI, string AT)
{
    Set(AD, CN, CI, SI, AT);
}
Attendance::~Attendance()
{
}
void Attendance::Set(DateDefine AD, int CN, string CI, string SI, string AT)
{
    AbsenceDate = AD;
    CourseNumber = CN;
    CourseInformation = CI;
    StudentInformation = SI;
    AbsenceType = AT;
}

class Attendance_Collection
{
public:
    Attendance_Collection();
    ~Attendance_Collection();
    void ReadFile(string F = "SASAttendance.txt");
    void WriteFile(string F = "SASAttendance.txt");
    void Create(DateDefine AD, int CN, string CI, string SI, string AT);

protected:
    vector<Attendance> AttendanceCollection;
};
Attendance_Collection::Attendance_Collection()
{
}
Attendance_Collection::~Attendance_Collection()
{
}
void Attendance_Collection::ReadFile(string F)
{
    ifstream File(F);
    Attendance Temp;
    while (!File.eof())
    {
        File >> Temp.AbsenceDate >> Temp.CourseNumber >> Temp.CourseInformation >> Temp.StudentInformation >> Temp.AbsenceType;
        AttendanceCollection.push_back(Temp);
    }
    File.close();
}
void Attendance_Collection::WriteFile(string F)
{
    ofstream File(F);
    for (int i = 0; i < AttendanceCollection.size(); ++i)
    {
        File << AttendanceCollection[i].AbsenceDate << " " << AttendanceCollection[i].CourseNumber << " " << AttendanceCollection[i].CourseInformation << " " << AttendanceCollection[i].StudentInformation << " " << AttendanceCollection[i].AbsenceType << endl;
    }
    File.close();
}
void Attendance_Collection::Create(DateDefine AD, int CN, string CI, string SI, string AT)
{
    AttendanceCollection.push_back(Attendance(AD, CN, CI, SI, AT));
}

class Manage : public Student_Collection, public Teacher_Collection, public Attendance_Collection
{
public:
    Manage();
    ~Manage();
    void ReadFile();
    void ReadFile(string SL, string TC, string AC);
    void WriteFile();
    void WriteFile(string SL, string TC, string AC);
    bool Authenticate(string Identity, int ID);
    void AddFunction_Student();
    void AddFunction_Attendance();

protected:
    string Identity;
};
Manage::Manage()
{
    Identity = "";
}
Manage::~Manage()
{
}
void Manage::ReadFile()
{
    Student_Collection::ReadFile();
    Teacher_Collection::ReadFile();
    Attendance_Collection::ReadFile();
}
void Manage::ReadFile(string SL, string TC, string AC)
{
    Student_Collection::ReadFile(SL);
    Teacher_Collection::ReadFile(TC);
    Attendance_Collection::ReadFile(AC);
}
void Manage::WriteFile()
{
    Student_Collection::WriteFile();
    Teacher_Collection::WriteFile();
    Attendance_Collection::WriteFile();
}
void Manage::WriteFile(string SL, string TC, string AC)
{
    Student_Collection::WriteFile(SL);
    Teacher_Collection::WriteFile(TC);
    Attendance_Collection::WriteFile(AC);
}
bool Manage::Authenticate(string I, int ID)
{
    if (I[0] == 'T' || I[0] == 't')
    {
        for (int i = 0; i < TeacherCollection.size(); ++i)
        {
            if (ID == TeacherCollection[i].GetID())
            {
                Identity = "Teacher";
                return true;
            }
        }
    }
    else if (I[0] == 'S' || I[0] == 's')
    {
        for (int i = 0; i < StudentCollection.size(); ++i)
        {
            if (ID == StudentCollection[i].GetID())
            {
                Identity = "Student";
                return true;
            }
        }
    }
    return false;
}
void Manage::AddFunction_Student()
{
    cout << "Please enter the student's ID(Enter \"auto\" will generate numbers automatically):" << endl;
    string SID;
    cin >> SID;
    cout << "Please enter the student's Name:" << endl;
    string SN;
    cin >> SN;
    cout << "Please enter the student's gender(Male or Female):" << endl;
    string G;
    cin >> G;
    cout << "Please enter the student's age:" << endl;
    int A;
    cin >> A;
    cout << "Please enter the student's class:" << endl;
    string C;
    cin >> C;
    if (SID == "auto" || SID == "Auto")
    {
        Student_Collection::Create(SN, G, A, C);
    }
    else 
    {
        Student_Collection::Create(atoi(SID.c_str()), SN, G, A, C);
    }
}
void Manage::AddFunction_Attendance()
{

}

int main(void)
{
    return 0;
}