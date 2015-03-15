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

    void mean_dist(point a,point b,fstream& f)//to find the point at which male or female prediction mean point reside.
    { if(f.good())
      {f.seekg(0,ios::beg);
      int ht,wt,gen,count_m=0,count_f=0,sum_m_x=0,
	  sum_m_y=0,sum_f_x=0,sum_f_y=0,avg_m_x,avg_m_y,avg_f_x,avg_f_y;
      while(f.eof()==0)
      { f>>ht;
	f>>wt;
	f>>gen;
	if(gen=='m'||gen=='M')
	{ sum_m_x=sum_m_x+ht;
	  count_m++;
	  sum_m_y=sum_m_y+wt;
	}
	else if(gen=='f'||gen=='F')
	{ sum_f_x=sum_f_x+ht;
	  sum_f_y=sum_f_y+wt;
	  count_f++;
	}

      }

      avg_m_x=sum_m_x/count_m;avg_m_y=sum_m_y/count_m;
      avg_f_x=sum_f_x/count_f;avg_f_y=sum_f_y/count_f;
      a.x=avg_m_x;a.y=avg_m_y;
      b.x=avg_f_x;b.y=avg_f_y;
      cout<<endl<<"Predictive point calculated.";
      }
      else{cout<<endl<<"file is not good still.";}
      //calculating the average distance between the points in cluster to select as the category defining point.
    }

    double dist(point a,point b)//to find distance between the new entry to predict and the male or female cluster mean positions.
    { double d;
      d=sqrt( pow((a.x-b.x),2) + pow((a.y-b.y),2));
      return d;
    }


void main(){

fstream file("database.tdxt",ios::nocreate,ios::app); //opening the database file.
clrscr();

struct point p,//points generated.
	     male,//for male cluster mean point.
	     female;//for female cluster mean point.

int option;
cout<<endl<<"Choose your action from the below options:"
    <<endl<<"1. provide data to learn."
    <<endl<<"2. Predict my gender.";
cin>>option;//take the option from user.

switch(option) //switch for option:: start
 { case 1:double h,w;char gen;
	  cout<<endl<<"Enter the height:";
	  cin>>h;
	  cout<<endl<<"Enter the weight:";
	  cin>>w;
	  cout<<endl<<"Enter the gender:[m/f] ";
	  cin>>gen;

	  if(file.good())//entering the learning data to the learning database.
	  { file<<h<<endl;
	    file<<w<<endl;
	    file<<gen<<endl;
	    cout<<"Learning database is updated. Thank you.";
	  }
	  else{cout<<endl<<"file is not good still.";}
   break;//to learn the relationship between the height:weight ratio and the gender(through K-map-cluster-algorithm)

   case 2:double ht,wt;
	  cout<<endl<<"Enter your height:";
	  cin>>ht;
	  cout<<endl<<"Enter your weight:";
	  cin>>wt;

	  mean_dist(male,female,file);
	  /*put the code here to fill the array of points with all
	  the data in database and then run the average point calculating
	  algorithm to generate the position of male and female
	  predictive positions(mean positions of the male and female cluster in the k map cluster).*/

	  p.x=ht;p.y=wt;
	  male.x=0;male.y=0;female.x=100;female.y=100;
	  double distance_m=dist(male,p),distance_f=dist(female,p);
	  //calculating the distance of the user point to the mean category predictive point.

	  if(distance_m>distance_f){cout<<endl<<"This data represents a female.";}
	  else{cout<<endl<<"This data represents a male.";}//the code prediction is being desplayed.

	  //now verifying the prediction to be true or not from the user.
	  char chk=' ',g;
	  cout<<endl<<"Was the prediction true? [y/n]::";
	  cin>>chk;
	  if(chk=='y'||chk=='Y')
	  { if(distance_m>distance_f){g='f';}
	    else{g='m';}
	  }
	  else if(chk=='n'||chk=='N')
	  { if(distance_m>distance_f){g='m';}
	    else{g='f';}
	  }

	  if(file.good())//filling the learning database according to the feedback.
	  {
	    while(file.eof()==0){}
	    file<<ht<<endl;
	    file<<wt<<endl;
	    file<<g<<endl;
	  }
	  else{cout<<endl<<"file is not good still.";}
   break;//to predict the users gender through the data provided..

   default:cout<<"Choose the options correctly\n press ENTER to reset.";
	  getch();main();
 }//switch end:

/*if(file.good())//verify if the file has opened correctly.
{ for(int i=0;i<10;i++)//inputting all the files data to the point array that we are using to predict the gender.
  { file>>p[i].x;
    file>>p[i].y;
    file>>p[i].gender;
  }
}*/

char ch=' ';
cout<<endl<<"Wanna Try Again::";//asking the user if he/she wants to try the code again.
 cin>>ch;
 if(ch=='y'||ch=='Y'){cout<<"press ENTER to reset:";main();}
 else if(ch=='n'||ch=='N'){exit(1);}

getch();
file.close();//file closed..
}
