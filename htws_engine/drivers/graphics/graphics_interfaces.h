#ifndef GRAPHICS_INTERFACES_H_
#define GRAPHICS_INTERFACES_H_

#include <string>

#include "../../basics/defines/basic_value_defines.h"
#include "../../basics/templates/math_classes.hpp"
#include "../../basics/templates/property.hpp"
#include "../../basics/templates/scontainer.hpp"
#include "color.h"

class IDrawable;
class IDrawable2D;
class IDrawable3D;

class ICanvas
{
protected:
	ICanvas() {}
public:
	virtual NumVector<int> GetSize() pure;
	virtual bool Supports3D() pure;
	virtual bool Draw(const IDrawable2D& object) pure;
	virtual bool Draw(const IDrawable3D& object) pure;
	virtual void* GetDriverSpecificRenderTarget() pure;
	virtual ~ICanvas()
	{
	}
};

class IDrawable
{
};

class IDrawable2D
{
protected:
	IDrawable2D() : zOrder(0) {}
public:
	int zOrder;
	virtual ~IDrawable2D() {}
	virtual bool operator<(const IDrawable2D& other) { return zOrder < other.zOrder; }
	virtual void Render(ICanvas * canvas) pure;
	virtual NumVector<int> GetPosition() pure;
	virtual NumVector<int> GetSize() pure;
};

class IDrawable3D
{

};

class IFont
{
public:
	const string name;
	IFont(const string& name) : name(name) {}
};

class IText: IDrawable2D
{

};

class IWindow : public SContainer<IDrawable2D>
{
protected:
	string name;
	bool closed;
	IWindow(const string& name) : name(name), closed(false), BackgroundColor(Color(0.0,0.0,0.0))
	{
	}
public:
	virtual ~IWindow()
	{
	}
	virtual void Update() pure;
	bool isClosed() const { return closed; }

public: //Properties
	Property<Color> BackgroundColor;
};

#endif /* GRAPHICS_INTERFACES_H_ */
