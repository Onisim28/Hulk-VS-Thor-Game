#pragma once
using namespace std;

class Warrior {
private:
	int life, power, defense;
public:
	string hero;
	Warrior(string hero, int life, int power, int defense) {
		this->life = life;;
		this->power = power;
		this->defense = defense;
		this->hero = hero;
	}
	int getlife() {
		return life;
	}

	int getpower() {
		return power;
	}
	int getdefense() {
		return defense;
	}
	int lifeobj1(Warrior&, Warrior&);
	int lifeobj2(Warrior&, Warrior&);

	Warrior() {
		life = 0;
		power = 0;
		defense = 0;
	}
	~Warrior()
	{
		cout << "warrior constructor was destroyed!" << endl;
	}
};

int Warrior::lifeobj1(Warrior& obj1life, Warrior& obj2life) {
	int t;
	t = obj1life.defense - obj2life.power - rand() % 40;
	// When we meet positive t, t should be transformed to negative //
	t = (t > 0) ? -t : t;
	obj1life.life = obj1life.life + t;
	return obj1life.life;
}
int Warrior::lifeobj2(Warrior& obj1life, Warrior& obj2life) {
	int t = obj2life.defense - obj1life.power - rand() % 40;
	// When we meet positive t, t should be transformed to negative //
	t = (t > 0) ? -t : t;
	obj2life.life = obj2life.life + t;
	return obj2life.life;
}

class Battle {
public:

	static void BattleStarts(Warrior&, Warrior&);

};
//Hulk este obj1, thor e obj2//
void Battle::BattleStarts(Warrior& obj1, Warrior& obj2) {
	int damageobj1 = obj1.getlife(), damageobj2 = obj2.getlife(), aux1 = 0, aux2 = 0;

	while (true) {
		obj2.lifeobj2(obj1, obj2);
		aux2 = obj2.getlife();
		damageobj2 = damageobj2 - aux2;
		// Damage dealed should not be negative //
		damageobj2 = (damageobj2 < 0) ? -damageobj2 : damageobj2;

		printf("%s Attacks! %s deals %d damage\n %s's life was decreased to %d\n", obj1.hero.c_str(), obj1.hero.c_str(), damageobj2, obj2.hero.c_str(), obj2.getlife());
		damageobj2 = aux2;
		if (obj2.getlife() <= 0) {
			printf("\n\t%s won the battle!\n\n", obj1.hero.c_str());
			break;
		}
		obj1.lifeobj1(obj1, obj2);
		aux1 = obj1.getlife();
		damageobj1 = damageobj1 - aux1;
		// Damage dealed should not be negative //
		damageobj1 = (damageobj1 < 0) ? -damageobj1 : damageobj1;
		printf("%s Attacks! %s deals %d damage\n %s's life was decreased to %d\n", obj2.hero.c_str(),
			obj2.hero.c_str(), damageobj1, obj1.hero.c_str(), obj1.getlife());
		damageobj1 = aux1;
		if (obj1.getlife() <= 0) {
			printf("\n\t%s won the battle!\n\n", obj2.hero.c_str());
			break;
		}
	}

}