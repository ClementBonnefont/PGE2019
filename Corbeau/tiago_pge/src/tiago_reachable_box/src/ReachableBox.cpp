
/*
 *  Code C++ de la génération d'une boite de collision 
 *
 *
 * 
 */

#include <tiago_reachable_box/ReachableBox.h>

ReachableBox::ReachableBox(float posOrigineX, float posOrigineY, float posOrigineZ, float scaleX, float scaleY, float scaleZ) {

    this->posOrigineX = posOrigineX;
    this->posOrigineY = posOrigineY; 
    this->posOrigineZ = posOrigineZ;
        
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->scaleZ = scaleZ; 
}

// Getters and setters 
void ReachableBox::setPosX(float posX){
    this->posOrigineX = posX;
}

void ReachableBox::setPosY(float posY){
    this->posOrigineY = posY;
}

void ReachableBox::setPosZ(float posZ){
    this->posOrigineZ = posZ;
}

void ReachableBox::setScaleX(float scaleX){
    this->scaleX = scaleX;
}

void ReachableBox::setScaleY(float scaleY){
    this->scaleY = scaleY;
}
void ReachableBox::setScaleZ(float scaleZ){
    this->scaleZ = scaleZ;
}

float ReachableBox::getPosX(){
    return this->posOrigineX;
}

float ReachableBox::getPosY(){
    return this->posOrigineY;
}

float ReachableBox::getPosZ(){
    return this->posOrigineZ;
}

float ReachableBox::getScaleX(){
    return this->scaleX;
}

float ReachableBox::getScaleY(){
    return this->scaleY;
}

float ReachableBox::getScaleZ(){
    return this->scaleZ;
}

bool ReachableBox::isReachable (float ptX, float ptY, float ptZ){
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
    

