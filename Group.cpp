#include "Group.h"

Group::Group() 
{
    SetGroupName("P26");
    SetCourse(3);
    SetSpecialization("Programmer and software developer");
}

void Group::Print() const
{
    cout << groupName << "\n";
    for (int i = 0; i < size; i++)
    {
        students[i].AverageGrade();
        students[i].PrintStudent();
    }
}

void Group::NewStudent(const Student& newstudent)
{
    countstudents++;
    students.push_back(newstudent);
}

void Group::ExcludedStudent(unsigned short index)
{
    {
        if (index < students.size()) {
            students.erase(students.begin() + index);
            countstudents--;
        }
}

void Group::LaggingStudent()
{
    if (countstudents == 0) {
        cout << "The group is done\n\n";
        return;
    }
    int minGradeIndex = 0;
    for (int i = 1; i < countstudents; i++)
    {
        if (students[i].GetAverageGrade() < students[minGradeIndex].GetAverageGrade())
        {
            minGradeIndex = i;
        }
    }
    students.erase(students.begin() + minGradeIndex);
    countstudents--;
    cout << "The student with the lowest grade is expelled\n";
}
void Group::SetCountOfStudent(int size)
{
    this->size = size;
}

int Group::GetCountOfStudent() const
{
    return size;
}

    void Group::SetGroupName(const string& groupName) {
        this->groupName = groupName;
    }

    string Group::GetGroupName() const {
        return groupName;
    }

    void Group::SetSpecialization(const string& specialization) {
        this->specialization = specialization;
    }

    string Group::GetSpecialization() const {
        return specialization;
    }

    void Group::SetCourse(int course) {
        this->course = course;
    }

    int Group::GetCourse() const {
        return course;
    }

    void Group::PrintAllStudents() const {
        cout << GetGroupName() << "\n";

        for (int i = 0; i < size; ++i) {
            students[i]->PrintStudent();
        }
    }

    };