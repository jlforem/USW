#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class PokemonCard {
public:
    string name;
    int hp;
    vector<string> attacks;
    int victories;
    int level;

    PokemonCard(string name, int hp, vector<string> attacks) : name(name), hp(hp), attacks(attacks), victories(0), level(1) {}

    void levelUp() {
        level++;
        hp = static_cast<int>(hp * 1.1);
    }

    void attack(PokemonCard& opponent) {
        int damage = rand() % 10 + 1;
        opponent.hp -= damage;
        cout << name << " attacks " << opponent.name << " for " << damage << " damage!\n";
    }

    bool isAlive() {
        return hp > 0;
    }
};

class Player {
public:
    string name;
    vector<PokemonCard> cards;

    Player(string name) : name(name) {}

    void addCard(PokemonCard card) {
        cards.push_back(card);
    }

    PokemonCard getRandomCard() {
        return cards[rand() % cards.size()];
    }
};

class Battle {
public:
    Player player1;
    Player player2;
    ofstream matchHistory;
    FILE matchHistoryFile;

    Battle(Player player1, Player player2) : player1(player1), player2(player2) {}

    void startBattle() {
        PokemonCard card1 = player1.getRandomCard();
        PokemonCard card2 = player2.getRandomCard();
        cout << "Battle between " << player1.name << "'s " << card1.name << " and " << player2.name << "'s " << card2.name << "!\n";
        while (card1.isAlive() && card2.isAlive()) {
            card1.attack(card2);
            if (!card2.isAlive()) {
                card1.victories++;
                if (card1.victories >= 5) {
                    card1.levelUp();
                    card1.victories = 0;
                }
            }
            if (card1.isAlive()) {
                card2.attack(card1);
                if (!card1.isAlive()) {
                    card2.victories++;
                    if (card2.victories >= 5) {
                        card2.levelUp();
                        card2.victories = 0;
                    }
                }
            }
        }
        if (card1.isAlive()) {
            cout << player1.name << " wins with " << card1.name << "!\n";
            matchHistory << player1.name << " vs " << player2.name << ": " << player1.name << " wins with " << card1.name << "!\n";
        }
        else {
            cout << player2.name << " wins with " << card2.name << "!\n";
            matchHistory << player1.name << " vs " << player2.name << ": " << player2.name << " wins with " << card2.name << "!\n";
        }
    }
};

int main() {
    srand(time(NULL));
    Player player1("Ash");
    player1.addCard(PokemonCard("Pikachu", 50, { "Thunderbolt", "Quick Attack" }));
    player1.addCard(PokemonCard("Charmander", 40, { "Ember", "Scratch" }));

    Player player2("Misty");
    player2.addCard(PokemonCard("Bulbasaur", 60, { "Vine Whip", "Razor Leaf" }));
    player2.addCard(PokemonCard("Squirtle", 50, { "Bubble", "Water Gun" }));
    
    Battle ashvMisty(player1, player2);
}