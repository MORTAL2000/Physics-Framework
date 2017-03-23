#pragma once
#include <iostream>

#include "Engine.h"
#include "Observer.h"
#include "Subject.h"
#include "Event.h"

class WindowEvent : public Event
{
public:
	enum EventList
	{
		WINDOW_RESIZE,
		WindowEventCount
	};
	EventList EventID;

	WindowEvent() {};
	~WindowEvent() {};
};

class WindowManager : public Observer
{
	/*----------MEMBER VARIABLES----------*/
private:
	static GLFWwindow * pWindow;

	/*------------------------------- ENGINE REFERENCE -------------------------------*/
	Engine & EngineHandle;
public:
	static int Width;
	static int Height;
	/*----------MEMBER FUNCTIONS----------*/
public:
	WindowManager(Engine & aEngine) : EngineHandle(aEngine) {}
	~WindowManager();

	inline GLFWwindow * GetWindow() const { return pWindow; }
	Engine const & GetEngine() { return EngineHandle; }

	// Window manager functions
	int InitializeWindow();
	// Observer functions
	virtual void OnNotify(Event * aEvent) override;

	// Window resize 
	static void WindowResizeCallback(GLFWwindow * aWindow, int aWidth, int aHeight);
	// Event thrown when window is resized
	static Subject WindowResize;
};

