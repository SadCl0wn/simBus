#ifndef __OBJECT_H__
#define __OBJECT_H__

class object{
    public:
        int *getCoor();
        bool setCoor(int coordonnees[2]);
    private:
        int coordonnees[2];
}

#endif