#include <iostream>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>

int main() {

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    std::cout << "Hello, World!" << std::endl;
    GLFWwindow* window =  glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);
    if (window == nullptr) 
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;

    glm::mat4 testMat(1.0f);
    glm::vec4 testVec(1.0f);
    auto testResult = testMat * testVec;

    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();
    }
    

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}