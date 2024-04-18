#include "Game.h"

////Initialize Game
//Create a new player
//Create a new treasure
//Create new traps
//Create a new dungeon
//Set endstate
Game::Game(int width, int height, int trapCount) {
     srand(time(NULL));

#ifdef DEBUG
     std::wcout << "Creating Player\n";
#endif

     player = new Player();
     player->SetPosition(rand()%width, rand()%height);

#ifdef DEBUG
     int* pPos = player->GetPosition();
     std::wcout << "Player Created at POS [" << pPos[0] << ", " << pPos[1] << "]\nCreating Treasure\n";
#endif

     treasure = new Treasure();
     treasure->PlaceTreasure(width, height, player->GetPosition());

#ifdef DEBUG
     int* tPos = treasure->GetPosition();
     std::wcout << "Treasure Created at POS [" << tPos[0] << ", " << tPos[1] << "]\nCreating Traps\n";
#endif

     traps = new Traps(trapCount);
     traps->PlaceTraps(width, height, player->GetPosition(), treasure->GetPosition());

#ifdef DEBUG
     std::wcout << "Traps Placed\nCreating Dungeon\n";
#endif

     dungeon = new Dungeon(width, height, treasure->GetPosition(), traps);

#ifdef DEBUG
     std::wcout << "Dungeon Created\n";
#endif

     this->endState = false;
}

////Clear Game
//Delete player
//Delete treasure
//Delete traps
//Delete dungeon
Game::~Game() {
     delete player;
     delete treasure;
     delete traps;
     delete dungeon;
}

////Tick
//Clear the screen and reprint dungeon
//Check win/loss conditions
//Get player input
void Game::Tick() {
     system("CLS");

     dungeon->PrintDungeon(player->GetPosition());

#ifdef DEBUG
     PrintDebug();
#endif
     if (WinOrLose()) {
          SetEndState(true);
          return;
     }

     int c = _getch();
     if (c == KEY_ESC) {
          SetEndState(true);
          return;
     }
     GetKeyInput(c);
}

////Get Key Input
//Check for arrow key code to avoid double input
//Move player based on key input
void Game::GetKeyInput(int c) {
     int* playerPos = player->GetPosition();
     int* dungeonSize = dungeon->GetSize();

     if (c == 224) {
          c = _getch();
          switch (c) {
          case KEY_UP:
               if (playerPos[1] > 0) player->MovePlayer(0, -1);
               break;
          case KEY_DOWN:
               if (playerPos[1] < (dungeonSize[1] - 1)) player->MovePlayer(0, 1);
               break;
          case KEY_LEFT:
               if (playerPos[0] > 0) player->MovePlayer(-1, 0);
               break;
          case KEY_RIGHT:
               if (playerPos[0] < (dungeonSize[0] - 1)) player->MovePlayer(1, 0);
               break;
          default:
               break;
          }
     }
}

bool Game::WinOrLose() {
     int* playerPos = player->GetPosition();
     int* treasurePos = treasure->GetPosition();
     int** trapList = traps->GetTraps();

     if (playerPos[0] == treasurePos[0] && playerPos[1] == treasurePos[1]) {
          std::wcout << "You found the treasure!\nGood job!!\n\n";
          return true;
     }

     for (int i = 0; i < traps->GetTrapCount(); i++) {
          if (playerPos[0] == trapList[i][0] && playerPos[1] == trapList[i][1]) {
               std::wcout << "A trap got you!\nThat's not good...\n\n";
               return true;
          }
     }
     return false;
}

////Set EndState (Helper Function)
//Set the endstate
void Game::SetEndState(bool endState) {
     this->endState = endState;
}

////Get EndState (Helper Function)
//Get the endstate
bool Game::GetEndState() {
     return this->endState;
}

////Print Debug
//Print debug info
#ifdef DEBUG
void Game::PrintDebug() {
     int* playerPos = this->player->GetPosition();
     int* treasurePos = this->treasure->GetPosition();
     int** trapList = this->traps->GetTraps();

     std::wcout << "Player   x: " << playerPos[0] << "\ty: " << playerPos[1] << std::endl;
     std::wcout << "Treasure x: " << treasurePos[0] << "\ty: " << treasurePos[1] << std::endl;
     for (int i = 0; i < this->traps->GetTrapCount(); i++) {
          std::wcout << "Trap   i: " << i << "\tx: " << trapList[i][0] << "\ty: " << trapList[i][1] << std::endl;
     }
}
#endif