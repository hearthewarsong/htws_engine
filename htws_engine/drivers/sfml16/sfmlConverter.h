#ifndef SFMLCONVERTER_H_
#define SFMLCONVERTER_H_

class SfmlConverter
{
public:
	SfmlConverter();
	virtual ~SfmlConverter();
	static sf::Color GetSFColor(const Color& color);
};

#endif /* SFMLCONVERTER_H_ */
