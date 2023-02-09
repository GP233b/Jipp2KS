#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

namespace Zadanie3Egzamin {

	class Person
	{
	private:
		string name;
		int age;
	public:
		Person(string name, int age)
		{
			this->name = name;
			this->age = age;
		}
		string getName() {
			return name;
		}
		int getAge() {
			return age;
		}
		friend ostream& operator<<(ostream& lhs, const Person& obj) {
			return	lhs << obj.name << " " << obj.age;
		}
	};

}
using namespace Zadanie3Egzamin;

int main()
{
	vector<Person> personList = { Person("Jan",23),Person("Tomek",12) ,Person("Krzyœ",50) };

	//Dodaj na koniec listy Patrycje, wiek 25
	personList.push_back(Person("Patrycja", 25));

	//Uzupe³nij klasê Person tak by poprawny by³ fragment kodu
	cout << personList[0] << endl;

	//Zarezerwuj w vectorze wiêcej pamiêci, tak by pomiescic 50 osob, czujesz, 
	//¿e czeka Ciê du¿o obliczeñ
	personList.reserve(50);

	//Wstaw poni¿sze osoby do vectora personList by by³y po Janie
	vector<Person> newPerson = { Person("Adam", 33), Person("Zosia",66) };
	//personList.insert(personList.begin() + 1, newPerson.begin() , newPerson.end());

	personList.insert(personList.begin() +1, newPerson[0]);
	personList.insert(personList.begin() + 2, newPerson[1]);

	//Wyœwietl elementy korzystaj¹c z iteratora

	vector<Person>::iterator IT;
	for (IT = personList.begin(); IT != personList.end(); IT++) {
		cout << *IT<<endl;
	}
	//usun z listy Krzysia
	for (IT = personList.begin(); IT != personList.end(); IT++) {
		if (IT->getName() == "Krzyœ") {
			IT = personList.erase(IT);
		}
	}
	
	//posortuj elementy w vectorze po wieku, tak by najpierw byli najmlodsi, potem najstarsi
	sort(personList.begin(), personList.end(), [](Person& A, Person& B) {return A.getAge() < B.getAge(); });

	//Jesteœ dobrym programist¹ dbaj¹cym o pamiêæ, zmniejsz odpowiednio pojemnoœæ twojego vectora
	personList.shrink_to_fit();


	//Co wiêcej jako dobry programista dbasz o porz¹dek w kodzie i 
	//ca³y kod odpowiedzialny za klasê Person umiescisz w przestrzeni nazw Zadanie3Egzamin

	//Na koniec pracy wyczyœæ ca³y vector personList by by³ pusty
	personList.clear();


}