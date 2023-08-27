#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct tale
{
	int talex;
	int taley;
};

int loop = 1, Minus = 0, x = 400, y = 400, a = 0, axis = 'x', score = 0, ay = 280, speed = 1, point = 0, xf = 500, yf = 500, dt = 30, ax1 = 0, ax2 = 0, page = 0;
char keyboard = '1', chspeed, level = '1';
int xef = rand() % (730 - 70 + 1) + 70, yef = rand() % (720 - 80 + 1) + 80, e = 0, efscore = 0, l;
tale location [100] = {0};




//Reset function: Resets the game to its default values or restarts the game 
void reset()
{
	Minus = 0;
	x = 400;
	y = 400;
	a = 0;
	axis = 'x';
	score = 0;
	loop = 0;
	efscore = 0;
	e = 0;
	tale location [100] = {0};
}




//Invalid Entry function: Gives the warning for the invalid input
void invalid()
{
	Beep (1500,600);
	char invalidstatement [30]= "YOU ENTERED AN INVALID VALUE" ;
	setcolor (RED);
	setbkcolor (GREEN);
	settextstyle (10, 0, 5);
	outtextxy (60, 600, invalidstatement);
	getch();
}




//Welcome screen function: Gives the  introductory or welcoming display
void welcome_screen()
{
	setcolor (YELLOW);
	setbkcolor (GREEN);
	
	for (int i = 100; i < 730; i+=10)
	{
		setactivepage (page);
		setvisualpage (1 - page);
		if (kbhit())
		{
			Beep (700,100);
			getch();
			break;	
		}	
		readimagefile ("welcome.jpg", 0, 0, 800, 800);
		
		setcolor(YELLOW);
		for (int j = 10 ; j < 150; j += 30)
			{
				circle (i - j, 600, 20);
				setfillstyle (SOLID_FILL, YELLOW);
				floodfill (i - j, 600, YELLOW);
			}
		setcolor (RED);
		circle (i , 590, 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (i , 590, RED);
	
		setcolor (RED);
		circle (i, 610, 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (i, 610, RED);
		
		page = 1 - page;
	}
}




//Setting function: Gives the menu for the settings of game.
void settings()
{
	loop = 1;
	
	while (loop)
	{
		readimagefile ("keyboard.jpg", 0, 0, 800, 800);
		keyboard = getch();
		
		if (keyboard == '1' || keyboard == '2')
		{
			Beep (700,100);		
			loop = 0;
		}
			
		else 
		{
			invalid();
			loop = 1;
		}	
	}
	
	loop = 1;
	
	while (loop)
	{
		readimagefile ("speed.jpg", 0, 0, 800, 800);
		chspeed = getch();
		
		if (chspeed == '1' || chspeed == '2' || chspeed == '3')
		{
			Beep (700,100);
			speed = chspeed - 48;
			loop = 0;
		}
		
		else 
		{
			invalid();
			loop = 1;			
		}
	}
	
	loop = 1;
	
	while (loop)
	{
		readimagefile ("level.jpg", 0, 0, 800, 800);
		level = getch();
		
		if (level == '1' || level == '2' || level == '3')
		{
			reset();
			Beep (700,100);
		}
		
		else 
		{
			invalid();
			loop = 1;
		}
	}
}




//Main Menu function: Displays the main menu on the screen
void main_menu()
{
	setactivepage (page);
	setvisualpage (page);
	while(loop)
	{
		ax1 = 130, ax2 = 300;
		readimagefile ("main menu.jpg",0,0,800,800);
		setcolor (RED);
		
		for (int i = 0; i < 10; i++)
		{
			arc (ax1, ay, 90, 270, 25);
			arc (ax2, ay, 270, 90, 25);
			ax1++;
			ax2--;
		}

		
		if (kbhit())
		{
			point = getch();
			
			switch (point)
			{
				case 72:
					{
						Beep (700,100);
						if (ay > 280)
							ay -= 70;
						else 
							ay = 490;
						break;
					}
				case 80:
					{
						Beep (700,100);
						if (ay < 480)
							ay += 70;
						else 
							ay = 280;
						break;
					}
				case 13:
					{
						Beep (700,100);
						if (ay == 280)
						{
							readimagefile ("ready.jpg",0,0,800,800);
							getch();
							Beep (700,100);
							loop = 0;
						}
						else if (ay == 350)
						{
							readimagefile ("rules.jpg",0,0,800,800);
							getch();
							Beep (700,100);
							loop = 1;
						}
						else if (ay == 420)
						{
							settings();
							loop = 1;
						}
						else if (ay == 490)
						{
							readimagefile ("exit.jpg",0,0,800,800);
							getch();
							Beep (700,100);
							exit(0);
						}
						break;	
					}				
			}
		}	
	}
}




//Pause function: Gives the pause menu whenever escape key is pressed during the game
void pause()
{
	setvisualpage (page);
	setactivepage (page);
	int loopp = 1;
	
	while (loopp)
	{
		readimagefile("pause menu.jpg",0,0,800,800);
		setcolor (RED);

		for (int i = 0; i < 10; i++)
		{
			arc (ax1, ay, 90, 270, 25);
			arc (ax2, ay, 270, 90, 25);
			ax1++;
			ax2--;
		}
		ax1 = 130, ax2 = 300;
		
		if (kbhit())
		{
			point = getch();
			
			switch (point)
			{
				case 72:
					{	
						Beep (700,100);
						if (ay == 490)
							ax2 += 200;	
										
						if (ay > 280)
							ay -= 70;
						else 
							ay = 490;
						break;
					}
				case 80:
					{
						Beep (700,100);
						if (ay == 490)
							ax2 += 200;
							
						if (ay < 480)
							ay += 70;
						else 
							ay = 280;
						break;
					}
				case 27:
					Beep (700,100);
					loopp = 0;
					break;
					
				case 13:
					{
						Beep (700,100);
						if (ay == 280 )
							loopp = 0;
							
						else if (ay == 350)
						{
							readimagefile ("rules.jpg",0,0,800,800);
							getch();
							Beep (700,100);
							loop = 1;
						}
						else if (ay == 420)
						{
							settings();
							loop = 1;
						}
						else if (ay == 490)
						{
							loop = 1;
							loopp = 0;
							main_menu();
							reset();
						}
						break;	
					}
			}
		}
		if (ay == 490)
			ax2 += 200;
	}
}




//Direction function: Gives the directions to the movement of snake 
void direction()
{
	int arrow = 0, wasd = 0;
	if (keyboard == '2')
	{
		if (kbhit())
		{
			Beep (700,100);
			wasd = getch();
			switch (wasd)
			{
			case 97:
				if (axis == 'x' && Minus == 0)
					break;
				axis = 'x';
				Minus = 1;
				break;

			case 119:
				if (axis == 'y' && Minus == 0)
					break;
				axis = 'y';
				Minus = 1;
				break;

			case 100:
				if (axis == 'x' && Minus == 1)
					break;
				axis = 'x';
				Minus = 0;
				break;

			case 115:
				if (axis == 'y' && Minus == 1)
					break;
				axis = 'y';
				Minus = 0;
				break;

			case 27:
				pause();
				break;

			}
		}
	}
	else if (keyboard == '1')
	{
		if (kbhit())
		{
			arrow = getch();
			switch (arrow)
			{
			case 75:
				Beep (700,100);
				if (axis == 'x')
					break;
				axis = 'x';
				Minus = 1;
				break;

			case 72:
				Beep (700,100);
				if (axis == 'y')
					break;
				axis = 'y';
				Minus = 1;

				break;

			case 77:
				Beep (700,100);
				if (axis == 'x')
					break;
				axis = 'x';
				Minus = 0;

				break;

			case 80:
				Beep (700,100);
				if (axis == 'y')
					break;

				axis = 'y';
				Minus = 0;
				break;
			case 27:
				Beep (700,100);
				pause();
				break;
			}
		}
	}
}




//Movement function: Gives the movement to the snake according to direction
void movement()
{
	location[0].talex = x ;
	location[0].taley = y ;
	
	if (axis == 'x')
	{
		if (Minus == 1)
			x -= speed * 5;

		else
			x += speed * 5;
	}
	else if (axis == 'y')
	{
		if (Minus == 1)
			y -= speed * 5;

		else
			y += speed * 5;
	}
}




//Level 1 Board function: Gives the display for level 1 
void level1board()
{
	char arr1[1], arr2[1];
	
		readimagefile ("level1board.jpg", 0, 0, 800, 800);
		sprintf (arr1, "%d", score + efscore);
		settextstyle (10, 0, 6);
		outtextxy (180, 20, arr1);
		
		sprintf (arr2,"%d",speed);
		settextstyle (10, 0, 6);
		outtextxy (500, 20, arr2);
}




//Level 2 Board function: Gives the display for level 2
void level2board()
{
	char arr1[1], arr2[1];
	readimagefile ("level2board.jpg", 0, 0, 800, 800);
		sprintf (arr1,"%d",score + efscore);
		settextstyle (10, 0, 6);
		outtextxy (200, 12, arr1);
		
		sprintf (arr2,"%d",speed);
		settextstyle (10, 0, 6);
		outtextxy (470, 12, arr2);
}




//Level 3 Board function: Gives the display for level 3
void level3board()
{
	char arr1[1], arr2[1];
	readimagefile ("level3board.jpg", 0, 0, 800, 800);
		sprintf (arr1,"%d",score + efscore);
		settextstyle (10, 0, 6);
		outtextxy (200, 12, arr1);
		
		sprintf (arr2,"%d",speed);
		settextstyle (10, 0, 6);
		outtextxy (470, 12, arr2);
}




//Snake Location funtion: Displays and controls the snake tale
void snake_location()
{
	l = 8;
	l -= (speed * 2);
	if (level == '1')
		level1board();
		
	if (level == '2')
		level2board();
		
	if (level == '3')
		level3board();
		
	//snake head
	setcolor (YELLOW);
	circle (x, y, 20);
	setfillstyle (SOLID_FILL, YELLOW);
	floodfill (x, y, YELLOW);
	
	//snake eyes
	if(axis == 'x')
	{
		setcolor (RED);
		circle (x , y + 10, 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (x , y + 10, RED);
	
		setcolor (RED);
		circle (x, y - 10, 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (x , y - 10, RED);	
	} 
	
	if(axis == 'y')
	{
		setcolor (RED);
		circle (x + 10 , y , 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (x + 10, y, RED);
	
		setcolor (RED);
		circle (x - 10, y, 5);
		setfillstyle (SOLID_FILL, RED);
		floodfill (x - 10, y, RED);	
	} 
	
	//snake tale 
	setcolor (YELLOW);

	for (int i = score * l; i > 0; i -= 1)
	{
		location[i].talex = location[i - 1].talex ;
		location[i].taley = location[i - 1].taley ;
		
		if (i % l == 0)
		{
			circle (location[i].talex, location[i].taley, 20);
			setfillstyle (SOLID_FILL, YELLOW);
			floodfill (location[i].talex, location[i].taley, YELLOW);
		}
	}
} 




//Fruit function: Gives the output to fruit and changes its location when snake touches.
void fruit ()
{
	if ( ( (x - xf < 35) && (x - xf > -35) ) && ( (y - yf < 35) && (y - yf > -35) ))
		{
			Beep (900,100);
			xf = rand() % (730 - 70 + 1) + 70;
			yf = rand() % (720 - 80 + 1) + 80;
			score++;
		}
	
	if (score == 50)
	{
		setvisualpage (page);
		setactivepage (page);
		Beep (700,100);
		if (level == '3')
		{
			readimagefile ("gamecompleted.jpg", 0, 0, 800, 800);
			getch();
			Beep (700,100);
			readimagefile ("exit.jpg",0,0,800,800);
			getch();
			Beep (700,100);
			exit (0);
		}
		else 
		{
			readimagefile ("levelcomplete.jpg", 0, 0, 800, 800);
			getch();
			Beep (700,100);
			level = level + 1;   
			reset();		
		}		
	}
	readimagefile("fruit.jpg", xf, yf, xf + 25, yf + 25);
}




//Gameover_menu Function: This to display the menu after game is over
void gameover_menu()
{
	setvisualpage (page);
	setactivepage (page);
	int ay1 = 365, p = 1;
	char arr1[100];
	
		while (p)
			{
				readimagefile("gameover.jpg",0,0,800,800);
				
				setcolor(YELLOW);
				sprintf(arr1,"%d",score + efscore);
				settextstyle(10, 0, 6);
				outtextxy (250, 250, arr1);
				
				setcolor (RED);
				for (int i = 0; i < 10; i++)
				{
					arc (ax1, ay1, 90, 270,25 );
					arc (ax2, ay1, 270, 90,25 );
					ax1++;
					ax2--;
				}
				ax1 = 130;
				ax2 = 300;
			
		
				if (kbhit())
				{
					point = getch();
					switch (point)
					{	
						case 72:
						{	
							Beep (700,100);
							if (ay1 > 365)
								ay1 -= 70;
							else 
								ay1 = 505;
							
							break;
						}
						case 80:
						{
							Beep (700,100);
							if (ay1 < 480)
								ay1 += 70;
							else 
								ay1 = 365;
							
							break;
						}
						case 13:
						{
							Beep (700,100);
							if (ay1 == 365)
							{
								readimagefile("ready.jpg",0,0,800,800);
								getch();
								a = 1;
								p = 0;
							}
						
							else if (ay1 == 435)
							{
								loop = 1;
								main_menu();
								p = 0;
								a = 1;
							}
							
							else if (ay1 == 505)
							{
								readimagefile ("exit.jpg",0,0,800,800);
								getch();
								exit(0);
							}
							break;	
						}				
					}

				}
				if (ay1 == 435)
					ax2 += 200;
			}
}




//Game status function: Checks the status of game if a foul commited or not 
void gamestatus()
{
	int game_status = 4, ay1 = 365, p = 1;
	char arr1[100];
	
	if (level == '1')
	{
		if (y >= 800)
			y = 0;
		else if (y <= 0)
			y = 800;
		else if (x >= 800)
			x = 0;
		else if (x <= 0)
			x = 800;		
	}
	
	else if (level == '2' || level == '3' || level == '4')
	{
		if (y > 740 || y < 60 || x > 750 || x < 50)
		{
			Beep (300,1000);
			Sleep(1000);
			gameover_menu();
		}
		if (level == '3')
		{
			for (int i = 1; i <= score * l; i++)
			{
				if (x == location[i].talex && y == location[i].taley)
				{
					Beep (300,1000);
					Sleep(1000);
					gameover_menu ();
				}
			}	
		}
	}

	if (a)
		reset();
}




//
void extrafruit ()
{
	int bx1 = 200, bx2 = 600;
	if (score >= 0 && e < 80 )
	{
		readimagefile ("extrafruit.jpg", xef, yef, xef + 50, yef + 50);
		rectangle (bx1 + e*2, 100, bx2 - e*2, 120);
		setfillstyle (SOLID_FILL, YELLOW);
		floodfill (400, 110, YELLOW);
		e ++;	
		if ( ( (x - xef < 55) && (x - xef > -55) ) && ( (y - yef < 55) && (y - yef > -55) ))
		{
			Beep (900,100);
			e = 80;
			efscore +=10;
		}
	}
}




//Main function: In which all the function are called to perform their specific task
int main()
{
	initwindow(800, 800, "Snake Game-2022");
	
	srand(time (NULL));
	welcome_screen();
	main_menu();
	
	while (1)
	{
		setactivepage (page);
		setvisualpage (1 - page);
		direction();
		movement();
		snake_location();
		extrafruit();
		fruit();
		gamestatus();
		page = 1 - page;
	}
	closegraph();
	return 0;
}
