#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string>

using namespace std;
const int MAX_QUESTIONS = 15;
const int COLUMNS = 6; //Question, Options A, B, C, D, Correct Answer

class questionbank{
  vector< vector<string> > table;
  string line;
  int i,j;
public:
  int m=0;
//function to retrieve ask questions
  int quesask(){
    //retrieving questions from .csv file
    ifstream ques;
    ques.open("test.csv");

    if (ques.fail()) {
        std::cout << "failed to open file" << std::endl;
    }

    while (getline(ques, line, '\n')) {
          vector<string> row;
          stringstream ss;
          ss << line;
          string part;

    while (getline(ss, part, ',')){
            row.push_back(part);
        }
    table.push_back(row);
    }
    ques.close();

    //displaying questions
    for (i = 0; i <= MAX_QUESTIONS-1;i++) {
           cout<<endl;
           for (j = 0; j < COLUMNS-1;j++) {
            cout <<"\t\t\t"<< table[i][j] << "\n\n";
           }
           string answer="0";
           cout<<"\n\n\t\t\tEnter the answer\n\n";

           //30 second timer for each question
           int waitSecond =30; /// number of second to wait for user input.
               while(1)
               {

                if(kbhit())
                 {
                  cin>>answer;
                  break;
                 }
                Sleep(1000);
                --waitSecond;

                if(waitSecond==0)   // wait complete.
                break;
               }
//checking if answer is correct
    if(answer==table[i][j])
        {
          cout<<"\n Correct answer \n";
          m+=1;
        }
    else if(answer =="0")
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,4);
          cout<<"\n TIME OVER";
        SetConsoleTextAttribute(h,7);
    }
    else{
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,4);
        cout<<"\n Wrong answer \n";
        SetConsoleTextAttribute(h,7);
        cout<<" Correct answer is: "<<table[i][j];
      }
    cout << endl;
    cout<<"\t\t   CURRENT SCORE :  "<<m;
    Sleep(2000);
    system("cls");
 }

//display pass or fail
    if(m>(MAX_QUESTIONS/2)){
             HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,11);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n*************************************************************************************************************************************************************************";
    cout<<"\n**      888888888  888888888  8     8  888888888  8888888    888888888  888888888  8       8  8          888888888  888888888  8  888888888  8       8  888888888      **";
    cout<<"\n**      8          8       8  88    8  8          8      8   8       8      8      8       8  8          8       8      8      8  8       8  8 8     8  8              **";
    cout<<"\n**      8          8       8  8 8   8  8          8      8   8       8      8      8       8  8          8       8      8      8  8       8  8  8    8  8              **";
    cout<<"\n**      8          8       8  8  8  8  8          8     8    8       8      8      8       8  8          8       8      8      8  8       8  8   8   8  8              **";
            SetConsoleTextAttribute(h,15);
    cout<<"\n**      8          8       8  8  8  8  8  888888  8888888    888888888      8      8       8  8          888888888      8      8  8       8  8    8  8  888888888      **";
    cout<<"\n**      8          8       8  8   8 8  8       8  8 8        8       8      8      8       8  8          8       8      8      8  8       8  8     8 8          8      **";
    cout<<"\n**      8          8       8  8    88  8       8  8   8      8       8      8      8       8  8          8       8      8      8  8       8  8      88          8      **";
    cout<<"\n**      888888888  888888888  8     8  888888888  8     8    8       8      8      888888888  888888888  8       8      8      8  888888888  8       8  888888888      **";
    cout<<"\n*************************************************************************************************************************************************************************";

      SetConsoleTextAttribute(h,8);
      cout<<"\n\t\t FINAL SCORE :  "<<m;
      }
    else{
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h,4);
      cout<<"\n\t\t XX YOU FAILED XX \n";
      SetConsoleTextAttribute(h,8);
      cout<<"\n\t\t FINAL SCORE :  "<<m;
  }
   return m;
}
};

//class for instructions
class Instruction{
public:
  Instruction()
{

}
void display()
    {
     system("cls");
     HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE );
     SetConsoleTextAttribute( h,6| FOREGROUND_INTENSITY );
     cout<<"\n\n\t\t\t\t INSTRUCTIONS";
     SetConsoleTextAttribute( h,7| FOREGROUND_INTENSITY );
     cout<<"\n\n\n\n\n[1] The quiz consists of questions carefully designed to help you self-assess your theoretical knowledge covered in OOP. ";
     cout<<"\n\n[2] Each question in the quiz is of multiple-choice format. Read each question carefully, and enter your response.Each \n      correct or incorrect response will result in appropriate feedback immediately.";
     cout<<"\n\n[3] There is a time limit assigned for the quiz, in such a way that to you get 30 seconds for each question. If you exceed \n    the time limit,it will automatically change to next question.";
     cout<<"\n\n[4] The total score for the quiz is based on your responses to all questions.";
    }

};

//class to display the opening page
class frontpage: public Instruction,public questionbank{
public:
  string Name;
  int Num;
  int c;
  frontpage(){
  int option;
    HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE );
  	SetConsoleTextAttribute( h,15 | FOREGROUND_INTENSITY );


  	  cout << "\n\n\n\n\n\n\n\n\n\n";
  	  cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  	  cout << "\n\t\t\t\t~    000000   000000   00000       00000    0    0   000000   000000   000000   000000   00000     ~";
      cout << "\n\t\t\t\t~    0    0   0    0   0    0      0    0   0    0      0         0        0    0        0    0    ~";
      cout << "\n\t\t\t\t~    0    0   0    0   0    0      0    0   0    0      0        0        0     0        0   0     ~";
  	  SetConsoleTextAttribute( h,11 | FOREGROUND_INTENSITY );
      cout << "\n\t\t\t\t~    0    0   0    0   0000        0  0 0   0    0      0       0        0      000      0 0       ~";
      cout << "\n\t\t\t\t~    0    0   0    0   0           0   00   0    0      0      0        0       0        0   0     ~";
      cout << "\n\t\t\t\t~    000000   000000   0           000000   000000   000000   000000   000000   000000   0    0    ~";
      cout << "\n\t\t\t\t~                                        0                                                         ~";
      cout << "\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      Sleep(10000);

  	do{
       system("cls");
  	SetConsoleTextAttribute( h,6| FOREGROUND_INTENSITY );
  	cout << "\n\n\n\n\n1.Insructions\t\t\t\t\t\t2.Play Game\t\t\t\t\t\t3.Leaderboard"<< endl;

      cout<<"\n\n\nChoose (1/2/3) to continue"<<endl;
      cin>>option;
      //main menu
      if(option==1)
      {
          Instruction i;
          i.display();
      }

      else if(option==2)
      {
    system("cls");

  	// Input the details
  	SetConsoleTextAttribute( h,6 | FOREGROUND_INTENSITY );
  	cout<<"\n\n\nDetails of the Candidate"<<endl;
  	cout << "\n\n\nName of the Candidate:";
  	cin >> Name;
  	cout << endl;

  	cout << "\nRegister Number:";

  	cin >> Num;
  	cout << endl;

  	string Respond;
  	cout << "\nAre you ready " << Name
  		<< "?[Y/N]" << endl;
  	cin >> Respond;
    system("cls");

  	    if (Respond == "y"||Respond == "Y")
  	    {
  		cout << endl;
  		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,11);
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t*************************************************************************************************************";
        cout<<"\n\t\t\t\t**      888888888    888888888  888888888  88888888        8          8       8  888888888   8      8      **";
        cout<<"\n\t\t\t\t**      8            8       8  8       8  8       8       8          8       8  8           8    8        **";
        cout<<"\n\t\t\t\t**      8            8       8  8       8  8       8       8          8       8  8           8  8          **";
        cout<<"\n\t\t\t\t**      8  88888888  8       8  8       8  8       8       8          8       8  8           88            **";
        cout<<"\n\t\t\t\t**      8       8 8  8       8  8       8  8       8       8          8       8  8           8  8          **";
        cout<<"\n\t\t\t\t**      8       8 8  8       8  8       8  8       8       8          8       8  8           8    8        **";
        cout<<"\n\t\t\t\t**      888888888 8  888888888  888888888  88888888        888888888  888888888  888888888   8      8      **";
        cout<<"\n\t\t\t\t*************************************************************************************************************";
        Sleep(3000);
        system("cls");
        SetConsoleTextAttribute(h,7);
        questionbank qb;
        m=qb.quesask();
        updateleaderboard(m);

      	}
  	    else
  	    {
  		SetConsoleTextAttribute( h,FOREGROUND_RED | FOREGROUND_INTENSITY );
  		cout << "\n\nSee you next time :(" << endl;
        break;
        }
      }
      //display leaderboard
      else if(option==3){
        ifstream scrboard;
        string line1;
        scrboard.open("scoreboard.txt");
        if (scrboard.is_open())
        {
          system("cls");
          cout<<"SCOREBOARD\n\n\n";
          cout<<"Name"<<"\t\tNumber"<<"\t\t Score"<<"\n";
          while(getline(scrboard,line1))
            {
              cout <<"\n"<< line1 << '\n';
            }
            scrboard.close();
        }
        else
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h,4);
            cout << "Unable to open file";
       }
      }

      else
      {
          HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(h,4);
          cout<<"Invalid";
          break;
      }


      cout<<endl<<endl<<"Press 1 for main menu or any other number to exit"<<endl;
      cin>>c;
  }while(c==1);
  }

//updating leaderboard
  void updateleaderboard(int m){
    ofstream update ("scoreboard.txt",ios::app);
    if (update.is_open())
    {
      update <<Name <<"\t\t "<<Num<<"\t\t "<<m;
      update.close();
    }
    else
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h,4);
        cout << "Unable to open file";
   }
  }

};

int main() {
  frontpage fp;
  return 0;
}
