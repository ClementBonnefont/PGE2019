
// Std C++ headers

#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

class CollisionBox{

    // attributs
    float scaleX;
    float scaleY;
    float scaleZ;

    float posOrigineX;
    float posOrigineY;
    float posOrigineZ;

public: 
    // Constructeur 
    CollisionBox(float posOrigineX, float posOrigineY, float posOrigineZ, float scaleX, float scaleY, float scaleZ);
    // méthodes de la classe 
    bool isCollision(float ptX, float ptY, float ptZ);
    //getters et setters 
    void setPosX(float posX);
    void setPosY(float posY);
    void setPosZ(float posZ);

    void setScaleX(float scaleX);
    void setScaleY(float scaleY);
    void setScaleZ(float scaleZ);

    float getPosX();
    float getPosY();
    float getPosZ();

    float getScaleX();
    float getScaleY();
    float getScaleZ();

};

#endif


