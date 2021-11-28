#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int k = 0;
class s
{
char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
void install();
void allotment();
void empty();
void show();
void avail();
void position(int i);
}
bus[10];
void vline(char ch)
{
for(int i = 80; i>0; i--)
cout<<ch;
}
void s::install()
{
 cout<<"Enter bus number: "<<endl;
 cin>>bus[k].busn;
 cout<<"Enter Driver's name: "<<endl;
 cin>>bus[k].driver;
 cout<<"Arrival time: "<<endl;
 cin>>bus[k].arrival;
 cout<<"Departure: "<<endl;
 cin>>bus[k].depart;
 cout<<"From: \t\t\t"<<endl;
 cin>>bus[k].from;
 cout<<"to: \t\t\t"<<endl;
 cin>>bus[k].to;
 bus[k].empty();
 k++;
 }
 void s::allotment()
 {
 int seat;
 char number[5];
 top:
 cout<<"Bus number: "<<endl;
 cin>>number;
 int n;
 for(n=0;n<=k;n++)
 {
 if(strcmp(bus[n].busn, number)==0)
 break;
 }
 while(n<=k)
 {
 cout<<"Seat number: "<<endl;
 cin>>seat;
 if(seat>32)
 {
 cout<<"There are only 32 seats available in this bus"<<endl;
 }
 else
 {
 if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
 {
 cout<<"Enter passenger's name: "<<endl;
 cin>>bus[n].seat[seat/4][(seat%4)-1];
 break;
 }
 else
 cout<<"The seat number is already reserved"<<endl;
 }
 }
 if(n>k)
 {
 cout<<"Enter correct bus number"<<endl;
 goto top;
 }
 }
 void s::empty()
 {
 for(int i=0;i<8;i++)
 {
 for(int j=o;j<4;j++)
 {
 strcpy(bus[k].seat[i][j], "Empty");
 }
}
}
void s::show()
{
int n;
char number[5];
cout<<"Enter bus number: "<<endl;
cin>>number;
for(n=0;n<=k;n++)
{
if(strcmp(bus[n].busn, number)==0)
break;
}
while(n<=k)
{
vline('*');
cout<<"Bus number: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\nDeparture time: "<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from
<<"\t\tTo: \t\t"<<bus[n].to<<endl;
vline('*');
bus[0].position(n);
int s=1;
for(int i=0;i<8;i++)
{
for(int j=0;j<4;j++)
{
s++;
if(strcmp(bus[n].seat[i][j], "Empty")!=0)
cout<<"The seat number: "<<(s-1)<<" is served for "<<bus[n].seat[i][j]<<".";
}
}
break;
}
if(n>k)
cout<<"Enter correct bus number: "<<endl;
}
void s::position(int a)
{
int b=0;k=0;
for(int i=0;i<8;i++)
{
cout<<endl;
for(int j=0;j<4;j++)
{
b++;
if(strcmp(bus[a].seat[i][j], "Empty")==0)
{
cout.width(5);
cout.fill(' ');
cout<<b<<".";
cout.width(10);
cout.fill(' ');
cout<<bus[a].seat[i][j];
k++;
}
else
{
cout.width(5);
cout.fill(' ');
cout<<b<<".";
cout.width(10);
cout.fill(' ');
cout<<bus[a].seat[i][j];
}
}
}
cout<<"\n\nThere are "<<k<<"seats empty in Bus number: "<<bus[a].busn;
}
void s::avail()
{
for(int n=0;n<k;n++)
{
vline('*');
cout<<"Bus number: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\nDeparture time: "<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from
<<"\t\tTo: \t\t"<<bus[n].to<<endl;
vline('*');
vline('_');
}
}

int main()
{
system("cls");
int w;
while(1)
{
cout<<"\n\n\n\n\n";
cout<<"\t\t\t1.Install\n\t\t\t"
<<"2.Reservation\n\t\t\t"
<<"3.Show\n\t\t\t"
<<"4.Buses Available. \n\t\t\t"
<<"5.Exit";
cout<<"\n\t\t\tEnter your choice:-> ";
cin>>w;
switch(w)
{
case 1: bus[k].install();
break;
case 2: bus[k].allotment();
break;
case 3:bus[0].show();
break;
case 4:bus[0].avail();
break;
case 5: exit(0);
}
}
return 0;
}

