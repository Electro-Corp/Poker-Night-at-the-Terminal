#include "screen.h"

//

Graphics::Screen::Screen(std::string title){
    updateDim();

    // Copy title
    this->title = title;

    // Clear screen
    system("clear");


}   

void Graphics::Screen::AddWindow(Window* window){
    window->index = windows.size();
    if(!window->isTimed) // Make sure its not a timed window
        currentContext = window->index; // Newest added window is current one
    this->windows.push_back(window);
}

int prev = 0;
void Graphics::Screen::Refresh(){
    // Somethings got to be off, check
    for(int i = 0; i < windows.size(); i++){
        if(!windows[i]->exist){
            windows.erase(std::next(windows.begin(), i));
            break;
        }
    }
    // Check if a window got removed
    if(prev != windows.size()){
        prev = windows.size();
        if(!windows[prev -1]->isTimed)
            currentContext = prev - 1;
    }
    // Check if the window changed
    if(updateDim() != 1){
        // Clear screen
        system("clear");
        Display();
    }
}

void Graphics::Screen::Display(){
    printf("\033[2J");
    system("clear");
    // Render Screen titlebar
    printAt((width / 2) - (title.length() / 2) - 1, 0, title.c_str());

    for(int i = 0; i < windows.size(); i++){
        if(windows[i]->isTimed){
            if(time(NULL) - windows[i]->start > windows[i]->time){
                windows[i]->CloseWindow();
            }
        }
        if(windows[i]->exist){
            // Render windows   
            for(int y = windows[i]->y; y < windows[i]->height + windows[i]->y; y++){
                for(int x = windows[i]->x; x < windows[i]->width + windows[i]->x; x++){
                    if(i == currentContext)
                        printAt(x, y, " ", CURRENT_WIN);
                    else
                        printAt(x, y, " ");
                }
            }   

            for(Text* t: windows[i]->texts){
                printAt(t->x + windows[i]->x, t->y + windows[i]->y, t->text.c_str(), TEXT_BG);
            }

            for(Button* b : windows[i]->buttons){
                int w = b->width;
                if(b->text.length() > w) w = b->text.length();
                for(int y = b->y; y < b->height + b->y; y++){
                    for(int x = b->x; x < w + b->x; x++){
                        if(!b->isSelected)
                        printAt(x + windows[i]->x, y + windows[i]->y, " ", BUTTON_BG_NORMAL);
                        else
                        printAt(x + windows[i]->x, y + windows[i]->y, " ", BUTTON_BG_SELECTED);
                    }
                }
                printAt(b->x + windows[i]->x + (b->width / 2) - 1, b->y + windows[i]->y + (b->height / 2), b->text.c_str(), TEXT_BG);
            }

            for(Image* image : windows[i]->images){
                int wow = image->width;
                if(wow > windows[i]->width) wow = windows[i]->width;
                if(wow == 0)
                    wow = image->width;
                int y = image->y + windows[i]->y, x = image->x + windows[i]->x;
                for (int j = 0, c = 0; j < image->colorData.size() * 2; j++) {
                    printf("\033[%d;%dH",y, x++);
                    printf("\033[48;2;%d;%d;%dm ", image->colorData[c].r, image->colorData[c].g, image->colorData[c].b);
                    if (j % 2 == 0)
                        c++;
                    if (j % wow == 0){
                        y++;
                        if(y > windows[i]->height + 1)break;
                        x = image->x + windows[i]->x;
                    }
                }
            }
        }
    }
}



void Graphics::Screen::DialogBox(std::string title, std::string message){
    Window* winTmp = new Window(title, width / 2, height / 2, 20 + message.length(), 5);
    Text* tmp = new Text(message, winTmp->width / 2, winTmp->height / 2);
    Button* ok = new Button(std::string{"OK"}, tmp->x, tmp->y + 2, 3, 1, NULL);  
    winTmp->AddText(tmp);
    winTmp->AddButton(ok);
    this->AddWindow(winTmp);
    this->Display();
}


/*
    Create window with a timer to destruction
*/
void Graphics::Screen::CreateTimedWindow(std::string person, std::string text, std::string path, int t){
    Window* tmp = new Window(person, text, width / 2, height / 2, 110, 110, t);
    seconds = time(NULL);
    tmp->start = seconds;
    Image* tpmImg = new Image(path, 0, 0);
    tmp->AddImage(tpmImg);
    this->AddWindow(tmp);
}

bool Graphics::Screen::HandleInput(char c){
    if(c == '\t'){
        int tmp = currentContext + 1;
        if(tmp > windows.size() - 1) tmp = 0;
        currentContext = tmp;
        while(!windows[currentContext]->isTimed){
            int tmp = currentContext + 1;
            if(tmp > windows.size() - 1) tmp = 0;
            currentContext = tmp;
        }
        return true;
    }
    return (windows[currentContext])->InputButtons(c);
}


/*
    Internal funcs
*/
void Graphics::Screen::closeMostRecent(){
    windows[currentContext]->CloseWindow();
    currentContext--;
}
// Print a char at a position
void printChar(int x, int y, char c){
    printf("\033[%d;%dH",y , x);
    printf("\033[48;2;%d;%d;%dm %c  \033[48;2;0;0;0m", 100, 100, 100, c);
}

// Print a string at a specified position
void Graphics::Screen::printAt(int x, int y, const char* text, enum RenderColor c){
    printf("\033[%d;%dH",y , x);
    int r = 0, g = 0, b = 0;
    switch(c){
        case DEFAULT_GRAY:
            r = 100;
            b = 100;
            g = 100;
            break;
        
        case CURRENT_WIN:
            r = 120;
            b = 80;
            g = 120;
            break;

        case TEXT_BG:
            r = 130;
            b = 120;
            g = 120;
            break;

        case BUTTON_BG_NORMAL:
            r = 80;
            b = 80;
            g = 80;
            break;

        case BUTTON_BG_SELECTED:
            r = 100;
            b = 80;
            g = 80;
            break;
        
        default:
            r = 255;
            break;
    }
    printf("\033[48;2;%d;%d;%dm %s\033[48;2;0;0;0m", r, g, b, text);
    /*for(int i = 0; i < strlen(text); i++){
        printf("\033[%d;%dH",y , x + i);
        printf("\033[48;2;%d;%d;%dm%c\033[48;2;0;0;0m", r, g, b, text[i]);
    }*/
    fflush(stdout);
}



int Graphics::Screen::updateDim(){
     // Get window size
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    int oldW = width, oldY = height;

    this->width = size.ws_col;
    this->height = size.ws_row;

    return oldW == width && height == oldY;
}