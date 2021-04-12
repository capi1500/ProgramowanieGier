//
// Created by Kacper on 26/03/2021.
//

#ifndef PROGRAMOWANIEGIER_MAP_HPP
#define PROGRAMOWANIEGIER_MAP_HPP

#include "field.hpp"

class Map : public sf::Drawable{
	private:
		std::vector<std::vector<Field>> fields;
	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	public:
		Field& getField(const sf::Vector2u& pos);
		Field& getField(const unsigned x, const unsigned y);
		
		Map();
};

#endif //PROGRAMOWANIEGIER_MAP_HPP