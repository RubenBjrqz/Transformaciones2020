// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

float angulo = 0.0f;

void actualizar()
{
	angulo += 0.01;
	if (angulo >= 360.0f)
	{
		angulo = 0.0f;
	}
}

void dibujarTriangulo()
{
	glPushMatrix();

	//glTranslatef(0.4f, -0.5f, 0.0f);
	glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	//glScalef(0.5f, 2.0f, 1.0f); 

	glBegin(GL_TRIANGLES);

	glColor3f(0.56f, 0.56f, 0.56f);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
}

void dibujar()
{
	dibujarTriangulo();
}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Colors", NULL, NULL);

	//Si no se pudo crear la ventana terminamos la ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OPENGL: " << versionGL;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.1,0.1,0.1,1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
