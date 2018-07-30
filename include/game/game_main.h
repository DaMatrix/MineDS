#ifndef __GAMEMAIN9__
#define __GAMEMAIN9__

int Game_FPS, Game_FrameCount, Game_VBLcount;

#include "common/general.h"
#include "../include/game/textures.h"
#include "fat/fatfile.h"

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#include "fat/cache.h"
#include "fat/file_allocation_table.h"
#include "fat/bit_ops.h"
#include "fat/filetime.h"
#include "fat/lock.h"

#include "../include/game/map.h"
#include "../include/game/jump.h"
#include "../include/game/player.h"
#include "../include/game/mobs.h"
#include "../include/game/controls.h"
#include "../include/game/iniparser.h"
#include "../include/game/interface.h"
#include "../include/game/environment.h"
#include "../include/game/displaylistlib.h"

#include "API/font.h"

#endif
