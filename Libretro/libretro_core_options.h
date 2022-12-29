#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include "libretro.h"
#include "retro_inline.h"

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */

struct retro_core_option_v2_category option_cats_us[] = {
   {
      "system",
      "System",
      "Change hardware-related settings."
   },
   {
      "video_general",
      "Video - General",
      "Change aspect ratio, overscan values, and other video-related settings."
   },
   {
      "video_image_adjustments",
      "Video - Image Adjustments",
      "Change values, color palette, video filters and other settings affecting the image output."
   },
   {
      "audio_general",
      "Audio - General",
      "Change sample rate, stereo effects and other sound-related settings."
   },
   {
      "audio_channel_balance",
      "Audio - Channel Balance",
      "Change the volume and overall balance of the audio channels."
   },
   {
      "audio_equalizer",
      "Audio - Equalizer",
      "Tweak and finetune the equalization of the sound."
   },
   {
      "input",
      "Input",
      "Change input devices and other input-related settings."
   },
   {
      "hacks",
      "Emulation Hacks",
      "Change processor overclocking and emulation accuracy settings affecting low-level performance and compatibility."
   },
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_us[] = {

   /* System */

   {
      "mesen_region",
      "System Region",
      NULL,
      "Change the region of the emulated system. When set to 'Auto', the hardware region will be detected based on the chosen content. If automatic detection is not possible, the NTSC region will be used by default. The 'Dendy' option is used to mimic a number of different NES clones.",
      NULL,
      "system",
      {
         { "Auto",  "Auto" },
         { "NTSC",  "NTSC" },
         { "PAL",   "PAL" },
         { "Dendy", "Dendy" },
         { NULL, NULL },
      },
      "Auto"
   },
   {
      "mesen_fdsautoinsertdisk",
      "FDS - Auto-insert Disks",
      NULL,
      "Automatically insert disks when needed for Famicom Disk System games.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_fdsfastforwardload",
      "FDS - Fast-Forward Load Screens",
      NULL,
      "Increase emulation speed temporarily while Famicom Disk System games are loading data from the disks. While being inaccurate, this allows to greatly reduce the time spent on loading screens.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },

   /* Video - General */

   {
      "mesen_aspect_ratio",
      "Aspect Ratio",
      NULL,
      "Define which aspect ratio should be used. 'Auto' will switch automatically between NTSC and PAL, depending on the chosen content. 'No Stretching' will preserve the unaltered almost-square ratio that is intrinsic to Famicom/NES systems. RetroArch's aspect ratio must be set to 'Core Provided' in the Video settings to achieve the best results.",
      NULL,
      "video_general",
      {
         { "Auto",             "Auto" },
         { "NTSC",             "NTSC (8:7)" },
         { "PAL",              "PAL (11:8)" },
         { "4:3",              NULL },
         { "4:3 (Preserved)",  NULL },
         { "16:9",             NULL },
         { "16:9 (Preserved)", NULL },
         { "No Stretching",    NULL },
         { NULL, NULL },
      },
      "Auto"
   },
   {
      "mesen_overscan_up",
      "Mask Overscan (Top)",
      NULL,
      "Mask out the potentially random glitchy video output on the top edge of the screen, that would have been hidden by the bezel around the edge of a standard-definition television panel.",
      NULL,
      "video_general",
      {
         { "None", "disabled" },
         { "4px",  "4 Pixels" },
         { "8px",  "8 Pixels" },
         { "12px", "12 Pixels" },
         { "16px", "16 Pixels" },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_overscan_down",
      "Mask Overscan (Bottom)",
      NULL,
      "Mask out the potentially random glitchy video output on the bottom edge of the screen, that would have been hidden by the bezel around the edge of a standard-definition television panel.",
      NULL,
      "video_general",
      {
         { "None", "disabled" },
         { "4px",  "4 Pixels" },
         { "8px",  "8 Pixels" },
         { "12px", "12 Pixels" },
         { "16px", "16 Pixels" },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_overscan_left",
      "Mask Overscan (Left)",
      NULL,
      "Mask out the potentially random glitchy video output on the left edge of the screen, that would have been hidden by the bezel around the edge of a standard-definition television panel.",
      NULL,
      "video_general",
      {
         { "None", "disabled" },
         { "4px",  "4 Pixels" },
         { "8px",  "8 Pixels" },
         { "12px", "12 Pixels" },
         { "16px", "16 Pixels" },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_overscan_right",
      "Mask Overscan (Right)",
      NULL,
      "Mask out the potentially random glitchy video output on the right edge of the screen, that would have been hidden by the bezel around the edge of a standard-definition television panel.",
      NULL,
      "video_general",
      {
         { "None", "disabled" },
         { "4px",  "4 Pixels" },
         { "8px",  "8 Pixels" },
         { "12px", "12 Pixels" },
         { "16px", "16 Pixels" },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_screenrotation",
      "Screen Rotation",
      NULL,
      "Rotate the display by the specified angle. This option is useful when playing games designed for a vertical display.",
      NULL,
      "video_general",
      {
         { "None",        "disabled" },
         { "90 degrees",  "90 Degrees" },
         { "180 degrees", "180 Degrees" },
         { "270 degrees", "270 Degrees" },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_fps_mode",
      "FPS Mode",
      NULL,
      "Define which FPS rate should be used. Setting this option to 'Integer' will force the core to produce exactly an output of either 50fps (for PAL content) or 60fps (for NTSC content). This may help reduce dropped frames during gameplay.",
      NULL,
      "video_general",
      {
         { "fps_mesen",   "Mesen" },
         { "fps_fceumm",  "FCEUmm" },
         { "fps_integer", "Integer" },
         { NULL, NULL },
      },
      "Mesen"
   },
   {
      "mesen_hdpacks",
      "Use HDNes HD Packs",
      NULL,
      "Enable the use of HD Packs, which allow to replace a game's graphics and audio with high definition alternatives. For the packs to be loaded properly, it is necessary to have a folder named 'HdPacks' in the RetroArch System/BIOS directory, then store the HD Pack data in a subfolder with the same name of the chosen content: for instance, RA System/BIOS folder -> HdPacks -> Mega Man (USA).",
      NULL,
      "video_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled"
   },

   /* Video - Image Adjustments */

   {
      "mesen_palette",
      "Palette",
      NULL,
      "Color palette to be used. If 'Custom' is selected, the palette used will be taken from the 'MesenPalette.pal' file placed in the RetroArch System/BIOS directory.",
      NULL,
      "video_image_adjustments",
      {
         { "Default",                           NULL },
         { "Composite Direct (by FirebrandX)",  NULL },
         { "Nes Classic",                       "NES Classic" },
         { "Nestopia (RGB)",                    NULL },
         { "Original Hardware (by FirebrandX)", NULL },
         { "PVM Style (by FirebrandX)",         NULL },
         { "Sony CXA2025AS",                    NULL },
         { "Unsaturated v6 (by FirebrandX)",    NULL },
         { "YUV v3 (by FirebrandX)",            NULL },
         { "Wavebeam (by nakedarthur)",         NULL },
         { "Custom",                            "Custom (MesenPalette.pal file)" },
         { "Raw",                               "Raw (Disables All Adjustments)" },
         { NULL, NULL },
      },
      "Default"
   },
   {
      "mesen_image",
      "Image Values",
      NULL,
      "Define whether the values of the image output should be set to default or allow for further tweaking.",
      NULL,
      "video_image_adjustments",
      {
         { "Default", NULL },
         { "Custom",  NULL },
         { NULL, NULL },
      },
      "Default"
   },
   {
      "mesen_brightness",
      "Brightness",
      NULL,
      "Adjust the brightness values of the image output.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_contrast",
      "Contrast",
      NULL,
      "Adjust the contrast values of the image output.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_saturation",
      "Saturation",
      NULL,
      "Adjust the saturation values of the image output.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_hue",
      "Hue",
      NULL,
      "Adjust the hue values of the image output.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_scanlines",
      "Scanlines",
      NULL,
      "Adjust the intensity of the internal scanlines. If applying an NTSC filter, the internal scanlines will only work with Blargg variants and Bisqwit 2x (either default or custom).",
      NULL,
      "video_image_adjustments",
      {
         { "0.00",  "disabled" },
         { "0.05",  "5%" },
         { "0.10",  "10%" },
         { "0.15",  "15%" },
         { "0.20",  "20%" },
         { "0.25",  "25%" },
         { "0.30",  "30%" },
         { "0.35",  "35%" },
         { "0.40",  "40%" },
         { "0.45",  "45%" },
         { "0.50",  "50%" },
         { "0.55",  "55%" },
         { "0.60",  "60%" },
         { "0.65",  "65%" },
         { "0.70",  "70%" },
         { "0.75",  "75%" },
         { "0.80",  "80%" },
         { "0.85",  "85%" },
         { "0.90",  "90%" },
         { "0.95",  "95%" },
         { "1.00",  "100%" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_filter",
      "Filter",
      NULL,
      "Apply a video filter to the picture, such as the ones replicating the NTSC signal processing. Setting this to any of the 'NTSC Custom' options allows more granular tweaking of each value of the NTSC filter.",
      NULL,
      "video_image_adjustments",
      {
         { "Disabled",            "disabled" },
         { "Composite (Blargg)",  "NTSC Composite (Blargg)" },
         { "S-Video (Blargg)",    "NTSC S-Video (Blargg)" },
         { "RGB (Blargg)",        "NTSC RGB (Blargg)" },
         { "Monochrome (Blargg)", "NTSC Monochrome (Blargg)" },
         { "Bisqwit 2x",          "NTSC Bisqwit 2x" },
         { "Bisqwit 4x",          "NTSC Bisqwit 4x" },
         { "Bisqwit 8x",          "NTSC Bisqwit 8x" },
         { "Custom (Blargg)",     "NTSC Custom (Blargg)" },
         { "Custom (Bisqwit 2x)", "NTSC Custom (Bisqwit 2x)" },
         { "Custom (Bisqwit 4x)", "NTSC Custom (Bisqwit 4x)" },
         { "Custom (Bisqwit 8x)", "NTSC Custom (Bisqwit 8x)" },
         { NULL, NULL },
      },
      "Disabled"
   },
   {
      "mesen_ntsc_artifacts",
      "NTSC Filter Artifacts",
      NULL,
      "Adjust the intensity of the artifacts when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_bleed",
      "NTSC Filter Color Bleed",
      NULL,
      "Adjust the intensity of the color bleed effect when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_fringing",
      "NTSC Filter Fringing",
      NULL,
      "Adjust the intensity of the fringing effect when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_gamma",
      "NTSC Filter Gamma",
      NULL,
      "Adjust the gamma level of the image output when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_resolution",
      "NTSC Filter Resolution",
      NULL,
      "Adjust the resolution of the image output when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_sharpness",
      "NTSC Filter Sharpness",
      NULL,
      "Adjust the sharpness of the image output when using the 'NTSC Custom (Blargg)' filter.",
      NULL,
      "video_image_adjustments",
      {
         { "-1.00", "-100" },
         { "-0.95", "-95" },
         { "-0.90", "-90" },
         { "-0.85", "-85" },
         { "-0.80", "-80" },
         { "-0.75", "-75" },
         { "-0.70", "-70" },
         { "-0.65", "-65" },
         { "-0.60", "-60" },
         { "-0.55", "-55" },
         { "-0.50", "-50" },
         { "-0.45", "-45" },
         { "-0.40", "-40" },
         { "-0.35", "-35" },
         { "-0.30", "-30" },
         { "-0.25", "-25" },
         { "-0.20", "-20" },
         { "-0.15", "-15" },
         { "-0.10", "-10" },
         { "-0.05", "-5" },
         { "0.00",  "Default" },
         { "0.05",  "+5" },
         { "0.10",  "+10" },
         { "0.15",  "+15" },
         { "0.20",  "+20" },
         { "0.25",  "+25" },
         { "0.30",  "+30" },
         { "0.35",  "+35" },
         { "0.40",  "+40" },
         { "0.45",  "+45" },
         { "0.50",  "+50" },
         { "0.55",  "+55" },
         { "0.60",  "+60" },
         { "0.65",  "+65" },
         { "0.70",  "+70" },
         { "0.75",  "+75" },
         { "0.80",  "+80" },
         { "0.85",  "+85" },
         { "0.90",  "+90" },
         { "0.95",  "+95" },
         { "1.00",  "+100" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_merge_fields",
      "NTSC Filter Merge Fields",
      NULL,
      "Define whether odd and even fields should be merged when applying the NTSC filter to the video output.",
      NULL,
      "video_image_adjustments",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_ntsc_yFilterLength",
      "NTSC Y Filter (Horizontal Blur)",
      NULL,
      "Adjust the intensity of the horizontal blur effect applied to the image output when using any of the 'NTSC Custom (Bisqwit)' filters.",
      NULL,
      "video_image_adjustments",
      {
         { "-0.50", "-50" },
         { "-0.40", "-40" },
         { "-0.30", "-30" },
         { "-0.20", "-20" },
         { "-0.10", "-10" },
         { "0.00",  "Default" },
         { "0.10",  "+10" },
         { "0.20",  "+20" },
         { "0.30",  "+30" },
         { "0.40",  "+40" },
         { "0.50",  "+50" },
         { "0.60",  "+60" },
         { "0.70",  "+70" },
         { "0.80",  "+80" },
         { "0.90",  "+90" },
         { "1.00",  "+100" },
         { "1.10",  "+110" },
         { "1.20",  "+120" },
         { "1.30",  "+130" },
         { "1.40",  "+140" },
         { "1.50",  "+150" },
         { "1.60",  "+160" },
         { "1.70",  "+170" },
         { "1.80",  "+180" },
         { "1.90",  "+190" },
         { "2.00",  "+200" },
         { "2.10",  "+210" },
         { "2.20",  "+220" },
         { "2.30",  "+230" },
         { "2.40",  "+240" },
         { "2.50",  "+250" },
         { "2.60",  "+260" },
         { "2.70",  "+270" },
         { "2.80",  "+280" },
         { "2.90",  "+290" },
         { "3.00",  "+300" },
         { "3.10",  "+310" },
         { "3.20",  "+320" },
         { "3.30",  "+330" },
         { "3.40",  "+340" },
         { "3.50",  "+350" },
         { "3.60",  "+360" },
         { "3.70",  "+370" },
         { "3.80",  "+380" },
         { "3.90",  "+390" },
         { "4.00",  "+400" },
      },
      "0.00"
   },
   {
      "mesen_ntsc_iFilterLength",
      "NTSC I Filter (Horizontal Bleed)",
      NULL,
      "Adjust the intensity of the 'I Filter' horizontal bleed effect applied to the image output when using any of the 'NTSC Custom (Bisqwit)' filters.",
      NULL,
      "video_image_adjustments",
      {
         { "0.00",  "0" },
         { "0.10",  "+10" },
         { "0.20",  "+20" },
         { "0.30",  "+30" },
         { "0.40",  "+40" },
         { "0.50",  "+50 (Default)" },
         { "0.60",  "+60" },
         { "0.70",  "+70" },
         { "0.80",  "+80" },
         { "0.90",  "+90" },
         { "1.00",  "+100" },
         { "1.10",  "+110" },
         { "1.20",  "+120" },
         { "1.30",  "+130" },
         { "1.40",  "+140" },
         { "1.50",  "+150" },
         { "1.60",  "+160" },
         { "1.70",  "+170" },
         { "1.80",  "+180" },
         { "1.90",  "+190" },
         { "2.00",  "+200" },
         { "2.10",  "+210" },
         { "2.20",  "+220" },
         { "2.30",  "+230" },
         { "2.40",  "+240" },
         { "2.50",  "+250" },
         { "2.60",  "+260" },
         { "2.70",  "+270" },
         { "2.80",  "+280" },
         { "2.90",  "+290" },
         { "3.00",  "+300" },
         { "3.10",  "+310" },
         { "3.20",  "+320" },
         { "3.30",  "+330" },
         { "3.40",  "+340" },
         { "3.50",  "+350" },
         { "3.60",  "+360" },
         { "3.70",  "+370" },
         { "3.80",  "+380" },
         { "3.90",  "+390" },
         { "4.00",  "+400" },
      },
      "0.50"
   },
   {
      "mesen_ntsc_qFilterLength",
      "NTSC Q Filter (Horizontal Bleed)",
      NULL,
      "Adjust the intensity of the 'Q Filter' horizontal bleed effect applied to the image output when using any of the 'NTSC Custom (Bisqwit)' filters.",
      NULL,
      "video_image_adjustments",
      {
         { "0.00",  "0" },
         { "0.10",  "+10" },
         { "0.20",  "+20" },
         { "0.30",  "+30" },
         { "0.40",  "+40" },
         { "0.50",  "+50 (Default)" },
         { "0.60",  "+60" },
         { "0.70",  "+70" },
         { "0.80",  "+80" },
         { "0.90",  "+90" },
         { "1.00",  "+100" },
         { "1.10",  "+110" },
         { "1.20",  "+120" },
         { "1.30",  "+130" },
         { "1.40",  "+140" },
         { "1.50",  "+150" },
         { "1.60",  "+160" },
         { "1.70",  "+170" },
         { "1.80",  "+180" },
         { "1.90",  "+190" },
         { "2.00",  "+200" },
         { "2.10",  "+210" },
         { "2.20",  "+220" },
         { "2.30",  "+230" },
         { "2.40",  "+240" },
         { "2.50",  "+250" },
         { "2.60",  "+260" },
         { "2.70",  "+270" },
         { "2.80",  "+280" },
         { "2.90",  "+290" },
         { "3.00",  "+300" },
         { "3.10",  "+310" },
         { "3.20",  "+320" },
         { "3.30",  "+330" },
         { "3.40",  "+340" },
         { "3.50",  "+350" },
         { "3.60",  "+360" },
         { "3.70",  "+370" },
         { "3.80",  "+380" },
         { "3.90",  "+390" },
         { "4.00",  "+400" },
      },
      "0.50"
   },
   {
      "mesen_ntsc_vertical_blend",
      "NTSC Filter Vertical Blending",
      NULL,
      "Define whether vertical blending should be applied to the video output when using NTSC filters.",
      NULL,
      "video_image_adjustments",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled"
   },
   {
      "mesen_ntsc_keep_vertical_resolution",
      "NTSC Filter Keep Vertical Resolution",
      NULL,
      "Choose whether the vertical resolution should be left unchanged when using NTSC filters.",
      NULL,
      "video_image_adjustments",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled"
   },

   /* Audio - General */

   {
      "mesen_audio_sample_rate",
      "Output Sample Rate",
      NULL,
      "Define which audio sample rate should be used for this core.",
      NULL,
      "audio_general",
      {
         { "11025", "11025 Hz" },
         { "22050", "22050 Hz" },
         { "44100", "44100 Hz" },
         { "48000", "48000 Hz" },
         { "96000", "96000 Hz" },
         { NULL, NULL },
      },
      "48000"
   },
   {
      "mesen_fake_stereo",
      "Fake Stereo",
      NULL,
      "Apply a fake stereo effect to the audio output.",
      NULL,
      "audio_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_mute_triangle_ultrasonic",
      "Mute Ultrasonic Frequencies on Triangle Channel",
      NULL,
      "Silence ultrasonic frequencies played through the triangle channel, to help reduce popping in the audio.",
      NULL,
      "audio_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_reduce_dmc_popping",
      "Reduce Popping on the DMC Channel",
      NULL,
      "Prevent games from changing the output of the DMC channel too abruptly, to help reduce popping in the audio.",
      NULL,
      "audio_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_swap_duty_cycle",
      "Swap Square Channel Duty Cycles",
      NULL,
      "Reproduce the output of some older NES clones that had incorrect sound output for both of the square channels. Enabling this option greatly alters the sound in some games. It should be activated only if the altered effect is desired.",
      NULL,
      "audio_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_disable_noise_mode_flag",
      "Disable Noise Channel Mode Flag",
      NULL,
      "Reproduce the output of very early Famicom models that did not make use of the noise channel flag. Enabling this option alters the noise channel in some games. It should be activated only if the altered effect is desired.",
      NULL,
      "audio_general",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },

   /* Input */

   {
      "mesen_controllerturbospeed",
      "Controller Turbo Speed",
      NULL,
      "Set the speed of the controller Turbo buttons, as defined internally in the core.",
      NULL,
      "input",
      {
         { "Disabled",  "disabled" },
         { "Slow",      NULL },
         { "Normal",    NULL },
         { "Fast",      NULL },
         { "Very Fast", NULL },
         { NULL, NULL },
      },
      "Fast"
   },
   {
      "mesen_shift_buttons_clockwise",
      "Shift Buttons Clockwise",
      NULL,
      "Rotate the A/B/X/Y buttons clockwise.",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },

   /* Emulation Hacks */

   {
      "mesen_nospritelimit",
      "Remove Sprite Limit",
      NULL,
      "Remove the limit that prevents the system from drawing more than 8 sprites per line, bringing the maximum amount of sprites to 64. This can help reduce the flickering seen in some games.",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled"
   },
   {
      "mesen_overclock",
      "Overclock",
      NULL,
      "Increase the effective clock rate of the emulated system. Overclocking can help reduce or remove slowdowns in games, but it can also cause issues.",
      NULL,
      "hacks",
      {
         { "None",      "disabled" },
         { "Low",       NULL },
         { "Medium",    NULL },
         { "High",      NULL },
         { "Very High", NULL },
         { NULL, NULL },
      },
      "None"
   },
   {
      "mesen_overclock_type",
      "Overclock Type",
      NULL,
      "Define whether the overclocking should be applied before or after the NMI signal is triggered at the end of the visible frame.",
      NULL,
      "hacks",
      {
         { "Before NMI (Recommended)", NULL },
         { "After NMI",                NULL },
         { NULL, NULL },
      },
      "Before NMI (Recommended)"
   },
   {
      "mesen_ramstate",
      "RAM Power-on State",
      NULL,
      "Choose whether the system RAM should be initialized by setting all bits to 0, 1 or entirely random values. For example, some games may rely on the initial RAM values for random number generation.",
      NULL,
      "hacks",
      {
         { "All 0s (Default)", "Set all bits to 0" },
         { "All 1s",           "Set all bits to 1" },
         { "Random Values",    "Randomize values" },
         { NULL, NULL },
      },
      "All 0s (Default)"
   },

   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us, /* RETRO_LANGUAGE_ENGLISH */
   NULL,        /* RETRO_LANGUAGE_JAPANESE */
   NULL,        /* RETRO_LANGUAGE_FRENCH */
   NULL,        /* RETRO_LANGUAGE_SPANISH */
   NULL,        /* RETRO_LANGUAGE_GERMAN */
   NULL,        /* RETRO_LANGUAGE_ITALIAN */
   NULL,        /* RETRO_LANGUAGE_DUTCH */
   NULL,        /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,        /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,        /* RETRO_LANGUAGE_RUSSIAN */
   NULL,        /* RETRO_LANGUAGE_KOREAN */
   NULL,        /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,        /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,        /* RETRO_LANGUAGE_ESPERANTO */
   NULL,        /* RETRO_LANGUAGE_POLISH */
   NULL,        /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,        /* RETRO_LANGUAGE_ARABIC */
   NULL,        /* RETRO_LANGUAGE_GREEK */
   NULL,        /* RETRO_LANGUAGE_TURKISH */
   NULL,        /* RETRO_LANGUAGE_SLOVAK */
   NULL,        /* RETRO_LANGUAGE_PERSIAN */
   NULL,        /* RETRO_LANGUAGE_HEBREW */
   NULL,        /* RETRO_LANGUAGE_ASTURIAN */
   NULL,        /* RETRO_LANGUAGE_FINNISH */
   NULL,        /* RETRO_LANGUAGE_INDONESIAN */
   NULL,        /* RETRO_LANGUAGE_SWEDISH */
   NULL,        /* RETRO_LANGUAGE_UKRAINIAN */
   NULL,        /* RETRO_LANGUAGE_CZECH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb,
      bool *categories_supported)
{
   unsigned version  = 0;
#ifndef HAVE_NO_LANGEXTRA
   unsigned language = 0;
#endif

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
#else
      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2,
            &options_us);
#endif
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
#ifndef HAVE_NO_LANGEXTRA
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
#endif
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

#ifndef HAVE_NO_LANGEXTRA
         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
#else
         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, option_v1_defs_us);
#endif
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

#ifndef HAVE_NO_LANGEXTRA
      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }
#endif

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
