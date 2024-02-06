#include <iostream>
#include <string>

using String = std::string;


// Exemple de variable mutable : modifiable même dans une méthode const
// Exemple de Member Initialiser List, pour éviter de créer deux fois une variable, il faut utiliser une MIL
// Exemple opérateur ternaire ("?")
//
// Heap : keyword "new" + forcé à "delete" manuellement, pour les gros objets, où ceux dont on veut contrôler la durée de vie
// Stack : objets qui expirent quand on sort de la scope où ils ont été déclarés, on devrait utiliser ça dès qu'on peut, éviter le heap le plus possible


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
		// ex = Example(); Mauvaise idée, cette ligne crée une instance de Example (dans la private) pour ne pas l'utiliser et en créer une nouvelle
		// Il faut utiliser une MIL pour initialiser directement la variable, sans passer par une nouvelle instance (plus de place en mémoire)
	}

	Entity(const String& name)
		: m_Name(name), m_DebugCount(0), ex(Example(name)) // Pareil ici, utilisation d'une MIL pour éviter création d'un autre Exemple()
	{
		// Il est aussi utile de séparer les méthodes et l'initialisation de variables barbantes, méthodes ici et variables en MIL
	}

	Entity(const char* name)
		: m_Name(name), m_DebugCount(0), ex(Example(name)) // Pareil ici, utilisation d'une MIL pour éviter création d'un autre Exemple()
	{
		// Il est aussi utile de séparer les méthodes et l'initialisation de variables barbantes, méthodes ici et variables en MIL
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
		Entity e0; // Création d'un (Exemple) sans paramètres
		Entity e1("Gab"); // Création d'un (Exemple) avec paramètres


		// Exemple "new" et allocation sur la heap
		// Le mot-clé "new" return un pointeur vers une adresse qui a été allouée, par exemple :

		int* heap = new int; // À noter : "new" appelle aussi le constructeur :

		Entity* e = new Entity; // Fait exactement la même chose que :
		Entity* e2 = (Entity*)malloc(sizeof(Entity)); // Sauf que "new" appelle le constructeur


		*heap = 0; // Déréférencement du pointeur

		// 4 bytes on été libérés pour permettre l'allocation, et ensuite, ils ont été assignés à une variable
		// Pour libérer la mémoire, on exécute :
		delete heap; // "delete" appelle aussi le destructeur (ici ~int)
		delete e;
		free(e2); // Si malloc() est utilisé (ce qui ne devrait pas arriver), il faut libérer la mémoire avec free()
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
// Remarque : si "new type[]" est appelé, il faut appeler "delete[]"


