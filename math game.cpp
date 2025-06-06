
#include <iostream>
using namespace std;
int numbersofQu() {
	int num;
	do {
		cout << " How many Question you want to ask?\n";
		cin >> num;

	} while (num < 0|| num>10);
	return num;


}
enum levels{easy=1,med,hard,mixe};
levels yourlevel() {
	int level;
	do {
		cout << " Enter Question level [1] easy [2] med [3] hard [4] mix?\n ";
		cin >> level;
	} while (level < 1 || level >4);
	return (levels)level;


}
string levelstringinsteadofenum(levels level) {
	string arr[4] = { "easy","med","hard","mix" };
	return arr[level - 1];
}
enum typeofqu{add=1,sub,mult,dive,mixed};
typeofqu yourtype() {
	int type;
	do {
		cout << " Enter Question type [1] add [2] sub [3] mult [4] dive [5] mix ?\n ";
		cin >> type;
	} while (type < 1 || type>5);
	return (typeofqu)type;


}
string typeofqustring(typeofqu type) {
	string arr[5] = { "+","-","*","/" ,"mix"};
	return arr[type - 1];


}
struct dataofoneround {
	int num1=0, num2=0, userresult=0, factresult=0;
	bool rightanswe = 0; levels qulevel; typeofqu qutype;


};
struct fullrounds {
	int numberofquestions = 0, rightanswers = 0, wronganswers = 0;
	typeofqu yourtype;levels operationlevel ;
	bool ispass = 0; dataofoneround onequ[100];
};
int randam(int from, int to) {
	return rand() % (to - from + 1) + from;
}
int numberbylevel(levels level) {
	if (level == levels::easy)return randam(1, 10);
	else if (level == levels::med)return randam(10, 50);
	else if (level ==levels::hard)return randam(50, 100);
	else return randam(1, 100);
}
int showround(int num1,int num2,string operation) {
	int userresult = 0;

	cout << num1 << endl;
	cout << num2 << "  " << operation << endl;
	cout << "________________\n";
	cin >> userresult;

	return userresult;
}
int factresult(int num1, int num2, typeofqu type) {
	switch (type) {
	case typeofqu::add:return num1 + num2;
		break;
	case typeofqu::dive:return num1 / num2;
		break;
	case typeofqu::mult:return num1 * num2;
		break;
	case typeofqu::sub:return num1 - num2;
		break;
	}


}
void returntoblack() {
	system("cls");
	system("color 0f");
}
bool validation(int userresult,int factresult) {
	if (userresult == factresult) {
		system("color 6f");
		cout << " Right Answer :-)\n";
		
		return true;
	}
	else {
		system("color 4f");
		cout << "Wrong Answer:-(\n] The Right answer is\a " << factresult << endl;
		
		return false;
	}

}
typeofqu ifmix() {
	return (typeofqu)randam(1, 4);
}
fullrounds mathgame(int rounds) {
	fullrounds finalresult;
	finalresult.operationlevel = yourlevel();
	finalresult.yourtype = yourtype();
	finalresult.numberofquestions = rounds;
	for (int i = 1; i <= rounds; i++) {
		typeofqu usertype;
		cout << " Question [ " << i << " / " << rounds << " ]\n";
		int num1 = numberbylevel(finalresult.operationlevel);
		int num2 = numberbylevel(finalresult.operationlevel);
		if (finalresult.yourtype == typeofqu::mixed) {
		
			usertype = ifmix();
		}
		else { usertype = finalresult.yourtype; }
		if (validation(showround(num1, num2, typeofqustring(usertype)), factresult(num1, num2, usertype)))
			finalresult.rightanswers++;
		else
			finalresult.wronganswers++;

	}
	return finalresult;




}
void printpassornot(fullrounds round) {

	if (round.rightanswers >= round.wronganswers) {
		cout << "       final result is PASS :-)\n";
		system("color 6f");
	}
	else {
		cout << "            final result is FAIL:-(\n";
		system("color 4f");
	}



}
dataofoneround generateonequ(levels qulevel,typeofqu qutype) {
	dataofoneround onequesation;
	if (qulevel== levels::mixe)
		qulevel = (levels)randam(1, 3);
	if (qutype == typeofqu::mixed)
		qutype = ifmix();
	onequesation.qulevel = qulevel;
	onequesation.qutype = qutype;
	switch(qulevel) {
	case levels::easy:
		onequesation.num1 = randam(1, 10);
		onequesation.num2 = randam(1, 10);
		onequesation.factresult = factresult(onequesation.num1, onequesation.num2, qutype);
		return onequesation;
	case levels::med:
		onequesation.num1 = randam(10, 50);
		onequesation.num2 = randam(10, 50);
		onequesation.factresult = factresult(onequesation.num1, onequesation.num2, qutype);
		return onequesation;
	case levels::hard:
		onequesation.num1 = randam(50, 100);
		onequesation.num2 = randam(50, 100);
		onequesation.factresult = factresult(onequesation.num1, onequesation.num2, qutype);
		return onequesation;




	}







}
void generataallquections(fullrounds& quiz) {
	for (int question = 0; question < quiz.numberofquestions; question++) {

		quiz.onequ[question] = generateonequ(quiz.operationlevel, quiz.yourtype);

	}



}
void showquestions(fullrounds quiz,int numberofquestion) {
	cout << "\n Question [ " << numberofquestion +1<< " / " << quiz.numberofquestions << " ] \n";
	cout << "_________________________\n";
	cout << quiz.onequ[numberofquestion].num1 << endl;
	cout << quiz.onequ[numberofquestion].num2 << "   ";
	cout << typeofqustring(quiz.onequ[numberofquestion].qutype) << endl;
	cout << "_________________________\n";
}
int answerofuser() {
	int answer;
	cin >> answer;
	return answer;
}
void colors(bool pass) {
	if (pass)system("color 2f");
	else {
		cout << "\a";
		system("color 4f");
	}


}
void checkrightorwrong(fullrounds& quiz, int numberofqu) {
	if (quiz.onequ[numberofqu].factresult == quiz.onequ[numberofqu].userresult) {
		cout << " Right answer :-)\n";
		quiz.onequ[numberofqu].rightanswe = true;
		quiz.rightanswers++;
	}
	else {
		cout << " Wrong  answer :-(\n";
		cout << " the right answer is " << quiz.onequ[numberofqu].factresult << endl;
		quiz.onequ[numberofqu].rightanswe = false;
		quiz.wronganswers++;

	}
	colors(quiz.onequ[numberofqu].rightanswe);





}
void askandcheck(fullrounds& quiz) {
	for (int qu = 0; qu < quiz.numberofquestions; qu++) {
		showquestions(quiz, qu);
		quiz.onequ[qu].userresult = answerofuser();
		checkrightorwrong(quiz, qu);
	}
	if (quiz.rightanswers >= quiz.wronganswers)quiz.ispass = true;
	else quiz.ispass = false;

}
string passorfail(fullrounds quiz) {
	if (quiz.ispass)
		return "        PASS     ";
	else
		return "         FAIL       ";

	colors(quiz.ispass);

}
void printfinalresult(fullrounds round) {
	cout << "\n______________________________________\n";
	            cout<< passorfail(round);

	cout << "\n______________________________________\n";
	cout << " number of question is      : " << round.numberofquestions;
	cout << " \nthe type of question is  : " << typeofqustring(round.yourtype);
	cout << " \nthe level of question is : " << levelstringinsteadofenum(round.operationlevel);
	cout << " \nthe right of question is : " << round.rightanswers;
	cout << " \nthe wrong of question is : " << round.wronganswers;
	cout << "\n______________________________________\n";

}
void playgame() {
	fullrounds quiz;
	quiz.numberofquestions = numbersofQu();
	quiz.operationlevel = yourlevel();
	quiz.yourtype = yourtype();
	generataallquections(quiz);
	askandcheck(quiz);

	printfinalresult(quiz);



}

void mathGame() {
	char complete = 'y';
	do {
		returntoblack();
		playgame();
	
		cout << "\n Do you want try again y/n?\n";
		cin >> complete;



	} while (complete == 'y' || complete == 'Y');





}



int main()
{
	srand((unsigned)time(NULL));
	mathGame();



	return 0;
}



