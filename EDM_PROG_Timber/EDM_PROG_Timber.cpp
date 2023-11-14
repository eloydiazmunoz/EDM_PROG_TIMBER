// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>


// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;


// Where is the player/branch? 
// Left or Right
const int MaxWidth = 1920;
const int MaxHeight = 1080;
const int PosTimeBar = 980;
const int NUM_BRANCHES = 6;
// Where is the player/branch?
// Left or Right
enum class side { LEFT, RIGHT, NONE };
// Cloud data
struct Cloud {
	bool active;
	sf::Sprite sprite;
	int speed;
};
int main()
{
	Sprite branches[NUM_BRANCHES];
	side branchPositions[NUM_BRANCHES];
	srand((int)time(0) * 10);
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "JOC DE ELOY DIAZ ", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.jpg");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Sprite spriteTree1, spriteTree2, spriteTree3;
	Texture textureTree1, textureTree2, textureTree3;

	textureTree1.loadFromFile("graphics/tree.png");

	spriteTree1.setTexture(textureTree1);
	spriteTree1.setPosition(1500, 0);

	textureTree2.loadFromFile("graphics/tree.png");
	spriteTree2.setTexture(textureTree2);
	spriteTree2.setPosition(810, 0);

	textureTree3.loadFromFile("graphics/tree.png");
	spriteTree3.setTexture(textureTree3);
	spriteTree3.setPosition(100, 0);


	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	// Is the bee currently moving?
	bool beeActive = false;
	// How fast can the bee fly
	float beeSpeed = 0.0f;
	// Define a structure for representing bees
	struct Bee {
		bool active;
		Sprite sprite;
		float speed;
	};

	const int numBees = 5;
	Bee spriteBees[numBees];

	// Initialize bee data
	for (int i = 0; i < numBees; ++i) {
		spriteBees[i].active = false;
		spriteBees[i].sprite.setTexture(textureBee);
		spriteBees[i].sprite.setPosition(0, 800);
		spriteBees[i].speed = 0.0f;
	}


	// Is the bee currently moving?

	// How fast can the bee fly

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
	// 3 New sprites with the same texture


	// Position the clouds on the left of the screen 
	Clock clock;
	//setup the bee

	// Load 1 new texture

	// 3 New sprites withe the same texture

	// Position the clouds off screen

	// Are the clouds currently on screen?

	// How fast is each cloud?
	// Cloud data array
	const int numClouds = 7;
	const int distance = 150;
	Cloud spriteCloud[numClouds];
	for (int i = 0; i < numClouds; ++i) {
		spriteCloud[i].active = false;
		spriteCloud[i].sprite.setTexture(textureCloud);
		spriteCloud[i].sprite.setPosition(0, 0 * distance);
		spriteCloud[i].speed = 0.0f;
	}

	// Variables to control time itself

	// Time bar
	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((MaxWidth / 2) - timeBarStartWidth / 2, PosTimeBar);
	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;


	// Track whether the game is running

	//Draw some text
	int score = 0;
	//// Variable para almacenar los FPS
	//int fps = 0;

	Text messageText;
	Text scoreText;
	/*Text fpsText;*/



	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);
	//fpsText.setFont(font);
	// Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");
	//fpsText.setString("fps ");
	// Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	//fpsText.setCharacterSize(130);

	// Choose a color
	messageText.setFillColor(Color::Cyan);
	scoreText.setFillColor(Color::Blue);
	// Choose a color
	messageText.setFillColor(Color::Cyan);
	Text fpsText;
	fpsText.setFont(font);
	fpsText.setCharacterSize(24);
	fpsText.setFillColor(Color::Yellow);
	fpsText.setPosition(MaxWidth - 100, 10);
	//HUB
	RectangleShape rectangleBackground;
	rectangleBackground.setSize(Vector2f(550, 150)); // Ample i altura
	rectangleBackground.setPosition(10, 10); // Posició x i y
	rectangleBackground.setFillColor(Color(0, 0, 0, 150)); // RGB i alfa




	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);
	//fpsText.setPosition(1220, 20);


	// Prepare 5 branches

	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);
		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20);
	}

	// Prepare the Player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(MaxWidth / 3, MaxHeight - 350);
	// The player starts on the left
	side playerSide = side::LEFT;
	// Prepare the gravestone
	Sprite spriteGrave;
	Texture textureGrave;
	textureGrave.loadFromFile("graphics/rip.png");
	spriteGrave.setTexture(textureGrave);
	spriteGrave.setPosition(600, 860);
	// Line the axe up with the tree
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;
	// Prepare the axe
	Sprite spriteAxe;
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(755, 845);
	// Prepare the flying log
	Sprite spriteLog;
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 730);
	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;


	// Control the player input
	bool acceptInput = false;
	// Prepare the sound
	SoundBuffer Chop;
	Chop.loadFromFile("sound/chop.WAV");
	Sound Chop_sound;
	Chop_sound.setBuffer(Chop);

	SoundBuffer Death;
	Death.loadFromFile("sound/death.WAV");
	Sound Death_sound;
	Chop_sound.setBuffer(Death);

	SoundBuffer Out_of_timeBuffer;
	Out_of_timeBuffer.loadFromFile("sound/out_of_time.WAV");
	Sound Out_of_time_sound;
	Out_of_time_sound.setBuffer(Out_of_timeBuffer);

	// ss now holds "Hello World"
	// Track whether the game is running
	bool paused = true;

	// Spawn a new branch at position 0
	// LEFT, RIGHT or NONE
	// Move all the branches down one place
	for (int seed = 1; seed <= 5; seed++)
	{
		for (int j = NUM_BRANCHES - 1; j > 0; j--) {
			branchPositions[j] = branchPositions[j - 1];
		}

		srand((int)time(0) + seed);
		int r = (rand() % 5);
		switch (r) {
		case 0:
			branchPositions[0] = side::LEFT;
			break;
		case 1:
			branchPositions[0] = side::RIGHT;
			break;
		default:
			branchPositions[0] = side::NONE;
			break;
		}
	}

	//game loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;
				// hide the axe
				spriteAxe.setPosition(2000,
					spriteAxe.getPosition().y);
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
			// Reset the time and the score
			score = 0;
			timeRemaining = 6;
			// Make all the branches disappear
			// starting in the second Position
			for (int i = 1; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE;
			}
			// Make sure the gravestone is hidden
			spriteGrave.setPosition(675, 2000);
			// Move the player into position
			spritePlayer.setPosition(580, 720);
			acceptInput = true;
		}
		// Wrap the player controls to
		// Make sure we are accepting input
		if (acceptInput)
		{
			// First handle pressing the right cursor key
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				// Make sure the player is on the right
				playerSide = side::RIGHT;
				score++;
				// Add to the amount of time remaining
				timeRemaining += (2 / score) + .15;
				spriteAxe.setPosition(AXE_POSITION_RIGHT,
					spriteAxe.getPosition().y);
				spritePlayer.setPosition(1200, 720);
				// Update the branches
				for (int j = NUM_BRANCHES - 1; j > 0; j--) {
					branchPositions[j] = branchPositions[j - 1];
				}// Spawn a new branch at position 0
				// LEFT, RIGHT or NONE
				int r = (rand() % 5);
				switch (r) {
				case 0:
					branchPositions[0] = side::LEFT;
					break;
				case 1:
					branchPositions[0] = side::RIGHT;
					break;
				default:
					branchPositions[0] = side::NONE;
					break;
				}
				// Set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;
				acceptInput = false;
				Chop_sound.play();
			}

			// First handle pressing the left cursor key 
			if (Keyboard::isKeyPressed(Keyboard::Left))
				
			{
				// El jugador ha premut la tecla de la fletxa esquerra

				//Estableix la posició del jugador al costat esquerre (LEFT).
				playerSide = side::LEFT;

				// Incrementa la puntuació del joc.
				score++;
				//// Incrementa la puntuació del joc.
				//fps++;

				// Afegeix temps al temps restant basat en la puntuació actual.
				timeRemaining += (2 / score) + 0.15;

				// Actualitza la posició de l'herba talladora (axe) a l'esquerra.
				spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);

				// Actualitza la posició del jugador.
				spritePlayer.setPosition(580, 720);

				// Actualitza les posicions de les branques (branches), movent-les una posició cap avall.
				for (int j = NUM_BRANCHES - 1; j > 0; j--) {
					branchPositions[j] = branchPositions[j - 1];
				}

				// Genera una nova branca aleatòria a la posició 0 (ESQUERRA).
				int r = (rand() % 5);
				switch (r) {
				case 0:
					branchPositions[0] = side::LEFT;
					break;
				case 1:
					branchPositions[0] = side::RIGHT;
					break;
				default:
					branchPositions[0] = side::NONE;
					break;
				}

				// Configura el tronc (log) per començar a moure's cap a l'esquerra.
				spriteLog.setPosition(810, 845);
				logSpeedX = 5000;
				logActive = true;
				Chop_sound.play();

				// Marca que el jugador no pot realitzar més accions per ara.
				acceptInput = false;
			}

		}

		//if (frameCount % 100 == 0)
		//{
		//	Text FpsText;
		//	// Actualitza de FPS
		//	int currentFps = 0;

		//	// Codi per calcular els fps 
		//	stringstream ss;
		//	ss << "FPS = " << currentFps;
		//	fpsText.setString(ss.str());


		//}



		//initialize the previous variables, one way or another
		// Make sure we are accepting input
				// More code here next...
				// First handle pressing the right cursor key

					// Make sure the player is on the right

					// Add to the amount of time remaining

					// update the branches

					// set the log flying to the left

					// Play a chop sound


				// Handle the left cursor key

				// Make sure the player is on the left

					// Add to the amount of time remaining

					// update the branches

					// set the log flying

			/*
			****************************************
			Update the scene
			****************************************
			*/
		if (!paused)
		{
			// Measure time


			Time dt = clock.restart();

			Time elapsedTime = dt;

			float fps = 1.0f / elapsedTime.asSeconds();

			stringstream ss;

			ss << "FPS: " << fps;

			fpsText.setString(ss.str());
			// End if(!paused)

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f) {
				// Pause the game
				paused = true;
				// Change the message shown to the player
				messageText.setString("Out of time!!");
				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				messageText.setPosition(MaxWidth / 2.0f, MaxHeight / 2.0f);
				// Out of time
				Out_of_time_sound.play();
			}

			// Play the out of time sound


		// Setup the bee
			if (!beeActive)
			{
				beeSpeed = (rand() % 200) + 200;

				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else
				//move the bee
			{
				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);


				if (spriteBee.getPosition().x < -100)
				{
					beeActive = false;
				}
			}
			// Manage the bee
			for (int i = 0; i < numBees; ++i) {
				if (!spriteBees[i].active) {
					spriteBees[i].speed = static_cast<float>(rand() % 200 + 200);
					float height = static_cast<float>(rand() % 500 + 500);
					spriteBees[i].sprite.setPosition(2000, height);
					spriteBees[i].active = true;
				}
				else {
					spriteBees[i].sprite.setPosition(
						spriteBees[i].sprite.getPosition().x - (spriteBees[i].speed * dt.asSeconds()),
						spriteBees[i].sprite.getPosition().y);

					if (spriteBees[i].sprite.getPosition().x < -100) {
						spriteBees[i].active = false;
					}
				}
			}


			// Move the bee

		// Has the bee reached the right hand edge of the screen?

		// Set it up ready to be a whole new cloud next frame

	// Manage the clouds
			for (int i = 0; i < numClouds; ++i) {
				if (!spriteCloud[i].active) {
					spriteCloud[i].speed = rand() % 200;
					float height = rand() % (distance * (i + 1));
					spriteCloud[i].sprite.setPosition(-200, height);
					spriteCloud[i].active = true;

				}
				else {
					spriteCloud[i].sprite.setPosition(
						spriteCloud[i].sprite.getPosition().x + (spriteCloud[i].speed * dt.asSeconds()), spriteCloud[i].sprite.getPosition().y);
					if (spriteCloud[i].sprite.getPosition().x > MaxWidth) {
						spriteCloud[i].active = false;

					}

				}

			}


			// How fast is the cloud

				// How high is the cloud

				// Has the cloud reached the right hand edge of the screen?

				// Set it up ready to be a whole new cloud next frame


			// Update the score text	
			int currentScore = 0;

			if (score != currentScore) {
				stringstream ss;
				ss << "Score = " << score;
				scoreText.setString(ss.str());
				currentScore = score;
			}

			// update the branch sprites

			// Handle a flying log
			if (logActive)
			{
				// Si el tronc està actiu (logActive és true), aleshores es realitzen les següents accions:

				// Es mou el tronc en la direcció especificada (cap a l'esquerra en aquest cas) amb una certa velocitat.
				spriteLog.setPosition(
					spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y
				);

				//Es verifica si el tronc ha arribat a una posició fora de la pantalla, en què cas es desactiva.
				if (spriteLog.getPosition().x < -100)
				{
					logActive = false;
				}
			}



			// has the player been squished by a branch?
			if (branchPositions[5] == playerSide)
			{
				//death 
				paused = true;
				acceptInput = false;
				//draw the gravestone
				spriteGrave.setPosition(525, 760);
				//hide the player
				spritePlayer.setPosition(2000, 600);
				//change the text of the message 
				messageText.setString("SQUISHED !!");
				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
				// play the death sound 
				Death_sound.play();
				
			}
		}
		// End if(!paused)

		 /*
		 ****************************************
		 Draw the scene
		 ****************************************
		 */

		 // Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);


		// Draw the clouds
		for (int i = 0; i < numClouds; i++)
		{
			window.draw(spriteCloud[i].sprite);
		}
		// update the branch sprites
		for (int i = 0; i < NUM_BRANCHES; i++)
		{
			float height = i * 150;
			if (branchPositions[i] == side::LEFT)
			{
				// Move the sprite to the left side
				branches[i].setPosition(610, height);
				// Flip the sprite round the other way
				branches[i].setRotation(180);
			}
			else if (branchPositions[i] == side::RIGHT)
			{
				// Move the sprite to the right side
				branches[i].setPosition(1330, height);
				// Set the sprite rotation to normal
				branches[i].setRotation(0);
			}
			else
			{
				// Hide the branch
				branches[i].setPosition(3000, height);
			}
		}
		// Draw the branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);

		}
		// Draw the tree
		window.draw(spriteTree1);
		window.draw(spriteTree2);
		window.draw(spriteTree3);
		//Draw the hub 
		window.draw(rectangleBackground);

		// Draw the player
		window.draw(spritePlayer);
		// Draw the axe
		window.draw(spriteAxe);
		// Draraw the flying log                            
		window.draw(spriteLog);
		// Draw the gravestone
		window.draw(spriteGrave);
		// Draw the bee
		for (int i = 0; i < numBees; i++)
		{
			window.draw(spriteBees[i].sprite);
		}
		// Draw the score
		window.draw(scoreText);
		
		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}
		window.draw(fpsText);
		// Draw the timebar
		window.draw(timeBar);
		// Show everything we just drew
		window.display();


	}

	return 0;
}



