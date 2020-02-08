
/*
 *  Code C++ de la génération d'une boite de collision 
 *
 *
 * 
 */

#include <tiago_move_arm_visu/CollisionBox.h>

CollisionBox::CollisionBox(float posOrigineX, float posOrigineY, float posOrigineZ, float scaleX, float scaleY, float scaleZ) {

    this->posOrigineX = posOrigineX;
    this->posOrigineY = posOrigineY; 
    this->posOrigineZ = posOrigineZ;
        
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->scaleZ = scaleZ; 
}

// Getters and setters 
void CollisionBox::setPosX(float posX){
    this->posOrigineX = posX;
}

void CollisionBox::setPosY(float posY){
    this->posOrigineY = posY;
}

void CollisionBox::setPosZ(float posZ){
    this->posOrigineZ = posZ;
}

void CollisionBox::setScaleX(float scaleX){
    this->scaleX = scaleX;
}

void CollisionBox::setScaleY(float scaleY){
    this->scaleY = scaleY;
}
void CollisionBox::setScaleZ(float scaleZ){
    this->scaleZ = scaleZ;
}

float CollisionBox::getPosX(){
    return this->posOrigineX;
}

float CollisionBox::getPosY(){
    return this->posOrigineY;
}

float CollisionBox::getPosZ(){
    return this->posOrigineZ;
}

float CollisionBox::getScaleX(){
    return this->scaleX;
}

float CollisionBox::getScaleY(){
    return this->scaleY;
}

float CollisionBox::getScaleZ(){
    return this->scaleZ;
}

bool CollisionBox::isCollision (float ptX, float ptY, float ptZ){
    if( ((ptX <= (this->posOrigineX + 0.5f * this->scaleX) ) && (ptX >= (this->posOrigineX - 0.5f * this->scaleX)) )&&
        ((ptY <= (this->posOrigineY + 0.5f * this->scaleY) ) && (ptY >= (this->posOrigineY - 0.5f * this->scaleY)) )&& 
        ((ptZ <= (this->posOrigineZ + 0.5f * this->scaleZ) ) && (ptZ >= (this->posOrigineZ - 0.5f * this->scaleZ)) ) ){
        return true; 
    }
    else // si il n'y a pas de collision entre le point 3D et la box 
    {
        return false;  
    }

}
    

