#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const string color_prefix = "\033[";
const string color_suffix = "m";

enum enWinner
{
  User = 32,
  PC = 31,
  Draw = 33
};

enum enChoice
{
  Stone = 1,
  Paper = 2,
  Scissors = 3
};

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

bool is_valid_choice(int choice)
{
  return ((choice == 1) || (choice == 2) || (choice == 3));
}

enChoice user_plays()
{
  int choice;
  do
  {
    choice = readNum("Enter your choice [1]: Stone, [2]: Paper, [3]: Scissors?\n");
  } while (!is_valid_choice(choice));
  return enChoice(choice);
}

enChoice pc_plays()
{
  return enChoice(random(1, 3));
}

bool user_wins(enChoice user_choice, enChoice pc_choice)
{
  return ((user_choice == Paper && pc_choice == Stone) ||
          (user_choice == Stone && pc_choice == Scissors) ||
          (user_choice == Scissors && pc_choice == Paper));
}

bool is_draw(enChoice user_choice, enChoice pc_choice)
{
  return user_choice == pc_choice;
}

enWinner who_is_winner_in_round(enChoice user_choice, enChoice pc_choice)
{
  bool user_winned = user_wins(user_choice, pc_choice);
  if (user_winned)
    return User;
  else if (is_draw(user_choice, pc_choice))
    return Draw;
  return PC;
}

string winner_to_str(enWinner winner) {
  switch (winner)
  {
  case User:
    return "User";
  case PC:
    return "PC";
  default:
    return "No Winner";
  }
}

string choice_to_str(enChoice choice) {
  switch (choice)
  {
  case Stone:
    return "Stone";
  case Scissors:
    return "Scissors";
  default:
    return "Paper";
  }
}

void increment_winner(enWinner winner, int &user_wins, int &pc_wins, int &draws)
{
  switch (winner)
  {
  case User:
    ++user_wins;
    break;
  case PC:
    ++pc_wins;
    break;
  case Draw:
    ++draws;
  default:
  break;
  }
}


void print_choices(enChoice user_choice, enChoice pc_choice, enWinner winner)
{
  cout << "------------------------------------------------------------\n";
  cout << "User Choice: " << choice_to_str(user_choice) << "\n";
  cout << "PC Choice: " << choice_to_str(pc_choice) << "\n";
  cout << "Round Winner: " << winner_to_str(winner) << "\n";
  cout << "------------------------------------------------------------\n";
}

void round_steps(int &user_wins, int &pc_wins, int &draws, int &num_of_rounds)
{
  enChoice user_choice = user_plays();
  enChoice pc_choice = pc_plays();
  enWinner winner = who_is_winner_in_round(user_choice, pc_choice);
  increment_winner(winner, user_wins, pc_wins, draws);
  print_choices(user_choice, pc_choice, winner);
  --num_of_rounds;
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

enWinner who_is_winner_in_game(int &user_wins, int &pc_wins) {
  if (user_wins > pc_wins)
    return User;
  else if (user_wins < pc_wins)
    return PC;
  return Draw;
}

void print_game_over_header() {
  cout << "------------------------------------------------------------\n";
  cout << "\t\t\tGame Over!\t\t\t\n";
  cout << "------------------------------------------------------------\n";
  cout << "\t\t\tGame Result!\t\t\t\n";
}


void game_over(int user_wins, int pc_wins, int draws, int rounds) {
  enWinner winner = who_is_winner_in_game(user_wins, pc_wins);
  print_game_over_header();
  cout << "Game Rounds: " << rounds << "\n";
  cout << "Player won " << user_wins << " number of times " << "\n";
  cout << "PC won " << pc_wins << " number of times " << "\n";
  cout << "Draw Times: " << draws << "\n";
  cout << "Winner: " << winner_to_str(winner) << "\n";
  cout << "------------------------------------------------------------\n";
}

void start_game(int rounds, int &user_wins, int &pc_wins, int &draws)
{
  int copy_rounds = rounds;
  while (copy_rounds)
    round_steps(user_wins, pc_wins, draws, copy_rounds);
}

void run_game() {
  int rounds = readNum("Enter number of rounds:\n");
  int user_wins = 0, pc_wins = 0, draws= 0;
  srand((unsigned)time(NULL));
  bool play_again;
  do
  {
    start_game(rounds, user_wins, pc_wins, draws);
    game_over(user_wins, pc_wins, draws, rounds);
    play_again = wants_to_play_again();
  } while (play_again);
}

int main()
{ 
  run_game();
  return 0;
}