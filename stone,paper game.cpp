

#include <iostream>
#include<string>
using namespace std;
int readnumbersofitriation() {
    int rounds;
    do {
       
        cout << " How many rounds 1 to 10?\n";
        cin >> rounds;

    } while (rounds < 1 || rounds>10);
    return rounds;



}
string changetostring(int number) {
    if (number == 1)return " stone";
    else if (number == 2)return " paper ";
    else return " scissors";
}
enum choises{stone=1,paper=2,scissors=3};
string userchoise() {
    int yourchoise;
    cout << " your choise is 1-stone 2-paper 3-scissors ";
        cin >> yourchoise;
        return changetostring(yourchoise);


}
int randam(int from, int to) {
    return rand() % (to - from + 1) + from;

}
string COMPUTERCHOISE() {
    return changetostring(randam(1, 3));
}
struct totaldata {
    int playerwintimes=0, computerwintimes=0, drawtimes=0;
    string finalwinner="";
};
void winner(string user,string computer,totaldata&data) {
    if (user == computer) {
        cout << "Round winner : No one\n";
        system("color 6f");
        data.drawtimes++;
    }
    else if ((user == "stone" && computer == " scissors")
        || (user == "paper" && computer == "stone") ||
        (user == "scissors" && computer == "paper")) {
        cout << "Round winner : player 1\n";
        system("color 2f");
        data.playerwintimes++;
    }
    else {
        cout << "Round winner : computer\n\a";
        system("color 4f");
        data.computerwintimes++;


    }
}


void whowin(string user, string computer, totaldata& data) {
    
/*if (user == "paper" && computer == choises::paper) {
        cout << " player 1 choise: paper\n ";
        cout << " computer choise: paper\n ";
        cout << " round winer    : no one\n ";
         system("color 6f");
        ++data.drawtimes;
    }
    else if (user == choises::paper && computer == choises::scissors) {
        cout << " player 1 choise: paper\n ";
        cout << " computer choise: scissors\n ";
        cout << " round winer    : computer\n\a ";
         system("color 4f");
       ++ data.computerwintimes;
    } 
    else if (user == choises::paper && computer == choises::stone) {
        cout << " player 1 choise: paper\n ";
        cout << " computer choise: stone\n ";
        cout << " round winer    : player1\n ";
         system("color 2f");
      ++data.playerwintimes;
    }
    else if (user == choises::scissors && computer == choises::paper) {
        cout << " player 1 choise: scissors\n ";
        cout << " computer choise: paper\n ";
        cout << " round winer    : player1\n ";
         system("color 2f");
        ++data.playerwintimes;
    }
    else if (user == choises::scissors && computer == choises::scissors) {
        cout << " player 1 choise: scissors\n ";
        cout << " computer choise: scissors\n ";
        cout << " round winer : no one\n ";
        cout << system("color 6f");

        ++data.drawtimes;
    }
    else if (user == choises::scissors && computer == choises::stone) {
        cout << " player 1 choise: scissors\n ";
        cout << " computer choise: stone\n ";
        cout << " round winer    : computer\n\a ";
         system("color 4f");
        ++data.computerwintimes;
    }
    else if (user == choises::stone && computer == choises::stone) {
        cout << " player 1 choise: stone\n ";
        cout << " computer choise: stone\n ";
        cout << " round winer    : no one\n ";
         system("color 6f");

       ++ data.drawtimes;
    }
    else if (user == choises::stone && computer == choises::paper) {
        cout << " player 1 choise: stone\n ";
        cout << " computer choise: paper\n ";
        cout << " round winer    : computer\n \a";
        system("color 4f");
       ++ data.computerwintimes;
    }
    else if (user == choises::stone && computer == choises::scissors) {
        cout << " player 1 choise: stone\n ";
        cout << " computer choise: scissors\n ";
        cout << " round winer    : player1\n ";
         system("color 2f");
        ++data.playerwintimes;
    }*/    
    cout << "player 1 choice is : " << user;
    cout << "\ncomputer choice is : " << computer<<endl;
         winner(user, computer, data);



}
bool youwantcompleteornot() {
    char yesorno;
    cout << " Do you want play again Y\N ?\n";
    cin >> yesorno;
    if (yesorno == 'y' || yesorno == 'Y' || yesorno == '1') return true;
    else return false;
}
void finalresult(totaldata &data) {
    if (data.playerwintimes > data.computerwintimes)
    {
        cout << "\t\t           +++ Winner ++++       \n";
        data.finalwinner = " player1 ";
    }
    else
    {
        cout << "\t\t           +++ Game Over +++    \n  ";

        if (data.computerwintimes > data.playerwintimes)data.finalwinner = "computer";
        else data.finalwinner = " no one";

    }

}
void showresult(totaldata &data) {
    cout << "\t\t________________________________________________\n";
    finalresult(data);
    cout << "\t\t________________________________________________\n";
    cout << "\t\t_____________  [Game Result]   __________________\n";
    cout << "\t\t Game rounds            : " << data.computerwintimes + data.drawtimes + data.playerwintimes<<endl;
    cout << "\t\t player 1 won times     : " << data.playerwintimes << endl;
    cout << "\t\t computer won times     : " << data.computerwintimes << endl;
    cout << "\t\t Draw times             : " << data.drawtimes<<endl;
    cout << "\t\t final winner           : " << data.finalwinner<<endl;
    cout << "\t\t________________________________________________\n";
    
}
void printtheallapp() {
    int numberoftrial = readnumbersofitriation();
    totaldata data;
    for (int i = 1; i <= numberoftrial; i++) {

        cout << " round [ " << i << " ] begins: \n";
        string user = userchoise();
        cout << "________________Round[" << i << "] _________________\n";
        whowin(user, COMPUTERCHOISE(), data);
        cout << "___________________________________\n\n";

    }
    showresult(data);

}
void mainfun() {
    bool yesorno;
    do {
        printtheallapp();
        yesorno = youwantcompleteornot();


    } while (yesorno);


}


int main()
{
    srand((unsigned) time(NULL));
   //
    mainfun();
    
}
