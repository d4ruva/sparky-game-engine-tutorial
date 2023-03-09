#include"window.h"

namespace sparky
{
	namespace graphics
	{
		void window_resize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];
		double Window::mx;
		double Window::my;


		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}


			
		};

		Window::~Window()
		{
			glfwTerminate();

		};

		bool Window::isKeyPressed(unsigned int keyCode)
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return m_Keys[keyCode];
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::init()
		{
			if(!glfwInit())
			{
				std::cout << "Failed to initialize GLFW;" << std::endl;
				return false;
			}else
			{
				std::cout << "Initialized GLFW successfully" << std::endl;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
			if(!m_Window)
			{
				std::cout << "Failed to Create a Window!! Exiting the program ...." << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Unable to initialize GLEW!. Exiting ....." << std::endl;
				return false;
			}

			std::cout << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}


		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		void window_resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			auto const* win = (Window*) glfwGetWindowUserPointer(window);
			
			win->s[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			]
		}

	} // namespace graphics
} // namespace sparky
