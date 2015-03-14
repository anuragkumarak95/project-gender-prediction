/*This code is working on the file :database.txt:,
and that file require to be at the same directory as the code.*/

#include<iostream.h> //all required pre-requisites applied.
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>

class point //creating our individual data as points object to evaluate later.
{public:
  int x,y;
  char gender;
    point(){x=0;
	    y=0;
	    gender='M';}
    int mean_dist(point a)//to find the point at which male or female prediction mean point reside.
    { //what is the equation of calculating mean in grapgic geometry.
      return 0;
    }
    int dist(point a,point b)//to find distance between the new entry to predict and the male or female cluster mean positions.
    { int d;
      d=0/*??*/;
      return d;
    }
};

void main(){

ifstream file("database.txt",ios::nocreate); //opening the database file.
clrscr();

class point p[50],//array of points generated.
      male,//for male cluster mean point.
      female;//for female cluster mean point.

int option;
cout<<endl<<"Choose your action from the below options:"
    <<endl<<"1. provide data to learn."
    <<endl<<"2. Predict my gender.";
cin>>option;//take the option from user.

switch(option) //switch for option:: start
 { case 1:
   break;//to learn the relationship between the height:weight ratio and the gender(through K-map-cluster-algorithm)

   case 2:int h,w;
	  cout<<endl<<"Enter your height:";
	  cin>>h;
	  cout<<endl<<"Enter your weight:";
	  cin>>w;
	  h=p[0].x;w=p[0].y;

   break;//to predict the users gender through the data provided..

   default:cout<<"Choose the options correctly\n press ENTER to reset.";
	   getch();main();
 }//switch end:

if(file.good())//verify if the file has opened correctly.
{ for(int i=0;i<10;i++)//inputting all the files data to the point array that we are using to predict the gender.
  { file>>p[i].x;
    file>>p[i].y;
    file>>p[i].gender;
  }
}

char ch=' ';
cout<<endl<<"Wanna Try Again::";//asking the user if he/she wants to try the code again.
 cin>>ch;
 if(ch=='y'||ch=='Y'){cout<<"press ENTER to reset:";main();}
 else if(ch=='n'||ch=='N'){exit(1);}

getch();
file.close();//file closed..
}
