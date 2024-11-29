#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel {
	easy = 1,
	med = 2,
	hard = 3,
	mixed = 4
};

enum enOperationType {
	add = 1,
	sub = 2,
	mul = 3,
	divi = 4,
	mix = 5,

};

enum result {
	correct = 1,
	incorrect = 2
};


struct stQuestionsInfo {
	short questionNumber;
	enQuestionsLevel questionLevel;
	enOperationType opType;
	result questionResult;

};


struct stGameResults {
	enQuestionsLevel questionLevel;
	enOperationType opType;
	short numberOfQuestions;
	int numbOfRightAnswers;
	int numbOfWrongAnswers;
	string markResult;

};



void setScreenColor(result result)
{
	if (result == ::correct) 
	    system("color 2F"); //turn screen to Green
	else 
		system("color 4F"); //turn screen to Red
	
}

int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}


int getQuestionsNumber() {
	int number;
	cout << "How many questions do you want to answer ? ";
	cin >> number;
	return number;
}


 enQuestionsLevel getQuestionsLevel() {
	 short level;
		do {
			cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
			cin >> level;
		} while (level < 1 || level > 4);
	return (enQuestionsLevel)level;
}


 enOperationType getOpType() {
	 short opType;
	 do {
		 cout << "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		 cin >> opType;
	 } while (opType < 1 || opType > 5);
	 return (enOperationType)opType;
 }



int getNumbers(enQuestionsLevel questionsLevel) {
	switch (questionsLevel) {
	case(::easy):
		return random(1, 10);
	case(::med):
		return random(10, 50);
	case(::hard):
		return random(50, 100);
	default:
		return random(1, 100);
	}
}

char getOpNumberInChar(int opNum) {
	switch (opNum) {
	case(1):
		return '+';
	case(2):
		return '-';
	case(3):
		return '*';
	case(4):
		return '/';
	}
}


result playOneQuestion(stQuestionsInfo &questionInfo) {
	int correctAnswer = 0, playerAnswer, mixOpNum;
	char mixOp;
	int num1 = getNumbers(questionInfo.questionLevel);
	int num2 = getNumbers(questionInfo.questionLevel);
	questionInfo.questionResult = ::incorrect;
		switch (questionInfo.opType) {
		case(::add):
			cout << endl << num1 << endl << num2 << " + \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 + num2) {
				questionInfo.questionResult = ::correct;
				 return  questionInfo.questionResult;
			}
			break;
		case(::sub):
			cout << endl << num1 << endl << num2 << " - \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 - num2) {
				questionInfo.questionResult = ::correct;
				return questionInfo.questionResult;
			}
			break;
		case(::mul):
			cout << endl << num1 << endl << num2 << " * \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 * num2) {
				questionInfo.questionResult = ::correct;
				return questionInfo.questionResult;
			}
			break;
		case(::divi):
			cout << endl << num1 << endl << num2 << " / \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 / num2) {
				questionInfo.questionResult = ::correct;
				 return questionInfo.questionResult = ::correct;
			}
			break;
		case(::mix):
			mixOpNum = random(1, 4);
			mixOp = getOpNumberInChar(mixOpNum);
			cout << endl << num1 << endl << num2 << " " << mixOp << " \n" << "_________" << endl;
			cin >> playerAnswer;
			switch (mixOp) {
			case '+':
				correctAnswer = num1 + num2;
				break;
			case '-':
				correctAnswer = num1 - num2;
				break;
			case '*':
				correctAnswer = num1 * num2;
				break;
			case '/':
				correctAnswer = num1 / num2;
				break;
			}
			if (correctAnswer == playerAnswer) {
				questionInfo.questionResult = ::correct;
				return questionInfo.questionResult;
				
			}
			  
		}
}

// Function to convert operation enum to string
string getOpTypeAsString(enOperationType opType) {
	switch (opType) {
	case add: return "Addition";
	case sub: return "Subtraction";
	case mul: return "Multiplication";
	case divi: return "Division";
	case mix: return "Mixed";
	default: return "Unknown";
	}
}

// Function to convert question level enum to string
string getQuestionLevelAsString(enQuestionsLevel level) {
	switch (level) {
	case easy: return "Easy";
	case med: return "Medium";
	case hard: return "Hard";
	case mixed: return "Mixed";
	default: return "Unknown";
	}
}

void printOneQuestResult(stQuestionsInfo questionInfo) {
	if (questionInfo.questionResult == correct) {
		cout << "Right Answer :-)" << endl;
	}
	else {
		cout << "Wrong Answer :-(" << endl;
	}
}

string gameMarkResult(short playerWinTimes, short
	playerLoseTimes)
{
	if (playerWinTimes > playerLoseTimes)
		return " PASS :-)";
	else
		return "FAIL :-(";

}

stGameResults fillGameResults(int numOfQuestions, short
	playerWinTimes, short playerLoseTimes, stQuestionsInfo questionInfo)
{
	stGameResults GameResults;
	GameResults.numberOfQuestions = numOfQuestions;
	GameResults.numbOfRightAnswers = playerWinTimes;
	GameResults.numbOfWrongAnswers = playerLoseTimes;
	GameResults.questionLevel = questionInfo.questionLevel;
	GameResults.opType = questionInfo.opType;
	GameResults.markResult = gameMarkResult(playerWinTimes, playerLoseTimes);
	return GameResults;
}

stGameResults playGame(int numOfQuestions) {
	stQuestionsInfo questionInfo;
	short playerWinTimes = 0, playerLoseTimes = 0;
	questionInfo.questionLevel = getQuestionsLevel();
	questionInfo.opType = getOpType();
	for (int questNumber = 1; questNumber <= numOfQuestions; questNumber++) {
		cout << "Questions [" << questNumber << "]\n";
		questionInfo.questionNumber = questNumber;
		questionInfo.questionResult = playOneQuestion(questionInfo);
		printOneQuestResult(questionInfo);
		setScreenColor(questionInfo.questionResult);
		if (questionInfo.questionResult == ::correct)
			playerWinTimes++;
		else 
			playerLoseTimes++;

	}
	return fillGameResults(numOfQuestions, playerWinTimes,
		playerLoseTimes, questionInfo);
	}



void printGameResults(stGameResults gameResults) {
	cout << "\n____________________________________________\n\n";
	cout << "Final Result is " << gameResults.markResult << endl;
	cout << "_____________________________________________\n\n";
	cout << "Number of Questions: " << gameResults.numberOfQuestions << endl;
	cout << "Question Level     : " << getQuestionLevelAsString(gameResults.questionLevel) << endl;
	cout << "Operation Type     : " << getOpTypeAsString(gameResults.opType) << endl;
	cout << "Number of Right Answers : " << gameResults.numbOfRightAnswers << endl;
	cout << "Number of Wrong Answers : " << gameResults.numbOfWrongAnswers << endl;
	cout << "_____________________________________________\n\n";
}


int main()
{
	srand((unsigned)time(NULL));
	stGameResults gameResults = playGame(getQuestionsNumber());
	printGameResults(gameResults);
	return 0;
}

