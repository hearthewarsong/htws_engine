/*
 * sfml2_window.h
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#ifndef SFML16_WINDOW_H_
#define SFML16_WINDOW_H_

class WindowImpl : public IWindow, public ICanvas
{
protected:
	sf::RenderWindow _window;
	void RecursiveRender(SContainer<IDrawable2D>& cRoot, bool skipCurrent = false);
public:
	WindowImpl(const string& nameddd);
	void Render(ICanvas * canvas);
	void Update();
	virtual ~WindowImpl();
	virtual NumVector<int> GetSize();
	virtual NumVector<int> GetPosition();
	virtual bool Supports3D();
	virtual bool Draw(const IDrawable2D& object);
	virtual bool Draw(const IDrawable3D& object);
	virtual void* GetDriverSpecificRenderTarget() { return (sf::RenderTarget*)&_window; }
	virtual sf::RenderWindow& GetSFRenderWindow() { return _window; }
};

#endif /* SFML16_WINDOW_H_ */
