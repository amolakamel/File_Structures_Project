#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
 
 
class Artist
{
public:
char Name [30] ;
char Birthplace[20];
int Age;
char Style_Of_Art [20];
int Year_of_Art;
};
 
class user
{
    public :
    char name[20] , pass[20];
};
//**************************************************************
void add_Artist()
{
 
 fstream f("Artist.txt",ios::out|ios::app);
 if(f.is_open())
 {
  char newartist='Y';
  do{
    Artist a;
    cout<<"Enter Artist name: \n";
    cin>>a.Name;
    cout<<"Enter Artist Birthplace : \n";
    cin>>a.Birthplace;
    cout<<"Enter Artist Age: \n";
    cin>>a.Age;
    cout<<"Enter Style of Art about: \n";
    cin>>a.Style_Of_Art;
    cout<<"Enter Year it was made: \n";
    cin>>a.Year_of_Art;
    f.write((char*)&a,sizeof(a));
    cout<<"Enter Y/N to Add new Artist in The Gallery";
    cin>>newartist;
    }
    while(newartist=='Y');
    f.close();
 }
 
}
void UpdateOptions() {
    cout<<"Press 1 to update the Name "<<endl
        <<"Press 2 to update the Birthplace "<<endl
        <<"Press 3 to update the Age "<<endl
        <<"Press 4 to update Style Of Art "<<endl
        <<"Press 5 to update Year of Art "<<endl;
 
}
void UpdateArtist(){
 
    Artist a;
    fstream f("Artist.txt",ios::in|ios::out);
    if(f.is_open()) {
        char Art [20] ;
        cout<<"Enter the Artist you want to update\n";
       cin>>Art;
        bool found =false;
        while(!f.eof()) {
            f.read((char*)&a,sizeof(a));
            if(strcmp(Art,a.Name)==0) {
                UpdateOptions();
                int n;
                cin>>n;
                if(n==1){
                    cout<<"Enter new name"; cin>>a.Name;
                }
                else  if(n==2){
                    cout<<"Enter New Birthplace"; cin>>a.Birthplace;
                }else  if(n==3){
                    cout<<"Enter New age"; cin>>a.Age;
                }else  if(n==4){
                    cout<<"Enter New Style Of Art"; cin>>a.Style_Of_Art;
                }else  if(n==5){
                    cout<<"Enter New Year of Art"; cin>>a.Year_of_Art;
                }else {
                    cout<<"Choose a number from 1 to 5 \n";
                }
                int cur = f.tellg();
                int siz = sizeof(a);
                f.seekp(cur-siz,ios::beg);
                f.write((char*)&a,sizeof(a));
                f.seekg(cur-siz,ios::beg);
                f.read((char*)&a,sizeof(a));
                found=true; break;
            } }
        if(!found) {
            cout<<"Artist not exist!"<<endl; }
        cout<<"If you want to update another Artist Enter Y \n ";
        char ch ; cin>>ch;
        if(ch=='Y' or ch=='y') {
            UpdateArtist();
        }
        f.close();
        }
}
void diplayArtist(){
 
Artist a;
ifstream in("Artist.txt",ios::in);
if(in.is_open())
{
cout<<"  Name"<<"\t"<<"\t\t"<<"Birthplace"<<"\t"<<"Age"<<"\t"<<"Style_Of_Art"<<"\t"<<"Year_of_Art"<<endl;
 
in.read((char*)&a,sizeof(a));
 
while(!in.eof())
{
cout<<" "<<a.Name<<"\t"<<"\t"<<a.Birthplace<<"\t"<<"\t"<<a.Age<<"\t"<<a.Style_Of_Art<<"\t"<<a.Year_of_Art<<endl;
in.read((char*)&a,sizeof(a));
}
 in.close();
}else{
    cout<<" There's a wrong in the system ";
    exit(1);
 
}
}
void research(){
    char str[30];
    cout<<"enter the name of artist you want to search for "<<'\n';
    cin>>str;
    bool found =false ;
 
   Artist a;
    ifstream in;
    in.open("Artist.txt", ios::in);
    if(in.is_open())
    {  in.read((char*) &a, sizeof(a));
        while(!in.eof())
        {
if (strcmp(str,a.Name)==0){
 
  cout<<"***********************************************************************************************************************"<<endl;
 
  cout<<"  Name"<<"\t"<<"\t\t"<<"Birthplace"<<"\t"<<"Age"<<"\t"<<"Style_Of_Art"<<"\t"<<"Year_of_Art"<<endl;
  cout<<" "<<a.Name<<"\t"<<"\t"<<a.Birthplace<<"\t"<<"\t"<<a.Age<<"\t"<<a.Style_Of_Art<<"\t"<<"\t"<<a.Year_of_Art<<endl;
 
    cout<<"**********************************************************************************************************************"<<endl;
    found =true;
    break;
    }
              in.read((char*) &a, sizeof(a));
        }
        if ( found ==false )cout<<"the Artist does't found ";
        in.close();
    }
    else
    {
        cout << "Can not open the specified file\n";
    }
    }
 
    void deleteArtist(){
    Artist s;
    ifstream in("Artist.txt", ios:: in);
    ofstream out("ArtistTemp.txt", ios:: out);
    if (in.is_open())
 
    {   char str [20];
        cout <<"please,Enter the name of Artist to delete his record";
        cin >>str;
        while (in.read((char*)&s,sizeof(s)))
        {
            if(strcmp(str,s.Name) !=0)
            {
            out.write((char*)&s,sizeof(s));
            }
        }
        in.close();
        out.close();
 
        remove("Artist.txt");
        rename( "ArtistTemp.txt", "Artist.txt");
    }
}
 
  void encrypt(char s[])
 {
    // (\0) -> null  char -> اخر عنصر جوا string
    //
   for(int i = 0 ; s[i] != '\0' ; i++)
    s[i] += 5 ;
 }
 
  void decrypt(char s[])
 {
   for(int i = 0 ; s[i] != '\0' ; i++)
    s[i] -= 5 ;
 }
 
  void add_user() // choice
 {
         ofstream out ;
         out.open("users.txt" , ios :: out | ios :: app) ;
 
        user s ;
        if(out.is_open())
        {
            char c = 'y' ;
            while(c == 'y')
            {
                cout << "if you want to input your data click on y otherwise click any character \n"  ;
                cin >> c ;
 
                if(c != 'y')
                   break ;
 
                cout << "please enter your name\n" ;
                cin >> s.name ;
 
                cout << "please enter your pass\n" ;
                cin >> s.pass ;
                encrypt(s.name) ;
                encrypt(s.pass) ;
                out << s.name <<"\t" << s.pass <<"\n";
            }
            out.close() ;
        }
            else
            cout << "can't open this file\n" ;
     }
 
  bool login()
 {
   fstream f("users.txt" , ios::in)  ;
   bool  find = 0 ;
    if(f.is_open())
    {
        char un[20] , pas[20] ;
        cout << "Enter your name : \n" ;
        cin >> un  ;
        cout << "Enter your password : \n" ;\
        cin >> pas;
        user s ;
        while(!f.eof())
        {
            f >> s.name >> s.pass ;
            decrypt(s.name) ;
            decrypt(s.pass ) ;
            if(strcmp(s.name , un)  == 0 && strcmp(s.pass , pas)  == 0)
            {
                find = 1 ;
                cout << "welcome " << s.name << " you logged in successfully.."<<"\n\n" ;
                f.close() ;
                return 1 ;
            }
        }
       if(!find)
       {
         cout << "User name and password not found you need to login first..\n" ;
         add_user() ;
         return 0 ;
       }
    }
  else
  {
     cout <<"File not exist ...\n" ;
     exit(1) ;
  }
 }
 
  void menu1()
 {
    // user management
   cout <<"Press 1 . if you want to add new artist \n" ;
   cout <<"Press 2 . if you want to display all artists \n" ;
   cout <<"Press 3 . if you want to delete artist \n" ;
   cout <<"Press 4 . if you want to search for any artist \n" ;
   cout <<"Press 5 . if you want to update data about any artist \n" ;
 }
 
  void menu2()
 {
      cout <<"Press 1 . if you want to display all artists \n" ;
      cout <<"Press 2 . if you want to search for any artist \n" ;
 }
 
 
int main()
{
 
    int n ;
 
    cout << " Hello  there If you want to register on the website, press 1.."
    << '\n' <<  '\n'  << " If you already have an account, press 2 to login ... \n \n otherwise if you want the guest mood press 3 \n" ;
 
      cin >> n ;
 
      if(n == 1){
 
        // add user on our website
 
          add_user();
      }
 
    else if(n == 2)
    {
        // check user data first
        // if it's ok he can Enter the Website and use all artist functions
        // otherwise he can Enter as a guest and can only diaplay artist and search about any artist
 
        if(login())
        {
           int ch ;
            menu1() ; cin >> ch ;
 
            if(ch == 1)
              add_Artist() ;
 
            else if(ch == 2)
             diplayArtist() ;
 
            else if(ch == 3)
              deleteArtist() ;
 
            else if(ch == 4)
              research() ;
 
            else if(ch == 5)
             UpdateArtist() ;
 
            else
              cout << "Can't find this on the menu .. \n" ;
       }
     }
    else
    {
       cout << "welcome \n" ;
        menu2() ;
        int ch ; cin >> ch ;
 
        if(ch == 1)
         diplayArtist() ;
        else if(ch == 2)
          research() ;
         else
          cout << "Can't find this on the menu .. \n" ;
    }
 
 
 return 0;
}
 
