#include <iostream>
#include <string>

using String = std::string;


// Exemple de variable mutable : modifiable m�me dans une m�thode const
// Exemple de Member Initialiser List, pour �viter de cr�er deux fois une variable, il faut utiliser une MIL
// Exemple op�rateur ternaire ("?")
//
// Heap : keyword "new" + forc� � "delete" manuellement, pour les gros objets, o� ceux dont on veut contr�ler la dur�e de vie
// Stack : objets qui expirent quand on sort de la scope o� ils ont �t� d�clar�s, on devrait utiliser �a d�s qu'on peut, �viter le heap le plus possible


class Example
{
private:
	String name;
public:
	Example()
	{
		name = "No Name";
		std::cout << "Constructed Example with no specified parameters !" << std::endl;
	}

	Example(String n)
	{
		// Ternary operator
		name = n == "Gab" ? "Master" : n; // value = (est-ce que v = "Gab" ?) Si oui, value = master, sinon, value = v

		std::cout << "Constructed Example with name " << name << " !" << std::endl;
	}
};


struct Entity
{

private:
	const String m_Name; // Le nom change pas, donc const
	int m_Age;
	mutable int m_DebugCount = 0; // Pour pouvoir garder la constance de GetName(), on met cette variable en mutable.
	Example ex;

public:
	Entity()
		: m_Name("No Name"), m_Age(NULL), m_DebugCount(0), ex(Example())
	{
		// ex = Example(); Mauvaise id�e, cette ligne cr�e une instance de Example (dans la private) pour ne pas l'utiliser et en cr�er une nouvelle
		// Il faut utiliser une MIL pour initialiser directement la variable, sans passer par une nouvelle instance (plus de place en m�moire)
	}

	Entity(const String& name)
		: m_Name(name), m_DebugCount(0), ex(Example(name)) // Pareil ici, utilisation d'une MIL pour �viter cr�ation d'un autre Exemple()
	{
		// Il est aussi utile de s�parer les m�thodes et l'initialisation de variables barbantes, m�thodes ici et variables en MIL
	}

	Entity(const char* name)
		: m_Name(name), m_DebugCount(0), ex(Example(name)) // Pareil ici, utilisation d'une MIL pour �viter cr�ation d'un autre Exemple()
	{
		// Il est aussi utile de s�parer les m�thodes et l'initialisation de variables barbantes, m�thodes ici et variables en MIL
	}

	Entity(int a)
		: m_Name("No Name"), m_Age(a) { }

	const String& GetName() const { m_DebugCount++; return m_Name; }

	int GetDebugCount()
	{
		return m_DebugCount;
	}
};

void PrintEntity(const Entity e) 
{
	// Printing
}


int main()
{
	
	puts("Section pointeurs, new");
	puts("");

	{
		Entity e0; // Cr�ation d'un (Exemple) sans param�tres
		Entity e1("Gab"); // Cr�ation d'un (Exemple) avec param�tres


		// Exemple "new" et allocation sur la heap
		// Le mot-cl� "new" return un pointeur vers une adresse qui a �t� allou�e, par exemple :

		int* heap = new int; // � noter : "new" appelle aussi le constructeur :

		Entity* e = new Entity; // Fait exactement la m�me chose que :
		Entity* e2 = (Entity*)malloc(sizeof(Entity)); // Sauf que "new" appelle le constructeur


		*heap = 0; // D�r�f�rencement du pointeur

		// 4 bytes on �t� lib�r�s pour permettre l'allocation, et ensuite, ils ont �t� assign�s � une variable
		// Pour lib�rer la m�moire, on ex�cute :
		delete heap; // "delete" appelle aussi le destructeur (ici ~int)
		delete e;
		free(e2); // Si malloc() est utilis� (ce qui ne devrait pas arriver), il faut lib�rer la m�moire avec free()
	}
	// Explication malloc, pointeur, new

	puts("");
	puts("Section conversion implicite");
	puts("");

	{

		Entity a = "Gab.";
		Entity b = (16);

		PrintEntity(22); // Cette ligne marche car une conversion implicite est possible entre le type Entity et int : il y a un constructeur int
	}
	std::cin.get();



}
// Remarque : si "new type[]" est appel�, il faut appeler "delete[]"


