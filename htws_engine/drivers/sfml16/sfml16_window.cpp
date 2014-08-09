/*
 * Window.cpp
 *
 *  Created on: May 2, 2014
 *      Author: hearthewarsong
 */

#include "../drivers_all.h"

#ifdef _3RD_SFML16

WindowImpl::WindowImpl(const string& name) :
		IWindow(name), _window(sf::VideoMode(800, 600, 32), name.c_str(), sf::Style::Close)
{
	sf::Font font;
	std::string filename("proba.tff");
	font.LoadFromFile(filename);
}

void WindowImpl::Update()
{
	sf::Event Event;
	while (_window.GetEvent(Event))
	{
		if (Event.Type == sf::Event::Closed)
		{
			_window.Close();
			closed = true;
			break;
		}
	}
}

void WindowImpl::RecursiveRender(SContainer<IDrawable2D>& cRoot,
		bool skipCurrent)
{
	if (!skipCurrent)
	{
		cRoot.Render(this);
	}
	if (cRoot.CanHaveChildren() && cRoot.HasChildren())
	{
		cRoot.SortChildren();
		foreach(ChildList, cRoot.GetCildren(), cIt){
			RecursiveRender(**cIt);
		}
	}
}

WindowImpl::~WindowImpl()
{

}

void WindowImpl::Render(ICanvas* canvas)
{
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.f, 1.f, 1.f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	sf::Color bgColor = SfmlConverter::GetSFColor(BackgroundColor);
	_window.Clear(bgColor);
	RecursiveRender(*this, true);
	_window.Display();
}

NumVector<int> WindowImpl::GetSize()
{
	return NumVector<int>(((sf::RenderTarget*)&_window)->GetWidth(),((sf::RenderTarget*)&_window)->GetHeight());
}

bool WindowImpl::Supports3D()
{
	//TODO implement 3D support
	return false;
}

bool WindowImpl::Draw(const IDrawable2D& object)
{
	return false;
}


NumVector<int> WindowImpl::GetPosition()
{
	return NumVector<int>(0,0);
}

bool WindowImpl::Draw(const IDrawable3D& object)
{
	return false;
}

#endif
