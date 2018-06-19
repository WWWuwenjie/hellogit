

#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct student
{
string name,gender;
bool sex;
double score;
student(){};
student(string _name,string _gender,double _score):name(_name),gender(_gender),score(_score){};

void judsex(){sex=(gender=="Male");}
bool operator<(const student &a)const
{
   return (score>a.score)||((score==a.score)&&(name<a.name));
}
};

vector<student>all,male,female;

double average(vector<student>&stu)
{
double sum=0;
for(auto x:stu) sum+=x.score;

return sum/(double)stu.size();
}

int main(){
    string buffer;

    freopen("score.csv","r",stdin);

    getline(cin,buffer);
    string name,gender;
    string score;

    while(getline(cin,buffer))
    {
      stringstream ss(buffer);

      getline(ss,name,',');
      getline(ss,gender,',');
      getline(ss,score,',');
      gender.erase(0,1);
      score.erase(0,1);
      double sc=stod(score);

      student stu(name,gender,sc);

      stu.judsex();
      if(stu.sex) male.push_back(stu);
      else female.push_back(stu);
      all.push_back(stu);
     }
cout<<"The average score of all the students: "<<average(all)<<endl
    <<"The average score of all male students: "<<average(male)<<endl
    <<"The average score of all female students: "<<average(female)<<endl;

sort(all.begin(),all.end());
cout<<"Name"<<"      "<<"Gender"<<"      "<<"Score"<<endl;
for(auto x:all)
{
  cout<<x.name<<"      ";
  if(x.sex) cout<<"Male"<<"      ";
  else cout<<"Female"<<"      ";
  cout<<x.score<<"      "<<endl;
}
    
    return 0;
}

