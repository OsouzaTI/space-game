#include "text2d.h"


Text2D* createText2D(Display* display, const char* text, int x, int y, int width, int height){

    Text2D* text2D = (Text2D*)malloc(sizeof(Text2D));
    text2D->_objectType = TEXT2D;
    text2D->objectId = OBJECT_ID++;
    setVector2D(&text2D->size, width, height);
    setVector2D(&text2D->position, x, y);

    text2D->text = (char*)malloc(sizeof(char)*strlen(text));
    strcpy(text2D->text, text);

    // TODO: fonte 
    SDL_Surface* textSurface = TTF_RenderText_Blended(getFont("minecraft"), text2D->text, SDLC_WHITE);
    if(ISNULL(textSurface)){
        printf("nao foi possivel criar a surface do label\n");
        return NULL;
    }

    text2D->textureText = SDL_CreateTextureFromSurface(display->renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return text2D;
}

void setText2DText(Display* display, Text2D* text2D, const char* text){
    
    text2D->text = (char*)realloc(text2D->text, sizeof(char)*(strlen(text)+1));
    strcpy(text2D->text, text);

    SDL_Surface* textSurface = TTF_RenderText_Blended(getFont("minecraft"), text2D->text, SDLC_WHITE);
    if(ISNULL(textSurface)){
        printf("nao foi possivel setar valor de label\n");
        return;
    }
    
    SDL_DestroyTexture(text2D->textureText);
    text2D->textureText = SDL_CreateTextureFromSurface(display->renderer, textSurface);    
    SDL_FreeSurface(textSurface);
    
}

void setText2DPosition(Text2D* text2D, int x, int y) {
    setVector2D(&text2D->position, x, y);
}

void setText2DUpdateCallback(Text2D* text2D, ObjectUpdateCallback update) {
    text2D->Events.update = update;
}

void renderText2D(Display* display, Text2D* text2D){
    SDL_Rect rect = {
        .x = text2D->position.x,
        .y = text2D->position.y,
        .w = text2D->size.x,
        .h = text2D->size.y
    };
    SDL_RenderCopy(display->renderer, text2D->textureText, NULL, &rect);
}