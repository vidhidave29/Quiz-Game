#include <iostream>
#include <string>
#include <vector>
using namespace std;

void displayBorder() {
    cout << "===============================================\n";
}

void displayWelcomeMessage() {
    displayBorder();
    cout << "\t  Welcome to the Game\n";
    displayBorder();
}

void displayMenu() {
    cout << "> Press 7 to start the Game\n";
    cout << "> Press 0 to quit the Game\n";
}

void displayQuestion(int qNum, const string& question, const vector<string>& options) {
    cout << "Question " << qNum << ": " << question << "\n";
    for (int i = 0; i < options.size(); ++i) {
        cout << i + 1 << ") " << options[i] << "\n";
    }
}

void displayResult(bool correct, const string& correctAnswer) {
    if (correct) {
        cout << "Correct Answer!\n";
    } else {
        cout << "Wrong Answer! The correct answer is: " << correctAnswer << "\n";
    }
}

int main() {
    int choice;
    vector<int> answers = {2, 2, 2, 1, 3};
    vector<int> points = {5, 5, 5, 5, 5};
    vector<string> correct_answers = {"Archive", "Mosaic", "Creeper Virus", "Security", "Cobol"};
    int total = 0;

    displayWelcomeMessage();
    displayMenu();

    cin >> choice;
    if (choice == 7) {
        cout << "\nThe game has started\n\n";
        for (int j = 0; j < 5; j++) {
            int user_answer;
            cout << "-----------------------------------------------\n";
            switch (j) {
                case 0:
                    displayQuestion(j + 1, "Which one is the first search engine on the internet?", {"Google", "Archive", "Wais", "Altavista"});
                    break;
                case 1:
                    displayQuestion(j + 1, "Which one is the first web browser invented in 1990?", {"Internet Explorer", "Mosaic", "Mozilla", "Nexus"});
                    break;
                case 2:
                    displayQuestion(j + 1, "First computer virus is known as?", {"Rabbit", "Creeper Virus", "Elk Cloner", "SCA Virus"});
                    break;
                case 3:
                    displayQuestion(j + 1, "Firewall in computers is used for?", {"Security", "Data Transmission", "Monitoring", "Authentication"});
                    break;
                case 4:
                    displayQuestion(j + 1, "Which of the following is not a database management software?", {"MySQL", "Oracle", "Cobol", "Sybase"});
                    break;
            }
            cout << "Enter your answer: ";
            cin >> user_answer;
            if (user_answer == answers[j]) {
                total += points[j];
                displayResult(true, correct_answers[j]);
            } else {
                displayResult(false, correct_answers[j]);
            }
        }
        cout << "\n-----------------------------------------------\n";
        cout << "Your total score is " << total << "\n";
        cout << "You " << (total == 25 ? "won" : "lost") << " this game\n";
        displayBorder();
    } else if (choice == 0) {
        cout << "The game has ended\n\n";
    } else {
        cout << "Invalid input\n\n";
    }
    return 0;
}
