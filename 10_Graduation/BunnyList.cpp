#include "BunnyList.h"

////BunnyList Initializer
//  Initialize the BunnyList Object
//Set Node* head to nullptr
//Set population to 0
//Assign Logger object
//Add c count of bunnies
//Find the longest possible name
// for formatting
BunnyList::BunnyList(int c, Logger* logger) {
#ifdef DEBUG
     std::cout << "DEBUG: INITIALIZING BUNNYLIST\n";
#endif
     head = nullptr;
     pop = 0;
     this->logger = logger;
     for (int i = 0; i < c; i++) {
          Bunny* temp = new Bunny();
          logger->AddToLog(temp->GetName().append(" was given life."));
          AddBunny(temp);
     }

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
#ifdef DEBUG
     std::cout << "DEBUG: DONE INITIALIZING BUNNYLIST\n";
#endif
}

////Bunny Destructor
//  Destroy the BunnyList Object
//Delete each Node in LinkedList
BunnyList::~BunnyList() {
#ifdef DEBUG
     std::cout << "DEBUG: DELETING BUNNYLIST\n";
#endif
     while (head) {
          Node* temp = head;
          head = head->next;
          delete temp;
     }
     delete head;
#ifdef DEBUG
     std::cout << "DEBUG: DONE DELETING BUNNYLIST\n";
#endif
}

////Add Bunny
//  Add a new Bunny to back of LinkedList
//Create a new Node and assign bunny
//Find back of LinkedList
//Insert new Node to LinkedList
//Increase population count
void BunnyList::AddBunny(Bunny* bunny) {
#ifdef DEBUG
     std::cout << "DEBUG: ADDING BUNNY NODE\n";
#endif
     Node* newNode = new Node();
     newNode->bunny = bunny;
     
     if (head == nullptr) {
          head = newNode;
          pop++;
#ifdef DEBUG
          std::cout << "DEBUG: DONE ADDING BUNNY NODE\n";
#endif
          return;
     }

     Node* temp = head;
     while (temp->next) temp = temp->next;
     temp->next = newNode;
     pop++;
#ifdef DEBUG
     std::cout << "DEBUG: DONE ADDING BUNNY NODE\n";
#endif
}

////Kill Bunny
//  Delete specified Bunny from LinkedList
//Assign temp Node to head
//If Bunny to delete is head
// immediately delete
//Else iterate through LinkedList
//  and delete when Bunny is found
//Decrease population count
void BunnyList::KillBunny(Node** listHead, Bunny* bunny) {
#ifdef DEBUG
     std::cout << "DEBUG: DELETING BUNNY NODE\n";
#endif
     Node* temp;
     if ((*listHead)->bunny == bunny) {
          temp = *listHead;
          *listHead = (*listHead)->next;
          delete temp;
          pop--;
     }
     else {
          Node* curr = *listHead;
          while (curr->next != NULL) {
               if (curr->next->bunny == bunny) {
                    temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                    pop--;
                    break;
               }
               else {
                    curr = curr->next;
               }
          }
     }
#ifdef DEBUG
     std::cout << "DEBUG: DONE DELETING BUNNY NODE\n";
#endif
}

////Print Bunnies
//  Print information for all Nodes
//Iterate through LinkedList
//Push Bunny info to Logger
void BunnyList::PrintBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: PRINTING BUNNIES\n";
#endif
     Node* temp = head;

     while (temp){
          logger->AddToLog(temp->bunny->GetInfo(nameBuffer));
          temp = temp->next;
     }
     logger->AddToLog("");
#ifdef DEBUG
     std::cout << "DEBUG: DONE PRINTING BUNNIES\n";
#endif
}

////Age Bunnies
//  Age all Bunnies
//Iterate through LinkedList
//If old age has been reached, KILL
//Else increment age
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

               logger->AddToLog(temp->bunny->GetName().append(" has died of old age."));
               KillBunny(&head, temp->bunny);
          }
          else {
               curr->bunny->SetAge(curr->bunny->GetAge() + 1);
               logger->AddToLog(curr->bunny->GetName().append(" is now ").append(std::to_string(curr->bunny->GetAge())).append(" years old."));
               curr = curr->next;
          }
     } while (curr && BunniesExist());
     logger->AddToLog("");
#ifdef DEBUG
     std::cout << "DEBUG: DONE AGING BUNNIES\n";
#endif
}

void BunnyList::AgeBunny(Node* bun) {
     bun->bunny->SetAge(bun->bunny->GetAge() + 1);
     logger->AddToLog(bun->bunny->GetName().append(" is now ").append(std::to_string(bun->bunny->GetAge())).append(" years old."));
}

////Breed Bunnies
//  Breed New Bunnies From Population
//Set Bred flag for formatting
//Iterate first Node through LinkedList
//  Skip if Node is not valid candidate
//Iterate second Node through LinkedList
//  Skip if Node is not valid candidate
//If both are valid create New Bunny
//Check for overpopulation
//  Break iteration and start Cull if
//    overpopulation
bool BunnyList::BreedBunnies() {
#ifdef DEBUG
     std::cout << "DEBUG: BREEDING BUNNIES\n";
#endif
     bool bred = false;
     Node* tempA = head;

     while (tempA) {
          if ((tempA->bunny->GetSex() == Sex::MALE) && tempA->bunny->CanBreed()) {
               Node* tempB = head;
               while(tempB){
                    if (tempB != tempA && (tempB->bunny->GetSex() == Sex::FEMALE) && tempB->bunny->CanBreed()) {
                         Bunny* tempChild = new Bunny((tempA->bunny->GetSex() == Sex::FEMALE) ? tempA->bunny->GetFur() : tempB->bunny->GetFur());

                         logger->AddToLog(tempA->bunny->GetName().append(" and ").append(tempB->bunny->GetName()).append(" gave birth to ").append(tempChild->GetName()).append("."));

                         AddBunny(tempChild);
                         bred = true;
                         if (GetPopulation() > POPULATION_LIMIT) {
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

////Turn Bunnies
//  Turn Bunnies Into Mutants
//Set anyTurned flag for formatting
//Get vector of current mutant Bunnies
//Iterate linkedlist and turn valid targets
//  Add target to new vector
//Iterate new target vector and turn targets
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
                    if ((temp != m) && 
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

////Cull Bunnies
//  Cull Bunnies From Overpopulation
//Get half the population
//Iterate through half population
//Choose a random bunny and KILL
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
                    logger->AddToLog(temp->bunny->GetName().append(" has died to starvation."));
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

////Bunnies Exist
//Check if the LinkedList is empty
bool BunnyList::BunniesExist() {
     if (head != NULL) return true;
     return false;
}

////Is Death Cascde
//  Are the bunnies on a path of destruction
//Are all the bunnies mutants?
//Are all the bunnies the same sex?
bool BunnyList::IsDeathCascade() {
     Node* curr = head;
     Sex sex;

     //All Mutants?
     while (curr->bunny->GetRadioactive()) curr = curr->next;
     if (curr == nullptr) return true;

     sex = curr->bunny->GetSex();
     curr = curr->next;

     while (curr) {
          if (!curr->bunny->GetRadioactive() && curr->bunny->GetSex() != sex)
               return false;
          curr = curr->next;
     }

     return true;
}