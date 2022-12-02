

#include <SFML/Graphics.hpp>
using namespace sf;

class buttons{
    private:
        RectangleShape r;
        String id;
    public:
        buttons (String id, RectangleShape r):id(id) , r(r) {}
        RectangleShape get_rect (){ return r; }
        String get_id(){return id;}

};

