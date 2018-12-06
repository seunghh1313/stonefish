//
//  IMGUI.h
//  Stonefish
//
//  Created by Patryk Cieslak on 11/27/12.
//  Copyright (c) 2012-2018 Patryk Cieslak. All rights reserved.
//

#ifndef __Stonefish_IMGUI__
#define __Stonefish_IMGUI__

#include <SDL2/SDL_keyboard.h>
#include "StonefishCommon.h"
#include "graphics/OpenGLDataStructs.h"

//interface colors
#define PANEL_COLOR 0                 //Panel/background
#define ACTIVE_TEXT_COLOR 1           //Label, title....
#define INACTIVE_TEXT_COLOR 2
#define ACTIVE_CONTROL_COLOR 3        //Button, slider...
#define INACTIVE_CONTROL_COLOR 4
#define HOT_CONTROL_COLOR 5
#define PUSHED_CONTROL_COLOR 6
#define EMPTY_COLOR 7                 //Slider, progress, checkbox, radio...
#define FILLED_COLOR 8
#define PLOT_COLOR 9                  //Plots
#define PLOT_TEXT_COLOR 10
#define CORNER_RADIUS 5.f

namespace sf
{
    //!
    struct ui_id
    {
        int owner;
        int item;
        int index;
    };
    
    class GLSLShader;
    class OpenGLPrinter;
    class ScalarSensor;
    
    //!
    class IMGUI
    {
    public:
        IMGUI(GLint windowWidth, GLint windowHeight, GLfloat hue = 0.52f);
        ~IMGUI();
        
        void Resize(GLint windowWidth, GLint windowHeight);
        void GenerateBackground();
        void Begin();
        void End();
        bool MouseInRect(int x, int y, int w, int h);
        bool MouseIsDown(bool leftButton);
        
        ui_id getHot();
        ui_id getActive();
        void setHot(ui_id newHot);
        void setActive(ui_id newActive);
        bool isHot(ui_id ID);
        bool isActive(ui_id ID);
        bool isAnyActive();
        void clearActive();
        void clearHot();
        int getWindowHeight();
        int getWindowWidth();
        int getMouseX();
        int getMouseY();
        GLuint getTranslucentTexture();
        
        //input handling
        void MouseDown(int x, int y, bool leftButton);
        void MouseUp(int x, int y, bool leftButton);
        void MouseMove(int x, int y);
        void KeyDown(SDL_Keycode key);
        void KeyUp(SDL_Keycode key);
        
        //widgets
        //passive
        void DoPanel(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
        void DoLabel(GLfloat x, GLfloat y, const char* text, GLfloat* color = NULL);
        void DoProgressBar(GLfloat x, GLfloat y, GLfloat w, Scalar progress, const char* title);
        //active
        bool DoButton(ui_id ID, GLfloat x, GLfloat y, GLfloat w, GLfloat h, const char* title);
        Scalar DoSlider(ui_id ID, GLfloat x, GLfloat y, GLfloat w, Scalar min, Scalar max, Scalar value, const char* title);
        bool DoCheckBox(ui_id ID, GLfloat x, GLfloat y, GLfloat w, bool value, const char* title);
        bool DoTimePlot(ui_id ID, GLfloat x, GLfloat y, GLfloat w, GLfloat h, ScalarSensor* sens, std::vector<unsigned short>& dims, const char* title, Scalar fixedRange[2] = NULL);
        bool DoXYPlot(ui_id ID, GLfloat x, GLfloat y, GLfloat w, GLfloat h, ScalarSensor* sensX, unsigned short dimX, ScalarSensor* sensY, unsigned short dimY, const char* title);
        
    private:
        void DrawPlainText(GLfloat x, GLfloat y, glm::vec4 color, const char* text);
        GLfloat PlainTextLength(const char* text);
        glm::vec2 PlainTextDimensions(const char* text);
        void DrawRoundedRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h, glm::vec4 color = glm::vec4(1));
        void DrawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h, glm::vec4 color = glm::vec4(1));
        
        GLint windowW,windowH;
        bool shaders;
        int mouseX, mouseY;
        bool mouseLeftDown, mouseRightDown;
        ui_id hot;
        ui_id active;
        
        OpenGLPrinter* plainPrinter;
        GLuint logoTexture;
        GLuint guiTexture;
        glm::vec4 theme[11];
        GLfloat backgroundMargin;
        
        //Translucent background
        GLuint guiVAO;
        GLuint translucentFBO;
        GLuint translucentTexture[2];
        GLSLShader* downsampleShader;
        GLSLShader* gaussianShader;
        GLSLShader* guiShader[2];
    };
}

#endif
