#pragma once
#include <time.h>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include "Build.h"
#include <map>

#define Num 3
#define counttower 10
#define min5 300
#define tensecond 10
namespace cry {
	struct Option {
		int money;
		int time;
	};

	enum Typeland {
		plain = 0,
		reservoir,
		mountain,
		walltype,
		towertypeempty,
		towertype,
		palacetype,
		lairtype,
		enemytype,


	};
	class landscape {
	private:
		Typeland type;
		int lenght;
		std::pair<int, int> coordinat;


	public:

		int getside() { return lenght; };
		Typeland getType() { return type; };
		int setType(Typeland );/*
		int setCoordinate(std::pair <int,int>);*/
		std::pair <int, int> getcoordinat() { return coordinat; };


	};


	class Playng_field {
	private:
		int lenght;
		int width;
		Palace palace;
		Lair lair;
		/*int time;*/
		std::pair<int, int> laircoordin;
		std::map<std::pair<int, int>, typeenemy > typewhere;
		
	public:
		std::map <std::pair<int, int>, std::shared_ptr<Enemy> >  enemywhere;
		std::vector <std::vector<landscape>> quad;
		std::pair <int, int> palacecoordin;
		std::vector < std::shared_ptr<Enemy> > enemypalace;
		std::map<std::pair<int,int>,std::shared_ptr<Tower> > towerwhere;
	public:
		Playng_field();
		int calculateTrajectory();
		int getLen() { return lenght; };
		int getWid() { return width; };
		landscape getquad(std::pair<int, int> t) { return quad[t.first][t.second]; };
		std::pair<int, int> getpairpalace() { return  palacecoordin; };
		int setpairpalace(std::pair<int, int> );
		void setlenght(int);
		void setwidth(int);
		int creatfiald(std::pair<int, int>, Typeland);
		int setpairenemy(std::pair<int, int>,typeenemy); 
		int setpairlair(std::pair<int, int> a);
		void setCoordin(std::pair<int, int>, std::pair<int, int>, std::vector<std::pair<int, int>> twr);
		int show();
	};
	class Game {
	private:
		Playng_field card;
		std::string menu[Num] = { "Hello!let's go.Enemy mustn't destroy u palace\n","game over\n","fly enemy just keep way to palace" };
		time_t clock;
		time_t clocktolvl;
		std::vector<std::pair <int, int>> towercoordin;
		std::pair <int, int> palacecordin;
		std::pair <int, int> laircoordin;//что бы правильно сформировать уровень вроде как башни находятся всегда на одних координатах
		Palace palace;
		Lair lair;
		Wall wall;
		Option option;
	public:
		Game();
		int start();
		int putenemy(allenemy&);
		int creatbuild(std::pair<int, int> , int );
		time_t gettime();
		time_t countttime();

	};

}