#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
//Classes
#include "Menu.h"
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"

King wKing;
King bKing;
Queen wQueen;
Queen bQueen;
Rook wRook;
Rook bRook;
Knight wKnight;
Knight bKnight;
Bishop wBishop;
Bishop bBishop;
Pawn wPawn;
Pawn bPawn;

//template functions for saving and loading the game 

template<typename T, int height, int width>
std::ostream& save(std::ostream& sv, T(&cell)[height][width])
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			sv << cell[i][j] << " ";
		}
		sv << "\n";
	}
	std::cout << "The game has been saved\n";
	return sv;
}

template<typename T2, int height, int width>
std::istream& load(std::istream& ld, T2(&cell)[height][width])
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			ld >> cell[i][j];
		}
	}
	return ld;
}


int main(){
	
	sf::RenderWindow gamebox(sf::VideoMode(800, 800), "JoChess");
	sf::RenderWindow menubox(sf::VideoMode(800, 800), "JoChess");
	
	Menu menu(menubox.getSize().x, menubox.getSize().y);
	
	float movingx = 0, moovingy = 0;
	int prevx = 0, prevy = 0, x = 0, y = 0;
	int playerMove = 0, move = 0;
	int isLegal = 8;
	int pieceID = 0;
	int checkWhite = 0, checkBlack = 0;



	sf::Texture board,wK, wQ, wR, wKn, wB, wP, bK, bQ, bR, bKn, bB, bP; 

	board.loadFromFile("images/board.png");
	wK.loadFromFile("images/wK.png");
	wQ.loadFromFile("images/wQ.png");
	wR.loadFromFile("images/wR.png");
	wKn.loadFromFile("images/wKn.png");
	wB.loadFromFile("images/wB.png");
	wP.loadFromFile("images/wP.png");
	bK.loadFromFile("images/bK.png");
	bQ.loadFromFile("images/bQ.png");
	bR.loadFromFile("images/bR.png");
	bKn.loadFromFile("images/bKn.png");
	bB.loadFromFile("images/bB.png");
	bP.loadFromFile("images/bP.png");

	sf::Sprite b(board); b.scale(1.69, 1.69);
	sf::Sprite WhiteKing(wK); WhiteKing.scale(1.6, 1.6);
	sf::Sprite WhiteQueen(wQ); WhiteQueen.scale(1.6, 1.6);
	sf::Sprite WhiteRook(wR); WhiteRook.scale(1.6, 1.6);
	sf::Sprite WhiteKnight(wKn); WhiteKnight.scale(1.6, 1.6);
	sf::Sprite WhiteBishop(wB); WhiteBishop.scale(1.6, 1.6);
	sf::Sprite WhitePawn(wP); WhitePawn.scale(1.6, 1.6);
	sf::Sprite BlackKing(bK); BlackKing.scale(1.6, 1.6);
	sf::Sprite BlackQueen(bQ); BlackQueen.scale(1.6, 1.6);
	sf::Sprite BlackRook(bR); BlackRook.scale(1.6, 1.6);
	sf::Sprite BlackKnight(bKn); BlackKnight.scale(1.6, 1.6);
	sf::Sprite BlackBishop(bB); BlackBishop.scale(1.6, 1.6);
	sf::Sprite BlackPawn(bP); BlackPawn.scale(1.6, 1.6);
	
	sf::Sprite Moving;


	//menu behaviour
	while (menubox.isOpen())
	{
		
		sf::Event event;
		while (menubox.pollEvent(event))
		{
			
			switch (event.type)
			{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.navUp();
						break;

						case sf::Keyboard::Down:
							menu.navDown();
						break;

						case sf::Keyboard::Return:
							switch (menu.pick()) {
								case 0:
									std::cout << "Starting a game..." << std::endl;
									//opens a new game
									menubox.close();
								break;

								case 2:
									menubox.close();
									gamebox.close();
								break;

								case 1:
									std::cout << "Loading a save file..." << std::endl;
									
									std::fstream in("savegame.txt", std::ios::in);
									try
									{

										if (in.is_open())
										{
											load(in, cell);
											in.close();
										}
										else { throw 404; }

									}
									catch (...)
									{
										std::cout << "Error, file couldn't be opened" << std::endl;
										return 1;
									}

									menubox.close();
									
								break;
							}
						break;
												
						case sf::Event::Closed:
							menubox.close();
						break;
					}
			}

			menubox.clear();
			menu.draw(menubox);
			menubox.display();
		}


	}

	while (gamebox.isOpen())
	{
		sf::Vector2i cursor = sf::Mouse::getPosition(gamebox);
		x = cursor.x / 100;
		y = cursor.y / 100;

		sf::Event e; 

		while (gamebox.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) gamebox.close();
			
			gamebox.clear();
			//picking up a piece and moving it
			if (e.type == sf::Event::MouseButtonPressed) 
			{
				if (e.key.code == sf::Mouse::Left) 
				{
					if (cell[y][x] != 0) {
						movingx = cursor.x - x * 100;
						moovingy = cursor.y - y * 100;
						
						if (cell[y][x] == bPawn.bPawn && playerMove == 1)
						{
							pieceID = bPawn.bPawn;
							Moving = BlackPawn;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wPawn.wPawn && playerMove == 0)
						{
							pieceID = wPawn.wPawn;
							Moving = WhitePawn;
							cell[y][x] = 0;
						}
						if (cell[y][x] == bKing.bKing && playerMove == 1)
						{
							pieceID = bKing.bKing;
							Moving = BlackKing;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wKing.wKing && playerMove == 0)
						{
							pieceID = wKing.wKing;
							Moving = WhiteKing;
							cell[y][x] = 0;
						}
						if (cell[y][x] == bQueen.bQueen && playerMove == 1)
						{
							pieceID = bQueen.bQueen;
							Moving = BlackQueen;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wQueen.wQueen && playerMove == 0)
						{
							pieceID = wQueen.wQueen;
							Moving = WhiteQueen;
							cell[y][x] = 0;
						}
						if (cell[y][x] == bRook.bRook && playerMove == 1)
						{
							pieceID = bRook.bRook;
							Moving = BlackRook;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wRook.wRook && playerMove == 0)
						{
							pieceID = wRook.wRook;
							Moving = WhiteRook;
							cell[y][x] = 0;
						}
						if (cell[y][x] == bKnight.bKnight && playerMove == 1)
						{
							pieceID = bKnight.bKnight;
							Moving = BlackKnight;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wKnight.wKnight && playerMove == 0)
						{
							pieceID = wKnight.wKnight;
							Moving = WhiteKnight;
							cell[y][x] = 0;
						}
						if (cell[y][x] == bBishop.bBishop && playerMove == 1)
						{
							pieceID = bBishop.bBishop;
							Moving = BlackBishop;
							cell[y][x] = 0;
						}
						if (cell[y][x] == wBishop.wBishop && playerMove == 0)
						{
							pieceID = wBishop.wBishop;
							Moving = WhiteBishop;
							cell[y][x] = 0;

						}
						if (cell[y][x] == 0)
						{
							move = 1;
							prevx = x;
							prevy = y;
						}
						
					}
				}
			}
			
			
			//putting down a piece
			if (e.type == sf::Event::MouseButtonReleased) 
			{
				if (e.key.code == sf::Mouse::Left) 
				{	
					//king's movement
					if (pieceID == wKing.wKing && move == 1)
					{
						isLegal = wKing.whiteMove(prevx, prevy, x, y);
						if (isLegal == 1 && wKing.white == 0)
						{
							wKing.white == 1;
						}
					}
					if (pieceID == bKing.bKing && move == 1)
					{
						isLegal = bKing.blackMove(prevx, prevy, x, y);
						if (isLegal == 1 && bKing.black == 0)
						{
							bKing.black == 1;
						}
					}
					//queen's movement
					if (pieceID == wQueen.wQueen && move == 1)
					{
						isLegal = wQueen.move(prevx, prevy, x, y);
					}
					if (pieceID == bQueen.bQueen && move == 1)
					{
						isLegal = bQueen.move(prevx, prevy, x, y);
					}
					//rook's movement
					if (pieceID == wRook.wRook && move == 1)
					{
						isLegal = wRook.move(prevx, prevy, x, y);
						if (isLegal == 1 && wRook.whiteLeft == 0 && prevx == 7 && prevy == 0)
						{
							wRook.whiteLeft = 1;
						}
						if (isLegal == 1 && wRook.whiteRight == 0 && prevx == 7 && prevy == 7)
						{
							wRook.whiteRight = 1;
						}
					}
					if (pieceID == bRook.bRook && move == 1)
					{
						isLegal = bRook.move(prevx, prevy, x, y);
						if (isLegal == 1 && bRook.blackLeft == 0 && prevx == 0 && prevy == 0)
						{
							wRook.blackLeft = 1;
						}
						if (isLegal == 1 && bRook.blackRight == 0 && prevx == 0 && prevy == 7)
						{
							wRook.blackRight = 1;
						}
					}
					//knight's movement
					if (pieceID == wKnight.wKnight && move == 1)
					{
						isLegal = wKnight.move(prevx, prevy, x, y);
					}
					if (pieceID == bKnight.bKnight && move == 1)
					{
						isLegal = bKnight.move(prevx, prevy, x, y);
					}
					//bishop's movement
					if (pieceID == wBishop.wBishop && move == 1)
					{
						isLegal = wBishop.move(prevx, prevy, x, y);
					}
					if (pieceID == bBishop.bBishop && move == 1)
					{
						isLegal = bBishop.move(prevx, prevy, x, y);
					}
					//pawn's movement
					if (pieceID == wPawn.wPawn && move == 1)
					{	
						isLegal = wPawn.whiteMove(prevx, prevy, x, y);
					}
 					if (pieceID == bPawn.bPawn && move == 1)
					{
						isLegal = bPawn.blackMove(prevx, prevy, x, y);		
					}


					if (isLegal == 1)
					{
						int no = cell[y][x];
						cell[y][x] = pieceID;
						
						if (playerMove == 0) 
						{
							if (checkWhite == 1)
							{
								wKing.whitePoz();
								if (wKing.whiteCheckTest(wKing.whitex, wKing.whitey))
								{
									cell[prevy][prevx] = pieceID;
									cell[y][x] = no;
								}
								else
								{
									checkWhite = 0;
									bKing.blackPoz();
									if (bKing.blackCheckTest(bKing.blackx, bKing.blacky))
									{
										checkBlack = 1;
									}
									playerMove = 1;
									std::cout << "Black's turn";
								}
							}
							else
							{
								wKing.whitePoz();
								if (wKing.whiteCheckTest(wKing.whitex, wKing.whitey))
								{
									cell[prevy][prevx] = pieceID;
									cell[y][x] = no;
								}
								else
								{
									bKing.blackPoz();
									if (bKing.blackCheckTest(bKing.blackx, bKing.blacky))
									{
										checkBlack = 1;
									}
									playerMove = 1;
									std::cout << "Black's turn";
								}
							}
						}
						else
						{
							if (checkWhite == 1)
							{
								bKing.blackPoz();
								if (bKing.blackCheckTest(bKing.blackx, bKing.blacky))
								{
									cell[prevy][prevx] = pieceID;
									cell[y][x] = no;
								}
								else
								{
									wKing.whitePoz();
									if (wKing.whiteCheckTest(wKing.whitex, wKing.whitey))
									{
										checkWhite = 1;
									}
									playerMove = 0;
									std::cout << "White's turn";
								}
							}
							else
							{
								bKing.blackPoz();
								if (bKing.blackCheckTest(bKing.blackx, bKing.blacky))
								{
									cell[prevy][prevx] = pieceID;
									cell[y][x] = no;
								}
								else
								{
									wKing.whitePoz();
									if (wKing.whiteCheckTest(wKing.whitex, wKing.whitey))
									{
										checkWhite = 1;
									}
									playerMove = 0;
									std::cout << "White's turn";
								}
							}
						}
					}
					else if (isLegal == 0) 
					{
						cell[prevy][prevx] = pieceID;
					}
					pieceID = 0;
					isLegal = 0;
					move = 0;
				}
			}

			//saving a game for later
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) 
			{
				std::fstream file("savegame.txt", std::ios::out);
				try {
					if (file.is_open())
					{
						save(file, cell);
						file.close();
					}

					else { throw 505; }

				}
				catch (...)
				{
					std::cout << "Unable to open file";
				}

			}
		}

		gamebox.clear(sf::Color::White);
		gamebox.draw(b);

		if (move == 1)
		{
			Moving.setPosition(cursor.x - movingx, cursor.y - moovingy);
			gamebox.draw(Moving);
		}


		//setting up a board with pieces
		for (int i = 0; i < 8 ; i++) 
		{
			for (int j = 0; j < 8 ; j++) 
			{
				if (cell[i][j] == 1) {
					WhiteKing.setPosition(j * 100, i * 100);
					gamebox.draw(WhiteKing);
				}
				if (cell[i][j] == 2) {
					WhiteQueen.setPosition(j * 100, i * 100);
					gamebox.draw(WhiteQueen);
				}
				if (cell[i][j] == 3) {
					WhiteRook.setPosition(j * 100, i * 100);
					gamebox.draw(WhiteRook);
				}
				if (cell[i][j] == 4) {
					WhiteKnight.setPosition(j * 100, i * 100);
					gamebox.draw(WhiteKnight);
				}
				if (cell[i][j] == 5) {
					WhiteBishop.setPosition(j * 100, i * 100);
					gamebox.draw(WhiteBishop);
				}
				if (cell[i][j] == 6) {
					WhitePawn.setPosition(j * 100, i * 100);
					gamebox.draw(WhitePawn);
				}
				if (cell[i][j] == 7) {
					BlackKing.setPosition(j * 100, i * 100);
					gamebox.draw(BlackKing);
				}
				if (cell[i][j] == 8) {
					BlackQueen.setPosition(j * 100, i * 100);
					gamebox.draw(BlackQueen);
				}
				if (cell[i][j] == 9) {
					BlackRook.setPosition(j * 100, i * 100);
					gamebox.draw(BlackRook);
				}
				if (cell[i][j] == 10) {
					BlackKnight.setPosition(j * 100, i * 100);
					gamebox.draw(BlackKnight);
				}
				if (cell[i][j] == 11) {
					BlackBishop.setPosition(j * 100, i * 100);
					gamebox.draw(BlackBishop);
				}
				if (cell[i][j] == 12) {
					BlackPawn.setPosition(j * 100, i * 100);
					gamebox.draw(BlackPawn);
				}
			}
		}

		gamebox.display();
	}


	return 0;
}