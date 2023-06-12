#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ofstream file;

class Calendar{
 private:
   int day;
   int month;
   int year;
 public:
   Calendar();
   Calendar(int day, int month, int year){
     this->day = day;
     this->month = month;
     this->year = year;
   }
   Calendar(const Calendar &d1){
    this->day = d1.day;
    this->month = d1.month;
    this->year = d1.year;
}
   void setDay(int day){
     this->day = day;
   }
   int getDay(){
     return day;
   }
   void setMonth(int month){
     this->month = month;
   }
   int getMonth(){
     return month;
   }
   void setYear(int year){
     this->year = year;
   }
   int getYear(){
     return year;
   }
};
Calendar :: Calendar(){
    day = 0;
    month = 0;
    year = 0;
}
///Въвеждаме днешната дата :
Calendar dneshnaData(6,12,2021);

class Student{
   private:
    string name;
    string fNum;
    Calendar birthDate;
    double avMarks;
   public:
    Student();
    Student(string name, string fNum, Calendar dataRojdenna, double avMarks) : birthDate(dataRojdenna){
        this->name = name;
        this->fNum = fNum;
        this->avMarks = avMarks;
    }
  void setName(string name){
     this->name = name;
   }
   string getName(){
     return name;
   }
  void setFNum(string fNum){
     this->fNum = fNum;
   }
   string getFNum(){
     return fNum;
   }
  void setBirthDate(Calendar birthDate){
     this->birthDate = birthDate;
   }
   Calendar getBirthDate(){
     return birthDate;
   }
  void setAvMarks(double avMarks){
     this->avMarks = avMarks;
   }
   double getAvMarks(){
     return avMarks;
   }

  int yearsOfAge(Calendar data);
};
   Student :: Student(){
    name = '\0';
    fNum = '\0';
    birthDate = Calendar(0, 0, 0);
    avMarks = 0;
   }

int Student :: yearsOfAge(Calendar data){
    int day,month,year, bday,bmonth,byear;

    day = data.getDay();
    month = data.getMonth();
    year = data.getYear();
    bday = getBirthDate().getDay();
    bmonth = getBirthDate().getMonth();
    byear = getBirthDate().getYear();

    if(month > bmonth){
        return year - byear;
    }
    else if(month < bmonth){
        return (year - byear) - 1;
    }
    else if(day >= bday){
        return year - byear;
    }
    else{
        return (year - byear) - 1;
    }

}

Student findMaxAvMarks(Student *students){
    int idx;
    int studentsSize = sizeof(students);
    double max = students[0].getAvMarks();
    for(int i=0; i<=studentsSize; i++){
        if(students[i].getAvMarks() > max){
            max = students[i].getAvMarks();
            idx = i;
        }
    }

return students[idx];
}
///Предефиниране на оператор <<
ostream& operator<<(ostream& os, Student& st){
    os << st.getName()<<" "<<"["<<st.getFNum()<<"]"<<endl;
    return os;

}
void studentsBtween18and26(Student *students){
    int studentsSize = sizeof(students);
    for(int i=0; i<=studentsSize; i++){
        if(students[i].yearsOfAge(dneshnaData)>=18 && students[i].yearsOfAge(Calendar(dneshnaData))<=26){
            cout<<students[i];
            cout<<endl;
            file<<students[i];
        }
    }
}



int main()
{
    cout << "Hello world!" << endl;
    cout<<endl;


    file.open("potokStudenti.txt");

    Student s1("Ivan Nikolov", "121219001", Calendar(2,4,1985), 3.66);
    Student s2("Angelina Stamova", "121219002", Calendar(14,7,1998), 4.12);
    Student s3("Aleksei Stoilov", "121218999", Calendar(3,12,1994), 5.17);
    Student s4("Ivelina Krumova", "121218777", Calendar(11,11,2001), 3.34);
    Student s5("Yordan Radichev", "121218321", Calendar(18,5,2002), 5.79);

    Student students [] = {s1, s2, s3, s4, s5};


    ///Дефинирайте метод, който по зададен параметър дата,
    ///връща възрастта на студента като брой навършени години.
    cout<<"Studentyt "<<s4.getName()<<" e na "<<s4.yearsOfAge(dneshnaData)<<" godini"<<endl;
    file<<"Studentyt "<<s4.getName()<<" e na "<<s4.yearsOfAge(dneshnaData)<<" godini"<<endl;


    ///Да се намери студента с максимален успех от потока.
    cout<<"\nStudent s nai-visok uspeh ot potoka: ";
    cout<<findMaxAvMarks(students).getName()<<" "<<"["<<findMaxAvMarks(students).getAvMarks()<<"]"<<endl;
    file<<"Student s nai-visok uspeh ot potoka: ";
    file<<findMaxAvMarks(students).getName()<<" "<<"["<<findMaxAvMarks(students).getAvMarks()<<"]"<<endl;


    ///Да се извеждат студентите от потока,
    ///които са между 18 и 26 години включително,
    ///като се предефинира операцията <<.

    cout<<"\nStudenti mejdu 18 i 26 godini vkl.: \n";
    file<<"\nStudenti mejdu 18 i 26 godini vkl.: \n";
    studentsBtween18and26(students);

    file.close();
    return 0;
}
