#include "GLFW/glfw3.h"
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "vec2.h"

using namespace std;

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Take me by the hand.", NULL, NULL);
	if (!window){
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	double lastTime = glfwGetTime();
	int frames = 0;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)){
		frames++;
		if (lastTime + 1 <= glfwGetTime()) {
			cout << frames << endl;
			//cout << chrono::high_resolution_clock::now() << endl;
			lastTime = glfwGetTime();
			frames = 0;
		}
		for (int i = 0; i < 2000; i++) {
			vec2f v(i, i*2);
			cout << v.toString() << endl;
		}
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}