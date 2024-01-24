#include <iostream>

class Cassa;

class Cassa {
public:
	Cassa():balance_(0){}

	int CurrentMoney() { // показать баланс
		return balance_;
	}
	void CashIn(int money) {
		balance_ += money;
	}
	void CashOut(int money) {		
		if (balance_ < money) {
			std::cerr << "Средств недостаточно!\n";
			return;
		}	
		balance_ -= money;		
	}
	int Exchange(int ticket, int money) {
		if (money < ticket) {
			std::cerr << "Средств недостаточно для попкупки!\n";
			return money;
		}
		if (balance_ < money - ticket) {
			std::cerr << "Средств недостаточно для сдачи!\n";
			return money;
		}
		balance_ += ticket;
		return money - ticket;
	}
private:
	int balance_;	
};



int main() {
	setlocale(LC_ALL, "ru");

	Cassa var1;
	Cassa var2;
	Cassa var3;
	int cashin;
	int cashout;
	int ticket;
	int money;
	std::cout << "Сколько денег внести -> ";
	std::cin >> cashin;
	var1.CashIn(1000);
	
	std::cout << "Первая касса: " << var1.CurrentMoney() << '\n';
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';

	std::cout << "Сколько денег взять из кассы -> ";
	std::cin >> cashout;

	var1.CashOut(cashout);
	var2.CashOut(cashout);

	std::cout << "Первая касса: " << var1.CurrentMoney() << '\n';
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';


	std::cout << "Сколько стоит товар -> ";
	std::cin >> ticket;
	std::cout << "Сколько дают денег -> ";
	std::cin >> money;

	var1.Exchange(ticket, money);
	int change = 0;
	
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';
	change = var2.Exchange(100, 20);
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';
	std::cout << "change: " << change << '\n';

	change = var2.Exchange(100, 120);
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';
	std::cout << "change: " << change << '\n';
	
	change = var2.Exchange(100, 100);
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';
	std::cout << "change: " << change << '\n';

	change = var2.Exchange(10, 20);
	std::cout << "Первая касса: " << var2.CurrentMoney() << '\n';
	std::cout << "change: " << change << '\n';
	return 0;
}

