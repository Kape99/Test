#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Question {
protected:
    string question;
    string correct_answer;

public:
    Question(string que, string corr_ans) {
        question = que;
        correct_answer = corr_ans;
    };
   

    virtual bool ask_question() {
        cout << question << endl;
        string userAns;
        cin >> userAns;
        if (userAns == correct_answer) {
            return true;
        }
        return false;

    }

};

class MultipleChoiseQuestion : public Question {
public:
    MultipleChoiseQuestion(string que, string corr_ans, vector<string> ans):Question(que, corr_ans){
        answers = ans;
    };


    bool ask_question() override {
        cout << question << endl;
        cout << "Select one of the following answer" << endl;
        int selected = 0;
        int max = answers.size();
        for (int i = 0; i < answers.size(); i++)
        {
            cout << i + 1 << ") " << answers[i] << endl;
        }
        cin >> selected;
        while (selected <= 0 && selected > max)
        {
            cout << "Write the number associated with your answer" << endl;
            cin >> selected;
        }

        if (answers[selected-1] == correct_answer) {
            return true;
        }
        return false;

    }
private:
    vector<string> answers;


};

int main() {
    
    int point = 0;
    vector<Question*> list;
    vector<string> ans;
    list.push_back(new Question("What is always coming but never arrives? ","tomorrow"));
    ans = { "usa", "australia", "south africa", "new zeland" };
    list.push_back(new MultipleChoiseQuestion("Which country do cities of Perth, Adelade & Brisbane belong to?", "australia", ans));
    cout << "There are 10 question, some with multiple choise where you have to select the correct one" << endl;
    cout << "others you should write the answer, use lowercase and there should be no problem" << endl;
    cout << "Good Luck" << endl;
    for each (Question * var in list) {
        cout << "------------------------------------------------------" << endl;

        if (var->ask_question())
            point++;
    }
    cout << "Your score is: " << point << endl;
}