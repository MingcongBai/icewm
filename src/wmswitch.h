#ifndef __SWITCH_H
#define __SWITCH_H

#include "ymenu.h"

class YFrameWindow;

class SwitchWindow: public YPopupWindow {
public:
    SwitchWindow(YWindow *parent = 0);
    virtual ~SwitchWindow();

    virtual void paint(Graphics &g, int x, int y, unsigned int width, unsigned int height);

    YFrameWindow *nextWindow(YFrameWindow *from, bool zdown, bool next);
    void begin(bool zdown, int mods);

    virtual void activatePopup();
    virtual void deactivatePopup();
    
    virtual bool handleKey(const XKeyEvent &key);
    virtual void handleButton(const XButtonEvent &button);

    void destroyedFrame(YFrameWindow *frame);

    void cancel();
    void accept();
    void displayFocus(YFrameWindow *frame);
private:
    YFrameWindow *fActiveWindow;
    YFrameWindow *fLastWindow;

    static YColor *switchFg;
    static YColor *switchBg;
    static YFont *switchFont;

    int modsDown;

    bool isUp;

    bool modDown(int m);
    bool isModKey(KeyCode c);
};

extern SwitchWindow *switchWindow;

extern YPixmap *switchbackPixmap;

#endif
