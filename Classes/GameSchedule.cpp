#include "GameSchedule.h"
#include "map/LargeMap.h"
#include "Factory\GrassFactory.h"
#include "Factory\SheepFactory.h"
#include "Factory\WolfFactory.h"
#include "Model\CreatureAggregations\SheepAggregation.h"
#include "Model\CreatureAggregations\WolfAggregation.h"

GameSchedule* GameSchedule::gameSchedule = nullptr;
bool GameSchedule::isPaused = true;
int GameSchedule::updateIntervalTimes = 40;
int GameSchedule::count = 0;
int GameSchedule::speed = 1;

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

	// auto grassFactory = GrassFactory();
	// grassFactory.createCreature();

	for (int i = 0; i < largeMap->getMapSize(); i++) {
		auto sheepFactory = SheepFactory(i);
		sheepFactory.createCreature();

		auto wolfFactory = WolfFactory(i);
		wolfFactory.createCreature();
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

// Update the hole game.
void GameSchedule::globalUpdate(float time) {
	if (isPaused)
		return;

	if (count < this->updateIntervalTimes) {
		count++;
		return;
	}
	else {
		count = 0;

		// Main game logic should be written here !!
		wolfEatSheep();
		sheepEatGrass();

		sheepMove();
		wolfMove();
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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < sheeps.size(); i++) {
		dynamic_cast<class Sheep*>(sheeps[i])->move(visibleSize);
	}
}

void GameSchedule::wolfMove() {
	auto wolfAgg = WolfAggregation::getInstance();
	auto wolfs = wolfAgg->getAllMembers();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < wolfs.size(); i++) {
		dynamic_cast<class Wolf*>(wolfs[i])->move(visibleSize);
	}
}

void GameSchedule::sheepEatGrass() {

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