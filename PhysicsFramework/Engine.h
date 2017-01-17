#pragma once

#include <map>
#include <memory>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Entity classes
#include "Object.h"
// Event classes
#include "Event.h"
#include "Subject.h"

// Forward Declarations
class WindowManager;
class InputManager;
class FrameRateController;
class GameObjectFactory;
class ResourceManager;
class Renderer;
class PhysicsManager;

// The main engine events that have Subjects created from the start
class EngineEvent : public Event
{
public:
	enum EventList
	{
		ENGINE_INIT,
		ENGINE_LOAD,
		ENGINE_TICK,
		ENGINE_UNLOAD,
		ENGINE_EXIT
	};
	EventList EventID;
	EngineEvent() {};
	~EngineEvent() {};
};

class Engine : public Object
{
	/*----------MEMBER VARIABLES----------*/
private:
	std::unique_ptr<WindowManager> pWindowManager;
	std::unique_ptr<InputManager> pInputManager;
	std::unique_ptr<FrameRateController> pFrameRateController;
	std::unique_ptr<GameObjectFactory> pGameObjectFactory;
	std::unique_ptr<ResourceManager> pResourceManager;
	std::unique_ptr<Renderer> pRenderer;
	std::unique_ptr<PhysicsManager> pPhysicsManager;
	// A map of the main engine events
	std::map<EngineEvent::EventList, Subject> MainEventList;

	/*----------MEMBER FUNCTIONS----------*/
public:
	Engine();
	int Init();
	int Load();
	int Unload();
	int Exit();
	int Tick();
	virtual ~Engine();
	std::map<EngineEvent::EventList, Subject> & GetMainEventList() { return MainEventList; }

};
