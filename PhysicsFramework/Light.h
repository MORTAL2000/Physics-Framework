#pragma once
#include "Typedefs.h"
// Base component class for all types of lights
#include "Component.h"

class Light : public Component
{
	/*----------MEMBER VARIABLES----------*/
public:
	vector3 Color = vector3(1.0f, 0.5f, 0.2f);
	float Intensity = 1.0f;
	int LightSlot = 0;
	/*----------MEMBER FUNCTIONS----------*/
public:
	Light() : Component(Component::LIGHT) {}
	virtual ~Light() {};

	static inline ComponentType GetComponentID() { return Component::ComponentType::LIGHT; }
	static inline const char * GetComponentName() { return ComponentTypeName[ComponentType::LIGHT]; }

	virtual void Deserialize(TextFileData & aTextData) override {};
	virtual void Serialize(TextFileData & aTextFileData) override {};

};