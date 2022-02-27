# Battleship Vs. AI
## Introduction
###### Rules and Gameplay

- The players can choose the size of the table which 8x8 to 10x10. After the player chooses >the size, a template class object is created, and the object will create two game class >objects which will create two tables, fake and real, for each of them. One of the game >object’s tables are for player, the others are for AI. Both of them have 5 ships which are >1 5-unit ship, 1 4-unit ship, 1 3-unit ship, and 2 2-unit ships. After the player enter >the coordinate to place the ship, the table will be refresh and use 2 to 5 to label the >ships. The coordinates of AI’s ships will be place randomly when the AI game’s class is >created. Player needs to hit all the ships to win the game. In the game, “X” means hit and >“O” means miss.  Every time after check the validation, the program will scan the table to >check whether there is any numbers which is ships on the table. If there isn’t any numbers >on the table, the game ends.

###### Thoughts after Program
- The game seems very simple, but the AI’s fire part is very complicated because it is very difficult to make an AI that acts like a human player. The AI checks the coordinates around the hit coordinate, and keeps firing when it gets the second hit. If one side is “O” or the side of the table, the AI needs to check the other side too. This needs many Boolean variables. Also, the AI table shown to the player isn’t the real table, it is a clear table and after the player fire, the program will compare the coordinate to the real table. Then it records and shows “O”, “X”, or invalid input. The validation part costs me a lot of time too because I use string as an input type and input in A1 form to let the player input the coordinates. This can check the length easily, but I need to use ascii code to translate after check the length.  It is possible to make the Ai smarter which is divided the table into several sections and randomly fire each of the section to increase the accuracy, but it needs more codes and better logic.


## Development
###### Approach Strategy
- The battleship needs at least three tables, one for the player and two for AI. It is too difficult to use one-dimension arrays. It is easier to use 2-dimension arrays. Also, I use A-J to label the rows and 0-9 to label the columns. The player enters the coordinates clearly, which prevents confusion. It is possible that the tables are larger than 10x10, but there are only 0-9 digits, and it isn't a good idea to use lower case characters with digits because it is easy to mix them up. I have tried to let the player choose which ship they want to place first, but there are 2 2-unit ships, so I used a Boolean to remember the first 2-unit ships. However, there are a lot of bugs and I couldn’t fix them. Therefore, I let the player place the 5-unit ship, then 4-unit ship, and so on. After the player and AI place their ships, I randomized the AI ships’ coordinates.  I used an array to store the ship units, so I can avoid the oversize by subtracting the units such as srand()%num-5(num is the size of the table).  After generating the coordinate, the program will randomly place it horizontally or vertically.  If the ship overlaps, it will try to place it another way. If it is still invalid, the program will randomize the coordinates again.  
- After prepping, I used a switch to separate the player’s fire turn and AI’s fire turn. If the game isn’t over, the program will switch to the AI’s turn and repeat. If the game ends on the player’s turn, the program will jump to another case same as AIs. Also, I put a do-while loop outside the switch and repeat until the game is over.
 For the AI’s fire part, I let the AI fire randomly until it hits. After AI hits, the program will record the coordinate and check the four coordinates beside it until it gets a second hit. After a second hit, the AI will fire in that direction until it gets misses, touches the side, or overlaps. Then, it will fire on the other opposite side until it registers a miss, oversize, or overlap again. 

| Type | Variable Name | Description | File | Line
| ------ | ------ |------ |------ |------ |
int|num |size of 2d dynamic array|	main | 41
| hx, hy, x, y |	current, pre fire coordinates |	AI.h |	20
|	| hx, hy, x, y |	|current, pre fire coordinates |	AI.h |	20
|	|oppcombo	|opposite side combo counter|	AI.h|	22
|	|combo	|combo counter|	AI.h|	23
|	|x1, x2, y1, y2	|2 coordinates to place ship|	Game.h|	45
|	|unit[5]	|units of the ships in an array|	Game.h|	46
|	|count	|place ship unit counter|	Game.cpp|	186
|	|max, min	| |	Game.cpp|	238
|	|count=0	|place ship unit counter|	Game.cpp|	239
|	|hplan	|hit plan after first hit (cross) |	Game.cpp|	390
|	|num	|size of the table|	Table.h|	34
|float	|hit, miss	|hit miss counter|	Game.h|	49
|char	|cx, cy	|char format of x, y|	AI.h|	24
|	|row=i+65 (overload)	|table coordinate indicator|	Game.cpp|	40
|	|temp (player)	|temp to store char form unit.txt|	Game.cpp|	66
|	|temp (ai)	|temp to store char form unit.txt|	Game.cpp|	81
|	|row=i+65 (print)	|table coordinate indicator|	Game.cpp|	161
|	|**fake	|fake table|	Table.h|	13
|	|**real	|real table|	Table.h|	14
|string	|numException	|array size exception string|	main|	67
|	|place	|player place input type|	Game.h|	51
| |	fire |	player fire input type| 	main|	372
| |	temp |	exception string 1 |  	Game.cpp|	225
| |	temp |	exception string 2 |  	Game.cpp|	240
| |	fire |	player fire input type | 	Game.cpp|	332
|bool |	invalid |	num validation | 	main|	42
| |	done |	finish fire | 	AI.h|	16
| |	cross[4] |	cross 4 boxes around hit | 	AI.h|	17
| |	crossdone |	if true back to random|  	AI.h|	18
| |	goback |	invalid back to random|  	AI.h|	19
| |	oneend |	one side finish|  	AI.h|	25
| |	combohit |	keep fire the same direction|  	AI.h|	26
| |	bhit |	hit Boolean|  	AI.h|	27
| |	over |	over Boolean|  	Game.h|	47
| |	valid |	validation Boolean|  	Game.h|	48
| |	win |	win Boolean|  	Game.h|	50
| |	valid |	ai place validation|  	Game.cpp|	95
|fstream |	io |	i/o file in function intro|  	main|	72
| |	io |	i/o file in Game(player) constructor|  	Game.cpp|	65
| |	io |	i/o file in Game(AI) constructor|  	Game.cpp|	82
|time_t |	tstart, tend |	delay display ai fire |  	AI.cpp|	23
|Table |	*t |	struct table pointer|  	Table.h|	35
|Game|	p(num) |	player game object|  	Why.h|	32
| |	ai(num, ‘c’) |	AI game object|  	Why.h|	33
|Why<test>|	a(num) |	class Why object with test type| 	main|	59
