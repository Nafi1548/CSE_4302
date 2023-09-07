#include <iostream>
using namespace std;

class Student
{
private:
    string firstName, lastName;
    int id;
    int year;
    string course[10];
    float ob_marks[10];
    int course_count;
    
    int findIndex(string name)
    {
        for (int i = 0; i < course_count; i++)
        {
            if (name == course[i])
                return i;
        }
        return -1;
    }

public:
    static int stCount;
    Student(string frstName, string lstName, int s_id)
    {
        firstName = frstName;
        lastName = lstName;
        id = s_id;
        stCount++;
        cout<<stCount;
    }
    void enrollInCourses(string courseName)
    {
        course[course_count] = courseName;
        ob_marks[course_count] = 0;
        course_count++;
    }
    void obtainedMarks(string courseName, float marks)
    {
        int index = findIndex(courseName);
        ob_marks[index] = marks;
    }
    float setGPAForEachCourse(string courseName)
    {
        int index = findIndex(courseName);
        if (ob_marks[index] >= 80)
            return 4;
        else if (ob_marks[index] >= 75)
            return 3.75;
        else if (ob_marks[index] >= 75)
            return 3.75;
        else if (ob_marks[index] >= 60)
            return 3.25;
        else if (ob_marks[index] >= 50)
            return 3;
        else if (ob_marks[index] >= 40)
            return 2.5;
        else
            return 0;
    }
    float displayCGPA()
    {
        float total = 0;
        for (int i = 0; i < course_count; i++)
        {
            if (ob_marks[i] >= 80)
                total += 4;
            else if (ob_marks[i] >= 75)
                total += 3.75;
            else if (ob_marks[i] >= 75)
                total += 3.75;
            else if (ob_marks[i] >= 60)
                total += 3.25;
            else if (ob_marks[i] >= 50)
                total += 3;
            else if (ob_marks[i] >= 40)
                total += 2.5;
            else
                total += 0;
        }
        return total/course_count;
    }
    void willGraduate()
    {
        int FLAG = 0;
        for (int i = 0; i < course_count; i++)
        {
            if (ob_marks[i] <40)
            {
                cout<<"fail"<<endl;
            }
        }
                cout<<"pass"<<endl;
    }
    void applyForScholarship(){
        float total = displayCGPA();
        if(total > 3.8) cout<<"apply"<<endl;
        else cout<<"dont apply"<<endl;
    }
    void participateInInternship(string company,string courseName){
        float total = displayCGPA();
        if(total > 3.0)
        {
            int index = findIndex(courseName);
            if(index == -1) cout<<"can do iternship at" <<company<<endl;
            else cout<<"can't do iternship at" <<company<<endl;
        }
        else cout<<"can't do iternship at" <<company<<endl;      
    }

    ~Student(){ 
       cout<<firstName<<" "<<lastName<<"  "<<id<<' ';
       for(int i = 0;i<course_count;i++)
       {
          cout<<course[i]<<' ';
       }
       cout<<endl;
    }
};
int Student::stCount = 0;
int main(){
    Student student1("John", "Doe", 2000);
    student1.enrollInCourses("Math");
    student1.enrollInCourses("Physics");
    
    student1.obtainedMarks("Math", 85);
    student1.obtainedMarks("Physics", 78);
    

    Student student2("Alice", "Smith", 1999);
    
    student2.enrollInCourses("English");
    student2.enrollInCourses("Biology");
    
    student2.obtainedMarks("English", 88);
    student2.obtainedMarks("Biology", 95);

    Student student3("Bob", "Johnson", 2001);
    
    student3.enrollInCourses("Art");
    student3.enrollInCourses("Economics");
    
    student3.obtainedMarks("Art", 92);
    student3.obtainedMarks("Economics", 85);

    student1.willGraduate();
    student2.willGraduate();
    student3.willGraduate();

    student1.applyForScholarship();
    student2.applyForScholarship();
    student3.applyForScholarship();
}