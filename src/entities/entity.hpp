//
// Created by Kacper on 12/03/2021.
//

#ifndef PROGRAMOWANIEGIER_ENTITY_HPP
#define PROGRAMOWANIEGIER_ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Entity : public sf::Transformable, public sf::Drawable{
	protected:
		bool visible;
		bool active;
		bool exists;
	public:
		bool isVisible() const;
		bool isActive() const;
		bool isExists() const;
		
		virtual void update(const sf::Time& time) = 0;
		
		Entity();
		virtual ~Entity() = default;
};

#endif //PROGRAMOWANIEGIER_ENTITY_HPP