#include "Game.h"

////Initialize Game
//Create a new player
//Create a new treasure
//Create new traps
//Create new enemies
//Create a new dungeon
//Set endstate
Game::Game(int width, int height, int trapCount, int enemyCount) {
     srand(time(NULL));

     entities = new std::vector<Entity*>();

     entities->emplace_back(new Player(PLAYER));
     entities->emplace_back(new Treasure(TREASURE));
     for (int i = 0; i < trapCount; i++) {
          entities->emplace_back(new Trap(TRAP));
     }
     for (int i = 0; i < enemyCount; i++) {
          entities->emplace_back(new Enemy(ENEMY));
     }

     PlaceEntities(width, height);

     dungeon = new Dungeon(width, height);

     this->endState = false;
}

////Clear Game
//Delete entities
//Delete dungeon
Game::~Game() {
     for (auto e : *entities) {
          delete e;
     }
     delete entities;
     delete dungeon;
}

////Place Entities
//Place all entities at random positions
void Game::PlaceEntities(int width, int height) {
     for (int i = 0; i < entities->size(); ) {
          int x = rand() % width;
          int y = rand() % height;
          bool collide = false;

          for (int j = 0; j < i; j++) {
               if ((*entities)[j]->CheckCollision(x,y)) collide = true;
          }

          if (!collide) {
               (*entities)[i]->SetPosition(x, y);
               i++;
          }
     }
}

////Tick
//Clear the screen and reprint dungeon
//Check win/loss conditions
//Get player input
void Game::Tick() {
     system("CLS");

     dungeon->PrintDungeon(entities);

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
     MoveEnemies();
}

////Win Or Lose
//
bool Game::WinOrLose() {
     for (int i = 1; i < entities->size(); i++) {
          if ((*entities)[0]->CheckCollision((*entities)[i])) {
               if (dynamic_cast<Treasure*>((*entities)[i]) != nullptr) {
                    std::wcout << "You found the treasure!\nGood job!!\n\n";
                    return true;
               }
               if (dynamic_cast<Trap*>((*entities)[i]) != nullptr) {
                    std::wcout << "A trap got you!\nThat's not good...\n\n";
                    return true;
               }
               if (dynamic_cast<Enemy*>((*entities)[i]) != nullptr) {
                    std::wcout << "You got caught by an enemy!\nBetter luck next time...\n\n";
                    return true;
               }
          }
     }
     return false;
}

////Get Key Input
//Check for arrow key code to avoid double input
//Move player based on key input
void Game::GetKeyInput(int c) {
     int* playerPos = (*entities)[0]->GetPosition();
     int* dungeonSize = dungeon->GetSize();

     if (c == 224) {
          c = _getch();
          switch (c) {
          case KEY_UP:
               if (playerPos[1] > 0) (*entities)[0]->MoveEntity(0, -1);
               break;
          case KEY_DOWN:
               if (playerPos[1] < (dungeonSize[1] - 1)) (*entities)[0]->MoveEntity(0, 1);
               break;
          case KEY_LEFT:
               if (playerPos[0] > 0) (*entities)[0]->MoveEntity(-1, 0);
               break;
          case KEY_RIGHT:
               if (playerPos[0] < (dungeonSize[0] - 1)) (*entities)[0]->MoveEntity(1, 0);
               break;
          default:
               break;
          }
     }
}

////Move Enemies
//
void Game::MoveEnemies() {
     for (int i = 1; i < entities->size(); i++) {
          if (dynamic_cast<Enemy*>((*entities)[i]) != nullptr) {
               int newX, newY;
               bool moved;

               do {
                    moved = true;
                    newX = (*entities)[i]->GetPosition()[0];
                    newY = (*entities)[i]->GetPosition()[1];

                    switch (rand() % 4) {
                    case 0:
                         newY--;
                         break;
                    case 1:
                         newY++;
                         break;
                    case 2:
                         newX--;
                         break;
                    case 3:
                         newX++;
                         break;
                    default:
                         break;
                    }

                    if ((newX > 0 && newX < (dungeon->GetSize()[0] - 1)) &&
                         (newY > 0 && newY < (dungeon->GetSize()[1] - 1))) {
                         for (int j = 0; j < entities->size(); j++) {
                              if ((*entities)[i] != (*entities)[j] &&
                                   (*entities)[j]->CheckCollision(newX, newY)) {
                                   if (dynamic_cast<Player*>((*entities)[j]) == nullptr) {
                                        moved = false;
                                   }
                              }
                         }
                    }
                    else {
                         moved = false;
                    }
               } while (!moved);
               (*entities)[i]->SetPosition(newX, newY);
          }
     }
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