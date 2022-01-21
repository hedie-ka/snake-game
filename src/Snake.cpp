#include "Snake.h"

void Snake::createSnake(sf::Vector2f headPosition, sf::Vector2f bodyPosition) {
    headTexture.loadFromFile("head.png");
    sf::RectangleShape head = *(new sf::RectangleShape(sf::Vector2f(40, 40)));
    head.setTexture(&headTexture);
    head.setPosition(headPosition);
    snake.push_back(head);
    texture.loadFromFile("body.png");
    sf::RectangleShape body = *(new sf::RectangleShape(sf::Vector2f(40, 40)));
    body.setTexture(&texture);
    body.setPosition(bodyPosition);
    body.setFillColor(sf::Color::Green);
    snake.push_back(body);
}

void Snake::grow(sf::Vector2f &tailPosition) {
    texture.loadFromFile("body.png");
    sf::RectangleShape body(sf::Vector2f(40, 40));
    body.setTexture(&texture);
    body.setPosition(tailPosition.x, tailPosition.y);
    body.setFillColor(sf::Color::Green);
    snake.push_back(body);
}

void Snake::moveSnake(sf::Vector2f direction) {
    std::list<sf::RectangleShape>::reverse_iterator pieceOfBody;
    for (pieceOfBody = snake.rbegin(); pieceOfBody != snake.rend(); ++pieceOfBody) {
        auto copyOfPiece = pieceOfBody;
        if (pieceOfBody == --snake.rend()) {
            sf::Vector2f headPosition = pieceOfBody->getPosition();
            pieceOfBody->setPosition(sf::Vector2f(headPosition.x + direction.x, headPosition.y + direction.y));
            if (headPosition.x > 760 || headPosition.x < 0 || headPosition.y > 760 || headPosition.y < 0)
                newMove(headPosition);
        } else {
            sf::Vector2f tailPosition = (++copyOfPiece)->getPosition();
            pieceOfBody->setPosition(sf::Vector2f(tailPosition.x, tailPosition.y));
        }
    }
}

sf::Vector2f Snake::getHeadPosition() {
    return (snake.begin())->getPosition();
}

sf::Vector2f Snake::getTailPosition() {
    return (--snake.end())->getPosition();
}

sf::Vector2f Snake::getPositionOfPlaceBeforeHead() {
    std::list<sf::RectangleShape>::iterator pieceOfBody;
    int counter = 0;
    for (pieceOfBody = snake.begin(); pieceOfBody != --snake.end(); ++pieceOfBody) {
        if (counter == 1)
            return pieceOfBody->getPosition();
        counter++;
    }
    return pieceOfBody->getPosition();
}

void Snake::newMove(sf::Vector2f headPosition) {
    if (headPosition.x > 760)
        (snake.begin())->setPosition(0, headPosition.y);
    if (headPosition.x < 0)
        (snake.begin())->setPosition(760, headPosition.y);
    if (headPosition.y > 760)
        (snake.begin())->setPosition(headPosition.x, 0);
    if (headPosition.y < 0)
        (snake.begin())->setPosition(headPosition.x, 760);
}

bool Snake::defeatSnake() {
    for (auto piece = snake.begin(); piece != snake.end(); piece++) {
        if (piece == snake.begin())
            continue;
        if (piece->getPosition() == getHeadPosition())
            return true;
    }
    return false;
}

bool Snake::accidentOfTwoSnakes(sf::Vector2f &headOfOtherSnake) {
    for (auto piece = snake.begin(); piece != snake.end(); piece++) {
        if (piece->getPosition() == headOfOtherSnake)
            return true;
    }
    return false;
}

bool Snake::ifFoodUnderSnake(sf::Vector2f &foodPosition) {
    for (auto piece = snake.begin(); piece != snake.end(); piece++) {
        if (piece->getPosition() == foodPosition)
            return true;
    }
    return false;
}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto pieceOfBody: snake)
        target.draw(pieceOfBody);
}

Snake::~Snake() {
    snake.erase(snake.begin(), snake.end());
    delete &snake;
}


