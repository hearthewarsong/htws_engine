#ifndef GRAPHICS_INTERFACES_H_
#define GRAPHICS_INTERFACES_H_

class IDrawable;
class IDrawable2D;
class IDrawable3D;

class ICanvas
{
protected:
	ICanvas();
public:
	virtual void getSize() = 0;
	virtual bool Supports3D() = 0;
	virtual bool Draw(const IDrawable2D& object) = 0;
	virtual bool Draw(const IDrawable3D& object) = 0;
	virtual ~ICanvas()
	{
	}
};

class IDrawable
{
};

class IDrawable2D
{
public:
	virtual void Render(ICanvas * canvas) pure;
	virtual ~IDrawable2D() {}
};

class IDrawable3D
{

};

class IFont
{

};

class IText: IDrawable2D
{

};

class IWindow : public SContainer<IDrawable2D>
{
protected:
	IWindow()
	{
	}
public:
	virtual ~IWindow()
	{
	}
};

#endif /* GRAPHICS_INTERFACES_H_ */
