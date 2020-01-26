#include <iostream>
#include <string>
#include <vector>

struct Posicion2D
{
	int X, Y;
};

struct Enemy
{
	char skin;
	Posicion2D pos;
};

struct Player
{
	char skin;
	Posicion2D pos;
};

struct room
{
	int index;
	std::vector<Enemy> enemyList;
	Player player;
	int startEnemyNUm;
};

room firstRoom;

struct magString
{
	std::string type;
	std::string content;
};

int main()
{
	std::string str ("index: 1; player: pos: x: 3, y: 4 . skin: X; startenemynum: 3;");

	std::vector<std::string> Estrings;

	//int dp = str.find(";");
	//std::string firstString = str.substr(0, dp+1);
	//std::cout << firstString << std::endl;

	//std::string firstRestString = str.substr(dp+1);

	//int dp2 = firstRestString.find(";");
	//std::string secondString = firstRestString.substr(0, dp2+1);
	//std::cout << secondString << std::endl;
	//
	//std::string secondRestString = firstRestString.substr(dp2+1);

	//int dp3 = secondRestString.find(";");
	//std::string thirdString = secondRestString.substr(0, dp3+1);
	//std::cout << thirdString << std::endl;

	for (size_t i = 0; i < str.size(); i++)
	{
		std::string AuxString = str;
		int PuntoComa = AuxString.find(';');
		Estrings.push_back(AuxString.substr(0, PuntoComa+1));
		str = str.substr(PuntoComa+1);
	}
	std::vector<magString> who;
	for (size_t i = 0; i < Estrings.size(); i++)
	{
		std::cout << Estrings[i] << std::endl;
		std::string AuxString = Estrings[i];
		int PuntoPunto = AuxString.find(':');
		magString AuxMagString;
		AuxMagString.type = AuxString.substr(0, PuntoPunto + 1);
		AuxMagString.content = AuxString.substr(PuntoPunto + 1);
		who.push_back(AuxMagString);

		if (who.at(i).type[0] == ' ')
		{
			who.at(i).type = who.at(i).type.substr(1);
		}
		char c = who.at(i).type[0];

		switch (c)
		{
		case 'i':
			std::cout << who.at(i).type << who.at(i).content << std::endl;
			firstRoom.index = stoi(who.at(i).content);
			break;
		case 'p':
			std::cout << who.at(i).type << who.at(i).content << std::endl;

			break;
		case 's':
			break;
		default:
			break;
		}
	}

	std::cout << std::endl << firstRoom.index;

	std::getchar();
	std::cin.get();

	return 0;
}