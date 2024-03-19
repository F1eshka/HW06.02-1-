#include "Logger.h"
#include "Student.h"
#include <iostream>
using namespace std;

    /// <summary>
    /// ����������� ����������� ������ Student.
    /// ������� ����� �������� �� ������ ����������� �������.
    /// </summary>
    /// <param name="original">������������ �������, ������� ����� ����������.</param>
    

    /// <summary>
    ///  ����������� �� ��������� ������ Student.
    /// �������������� �������� ���������� �� ���������.
    /// </summary>
    Student::Student() : Student("Benoeva", "Malika", "Khasanovna", "Filatovo 7", "0734054475") { Logger::GetInstance()->Write("Student has been created\n"); }

    /// <summary>
    /// ����������� ������ Student.
    /// �������������� �������� � ����������� ����������.
    /// </summary>
    /// <param name="surname">������� ��������.</param>
    /// <param name="name">��� ��������.</param>
    /// <param name="middlname">�������� ��������.</param>
    /// <param name="adress">����� ��������.</param>
    /// <param name="phonenumber">����� �������� ��������.</param>
    Student::Student(string surname, string name, string middlname, string adress, string phonenumber)
    {
        count++;
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone(phonenumber);
    }
    
    Student::Student(string surname, string name, string middlname, string adress) :Student(surname, name, middlename, adress, "0674078044") { count++; }


    /// <summary>
    /// ���������� ������ Student.
    /// ����������� ������, ������� ��������� ������.
    /// </summary>
    Student::~Student()
    {
        count--;
        //if (grade_of_practic != nullptr)
        //    delete[] grade_of_practic;
        //if (grade_of_homework != nullptr)
        //    delete[] grade_of_homework;
        //if (grade_of_exam != nullptr)
         //   delete[] grade_of_exam;
    }

   
    /// <summary>
    /// ������� ���������� � �������� � �������.
    /// </summary>
    void Student::PrintStudent() const
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "PhoneNumber: " << phonenumber << "\n";
        PrintExam();
        PrintPractic();
        PrintHomeWork();

    }

    unsigned int Student::GetCount()
    {
        return count;
    }

    void  Student::AverageGrade()
    {

        for (int i = 0; i < grade_of_exam.size(); i++)
        {
            averagegrade += grade_of_exam[i] / grade_of_exam.size();
        }
        cout << averagegrade << "\n";
    }



    /// <summary>
    /// ��������� ����� ������ �� �������� ��������.
    /// </summary>
    /// <param name="newcountry">����� ������ �� ��������.</param>
    void Student::AddPractic(int newpractic)
    {
        grade_of_practic.push_back(newpractic);
    }


    /// <summary>
    /// ������� ������ �� �������� �������� � �������.
    /// </summary>
    void Student::PrintPractic() const
    {
        cout << "Practic:  ";
        for (int i = 0; i < grade_of_practic.size(); i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// �������� ������ �� �������� �������� �� ���������� �������.
    /// </summary>
    /// <param name="index">������ ������ �� ��������</param>
    /// <returns>������ �� �������� �� ���������� �������</returns>
    int Student::GePracticRatesCount(unsigned int index) const
    {
        return grade_of_practic.at(index);
    }


    /// <summary>
    /// ��������� ����� ������ �� �������� ������ ��������
    /// </summary>
    /// <param name="newcountry">����� ������ �� �������� ������</param>
    void Student::AddHomeWork(int new_homework)
    {
        grade_of_homework.push_back(new_homework);
    }

    /// <summary>
    /// ������� ������ �� �������� ������ �������� � �������.
    /// </summary>
    void Student::PrintHomeWork() const
    {
        cout << "HomeWork:  ";
        for (int i = 0; i < grade_of_homework.size(); i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// �������� ������ �� �������� ������ �������� �� ���������� �������.
    /// </summary>
    /// <param name="index">������ ������ �� �������� ������</param>
    /// <returns>������ �� �������� ������ �� ���������� �������</returns>
    int Student::GetHomeWorkRatesCount(unsigned int index) const
    {
        return grade_of_homework.at(index);
    }

    /// <summary>
    /// ��������� ����� ������ �� ������� ��������
    /// </summary>
    /// <param name="newcountry">����� ������ �� �������</param>
    void Student::AddExam(int newexam)
    {
        grade_of_exam.push_back(newexam);
    }


    /// <summary>
    /// ������� ������ �� ������� �������� � �������
    /// </summary>
    void Student::PrintExam() const
    {
        cout << "Exam:  ";
        for (int i = 0; i < grade_of_exam.size(); i++)
        {
            cout << grade_of_exam[i] << ",";
        }
        cout << "\n";
    }

    /// <summary>
    /// �������� ������ �� ������� �������� �� ���������� �������
    /// </summary>
    /// <param name="index">������ ������ �� �������</param>
    /// <returns>������ �� ������� �� ���������� �������</returns>
    int Student::GetExamRatesCount(unsigned int index) const
    {
        return grade_of_exam.at(index);
    }

    /// <summary>
    /// ������������� ������� ��������
    /// </summary>
    /// <param name="surname">����� ������� ��������</param>
    void Student::SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// ���������� ������� ��������
    /// </summary>
    /// <returns>������� ��������</returns>
    string Student::GetSurname() const
    {
        return surname;
    }

    /// <summary>
    /// ������������� ��� ��������
    /// </summary>
    /// <param name="name">����� ��� ��������</param>
    void Student::SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// ���������� ��� ��������
    /// </summary>
    /// <returns>��� ��������</returns>
    string Student::GetName() const
    {
        return name;
    }

    /// <summary>
    /// ������������� �������� ��������
    /// </summary>
    /// <param name="middlname">����� �������� ��������</param>
    void Student::SetMiddlName(string middlname)
    {
        this->middlename = middlname;
    }

    /// <summary>
    /// ���������� �������� ��������
    /// </summary>
    /// <returns>�������� ��������</returns>
    string Student::GetMiddlName() const
    {
        return middlename;
    }

    /// <summary>
    /// ������������� ����� ��������
    /// </summary>
    /// <param name="adress">����� ����� ��������</param>
    void Student::SetAdress(string adress)
    {
        this->adress = adress;
    }

    /// <summary>
    /// ���������� ����� ��������
    /// </summary>
    /// <returns>����� ��������</returns>
    string Student::GetAdress() const
    {
        return adress;
    }

    /// <summary>
    ///  ������������� ����� �������� ��������
    /// </summary>
    /// <param name="phonenumber">����� ����� �������� ��������</param>
    void Student::SetPhone(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }

    /// <summary>
    /// ���������� ����� �������� ��������
    /// </summary>
    /// <returns>����� �������� ��������</returns>
    string Student::GetPhone() const
    {
        return phonenumber;
    }

    /// <summary>
    /// ����� ��� ������������ ������ � ��������� �������� �� ��������.
    /// </summary>
    /// <param name="s">�������, ������� ����� �������</param>
    void Student::GoToPeresdacha(Student s)
{
    cout << "hey hey peresdacha...\n";
}
    void Student::SetAverageGrade(int averagegrade)
    {
        this->averagegrade = averagegrade;
    }
    int Student::GetAverageGrade() const
    {
        return averagegrade;
    }

    unsigned int Student::count;