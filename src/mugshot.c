#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

static const u32 sMugshotImg_Amneet[] = INCBIN_U32("graphics/mugshots/amneet.4bpp.lz");
static const u16 sMugshotPal_Amneet[] = INCBIN_U16("graphics/mugshots/amneet.gbapal");
static const u32 sMugshotImg_Angelina[] = INCBIN_U32("graphics/mugshots/angelina.4bpp.lz");
static const u16 sMugshotPal_Angelina[] = INCBIN_U16("graphics/mugshots/angelina.gbapal");
static const u32 sMugshotImg_Bobby[] = INCBIN_U32("graphics/mugshots/bobby.4bpp.lz");
static const u16 sMugshotPal_Bobby[] = INCBIN_U16("graphics/mugshots/bobby.gbapal");
static const u32 sMugshotImg_John[] = INCBIN_U32("graphics/mugshots/john.4bpp.lz");
static const u16 sMugshotPal_John[] = INCBIN_U16("graphics/mugshots/john.gbapal");
static const u32 sMugshotImg_Tilyou[] = INCBIN_U32("graphics/mugshots/tilyou.4bpp.lz");
static const u16 sMugshotPal_Tilyou[] = INCBIN_U16("graphics/mugshots/tilyou.gbapal");

static const struct Mugshot sMugshots[] = {
    [MUGSHOT_ANGELINA] = {.x = 16, .y = 5, .width = 24, .height = 24, .image = sMugshotImg_Angelina, .palette = sMugshotPal_Angelina},
    [MUGSHOT_AMNEET] = {.x = 3, .y = 4, .width = 64, .height = 80, .image = sMugshotImg_Amneet, .palette = sMugshotPal_Amneet},
    [MUGSHOT_BOBBY] = {.x = 0, .y = 4, .width = 88, .height = 80, .image = sMugshotImg_Bobby, .palette = sMugshotPal_Bobby},
    [MUGSHOT_JOHN] = {.x = 3, .y = 3, .width = 80, .height = 88, .image = sMugshotImg_John, .palette = sMugshotPal_John},
    [MUGSHOT_TILYOU] = {.x = 3, .y = 3, .width = 72, .height = 88, .image = sMugshotImg_Tilyou, .palette = sMugshotPal_Tilyou},
};


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}