#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>




class TriangleRenderer {

public:
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;
	GLFWwindow *window;

	TriangleRenderer() {

	}

	~TriangleRenderer() {
		cleanup();
	}

	void run() {
		initWindow();
		initVulkan();
		mainLoop();
	}

private:
	void initWindow() {
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH,HEIGHT,"Vulkan",nullptr,nullptr);
	}
	void initVulkan() {

	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}

	void cleanup() {

	}

};


int main(int argc, char** argv)
{
	TriangleRenderer app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}