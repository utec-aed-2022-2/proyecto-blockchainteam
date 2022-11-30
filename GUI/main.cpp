#include <SFML/Graphics.hpp>
#include "buttons.h"
#include "MainMenu.h"


using namespace sf;
using namespace std;

void generate_random_block(
    RenderWindow &GENERATE,
    RenderWindow &INSERTS,
    RenderWindow &SEARCH
 ){
    while (GENERATE.isOpen()){
        Event GENERATEEvent;

        while (GENERATE.pollEvent(GENERATEEvent)){
            if(GENERATEEvent.type == Event::Closed) GENERATE.close(); 
            if(GENERATEEvent.type == Event::KeyPressed){
                if(GENERATEEvent.key.code == Keyboard::Escape){
                    GENERATE.close();
                }
            }
        }
        INSERTS.close();
        SEARCH.close();
        INSERTS.close();
        GENERATE.clear();
        // Inicio
        Font font;
        if (!font.loadFromFile("fonts/Tacoma.ttf")){
            system("echo No se encuentra la fuente &pause");
            return ;
        }
        Text texto("GENERAR BLOQUE",font);

        GENERATE.draw(texto);
        // Listar Bloques
        vector<Text> lista(10);
        Text txt;
        int x = 0;
        for(int i=0; i<10;i++){
            x += 50;
            String cadena = "BUUU" ;
            
            txt.setString(cadena);
            txt.setFont(font);
            txt.setFillColor(Color::White);
            txt.setCharacterSize(40);

            // Posición del txt (X , Y)
            txt.setPosition(250 , 100 + x);
            lista.push_back(txt);

        }   
                

        for(unsigned int i = 0; i < lista.size(); i++){
            GENERATE.draw(lista[i]);

        }

        
        GENERATE.display();
    }                        
}

void insert_block(
    RenderWindow &GENERATE,
    RenderWindow &INSERTS,
    RenderWindow &SEARCH
 ){
    while (INSERTS.isOpen()){
        Event INSERTSEvent;

        while (INSERTS.pollEvent(INSERTSEvent)){
            if(INSERTSEvent.type == Event::Closed) INSERTS.close(); 
            if(INSERTSEvent.type == Event::KeyPressed){
                if(INSERTSEvent.key.code == Keyboard::Escape){
                    INSERTS.close();
                }
            }
        }
        GENERATE.close();
        SEARCH.close();
        INSERTS.clear();
        Font font;
        if (!font.loadFromFile("fonts/Tacoma.ttf")){
            system("echo No se encuentra la fuente &pause");
            return ;
        }
        Text texto("CREAR BLOQUE",font);




        INSERTS.draw(texto);
        INSERTS.display();
    }                        
}

void search_block(
    RenderWindow &GENERATE,
    RenderWindow &INSERTS,
    RenderWindow &SEARCH
 ){
    while (SEARCH.isOpen()){
        Event SEARCHEVENT;

        while (SEARCH.pollEvent(SEARCHEVENT)){
            if(SEARCHEVENT.type == Event::Closed) SEARCH.close(); 
            if(SEARCHEVENT.type == Event::KeyPressed){
                if(SEARCHEVENT.key.code == Keyboard::Escape){
                    SEARCH.close();
                }
            }
        }
        GENERATE.close();
        INSERTS.clear();
        SEARCH.clear();
        Font font;
        if (!font.loadFromFile("fonts/Tacoma.ttf")){
            system("echo No se encuentra la fuente &pause");
            return ;
        }
        Text texto("Estamos en BUSCAR un bloque",font);
        SEARCH.draw(texto);
        SEARCH.display();
    }                        
}

int main(){
    
    RenderWindow MENU(VideoMode(960,720),"Main Menu",Style::Default);
    MainMenu MainMenu(MENU.getSize().x , MENU.getSize().y );

    while (MENU.isOpen()){
        Event event;
        while (MENU.pollEvent(event)){
            if(event.type == Event::Closed) MENU.close(); 
            if(event.type == Event::KeyReleased) {
                if(event.key.code == Keyboard::Up){
                    MainMenu.MoveUp();
                    break;
                }
                if(event.key.code == Keyboard::Down){
                    MainMenu.MoveDown();
                    break;
                }
                if(event.key.code == Keyboard::Return){
                    RenderWindow GENERATE(VideoMode(960,720),"GENERATE");
                    RenderWindow INSERTS(VideoMode(960,720),"INSERTS");
                    RenderWindow SEARCH(VideoMode(960,720),"SEARCH");
                    
                    int x = MainMenu.MainMenuPressed();
                    if( x==0){
                        generate_random_block(GENERATE,INSERTS,SEARCH);
                    }
                    if( x==1){
                        insert_block(GENERATE,INSERTS,SEARCH);
                        
                    }
                    if( x==2){
                        search_block(GENERATE,INSERTS,SEARCH );
                    }
                    if( x== 3) MENU.close();
                    break;
                }
            }
        }
        MENU.clear();
        MainMenu.draw(MENU);
        MENU.display();
        
    }
    
}

