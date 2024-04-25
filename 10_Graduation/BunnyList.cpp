#include "BunnyList.h"

BunnyList::BunnyList(int c, Logger* logger) {
     head = nullptr;
     pop = 0;
     this->logger = logger;
     for (int i = 0; i < c; i++) AddBunny(new Bunny());

     std::ifstream maleNameFile(MALE_FILE);
     std::ifstream femaleNameFile(FEMALE_FILE);
     std::ifstream lastNameFile(LASTNAME_FILE);
     size_t longestFirstName = 0;
     size_t longestLastName = 0;
     std::string line;
     
     while (std::getline(maleNameFile, line))
          if (line.length() > longestFirstName)
               longestFirstName = line.length();
     while (std::getline(femaleNameFile, line))
          if (line.length() > longestFirstName)
               longestFirstName = line.length();
     while (std::getline(lastNameFile, line))
          if (line.length() > longestLastName)
               longestLastName = line.length();

     maleNameFile.close();
     femaleNameFile.close();
     lastNameFile.close();

     nameBuffer = 33 + longestFirstName + longestLastName;
}

BunnyList::~BunnyList() {
     while (head) {
          Node* temp = head;
          head = head->next;
          delete temp;
     }
     delete head;
}

void BunnyList::AddBunny(Bunny* bunny) {
     Node* newNode = new Node();
     newNode->bunny = bunny;
     logger->AddToLog(bunny->GetName().append(" has been born."));
     
     if (head == nullptr) {
          head = newNode;
          pop++;
          return;
     }

     Node* temp = head;
     while (temp->next) temp = temp->next;
     temp->next = newNode;
     pop++;
}

void BunnyList::KillBunny(Node** listHead, Bunny* bunny) {
     Node* temp;
     if ((*listHead)->bunny == bunny) {
          temp = *listHead;
          *listHead = (*listHead)->next;
          logger->AddToLog(temp->bunny->GetName().append(" has died."));
          delete temp;
          pop--;
     }
     else {
          Node* curr = *listHead;
          while (curr->next != NULL) {
               if (curr->next->bunny == bunny) {
                    temp = curr->next;
                    curr->next = curr->next->next;
                    logger->AddToLog(temp->bunny->GetName().append(" has died."));
                    delete temp;
                    pop--;
                    break;
               }
               else {
                    curr = curr->next;
               }
          }
     }
}

void BunnyList::PrintBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: PRINTING BUNNIES\n";
#endif

     Node* temp = head;

     do{
          logger->AddToLog(temp->bunny->GetInfo(nameBuffer));
          temp = temp->next;
     } while (temp);

#ifdef DEBUG
     std::cout << "DEBUG: DONE PRINTING BUNNIES\n";
#endif
}

void BunnyList::AgeBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: AGING BUNNIES\n";
#endif

     Node* curr = head;
     do{
          if ((curr->bunny->GetRadioactive() && curr->bunny->GetAge() == 50) ||
              (!curr->bunny->GetRadioactive() && curr->bunny->GetAge() == 10)) {
               Node* temp = curr;
               curr = curr->next;

               KillBunny(&head, temp->bunny);
          }
          else {
               curr->bunny->SetAge(curr->bunny->GetAge() + 1);
               curr = curr->next;
          }
     } while (curr && BunniesExist());

#ifdef DEBUG
     std::cout << "DEBUG: DONE AGING BUNNIES\n";
#endif
}

bool BunnyList::BreedBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: BREEDING BUNNIES\n";
#endif
     bool bred = false;
     Node* tempA = head;
     while (tempA) {
          if (tempA->bunny->CanBreed()) {
               Node* tempB = head;
               while (tempB) {
                    if (tempB != tempA && tempB->bunny->CanBreed() &&
                         (tempA->bunny->GetSex() != tempB->bunny->GetSex())) {
                         AddBunny(new Bunny((tempA->bunny->GetSex() == Sex::FEMALE) ? tempA->bunny->GetFur() : tempB->bunny->GetFur()));
                         bred = true;
                         if (GetPopulation() > CULL_COUNT) {
                              CullBunnies();
#ifdef DEBUG
                              std::cout << "DEBUG: BUNNY BREEDING RESULTED IN CULLING\n";
#endif
                              return bred;
                         }
                    }
                    tempB = tempB->next;
               }
          }
          tempA = tempA->next;
     }

#ifdef DEBUG
     std::cout << "DEBUG: DONE BREEDING BUNNIES\n";
#endif

     return bred;
}

bool BunnyList::TurnBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: TURNING BUNNIES\n";
#endif
     bool anyTurned = false;
     std::vector<Node*> mutants;
     std::vector<Node*> newMutants;
     Node* temp = head;
     while (temp) {
          if (temp->bunny->GetRadioactive())
               mutants.push_back(temp);
          temp = temp->next;
     }

     for (auto& m : mutants) {
          bool turned = false;
          if (mutants.size() + newMutants.size() == GetPopulation()) break;
          do {
               int random = rand() % GetPopulation();
               int i = 0;
               Node* temp = head;
               do {
                    if (temp != m &&
                         !temp->bunny->GetRadioactive() &&
                         (count(newMutants.begin(), newMutants.end(), temp) == 0) &&
                         random == i) { 
                         logger->AddToLog(m->bunny->GetName().append(" turned ").append(temp->bunny->GetName()));
                         newMutants.push_back(temp);
                         turned = true;
                         break;
                    }
                    i++;
                    temp = temp->next;
               } while (temp);
          } while (turned == false);
     }

     if (newMutants.size() > 0) anyTurned = true;

     for (auto n : newMutants) {
          n->bunny->SetRadioactive(true);
     }

     mutants.clear();
     newMutants.clear();
#ifdef DEBUG
     std::cout << "DEBUG: DONE TURNING BUNNIES\n";
#endif
     return anyTurned;
}

void BunnyList::CullBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: CULLING BUNNIES\n";
#endif

     int cullCount = GetPopulation() / 2;
     std::string str = "\nOverpopulation has caused ";
     str.append(std::to_string(cullCount)).append(" random bunnies to die");
     logger->AddToLog(str);

     for (int i = 0; i < cullCount; i++) {
          int random = rand() % GetPopulation();
          int x = 0;
          Node* temp = head;
          while(temp){
               if (x == random) {
                    KillBunny(&head, temp->bunny);
                    break;
               }
               x++;
               temp = temp->next;
          }
     }

#ifdef DEBUG
     std::cout << "DEBUG: DONE CULLING BUNNIES\n";
#endif
}

bool BunnyList::BunniesExist() {
     if (head != NULL) return true;
     return false;
}