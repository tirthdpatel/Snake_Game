# Introduction
---
## Group Name :-     ELITES
## Members:-
- Het Sachani     - 202404035
- Tirth Patel        - 202401227
- Jeet Patel         - 202404026

---
## Requirement to Run
Code will Run in Windows only

---

## Objective 


The Snake Game is a classic arcade game where the player controls a
snake that grows in size as it consumes food. The game ends if the snake
collides with itself or the boundaries of the play area.

---
# Files Used:-

1. Game.cpp
2. Food.h
3. Food.cpp
4. Snake.h
5. Snake.cpp

---
# Header Files Used:-

1. bits/stdc++.h
2. conio.h
3. ctime
4. windows.h
5. cstdlib
6. random

---
# Brief File Description:-
## Game.cpp:-

 The File Game.cpp is used for:
  - Starting the Game
  - Printing the Grid
  - Tutorial and Rules

---
## Food.h:-

1. The file Food.h contains the Class food
2. The Class food contain declaration of the following :-
3. COORD Pos
4. A int K.
5. The Constructor for Class food.
6. Vector of type string named v ,which contains the different types of the food which can be generated.
7. Vector of type Int named weight ,which contains the chance of generating a certain food from "v".
8. Vector of type int name scores , which contains the score which is given when a certain food is consumed.
9. A Function gen_food() , which is of type int.
10. The Function get_pos(), which is of type COORD.

---
## Food.cpp

The Food.cpp contains the initialization of functions:-
1. get_pos :- Return the position of the current food.
2. gen_food:- It selects a random food from the vector v and generates on the grid and returns a int which is the score of the generated food.

---
## Snake.h
The file Snake.h contains  :
1. structure  "node" which contains:-
    - A "pos" of type COORD.
    - A "next" which is a self referencing  pointer node.
    - A constructor function to create a object for struct node.
2. Class snake  which contains:-
	In Private:-
	 - A node pointer named head.(pointing to head of the snake)
	 - A node pointer named tail. (pointing to the tail of the snake)
	 - A char named dir. (the direction in which the snake is moving )
	 - A int named vel. (the velocity/speed of the snake)
	 - A int named len.( it contains the len of the snake)
    In Public:-
     - A vector of type string , which is named colour, contains the possible colour of the snakes.
     - A declaration of constructor of snake which take "pos "and "vel" as input.
     - A declaration  of function of type void ,which is named as change_dir and  take a char "dir " as input.
     - A declaration of function of type void, which is named as move_snake. 
     - A declaration of function of type COORD, which is named as get_pos.
     - A declaration of function of type COORD, which is named as set_pos and takes 2 integers as input.
     - A declaration of function of type boolean , which is named eaten and takes position of the generated food as input.
     - A declaration of function of type void , which is named grow .
     - A declaration of function of type void, which is named delete_tail.
     - A declaration of function of type boolean, which is named collided.
     - A declaration of function of type node*, which is named get_body.

---
## Snake.cpp

Snake.cpp contains all the definition of the function which are declared in Snake.h:
   1. The Constructor function creates  the object snake for the game, the COORD which it takes as input are central coordinates of the grid and the velocity is by how many grid units the snake moves by, the velocity is set to 1 unit per frame. the constructor function also creates a new node called head which acts as the head of the snake and as the initial length of the snake is 1 grid unit the tail of the snake is also assigned as its head.
   2. The Destructor function is also defined in the file so when the snake moves the previous unit's memory gets freed.
   3. The move_snake function is responsible for the movement of the snake in the grid it defines which keys are responsible for whatsoever movement of the snake
      - 'w' and 'upward arrow key' is responsible for moving the snake upward.
      - 'a' and 'left arrow key' is responsible for moving the snake to the left.
      - 's' and 'downward arrow key' is responsible for moving the snake downward.
      - 'd' and 'right  arrow key' is responsible for moving the snake to the right.
     It also continuously  revaluate the position of the current head and assigns that position to the new head.
   4. The change_dir function takes input from the keyboard using conio.h and passes its argument to move snake function which then decides the direction of movement of snake.
   5. The delete_tail function we create 2 temporary node pointers , one of them pointing to head and other to the tail, then we basically traverse the entire body of the snake till its second last node, then we update the tail's position to the second last node and free the temp pointer pointing to the last node, it is called in the move_snake function to continuously update the size of the snake body in game.
   6. The get_pos function returns the position of head of  snake.
   7. The grow function is responsible for the growth of  size of snake by adding a new node at the end and assigning the new node as tail.
   8. The collided function bounds the snake to move within grid and constrains it to not collide with itself.
   9. The set_pos function redefines the position of the snake and its size when we restart the game.  
   
     
   
   
   


---

# How Code works
1. The object for class snake is created at the centre of the grid which is declared globally.
2. The object for class food is created globally.
3. The Grid is defined as a class with
     - Private variables as its length and its breadth.
     - The public part creates a 2D matrix for movement of snake and generation of food within its boundary.
4. To continuously update the grid we call the SetConsolCursorPosition function and hide_cursor function from windows.h.
5. The gamestart function is defines various User Interface features for the game, and calls and controls all the above mentioned functions.
6. The int main() function calls gamestart function.

---
# Feature of The Game
1. The game starts with a Fancy Font which displays "SNAKE GAME", like in the classic game.
2. Which after a 2sec delay is followed by a list of options which are:
	  - "PRESS t FOR TUTORIALS AND RULES"
	  It explains the basic rules of how the game works and tutorial show how game should be played.It also displays what kind of food may appear and what there corresponding points are.

	 - "PRESS c TO CONTINUE TO THE GAME"
	     It basically proceeds to the start of the game.
	 - "PRESS esc TO EXIT THE GAME"
	     It basically stops execution of  code.
3. After pressing 'c' 
     - The game asks to choose the color for snake from 6 different choices.
     - After Selection of the color of snake you get a UI which shows 
         "Let's Begin. Press ENTER To Start The Game".
    - Upon pressing 'Enter' game starts.
    - Whilst playing game screen continuously shows you the updated Score.
    - If the snake collides the Screen Shows GameOver Interface with Final Score and 2 options
	      "PRESS r TO RESTART THE GAME" 
			  This will call the gamestart function again.
	       "PRESS e TO EXIT" 

4. The food served to the snake are catagorized as following:
	- Normal:
		"🐇" "🪿" "🥚" each are worth 10 points. If the snake eats them Size increases by 1 unit.
	- Exotic:
		"🦢" "🦩" each are worth 20 points. If the snake eats them Size increases by 2 units.
	- Ultra Exotic:
		"🦚" It is are worth 30 points. If the snake eats them Size increases by 3 units.
5. Based on these categories each category has a different spawning rate
	- Normal has a spawning chance of 25% each.
	- Exotic has a spawning chance of 10% each.
	- Ultra Exotic has a spawning chance of 5%.

---

# What We Learnt
 1. Linked List 
 2. Conio.h
 3. Windows.h
 4. Random
 5. Classes
 6. Header Files
 7. Multi File Compilation

---
# Acknowledgment
Youtube : [ProgrammingKnowledge](https://www.youtube.com/@ProgrammingKnowledge)
 
 Chat GPT








