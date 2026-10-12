export interface Theme {
  name: string;
  settings: Record<string, string>;
}

/**
 * Transforms a day theme settings keys to their night theme counterparts.
 * e.g., SETTING_TIME_COLOR -> SETTING_NIGHT_TIME_COLOR
 */
export const toNightTheme = (theme: Theme): Theme => {
  const nightSettings: Record<string, string> = {};
  for (const [key, value] of Object.entries(theme.settings)) {
    if (key.startsWith('SETTING_')) {
      const nightKey = key.replace('SETTING_', 'SETTING_NIGHT_');
      nightSettings[nightKey] = value;
    } else {
      nightSettings[key] = value;
    }
  }
  return {
    ...theme,
    settings: nightSettings,
  };
};

/**
 * Transforms a day theme settings keys to their Quiet Time theme counterparts.
 * e.g., SETTING_TIME_COLOR -> SETTING_QUIET_TIME_COLOR
 */
export const toQuietTheme = (theme: Theme): Theme => {
  const quietSettings: Record<string, string> = {};
  for (const [key, value] of Object.entries(theme.settings)) {
    if (key.startsWith('SETTING_')) {
      const quietKey = key.replace('SETTING_', 'SETTING_QUIET_');
      quietSettings[quietKey] = value;
    } else {
      quietSettings[key] = value;
    }
  }
  return {
    ...theme,
    settings: quietSettings,
  };
};

/**
 * Combines light, neutral and dark themes into a single list, ensuring the first 
 * theme is marked as the default.
 * 
 * @param primaryThemes The first group of themes (e.g. light themes for day mode)
 * @param neutralThemes The second group of themes (e.g. neutral themes)
 * @param secondaryThemes The third group of themes (e.g. dark themes for day mode)
 * @param mode Whether to transform keys to SETTING_NIGHT_ or SETTING_QUIET_ counterparts
 */
export const prepareThemes = (
  primaryThemes: Theme[],
  neutralThemes: Theme[],
  secondaryThemes: Theme[],
  mode: boolean | 'day' | 'night' | 'quiet'
): Theme[] => {
  let combined = [...primaryThemes, ...neutralThemes, ...secondaryThemes];
  
  if (mode === true || mode === 'night') {
    combined = combined.map(toNightTheme);
  } else if (mode === 'quiet') {
    combined = combined.map(toQuietTheme);
  }

  return combined.map((theme, index) => {
    if (index === 0) {
      return {
        ...theme,
        name: `${theme.name} (Default)`,
      };
    }
    return theme;
  });
};
