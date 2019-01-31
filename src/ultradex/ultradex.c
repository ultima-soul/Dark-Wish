#include <pokeagb/pokeagb.h>
#include "../global.h"
#include "ultradex.h"

static struct UltraDexState** UltraDexPtr = (struct UltraDexState**)(ULTRADEX_START);
extern void BuildGradient(u16 startColor, u16 stopColor);
extern void BuildGradientPalette(void);
extern void BuildMosaic(void* charbase, void* mapbase);
extern void Setup(void);
extern void C2DexnavGui(void);
extern void VblankSPQ(void);
extern void HBlankCBUltraDex(void);
extern void SpawnPageOneIcons(void);
extern void SpawnPageTwoIcons(void);
extern void SpawnUltraDexCursor(void);
extern void SpawnUltraDexPageTracker(void);
extern void ShowUltraDexObjects(u8 page);
extern void UpdateUltraDexCursor(void);
extern void TransitionPage1(void);
extern void TransitionPage2(void);


/* Entry point into the Ultradex */
u8 LaunchUltraDex()
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0x0000);
    void C1UltraDexBoot(void);
    SetMainCallback(C1UltraDexBoot);
    gMain.state = 0;
    return true;
}


const struct BgConfig BGConfigUDex[4] = {
    {
        .padding = 0,
        .b_padding = 0,
        .priority = 0,
        .palette = 0,
        .size = 0,
        .map_base = 31,
        .character_base = 0,
        .bgid = 0,
    },
    {
        .padding = 0,
        .b_padding = 0,
        .priority = 1,
        .palette = 0,
        .size = 0,
        .map_base = 30,
        .character_base = 1,
        .bgid = 1,
    },
    {
        .padding = 0,
        .b_padding = 0,
        .priority = 2,
        .palette = 0,
        .size = 0,
        .map_base = 29,
        .character_base = 2,
        .bgid = 2,
    },
    {
        .padding = 0,
        .b_padding = 0,
        .priority = 3,
        .palette = 0,
        .size = 0,
        .map_base = 28,
        .character_base = 3,
        .bgid = 3,
    },
};


struct TextboxTemplate UDexTextTemplate[] = {
    {
        /* Current open application in Top Left */
        .bg_id = 0,
        .x = 1,
        .y = 0,
        .width = 9,
        .height = 2,
        .pal_id = 15,
        .charbase = 1,
    },
    {
        /* Time */
        .bg_id = 0,
        .x = 26,
        .y = 0,
        .width = 6,
        .height = 2,
        .pal_id = 15,
        .charbase = 31,
    },
    {
        /* Current Selected Application */
        .bg_id = 0,
        .x = 12,
        .y = 10,
        .width = 12,
        .height = 3,
        .pal_id = 15,
        .charbase = 61,
    },
    {
        /* Application desc text */
        .bg_id = 0,
        .x = 1,
        .y = 16,
        .width = 32,
        .height = 6,
        .pal_id = 15,
        .charbase = 121,
    },
    {
        .bg_id = 0xFF, /* marks the end of the tb array */
    },
};


void UltraDexSetup()
{
    Setup();
    rboxes_free();
    bg_vram_setup(0, (struct BgConfig *)&BGConfigUDex, 4);
    u32 set = 0;
    CpuFastSet((void*)&set, (void*)ADDR_VRAM, CPUModeFS(0x10000, CPUFSSET));
    gpu_sync_bg_hide(3);
    gpu_sync_bg_hide(2);
    gpu_sync_bg_hide(1);
    gpu_sync_bg_hide(0);
    SetMainCallback2(C2DexnavGui);
    SetVBlankCallback(VblankSPQ);
}


void UpdateTimeText()
{
    rboxid_clear_pixels(1, 0);
    // time
    u8 hours = 0;
    u8 mins = 0;
    pchar colon[] = _(":");
    pchar charZero[] = _("0");

    GetClockTime(&hours, &mins);
    if (hours < 10) {
        // pad 0
        pstrcpy(string_buffer, charZero);
    } else {
        string_buffer[0] = 0xFF;
    }
    fmt_int_10(string_buffer + 20, hours, 0, 4);
    pstrcat(string_buffer, string_buffer + 20);
    pstrcat(string_buffer, colon);

    if (mins < 10) {
        // pad 0
        pstrcpy(string_buffer + 3, charZero);
        fmt_int_10(string_buffer + 4, mins, 0, 4);
    } else {
        fmt_int_10(string_buffer + 3, mins, 0, 4);
    }
    rboxid_print(1, 1, 0, 2, &textWhite, 0, string_buffer);
    rboxid_update(1, 3);
    rboxid_tilemap_update(1);
}


void UpdateAppHeaderText()
{
    // currently open app name
    rboxid_clear_pixels(0, 0);
    rboxid_print(0, 1, 0, 2, &textWhite, 0, DexApps[gUltraDex->currentOpenApp].appName);
    rboxid_update(0, 3);
    rboxid_tilemap_update(0);
    // time
    UpdateTimeText();
}

void UpdateSelectedAppText()
{
    // currently selected app name
    rboxid_clear_pixels(2, 0);
    rboxid_clear_pixels(3, 0);
    rboxid_print(2, 1, 6, 2, &textWhite, 0, DexApps[gUltraDex->selectedAppIndex + 1].appName);
    rboxid_print(3, 1, 3, 0, &textWhite, 0, DexApps[gUltraDex->selectedAppIndex + 1].appDescription);
    rboxid_update(2, 3);
    rboxid_tilemap_update(2);
    rboxid_update(3, 3);
    rboxid_tilemap_update(3);
}


void C1UltraDexBoot()
{
    switch(gMain.state) {
        case 0:
            if (!gPaletteFade.active) {
                m4aMPlayVolumeControl(&mplay_BGM, 0xFFFF, 128);
                UltraDexSetup();
                SetMainCallback(C1UltraDexBoot); // setup resets all CBs
                // allocate ultradex
                gUltraDex = (struct UltraDexState*)malloc_and_clear(sizeof(struct UltraDexState));
                gUltraDex->sharedGfx = (struct UltraDexSharedGraphics*)malloc_and_clear(sizeof(struct UltraDexSharedGraphics));
                gUltraDex->selectedAppIndex = 0;
                gMain.state++;
            }
            break;
        case 1:
        {
            // build bg graphics
            void *char_base = (void*) 0x6000000 + (0x4000 * 0);
            void *map_base = (void*) 0x6000000 + (0xF800 - (0x800 * 0));
            BuildMosaic(char_base + 0x4000, map_base - 0x800);
            gMain.state++;
            break;
        }
        case 2:
        {
            // update text
            rbox_init_from_templates(UDexTextTemplate);
            // for (u8 i = 0; i < sizeof(gUltraDex->sharedGfx->textboxes); i++) {
            //     rboxid_clear_pixels(i, 0);
            // }
            UpdateAppHeaderText();
            UpdateSelectedAppText();
            // display committed gfx
            // for (u8 i = 0; i < 5; i++) {
            //     rboxid_update(i, 3);
            //     rboxid_tilemap_update(i);
            // }
            gMain.state++;
            break;
        }
        case 3:
            SpawnUltraDexCursor();
            SpawnPageOneIcons();
            SpawnPageTwoIcons();
            SpawnUltraDexPageTracker();
            gMain.state++;
            break;
        case 4:
            BuildGradient(0x71ED, 0x6791);
            BuildGradientPalette();
            gpu_pal_apply(gUltraDex->sharedGfx->gradient_palette, 0, 32);
            memset(gUltraDex->sharedGfx->gradient_palette, 0, 32 * 20);
            SetHBlankCallback(HBlankCBUltraDex);
            interrupts_enable(INTERRUPT_VBLANK | INTERRUPT_HBLANK);
            gMain.state++;
            break;
        case 5:
            bgid_mark_for_sync(0);
            bgid_mark_for_sync(1);
            bgid_mark_for_sync(2);
            bgid_mark_for_sync(3);
            gpu_sync_bg_show(0);
            gpu_sync_bg_show(1);
            gpu_sync_bg_show(2);
            gpu_sync_bg_show(3);
            ShowUltraDexObjects(gUltraDex->page);
            ShowUltraDexObjects(1);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0x0000);
            gMain.state++;
            break;
        case 6:
            if (!gPaletteFade.active) {
                gMain.state++;
            } else {
                BuildGradientPalette();
            }
            break;
        case 7:
            // handle input
            {
                void C1UltraDexInteractionHandler(void);
                SetMainCallback(C1UltraDexInteractionHandler);
                gMain.state = 0;
                break;
            }
    };
}


void C1UltraDexInteractionHandler()
{
    UpdateTimeText();
    switch (gMain.heldKeys & (KEY_A | KEY_B | KEY_LEFT | KEY_RIGHT)) {
        case KEY_A:
            // run selected app
            break;
        case KEY_B:
            // exit to start menu
            break;
        case KEY_LEFT:
            // move cursor right once
            gUltraDex->selectedAppIndex--;
            if (gUltraDex->selectedAppIndex < 0) {
                // make error noise
                audio_play(SOUND_RSE_BERRY_MIX_CLICK);
                gUltraDex->selectedAppIndex++;
                return;
            } else if (gUltraDex->selectedAppIndex < APPS_PER_PAGE && gUltraDex->page) {
                // we need to go to page 1
                gUltraDex->page--;
                gSprites[gUltraDex->cursorObjId].invisible = true;
                TransitionPage1();
                UpdateSelectedAppText();
                UpdateUltraDexCursor();
                SetMainCallback(NULL);
            } else {
                UpdateSelectedAppText();
                UpdateUltraDexCursor();
            }
            break;
        case KEY_RIGHT:
            // move cursor left once
            gUltraDex->selectedAppIndex++;
            if (gUltraDex->selectedAppIndex == APPS_COUNT-1) {
                // make error noise
                gUltraDex->selectedAppIndex--;
                audio_play(SOUND_RSE_BERRY_MIX_CLICK);
                return;
            } else if (gUltraDex->selectedAppIndex > (APPS_PER_PAGE - 1) && !gUltraDex->page) {
                // we need to go to page 2
                gUltraDex->page++;
                gSprites[gUltraDex->cursorObjId].invisible = true;
                TransitionPage2();
                UpdateSelectedAppText();
                UpdateUltraDexCursor();
                SetMainCallback(NULL);
            } else {
                UpdateSelectedAppText();
                UpdateUltraDexCursor();
            }
            break;
        default:
            return;
    };
    audio_play(SOUND_GENERIC_CLINK);
}
