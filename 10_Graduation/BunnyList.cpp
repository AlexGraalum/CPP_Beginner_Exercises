#include "BunnyList.h"

BunnyList::BunnyList(int c) {
     head = nullptr;
     pop = 0;
     for (int i = 0; i < c; i++)
          AddBunny(new Bunny());
}

BunnyList::~BunnyList() {
     while (head) {
          Node* temp = head;
          head = head->next;
          delete temp->bunny;
          delete temp;
     }
     delete head;
}

void BunnyList::AddBunny(Bunny* bunny) {
     Node* newNode = new Node();
     newNode->bunny = bunny;

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
}

void BunnyList::PrintBunnies() {
     Node* temp = head;

     do{
          temp->bunny->PrintInfo();
          temp = temp->next;
     } while (temp);
}

void BunnyList::AgeBunnies() {
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
}

void BunnyList::BreedBunnies() {
     Node* tempA = head;
     do{
          if (tempA->bunny->GetAge() > 1 && !tempA->bunny->GetRadioactive()) {
               Node* tempB = tempA->next;
               do{
                    if ((tempB->bunny->GetSex() != tempA->bunny->GetSex()) && 
                         tempB->bunny->GetAge() > 1 && !tempB->bunny->GetRadioactive()) {
                         AddBunny(new Bunny((tempA->bunny->GetSex() == Sex::FEMALE) ? tempA->bunny->GetFur(): tempB->bunny->GetFur()));
                    }
                    tempB = tempB->next;
               } while (tempB);
          }
          tempA = tempA->next;
     } while (tempA->next);
}

void BunnyList::TurnBunnies() {
     Node* tempA = head;
     do {
          if (tempA->bunny->GetRadioactive()) {
               int random = rand() % GetPopulation();
               int i = 0;
               Node* tempB = head;
               do {
                    if (tempB != tempA && !tempB->bunny->GetRadioactive() && random == i) {
                         std::cout << *(tempA->bunny) << " turned " << *(tempB->bunny) << std::endl;
                         tempB->bunny->SetRadioactive(true);
                         break;
                    }
                    i++;
                    tempB = tempB->next;
               } while (tempB);
          }
          tempA = tempA->next;
     } while (tempA);
}

void BunnyList::CullBunnies() {
     std::cout << "Overpopulation has caused 500 random bunnies to die.\n";
     for (int i = 0; i < 500; i++) {
          int random = rand() % GetPopulation();
          int x = 0;
          Node* temp = head;
          do {
               if (random == x) {
                    KillBunny(&head, temp->bunny);
                    break;
               }
               x++;
               temp = temp->next;
          } while (temp);
     }
}

bool BunnyList::BunniesExist() {
     if (head != NULL) return true;
     return false;
}