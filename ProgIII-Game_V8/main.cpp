#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

#include "Ammo.h"
#include "Game.h"
#include "Bazooka.h"
#include "Character.h"
#include "DemolitionHero.h"
#include "GhostMonster.h"
#include "Gun.h"
#include "Hero.h"
#include "Item.h"
#include "MedicHero.h"
#include "Monster.h"
#include "Object.h"
#include "Pistol.h"
#include "Potion.h"
#include "Rifle.h"
#include "TankMonster.h"

using namespace std;


// Ammo Class
AMMO Ammo::Ammo() : Item('A'), bulletsNumber(0) {
}

AMMO Ammo::Ammo(int bulletsNumber) : Item('A'), bulletsNumber(bulletsNumber) {
}

AMMO int Ammo::getBulletsNumber() const{
    return bulletsNumber;
}

AMMO void Ammo::setBulletsNumber(int bulletsNumber){
    this -> bulletsNumber = bulletsNumber;
}

AMMO Ammo::~Ammo(){
}

// Bazooka Class
BAZOOKA Bazooka::Bazooka() : Gun("Bazooka", 4, 150, 8, 'B') {
}

BAZOOKA Bazooka::~Bazooka(){
}

//90% sure
BAZOOKA void Bazooka::useSpecial(Hero& hero, Object*** map) {
    int HeroX = hero.getX();
    int HeroY = hero.getY();
    if((HeroX + HeroY) == 14){
        for(int i = 0 ; i < 14 ; i++){
            Object* obj = map[i][14-i];
            if (Monster* monster = dynamic_cast<Monster*>(obj)) {
                monster->setHealthPoints(0);
            }
        }
    }
    if(HeroX == HeroY){
        for(int i = 0 ; i < 14 ; i++){
            Object* obj = map[i][i];
            if (Monster* monster = dynamic_cast<Monster*>(obj)) {
                monster->setHealthPoints(0);
            }
        }
    }
}


// Item Class
ITEM Item::Item(char type) : Object(type) {}

ITEM Item::~Item(){
}

// Character Class
CHARACTER Character::Character() : Object() { x = 0; y = 0; healthPoints = 0; }

CHARACTER Character::Character(char type, int x, int y, int healthPoints) : Object(type), x(x), y(y), healthPoints(healthPoints) {}

CHARACTER int Character::getX() const{
    return x;
}

CHARACTER void Character::setX(int x){
    this -> x = x;
}

CHARACTER int Character::getY() const{
    return y;
}

CHARACTER void Character::setY(int y){
    this -> y = y;
}

CHARACTER int Character::getHealthPoints() const{
    return healthPoints;
}

CHARACTER void Character::setHealthPoints(int healthPoints){
    this -> healthPoints = healthPoints;
}

CHARACTER Character::~Character(){
}

// DemolitionHero
DEMOLITIONHERO DemolitionHero::DemolitionHero() : Hero() { gun2 = nullptr; }

DEMOLITIONHERO DemolitionHero::DemolitionHero(char type, int x, int y, int healthPoints, Gun* weapon, Gun* gun2) : Hero('H', x, y, healthPoints, weapon), gun2(gun2) {}

DEMOLITIONHERO Gun* DemolitionHero::getGun2() const{
    return gun2;
}

DEMOLITIONHERO void DemolitionHero::setGun2(Gun* gun2){
    this -> gun2 = gun2;
}

DEMOLITIONHERO DemolitionHero::~DemolitionHero(){
}

DEMOLITIONHERO void DemolitionHero::useSpecial(){
    Gun* temp = getGun();
    setGun(getGun2());
    setGun2(temp);
}

DEMOLITIONHERO void DemolitionHero::print(ostream& os) const{
    Hero::print(os);
    os << "Special Ability: Secondary-Gun Exchange" << "\n" <<
    "Secondary-Gun: " << getGun2()->getName() << "\n"
    << "Ammo: " << getGun2()->getBullets() << " -- Range: " << getGun2()->getRange() << " -- Damage: "<< getGun2()->getDamageAmount() << endl;
}

// GhostMonster
GHOSTMONSTER GhostMonster::GhostMonster() : Monster() { isVisible = false; }

GHOSTMONSTER GhostMonster::GhostMonster(char type, int x, int y, int healthPoints, string name, bool isVisible) : Monster('G', x, y, healthPoints, name), isVisible(isVisible) {}

GHOSTMONSTER bool GhostMonster::getIsVisible() const{
    return isVisible;
}

GHOSTMONSTER void GhostMonster::setIsVisible(bool isVisible){
    this -> isVisible = isVisible;
}

GHOSTMONSTER GhostMonster::~GhostMonster(){
}

//Gun
GUN Gun::Gun() : Object('G'){}

GUN Gun::Gun(string name, int bullets, int damageAmount, int range, char type) : Object(type), name(name), bullets(bullets), damageAmount(damageAmount), range(range){}

GUN string Gun::getName() const{
    return name;
}

GUN int Gun::getBullets() const{
    return bullets;
}

GUN int Gun::getDamageAmount() const{
    return damageAmount;
}

GUN int Gun::getRange() const{
    return range;
}

GUN void Gun::setName(string name){
    this -> name = name;
}

GUN void Gun::setBullets(int bullets){
    this -> bullets = bullets;
}

GUN void Gun::setDamageAmount(int damageAmount){
    this -> damageAmount = damageAmount;
}

GUN void Gun::setRange(int range){
    this -> range = range;
}

ostream& operator<<(ostream& os, const Gun& gun) {
    os << "Gun Name: " << gun.getName() << "\n"
       << "Bullets: " << gun.getBullets() << "\n"
       << "Damage Amount: " << gun.getDamageAmount() << "\n"
       << "Range: " << gun.getRange() << endl;
    return os;
}

GUN Gun::~Gun(){
}

//Pistol Class
PISTOL Pistol::Pistol() : Gun("Pistol", 16, 30, 2, 'P') {}

PISTOL Pistol::~Pistol(){
}

// Sure 90%
PISTOL void Pistol::useSpecial(Hero& hero, Object*** map) {
    setBullets(getBullets() - 4);
    int heroX = hero.getX();
    int heroY = hero.getY();
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    int damage = getDamageAmount();
    for (int i = 0; i < 4; i++) {
        int newX = heroX + dx[i];
        int newY = heroY + dy[i];
        if (newX >= 0 && newX < 15 && newY >= 0 && newY < 15) {
            Object* obj = map[newX][newY];
            if (GhostMonster* monster = dynamic_cast<GhostMonster*>(obj)){
                int newHealth = monster->getHealthPoints() - damage;
                monster->setHealthPoints(newHealth);
            }else if (TankMonster* monster = dynamic_cast<TankMonster*>(obj)){
                int RemainingDamage = damage;
                if(monster->getShield() > 0){
                    int newShield = monster->getShield() - damage;
                    if (newShield < 0) {
                        RemainingDamage = -newShield;
                        newShield = 0;
                    } else {
                        RemainingDamage = 0;
                    }
                    monster->setShield(newShield);
                }
                int newHealth = monster->getHealthPoints() - RemainingDamage;
                monster->setHealthPoints(newHealth);
            }
        }
    }
}

//Rifle Class
RIFLE Rifle::Rifle() : Gun("Rifle", 30, 20, 4, 'R') {}

RIFLE Rifle::~Rifle(){
}

// Sure 90%
RIFLE void Rifle::useSpecial(Hero& hero, Object*** map) {
    setBullets(getBullets() - 3);
    int heroX = hero.getX();
    int heroY = hero.getY();
    int dx[] = {0, 0, -1};
    int dy[] = {-1, 1, 0};
    int damage = getDamageAmount();
    for (int i = 0; i < 3 ; i++) {
        for (int j = 1; j <= getRange() ; j++) {
            int newX = heroX + dx[i] * j;
            int newY = heroY + dy[i] * j;
            if (newX >= 0 && newX < 15 && newY >= 0 && newY < 15) {
                Object* obj = map[newX][newY];
                if (GhostMonster* monster = dynamic_cast<GhostMonster*>(obj)){
                    int newHealth = monster->getHealthPoints() - damage;
                    monster->setHealthPoints(newHealth);
                }else if (TankMonster* monster = dynamic_cast<TankMonster*>(obj)){
                    int RemainingDamage = damage;
                    if(monster->getShield() > 0){
                        int newShield = monster->getShield() - damage;
                        if (newShield < 0) {
                            RemainingDamage = -newShield;
                            newShield = 0;
                        } else {
                            RemainingDamage = 0;
                        }
                        monster->setShield(newShield);
                    }
                    int newHealth = monster->getHealthPoints() - RemainingDamage;
                    monster->setHealthPoints(newHealth);
                }
            }
        }
    }
}

//Hero Class
HERO Hero::Hero() : Character() { gun = nullptr; }

HERO Hero::Hero(char type, int x, int y, int healthPoints, Gun* gun) : Character(type, x, y, healthPoints), gun(gun) {}

HERO Gun* Hero::getGun() const{
    return gun;
}

HERO void Hero::setGun(Gun* gun){
    this -> gun = gun;
}

HERO Hero::~Hero(){
}

HERO void Hero::print(ostream& os) const{
    os << "X-Pos: " << getX() << " , " << "Y-Pos: " << getY() << "\n" <<
    "Current-HP: " << getHealthPoints() << "\n" <<
    "Main Gun: " << getGun()->getName() << "\n"
    << "Ammo: " << getGun()->getBullets() << " -- Range: " << getGun()->getRange() << " -- Damage: "<< getGun()->getDamageAmount() << endl;
}

ostream& operator<<(ostream& os, Hero& hero) {
    hero.print(os);
    return os;
}

Hero& operator+(Hero& hero, const Ammo& ammo) {
    int res = ammo.getBulletsNumber() + hero.getGun()->getBullets();
    hero.getGun()->setBullets(res);
    return hero;
}

Hero& operator+(Hero& hero, const Potion& potion) {
    hero.setHealthPoints(hero.getHealthPoints() + potion.getHealingValue());
    return hero;
}

Hero& operator-(Hero& hero, Monster& monster) {
    monster.setHealthPoints(monster.getHealthPoints() - 20);
    hero.setHealthPoints(hero.getHealthPoints() - 10);

    return hero;
}
// MedicHero
MEDICHERO MedicHero::MedicHero() : Hero() { healingAmount = 0; }

MEDICHERO MedicHero::MedicHero(char type, int x, int y, int healthPoints, Gun* weapon, int healingAmount) : Hero('H', x, y, healthPoints, weapon), healingAmount(healingAmount) {}

MEDICHERO int MedicHero::getHealingAmount() const{
    return healingAmount;
}

MEDICHERO void MedicHero::setHealingAmount(int healingAmount){
    this -> healingAmount = healingAmount;
}

MEDICHERO MedicHero::~MedicHero(){
}

MEDICHERO void MedicHero::useSpecial() {
    if (!getHasHealed()) {
        setHealthPoints(getHealthPoints() + getHealingAmount());
        setHasHealed(true);
        cout << "Special Ability Used" << endl;
    }else{
        cout << "Special Ability Already Used" <<endl;
    }
}

MEDICHERO bool MedicHero::getHasHealed() const{
    return hasHealed;
}

MEDICHERO void MedicHero::setHasHealed(bool hasHealed){
    this -> hasHealed = hasHealed;
}

MEDICHERO void MedicHero::print(ostream& os) const{
    Hero::print(os);
    os << "Special Ability: Self-Healing" << "\n" << "Self-Healing Amount: " << healingAmount << endl;
}

// Monster
MONSTER Monster::Monster() : Character() { name = "NoName"; }

MONSTER Monster::Monster(char type, int x, int y, int healthPoints, string name) : Character(type, x, y, healthPoints), name(name) {}

MONSTER string Monster::getName() const{
    return name;
}

MONSTER void Monster::setName(string name){
    this -> name = name;
}

MONSTER Monster::~Monster(){
}

// Object
OBJECT Object::Object(){
}

OBJECT Object::Object(char type) : type(type){
}

OBJECT char Object::getType() const{
    return type;
}

OBJECT void Object::setType(char type){
    this -> type = type;
}

OBJECT Object::~Object(){
}

ostream& operator<<(ostream& os, const Object& obj) {
    os << obj.type;
    return os;
}

// Potion
POTION Potion::Potion() : Item('P'), healingValue(0) {}

POTION Potion::Potion(int healingValue) : Item('P'), healingValue(healingValue) {}

POTION int Potion::getHealingValue() const{
    return healingValue;
}

POTION void Potion::setHealingValue(int healingValue){
    this -> healingValue = healingValue;
}

POTION Potion::~Potion(){
}

// TankMonster
TANKMONSTER TankMonster::TankMonster() : Monster() { shield = 0; }

TANKMONSTER TankMonster::TankMonster(char type, int x, int y, int healthPoints, string name, int shield) : Monster('T', x, y, healthPoints, name), shield(shield) {}

TANKMONSTER int TankMonster::getShield() const{
    return shield;
}

TANKMONSTER void TankMonster::setShield(int shield){
    this -> shield = shield;
}

TANKMONSTER TankMonster::~TankMonster(){
}

// Game
GAME Game::Game(){}

int Game::round = 0;

GAME Game::Game(int rows, int columns, Hero* hero) : rows(15), columns(15), hero(hero) {}

GAME Object*** Game::getGrid() const{
    return grid;
}

GAME void Game::setGrid(Object*** grid){
    this -> grid = grid;
}

GAME int Game::getRows() const{
    return rows;
}

GAME void Game::setRows(int rows){
    this -> rows = rows;
}

GAME int Game::getColumns() const{
    return columns;
}

GAME void Game::setColumns(int columns){
    this -> columns = columns;
}

GAME Hero* Game::getHero() const{
    return hero;
}

GAME void Game::setHero(Hero* hero){
    this -> hero = hero;
}

GAME int Game::getRound() const{
    return round;
}

GAME void Game::incrementRound(){
    round++;
}

// Sure 95%
GAME void Game::Move(Hero& hero, char direction) {
    int heroX = hero.getX();
    int heroY = hero.getY();
    int newX = heroX;
    int newY = heroY;

    switch (direction) {
        case 'w': newX--; break;
        case 's': newX++; break;
        case 'd': newY++; break;
        case 'a': newY--; break;
    }

    if (newX >= 0 && newX < 15 && newY >= 0 && newY < 15) {
        if (Ammo* ammo = dynamic_cast<Ammo*>(grid[newX][newY])) {
            hero + *ammo;
            delete grid[newX][newY];
            grid[heroX][heroY] = new Object('.');
            grid[newX][newY] = &hero;
            hero.setX(newX);
            hero.setY(newY);
        }
        else if (Potion* potion = dynamic_cast<Potion*>(grid[newX][newY])) {
            hero + *potion;
            delete grid[newX][newY];
            grid[heroX][heroY] = new Object('.');
            grid[newX][newY] = &hero;
            hero.setX(newX);
            hero.setY(newY);
        }
        else if (Monster* monster = dynamic_cast<Monster*>(grid[newX][newY])) {
            hero - *monster;
        }
        else if(Object* object = dynamic_cast<Object*>(grid[newX][newY])){
            if (object->getType() == '.') {
                grid[heroX][heroY] = new Object('.');
                grid[newX][newY] = &hero;
                hero.setX(newX);
                hero.setY(newY);
            }
        }
    }else{
        // Error Message (Moving Outside OF Bounds)
    }
}


GAME void Game::FireGun(char direction) {
    Hero* hero = getHero();
    Gun* gun = hero->getGun();
    int X = hero->getX();
    int Y = hero->getY();
    if(gun->getBullets() > 0){
        gun->setBullets(gun->getBullets() - 1); // Reduce ammo by 1
        int range = gun->getRange();
        int damage = gun->getDamageAmount();
        for(int i = 1; i <= range; i++){
            int newX = X, newY = Y;
            switch (direction) {
                case 'w': newX -= i; break;
                case 's': newX += i; break;
                case 'a': newY -= i; break;
                case 'd': newY += i; break;
            }
            if(newX >= 0 && newX < 15 && newY >= 0 && newY < 15){
                Object* obj = grid[newX][newY];
                if (GhostMonster* monster = dynamic_cast<GhostMonster*>(obj)){
                    int newHealth = monster->getHealthPoints() - damage;
                    monster->setHealthPoints(newHealth);
                    return;
                }else if (TankMonster* monster = dynamic_cast<TankMonster*>(obj)){
                    int RemainingDamage = damage;
                    if(monster->getShield() > 0){
                        int newShield = monster->getShield() - damage;
                        if (newShield < 0) {
                            RemainingDamage = -newShield;
                            newShield = 0;
                        } else {
                            RemainingDamage = 0;
                        }
                        monster->setShield(newShield);
                    }
                    int newHealth = monster->getHealthPoints() - RemainingDamage;
                    monster->setHealthPoints(newHealth);
                    return;
                }
            }
        }
    }else {
        //Error Message Not Enough Bullets
    }
}


GAME void Game::useGunSpecial() {
    Hero* hero = getHero();
    Gun* gun = hero->getGun();
    int X = hero->getX();
    int Y = hero->getY();

    if (gun->getType() == 'B' && ((X+Y) == 14 || Y == X)) {
        gun->useSpecial(*hero, getGrid());
    }else if (gun->getType() == 'P' && gun->getBullets() >= 4) {
        gun->useSpecial(*hero, getGrid());
    }else if (gun->getType() == 'R' && gun->getBullets() >= 3) {
        gun->useSpecial(*hero, getGrid());
    }else{
        //Error "Cannot use the special ability of the gun. Insufficient bullets or incorrect position."
    }
}


GAME int Game::checkGameOver() {

    if (hero->getHealthPoints() <= 0) {
        system("cls");
        cout << "Your Current Health is " << this -> getHero()->getHealthPoints() << "\n"
        << "Game over! The hero is dead. You lost." << endl;
        return 0;
    }

    bool allMonstersDead = true;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (grid[i][j]->getType() == 'G' || grid[i][j]->getType() == 'T') {
                Monster* monster = dynamic_cast<Monster*>(grid[i][j]);
                if (monster->getHealthPoints() > 0) {
                    allMonstersDead = false;
                    break;
                }
            }
        }
        if (!allMonstersDead)
            break;
    }
    if (allMonstersDead) {
        system("cls");
        cout << "Congratulations! All monsters are dead. You won!" << endl;
        return 1;
    } else
        return -1;
}

// 99% sure it's correct
GAME void Game::updateMap() {

    //Dead Monsters Updates
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (grid[i][j]->getType() == 'T' || grid[i][j]->getType() == 'G') {
                Monster* monster = dynamic_cast<Monster*>(grid[i][j]);
                if (monster->getHealthPoints() <= 0) {
                    delete grid[i][j];
                    grid[i][j] = new Object('.');
                }
            }
        }
    }

    //Ghost Monster visibility Update
    int RCheck = (round-1) / 3;
    if (RCheck %2 == 0) {
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                if (grid[i][j]->getType() == 'G') {
                    GhostMonster* ghostMonster = dynamic_cast<GhostMonster*>(grid[i][j]);
                    ghostMonster->setIsVisible(false);
                }
            }
        }
    } else {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j]->getType() == 'G') {
                    GhostMonster* ghostMonster = dynamic_cast<GhostMonster*>(grid[i][j]);
                    ghostMonster->setIsVisible(true);
                }
            }
        }
    }

    //20's Round Spawn update
    if (round % 20 == 0)
        respawnMonsters();

    //Ending Functions
    system("cls");
    cout<< *(this -> getHero()) << "Current Round: " << this-> getRound() << "\n\n"
    << "To Move Use The Type 'W / A / S / D' And To Fire Your Gun Type 'F' And The Direction You Want To Fire At For Example: 'FA'" << "\n"
    << "To Use Your Hero's Special Type 'HS' And To Use Your Guns Special Type 'GS'" << "\n\n";
    showMap();
}

// 100% sure it's correct
GAME void Game::respawnMonsters() {
    srand(time(NULL));
    spawnMonster('G');
    spawnMonster('T');
}

// 100% sure it's correct
GAME void Game::spawnMonster(char monsterType) {
    int randX, randY;

    do {
        randX = rand() % rows;
        randY = rand() % columns;
    } while (grid[randX][randY]->getType() != '.');

    switch (monsterType) {
        case 'G':
            grid[randX][randY] = new GhostMonster('G', randX, randY, 100, "New Ghost", true);
            break;
        case 'T':
            grid[randX][randY] = new TankMonster('T', randX, randY, 100, "New Tank", 50);
            break;
    }
}

// 100% sure it's correct
GAME void Game::GenerateMap() {
    //grid Creation
    grid = new Object**[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new Object*[columns];
        for (int j = 0; j < columns; j++) {
            grid[i][j] = new Object('.');
        }
    }

    //Seed the random generator For Random Positions Each Time
    srand(time(NULL));

    //HealthPotions
    for (int i = 0; i < 5; i++) {
        int x = rand() % 15;
        int y = rand() % 15;
        while(grid[x][y]->getType() != '.') {
            x = rand() % 15;
            y = rand() % 15;
        }
        grid[x][y] = new Potion(rand() % 41 + 10);
    }

    //Ammo
    for (int i = 0; i < 10; i++) {
        int x = rand() % 15;
        int y = rand() % 15;
        while(grid[x][y]->getType() != '.') {
            x = rand() % 15;
            y = rand() % 15;
        }
        grid[x][y] = new Ammo(rand() % 16 + 5); // Number of bullets between 5 and 20
    }

    //Monsters
    for (int i = 0; i < 10; i++) {
        int x = rand() % 15;
        int y = rand() % 15;
        while(grid[x][y]->getType() != '.') {
            x = rand() % 15;
            y = rand() % 15;
        }
        if(i<5){
            grid[x][y] = new GhostMonster('G', x, y, (rand() % 10 + 6) * 10, "Ghost", true);
        }else{
            grid[x][y] = new TankMonster('T', x, y, (rand() % 10 + 6) * 10, "Tank", true);
        }
    }
}

// 100% sure it's correct
GAME void Game::showMap() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if(grid[i][j]->getType() == 'G'){
                GhostMonster* monster = dynamic_cast<GhostMonster*>(grid[i][j]);
                if (monster->getIsVisible() == false)
                    cout << ". ";
                else
                    cout << grid[i][j]->getType() << " ";
            }else
                cout << grid[i][j]->getType() << " ";
        }
        cout << endl;
    }
}

// Needs Implementations
GAME void Game::startGame() {
    this -> incrementRound();
    GenerateMap();
    grid[0][0] = this->getHero();
    cout << *hero << endl;
    showMap();
}

// 99% sure it's correct
GAME Game::~Game() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0 ; j < columns ; j++){
            delete[] grid[i][j];
        }
        delete[] grid[i];
    }
    delete grid;
}

// Needs Implementations
int main(){
    string V1,V2,V3;
    int heroChoice, gunChoice, gunChoice2;
    Hero* H;
    Gun* chosenGun;
    Gun* chosenGun2;

    //Choose hero
    do {
        cout << "Please enter 1 to choose Demolition or 2 to choose Medic: ";
        cin >> V1;
        stringstream(V1) >> heroChoice;
    } while (heroChoice != 1 && heroChoice != 2);

    //Choose gun 1
    do {
        cout <<"Choose First Weapon: " << endl <<"Please enter 1 for Pistol, 2 for Bazooka or 3 for Rifle: ";
        cin >> V2;
        stringstream(V2) >> gunChoice;
    } while (gunChoice != 1 && gunChoice != 2 && gunChoice != 3);

    //Choose gun 2
    if(heroChoice == 1){
        do {
            cout <<"Choose Second Weapon: "<< endl <<"Please enter 1 for Pistol, 2 for Bazooka or 3 for Rifle: ";
            cin >> V3;
            stringstream(V3) >> gunChoice2;
        } while (gunChoice2 != 1 && gunChoice2 != 2 && gunChoice2 != 3);
        if (gunChoice2 == 1) {
            chosenGun2 = new Pistol();
        } else if (gunChoice2 == 2) {
            chosenGun2 = new Bazooka();
        } else {
            chosenGun2 = new Rifle();
        }
    }

    if (gunChoice == 1) {
        chosenGun = new Pistol();
    } else if (gunChoice == 2) {
        chosenGun = new Bazooka();
    } else {
        chosenGun = new Rifle();
    }

    if (heroChoice == 1) {
        H = new DemolitionHero('H', 0, 0, 100, chosenGun, chosenGun2);
    } else {
        H = new MedicHero('H', 0, 0, 100, chosenGun, 50);
    }

    Game* game = new Game(15,15,H);
    system("cls");
    game->startGame();

    while(game->checkGameOver()==-1){
        game -> updateMap();
        string input;
        cin >> input;

        bool validCommand = false;

        if (input == "w" || input == "W") {
            game->Move(*H,'w');
            validCommand = true;
        } else if (input == "a" || input == "A") {
            game->Move(*H,'a');
            validCommand = true;
        } else if (input == "s" || input == "S") {
            game->Move(*H,'s');
            validCommand = true;
        } else if (input == "d" || input == "D") {
            game->Move(*H,'d');
            validCommand = true;
        } else if (input == "FA" || input == "fA" || input == "Fa" || input == "fa") {
            game->FireGun('a');
            validCommand = true;
        } else if (input == "FS" || input == "fS" || input == "Fs" || input == "fs") {
            game->FireGun('s');
            validCommand = true;
        } else if (input == "FD" || input == "fD" || input == "Fd" || input == "fd") {
            game->FireGun('d');
            validCommand = true;
        } else if (input == "FW" || input == "fW" || input == "Fw" || input == "fw") {
            game->FireGun('w');
            validCommand = true;
        } else if (input == "GS" || input == "Gs" || input == "gS" || input == "gs") {
            game->useGunSpecial();
            validCommand = true;
        } else if (input == "HS" || input == "Hs" || input == "hS" || input == "hs") {
            game->getHero()->useSpecial();
            validCommand = true;
        }

        if (validCommand) {
            game->incrementRound();
        }
    }

    return 0;
}
