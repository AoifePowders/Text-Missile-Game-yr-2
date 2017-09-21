//Name: Aoife Powders
//Date: 14/09/17
//Time Taken:

#include <iostream>
#include <cstdlib>
#include <ctime>

//gets position of target
typedef struct Position
{
	int launchx = 0;
	int launchy = 0;
	int x = 0;
	int y = 0;
	int Enter;

	void printPos() //function that prints coordinates x and y
	{
		std::cout << "Enter Target X Coordinates (1-10): " ;
		std::cin >> launchx;
		std::cout << "Enter Target Y Coordinates (1-10): " ;
		std::cin >> launchy;
		std::cout << "Target Coordinates are: "<< launchx <<"," << launchy << std::endl;
		std::cout << "Press any number and enter to continue" << std::endl;
		std::cin >> Enter;
		system("CLS"); // clears the screen
	}
}Coordinates;

	

enum Warhead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy
{
	Coordinates coordinates;
}Target;

struct Missile
{
	int Enter;
	Warhead Payload;
	Coordinates coordinates;
	Target target;
	bool armed;
	int launchCode = (rand() % 1000);
	int launchCode2 = (rand() % 100000);
	int code;
	int launch = 0;
	int weapon;

	//prints the weapon selection
	void printWeapon()
	{

		int time;
		int time2;

		std::cout << "Choose your weapon:" << std::endl << " 1) Explosive (shows short code for 1 second) " << std::endl << " 2) Nuclear (shows long code for 3 seconds)" << std::endl;
		std::cin >> weapon;

		if (weapon == 1)
		{
			std::cout << "You choose Explosive" << std::endl;
			//flashes code on screen
			for (time = 25; time > 0; time--)
			{
				std::cout << "Launch Code is: " << launchCode << std::endl;
				system("CLS");
			}
			
		}
		else
		{
			std::cout << "You choose Nuclear" << std::endl;
			for (time2 = 50; time2 > -1; time2--)
			{
				std::cout << "Launch Code is: " << launchCode2 << std::endl;
				system("CLS");
			}
		}
	}

	void printArm() 
	{
		Missile missile;
		int Enter;
		std::cout << "Enter Launch Code when you want to arm the missile: ";
		std::cin >> code;

		if (weapon == 1)
		{
			if (code != launchCode) // if the launch code is wrong you can retry until you get ut right
			{
				std::cout << "Wrong code, Missile was not armed" << std::endl;
				std::cout << "Press any number and enter to retry" << std::endl;
				std::cin >> Enter;
				system("CLS");
				missile.printWeapon();
				missile.printArm();
			}
			else // if launch code is right missile is armed
			std::cout << "Correct code, Missile armed" << std::endl;
			std::cout << "Press any number and enter to continue" << std::endl;
			std::cin >> Enter;
			system("CLS");
		}

		if (weapon == 2)
		{
			if (code != launchCode2)
			{
				std::cout << "Wrong code, Missile was not armed";
				std::cout << "Press any number and enter to retry" << std::endl;
				std::cin >> Enter;
				system("CLS");
				missile.printWeapon();
				missile.printArm();
			}
			else
			std::cout << "Correct code, Missile armed" << std::endl;
			std::cout << "Press any number and enter to continue" << std::endl;
			std::cin >> Enter;
			system("CLS");
		}
	}

	void printLaunch()// prints launch dialogue
	{
		int Enter;
		std::cout << "Would you like to launch? " << std::endl << "Type 1 for Yes or 2 for No" << std::endl;
		std::cin >> launch;

		if (launch != 1) // if you dont launch then the game is poinless really XD
		{
			std::cout << "You choose to not launch missile, The target still stands" << std::endl << "GAME OVER" << std::endl;
			
		}
		else if (launch == 1)
		{
			std::cout << "You chose to launch Missile" << std::endl;
			std::cout << "Press any number and enter to continue" << std::endl;
			std::cin >> Enter;
			system("CLS");
		}
	}

	void update() //function updates missile coordinates
	{
		int randomNumber = (rand() % 10); //gets a random position that missile hit
		int randomNumber2 = (rand() % 10);

			

		if (launch == 1)
		{
			coordinates.x = randomNumber;
			coordinates.y = randomNumber2;
		}
	}

	void printUpdatedcord() // outputs ending
	{
		if (coordinates.x == coordinates.launchx && coordinates.y == coordinates.launchy)
		{
			std::cout << "You have successfully hit the target" << std::endl << "GAME OVER" << std::endl;
		}
		if(coordinates.x != coordinates.launchx || coordinates.y != coordinates.launchy)
		{
			std::cout << "You have failed to hit the target" << std::endl << "GAME OVER " << std::endl;
		}
		else if (coordinates.x != coordinates.launchx &&  coordinates.y != coordinates.launchy)
		{
			std::cout << "You have failed to hit the target" << std::endl << "GAME OVER " << std::endl;
		}

		std::cout << "Missile hit X coordinate " <<coordinates.x << std::endl; //tells you where the missile hit
		std::cout << "Missile hit Y coordinate " <<coordinates.y << std::endl;
	}


};

int main()
{
	srand((unsigned)time(0));
	//calls all functions
	Missile missile;
	missile.printWeapon();

	Position position;
	position.printPos();
	missile.printLaunch();
	missile.printArm();
	
	missile.update();
	missile.printUpdatedcord();

	system("Pause");
}