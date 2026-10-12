#pragma once
#include "widgets.h"
#include <pebble.h>
#include <sys/syslimits.h>

#define CURRENT_SETTINGS_VERSION 3
#define SETTINGS_VERSION_PERSIST_KEY 1
#define SETTINGS_PERSIST_KEY 2
#define SETTINGS_EXTRA_PERSIST_KEY 3
#define ALT_CITY_LABEL_LEN 20

// default settings
#ifdef PBL_COLOR
#define DEFAULT_TIME_COLOR GColorBlack
#define DEFAULT_SUBTEXT_PRIMARY_COLOR GColorBlack
#define DEFAULT_SUBTEXT_SECONDARY_COLOR GColorDarkGray
#define DEFAULT_BG_COLOR GColorWhite
#define DEFAULT_PIP_COLOR_PRIMARY GColorBlack
#define DEFAULT_PIP_COLOR_SECONDARY GColorLightGray
#define DEFAULT_RING_STROKE_COLOR GColorBlack
#define DEFAULT_RING_NIGHT_COLOR GColorCobaltBlue
#define DEFAULT_RING_DAY_COLOR GColorVividCerulean
#define DEFAULT_RING_SUNRISE_COLOR GColorMelon
#define DEFAULT_RING_SUNSET_COLOR GColorChromeYellow
#define DEFAULT_SUN_STROKE_COLOR GColorBlack
#define DEFAULT_SUN_FILL_COLOR GColorYellow

// night theme defaults
#define DEFAULT_NIGHT_TIME_COLOR GColorFromHEX(0xFFFFFF)
#define DEFAULT_NIGHT_SUBTEXT_PRIMARY_COLOR GColorFromHEX(0xFFFFFF)
#define DEFAULT_NIGHT_SUBTEXT_SECONDARY_COLOR GColorFromHEX(0xAAAAFF)
#define DEFAULT_NIGHT_BG_COLOR GColorFromHEX(0x000055)
#define DEFAULT_NIGHT_PIP_COLOR_PRIMARY GColorFromHEX(0xFFFFFF)
#define DEFAULT_NIGHT_PIP_COLOR_SECONDARY GColorFromHEX(0x0055AA)
#define DEFAULT_NIGHT_RING_STROKE_COLOR GColorBlack
#define DEFAULT_NIGHT_RING_NIGHT_COLOR GColorFromHEX(0x0000AA)
#define DEFAULT_NIGHT_RING_DAY_COLOR GColorFromHEX(0x00AAFF)
#define DEFAULT_NIGHT_RING_SUNRISE_COLOR GColorFromHEX(0x0055FF)
#define DEFAULT_NIGHT_RING_SUNSET_COLOR GColorFromHEX(0x0055FF)
#define DEFAULT_NIGHT_SUN_STROKE_COLOR GColorBlack
#define DEFAULT_NIGHT_SUN_FILL_COLOR GColorFromHEX(0xFFFFFF)
#else
#define DEFAULT_TIME_COLOR GColorBlack
#define DEFAULT_SUBTEXT_PRIMARY_COLOR GColorBlack
#define DEFAULT_SUBTEXT_SECONDARY_COLOR GColorBlack
#define DEFAULT_BG_COLOR GColorWhite
#define DEFAULT_PIP_COLOR_PRIMARY GColorBlack
#define DEFAULT_PIP_COLOR_SECONDARY GColorBlack
#define DEFAULT_RING_STROKE_COLOR GColorBlack
#define DEFAULT_RING_NIGHT_COLOR GColorBlack
#define DEFAULT_RING_DAY_COLOR GColorWhite
#define DEFAULT_RING_SUNRISE_COLOR GColorLightGray
#define DEFAULT_RING_SUNSET_COLOR GColorLightGray
#define DEFAULT_SUN_STROKE_COLOR GColorBlack
#define DEFAULT_SUN_FILL_COLOR GColorWhite

// night theme defaults
#define DEFAULT_NIGHT_TIME_COLOR GColorWhite
#define DEFAULT_NIGHT_SUBTEXT_PRIMARY_COLOR GColorWhite
#define DEFAULT_NIGHT_SUBTEXT_SECONDARY_COLOR GColorWhite
#define DEFAULT_NIGHT_BG_COLOR GColorBlack
#define DEFAULT_NIGHT_PIP_COLOR_PRIMARY GColorWhite
#define DEFAULT_NIGHT_PIP_COLOR_SECONDARY GColorWhite
#define DEFAULT_NIGHT_RING_STROKE_COLOR GColorBlack
#define DEFAULT_NIGHT_RING_NIGHT_COLOR GColorBlack
#define DEFAULT_NIGHT_RING_DAY_COLOR GColorWhite
#define DEFAULT_NIGHT_RING_SUNRISE_COLOR GColorLightGray
#define DEFAULT_NIGHT_RING_SUNSET_COLOR GColorLightGray
#define DEFAULT_NIGHT_SUN_STROKE_COLOR GColorBlack
#define DEFAULT_NIGHT_SUN_FILL_COLOR GColorWhite
#endif

// default settings, black and white

typedef enum {
  PIP_SHOW_ALL = 0,
  PIP_SHOW_MAJOR = 1,
  PIP_HIDDEN = 2
} PipVisibilityType;

typedef enum { TEMP_UNIT_CELSIUS = 0, TEMP_UNIT_FAHRENHEIT = 1 } TempUnitType;

// typedef enum {
//   NO_VIBE = 0,
//   VIBE_EVERY_HOUR = 1,
//   VIBE_EVERY_HALF_HOUR = 2
// } VibeIntervalType;

#define DEFAULT_BACKLIGHT_USE_SYSTEM true
#define DEFAULT_BACKLIGHT_COLOR 0xFFFFFF
#define DEFAULT_NIGHT_BACKLIGHT_USE_SYSTEM true
#define DEFAULT_NIGHT_BACKLIGHT_COLOR 0xFFFFFF
#define DEFAULT_SHOW_BT_DISCONNECT_ICON false

#define DEFAULT_USE_QUIET_THEME false
#define DEFAULT_QUIET_BACKLIGHT_USE_SYSTEM true
#define DEFAULT_QUIET_BACKLIGHT_COLOR 0xFFFFFF

#define DEFAULT_QUIET_TIME_COLOR DEFAULT_NIGHT_TIME_COLOR
#define DEFAULT_QUIET_SUBTEXT_PRIMARY_COLOR DEFAULT_NIGHT_SUBTEXT_PRIMARY_COLOR
#define DEFAULT_QUIET_SUBTEXT_SECONDARY_COLOR DEFAULT_NIGHT_SUBTEXT_SECONDARY_COLOR
#define DEFAULT_QUIET_BG_COLOR DEFAULT_NIGHT_BG_COLOR
#define DEFAULT_QUIET_PIP_COLOR_PRIMARY DEFAULT_NIGHT_PIP_COLOR_PRIMARY
#define DEFAULT_QUIET_PIP_COLOR_SECONDARY DEFAULT_NIGHT_PIP_COLOR_SECONDARY
#define DEFAULT_QUIET_RING_STROKE_COLOR DEFAULT_NIGHT_RING_STROKE_COLOR
#define DEFAULT_QUIET_RING_NIGHT_COLOR DEFAULT_NIGHT_RING_NIGHT_COLOR
#define DEFAULT_QUIET_RING_DAY_COLOR DEFAULT_NIGHT_RING_DAY_COLOR
#define DEFAULT_QUIET_RING_SUNRISE_COLOR DEFAULT_NIGHT_RING_SUNRISE_COLOR
#define DEFAULT_QUIET_RING_SUNSET_COLOR DEFAULT_NIGHT_RING_SUNSET_COLOR
#define DEFAULT_QUIET_SUN_STROKE_COLOR DEFAULT_NIGHT_SUN_STROKE_COLOR
#define DEFAULT_QUIET_SUN_FILL_COLOR DEFAULT_NIGHT_SUN_FILL_COLOR

// Color theme struct containing just the color fields
typedef struct {
  GColor timeColor;
  GColor subtextPrimaryColor;
  GColor subtextSecondaryColor;
  GColor bgColor;
  GColor pipColorPrimary;
  GColor pipColorSecondary;
  GColor ringStrokeColor;
  GColor ringNightColor;
  GColor ringDayColor;
  GColor ringSunriseColor;
  GColor ringSunsetColor;
  GColor sunStrokeColor;
  GColor sunFillColor;
#if defined(PBL_RGB_BACKLIGHT)
  bool useSystemBacklight;
  uint32_t backlightColor;
#endif
} ColorTheme;

typedef struct {
  // text colors
  GColor timeColor;
  GColor subtextPrimaryColor;
  GColor subtextSecondaryColor;

  // decoration colors
  GColor bgColor;
  GColor pipColorPrimary;
  GColor pipColorSecondary;
  GColor ringStrokeColor;
  GColor ringNightColor;
  GColor ringDayColor;
  GColor ringSunriseColor;
  GColor ringSunsetColor;
  GColor sunStrokeColor;
  GColor sunFillColor;

  // night theme colors
  GColor nightTimeColor;
  GColor nightSubtextPrimaryColor;
  GColor nightSubtextSecondaryColor;
  GColor nightBgColor;
  GColor nightPipColorPrimary;
  GColor nightPipColorSecondary;
  GColor nightRingStrokeColor;
  GColor nightRingNightColor;
  GColor nightRingDayColor;
  GColor nightRingSunriseColor;
  GColor nightRingSunsetColor;
  GColor nightSunStrokeColor;
  GColor nightSunFillColor;

  bool useNightTheme;
  bool useLargeFonts;
  bool showLeadingZero;
  PipVisibilityType pipVisibility;
  TempUnitType tempUnit;
  uint8_t language;

  // Widget slots (stored as format strings)
  char widgetUpperSecondary[WIDGET_TEXT_LEN];
  char widgetUpperPrimary[WIDGET_TEXT_LEN];
  char widgetLowerPrimary[WIDGET_TEXT_LEN];
  char widgetLowerSecondary[WIDGET_TEXT_LEN];

  char altCityLabel[ALT_CITY_LABEL_LEN];
  int16_t altCityUtcOffset;
  char altCity2Label[ALT_CITY_LABEL_LEN];
  int16_t altCity2UtcOffset;
  int16_t localUtcOffset;
  bool usePrimaryFontForAllWidgets;
  bool useSystemBacklight;
  uint32_t backlightColor;
  bool nightUseSystemBacklight;
  uint32_t nightBacklightColor;
  bool showBtDisconnectIcon;
  bool useQuietTheme;
  GColor quietTimeColor;
  GColor quietSubtextPrimaryColor;
  GColor quietSubtextSecondaryColor;
  GColor quietBgColor;
  GColor quietPipColorPrimary;
  GColor quietPipColorSecondary;
  GColor quietRingStrokeColor;
  GColor quietRingNightColor;
  GColor quietRingDayColor;
  GColor quietRingSunriseColor;
  GColor quietRingSunsetColor;
  GColor quietSunStrokeColor;
  GColor quietSunFillColor;
  bool quietUseSystemBacklight;
  uint32_t quietBacklightColor;
  int8_t lastPhoneBattery;
} Settings;

typedef struct {
  // text colors
  GColor timeColor;
  GColor subtextPrimaryColor;
  GColor subtextSecondaryColor;

  // decoration colors
  GColor bgColor;
  GColor pipColorPrimary;
  GColor pipColorSecondary;
  GColor ringStrokeColor;
  GColor ringNightColor;
  GColor ringDayColor;
  GColor ringSunriseColor;
  GColor ringSunsetColor;
  GColor sunStrokeColor;
  GColor sunFillColor;

  // night theme colors
  GColor nightTimeColor;
  GColor nightSubtextPrimaryColor;
  GColor nightSubtextSecondaryColor;
  GColor nightBgColor;
  GColor nightPipColorPrimary;
  GColor nightPipColorSecondary;
  GColor nightRingStrokeColor;
  GColor nightRingNightColor;
  GColor nightRingDayColor;
  GColor nightRingSunriseColor;
  GColor nightRingSunsetColor;
  GColor nightSunStrokeColor;
  GColor nightSunFillColor;

  bool useNightTheme;
  bool useLargeFonts;
  bool showLeadingZero;

  PipVisibilityType pipVisibility;
  TempUnitType tempUnit;
  uint8_t language;

  // Widget slots (stored as format strings)
  char widgetUpperSecondary[WIDGET_TEXT_LEN];
  char widgetUpperPrimary[WIDGET_TEXT_LEN];
  char widgetLowerPrimary[WIDGET_TEXT_LEN];
  char widgetLowerSecondary[WIDGET_TEXT_LEN];
} StoredSettings;

// we're kinda at the limit for stored settings, so new settings get their own
// special struct
typedef struct {
  char altCityLabel[ALT_CITY_LABEL_LEN];
  int16_t altCityUtcOffset;
  char altCity2Label[ALT_CITY_LABEL_LEN];
  int16_t altCity2UtcOffset;
  int16_t localUtcOffset;
  bool usePrimaryFontForAllWidgets;
  bool useSystemBacklight;
  uint32_t backlightColor;
  bool nightUseSystemBacklight;
  uint32_t nightBacklightColor;
  bool showBtDisconnectIcon;
  bool useQuietTheme;
  GColor quietTimeColor;
  GColor quietSubtextPrimaryColor;
  GColor quietSubtextSecondaryColor;
  GColor quietBgColor;
  GColor quietPipColorPrimary;
  GColor quietPipColorSecondary;
  GColor quietRingStrokeColor;
  GColor quietRingNightColor;
  GColor quietRingDayColor;
  GColor quietRingSunriseColor;
  GColor quietRingSunsetColor;
  GColor quietSunStrokeColor;
  GColor quietSunFillColor;
  bool quietUseSystemBacklight;
  uint32_t quietBacklightColor;
  int8_t lastPhoneBattery;
} StoredSettingsExtra;

typedef char StoredSettings_must_fit_in_persist_data
    [(sizeof(StoredSettings) <= PERSIST_DATA_MAX_LENGTH) ? 1 : -1];
typedef char StoredSettingsExtra_must_fit_in_persist_data
    [(sizeof(StoredSettingsExtra) <= PERSIST_DATA_MAX_LENGTH) ? 1 : -1];

extern Settings globalSettings;

ColorTheme getCurrentColorTheme();

void Settings_init();
void Settings_deinit();
void Settings_loadFromStorage();
void Settings_saveToStorage();
void Settings_updateDynamicSettings();
