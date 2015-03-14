/*This code is working on the file :database.txt:,
and that file require to be at the same directory as the code.*/

#include<iostream.h> //all required pre-requisites applied.
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<math.h>

struct point
{ double x,y;
  char gender;
}; //creating our individual data as points object to evaluate later.

    int mean_dist(point p,point a[],int x)//to find the point at which male or female prediction mean point reside.
    { double sum_x=0,avg_x,sum_y=0,avg_y;
      for(int i=0;i<x;i++){sum_x=sum_x+a[i].x;sum_y=sum_y+a[i].y;}
      avg_x=sum_x/x;
      avg_y=sum_y/x;
      p.x=avg_x;
      p.y=avg_y;
      //calculating the average distance between the points in cluster to select as the category defining point.
      return 0;
    }

    double dist(point a,point b)//to find distance between the new entry to predict and the male or female cluster mean positions.
    { double d;
      d=sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2));
      return d;
    }


void main(){

ifstream file("database.txt",ios::nocreate); //opening the database file.
clrscr();

struct point p[50],//array of points generated.
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

   case 2:double h,w;
	  cout<<endl<<"Enter your height:";
	  cin>>h;
	  cout<<endl<<"Enter your weight:";
	  cin>>w;
	  p[0].x=h;p[0].y=w;
	  male.x=0;male.y=0;female.x=100;female.y=100;
	  double distance_m=dist(male,p[0]),distance_f=dist(female,p[0]);
	  //calculating the distance of the user point to the mean category predictive point.
	  if(distance_m>distance_f){cout<<endl<<"This data represents a female.";}
	  else{cout<<endl<<"This data represents a male.";}
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
