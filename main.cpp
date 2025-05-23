
#include "circleClass.h"
#include "collisonCheck.h"
int main() 
{
	//vectors that hold shape data:
	std::vector<Circle> circleDataList;
	std::vector<Rectangle> rectangleDataList;
	std::vector<textInfo> textInfoDataList;
	std::vector<sf::Text> textList;


	//basically a vector of all the words in the text file as strings (really scuffed logic here)
	std::vector <std::string> instructions = getFileInfo();
	std::vector <int> windowInfo;
	for (int i = 0; i < instructions.size(); i++ )
	{
		if (instructions[i] == "Window")
		{
			windowInfo.push_back(static_cast<int>(std::stoi(instructions[i + 1])));
			windowInfo.push_back(static_cast<int>(std::stoi(instructions[i + 2])));
		}
		if (instructions[i] == "Font") 
		{
			sf::Font font(instructions[i + 1]);
			textInfo newText(
				instructions[i + 1], //fontpath
				std::stoi(instructions[i+2]), // size of text
				std::stoi(instructions[i + 3]), //r
				std::stoi(instructions[i + 4]), //g
				std::stoi(instructions[i + 5]) //b
				
			);
			textInfoDataList.push_back(newText);
		}
		if (instructions[i] == "Circle")
		{
			Circle newCircle(
				instructions[i + 1],             // name
				std::stof(instructions[i + 2]),  // xPos
				std::stof(instructions[i + 3]),  // yPos
				std::stof(instructions[i + 4]),  // dx
				std::stof(instructions[i + 5]),  // dy
				std::stoi(instructions[i + 6]),  // r
				std::stoi(instructions[i + 7]),  // g
				std::stoi(instructions[i + 8]),  // b
				std::stof(instructions[i + 9])   // radius
			);
			circleDataList.push_back(newCircle);
		}
		if (instructions[i] == "Rectangle")
		{
			Rectangle newRect(
				instructions[i + 1],             // name
				std::stof(instructions[i + 2]),  // xPos
				std::stof(instructions[i + 3]),  // yPos
				std::stof(instructions[i + 4]),  // dx
				std::stof(instructions[i + 5]),  // dy
				std::stoi(instructions[i + 6]),  // r
				std::stoi(instructions[i + 7]),  // g
				std::stoi(instructions[i + 8]),  // b
				std::stof(instructions[i + 9]),   // width
				std::stof(instructions[i + 10])   // height
			);
			rectangleDataList.push_back(newRect);
		}
	}


	//Intatiates the main window object in ordr to call the window
	sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(windowInfo[0]), static_cast<unsigned int>(windowInfo[1]) }), "My Window", sf::Style::Default);



	for (auto& shapeC : circleDataList) 
	{ 
		shapeC.intiateCircle(); //intiatizes all color for the circles
		sf::Text text(textInfoDataList[0].font);
		text.setFillColor(sf::Color(textInfoDataList[0].r, textInfoDataList[0].g, textInfoDataList[0].b));
		text.setCharacterSize(textInfoDataList[0].size);
		text.setString(shapeC.name);
		text.setPosition({ shapeC.xPos/2, shapeC.yPos/2});
		textList.push_back(text);
	} 	
	for (auto& shapeR : rectangleDataList) { shapeR.intiateRect(); } 	//intiatizes all color for the rectangles


	//Main window loop
	while (window.isOpen())
	{
		//This is the event handling (closing, moving, minimizing the window, and such)
		while (const std::optional event = window.pollEvent()) 
		{
			if (event->is < sf::Event::Closed>())
			{
				window.close();
			}
		}
		//Clears window with black background
		window.clear(sf::Color::Black);


		for (auto& shapeC : circleDataList) //Loops over and draws all circles
		{
			window.draw(shapeC.sf_circle);
			shapeC.sf_circle.move({ shapeC.dx, shapeC.dy });
			checkWallCollisionCircle(shapeC.sf_circle, shapeC, windowInfo[1], windowInfo[0]);


			sf::Text text(textInfoDataList[0].font);
			text.setFillColor(sf::Color(textInfoDataList[0].r, textInfoDataList[0].g, textInfoDataList[0].b));
			text.setCharacterSize(textInfoDataList[0].size);
			text.setString(shapeC.name);

			if (textInfoDataList[0].check)
			{
				std::cout << "True" << std::endl;
				text.setPosition({ shapeC.xPos/2, shapeC.yPos/2 });
				textInfoDataList[0].check = false;
				window.draw(text);
			}
			else
			{
				text.setPosition
				(
					{ 
					shapeC.sf_circle.getPosition().x + shapeC.radius - shapeC.dx - textInfoDataList[0].size,
					shapeC.sf_circle.getPosition().y + shapeC.radius - shapeC.dy - textInfoDataList[0].size/2
					}
				);
				window.draw(text);
			}

		}
		for (auto& shapeC : rectangleDataList) //Loops over and draws all rectangles
		{
			window.draw(shapeC.sf_rect);
			shapeC.sf_rect.move({ shapeC.dx, shapeC.dy });
			checkWallCollisionRect(shapeC.sf_rect, shapeC, windowInfo[1], windowInfo[0]);

			sf::Text text(textInfoDataList[0].font);
			text.setFillColor(sf::Color(textInfoDataList[0].r, textInfoDataList[0].g, textInfoDataList[0].b));
			text.setCharacterSize(textInfoDataList[0].size);
			text.setString(shapeC.name);

			if (textInfoDataList[0].check)
			{
				std::cout << "True" << std::endl;
				text.setPosition({ shapeC.xPos / 2, shapeC.yPos / 2 });
				textInfoDataList[0].check = false;
				window.draw(text);
			}
			else
			{
				text.setPosition
				(
					{
					shapeC.sf_rect.getPosition().x + shapeC.width/2 - shapeC.dx - textInfoDataList[0].size,
					shapeC.sf_rect.getPosition().y + shapeC.height/2 - shapeC.dy - textInfoDataList[0].size / 2
					}
				);
				window.draw(text);
			}
		}


		//end the current frame
		window.display();
	}
	return 0;
}