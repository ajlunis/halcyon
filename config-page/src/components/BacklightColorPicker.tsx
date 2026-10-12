import React from 'react';
import { useConfig } from '../context/PebbleConfigContext';
import { Settings } from '../context/types';
import { FormItemLabel } from './FormItem';
import { Switch } from 'react-aria-components';

export interface BacklightColorPickerProps {
  label?: string;
  description?: string;
  useSystemKey: keyof Settings;
  colorKey: keyof Settings;
}

export const PRESET_BACKLIGHT_COLORS = [
  { name: 'Pure White', hex: '#FFFFFF' },
  { name: 'Cool Ice', hex: '#E0F7FA' },
  { name: 'Warm Ivory', hex: '#FFF2D6' },
  { name: 'Candlelight Amber', hex: '#FFA000' },
  { name: 'Night Vision Red', hex: '#FF1744' },
  { name: 'Sunset Orange', hex: '#FF5722' },
  { name: 'Neon Pink', hex: '#FF4081' },
  { name: 'Electric Purple', hex: '#9C27B0' },
  { name: 'Electric Blue', hex: '#2979FF' },
  { name: 'Cyber Cyan', hex: '#00E5FF' },
  { name: 'Emerald Green', hex: '#00E676' },
  { name: 'Golden Amber', hex: '#FFD700' },
];

export const BacklightColorPicker: React.FC<BacklightColorPickerProps> = ({
  label = 'Backlight Color',
  description = 'Customize RGB backlight color for Time 2 and Round 2',
  useSystemKey,
  colorKey,
}) => {
  const { settings, updateSetting } = useConfig();
  const useSystem = Number(settings[useSystemKey] ?? 1) === 1;

  const rawColor = String(settings[colorKey] || 'FFFFFF');
  const normalizedHex = rawColor.startsWith('#')
    ? rawColor.toUpperCase()
    : `#${rawColor.toUpperCase()}`;

  const handleToggleSystem = (checked: boolean) => {
    updateSetting(useSystemKey, checked ? 1 : 0);
  };

  const handleSelectColor = (hex: string) => {
    const clean = hex.replace('#', '').toUpperCase();
    updateSetting(colorKey, clean);
  };

  return (
    <div className="halite-backlight-section">
      <Switch
        isSelected={useSystem}
        onChange={handleToggleSystem}
        className="halite-item halite-toggle"
      >
        <FormItemLabel
          label="Use system backlight color"
          description="Keep default backlight or select a custom RGB backlight color"
        />
        <div className="halite-switch">
          <div className="halite-switch-thumb" />
        </div>
      </Switch>

      {!useSystem && (
        <div className="halite-backlight-container">
          <div className="halite-backlight-header">
            <FormItemLabel label={label} description={description} />
            <label
              className="halite-backlight-badge-trigger"
              title="Click to choose a custom color"
            >
              <span
                className="halite-backlight-badge-swatch"
                style={{
                  backgroundColor: normalizedHex,
                  boxShadow: `0 0 10px ${normalizedHex}66`,
                }}
              />
              <span className="halite-backlight-badge-hex">{normalizedHex}</span>
              <input
                type="color"
                value={normalizedHex.length === 7 ? normalizedHex : '#FFFFFF'}
                onChange={(e) => handleSelectColor(e.target.value)}
                className="halite-backlight-hidden-color-input"
                aria-label="Pick custom backlight color"
              />
            </label>
          </div>

          <div
            className="halite-backlight-presets-grid"
            role="radiogroup"
            aria-label="Preset backlight colors"
          >
            {PRESET_BACKLIGHT_COLORS.map((preset) => {
              const isSelected = normalizedHex.toLowerCase() === preset.hex.toLowerCase();
              return (
                <button
                  key={preset.hex}
                  type="button"
                  title={preset.name}
                  aria-label={`${preset.name} (${preset.hex})`}
                  aria-checked={isSelected}
                  role="radio"
                  onClick={() => handleSelectColor(preset.hex)}
                  className={`halite-backlight-swatch-btn ${isSelected ? 'selected' : ''}`}
                  style={{
                    backgroundColor: preset.hex,
                    boxShadow: isSelected ? `0 0 8px 2px ${preset.hex}` : undefined,
                  }}
                />
              );
            })}
          </div>
        </div>
      )}
    </div>
  );
};
