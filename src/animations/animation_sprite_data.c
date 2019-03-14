#include <pokeagb\pokeagb.h>
#include "animation_sprite_macros.h"
#include "../../generated/images/battle_animations/impact1.h"
#include "../../generated/images/battle_animations/burn.h"
#include "../../generated/images/battle_animations/poison.h"
#include "../../generated/images/battle_animations/paralyze.h"
#include "../../generated/images/battle_animations/freeze.h"
#include "../../generated/images/battle_animations/confused.h"
#include "../../generated/images/battle_animations/infactuation.h"
#include "../../generated/images/battle_animations/sleep.h"
#include "../../generated/images/battle_animations/smoke.h"
#include "../../generated/images/battle_animations/glowball.h"
#include "../../generated/images/battle_animations/pokeball.h"
#include "../../generated/images/battle_animations/impact2.h"
#include "../../generated/images/battle_animations/impact2.h"
#include "../../generated/images/battle_animations/pokeballParticle.h"
#include "../../generated/images/battle_animations/starParticle.h"
#include "../../generated/images/battle_animations/yesno.h"
#include "../../generated/images/battle_animations/yesnoCursor.h"
#include "../../generated/images/battle_animations/fist.h"
#include "../../generated/images/battle_animations/circular.h"
#include "../../generated/images/battle_animations/bimpact1.h"
#include "../../generated/images/battle_animations/watersplash.h"
#include "../../generated/images/battle_animations/chop.h"
#include "../../generated/images/battle_animations/slap.h"
#include "../../generated/images/battle_animations/bigfist.h"
#include "../../generated/images/battle_animations/smallfire.h"
#include "../../generated/images/battle_animations/bigbluefist.h"
#include "../../generated/images/battle_animations/lightningbolt.h"
#include "../../generated/images/battle_animations/yellowfist.h"
#include "../../generated/images/battle_animations/vicegrip.h"
#include "../../generated/images/battle_animations/guillotine.h"
#include "../../generated/images/battle_animations/guillotineLeft.h"
#include "../../generated/images/battle_animations/tornadopiece.h"
#include "../../generated/images/battle_animations/impact3.h"


/* the impact sprite from tackle */
ASSETS(impact1, s32x32, 400);

MAKE_OAM(impact1)
    OAM_PRIORITY(3)
    OAM_SIZE(o32x32)
END_OAM()


/* the burn animation sprite */
ASSETS(burn, s16x32, 401);

MAKE_OAM(burn)
    OAM_AFFINE()
    OAM_SHAPE(TALL)
    OAM_SIZE(o16x32)
    OAM_PRIORITY(1)
END_OAM()

// burn sprite to shrink
BEGIN_AFFINE_ANIM(burn)
    PLAY_AFFINE(-20, -20, 0, 10)
END_AFFINE()


/* poison ailment sprite */
ASSETS(poison, s16x16, 402);

MAKE_OAM(poison)
    OAM_SIZE(o16x16)
    OAM_PRIORITY(1)
END_OAM()


/* paralyze ailment sprite */
ASSETS(paralyze, s32x32 * 3, 403);

MAKE_OAM(paralyze)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_FRAME_ANIM(paralyzeFrames)
    SHOW_FRAME(0, s32x16, NOFLIP, 5)
    SHOW_FRAME(1, s32x16, NOFLIP, 5)
    SHOW_FRAME(4, s32x8, NOFLIP, 5)
    SHOW_FRAME(5, s32x8, NOFLIP, 5)
    SHOW_FRAME(6, s32x8, NOFLIP, 5)
    SHOW_FRAME(8, s32x8, NOFLIP, 5)
    JUMP_FRAME(0)
END_ANIM()


/* freeze ailment sprite */
ASSETS(freeze, s32x32, 404);

MAKE_OAM(freeze)
    OAM_PRIORITY(3)
    OAM_SIZE(o32x32)
    OAM_AFFINE()
END_OAM()

// freeze sprite to grow
BEGIN_AFFINE_ANIM(freeze)
    PLAY_AFFINE(-200, -200, 0, 1)
    PLAY_AFFINE(10, 10, 0, 15)
    PLAY_AFFINE(0, 0, 0, 10)
END_AFFINE()

// freeze sprite grow slow and rotate slow
BEGIN_AFFINE_ANIM(freeze2)
    PLAY_AFFINE(-200, -200, 0, 1)
    PLAY_AFFINE(5, 5, 5, 20)
END_AFFINE()


/* confused sprite */
ASSETS(confused, s16x16 * 3, 405);

MAKE_OAM(confused)
    OAM_PRIORITY(1)
    OAM_SIZE(o16x16)
END_OAM()

BEGIN_FRAME_ANIM(confusedFrames)
    SHOW_FRAME(0, s16x16, NOFLIP, 20)
    SHOW_FRAME(1, s16x16, NOFLIP, 20)
    SHOW_FRAME(2, s16x16, NOFLIP, 20)
    JUMP_FRAME(0)
END_ANIM()


/* infactuation sprite */
ASSETS(infactuation, s16x16, 406);

MAKE_OAM(infactuation)
    OAM_SIZE(o16x16)
    OAM_PRIORITY(1)
END_OAM()


/* Sleep sprite */
ASSETS(sleep, s32x32, 407);

MAKE_OAM(sleep)
    OAM_AFFINE()
    OAM_SIZE(o32x32)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_AFFINE_ANIM(sleep)
    PLAY_AFFINE(-150, -150, -30, 1)
    PLAY_AFFINE(2, 2, 2, 5)
    PLAY_AFFINE(0, 0, 8, 0)
    PLAY_AFFINE(2, 2, 2, 5)
    PLAY_AFFINE(0, 0, 8, 0)
    PLAY_AFFINE(2, 2, 2, 5)
    PLAY_AFFINE(0, 0, 8, 0)
END_AFFINE()


/* Smoke sprite */
ASSETS(smoke, s32x32 * 3, 408);

MAKE_OAM(smoke)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_FRAME_ANIM(smokeFrames)
    SHOW_FRAME(0, s32x32, NOFLIP, 5)
    SHOW_FRAME(1, s32x32, NOFLIP, 5)
    SHOW_FRAME(2, s32x32, NOFLIP, 5)
END_ANIM()


/* glowball sprite */
ASSETS(glowball, s16x16, 409);

MAKE_OAM(glowball)
    OAM_AFFINE()
    OAM_SIZE(o16x16)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_AFFINE_ANIM(glowball)
    PLAY_AFFINE(0, 0, 0, 1)
    PLAY_AFFINE(-10, -10, 0, 30)
END_AFFINE()

BEGIN_AFFINE_ANIM(glowballSmaller)
    PLAY_AFFINE(-100, -100, 0, 1)
    PLAY_AFFINE(-10, -10, 0, 20)
END_AFFINE()

BEGIN_AFFINE_ANIM(glowballRev)
    PLAY_AFFINE(-300, -300, 0, 1)
    PLAY_AFFINE(10, 10, 0, 30)
END_AFFINE()


/* pokeball sprite */
ASSETS(pokeball, s16x16 * 3, 410);

MAKE_OAM(pokeball)
    OAM_AFFINE()
    OAM_SIZE(o16x16)
    OAM_PRIORITY(1)
END_OAM()

const struct Frame pokeballOpen[] = {
    SHOW_FRAME(0, s16x16, NOFLIP, 5)
    SHOW_FRAME(1, s16x16, NOFLIP, 5)
    STOP_ANIM()
};

const struct Frame pokeballClose[] = {
    SHOW_FRAME(1, s16x16, NOFLIP, 5)
    SHOW_FRAME(0, s16x16, NOFLIP, 5)
    STOP_ANIM()
};

const struct Frame* pokeballFrames[] = {
    pokeballOpen,
    pokeballClose,
};
const struct Frame* pokeballOpenPtr[] = {pokeballOpen};

BEGIN_AFFINE_ANIM(pokeballLeftTilt)
    PLAY_AFFINE(0, 0, 0, 1)
    PLAY_AFFINE(0, 0, -6, 5)
    PLAY_AFFINE(0, 0, 0, 5)
    PLAY_AFFINE(0, 0, 6, 5)
    PLAY_AFFINE(0, 0, 6, 3)
    PLAY_AFFINE(0, 0, 0, 3)
    PLAY_AFFINE(0, 0, -6, 3)
END_AFFINE()

BEGIN_AFFINE_ANIM(pokeballRightTilt)
    PLAY_AFFINE(0, 0, 0, 1)
    PLAY_AFFINE(0, 0, 6, 5)
    PLAY_AFFINE(0, 0, 0, 5)
    PLAY_AFFINE(0, 0, -6, 5)
    PLAY_AFFINE(0, 0, -6, 3)
    PLAY_AFFINE(0, 0, 0, 3)
    PLAY_AFFINE(0, 0, 6, 3)
END_AFFINE()


/* impact2 sprite */
ASSETS(impact2, s16x16, 411);

MAKE_OAM(impact2)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(3)
END_OAM()


/* Pokeball particles when opened or closed */
ASSETS(pokeballParticle, s8x8 * 3, 412);

MAKE_OAM(pokeballParticle)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_FRAME_ANIM(pokeballParticleFrames)
    SHOW_FRAME(0, s8x8, NOFLIP, 5)
    SHOW_FRAME(1, s8x8, NOFLIP, 5)
    SHOW_FRAME(2, s8x8, NOFLIP, 5)
    JUMP_FRAME(0)
END_ANIM()


/* Pokeball capture sucess stars particle */
ASSETS(starParticle, s8x8, 413);

MAKE_OAM(starParticle)
END_OAM()


/* Yes no choice box for..whatever choices */
ASSETS(yesno, s64x64, 414);

MAKE_OAM(yesno)
    OAM_SIZE(o64x64)
    OAM_PRIORITY(1)
END_OAM()


/* a cursor meant for the yesno box */
ASSETS(yesnoCursor, s16x16, 415);

MAKE_OAM(yesnoCursor)
    OAM_SIZE(o16x16)
    OAM_PRIORITY(0)
END_OAM()


/* fist sprite */
ASSETS(fist, s32x32, 416);

MAKE_OAM(fist)
    OAM_PRIORITY(3)
    OAM_AFFINE()
    OAM_SIZE(o32x32)
END_OAM()

MAKE_OAM(fist2)
    OAM_PRIORITY(1)
    OAM_AFFINE()
    OAM_SIZE(o32x32)
END_OAM ()

BEGIN_AFFINE_ANIM(fist)
    PLAY_AFFINE(-100, -100, 0, 1)
    PLAY_AFFINE(20, 20, 0, 8)
END_AFFINE()

BEGIN_AFFINE_ANIM(fist2)
    PLAY_AFFINE(0, 0, 3, 5)
END_AFFINE()

BEGIN_AFFINE_ANIM(fist3)
    PLAY_AFFINE(-450, -450, 0, 1)
    PLAY_AFFINE(6, 6, -7, 24)
END_AFFINE()


/* circular sprite */
ASSETS(circular, s16x16, 417);

MAKE_OAM(circular)
    OAM_AFFINE()
    OAM_PRIORITY(3)
    OAM_SIZE(o16x16)
END_OAM()

BEGIN_AFFINE_ANIM(circular)
    PLAY_AFFINE(8, 8, 0, 32)
END_AFFINE()


/* the impact sprite from tackle - but white for blendability */
ASSETS(bimpact1, s32x32, 418);

MAKE_OAM(bimpact1)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(3)
END_OAM()


/* a splash of dispersing water */
ASSETS(watersplash, s64x64 * 4, 419);

MAKE_OAM(watersplash)
    OAM_SIZE(o64x64)
    OAM_PRIORITY(2)
END_OAM()

BEGIN_FRAME_ANIM(watersplashFrames)
    SHOW_FRAME(0, s64x64, NOFLIP, 5)
    SHOW_FRAME(1, s64x64, NOFLIP, 5)
    SHOW_FRAME(2, s64x64, NOFLIP, 5)
    SHOW_FRAME(3, s64x64, NOFLIP, 5)
    JUMP_FRAME(0)
END_ANIM()


/* Chop hand from Karate chop */
ASSETS(chop, s32x32 * 2, 420);

MAKE_OAM(chop)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(1)
END_OAM()

BEGIN_FRAME_ANIM(chopLeftFrames)
    SHOW_FRAME(1, 16, NOFLIP, 1)
END_ANIM()


/* Slap hand from double slap */
ASSETS(slap, s32x32 * 3, 421);

MAKE_OAM(slap)
    OAM_SIZE(o32x32)
    OAM_PRIORITY(3)
END_OAM()

BEGIN_FRAME_ANIM(slapFrames)
    SHOW_FRAME(0, s32x32, NOFLIP, 12)
    SHOW_FRAME(1, s32x32, NOFLIP, 4)
    SHOW_FRAME(2, s32x32, NOFLIP, 12)
    SHOW_FRAME(2, s32x32, NOFLIP, 12)
    SHOW_FRAME(1, s32x32, NOFLIP, 4)
    SHOW_FRAME(0, s32x32, NOFLIP, 12)
END_ANIM()


/* Big red fist from mega punch, and blue fist from ice punch */
ASSETS(bigfist, s64x64, 422);
ASSETS(bigbluefist, s64x64, 424);

MAKE_OAM(bigfist)
    OAM_AFFINE()
    OAM_SIZE(o64x64)
    OAM_PRIORITY(2)
END_OAM()

BEGIN_AFFINE_ANIM(bigfistShrink)
    PLAY_AFFINE(-140, -140, 0, 1)
END_AFFINE()


/* The small fire from fire punch */
ASSETS(smallfire, s16x32 * 4, 423);

MAKE_OAM(smallfire)
    OAM_SHAPE(TALL)
    OAM_SIZE(o16x32)
    OAM_PRIORITY(2)
END_OAM()

MAKE_OAM(smallfireAff)
    OAM_AFFINE()
    OAM_SHAPE(TALL)
    OAM_SIZE(o16x32)
    OAM_PRIORITY(3)
END_OAM()

BEGIN_FRAME_ANIM(smallfireFrames)
    SHOW_FRAME(0, s16x32, NOFLIP, 5)
    SHOW_FRAME(1, s16x32, NOFLIP, 5)
    SHOW_FRAME(2, s16x32, NOFLIP, 5)
    SHOW_FRAME(3, s16x32, NOFLIP, 5)
    JUMP_FRAME(0)
END_ANIM()

BEGIN_AFFINE_ANIM(smallfire)
    PLAY_AFFINE(-6, -6, 0, 20)
END_AFFINE()


/* Lightning bolt */
ASSETS(lightningbolt, s32x32 * 2, 425);

MAKE_OAM(lightningbolt)
    OAM_AFFINE()
    OAM_SIZE(o32x32)
    OAM_PRIORITY(3)
END_OAM()

BEGIN_FRAME_ANIM(lightningboltFrames)
    SHOW_FRAME(0, s32x32, NOFLIP, 2)
    SHOW_FRAME(1, s32x32, NOFLIP, 2)
    JUMP_FRAME(0)
END_ANIM()


/* Yellow fist sprite from thunder punch */
ASSETS(yellowfist, s64x64, 426);

MAKE_OAM(yellowfist)
    OAM_AFFINE()
    OAM_SIZE(o64x64)
END_OAM()

BEGIN_AFFINE_ANIM(bigfistShrinkSlowly)
    PLAY_AFFINE(0, 0, 0, 8)
    PLAY_AFFINE(-100, -100, 0, 1)
    PLAY_AFFINE(0, 0, 0, 28)
END_AFFINE()


/* Vicegrip graphic */
ASSETS(vicegrip, s32x32 * 3, 427);

MAKE_OAM(vicegrip)
    OAM_PRIORITY(2)
    OAM_SIZE(o32x32)
END_OAM()

MAKE_OAM(vicegripFlip)
    OAM_PRIORITY(2)
    OAM_HFLIP()
    OAM_VFLIP()
    OAM_SIZE(o32x32)
END_OAM()

BEGIN_FRAME_ANIM(vicegripFrame)
    SHOW_FRAME(0, s32x32, NOFLIP, 2)
    SHOW_FRAME(1, s32x32, NOFLIP, 2)
    SHOW_FRAME(2, s32x32, NOFLIP, 2)
END_ANIM()

BEGIN_FRAME_ANIM(vicegripFlipFrame)
    SHOW_FRAME(0, s32x32, HVFLIP, 2)
    SHOW_FRAME(1, s32x32, HVFLIP, 2)
    SHOW_FRAME(2, s32x32, HVFLIP, 2)
END_ANIM()


/* Guillotine */
ASSETS(guillotine, s64x64, 428);
ASSETS(guillotineLeft, s64x64, 429);

MAKE_OAM(guillotine)
    OAM_AFFINE()
    OAM_PRIORITY(3)
    OAM_SIZE(o64x64)
END_OAM()

BEGIN_AFFINE_ANIM(guillotineGrow)
    PLAY_AFFINE(-100, -140, 0, 1)
    PLAY_AFFINE(5, 7, 0, 20)
END_AFFINE()

BEGIN_AFFINE_ANIM(guillotineTiltLeft)
    PLAY_AFFINE(0, 0, 1, 40)
END_AFFINE()

BEGIN_AFFINE_ANIM(guillotineTiltRight)
    PLAY_AFFINE(0, 0, -1, 40)
END_AFFINE()


/* Razor wind whip up */
ASSETS(tornadopiece, s64x64 * 4, 430);

MAKE_OAM(tornadopiece)
    OAM_AFFINE()
    OAM_PRIORITY(2)
    OAM_SIZE(o64x64)
END_OAM()

MAKE_OAM(tornadopieceAttack)
    OAM_PRIORITY(2)
    OAM_SIZE(o64x64)
END_OAM()

BEGIN_FRAME_ANIM(tornadopieceFrame)
    SHOW_FRAME(0, s64x64, NOFLIP, 3)
    SHOW_FRAME(1, s64x64, NOFLIP, 3)
    SHOW_FRAME(2, s64x64, NOFLIP, 3)
    SHOW_FRAME(3, s64x64, NOFLIP, 3)
    JUMP_FRAME(0)
END_ANIM()

BEGIN_AFFINE_ANIM(tornadopiece)
    PLAY_AFFINE(180, 180, 0, 1)
    PLAY_AFFINE(-12, -12, 0, 30)
    PLAY_AFFINE(0, 0, 0, 4)
    PLAY_AFFINE(12, 12, 0, 30)
END_AFFINE()


/* Impact3 particle (small 16x16) */
ASSETS(impact3, s16x16, 431);

MAKE_OAM(impact3)
    OAM_PRIORITY(2)
    OAM_SIZE(o16x16)
END_OAM()
