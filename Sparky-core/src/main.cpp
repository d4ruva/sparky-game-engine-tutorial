#include "graphics/window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Untitled Window", 300 * 3, 300 /16 * 9 * 3);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	uint32_t vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{

		window.clear();	

#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f( 0.0,  0.5);
		glVertex2f( 0.5, -0.5);

		glEnd();
#endif

		glBegin(GL_QUADS);

		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);

		glEnd();

		window.update();
	}

	return EXIT_SUCCESS;
}