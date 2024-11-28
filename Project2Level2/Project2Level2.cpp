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
	short numberOfQuestions;
	int numbOfRightAnswers;
	int numberOfWrongAnswers;

};


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


void playOneQuestion(stQuestionsInfo &questionInfo) {
	int correctAnswer = 0, playerAnswer, mixOpNum;
	char mixOp;
	int num1 = getNumbers(questionInfo.questionLevel);
	int num2 = getNumbers(questionInfo.questionLevel);
	questionInfo.questionResult = ::incorrect;
		switch (questionInfo.opType) {
		case(::add):
			cout << num1 << endl << num2 << " + \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 + num2) {
				questionInfo.questionResult = ::correct;
			}
			break;
		case(::sub):
			cout << num1 << endl << num2 << " - \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 - num2) {
				questionInfo.questionResult = ::correct;
			}
			break;
		case(::mul):
			cout << num1 << endl << num2 << " * \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 * num2) {
				questionInfo.questionResult = ::correct;
			}
			break;
		case(::divi):
			cout << num1 << endl << num2 << " / \n" << "_________" << endl;
			cin >> playerAnswer;
			if (playerAnswer == num1 / num2) {
				questionInfo.questionResult = ::correct;
			}
			break;
		case(::mix):
			mixOpNum = random(1, 4);
			mixOp = getOpNumberInChar(mixOpNum);
			cout << num1 << endl << num2 << " " << mixOp << " \n" << "_________" << endl;
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
				break;
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
	cout << "Question Level: " << getQuestionLevelAsString(questionInfo.questionLevel) << endl;
	cout << "Operation Type: " << getOpTypeAsString(questionInfo.opType) << endl;
	if (questionInfo.questionResult == correct) {
		cout << "Result: Correct" << endl;
	}
	else {
		cout << "Result: Incorrect" << endl;
	}
}






int main()
{
	srand((unsigned)time(NULL));
	stQuestionsInfo questionInfo;
	questionInfo.questionLevel = getQuestionsLevel();
	questionInfo.opType = getOpType();
	playOneQuestion(questionInfo);
	printOneQuestResult(questionInfo);
	return 0;
}

