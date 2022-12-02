#include "SFML\Graphics.hpp"
#include <iostream>


using namespace std;
using namespace sf;

#define Max_main_menu 4

class MainMenu{
    private:
        int MainMenuSelected;
        Font font;
        Text mainMenu[Max_main_menu];


    public:
        // Del siguiente video
        MainMenu(int eje_x,int eje_y);
    
        void draw(RenderWindow &window);
        void MoveUp();
        void MoveDown();

        int MainMenuPressed(){ return MainMenuSelected; }
         
};

// Next Video

MainMenu::MainMenu(int eje_x , int eje_y ){
    if(!font.loadFromFile("fonts/Tacoma.ttf")){
        cout << "No font is here";
    }
    // PLAY
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::Blue);
    mainMenu[0].setString("GENERATE");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400,200);

    // OPTIONS
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::Blue);
    mainMenu[1].setString("INSERT");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400,300);

    // ABOUT
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::Blue);
    mainMenu[2].setString("SEARCH");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400,400);

    // EXIT
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::Blue);
    mainMenu[3].setString("EXIT");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400,500);

    MainMenuSelected = -1;

}

    // Dibukar el menu princiaapl
void MainMenu::draw(RenderWindow &window){
    for(int i=0; i< Max_main_menu ; i++){
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveUp(){
    if(MainMenuSelected -1 >= 0){
        mainMenu[MainMenuSelected].setFillColor(Color::Red); // white
        MainMenuSelected--;
        if(MainMenuSelected == -1){
            MainMenuSelected =2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Green ); // blue
    }
}

void MainMenu::MoveDown(){
    if(MainMenuSelected + 1 <= Max_main_menu){
        mainMenu[MainMenuSelected].setFillColor(Color::Yellow); // white
        MainMenuSelected++;
        if(MainMenuSelected == 4){
            MainMenuSelected =0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::White ); // blue
    }
}

