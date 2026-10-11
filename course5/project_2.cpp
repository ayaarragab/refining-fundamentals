#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const short EASY_UPPER_LIMIT = 10;
const short MEDIUM_UPPER_LIMIT = 50;
const short HARD_UPPER_LIMIT = 100;

int random(short from, short to)
{
  return rand() % (to - from + 1) + from;
}

int readNum(string message)
{
  int n;
  cout << message;
  cin >> n;
  return n;
}

enum enOpType
{ 
  Add=1,
  Sub=2,
  Mul=3,
  Div=4,
  opMix=5
};

enum enDifficulty
{
  Easy=1,
  Medium=2,
  Hard=3,
  Mix=4
};

enum enStatus
{
  Passed=1,
  Failed=2
};

struct stGameInfo {
  short num_of_questions;
  enOpType operation;
  enDifficulty difficulty;
  short num_of_answered_questions;
  enStatus status;
};

struct stQuestionInfo {
  short number;
  short op1;
  short op2;
  short result;
  enOpType operation;
  char op;
  enDifficulty difficulty;
};

void init_game(stGameInfo &game) {
  game.num_of_questions = readNum("Enter number of questions:\n");
  game.num_of_answered_questions = 0;
  game.operation = (enOpType)readNum("Operation? [1]: Add | [2]: Subtract | [3]: Multiply | [4]: Divide | [5]: Mix \n");

  game.difficulty = (enDifficulty)readNum("Difficulty? [1]-> Easy | [2] -> Medium | [3] -> Hard | [4] -> Mix :\n");
}

short get_operand(enDifficulty difficulty) {
  switch (difficulty)
  {
  case Easy:
    return random(1, EASY_UPPER_LIMIT);
  case Medium:
    return random(EASY_UPPER_LIMIT, MEDIUM_UPPER_LIMIT);
  case Hard:
    return random(MEDIUM_UPPER_LIMIT, HARD_UPPER_LIMIT);
  case Mix:
    return get_operand((enDifficulty)random(1, 4));
  }
  return 0;
}

char get_operator_and_result(short num1, short num2, enOpType operation, short &result) {
  switch (operation)
  {
  case Add:
    result = num1 + num2;
    return '+';
  case Sub:
    result = num1 - num2;
    return '-';
  case Mul:
    result = num1 * num2;
    return '*';
  case Div:
    result = num1 / num2;
    return '/';
  case opMix:
    return get_operator_and_result(num1, num2, (enOpType)random(1, 5), result);
  }
  return '0';
}




stQuestionInfo generate_one_question(stGameInfo game, short i) {
  stQuestionInfo q;
  short op1 = get_operand(game.difficulty);
  short op2 = get_operand(game.difficulty);
  short result;
  char op = get_operator_and_result(op1, op2, game.operation, result);
  q.number = i;
  q.op1 = op1;
  q.op2 = op2;
  q.op = op;
  q.difficulty = game.difficulty;
  q.result = result;
  return q;
}

void display_question(stQuestionInfo q) {
  cout << "Question [" << q.number << "]: \n";
  cout << q.op1 << " " << q.op << " " << q.op2 << " " << "=" << " " << "\n";
}

short get_answer() {
  short ans;
  cin >> ans;
  return ans;
}

bool compare_answers(short user_answer, short result) {
  return user_answer == result;
}

void user_result_action(short result, bool is_correct, stGameInfo &game) {
  if (is_correct) {
      ++game.num_of_answered_questions;
      cout << "Right Answer!\n";
  } else {
    cout << "Wrong Answer!\n";
    cout << "Answer is " << result << "\n";
  }
}

void generate_questions(stGameInfo &game) {
  for (short i = 1; i <= game.num_of_questions; i++)
  {
    stQuestionInfo q = generate_one_question(game, i);
    display_question(q);
    short ans = get_answer();
    bool is_correct = compare_answers(ans, q.result);
    user_result_action(q.result, is_correct, game);
  }
  
}

void start_math_game(stGameInfo game) {
  generate_questions(game);
}

bool wants_to_play_again()
{
  char wants_or_not;
  cout << "Do you want to play again? (Y/N) \n";
  cin >> wants_or_not;
  if (wants_or_not == 'Y' || wants_or_not == 'y')
    return true;
  return false;
}

string decide_game_status(stGameInfo &game) {
  if ((game.num_of_questions - game.num_of_answered_questions) >= game.num_of_questions / 2){
    game.status = Passed;
    return "Passed";
  }
  else {
    game.status = Failed;
    return "Failed";
  }
}

void game_over(stGameInfo game) {
  string status = decide_game_status(game);
  cout << "\t\t\tGame Over\t\t\t\n";
  cout << "You " << status <<  " with" << game.num_of_answered_questions << " out of " << game.num_of_questions << "\n";
}

void run_game() {
  srand((unsigned)time(NULL));
  stGameInfo game;
  bool play_again;
  do
  {
    init_game(game);
    start_math_game(game);
    game_over(game);
    play_again = wants_to_play_again();
  } while (play_again);
}

int main()
{ 
  run_game();
  return 0;
}