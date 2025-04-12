#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include "game.h"

void Game::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Chess puzzle game";
	vm = sf::VideoMode({width, height});
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);

	

}

void Game::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				//close this state and take back to main menu
				window->close();
				
				Menu menu;
			
				menu.running();
				
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
			
				LevelOne one;
				one.running();
				window->close();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
				LevelTwo two;
				two.running();
				window->close();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num3)
			{

				window->close();
			}
		}
	}
}

void Game::updating()
{
	pollEvents();
}

void Game::rendering()
{

	

	sf::Texture texture0("Sprites\\textbackdrop.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 100,-500 });
	sprite0.scale(sf::Vector2f(3.0f, 2.75));

	sf::Font font("Fonts\\jersey10.ttf");

	sf::Text textA(font);
	textA.setString("CHOOSE A LEVEL: ");
	textA.setCharacterSize(150);
	textA.setFillColor(sf::Color::White);
	textA.setPosition({ 550,50 });

	sf::Text textB(font);
	textB.setString("Level One: Enter 1. ");
	textB.setCharacterSize(150);
	textB.setFillColor(sf::Color::Black);
	textB.setPosition({ 400,450 });

	sf::Text textC(font);
	textC.setString("Level Two: Enter 2.");
	textC.setCharacterSize(150);
	textC.setFillColor(sf::Color::Black);
	textC.setPosition({ 400,600 });

	sf::Text textD(font);
	textD.setString("Level Three: Enter 3.");
	textD.setCharacterSize(150);
	textD.setFillColor(sf::Color::Black);
	textD.setPosition({ 400,750 });





	
	window->clear(sf::Color(75, 54, 33));

	window->draw(sprite0);
	window->draw(textA);
	window->draw(textB);
	window->draw(textC);	
	window->draw(textD);


	window->display();


}

Game::Game()
{
	initWindow();
	
	
}

Game::~Game()
{
	delete window;
	
	backgroundMusic.stop();
	//stops this music if user goes back or moves forward.
}

void Game::running()
{
	while (window->isOpen()) 
	{
		updating();
		rendering();
	}
}

void Menu::initWindow()
{

	width = 2000;
	height = 1500;
	title = "Main menu";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);

}

void Menu::pollEvents()
{

	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
			{
				//press enter to stop main menu window and music and start game state
				backgroundMusic.stop();
				window->close();
				Game game;
				game.running();
			}
		

		}
	}
}

void Menu::updating()
{

	pollEvents();
}

void Menu::rendering()
{
   // Load font and title
   sf::Font font("Fonts\\jersey10.ttf");

   sf::Text text1(font);
   text1.setString("Chess Puzzle Game");
   text1.setCharacterSize(175);
   text1.setFillColor(sf::Color::Black);
   text1.setPosition({ 450,375 });

   // Load enter text
   sf::Text text2(font);
   text2.setCharacterSize(100);
   text2.setString("Press Enter To Play");
   text2.setFillColor(sf::Color::Black);
   text2.setPosition({ 650,675 });

   // Load quit text
   sf::Text text3(font);
   text3.setCharacterSize(100);
   text3.setString("Press Escape To Quit");
   text3.setFillColor(sf::Color::Black);
   text3.setPosition({ 650,800 });

   // Load sprites
   sf::Texture texture1("Sprites\\queen1.png");
   sf::Sprite sprite1(texture1);
   sprite1.setOrigin({ 32,32 });
   sprite1.setPosition({ 845,652 });
   sprite1.scale(sf::Vector2f(2.0, 2.0));

   sf::Texture texture2("Sprites\\textbackdrop.png");
   sf::Sprite sprite2(texture2);
   sprite2.setPosition({ 200,-550 });
   sprite2.scale(sf::Vector2f(2.74, 2.75));

   sf::Texture texture3("Sprites\\king1.png");
   sf::Sprite sprite3(texture3);
   sprite3.setOrigin({ 32,32 });
   sprite3.setPosition({ 1150,652 });
   sprite3.scale(sf::Vector2f(2.0, 2.0));

   sf::Texture texture4("Sprites\\bishop1.png");
   sf::Sprite sprite4(texture4);
   sprite4.setOrigin({ 32,32 });
   sprite4.setPosition({ 995,652 });
   sprite4.scale(sf::Vector2f(2.0, 2.0));

  
 
   

   window->clear(sf::Color(75, 54, 33));

   // Draw elements
   window->draw(sprite2);
   window->draw(text1);
   window->draw(text2);
   window->draw(text3);
   window->draw(sprite1);
   window->draw(sprite3);
   window->draw(sprite4);

   window->display();
}



Menu::Menu()
{
	initWindow();
	if (!backgroundMusic.openFromFile("media/openingsound.flac")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		backgroundMusic.setVolume(150.f); // Set volume
		backgroundMusic.play(); // Start playing
	}
	
}

Menu::~Menu()
{
	
	delete window;
	backgroundMusic.stop();
}

void Menu::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}



void LevelOne::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 1";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}



void LevelOne::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				levelstart.stop();
				window->close();
				Game game;
				game.running();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
				levelstart.stop();
				window->close();
				LevelOnePass pass;
				pass.running();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
				levelstart.stop();
				window->close();
				LevelOneFail fail;
				fail.running();

			}
		}
	}
}

void LevelOne::updating()
{
	pollEvents();
}

void LevelOne::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");

	sf::Text text0(font);
	text0.setString("LEVEL1: ");
	text0.setCharacterSize(150);
	text0.setFillColor(sf::Color::White);
	text0.setPosition({ 100,5 });

	sf::Text text1(font);
	text1.setString("Press 1 to move Rook to A4.");
	text1.setCharacterSize(90);
	text1.setFillColor(sf::Color::White);
	text1.setPosition({ 500,10 });

	sf::Text text2(font);
	text2.setString("Press 2 to move Queen to A4.");
	text2.setCharacterSize(90);
	text2.setFillColor(sf::Color::White);
	text2.setPosition({ 500,100 });

	

	sf::Texture texture0("Sprites\\queen.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 590,1300 });
	sprite0.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture1("Sprites\\rook.png");
	sf::Sprite sprite1(texture1);
	sprite1.setPosition({ 855,895 });
	sprite1.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture2("Sprites\\king.png");
	sf::Sprite sprite2(texture2);
	sprite2.setPosition({ 587,360 });
	sprite2.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture3("Sprites\\king1.png");
	sf::Sprite sprite3(texture3);
	sprite3.setPosition({ 450,490 });
	sprite3.scale(sf::Vector2f(2.0, 2.0));


	sf::Texture texture4("Sprites\\chessboard1.png");
	sf::Sprite sprite4(texture4); 
	sprite4.setPosition({ 400,285 });
	sprite4.scale({ 0.5f,0.5f });



	


	window->clear(sf::Color(75, 54, 33));


	window->draw(text0);
	window->draw(text1);
	window->draw(text2);
	

	window->draw(sprite4);
	window->draw(sprite3);
	window->draw(sprite2);
	window->draw(sprite1);
	window->draw(sprite0);
	
	window->display();
}

LevelOne::LevelOne()
{
	initWindow();

	
	// Load and play background music
	if (!levelstart.openFromFile("media/levelstart.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		levelstart.setVolume(30.f); // Set volume
		levelstart.play();          // Start playing
	}
}

	


LevelOne::~LevelOne()
{
	delete window;

	levelstart.stop();
}

void LevelOne::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}

//opens pass window if user chooses the right answer

void LevelOnePass::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 1";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}


void LevelOnePass::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				victory.stop();
				window->close();
				LevelOne level1;
				level1.running();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
				victory.stop();
				window->close();
				LevelTwo two;
				two.running();
				
			}
			
			
			
		}
	}
}

void LevelOnePass::updating()
{
	pollEvents();
}

void LevelOnePass::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");


	sf::Text text0(font);
	text0.setString("LEVEL 1: PASSED ! ! !");
	text0.setCharacterSize(200);
	text0.setFillColor(sf::Color::Green);
	text0.setPosition({ 400,150 });

	sf::Text text1(font);
	text1.setString("Enter 1 to continue to Level 2.");
	text1.setCharacterSize(150);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition({ 190,585 });

	sf::Text text2(font);
	text2.setString("Or enter Backspace to go back.");
	text2.setCharacterSize(150);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition({ 190,785 });

	sf::Texture texture0("Sprites\\textbackdrop.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 25,-450 });
	sprite0.scale(sf::Vector2f(3.25f, 2.75));


	//clear window
	window->clear(sf::Color(75, 54, 33));
	
	//draw sprite and text
	window->draw(sprite0);
	window->draw(text0);
	window->draw(text1);
	window->draw(text2);
	

	//display window
	window->display();
}

LevelOnePass::LevelOnePass()
{
	initWindow();


	// Load and play background music
	if (!victory.openFromFile("media/victory.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		victory.setVolume(10.f); // Set volume
		victory.play();          // Start playing
	}
}

LevelOnePass::~LevelOnePass()
{
	delete window;

	levelstart.stop();
}

void LevelOnePass::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}
//if they fail opens fail window
void LevelOneFail::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 1";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void LevelOneFail::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				levelstart.stop();
				window->close();
				LevelOne level1;
				level1.running();
			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{

				levelstart.stop();
				window->close();
				LevelOne level1;
				level1.running();

			}

			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
				
				window->close();
			
			}

		}
	}
}

void LevelOneFail::updating()
{
	pollEvents();
}

void LevelOneFail::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");


	sf::Text text0(font);
	text0.setString("LEVEL 1: FAIL");
	text0.setCharacterSize(200);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition({ 400,150 });

	sf::Text text1(font);
	text1.setString("Enter 1 to try again.");
	text1.setCharacterSize(150);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition({ 190,585 });

	sf::Text text2(font);
	text2.setString("Or enter 2 to give up and quit.");
	text2.setCharacterSize(150);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition({ 190,785 });

	sf::Texture texture0("Sprites\\textbackdrop.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 25,-450 });
	sprite0.scale(sf::Vector2f(3.25f, 2.75));


	//clear window
	window->clear(sf::Color(75, 54, 33));

	//draw sprite and text
	window->draw(sprite0);
	window->draw(text0);
	window->draw(text1);
	window->draw(text2);


	//display window
	window->display();
}

LevelOneFail::LevelOneFail()
{
	initWindow();


	// Load and play background music
	if (!lose.openFromFile("media/lose.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		lose.setVolume(10.f); // Set volume
		lose.play();          // Start playing
	}
}

LevelOneFail::~LevelOneFail()
{
	delete window;
	levelstart.stop();
}

void LevelOneFail::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}

//window and functions for level 2
void LevelTwo::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 1";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void LevelTwo::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				levelstart.stop();
				window->close();
				LevelOne one;
				one.running();


			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
				levelstart.stop();
				window->close();
				LevelTwoFail fail;
				fail.running();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
				levelstart.stop();
				window->close();
				LevelTwoPass pass;
				pass.running();

			}


		}
	}
}

void LevelTwo::updating()
{
	pollEvents();
}

void LevelTwo::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");

	sf::Text text0(font);
	text0.setString("LEVEL2: ");
	text0.setCharacterSize(150);
	text0.setFillColor(sf::Color::White);
	text0.setPosition({ 50,5 });

	sf::Text text1(font);
	text1.setString("Press 1 to move Bishop to B7.");
	text1.setCharacterSize(90);
	text1.setFillColor(sf::Color::White);
	text1.setPosition({ 500,10 });

	sf::Text text2(font);
	text2.setString("Press 2 to move Rook to A6.");
	text2.setCharacterSize(90);
	text2.setFillColor(sf::Color::White);
	text2.setPosition({ 500,100 });


	sf::Texture texture0("Sprites\\king.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 1395,1300 });
	sprite0.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture1("Sprites\\rook.png");
	sf::Sprite sprite1(texture1);
	sprite1.setPosition({ 450,1300 });
	sprite1.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture2("Sprites\\rook1.png");
	sf::Sprite sprite2(texture2);
	sprite2.setPosition({ 587,360 });
	sprite2.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture3("Sprites\\king1.png");
	sf::Sprite sprite3(texture3);
	sprite3.setPosition({ 450,360 });
	sprite3.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture4("Sprites\\bishop1.png");
	sf::Sprite sprite4(texture4);
	sprite4.setPosition({ 990, 755 });
	sprite4.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture5("Sprites\\bishop.png");
	sf::Sprite sprite5(texture5);
	sprite5.setPosition({ 1265, 1170 });
	sprite5.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture6("Sprites\\pawn1.png");
	sf::Sprite sprite6(texture6);
	sprite6.setPosition({ 450, 620 });
	sprite6.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture7("Sprites\\pawn1.png");
	sf::Sprite sprite7(texture7);
	sprite7.setPosition({ 592, 485 });
	sprite7.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture8("Sprites\\pawn.png");
	sf::Sprite sprite8(texture8);
	sprite8.setPosition({ 587, 1165 });
	sprite8.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture9("Sprites\\pawn.png");
	sf::Sprite sprite9(texture9);
	sprite9.setPosition({ 1395, 1160 });
	sprite9.scale(sf::Vector2f(2.0, 2.0));

	sf::Texture texture10("Sprites\\chessboard1.png");
	sf::Sprite sprite10(texture10);
	sprite10.setPosition({ 400,285 });
	sprite10.scale({ 0.5f,0.5f });






	window->clear(sf::Color(75, 54, 33));


	window->draw(text0);
	window->draw(text1);
	window->draw(text2);

	window->draw(sprite10);
	window->draw(sprite9);
	window->draw(sprite8);
	window->draw(sprite7);
	window->draw(sprite6);
	window->draw(sprite5);
	window->draw(sprite4);
	window->draw(sprite3);
	window->draw(sprite2);
	window->draw(sprite1);
	window->draw(sprite0);

	window->display();
}

LevelTwo::LevelTwo()
{
	initWindow();


	// Load and play background music
	if (!levelstart.openFromFile("media/levelstart.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		levelstart.setVolume(30.f); // Set volume
		levelstart.play();          // Start playing
	}
}

LevelTwo::~LevelTwo()
{
	delete window;

	levelstart.stop();
}

void LevelTwo::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}

void LevelTwoPass::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 1";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void LevelTwoPass::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
				levelstart.stop();
				window->close();
				LevelTwo two;
				two.running();


			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
				
				window->close();
				


			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
				LevelTwoPass pass;
				pass.running();
				window->close();

			}
			


		}
	}
}

void LevelTwoPass::updating()
{
	pollEvents();
}

void LevelTwoPass::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");


	sf::Text text0(font);
	text0.setString("LEVEL 2: PASSED ! ! !");
	text0.setCharacterSize(200);
	text0.setFillColor(sf::Color::Green);
	text0.setPosition({ 400,150 });

	sf::Text text1(font);
	text1.setString("Enter 1 to continue to Level 3.");
	text1.setCharacterSize(150);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition({ 190,585 });

	sf::Text text2(font);
	text2.setString("Or enter Backspace to go back.");
	text2.setCharacterSize(150);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition({ 190,785 });

	sf::Texture texture0("Sprites\\textbackdrop.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 25,-450 });
	sprite0.scale(sf::Vector2f(3.25f, 2.75));


	//clear window
	window->clear(sf::Color(75, 54, 33));

	//draw sprite and text
	window->draw(sprite0);
	window->draw(text0);
	window->draw(text1);
	window->draw(text2);


	//display window
	window->display();
}

//Load pass window if they pass
LevelTwoPass::LevelTwoPass()
{
	initWindow();


	// Load and play background music
	if (!victory.openFromFile("media/victory.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		victory.setVolume(10.f); // Set volume
		victory.play();          // Start playing
	}
}

LevelTwoPass::~LevelTwoPass()
{
	delete window;
	levelstart.stop();
}

void LevelTwoPass::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}


//if user fails it'll load this window
void LevelTwoFail::initWindow()
{
	width = 2000;
	height = 1500;
	title = "Level 2";
	vm = sf::VideoMode({ width, height });
	window = new sf::RenderWindow(vm, title);
	window->setFramerateLimit(60);
}

void LevelTwoFail::pollEvents()
{
	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			window->close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window->close();

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace)
			{
			
				window->close();
				


			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num1)
			{
				levelstart.stop();

				window->close();
				LevelTwo two;
				two.running();
				

			}
			if (keyPressed->scancode == sf::Keyboard::Scancode::Num2)
			{
			
				window->close();
			

			}


		}
	}
}

void LevelTwoFail::updating()
{
	pollEvents();
}

void LevelTwoFail::rendering()
{
	sf::Font font("Fonts\\jersey10.ttf");


	sf::Text text0(font);
	text0.setString("LEVEL 2: FAIL");
	text0.setCharacterSize(200);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition({ 400,150 });

	sf::Text text1(font);
	text1.setString("Enter 1 to try again.");
	text1.setCharacterSize(150);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition({ 190,585 });

	sf::Text text2(font);
	text2.setString("Or enter 2 to give up and quit.");
	text2.setCharacterSize(150);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition({ 190,785 });

	sf::Texture texture0("Sprites\\textbackdrop.png");
	sf::Sprite sprite0(texture0);
	sprite0.setPosition({ 25,-450 });
	sprite0.scale(sf::Vector2f(3.25f, 2.75));


	//clear window
	window->clear(sf::Color(75, 54, 33));

	//draw sprite and text
	window->draw(sprite0);
	window->draw(text0);
	window->draw(text1);
	window->draw(text2);


	//display window
	window->display();
}

LevelTwoFail::LevelTwoFail()
{
	initWindow();


	// Load and play background music
	if (!lose.openFromFile("media/lose.wav")) {
		std::cerr << "Error loading music file" << std::endl;
	}
	else {
		lose.setVolume(10.f); // Set volume
		lose.play();          // Start playing
	}
}

LevelTwoFail::~LevelTwoFail()
{
	delete window;
	levelstart.stop();
}


void LevelTwoFail::running()
{
	while (window->isOpen())
	{

		updating();
		rendering();
	}
}
