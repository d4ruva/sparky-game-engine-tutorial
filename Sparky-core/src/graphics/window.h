#pragma once
#include<iostream>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

#define MAX_KEYS			1024
#define MAX_BUTTONS			3

namespace sparky
{
	namespace graphics
	{
		class Window
		{
		private:
			const char* m_Title;
			int m_Width;
			int m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;

			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double mx, my;

		public:
			Window(const char* name, int width, int height);
			~Window();

			bool closed() const;
			void update();
			void clear() const;

			inline int getHeight() const { return m_Height; }
			inline int getWidth() const	 { return m_Width; }

			static bool isKeyPressed(unsigned int keyCode);

		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mosue_button_callback(GLFWwindow* window, int button, int action, int mods);
		};
	}
}
