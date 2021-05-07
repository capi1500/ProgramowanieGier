//
// Created by Kacper on 07/05/2021.
//

#include <systems/console.hpp>
#include "fleeGhostState.hpp"
#include "../ghost.hpp"
#include "defaultGhostState.hpp"
#include "deadGhostState.hpp"

void FleeGhostState::calculateMove(){
	std::vector<sf::Vector2u> possible = ghost.getMap().findShortestPath(ghost.getPos(), sf::Vector2u(17, 14), ghost.isPassDoor());
	if(possible.empty()){
		moves.push(ghost.getPos());
	}
	for(auto& v : possible)
		moves.push(v);
}

FleeGhostState::FleeGhostState(FiniteStateMachine& fsm, Ghost& ghost, AssetManager::EntityAssetPack& assetPack) : GhostState(fsm, ghost, assetPack){
	speed = 0.7;
}

void FleeGhostState::update(const sf::Time& time){
	GhostState::update(time);
	if(ghost.getPos() == sf::Vector2u(17, 14)){
		if(!atBase){
			atBase = true;
			timeAtBase = sf::Time::Zero;
		}
		else{
			timeAtBase += time;
			if(timeAtBase >= sf::seconds(3)){
				atBase = false;
				message.notify(Message("change ghost to deafult", Message::Debug));
				fsm.replace(new DefaultGhostState(fsm, ghost, assetPack));
			}
		}
	}
}

void FleeGhostState::onNotify(const GameEvent& event){
	if(event.type == GameEvent::PacmanMove){
		if(event.pacmanMove.position == ghost.getPos()){
			message.notify(Message("change ghost to dead", Message::Debug));
			fsm.replace(new DeadGhostState(fsm, ghost, assetPack));
		}
	}
}
