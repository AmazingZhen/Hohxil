#include "GameSchedule.h"
#include "Map\LargeMap.h"
#include "Map\GameFail.h"
#include "Map\GameSuccess.h"
#include "Factory\GrassFactory.h"
#include "Factory\SheepFactory.h"
#include "Factory\WolfFactory.h"
#include "Model\CreatureAggregations\SheepAggregation.h"
#include "Model\CreatureAggregations\GrassAggregation.h"
#include "Model\CreatureAggregations\WolfAggregation.h"
#include "Model\Creatures\Sheep.h"

GameSchedule* GameSchedule::gameSchedule = nullptr;
bool GameSchedule::isPaused = true;
int GameSchedule::updateIntervalTimes = 40;
int GameSchedule::count = 0;
int GameSchedule::speed = 1;
int GameSchedule::leftTimes = GameSchedule::WIN_TIMES;

GameSchedule* GameSchedule::getInstance() {
	if (!gameSchedule) {
		gameSchedule = new GameSchedule();
		gameSchedule->init();
    }
	return gameSchedule;
}

bool GameSchedule::init() {
	// Maybe do something ...

	LargeMap *largeMap = (LargeMap*)LargeMap::getInstance();

	for (int i = 0; i < largeMap->getMapSize(); i++) {
		auto sheepFactory = SheepFactory(i);
		
		sheepFactory.createCreature();

		auto wolfFactory = WolfFactory(i);
		wolfFactory.createCreature();

		auto grassFactory = GrassFactory();
		grassFactory.createCreature();
	}

	return true;
}

void GameSchedule::start() {
    log("GameSchedule -----> start ");
	if (isPaused) {
		isPaused = false;
		Director::getInstance()->getScheduler()->schedule(
			schedule_selector(GameSchedule::globalUpdate),
			this,
			UPDATE_INTERVAL,
			false
			);
	}
}

void GameSchedule::end() {
    log("GameSchedule -----> end ");
    Director::getInstance()->getScheduler()->unschedule(schedule_selector(GameSchedule::globalUpdate), this);
	CC_SAFE_DELETE(gameSchedule);
}

void GameSchedule::pause() {
    log("GameSchedule -----> pause ");
	isPaused = true;
}

void GameSchedule::resume() {
    log("GameSchedule -----> resume ");
	isPaused = false;
}

int GameSchedule::getSpeed() {
	log("GameSchedule -----> getSpeed ");
	return this->speed;
}

void GameSchedule::setSpeed(int speed) {
	log("GameSchedule -----> setSpeed ");
	this->speed = speed;
	this->updateIntervalTimes = MAX_UPDATE_INTERVAL / speed;
}

// Update the whole game.
void GameSchedule::globalUpdate(float time) {
	if (isPaused)
		return;

	if (count < this->updateIntervalTimes) {
		count++;
		return;
	}
	else {
		count = 0;

		--GameSchedule::leftTimes;

		// Main game logic should be written here !!
		wolfEatSheep();
		sheepEatGrass();

		sheepMove();
		wolfMove();

		sheepBreed();
		
		checkSuccessOrFail();
	}

}

void GameSchedule::onExit() {
    log("GameSchedule dispose!!!!");
}

GameSchedule::~GameSchedule() {
    log("GameSchedule dispose!!!!");
}

void GameSchedule::sheepMove() {
	auto sheepAgg = SheepAggregation::getInstance();
	auto sheeps = sheepAgg->getAllMembers();

	for (int i = 0; i < sheeps.size(); i++) {
		dynamic_cast<class Sheep*>(sheeps[i])->move();
	}
}

void GameSchedule::wolfMove() {
	auto wolfAgg = WolfAggregation::getInstance();
	auto wolfs = wolfAgg->getAllMembers();

	for (int i = 0; i < wolfs.size(); i++) {
		dynamic_cast<class Wolf*>(wolfs[i])->move();
	}
}

void GameSchedule::sheepEatGrass() {
    auto sheepAgg = SheepAggregation::getInstance();
    auto sheeps = sheepAgg->getAllMembers();
    
    auto grassAgg = GrassAggregation::getInstance();
    auto grass = grassAgg->getAllMembers();
    
    for (int cur_sheep = 0; cur_sheep < sheeps.size(); cur_sheep++) {
        for (int cur_grass = 0; cur_grass < grass.size(); cur_grass++) {
            if (grass[cur_grass]->getParent() != sheeps[cur_sheep]->getParent()) {
                continue;
            }
            
            if (sheeps[cur_sheep]->getBoundingBox().intersectsRect(grass[cur_grass]->getBoundingBox())) {
                log("sheep eat grass!!!!");
                
                dynamic_cast<class Sheep*>(sheeps[cur_sheep])->prey(grass[cur_grass]);
            }
        }
    }
    
    grassAgg->clearingDeathAndUpdate();
}

void GameSchedule::wolfEatSheep() {
	auto wolfAgg = WolfAggregation::getInstance();
	auto wolfs = wolfAgg->getAllMembers();

	auto sheepAgg = SheepAggregation::getInstance();
	auto sheeps = sheepAgg->getAllMembers();

	for (int cur_wolf = 0; cur_wolf < wolfs.size(); cur_wolf++) {
		for (int cur_sheep = 0; cur_sheep < sheeps.size(); cur_sheep++) {
			if (wolfs[cur_wolf]->getParent() != sheeps[cur_sheep]->getParent()) {
				continue;
			}

			if (wolfs[cur_wolf]->getBoundingBox().intersectsRect(sheeps[cur_sheep]->getBoundingBox())) {
				log("Wolf eat sheep!!!!");

				dynamic_cast<class Wolf*>(wolfs[cur_wolf])->prey(sheeps[cur_sheep]);
			}
		}
	}

	sheepAgg->clearingDeathAndUpdate();
}

void GameSchedule::sheepBreed() {
	auto sheepAgg = SheepAggregation::getInstance();
	auto sheeps = sheepAgg->getAllMembers();

	for (int cur_sheep = 0; cur_sheep < sheeps.size(); cur_sheep++) {
		for (int next_sheep = cur_sheep + 1; next_sheep < sheeps.size(); next_sheep++) {
			if (sheeps[cur_sheep]->getParent() != sheeps[next_sheep]->getParent()) {
				continue;
			}

			if (sheeps[cur_sheep]->getBoundingBox().intersectsRect(sheeps[next_sheep]->getBoundingBox())) {
				dynamic_cast<class Sheep*>(sheeps[cur_sheep])->breed(dynamic_cast<class Sheep*>(sheeps[next_sheep]));
				break;
			}
		}
	}
}

void GameSchedule::wolfBreed() {
	auto wolfAgg = SheepAggregation::getInstance();
	auto wolfs = wolfAgg->getAllMembers();

	for (int cur_wolf = 0; cur_wolf < wolfs.size(); cur_wolf++) {
		for (int next_wolf = cur_wolf + 1; next_wolf < wolfs.size(); next_wolf++) {
			if (wolfs[cur_wolf]->getParent() != wolfs[next_wolf]->getParent()) {
				continue;
			}

			if (wolfs[cur_wolf]->getBoundingBox().intersectsRect(wolfs[next_wolf]->getBoundingBox())) {
				dynamic_cast<class Sheep*>(wolfs[cur_wolf])->breed(dynamic_cast<class Sheep*>(wolfs[next_wolf]));
				break;
			}
		}
	}
}

void GameSchedule::checkSuccessOrFail() {
	auto wolfAgg = WolfAggregation::getInstance();
	auto wolfs = wolfAgg->getAllMembers();

	auto sheepAgg = SheepAggregation::getInstance();
	auto sheeps = sheepAgg->getAllMembers();

	if (GameSchedule::leftTimes <= 0) {
		end();
		//pause();
		auto scene = GameSuccess::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, scene));
	} else if (wolfs.size() == 0 || sheeps.size() == 0) {
		end();
		//pause();
		auto scene = GameFail::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, scene));
	} else {
		// do nothing
	}
}

int GameSchedule::getLeftTimes() {
	return leftTimes;
}