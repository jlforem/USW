#include <iostream>
#include <string>
using namespace std;

class Pokemon {
public:
    string name;
    int health;
    int attack;
    int defense;

    Pokemon(string n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {}

    virtual void attack(Pokemon& target) {
        target.health -= this->attack;
        cout << this->name << " attacked " << target.name << " for " << this->attack << " damage." << endl;
    }
};

class PokemonAttacks : public Pokemon {
public:
    PokemonAttacks(string n, int h, int a, int d, string at) : Pokemon(n, h, a, d) {
        attackType = at;
    }

    string attackType;

    void attack(Pokemon& target) override {
        if (attackType == "fire") {
            if (target.defense < 50) {
                target.health -= this->attack * 2;
                cout << this->name << " attacked " << target.name << " with fire for " << this->attack * 2 << " damage." << endl;
            }
            else {
                target.health -= this->attack;
                cout << this->name << " attacked " << target.name << " with fire for " << this->attack << " damage." << endl;
            }
        }
        else if (attackType == "water") {
            if (target.defense < 50) {
                target.health -= this->attack * 2;
                cout << this->name << " attacked " << target.name << " with water for " << this->attack * 2 << " damage." << endl;
            }
            else {
                target.health -= this->attack;
                cout << this->name << " attacked " << target.name << " with water for " << this->attack << " damage." << endl;
            }
        }
    }
};

class Trainer {
public:
    string name;
    PokemonAttacks pokemon;

    Trainer(string n, PokemonAttacks p) : name(n), pokemon(p) {}

    void train() {
        pokemon.attack += 10;
        pokemon.defense += 5;
        cout << this->name << " trained their pokemon, increasing its attack by 10 and defense by 5." << endl;
    }
};

class Battle {
public:
    Trainer trainer1;
    Trainer trainer2;

    Battle(Trainer t1, Trainer t2) : trainer1(t1), trainer2(t2) {}

    void fight() {
        while (trainer.pokemon.health > 0 && trainer2.pokemon.health > 0) {
            trainer1.pokemon.attack(trainer2.pokemon);
            if (trainer2.pokemon.health <= 0) {
                cout << trainer1.name << " won the battle!" << endl;
                return;
            }
            trainer2.pokemon.attack(trainer1.pokemon);
            if (trainer1.pokemon.health <= 0) {
                cout << trainer2.name << " won the battle!" << endl;
                return;
            }
        }
    }
};

int main()
{
    PokemonAttacks pikachu("Pikachu", 100, 50, 30, "fire");
    Trainer ash("Ash", pikachu);
    PokemonAttacks charmander("Charmander", 80, 40, 40, "water");
    Trainer misty("Misty", charmander);
    Battle battle(ash, misty);
    battle.fight();

    return 0;
}