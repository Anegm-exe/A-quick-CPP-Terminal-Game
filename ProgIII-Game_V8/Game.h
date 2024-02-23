#ifndef GAME
#define GAME
#include "Object.h"
#include "Hero.h"

class Game{
private:
    Object*** grid;
    int rows;
    int columns;
    Hero* hero;
    static int round;

public:
    Game();

    Game(int rows, int columns, Hero* hero);

    ~Game();

    // Getter & setter

    Object*** getGrid() const;

    void setGrid(Object*** grid);

    int getRows() const;

    void setRows(int rows);

    int getColumns() const;

    void setColumns(int columns);

    Hero* getHero() const;

    void setHero(Hero* hero);

    int getRound() const;

    void incrementRound();

    // Methods

    void GenerateMap();

    void showMap();

    void startGame();

    void Move(Hero& h1 , char direction);

    void FireGun(char direction);

    void useGunSpecial();

    int checkGameOver();

    void updateMap();

    void spawnMonster(char monsterType);

    void respawnMonsters();
};
#endif
