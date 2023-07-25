#include <GLFW/glfw3.h>
#include <cstdlib>
#include <windows.h>

int main(void)
{

    GLFWwindow* window;

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_RESIZABLE, false);

    window = glfwCreateWindow(800, 800, "joe", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    float x = 0;
    float y = 0;

    bool right = true;

    float red = rand() / (float) RAND_MAX;
    float green = rand() / (float) RAND_MAX;
    float blue = rand() / (float) RAND_MAX;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
        glColor3f(red, green, blue);
        glVertex2d(x-0.05, y+0.05);
        glVertex2d(x+0.05, y+0.05);
        glVertex2d(x+0.05, y-0.05);
        glVertex2d(x-0.05, y-0.05);
        glEnd();

        if (x >= 0.95 || x <= -0.95)  {
            right = !right;
            red = rand() / (float) RAND_MAX;
            green = rand() / (float) RAND_MAX;
            blue = rand() / (float) RAND_MAX;
        }

        if (y >= 0.95 || y <= -0.95) {
            y = 0;
            Beep(1500, 100);
        }

        if (right) x+=0.01;
        else x-=0.01;

        if (0 + (rand() % (1 - 0 + 1)) == 1) y+=0.005;
        else y-=0.005;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}