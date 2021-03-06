#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

class PC
{
    private:
        int health;
        float x, y;
        bool moving;
    public:
        int getHealth(void);
        float getX(void);
        float getY(void);
        void startMoving(void);
        void stopMoving(void);

        void update();
        void draw();
};


#endif
