#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


enum enWinner
{
  User,
  PC,
  Draw
};

enum enChoice
{
  Stone = 1,
  Paper = 2,
  Scissors = 3
};

struct stRoundInfo {
  int number;
  enWinner winner;
  enChoice user_choice;
  enChoice pc_choice;
};

struct stGameInfo {
  int rounds;
  int user_wins;
  int pc_wins;
  int draws;
  enWinner winner;
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

void increment_winner(enWinner winner, stGameInfo &game)
{
  switch (winner)
  {
  case User:
    ++game.user_wins;
    break;
  case PC:
    ++game.pc_wins;
    break;
  case Draw:
    ++game.draws;
  default:
  break;
  }
}


void print_choices(stRoundInfo round)
{
  cout << "------------------------------------------------------------\n";
  cout << "User Choice: " << choice_to_str(round.user_choice) << "\n";
  cout << "PC Choice: " << choice_to_str(round.pc_choice) << "\n";
  cout << "Round Winner: " << winner_to_str(round.winner) << "\n";
  cout << "------------------------------------------------------------\n";
}

void round_steps(stGameInfo &game, int &num_of_rounds, int &round_number)
{
  cout << "Round Number [" << round_number << "]\n";

  stRoundInfo round;
  enChoice user_choice = user_plays();
  enChoice pc_choice = pc_plays();
  enWinner winner = who_is_winner_in_round(user_choice, pc_choice);


  round.number = round_number;
  round.pc_choice = pc_choice;
  round.user_choice = user_choice;
  round.winner = winner;
  
  increment_winner(round.winner, game);
  
  print_choices(round);
  --num_of_rounds;
  ++round_number;
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
  cout << "\t\t\t------------------------------------------------------------\t\t\t\n";
  cout << "\t\t\t\t\t\tGame Over!\t\t\t\t\t\t\n";
  cout << "\t\t\t------------------------------------------------------------\t\t\t\n";
  cout << "\t\t\t\t\t\tGame Result!\t\t\t\t\t\t\n";
}


void game_over(stGameInfo &game) {
  enWinner winner = who_is_winner_in_game(game.user_wins, game.pc_wins);
  game.winner = winner;
  print_game_over_header();
  cout << "Game Rounds: " << game.rounds << "\n";
  cout << "Player won " << game.user_wins << " number of times " << "\n";
  cout << "PC won " << game.pc_wins << " number of times " << "\n";
  cout << "Draw Times: " << game.draws << "\n";
  cout << "Winner: " << winner_to_str(game.winner) << "\n";
  cout << "------------------------------------------------------------\n";
}

void start_game(stGameInfo &game)
{
  int copy_rounds = game.rounds;
  int round_number = 1;
  while (copy_rounds)
    round_steps(game, copy_rounds, round_number);
}

void initialize_game(stGameInfo &game) {
  game.rounds = readNum("Enter number of rounds:\n");
  game.draws = 0;
  game.pc_wins = 0;
  game.user_wins = 0;
}

void run_game() {
  stGameInfo game;
  
  initialize_game(game);

  srand((unsigned)time(NULL));
  bool play_again;
  do
  {
    start_game(game);
    game_over(game);
    play_again = wants_to_play_again();
  } while (play_again);
}

int main()
{ 
  run_game();
  return 0;
}