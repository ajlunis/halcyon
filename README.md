![Halcyon showing 10:38AM](screenshots/platforms/emery-am.png) ![Halcyon showing 10:38PM](screenshots/platforms/emery-pm.png)

# Halcyon
An analog-digital watchface featuring the solar day!

Halcyon represents the 24 hours of the day as a ring around the edges of your watch, highlighting the sunrise, sunset, and the position of the sun! (Inspired by the PebbleOS 3.9-era sleep visualization!)

### Features:

- **Solar Day Ring:** Watch the hours of your day slip away as the sun moves through the 24-hour outer dial!
- **Day & Night Themes:** Select from various exciting color presets, with separate themes for nighttime and daytime.
- **Quiet Time Theme:** Optional 3rd conditional theme that activates automatically whenever Quiet Time is enabled on the watch.
- **Custom Backlight Color:** On RGB backlight devices (Pebble Time 2 & Round 2), configure custom backlight colors per theme, choose from hardware-optimized presets, enter a custom HEX code, or use the system default.
- **Bluetooth Disconnection Indicator:** Optional badge at the top-center border displaying a stylized 'B' with a red strike-through when phone connection is lost.
- **Unreasonable Color Customization:** Create, customize, save, load, and share custom themes with live previews.
- **Widgets:** Up to 4 user-selectable widgets including weather, phone battery (`{phone_batt}`), watch battery (`{batt}`), heart rate, steps, and more.
- **Custom Widgets:** Add a monogram or build your own hybrid widgets featuring any available tokens.
- **Multilingual Localization:** Widgets are fully localized into 38 different languages.

### Install it on your watch: 

- **Download it on the Pebble Store:**
  - https://apps.repebble.com/halcyon_67cb1c5fb7a02301b9a6e415
- **...or on the Rebble Store:**
  - https://apps.rebble.io/en_US/application/67cb1c5fb7a02301b9a6e415

---

### Building the Watchface

The watchface targets all Pebble platforms: `aplite`, `basalt`, `chalk`, `diorite`, `emery`, `flint`, and `gabbro`.

#### Prerequisites
- Modern [Core Devices](https://github.com/coredevices) Pebble Tooling:
  ```bash
  uv tool install pebble-tool --python 3.13
  pebble sdk install latest
  ```
- Node.js (for PebbleKit JS webpack bundling and config page builds)

#### Build
```bash
# Build the .pbw bundle for all platforms
pebble build

# Clean build artifacts
pebble clean
```
The compiled bundle will be output to `build/Halcyon.pbw`.

---

### Configuration Page (`config-page/`)

The settings page is a React + Vite + Tailwind application located in `config-page/`.

#### Local Development
```bash
cd config-page
npm install
npm run dev
```

To test local configuration from your phone:
1. In `src/pkjs/index.js`, set `USE_LOCAL_CONFIG = true` and update `configLocalUri` to your machine's local network IP (e.g. `http://192.168.1.X:5173/index.html`).
2. Rebuild and install the `.pbw`:
   ```bash
   pebble build
   pebble install --phone <PHONE_IP>
   ```

#### Production Build & GitHub Pages Deployment
```bash
cd config-page
npm run build
```
Pushing to `master` automatically triggers the GitHub Actions workflow (`.github/workflows/deploy.yml`) to deploy the built configuration page to GitHub Pages. Update `configDataUri` in `src/pkjs/index.js` to point to your deployed URL.
