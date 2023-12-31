/*
*/
#include "window.h"

/*
    Create basic window
*/
Graphics::Window::Window(std::string title, int x, int y, int width, int height){
    this->title;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

/*
    Timed dialog window 
*/
Graphics::Window::Window(std::string person, std::string caption, int x, int y, int width, int height, int seconds){
    this->title = person;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    Text* personText = new Text(std::string{person + ": " + caption}, 0, height - 2);
    this->AddText(personText);
    this->isTimed = true;
    this->time = seconds;
}


void Graphics::Window::AddText(Text* t){
    this->texts.push_back(t);
}

void Graphics::Window::AddButton(Button* b){
    this->buttons.push_back(b);
    UpdateSelection(1);
}

void Graphics::Window::AddImage(Image* i){
    this->images.push_back(i);
}

bool Graphics::Window::InputButtons(char c){
    if(c == '\n'){
        if(this->buttons[currentButton]->onClick)
        this->buttons[currentButton]->onClick();
        else // Assume to be quit
        this->CloseWindow();

        return true;
    }
    if(c == 27){
        if (read(STDIN_FILENO, &c, 1) == 1 && read(STDIN_FILENO, &c, 1) == 1) {
            switch (c) {
                case 'C':
                    UpdateSelection(1);
                    return true;
                    break;
                case 'D':
                    UpdateSelection(0);
                    return true;
                    break;
            }
        }
    }
    return false;
}

void Graphics::Window::UpdateSelection(int u){
    if(buttons.size() > 1){
        this->buttons[currentButton]->isSelected = false;
        int nextInd = currentButton;
        if(u == 1) nextInd++;
        else nextInd--;
        if(nextInd > buttons.size() - 1)nextInd = 0;
        if(nextInd < 0)nextInd = buttons.size() -1;
        this->buttons[nextInd]->isSelected = true;
        currentButton = nextInd;
    }
}


void Graphics::Window::CloseWindow(){
    this->exist = false;
}