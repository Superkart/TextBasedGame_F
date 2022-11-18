#include <ctime>
#include <iostream>
using namespace std;

string playerName;

class Player {
private:
  int health = 100;
  int minDamage = 20;
  int maxDamage = 30;
  int minHeal = 10;
  int maxHeal = 20;

public:
  Player() {
    cout << "---------------------------------------------------------" << endl;
    cout << "I " << playerName << " Am ready to kill you Hades!! " << endl;
    cout << "I Your Worst Enemy, Shall Take Your head Hades!!" << endl;
    cout << "Then I Shall Become King of the UnderWorld!" << endl;
    cout << "HERE I COME!!" << endl;
    cout << "---------------------------------------------------------" << endl;
  }

  int GetHealth() { return health; }
  int GenerateRandomDamage() {
    int randomDamage;
    srand(time(0));
    randomDamage = minDamage + (rand() % (maxDamage - minDamage + 1));
    return randomDamage;
  }
  void TakeDamage(int damage) {
    if (health > 0) {
      health = health - damage;
      cout << "Player has taken damage of: " << damage << endl;
      cout << "Player's health has reduced to: " << health << endl;
      cout << "---------------------------------------------------------"
           << endl;
    } else {
      cout << "You have died!" << endl;
    }
  }
  int GenerateRandomHeal() {
    int randomHeal;
    srand(time(0));
    randomHeal = minHeal + (rand() % (maxHeal - minHeal + 1));
    return randomHeal;
  }
  void Heal(int healValue) {
    health = health + healValue;
    cout << "Player has healed by: " << healValue << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Player health has increased to: " << health << endl;
  }
};

class Enemy {
private:
  int health = 100;
  int minDamage = 10;
  int maxDamage = 30;

public:
  Enemy() {
    cout << "---------------------------------------------------------" << endl;
    cout << "Bwhahahahahh Hello " << playerName << "!!!!!" << endl;
    cout << "Be Prepared to be my meal for today!!!!" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Here is Hades!" << endl;
    cout << "---------------------------------------------------------" << endl;
  }

  int GetHealth() { return health; }
  int GenerateRandomDamage() {
    int randomDamage;
    srand(time(0));
    randomDamage = minDamage + (rand() % (maxDamage - minDamage + 1));
    return randomDamage;
  }
  void TakeDamage(int damage) {
    if (health > 0) {
      health = health - damage;
      cout << "Enemy has taken damage of: " << damage << endl;
      cout << "Enemy's health has reduced to: " << health << endl;
      cout << "---------------------------------------------------------"
           << endl;
    } else {
      cout << "You have Won!" << endl;
    }
  }
};

bool StartGame(char input) {
  if (input == 's' || input == 'S') {
    return true;
  } else
    return false;
}
char GetPlayerInput() {
  char input;
  cin >> input;
  cout << "Player has pressed : " << input << endl;
  return input;
}
void GetPlayerName() {
  cout << "Hello Player!" << endl;
  cout << "Please enter your name: " << endl;
  cout << "---------------------------------------------------------" << endl;
  cin >> playerName;
  system("clear");
}
void GameStory() {
  cout << "---------------------------------------------------------" << endl;
  cout << "Welcome to the UnderWorld " << endl;
  cout << "The King of the UnderWorld" << endl;
  cout << "Lord Hades!! Has been waiting for your arrival" << endl;
  cout << "---------------------------------------------------------" << endl;
}
bool GameOver(Player p, Enemy e) {
  if (p.GetHealth() <= 0 && e.GetHealth() <= 0) {
    return true;
  } else {
    return false;
  }
}
void GameLoop(Player p, Enemy e) {
  char playerInput;
  do {
    cout << "Press A to Attack and H to heal" << endl;
    playerInput = GetPlayerInput();

    if (playerInput == 'a' || playerInput == 'A') {
      e.TakeDamage(p.GenerateRandomDamage()); // Attacking enemy

      if (e.GetHealth() > 0) {
        cout << "Hahaha!! Is that all you've got?" << endl;

        p.TakeDamage(e.GenerateRandomDamage()); // Attacking player
      }

    } else if (playerInput == 'h' || playerInput == 'H') {
      p.Heal(p.GenerateRandomHeal()); // Healing player

      if (e.GetHealth() > 0) {
        cout << "Hahaha!! Is that all you've got?" << endl;

        p.TakeDamage(e.GenerateRandomDamage()); // Attacking player
      }

    } else {
      cout << "Invalid Input!" << endl;
    }

  } while (!GameOver(p, e));
}

int main() {
  char playerInput;
  do {
    cout << "To Begin this battle press S" << endl;
    cin >> playerInput;
    if (StartGame(playerInput)) {
      GetPlayerName();
      GameStory();
      Player P;
      Enemy E;
      GameLoop(P, E);
    } else {
      cout << "Thanks for Playing :)" << endl;
    }
  } while (StartGame(playerInput));
}