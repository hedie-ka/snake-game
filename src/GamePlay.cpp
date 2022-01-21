#include "GamePlay.h"
#include "GameOverMenu.h"

std::string GamePlay::howFast;

void GamePlay::setHowFast(std::string speedStr) {
    howFast = speedStr;
}

std::string GamePlay::getHowFast() {
    return howFast;
}

void GamePlay::loading() {
    map.load(sf::Vector2u(40, 40), 20, 20);
    firstSnake.createSnake(sf::Vector2f(0, 0), sf::Vector2f(40, 0));
    secondSnake.createSnake(sf::Vector2f(0, 40), sf::Vector2f(0, 80));
    firstWall.load(sf::Vector2u(40, 40), 3, 1);
    secondWall.load(sf::Vector2u(40, 40), 1, 3);
    GamePlay::separateWalls(1);
    GamePlay::separateWalls(2);
    firstFood.setPosition(ifIsOn(1));
    secondFood.setPosition(ifIsOn(2));
}

void GamePlay::controlEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (firstSnake.getHeadPosition().x == firstSnake.getPositionOfPlaceBeforeHead().x) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                directionForFirstSnake = {40, 0};
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                directionForFirstSnake = {-40, 0};
        }
        if (firstSnake.getHeadPosition().y == firstSnake.getPositionOfPlaceBeforeHead().y) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                directionForFirstSnake = {0, -40};
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                directionForFirstSnake = {0, 40};
        }
        if (secondSnake.getHeadPosition().x == secondSnake.getPositionOfPlaceBeforeHead().x) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                directionForSecondSnake = {40, 0};
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                directionForSecondSnake = {-40, 0};
        }
        if (secondSnake.getHeadPosition().y == secondSnake.getPositionOfPlaceBeforeHead().y) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                directionForSecondSnake = {0, -40};
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                directionForSecondSnake = {0, 40};
        }
    }
}

void GamePlay::myDraw(sf::RenderWindow &window) {
    window.draw(map);
    window.draw(firstWall);
    window.draw(secondWall);
    window.draw(firstFood);
    window.draw(secondFood);
    window.draw(firstSnake);
    window.draw(secondSnake);
}

void GamePlay::growSnakes(sf::Vector2f &lastPositionOfTail1, sf::Vector2f &lastPositionOfTail2) {
    if (firstSnake.getHeadPosition() == firstFood.getPosition()) {
        firstSnake.grow(lastPositionOfTail1);
        Music::playEatingFoodMusic();
        firstFood.setPosition(ifIsOn(3));
    } else if (firstSnake.getHeadPosition() == secondFood.getPosition()) {
        firstSnake.grow(lastPositionOfTail1);
        Music::playEatingFoodMusic();
        secondFood.setPosition(ifIsOn(4));
    }
    if (secondSnake.getHeadPosition() == firstFood.getPosition()) {
        secondSnake.grow(lastPositionOfTail2);
        Music::playEatingFoodMusic();
        firstFood.setPosition(ifIsOn(3));
    } else if (secondSnake.getHeadPosition() == secondFood.getPosition()) {
        secondSnake.grow(lastPositionOfTail2);
        Music::playEatingFoodMusic();
        secondFood.setPosition(ifIsOn(4));
    }
}

void GamePlay::separateWalls(int whichOne) {
    srand(time(0));
    sf::Vector2f positionForNewWall;
    if (whichOne == 1)
        while (1) {
            positionForNewWall = sf::Vector2f(40 * (rand() % 17 + 0), 40 * (rand() % 20 + 0));
            if (positionForNewWall != sf::Vector2f(0, 0) && positionForNewWall != sf::Vector2f(0, 40) &&
                positionForNewWall != sf::Vector2f(40, 0) && positionForNewWall != sf::Vector2f(80, 0) &&
                positionForNewWall != sf::Vector2f(0, 80)) {
                firstWall.setPosition(positionForNewWall);
                break;
            }
        }
    else {
        int flag;
        while (1) {
            flag = 0;
            positionForNewWall = sf::Vector2f(40 * (rand() % 20 + 0), 40 * (rand() % 17 + 0));
            for (int row = 0; row < 3; row++) {
                for (int column = 0; column < 3; column++) {
                    if ((abs((firstWall.getPosition().x + column * 40) - positionForNewWall.x) <= 120)) {
                        flag++;
                        break;
                    } else if (abs(firstWall.getPosition().y - (positionForNewWall.y + row * 40)) <= 120) {
                        flag++;
                        break;
                    }
                }
                if (flag != 0)
                    break;
            }
            if (flag == 0 && positionForNewWall != sf::Vector2f(0, 0) && positionForNewWall != sf::Vector2f(0, 40) &&
                positionForNewWall != sf::Vector2f(40, 0) && positionForNewWall != sf::Vector2f(80, 0) &&
                positionForNewWall != sf::Vector2f(0, 80)) {
                secondWall.setPosition(positionForNewWall);
                break;
            }
        }
    }
}

sf::Vector2f GamePlay::ifIsOn(int where) {
    srand(time(0));
    while (1) {
        int isOnFirstWall = 0, isOnSecondWall = 0, isOnFirstFood = 0, isOnSecondFood = 0;
        sf::Vector2f position = {(float) (40 * (rand() % 20 + 0)), (float) (40 * (rand() % 20 + 0))};
        if (firstSnake.ifFoodUnderSnake(position) || secondSnake.ifFoodUnderSnake(position))
            continue;
        for (int row = 0; row < 3; row++) {
            sf::Vector2f wend = {(float) (row * 40) + firstWall.getPosition().x, firstWall.getPosition().y};
            if ((position != wend))
                continue;
            else {
                isOnFirstWall = 1;
                break;
            }
        }
        if (!isOnFirstWall) {
            for (int column = 0; column < 3; column++) {
                sf::Vector2f wend = {secondWall.getPosition().x, (float) (column * 40) + secondWall.getPosition().y};
                if ((position != wend))
                    continue;
                else {
                    isOnSecondWall = 1;
                    break;
                }
            }
        }
        if (((where == 2) || (where == 4)) && (abs(firstFood.getPosition().x - position.x) <= 80) &&
            (abs(firstFood.getPosition().y - position.y) <= 80))
            isOnFirstFood = 1;
        if ((where == 3) && (abs(secondFood.getPosition().x - position.x) <= 80) &&
            (abs(secondFood.getPosition().y - position.y) <= 80))
            isOnSecondFood = 1;
        if ((!isOnFirstWall) && (!isOnSecondWall) &&
            (!isOnFirstFood) && (!isOnSecondFood)) {
            return position;
        }
    }
}

void GamePlay::speed() {
    sf::Vector2f lastPositionOfTail1 = sf::Vector2f(firstSnake.getTailPosition());  // for first snake.
    sf::Vector2f lastPositionOfTail2 = sf::Vector2f(secondSnake.getTailPosition()); // for second snake
    if (howFast == "fast") {
        if (clock.getElapsedTime() > sf::seconds(0.25)) {
            firstSnake.moveSnake(directionForFirstSnake);
            secondSnake.moveSnake(directionForSecondSnake);
            growSnakes(lastPositionOfTail1, lastPositionOfTail2);
            clock.restart();
        }
    }
    if (howFast == "slow") {
        if (clock.getElapsedTime() > sf::seconds(0.5)) {
            firstSnake.moveSnake(directionForFirstSnake);
            secondSnake.moveSnake(directionForSecondSnake);
            growSnakes(lastPositionOfTail1, lastPositionOfTail2);
            clock.restart();
        }
    }
}

void GamePlay::defeat(sf::RenderWindow &window) {
    for (int row = 0; row < 3; row++) {
        sf::Vector2f wend = {(float) (row * 40) + firstWall.getPosition().x, firstWall.getPosition().y};
        if ((firstSnake.getHeadPosition() == wend) ||
            (secondSnake.getHeadPosition() == wend)) {
            Music::playGameOverMusic();
            GameOverMenu::controlEvents(window);
        }
    }
    for (int column = 0; column < 3; column++) {
        sf::Vector2f wend = {secondWall.getPosition().x, (float) (column * 40) + secondWall.getPosition().y};
        if ((firstSnake.getHeadPosition() == wend) ||
            (secondSnake.getHeadPosition() == wend)) {
            Music::playGameOverMusic();
            GameOverMenu::controlEvents(window);
        }
    }
    if (firstSnake.defeatSnake()) {
        Music::playGameOverMusic();
        GameOverMenu::controlEvents(window);
    }

    if (secondSnake.defeatSnake()) {
        Music::playGameOverMusic();
        GameOverMenu::controlEvents(window);
    }
    sf::Vector2f headOfSecondSnake = secondSnake.getHeadPosition();
    if (firstSnake.accidentOfTwoSnakes(headOfSecondSnake)) {
        Music::playGameOverMusic();
        GameOverMenu::controlEvents(window);
    }
    sf::Vector2f headOfFirstSnake = firstSnake.getHeadPosition();
    if (secondSnake.accidentOfTwoSnakes(headOfFirstSnake)) {
        Music::playGameOverMusic();
        GameOverMenu::controlEvents(window);
    }
}

void GamePlay::play(sf::RenderWindow &window) {
    GamePlay gameplay;
    gameplay.loading();
    while (window.isOpen()) {
        gameplay.controlEvents(window);
        gameplay.defeat(window);
        // std::string howFast = GamePlay::getHowFast();
        gameplay.speed();
        window.clear(sf::Color::White);
        gameplay.myDraw(window);
        window.display();
        // sf::sleep(interval);
    }
}


