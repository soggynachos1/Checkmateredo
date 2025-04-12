#pragma once
#include <string.h>


#include <SFML/Graphics.hpp>



class Game {
private: 
	unsigned int width;
	unsigned int height;
	std::string title;
	sf::VideoMode vm;
	sf::Music levelstart;
	sf::Music backgroundMusic;
	

	void initWindow();

	void pollEvents();

	void updating();
	void rendering();
public: 
	sf::RenderWindow* window;

	Game();

	~Game();

	void running();
};

class Menu
{
private:
	unsigned int width;
	unsigned int height;
	std::string title;
	sf::VideoMode vm;
	sf::Music backgroundMusic;
	

	void initWindow();
	void pollEvents();
	void updating();
	void rendering();

public:
	sf::RenderWindow* window;
	Menu();
	~Menu();
	void running();
};

class LevelOne {
private: 
	unsigned int width;
	unsigned int height;
	std::string title;
	
	sf::VideoMode vm;

	sf::Music levelstart;


	
	void initWindow();

	void pollEvents();
	void updating();
	void rendering();

public: 
	sf::RenderWindow* window;

	LevelOne();
	
	~LevelOne();

	void running();
	
};

class LevelOnePass {
private:
	unsigned int width;
	unsigned int height;
	std::string title;

	sf::VideoMode vm;

	sf::Music levelstart;
	sf::Music victory;

	void initWindow();

	void pollEvents();
	void updating();
	void rendering();
public:
	sf::RenderWindow* window;

	LevelOnePass();

	~LevelOnePass();

	void running();


};

class LevelOneFail {
private:
	unsigned int width;
	unsigned int height;
	std::string title;

	sf::VideoMode vm;

	sf::Music levelstart;
	sf::Music lose;
	

	void initWindow();

	void pollEvents();
	void updating();
	void rendering();
public:
	sf::RenderWindow* window;

	LevelOneFail();

	~LevelOneFail();

	void running();


};

class LevelTwo {
private:
	unsigned int width;
	unsigned int height;
	std::string title;

	sf::VideoMode vm;

	sf::Music levelstart;



	void initWindow();

	void pollEvents();
	void updating();
	void rendering();

public:
	sf::RenderWindow* window;

	LevelTwo();

	~LevelTwo();

	void running();

};

class LevelTwoPass {
private:
	unsigned int width;
	unsigned int height;
	std::string title;

	sf::VideoMode vm;

	sf::Music levelstart;
	sf::Music victory;

	void initWindow();

	void pollEvents();
	void updating();
	void rendering();
public:
	sf::RenderWindow* window;

	LevelTwoPass();

	~LevelTwoPass();

	void running();


};

class LevelTwoFail {
private:
	unsigned int width;
	unsigned int height;
	std::string title;

	sf::VideoMode vm;

	sf::Music levelstart;
	sf::Music lose;

	void initWindow();

	void pollEvents();
	void updating();
	void rendering();
public:
	sf::RenderWindow* window;

	LevelTwoFail();

	~LevelTwoFail();

	void running();


};


