#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
FILE *fk, *fs;
char another, choice;

struct student
{
   char first_name[50], last_name[50];
   char course[100];
   int section;
   
 };
  
 struct student a;
 char xfirst_name[50], xlast_name[50];
 long int recsize;
 
 fk=fopen("users.txt", "rb+");
 if (fk == NULL)
 {
     fk = fopen("users.txt", "wb+");
     if (fk==NULL)
     {
     puts("Cannot open file");
     return 0;
     }
 }
 
 recsize = sizeof(a);
 while(1)
 {
    system("cls");
    
    cout<< "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
    cout<<"\n\n";
    cout<< "\n \t\t\t 1. Add    Records";
    cout<< "\n \t\t\t 2. List   Records";
    cout<< "\n \t\t\t 3. Modify Records";
    cout<< "\n \t\t\t 4. Delete Records";
    cout<< "\n \t\t\t 5. Exit   Program";
    cout<<"\n\n";
    cout<< "\t\t\t Select Your Choice :=> ";
    fflush(stdin);
    choice = getchar();
    switch(choice)
    {
    case '1':
           fseek(fk,0,SEEK_END);
           another = 'Y';
           while(another == 'Y' || another == 'y')
           {
                 system("cls");
                 cout<<"Enter the first name: ";
                 cin>>a.first_name;
                 cout<<"Enter the last name : ";
                 cin>>a.last_name;
                 cout<<"Enter the course    : ";
                 cin>>a.course;
                 cout<<"Enter the section   : ";
                 cin>>a.section;
                 fwrite(&a,recsize,1,fk);
                 cout<<"\nAdd another record (Y/N)"<<endl;
                 fflush(stdin);
                 another = getchar();
                 
               }
               break;
         case '2':
              system("cls");
              rewind(fk);
              cout<< "=== View the records in the Database ==="<<endl;
              while(fread(&a,recsize,1,fk) == 1)
              {
                  cout<<"\n";
                  cout<<"\n" << a.first_name << setw(10) << a.last_name<<endl;
                  cout<<"\n" << a.course << setw(8) << a.section;
               }
               cout<<"\n\n";
               system("pause");
               break;
         case '3':
              system("cls");
              another = 'Y';
              while(another == 'Y' || another == 'y')
              {
                 cout<<"\n Enter the last name of the student : ";
                 cin>> xlast_name;
                 
                 rewind(fk);
                 while(fread(&a,recsize,1,fk) == 1) 
                 {
                   if(strcmp(a.last_name, xlast_name) == 0)
                   {
                     cout <<"Enter the new first name : ";
                     cin>>a.first_name;
                     cout <<"Enter the new last name  : ";
                     cin>>a.last_name;
                     cout <<"Enter the new course     : ";
                     cin>>a.course;
                     cout <<"Enter the new section    : ";
                     cin>>a.section;
                     fseek(fk, -recsize, SEEK_CUR);
                     fwrite(&a,recsize,1,fk);
                     break;
                    }
                    else
                    cout<<"record not found";
                  }
                  cout<<"\n Modify another record (Y/N) ";
                  fflush(stdin);
                  another = getchar();
                }
                break;
               
             case '4':
                  system("cls");
                  another = 'Y';
                  while(another == 'Y' || another == 'y')
                  {
                    cout<<"\n Enter the last name of the student to delete : ";
                    cin>> xlast_name;
                    
                    fs = fopen("temp.dat","wb");
                    
                    rewind(fk);
                    while(fread(&a,recsize,1,fk) == 1) 
                       
                       if(strcmp(a.last_name,xlast_name)!=0)
                       {
                          fwrite(&a,recsize,1,fs);
                        }
                      fclose(fk);
                      fclose(fs);
                      remove("users.txt");
                      rename("temp.dat","users.txt");
                      
                      fk=fopen("users.txt","rb+");
                      
                      cout<<"\n Delete another record (Y/N) ";
                      fflush(stdin);
                      another = getchar();
                      }
                      
                      break;
                      
                    case '5':
                       fclose(fk);
                       cout<<"\n\n";
                       cout<<"\t\t THANK YOU FOR USING THE SOFTWARE";
                       cout<< "\n\n";
                       exit(0);
                       }
                    }
                    
                    system("pause");
                    return 0;
           }
                     
                   
                  
                  
             
                 
              
                  
                  
              
                 
                 
    
   
