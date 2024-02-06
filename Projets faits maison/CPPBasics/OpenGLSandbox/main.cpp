#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInputs(GLFWwindow* window) // Basique
{
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		glClearColor(1.0f, 0.6f, 0.0f, 1.0f); // Cr�er l'�tat � appliquer au prochain frame buffer, puis l'appliquer ligne suivante
		glClear(GL_COLOR_BUFFER_BIT);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

// Code source du shader vertex
const char* vertexShaderSource = "#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}";

// Code source du shader fragment
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.2f, 0.5f, 1.0f);\n"
"}";

int main()
{
	// D�finition des variables
	int vertexShaderCompileSuccess;
	int fragmentShaderCompileSuccess;

	char vertexShaderInfoLog[512];
	char fragmentShaderInfoLog[512];
	float vertices[] = { // Triangle 1
		 -1.0f,  0.0f, 0.0f,
		 -0.5f,  1.0f, 0.0f,
		  0.0f,  0.0f, 0.0f,
	};

	float vertices2[] = {
		// Triangle 2
		0.0f,  0.0f, 0.0f,
		0.5f, -1.0f, 0.0f,
		1.0f,  0.0f, 0.0f
	};


	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	// Initialisation d'OpenGL et GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Dire � GLFW que OpenGL est en version 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Le profil utilis� est "Core"

	GLFWwindow* window = glfwCreateWindow(800, 600, "Title", NULL, NULL);

	// Si �a a pas march�, return une erreur
	if (window == NULL)
	{
		std::cout << "La fenetre n'a pas pu etre creee" << std::endl;
		glfwTerminate();
		return -1;
	} 

	glfwMakeContextCurrent(window); // Dire que c'est cette fen�tre l� qu'on veut afficher

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD n'a pas pu etre initialise" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Quand on veut resize, appeler cette fonction
	
	// Setup du VAO (qui sauvegarde les param�tres du VBO)
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Setup du VBO (qui charge les vertices avant de les envoyer au shader)
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Appliquer le buffer � GL_ARRAY_BUFFER

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copier l'�tat du buffer qu'on a bind vers le vrai buffer
	/*
	Pour le dernier param�tre, il y a 3 possibilit�s :
	GL_STATIC_DRAW, quand on d�finit une fois mais qu'on utilise beaucoup
	GL_STREAM_DRAW, quand on d�finit une fois et qu'on utilise un peu
	GL_DYNAMIC_DRAW, quand on d�finit et qu'on utilise beaucoup
	(Ce param�tre change dans quelle partie du GPU le shader place les donn�es : dans la partie � acc�s rapide ou lent)
	*/

	// Setup de l'EBO (qui combine les vertices en �l�ments)
	unsigned int EBO;
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Setup du shader Vertex Buffer (qui tra�te les vertices)
	/* Le shader compile le code pendant l'ex�cution
	Cr�ation de l'objet du buffer */

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // Assigner vertexShaderSource au code du shader cr�� ligne pr�c�dente
	glCompileShader(vertexShader); // Compiler le shader

	// V�rifier si le shader compile correctement
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexShaderCompileSuccess);
	if (!vertexShaderCompileSuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, vertexShaderInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vertexShaderInfoLog << std::endl;
	}

	// Setup du shader Fragment Buffer (qui ajoute les couleurs)
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentShaderCompileSuccess);
	if (!fragmentShaderCompileSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentShaderInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragmentShaderInfoLog << std::endl;
	}

	// Cr�ation et utilisation du shaderProgram qui lie les deux shaders cr��s
	unsigned int shaderProgram;
	shaderProgram = glad_glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	// Interpr�tation des vertices pr�sentes en m�moire et activation du VAO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	/* Le d�but du pointeur vers les vertices se situe � 0, on dessine en 3 dimensions (deuxi�me argument = vec3),
	 * les coordonn�es sont en float (GL_FLOAT), elles ne sont pas normalis�es (on les a mises de 0.0f � 1.0f)
	 * la taille totale est de 3 fois la taille d'un float (on ne met pas une constante pour la compatibilit�
	 * entre les OS), et on passe un pointeur nul pour d�finir l'offset du d�but des donn�es par rapport au d�but sp�cifi�
	*/
	glEnableVertexAttribArray(0);


	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// D�but de la boucle de rendu (1 it�ration = 1 frame)
	while (!glfwWindowShouldClose(window))
	{
		// Input
		processInputs(window);

		glUseProgram(shaderProgram);

		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Rendu (toujours � la fin)
		glfwSwapBuffers(window); // Swap le buffer front et back � chaque fois
		glfwPollEvents();
	}

	// Ne pas oublier de nettoyer les shaders quand on en n'a plus besoin
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glfwTerminate(); // Nettoyer la m�moire utilis�e quand on ferme la fen�tre
	return 0;
}
