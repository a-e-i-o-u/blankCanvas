#include "Application.h"

#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Wall.h"

void App::Run()
{
    StartUp();

    int   frames        = 0;
    float starttime     = 0;
    float timepassed    = 0;
    while(window.isOpen())
    {
        /** Process Events **/
        pollEvents();

        /**  Clear Window  **/
        window.clear(Camera::backgroundColor);

        timepassed += calculateTime();

        if(isFocused) {

            /** Calculate FPS **/
            if (timepassed - starttime > 0.25 && frames > 10) {
                Time::fps = frames / (timepassed - starttime);
                starttime = timepassed;
                frames = 0;
            }

            /** Update **/
            Update  ();

            /**  Draw  **/
            Draw    ();

            /** Display Frame **/
            window.display();

            frames++;
        }
    }

    CleanUp();
}

void App::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) view.move(-32 * Time::deltaTime, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) view.move( 32 * Time::deltaTime, 0);


    Input::mousePosition.x = static_cast <int> (((sf::Mouse::getPosition(window).x - 32) / 32 + view.getCenter().x / 32) - 6);
    Input::mousePosition.y = static_cast <int> (((sf::Mouse::getPosition(window).y - 32) / 32 + view.getCenter().y / 32) - 6);

    level -> Update();

    window.setView(*Camera::main);
}

void App::Draw()
{
    level -> Draw(window);
}


void App::StartUp()
{
    Camera::main = &view;
    level = new (std::nothrow) Level();
    window.create    (sf::VideoMode(480, 480), "blankCanvas", sf::Style::Close);

    view.setCenter  (0, 0);
    view.setSize    (480, 480);

    Camera::backgroundColor = sf::Color(49, 77, 121);

    Entity* newPlayer   = level -> createEntity(new (std::nothrow) Player,  sf::Vector2i( 0, 0));
    Entity* newWall1    = level -> createEntity(new (std::nothrow) Wall,    sf::Vector2i( 1, 1));
    Entity* newWall2    = level -> createEntity(new (std::nothrow) Wall,    sf::Vector2i( 1, 2));
    Entity* newWall3    = level -> createEntity(new (std::nothrow) Wall,    sf::Vector2i(-2, 1));


    {
        newPlayer -> setTexture(textureManager.get_image("textures/player.png"));

        newWall1 -> setTexture(textureManager.get_image("textures/wall.png"));
        newWall2 -> setTexture(textureManager.get_image("textures/wall.png"));
        newWall3 -> setTexture(textureManager.get_image("textures/wall.png"));

    }
}

void App::CleanUp()
{
    level -> CleanUp();
    delete level;

    textureManager.deleteEverything();
}


void App::pollEvents()
{
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::GainedFocus)
            isFocused = true;
        if(event.type == sf::Event::LostFocus)
            isFocused = false;
    }
}


float App::calculateTime()
{
    sf::Time time   = clock.restart();
    Time::deltaTime = time.asSeconds();

    return time.asSeconds();
}

