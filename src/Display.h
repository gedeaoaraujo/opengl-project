#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <SDL2/SDL.h>
#include <string>

class Display {

public:
	Display(int width, int height, const std::string& title);

	void update();
	bool getIsClosed();
	void clear(float r, float g, float b, float a);

	virtual ~Display();

private:
	bool isClosed;
	SDL_Window* window;
	SDL_GLContext glContext;

	Display(const Display &other);
	void operator=(const Display &other);
};

#endif /* DISPLAY_H_ */
