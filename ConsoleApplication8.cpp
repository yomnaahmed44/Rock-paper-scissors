#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include<iomanip>
#include<cstdlib>

enum gamechoice {rock=1,paper=2,scissors=3};
enum winner { computer = 1, player = 2 ,tied=3};
void printtabs(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "-";
    }
}
int readnumofrounds() {
    int n;
    cout << "How many rounds 1 to 10?";
    cin >> n;
    return n;
}
int randomnumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}
gamechoice numtoenum(int n) {
    switch (n) {
    case 1:
        return gamechoice::rock;
        break;
    case 2:
        return gamechoice::paper;
        break;
    case 3:
        return gamechoice::scissors;
        break;
}
}
winner returnwinner(gamechoice compchoice, gamechoice playerchoice) {
    if ((compchoice == gamechoice::paper && playerchoice == gamechoice::paper) || (compchoice == gamechoice::scissors && playerchoice == gamechoice::scissors) || (compchoice == gamechoice::rock && playerchoice == gamechoice::rock)) {
        return winner::tied;
  }
    if ((compchoice == gamechoice::paper && playerchoice == gamechoice::rock) || (compchoice == gamechoice::scissors && playerchoice == gamechoice::paper) || (compchoice == gamechoice::rock && playerchoice == gamechoice::scissors)) {
        return winner::computer;
    }
    if ((compchoice == gamechoice::rock && playerchoice == gamechoice::paper) || (compchoice == gamechoice::paper && playerchoice == gamechoice::scissors) || (compchoice == gamechoice::scissors && playerchoice == gamechoice::rock)) {
        return winner::player;
    }
}
string winnertostring(winner n) {
    switch (n) {
    case winner::computer:
        return "Computer";
        break;
    case winner::player:
        return "Player";
        break;
    case winner::tied:
        return "Tied";
        break;
    default:
        return"0";
        break;
    }
}
  string choicetostring(int n) {
        switch (n) {
        case 1:
            return "Rock";
            break;
        case 2:
            return "Paper";
            break;
        case 3:
            return "Scissors";
            break;
        default:
            return "0";
            break;
        }

    }
  void resetgame() {
      system("cls");     system("color 0F");
  }

void game() {
    int n = readnumofrounds();
    int x = n;
    int compwins = 0;
    int ties = 0;
    int playerwins = 0;
    int y = 1;
    while (x--) {
        cout<< "Round [" << y << "] begins:"<<endl;
        cout<< "Your choice: [1]:Rock, [2]:Paper, [3]:Scissors ?"<<endl;
        int playerchoice;
        cin>> playerchoice;
        int compchoice = randomnumber(1, 3);
        gamechoice enplayerchoice = numtoenum(playerchoice);
        gamechoice encompchoice = numtoenum(compchoice);
        printtabs(20);
        cout << endl;
        cout << "Round [" << y << "]"<<endl;
        printtabs(20);
        cout << endl;
        cout << "Player choice: " << choicetostring(playerchoice)<<endl;
        cout << "Computer choice: " << choicetostring(compchoice)<<endl;
        if (returnwinner(encompchoice, enplayerchoice) == winner::computer) {
            compwins++;
            system("color 4F");
            cout << "Round Winner : " << winnertostring(returnwinner(encompchoice, enplayerchoice))<<endl;
        }
        else if (returnwinner(encompchoice, enplayerchoice) == winner::player) {
            playerwins++;
            system("color 2F");
            cout << "Round Winner : " << winnertostring(returnwinner(encompchoice, enplayerchoice))<<endl;
        }
        else {
            ties++;
            system("color 6F");
            cout << "Round Winner : " << winnertostring(returnwinner(encompchoice, enplayerchoice))<<endl;
        }
        printtabs(25);
        cout << endl;
        y++;
    }
    cout << "\t\t";
    printtabs(25);
    cout << "\t\t"<<endl;
    cout << "\t\t+++ G a m e  O v e r +++\t\t"<<endl;
    cout << "\t\t";
    printtabs(25);
    cout << "\t\t" << endl;
    cout << "\t\t";
    printtabs(10);
    cout << "[ Game Results ]";
    printtabs(10);
    cout << "\t\t" << endl;
    cout << "\t\tGame Rounds        : " << n<<endl;
    cout << "\t\tPlayer won times        : " << playerwins<<endl;
    cout << "\t\tComputer won times        : " << compwins<<endl;
    cout << "\t\tDraw ties        : " << ties << endl;
    if(compwins>playerwins)
    cout << "\t\tFinal Winner        : Computer"<<endl;
    else if (playerwins > compwins)
        cout << "\t\tFinal Winner        : Player"<<endl;
    else
        cout << "\t\tFinal Winner        : Tied"<<endl;
    cout <<"\t\t";
    printtabs(25);
    cout << "\t\t" << endl;
 
 }
int main()
{
    
    srand((unsigned)time(NULL));
    char ans;
    do {
        game();
        cout << "Do you want to play again ? Y/N" << endl;
       
        cin >> ans;
        system("color 0F");

    } while (ans == 'y' || ans == 'Y');
   
    return 0;
}


