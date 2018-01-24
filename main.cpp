#include "Skater.hpp"
#include "MichelleKwan.hpp"
#include "TaraLipinski.hpp"
#include "Quality.hpp"
#include "Space.hpp"
#include "Choreography.hpp"
#include "CombinationSpin.hpp"
#include "StepSequence.hpp"
#include "JumpCombination.hpp"
#include "Podium.hpp"
#include "Retirement.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

using namespace std;

int getInt();
int toosmall();
void fight(Skater* a, Skater* b);
void optionsMenu();
bool isQualityInBag(string name, Quality xyz[], int);

int main()
{
  unsigned seed;
  seed = time(0);
  srand(seed);
  int choice;
  Skater *michelleKwan;
  Skater *taraLipinski;
  int numMoves;
  numMoves = 1;
  Space* currentSpaceCurrentSpace;

  //menu for game
  while (!(choice == 3))
  {
    cout << "******* Welcome to the 1998 Olympics in Nagano, Japan *******"<<endl;
    cout <<"This is the Ladies' Figure Skating Final!"<<endl<< "Our last two competitors are ";
    cout<<"Michelle Kwan and Tara Lipinski!"<<endl<<endl;
    cout << "Menu:" <<endl;
    cout << "1 - Play Game" << endl;
    cout << "2 - Game Objective" << endl;
    cout << "3 - Exit Game" << endl;

    choice = getInt();
    while (choice < 0 || choice == 0 || choice > 3)
    {
      if(choice < 0 || choice == 0)
      {
        cout << "Choices must be a positive integer greater than 0" << endl;
        cin>>choice;
      }
      else
      {
        cout << "Choices must only be 1, 2, or 3" << endl;
        cin>>choice;
      }
    }

    if(choice == 1)
    {
      MichelleKwan Michelle;
      michelleKwan = &Michelle;
      TaraLipinski tara;
      taraLipinski = &tara;
      
      Space* currentSpace;
      Space* space1;
      Space* space2;
      Space* space3;
      Space* space4;
      Space* space5;

      Quality bag[5];
      int arrayEnd = 0;

      space1 = new Choreography;
      space2 = new CombinationSpin;
      space3 = new StepSequence;
      space4 = new JumpCombination;
      space5 = new Podium;
      currentSpace = space1;
      currentSpaceCurrentSpace = currentSpace;

      //Only 6 moves are allowed for this game
      while(!(currentSpace->getRoomName() == "Podium" && currentSpace->getVisited()==1) && michelleKwan->getStrength()>0 && numMoves < 7 )
      {

        char yOrN;
        cout<< endl;
        cout << "                    ***************" << endl;
        cout << "Current Element: " << currentSpace->getRoomName() << "."<< endl;
        cout << "                    ***************" << endl;
        cout << endl;
        if(currentSpace->getRoomName() == "Choreography" && currentSpace->getVisited()==0)
        {
          currentSpace->specialFunction();
          Quality artistry;
          artistry.setQualityName("Artistry");
          bag[arrayEnd] = artistry;
          arrayEnd++;
          cout << "Michelle earned the followiing quality: "  << endl;
          cout << artistry.getQualityName()<< endl;
          currentSpace->setVisited();
          cout << endl;
        }
        else if (currentSpace->getRoomName() == "Combination Spin" && currentSpace->getVisited()==0)
        {
          currentSpace->specialFunction();
          Quality grace;
          grace.setQualityName("Grace");
          bag[arrayEnd] = grace;
          arrayEnd++;
          cout << "Michelle earned the followiing quality: " << endl;
          cout << grace.getQualityName()<< endl;
          currentSpace->setVisited();
          cout << endl;
        }
        else if (currentSpace->getRoomName() == "Step Sequence" && currentSpace->getVisited()==0)
        {
          currentSpace->specialFunction();
          Quality technicalAbility ;
          technicalAbility.setQualityName("Technical Ability");
          bag[arrayEnd] = technicalAbility;
          arrayEnd++;
          cout << "Michelle earned the followiing quality: "  << endl;
          cout << technicalAbility.getQualityName() << endl;
          currentSpace->setVisited();
          cout << endl;
        }
        else if(currentSpace->getRoomName() == "Jump Combination" && currentSpace->getVisited()==0)
        {
          currentSpace->specialFunction();
          Quality strength;
          strength.setQualityName("Strength");
          bag[arrayEnd] = strength;
          arrayEnd++;
          cout << "Michelle earned the followiing quality: "  << endl;
          cout << strength.getQualityName() << endl;
          currentSpace->setVisited();
          cout << endl;
        }
        else if(currentSpace->getRoomName() == "Podium" && currentSpace->getVisited()==0)
        {
          Quality Fulfillment;
          currentSpace->specialFunction();
          if(static_cast<Podium*>(currentSpace)->getOption() == 'Y' || static_cast<Podium*>(currentSpace)->getOption() == 'y')
          {
            Fulfillment.setQualityName("Fulfillment");
            bag[arrayEnd] = Fulfillment;
            arrayEnd++;
            cout << "Michelle earned the followiing quality: " << endl;
            cout << Fulfillment.getQualityName() << endl;
          }
          currentSpace->setVisited();
          cout << endl;
        }
        else
        {
          cout <<"You have already completed this element. Please go do a new element in your program."<<endl;
        }

      fight(michelleKwan, taraLipinski);

      cout << endl;

      if(currentSpace->getRoomName()=="Podium" && (currentSpace->getVisited()==1))
      {
        //do nothing
      }
      else
      {
        optionsMenu();
        cin>>choice;
        switch(choice)
        {
          case 1:
            currentSpace = space1;
            break;

          case 2:
            currentSpace = space2;
            break;

          case 3:
            currentSpace = space3;
            break;

          case 4:
            currentSpace = space4;
            break;

          case 5:
            currentSpace = space5;
            break;
        }
        if(currentSpace->getRoomName() == "Step Sequence" && !(isQualityInBag("Artistry", bag, arrayEnd)
                &&isQualityInBag("Grace", bag, arrayEnd)))
        {
          cout <<"You must go back to the Combination Spin to get your grace quality!" << endl;
              cout << "       *******" << endl;
          cout <<"you are being sent to the Combination Spin now." << endl;
                      cout << "     *******" << endl;
          currentSpace =space2;
        }
        else if (currentSpace->getRoomName() == "Jump Combination" && !(isQualityInBag("Artistry", bag, arrayEnd)
                &&isQualityInBag("Grace", bag, arrayEnd) && isQualityInBag("Technical Ability", bag, arrayEnd)))
        {
          if(!isQualityInBag("Grace", bag, arrayEnd))
          {
            cout << "You must get the grace quality first before you can continue."<<endl;
            cout <<"You are being sent to the Combination Spin now." << endl;
            currentSpace = space2;
          }
          else
          {
            cout <<"You must go to the Step Sequence to get your technical ability quality!" << endl;
            cout<<"You are being sent to the Step Sequence now." << endl;
            currentSpace = space3;

          }
        }
        else if (currentSpace->getRoomName() == "Podium" && !(isQualityInBag("Artistry", bag, arrayEnd)
                &&isQualityInBag("Grace", bag, arrayEnd) && isQualityInBag("Technical Ability", bag, arrayEnd)
                && isQualityInBag("Strength", bag, arrayEnd)))
        {
          if(!isQualityInBag("Grace", bag, arrayEnd))
          {
            cout << "You must get grace quality first before you can continue."<<endl;
            cout <<"You are being sent to the Combination Spin now." << endl;
            currentSpace = space2;
          }
          else if (!(isQualityInBag("Technical Ability", bag, arrayEnd)))
          {
            cout <<"You must go to the Step Sequence to get your Technical Ability!" << endl;
            cout<<"You are being sent to the Step Sequence now." << endl;
            currentSpace = space3;
          }
          else
          {
            cout <<"You must go to the Jump Combination to get your strength to unlock the Podium!" << endl;
            cout<<"You are being sent to Jump Combination now." << endl;
            currentSpace = space4;
          }
        }
        cout <<"Do you want see the qualities Michelle currently has earned?  Enter Y or N: "<< endl;
        cin>> yOrN;
        if(yOrN == 'y'|| yOrN == 'Y')
        {
          cout << "Michelle earned the followiing quality: " << endl;
          for(int i = 0; i < arrayEnd; i++)
            cout << (i+1) << " : " << bag[i].getQualityName() << endl;
          cout << endl;
        }
      }
      numMoves++;
    }
      cout<< endl;
      if (numMoves > 6)
      {
        cout << "The number of moves exceeded the maximum number of moves allowed. "  << endl;
        cout << "Please Play Again";
        cout << endl;
      }
      else
      {
        if(dynamic_cast<Podium*>(currentSpace)->getOption() == 'y' ||  dynamic_cast<Podium*>(currentSpace)->getOption() == 'Y')
        {

          currentSpace = NULL;
          currentSpace = new Retirement;
          cout<< endl;
          cout << "                    *********" << endl;
          cout << "You are at the " << currentSpace->getRoomName() << " element."<< endl;
          cout << "                    *********" << endl;
          currentSpace->specialFunction();
          cout << endl;
        }
        else
        {
          cout <<"Michelle Kwan has decided to keep competing as an amateur athlete."<<endl;
          cout<<"She will continue on to the 2002 Olympics in Salt Lake City "<<endl;
          cout<<"where she will battle another rival, Sarah Hughes."<<endl;
        }
      }
      //reset to replay game
      space1->reset();
      space2->reset();
      space3->reset();
      space4->reset();
      space5->reset();
      numMoves = 1;
    }
    else if (choice == 2)
    {

      cout<<endl;
      cout<< "             Game Objective          "<<endl;
      cout<<"Michelle Kwan is in the skating battle of her career as she competes against "<<endl;
      cout<<"her rival, Tara Lipinski. During her final routine at the Olympics, she must "<<endl;
      cout<<"complete the following elements:"<<endl;
      cout<<"1) Choreography"<<endl<<"2) Combination Spin"<<endl<<"3) Step Sequence"<<endl<<"4) Jump Combination"<<endl;
      cout<<"Kwan will battle Lipinksi inside each element and competition disqualification is a possibility."<<endl;
      cout<<"Each element will require a task to be completed to earn a 'quality'."<<endl;
      cout<<"After Michelle has earned the 4 element qualities, she can move on to the podium."<<endl;
      cout<<"Based on the scores from the short program, we know Michelle will either earn silver "<<endl;
      cout<<"or gold so she is definitely on that podium."<<endl;
      cout<<"Once she is awarded her medal, Michelle must choose to retire or continue as an amateur athlete."<<endl;
      cout<<"While the gold medal is the ultimate goal, choosing to retire or not is up to you."<<endl;
      cout<<endl<<"You will have 6 moves to complete the game before time is up."<<endl;
      cout<<"TIP: The ideal path to reach the end goal is to do the elements in order, however, she may do them out of order."<<endl;
      cout<<endl;
    }

    if (numMoves > 6)
    {
      cout << " The number of moves exceeded the maximum number of moves allowed "  << endl;
      cout << "Please Play Again";
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

int getInt()
{
 	int x;
 	while(!(cin >> x))
  {
 		cin.clear();
 		cin.ignore(numeric_limits<streamsize>::max(),'\n');
 		cout << "ERROR: Input must be integers.\n";
 	}
 	return x;
}

int toosmall()
{
  cout << "ERROR: Please enter a positive integer that is greater than 0." <<endl;
  int x = getInt();
  while(x < 0 || x == 0)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "ERROR: Try again."<<endl;
    x = getInt();
  }
  return (x);
}

void fight(Skater* a, Skater* b)
{
  string opponent1 = "Michelle Kwan";
  string opponent2 = "Tara Lipinski";
  cout<<"Now the two skaters must battle over this element!"<<endl;
  int Opponent1Attack = a->attack();
  b->defend(Opponent1Attack);
  int Opponent2Attack = b->attack();
a->defend(Opponent2Attack);

    if (a->getStrength()>b->getStrength())
        cout<<"Michelle Kwan beat Tara Lipinski at this element!"<<endl;
    else if (a->getStrength()==b->getStrength())
        cout<<"Michelle and Tara got the same score on this element."<<endl;
    else if (a->getStrength()<b->getStrength())
        cout<<"Tara Lipinski beat Michelle Kwan at this element."<<endl;
}


void optionsMenu()
{
  cout << "Choose an element: "<< endl;
  cout << "1 - Choreography " << endl;
  cout << "2 - Combination Spin " << endl;
  cout << "3 - Step Sequence " << endl;
  cout << "4 - Jump Combination" << endl;
  cout << "5 - The Podium "<< endl;
}

bool isQualityInBag(string name, Quality xyz[], int y)
{
  for(int k=0; k < y; k++)
  {
    if(name == xyz[k].getQualityName())
    {
      return true;
    }
  }
  return false;
}
