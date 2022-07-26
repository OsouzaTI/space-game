#ifndef SCENELOADER_H
#define SCENELOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <core/assets.h>
#include <core/object_manager.h>
#include <core/constants.h>
#include <objects/object2d.h>
#include <helpers/hashtable.h>
#include <helpers/vector2d.h>

typedef struct object_scene_loader
{
    int hasSize;
    int hasPosition;
    int hasBoxCollider2D;
    int hasTokenIdentifier;
    Vector2D size;
    Vector2D position;
    char token[2];
    char spriteName[255];
    char tokenIdentifier[MAX_SIZE_TOKEN_IDENTIFIER];
    int renderBoxCollider2D;
    int collisionTag;
    int collisionTags[N_COLLISION_TAGS];
} ObjectSceneLoader;

ObjectSceneLoader* createObjectSceneLoader();
void objectSceneLoaderBindWithObject2D(Display* display, ObjectSceneLoader* objectSceneLoader, Object2D* object2D);
void sceneLoader(ObjectManager* objectManager, Display* display, const char* filePath);
void printObjectSceneLoader(ObjectSceneLoader* objectSceneLoader);
#endif