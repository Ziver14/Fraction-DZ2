#include<iostream>


template<typename T>
class Fraction {
public:
	//Так как конструктор поумолчанию заполняет все поля нулями, запрещаем его вызов автомотически
	//потому что знаменатель не может быть равен 0;
	explicit Fraction() {};

	Fraction(T  num, T  den) {
		if (den == 0) {
			throw std::exception("ERROR");
		}
		numerator = num;
		denominator = den;

	}
	//Методы доступа и изменения полей класса
	void SetNumerator(T num) {
		numerator = num;
	}

	void SetDenominator (T den) {
		denominator = den;
	}

	T GetNumerator() const {
		return numerator;
	}

	T GetDenominator() const  {
		return denominator;
	}
	//Методы определения целой части, дробной части, обратной дроби 
	int FullPart(){
		int full;
		return full = numerator / denominator;;
	}
	 	
	void FractionalPart() {
		int num_ = numerator % denominator;
		std::cout << num_ << '/' << denominator;
	}
		
	void Inverce() {
		std::swap(numerator, denominator);
		std::cout << numerator << '/' << denominator;

	}
	//Методы предикаты определения свойств дроби
	bool CorrectFraction() {
		if (denominator > numerator)
			return true;
		else
			return false;
	}

	bool InCorrectFraction() {
		if (numerator > denominator)
			return true;
		else
			return false;
	}

	bool IntegerFraction() {
		if (numerator == denominator) {
			return true;
		}
		else
			return false;

		
	}
	//Операторы математики
	Fraction operator+(const Fraction& other) {
		T num = numerator * other.denominator+denominator*other.numerator;
		T den = denominator * other.denominator;
		return Fraction(num, den);
	}

	Fraction operator- (const Fraction& other) {
		T num = numerator * other.denominator - other.numerator * denominator;
		T den = denominator * other.denominator;
		return Fraction(num, den);
	}

	Fraction operator / (const Fraction & other) {
		T num = numerator * other.denominator;
		T den = denominator * other.numerator;
		return Fraction(num, den);
	}

	Fraction operator*(const Fraction& other) {
		T num = numerator * other.numerator;
		T den = denominator * other.denominator;
		return Fraction(num, den);
	}

	Fraction operator +() {
		return Fraction(numerator, denominator);
	}

	Fraction operator -() {
		return Fraction(-numerator, denominator);
	}

	Fraction& operator ++() {
		numerator += denominator;
		return*this;
	}

	Fraction& operator--() {
		numerator = numerator - denominator;
		return* this;
	}

	//Операторы работы с потоками
	friend std::ostream& operator<<(std::ostream& os, const Fraction<T>& fraction) {
		os << fraction.numerator << '/' << fraction.denominator;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Fraction<T>& fraction) {
		is >> fraction.numerator  >> fraction.denominator;
		return is;
		
	}
private:
	T numerator;
	T denominator;
};



int main() {
	setlocale(LC_ALL, "ru");

	Fraction<int> fra1;
	Fraction<int> fra2;
	std::cout << "Введите дробь 1 -> ";
	std::cin >> fra1;
	std::cout << fra1;
	std::cout << std::endl;
	std::cout << "Введите дробь 2 -> ";
	std::cin >> fra2;
	std::cout << fra2;
	std::cout << std::endl;
	Fraction<int> Sum = fra1 + fra2;
	std::cout <<"Сумма = " << Sum;
	Fraction<int> Dif = fra1 - fra2;
	std::cout << std::endl;
	std::cout << "Разность = " << Dif;
	Fraction<int> Def = fra1 / fra2;
	std::cout << std::endl;
	std::cout << "Частное = " << Def;
	Fraction<int> Mult = fra1 * fra2;
	std::cout << std::endl;
	std::cout << "Произведение = " << Mult;
	std::cout << std::endl;
	++fra1;
	std::cout << fra1;
	std::cout << std::endl;
	--fra1;
	std::cout << fra1;
	std::cout << std::endl;
	

	return 0;
}