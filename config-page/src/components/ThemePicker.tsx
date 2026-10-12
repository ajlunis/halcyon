import React from 'react';
import { useCapabilities, useConfig } from '../context/PebbleConfigContext';
import { Settings } from '../context/types';
import { FormItem } from './FormItem';
import { GridList, GridListItem, Text } from 'react-aria-components';
import { WatchPreview, WatchPreviewProps } from './WatchPreview';
import { SavedTheme, remapToNightKeys, remapToQuietKeys } from '../hooks/useSavedThemes';
import customIconUrl from '../assets/custom-icon.svg';

export const ThemePicker: React.FC<{
  label?: string;
  messageKey: keyof Settings;
  themes: { name: string; settings: Record<string, string> }[];
  watchPreviewProps?: Partial<WatchPreviewProps>;
  savedThemes?: SavedTheme[];
}> = ({ label, messageKey, themes, watchPreviewProps, savedThemes = [] }) => {
  const { settings, updateSetting } = useConfig();
  const capabilities = useCapabilities();
  const currentValue = settings[messageKey];
  const isRound = capabilities.ROUND && !capabilities.RECT;
  const isNight = watchPreviewProps?.isNight ?? false;
  const isQuiet = watchPreviewProps?.isQuiet ?? false;

  const handleThemeChange = (themeId: string) => {
    updateSetting(messageKey, themeId);

    if (themeId === 'custom') return;

    // Check saved themes first
    const saved = savedThemes.find((t) => t.id === themeId);
    if (saved) {
      const settingsToApply = isQuiet
        ? remapToQuietKeys(saved.settings)
        : isNight
          ? remapToNightKeys(saved.settings)
          : saved.settings;
      Object.entries(settingsToApply).forEach(([key, value]) => {
        updateSetting(key, value);
      });
      return;
    }

    const theme = themes[parseInt(themeId, 10)];
    if (theme) {
      Object.entries(theme.settings).forEach(([key, value]) => {
        updateSetting(key, value);
      });
    }
  };

  const themeList = React.useMemo(() => [
    { id: 'custom', name: 'Custom', settings: {}, isSaved: false },
    ...savedThemes.map((t) => ({
      id: t.id,
      name: t.name,
      // Remap keys so the preview card renders correctly in night/quiet mode
      settings: isQuiet
        ? remapToQuietKeys(t.settings)
        : isNight
          ? remapToNightKeys(t.settings)
          : t.settings,
      isSaved: true,
    })),
    ...themes.map((theme, index) => ({
      id: index.toString(),
      name: theme.name,
      settings: theme.settings,
      isSaved: false,
    })),
  ], [themes, savedThemes, isNight, isQuiet]);

  const isCustomBacklight = Number(
    isQuiet
      ? settings.SETTING_QUIET_BACKLIGHT_USE_SYSTEM ?? 1
      : isNight
        ? settings.SETTING_NIGHT_BACKLIGHT_USE_SYSTEM ?? 1
        : settings.SETTING_BACKLIGHT_USE_SYSTEM ?? 1
  ) === 0;
  const rawCustomBacklight = isQuiet
    ? settings.SETTING_QUIET_BACKLIGHT_COLOR
    : isNight
      ? settings.SETTING_NIGHT_BACKLIGHT_COLOR
      : settings.SETTING_BACKLIGHT_COLOR;
  const customBacklightHex = (rawCustomBacklight || 'FFFFFF').startsWith('#')
    ? (rawCustomBacklight || 'FFFFFF')
    : `#${rawCustomBacklight || 'FFFFFF'}`;

  return (
    <FormItem className="halite-theme-picker">
      <GridList
        items={themeList}
        selectionMode="single"
        selectedKeys={[currentValue]}
        onSelectionChange={(keys) => {
          const selected = Array.from(keys)[0] as string;
          if (selected) handleThemeChange(selected);
        }}
        layout='grid'
        aria-label={label}
        className="halite-theme-grid"
      >
        {(item) => (
          <GridListItem id={item.id} className={`halite-theme-card ${isRound ? 'round' : 'rect'}`} textValue={item.name}>
            <div className={`halite-theme-card-preview ${isRound ? 'round' : 'rect'}`}>
              {item.id === 'custom' ? (
                <div className={`halite-custom-icon ${isRound ? 'round' : 'rect'}`} style={{ position: 'relative' }}>
                  <img src={customIconUrl} alt="" width={40} height={38} />
                  {isCustomBacklight && (
                    <div
                      className="halite-backlight-preview-glow"
                      style={{
                        borderRadius: isRound ? '50%' : '14px',
                        background: `radial-gradient(circle, ${customBacklightHex}44 0%, ${customBacklightHex}22 60%, transparent 100%)`,
                        boxShadow: `inset 0 0 12px ${customBacklightHex}66`,
                      }}
                    />
                  )}
                </div>
              ) : (
                <WatchPreview overrideSettings={item.settings} {...watchPreviewProps} />
              )}
            </div>
            <Text className="halite-theme-card-label">
              {item.name}
            </Text>
          </GridListItem>
        )}
      </GridList>
    </FormItem>
  );
};
