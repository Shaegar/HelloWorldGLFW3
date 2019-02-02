#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "drawable.h"

class Level: public Drawable {
    private:
        float height;
    public:
        Level(const float height);
        float getHeight();
        void setHeight(const float value);
        void draw();
        void update();
};

#endif
